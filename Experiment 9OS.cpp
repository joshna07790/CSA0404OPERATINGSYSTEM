#include <stdio.h>
#include <string.h>

int main()
{
    FILE *fp;
    char data[100];

    fp = fopen("shared_memory.txt", "w");

    if (fp == NULL)
    {
        printf("Unable to create shared memory.\n");
        return 1;
    }

    strcpy(data, "Hello, shared memory!");

    fprintf(fp, "%s", data);
    fclose(fp);

    printf("Data written to shared memory: %s\n", data);

    fp = fopen("shared_memory.txt", "r");

    if (fp == NULL)
    {
        printf("Unable to access shared memory.\n");
        return 1;
    }

    fgets(data, sizeof(data), fp);
    fclose(fp);

    printf("Data read from shared memory: %s\n", data);

    return 0;
}