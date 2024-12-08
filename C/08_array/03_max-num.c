//programm to check minimum number in an array

#include <stdio.h>
#include <limits.h>

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

    int i, max = INT_MAX;
    for (i = 0; i < n; i++)
    {
        if (max > arr[i])
        {
            max = arr[i];
        }
    }
    printf("the minimum number of array is %d", max);

    return 0;
}