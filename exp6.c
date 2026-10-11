#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    char name[50];
    struct Node *left;
    struct Node *right;
};

struct Node *insert(struct Node *root, char name[])
{
    if (root == NULL)
    {
        struct Node *newNode;

        newNode = (struct Node *)malloc(sizeof(struct Node));

        if (newNode == NULL)
        {
            printf("Memory allocation failed!\n");
            exit(1);
        }

        strcpy(newNode->name, name);
        newNode->left = NULL;
        newNode->right = NULL;

        return newNode;
    }

    if (strcmp(name, root->name) < 0)
    {
        root->left = insert(root->left, name);
    }
    else if (strcmp(name, root->name) > 0)
    {
        root->right = insert(root->right, name);
    }

    return root;
}

void postorder(struct Node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%s ", root->name);
    }
}

int main()
{
    struct Node *root = NULL;
    char name[50];
    int n, i;

    printf("Enter number of users: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter user name: ");
        scanf("%49s", name);

        root = insert(root, name);
    }

    printf("\nPostorder Traversal:\n");
    postorder(root);

    printf("\n");

    return 0;
}