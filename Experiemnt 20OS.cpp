#include <stdio.h>
#include <windows.h>
#include <stdint.h>

HANDLE rw_mutex, read_mutex;
int read_count = 0;
int data = 10;

DWORD WINAPI reader(LPVOID arg) {
    int id = (int)(intptr_t)arg;

    WaitForSingleObject(read_mutex, INFINITE);
    read_count++;

    if (read_count == 1)
        WaitForSingleObject(rw_mutex, INFINITE);

    ReleaseMutex(read_mutex);

    printf("Reader %d reads data: %d\n", id, data);

    WaitForSingleObject(read_mutex, INFINITE);
    read_count--;

    if (read_count == 0)
        ReleaseMutex(rw_mutex);

    ReleaseMutex(read_mutex);
    return 0;
}

DWORD WINAPI writer(LPVOID arg) {
    WaitForSingleObject(rw_mutex, INFINITE);

    data += 10;
    printf("Writer updates data: %d\n", data);

    ReleaseMutex(rw_mutex);
    return 0;
}

int main() {
    HANDLE r1, r2, w1;

    rw_mutex = CreateMutex(NULL, FALSE, NULL);
    read_mutex = CreateMutex(NULL, FALSE, NULL);

    r1 = CreateThread(NULL, 0, reader, (LPVOID)(intptr_t)1, 0, NULL);
    r2 = CreateThread(NULL, 0, reader, (LPVOID)(intptr_t)2, 0, NULL);
    w1 = CreateThread(NULL, 0, writer, NULL, 0, NULL);

    WaitForSingleObject(r1, INFINITE);
    WaitForSingleObject(r2, INFINITE);
    WaitForSingleObject(w1, INFINITE);

    CloseHandle(r1);
    CloseHandle(r2);
    CloseHandle(w1);
    CloseHandle(rw_mutex);
    CloseHandle(read_mutex);

    return 0;
}