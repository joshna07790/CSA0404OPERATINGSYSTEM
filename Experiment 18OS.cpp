#include <stdio.h>
#include <windows.h>

#define SIZE 5

int buffer[SIZE], in = 0, out = 0;
HANDLE empty, full, mutex;

DWORD WINAPI producer(LPVOID arg) {
    int i;

    for (i = 1; i <= 5; i++) {
        WaitForSingleObject(empty, INFINITE);
        WaitForSingleObject(mutex, INFINITE);

        buffer[in] = i;
        printf("Produced: %d\n", i);
        in = (in + 1) % SIZE;

        ReleaseMutex(mutex);
        ReleaseSemaphore(full, 1, NULL);
    }
    return 0;
}

DWORD WINAPI consumer(LPVOID arg) {
    int i, item;

    for (i = 1; i <= 5; i++) {
        WaitForSingleObject(full, INFINITE);
        WaitForSingleObject(mutex, INFINITE);

        item = buffer[out];
        printf("Consumed: %d\n", item);
        out = (out + 1) % SIZE;

        ReleaseMutex(mutex);
        ReleaseSemaphore(empty, 1, NULL);
    }
    return 0;
}

int main() {
    HANDLE p, c;

    empty = CreateSemaphore(NULL, SIZE, SIZE, NULL);
    full = CreateSemaphore(NULL, 0, SIZE, NULL);
    mutex = CreateMutex(NULL, FALSE, NULL);

    p = CreateThread(NULL, 0, producer, NULL, 0, NULL);
    c = CreateThread(NULL, 0, consumer, NULL, 0, NULL);

    WaitForSingleObject(p, INFINITE);
    WaitForSingleObject(c, INFINITE);

    CloseHandle(p);
    CloseHandle(c);
    CloseHandle(empty);
    CloseHandle(full);
    CloseHandle(mutex);

    return 0;
}