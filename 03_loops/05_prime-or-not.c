#include <stdio.h>

int main()
{

    int n, i;
    printf("enter a number to find if it is prime or composite : \n");
    scanf("%d", &n);

    int a = 0;
    for (i = 2; i < n; i++)
    {
        if (n % i == 0)
        {
            a = 1;
            break;
        }
    }
    if (n < 0)
    {
        printf("the entered number is Negetive, It cannot be defines as prime or composite\n");
    }

    else if (n == 1 || n == 0)
    {
        printf("%d is neither prime or composite\n", n);
    }
    else if (a == 0)
    {
        printf("the entered number %d is prime\n", n);
    }
    else
    {
        printf("the entered number %d is composite\n", n);
    }
    return 0;
}