#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    char webpage[100];
    struct Node *next;
};

struct Node *top = NULL;

void push()
{
    struct Node *newNode;
    char page[100];

    newNode = (struct Node *)malloc(sizeof(struct Node));

    if (newNode == NULL)
    {
        printf("Memory allocation failed!\n");
        return;
    }

    printf("Enter webpage name or URL: ");
    scanf(" %99[^\n]", page);

    strcpy(newNode->webpage, page);

    newNode->next = top;
    top = newNode;

    printf("Webpage added to history!\n");
}

void display()
{
    struct Node *temp = top;

    if (top == NULL)
    {
        printf("Browser history is empty!\n");
        return;
    }

    printf("\nBrowser History (Latest First):\n");

    while (temp != NULL)
    {
        printf("%s\n", temp->webpage);
        temp = temp->next;
    }
}

int main()
{
    int choice;

    do
    {
        printf("\n1. Push (Visit Webpage)");
        printf("\n2. Display History");
        printf("\n3. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                push();
                break;

            case 2:
                display();
                break;

            case 3:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while (choice != 3);

    return 0;
}