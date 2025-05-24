// number of triplets whose sum add up to "X"
#include <stdio.h>

int main()
{

    int n;
    printf("enter the the number of elements of array {must be greater than 3} : ");
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        printf("enter the %d element of the array : ", i + 1);
        scanf("%d", &arr[i]);
    }

    int x;
    printf("enter 'x' to find number of triplets whose sum add up to X : ");
    scanf("%d", &x);

    int tripletcount = 0;
    for (int i = 0; i < n - 2; i++)
    {
        for (int j = i + 1; j < n - 1; j++)
        {
            for (int k = j + 1; k < n; k++)
            {

                if (arr[i] + arr[j] + arr[k] == x)
                {
                    tripletcount++;
                    printf("The pairs are (%d,%d,%d)\n", arr[i], arr[j], arr[k]);
                }
            }
        }
    }
    printf("The number of triplets whose sum add up to '%d' is %d \n", x, tripletcount);

    return 0;
}
