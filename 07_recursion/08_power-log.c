// calculate power {logrithmic} using recursion

#include <stdio.h>

int logpower(int a, int b);

int main()
{
    int a, b;
    printf("Enter base : \n");
    scanf("%d", &a);

    printf("Enter power : \n");
    scanf("%d", &b);

    logpower(a, b);

    printf("the base %d raised to power %d is %d\n", a, b, logpower(a, b));

    return 0;
}

int logpower(int a, int b)
{
    int x;
    if (b == 1)
        return a;
    if (b % 2 == 0)
    {
        x = logpower(a, b / 2);
        return x * x;
    }
    if (b % 2 != 0)
    {
        x = logpower(a, b / 2);
        return x * x * a;
    }
}