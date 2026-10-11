#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    char text[100];
    struct Node *next;
};

struct Node *head = NULL;

void insert()
{
    struct Node *newNode, *temp;
    char line[100];

    newNode = (struct Node *)malloc(sizeof(struct Node));

    if (newNode == NULL)
    {
        printf("Memory allocation failed!\n");
        return;
    }

    printf("Enter a line of text: ");
    scanf(" %99[^\n]", line);

    strcpy(newNode->text, line);
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        temp = head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    printf("Line inserted successfully!\n");
}

void display()
{
    struct Node *temp = head;

    if (head == NULL)
    {
        printf("Linked list is empty!\n");
        return;
    }

    printf("\nLines of text:\n");

    while (temp != NULL)
    {
        printf("%s\n", temp->text);
        temp = temp->next;
    }
}

int main()
{
    int choice;

    do
    {
        printf("\n1. Insert Line");
        printf("\n2. Display Lines");
        printf("\n3. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                insert();
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