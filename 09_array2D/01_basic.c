// basic array 2D

#include <stdio.h>

int main()
{
    int r, c;
    printf("enter number of rows : ");
    scanf("%d", &r);

    printf("enter number of colume : ");
    scanf("%d", &c);

    int arr[r][c];

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            scanf("%d", &arr[i][j]);
        }

        printf("\n");
    }

    printf("the entered array is : \n");

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            printf("%d  ", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}