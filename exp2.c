#include <stdio.h>

struct Student
{
    int roll;
    char name[50];
    char program[30];
    char course[30];
    float marks;
};

int main()
{
    struct Student s[100];
    int n, i, choice, r, found;

    printf("Enter number of students: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("\nEnter details of student %d\n", i + 1);

        printf("Roll No: ");
        scanf("%d", &s[i].roll);

        printf("Name: ");
        scanf("%49s", s[i].name);

        printf("Program: ");
        scanf("%29s", s[i].program);

        printf("Course: ");
        scanf("%29s", s[i].course);

        printf("Subject Marks: ");
        scanf("%f", &s[i].marks);
    }

    printf("\n1. Search Student");
    printf("\n2. Modify Student Record");
    printf("\nEnter choice: ");
    scanf("%d", &choice);

    printf("Enter roll number: ");
    scanf("%d", &r);

    found = 0;

    for (i = 0; i < n; i++)
    {
        if (s[i].roll == r)
        {
            found = 1;

            if (choice == 1)
            {
                printf("\nRoll No: %d", s[i].roll);
                printf("\nName: %s", s[i].name);
                printf("\nProgram: %s", s[i].program);
                printf("\nCourse: %s", s[i].course);
                printf("\nMarks: %.2f\n", s[i].marks);
            }
            else if (choice == 2)
            {
                printf("Enter new name: ");
                scanf("%49s", s[i].name);

                printf("Enter new program: ");
                scanf("%29s", s[i].program);

                printf("Enter new course: ");
                scanf("%29s", s[i].course);

                printf("Enter new marks: ");
                scanf("%f", &s[i].marks);

                printf("Record modified successfully!\n");
            }
            else
            {
                printf("Invalid choice!\n");
            }

            break;
        }
    }

    if (found == 0)
        printf("Student not found!\n");

    return 0;
}