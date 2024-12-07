// product of n array elements

#include <stdio.h>

int main()
{

    int n;
    printf("enter number of elements in array : ");
    scanf("%d", &n);

    int arr[n], i;
    int pro = 1;
    for (i = 0; i <= n - 1; i++)
    {
        printf("enter %d element of the array : ", i + 1);
        scanf("%d", &arr[i]);
        pro = pro * arr[i];
    }
    printf("the product of first %d elements of array is :  %d\n", n, pro);

    return 0;
}