#include <stdio.h>

struct Employee {
    int id;
    char name[30];
    float salary;
};

int main() {
    FILE *fp;
    struct Employee e;
    int n, pos, i;

    fp = fopen("employee.dat", "wb+");

    if (fp == NULL) {
        printf("File error");
        return 1;
    }

    printf("Enter number of employees: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter ID, name and salary: ");
        scanf("%d %29s %f", &e.id, e.name, &e.salary);
        fwrite(&e, sizeof(e), 1, fp);
    }

    printf("Enter employee position: ");
    scanf("%d", &pos);

    if (pos >= 1 && pos <= n) {
        fseek(fp, (pos - 1) * sizeof(e), SEEK_SET);
        fread(&e, sizeof(e), 1, fp);

        printf("\nEmployee Details\n");
        printf("ID: %d\n", e.id);
        printf("Name: %s\n", e.name);
        printf("Salary: %.2f\n", e.salary);
    } else {
        printf("Invalid position");
    }

    fclose(fp);
    return 0;
}