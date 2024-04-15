#ifndef CIRCULAR_BUFFER_H
#define CIRCULAR_BUFFER_H

#include <stdbool.h>

typedef struct {
    int *buffer;
    int head;
    int tail;
    int size;
    int cnt;
} CircularBuffer;

CircularBuffer *createBuffer(int size);
void freeBuffer(CircularBuffer *cb);
void write(CircularBuffer *cb, int value, bool overwrite);
int read(CircularBuffer *cb);
void printBuffer(CircularBuffer *cb);

#endif // CIRCULAR_BUFFER_H
