// find the value of Nth term of this GP 10000000000,6666666496,4444444160,2962962688......

#include <stdio.h>

int main()
{
    float n;
    printf("enter the term of GP 10000000000,6666666496,4444444160,2962962688.... to find its values : \n");
    scanf("%f", &n);

    float a = 9999999999;
    for (float i = 1; i <= n; i++)
    {

        printf("the value of %.fth term of GP is %f\n", i, a);
        a = a * 2 / 3;
    }

    return 0;
}