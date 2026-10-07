#include <stdio.h>
#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"

enum {
    estado1, // Secuencia A: 1 -> 3 -> 2
    estado2, // Secuencia B: 2 -> 2 -> 3 -> 1
    estado3  // Secuencia C: 3 -> 3 -> 3 -> 1 -> 2
} estado;

SemaphoreHandle_t semA;
SemaphoreHandle_t semB;
SemaphoreHandle_t semC;

void A(void *pvParameters) {
    for (;;) {
        if (xSemaphoreTake(semA, portMAX_DELAY) == pdTRUE) {
            printf("Tarea 1\n");
            vTaskDelay(pdMS_TO_TICKS(1000));
            switch (estado) {
                case estado1:
                    // 1 -> 3
                    xSemaphoreGive(semC);
                    break;
                case estado2:
                    // Fin de Secuencia B. Pasa a Secuencia C (inicia con Tarea 3)
                    estado = estado3;
                    xSemaphoreGive(semC);
                    printf("\n");
                    break;
                case estado3:
                    // 1 -> 2
                    xSemaphoreGive(semB);
                    break;
            }
        }
    }
}

void B(void *pvParameters) {
    static int countB = 0;

    for (;;) {
        if (xSemaphoreTake(semB, portMAX_DELAY) == pdTRUE) {
            printf("Tarea 2\n");
            vTaskDelay(pdMS_TO_TICKS(1000));

            switch (estado) {
                case estado1:
                    // Fin de Secuencia A. Pasa a Secuencia B (inicia con Tarea 2)
                    estado = estado2;
                    countB = 0;
                    xSemaphoreGive(semB);
                    printf("\n");
                    break;
                case estado2:
                    countB++;
                    if (countB == 1) {
                        // 2 -> 2 (segunda ejecución de B)
                        xSemaphoreGive(semB);
                    } else {
                        // 2 -> 3
                        countB = 0;
                        xSemaphoreGive(semC);
                    }
                    break;
                case estado3:
                    // Fin de Secuencia C. Reinicia el ciclo a Secuencia A (inicia con Tarea 1)
                    estado = estado1;
                    xSemaphoreGive(semA);
                    printf("\n");
                    break;
            }
        }
    }
}

void C(void *pvParameters) {
    static int countC = 0;

    for (;;) {
        if (xSemaphoreTake(semC, portMAX_DELAY) == pdTRUE) {
            printf("Tarea 3\n");
            vTaskDelay(pdMS_TO_TICKS(1000));

            switch (estado) {
                case estado1:
                    // 3 -> 2
                    xSemaphoreGive(semB);
                    break;
                case estado2:
                    // 3 -> 1
                    xSemaphoreGive(semA);
                    break;
                case estado3:
                    countC++;
                    if (countC < 3) {
                        // Se repite 3 veces (3 -> 3 -> 3)
                        xSemaphoreGive(semC);
                    } else {
                        // 3 -> 1
                        countC = 0;
                        xSemaphoreGive(semA);
                    }
                    break;
            }
        }
    }
}

int main(void) {
    semA = xSemaphoreCreateBinary();
    semB = xSemaphoreCreateBinary();
    semC = xSemaphoreCreateBinary();

    estado = estado1;

    if (semA != NULL && semB != NULL && semC != NULL) {
        // Habilita a la Tarea 1 (A) a arrancar la primera secuencia
        xSemaphoreGive(semA);

        xTaskCreate(A, "Tarea A", configMINIMAL_STACK_SIZE, NULL, 1, NULL);
        xTaskCreate(B, "Tarea B", configMINIMAL_STACK_SIZE, NULL, 1, NULL);
        xTaskCreate(C, "Tarea C", configMINIMAL_STACK_SIZE, NULL, 1, NULL);

        vTaskStartScheduler();
    }

    while (1);
    return 0;
}