#include "circular_buffer.h"

void test(CircularBuffer *cb, bool overwrite);

int main() {
    // Buffer size
    int size=5;
    CircularBuffer *cb = createBuffer(size);
    // Overflow condition Option
    bool overwrite = true;
    // Test
    test(cb, overwrite);
}

void test(CircularBuffer *cb, bool overwrite) {
    write(cb, 1, overwrite);
    printBuffer(cb);
    write(cb, 2, overwrite);
    printBuffer(cb);
    write(cb, 3, overwrite);
    printBuffer(cb);
    write(cb, 4, overwrite);
    printBuffer(cb);
    write(cb, 5, overwrite);
    printBuffer(cb);
    write(cb, 6, overwrite);
    printBuffer(cb);
    write(cb, 7, overwrite);
    printBuffer(cb);
    write(cb, 8, overwrite);
    printBuffer(cb);
    printf("read %d\n", read(cb));
    printBuffer(cb);
    printf("read %d\n", read(cb));
    printBuffer(cb);
    printf("read %d\n", read(cb));
    printBuffer(cb);
    printf("read %d\n", read(cb));
    printBuffer(cb);
    printf("read %d\n", read(cb));
    printBuffer(cb);
    printf("read %d\n", read(cb));
    printBuffer(cb);
    printf("read %d\n", read(cb));
    printBuffer(cb);
    write(cb, 1, overwrite);
    printBuffer(cb);
    write(cb, 2, overwrite);
    printBuffer(cb);
    write(cb, 3, overwrite);
    printBuffer(cb);
    write(cb, 4, overwrite);
    printBuffer(cb);
    write(cb, 5, overwrite);
    printBuffer(cb);
    write(cb, 6, overwrite);
    printBuffer(cb);
    write(cb, 7, overwrite);
    printBuffer(cb);
    write(cb, 8, overwrite);
    printBuffer(cb);
    printf("read %d\n", read(cb));
    printBuffer(cb);
    printf("read %d\n", read(cb));
    printBuffer(cb);
    write(cb, 1, overwrite);
    printBuffer(cb);
    write(cb, 2, overwrite);
    printBuffer(cb);
    freeBuffer(cb);
}

