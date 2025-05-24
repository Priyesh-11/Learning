// print 1 to n using recursion.

#include <stdio.h>

void increase(int n);

int main()
{
    int n;
    printf("enter n  : ");
    scanf("%d", &n);

    increase(n);

    // printf("The factorial of the %d number is : %d\n", n, facto(n));
    return 0;
}

void increase(int n)
{

    if (n <= 0)
        return;

    increase(n - 1);
    printf("%d\n", n);
    

    return;
}
