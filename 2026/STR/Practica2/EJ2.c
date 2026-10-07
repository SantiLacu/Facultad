#include <stdio.h>
#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"

enum {
    estadoA,
    estadoB,
    estadoC
}estado;

SemaphoreHandle_t semA;
void A(void *pvParameters) {
    for (;;) {
        printf("Tarea A\n");
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}

void B(void *pvParameters) {
    for (;;) {
        printf("Tarea B\n");
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}

void C(void *pvParameters) {
    for (;;) {
        printf("Tarea C\n");
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}

int main(void) {
    xTaskCreate(A, "Tarea A", configMINIMAL_STACK_SIZE, NULL, 3, NULL);
    xTaskCreate(B, "Tarea B", configMINIMAL_STACK_SIZE, NULL, 5, NULL);
    xTaskCreate(C, "Tarea C", configMINIMAL_STACK_SIZE, NULL, 1, NULL);

    vTaskStartScheduler();

    while (1);
    return 0;
}