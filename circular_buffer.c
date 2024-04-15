#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "circular_buffer.h"

CircularBuffer *createBuffer(int size) {
    CircularBuffer *cb = (CircularBuffer *)malloc(sizeof(CircularBuffer));
    cb->buffer = (int *)malloc(sizeof(int) * size);
    cb->head = 0;
    cb->tail = 0;
    cb->size = size;
    cb->cnt = 0;
    return cb;
}

void freeBuffer(CircularBuffer *cb) {
    free(cb->buffer);
    free(cb);
    printf("Buffer is freed.\n");
}

void write(CircularBuffer *cb, int value, bool overwrite) {
    if (!overwrite && cb->cnt == cb->size) {
        printf("Failed to write because buffer is full.\n");
        return ;
    }
    cb->buffer[cb->tail] = value;
    cb->tail = (cb->tail + 1) % cb->size;
    cb->head = cb->cnt >= cb->size ? cb->head + 1 : cb->head;
    cb->cnt=cb->cnt >= cb->size ? cb->size : cb->cnt+1;
}

int read(CircularBuffer *cb) {
    if (cb->cnt==0) {
        cb->head = 0;
        cb->tail = 0;
        printf("Failed to read because buffer is empty.\n");
        return -1;
    }
    int value = cb->buffer[cb->head];
    cb->head = (cb->head+1) % cb->size;
    cb->cnt--;
    return value;
}

void printBuffer(CircularBuffer *cb) {
    if (cb->cnt==0) {
        printf("Buffer is empty\n");
        return;
    }
    printf("[");
    int index = cb->head;
    for (int i = 0; i < cb->cnt; i++) {
        printf("%d ", cb->buffer[index]);
        index = (index + 1) % cb->size;
    }
    printf("]\n");
}

