// find the value of Nth term of this GP 3,12,48......
#include <stdio.h>

int main()
{
    int n;
    printf("enter the term of GP 3,12,48.... to find its values : \n");
    scanf("%d", &n);

    int a = 3;
    for (int i = i; i <= n; i++)
    {
        printf("the value of %dth term of GP is %d\n", i, a);
        a = a * 4;
    }

    return 0;
}