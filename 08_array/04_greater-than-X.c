// count the array elements greater than X
#include <stdio.h>

int main()
{

    int n;
    printf("enter the the number of elements of array : ");
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        printf("enter the %d element of the array : ", i + 1);
        scanf("%d", &arr[i]);
    }

    int x;
    printf("enter 'x' to find no. of elements greater than x : ");
    scanf("%d", &x);

    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > x)
        {
            count++;
        }
    }
    printf("The no. of elements greater than x is %d", count);

    return 0;
}