#include <stdio.h>
#include <string.h>

int main()
{
    FILE *fp;
    char message[100];

    strcpy(message, "Hello, message queue!");

    fp = fopen("message_queue.txt", "w");

    if (fp == NULL)
    {
        printf("Unable to create message queue.\n");
        return 1;
    }

    fprintf(fp, "%s", message);
    fclose(fp);

    printf("Producer: Data sent to message queue: %s\n", message);

    fp = fopen("message_queue.txt", "r");

    if (fp == NULL)
    {
        printf("Unable to receive message.\n");
        return 1;
    }

    fgets(message, sizeof(message), fp);
    fclose(fp);

    printf("Consumer: Data received from message queue: %s\n", message);

    return 0;
}