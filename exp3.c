#include <stdio.h>

#define MAX 5

int main()
{
    int queue[MAX];
    int front = 0, rear = -1;
    int choice, parcel, i;

    do
    {
        printf("\n\n1. Add Parcel (Enqueue)");
        printf("\n2. Display Parcels");
        printf("\n3. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                if (rear == MAX - 1)
                {
                    printf("Queue is full!\n");
                }
                else
                {
                    printf("Enter parcel number: ");
                    scanf("%d", &parcel);

                    rear++;
                    queue[rear] = parcel;

                    printf("Parcel added successfully!\n");
                }
                break;

            case 2:
                if (rear < front)
                {
                    printf("Queue is empty!\n");
                }
                else
                {
                    printf("Parcels in queue: ");

                    for (i = front; i <= rear; i++)
                    {
                        printf("%d ", queue[i]);
                    }
                    printf("\n");
                }
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