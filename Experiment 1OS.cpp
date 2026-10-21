#include <stdio.h>
#include <windows.h>
#include <tlhelp32.h>

DWORD GetParentProcessID(DWORD processID)
{
    HANDLE hSnapshot;
    PROCESSENTRY32 pe32;
    DWORD parentPID = 0;

    hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);

    if (hSnapshot == INVALID_HANDLE_VALUE)
        return 0;

    pe32.dwSize = sizeof(PROCESSENTRY32);

    if (Process32First(hSnapshot, &pe32))
    {
        do
        {
            if (pe32.th32ProcessID == processID)
            {
                parentPID = pe32.th32ParentProcessID;
                break;
            }
        } while (Process32Next(hSnapshot, &pe32));
    }

    CloseHandle(hSnapshot);

    return parentPID;
}

int main()
{
    DWORD processID;
    DWORD parentProcessID;

    processID = GetCurrentProcessId();
    parentProcessID = GetParentProcessID(processID);

    printf("Current Process ID (PID): %lu\n", processID);
    printf("Parent Process ID (PPID): %lu\n", parentProcessID);

    return 0;
}