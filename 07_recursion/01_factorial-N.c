// factorial of n using recursion.

#include <stdio.h>

int facto(int n);

int main()
{
    int n;
    printf("enter a number to find its factorial : ");
    scanf("%d", &n);

    facto(n);

    printf("The factorial of the %d number is : %d\n", n, facto(n));

    return 0;
}

int facto(int n)
{

    if (n == 0)
        return 1;
    int fac = n * facto(n - 1);
    // printf("%d\n", fac);
    return fac;
}
