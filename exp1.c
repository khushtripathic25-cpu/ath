#include <stdio.h>

int main()
{
    int price[100], n, i, j, key;

    printf("Enter number of products: ");
    scanf("%d", &n);

    printf("Enter product prices:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &price[i]);
    }

    for (i = 1; i < n; i++)
    {
        key = price[i];
        j = i - 1;

        while (j >= 0 && price[j] > key)
        {
            price[j + 1] = price[j];
            j--;
        }

        price[j + 1] = key;
    }

    printf("Prices in ascending order:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", price[i]);
    }

    return 0;
}