#include <stdio.h>
#include <windows.h>

DWORD WINAPI threadFunction(LPVOID arg) {
    printf("Inside the thread\n");
    return 0;
}

int main() {
    HANDLE thread;
    DWORD threadId;

    thread = CreateThread(
        NULL, 0, threadFunction, NULL, 0, &threadId
    );

    if (thread == NULL) {
        printf("Thread creation failed\n");
        return 1;
    }

    printf("Thread created successfully\n");

    if (GetThreadId(thread) == threadId)
        printf("Thread IDs are equal\n");

    WaitForSingleObject(thread, INFINITE);
    printf("Thread joined successfully\n");

    CloseHandle(thread);
    printf("Main program completed\n");

    return 0;
}