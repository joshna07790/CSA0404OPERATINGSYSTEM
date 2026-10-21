#include <stdio.h>
#include <windows.h>

HANDLE mutex;
int counter = 0;

DWORD WINAPI increment(LPVOID arg) {
    int i;

    for (i = 0; i < 100000; i++) {
        WaitForSingleObject(mutex, INFINITE);
        counter++;
        ReleaseMutex(mutex);
    }

    return 0;
}

int main() {
    HANDLE t1, t2;

    mutex = CreateMutex(NULL, FALSE, NULL);

    t1 = CreateThread(NULL, 0, increment, NULL, 0, NULL);
    t2 = CreateThread(NULL, 0, increment, NULL, 0, NULL);

    WaitForSingleObject(t1, INFINITE);
    WaitForSingleObject(t2, INFINITE);

    printf("Final counter value: %d\n", counter);

    CloseHandle(t1);
    CloseHandle(t2);
    CloseHandle(mutex);

    return 0;
}