// print n to 1 using recursion.

#include <stdio.h>

void decrease(int n);

int main()
{
    int n;
    printf("enter n  : ");
    scanf("%d", &n);

    decrease(n);

    // printf("The factorial of the %d number is : %d\n", n, facto(n));
    return 0;
}

void decrease(int n)
{

    if (n <= 0)
        return;

    printf("%d\n", n);
    decrease(n - 1);

    return;
}
