CC = gcc
FREERTOS_DIR = /home/santiago/Facultad/Facultad/2026/STR/Practica2/FreeRTOS
CONFIG_DIR = /home/santiago/Facultad/Facultad/2026/STR/Practica2/Config
PORT_DIR = $(shell find $(FREERTOS_DIR) -name "portmacro.h" | grep -i posix | head -n 1 | xargs dirname)

CFLAGS = -I$(FREERTOS_DIR)/include -I$(CONFIG_DIR) -I$(PORT_DIR) -pthread

SRC_FREERTOS = $(FREERTOS_DIR)/tasks.c \
               $(FREERTOS_DIR)/queue.c \
               $(FREERTOS_DIR)/list.c \
               $(FREERTOS_DIR)/timers.c \
               $(FREERTOS_DIR)/event_groups.c \
               $(PORT_DIR)/port.c \
               $(shell find $(PORT_DIR) -name "wait_for_event.c" | head -n 1) \
               $(shell find $(FREERTOS_DIR)/portable/MemMang -name "heap_3.c" | head -n 1)

all: EJ4

EJ4: EJ4.c
	$(CC) EJ4.c $(SRC_FREERTOS) $(CFLAGS) -o EJ4
