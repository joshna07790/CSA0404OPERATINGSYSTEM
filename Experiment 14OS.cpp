#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFFER_SIZE 4096

#define SOURCE_FILE "C:/Users/itssk/OneDrive/Desktop/sasi.txt"
#define DESTINATION_FILE "C:/Users/itssk/OneDrive/Desktop/sk.txt"

void create()
{
    FILE *fp;

    fp = fopen(SOURCE_FILE, "w");

    if (fp == NULL)
    {
        printf("File creation failed.\n");
        return;
    }

    fclose(fp);

    printf("File created successfully.\n");
}

void copy()
{
    int source_fd, dest_fd;
    char buffer[BUFFER_SIZE];
    ssize_t bytesRead, bytesWritten;

    source_fd = open(SOURCE_FILE, O_RDONLY);

    if (source_fd == -1)
    {
        printf("Source file could not be opened.\n");
        return;
    }

    dest_fd = open(DESTINATION_FILE, O_WRONLY | O_CREAT | O_TRUNC, 0666);

    if (dest_fd == -1)
    {
        printf("Destination file could not be opened.\n");
        close(source_fd);
        return;
    }

    while ((bytesRead = read(source_fd, buffer, BUFFER_SIZE)) > 0)
    {
        bytesWritten = write(dest_fd, buffer, bytesRead);

        if (bytesWritten != bytesRead)
        {
            printf("File copy failed.\n");
            close(source_fd);
            close(dest_fd);
            return;
        }
    }

    close(source_fd);
    close(dest_fd);

    printf("File copied successfully.\n");
}

void deleteFile()
{
    if (remove(SOURCE_FILE) == 0)
    {
        printf("File deleted successfully.\n");
    }
    else
    {
        printf("File deletion failed.\n");
    }
}

int main()
{
    int n;

    printf("1. Create\n");
    printf("2. Copy\n");
    printf("3. Delete\n");

    printf("Enter your choice: ");
    scanf("%d", &n);

    switch (n)
    {
        case 1:
            create();
            break;

        case 2:
            copy();
            break;

        case 3:
            deleteFile();
            break;

        default:
            printf("Invalid choice.\n");
    }

    return 0;
}