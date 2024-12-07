//today's {29-11-24} codes to write :
//1.Write a program to calculate Combinations nCr of given n and r.

#include <stdio.h>

int nCr(int n)
{

    int nCr = 1, i;

    for (int i = 1; i <= n; i++)
    {
        nCr = nCr * i;
    }
    return nCr;
}

int main()
{

    int n, r;
    printf("enter n of Combinations : \n");
    scanf("%d", &n);

    printf("enter r of Combinations : \n");
    scanf("%d", &r);

    int com = nCr(n) / (nCr(r) * nCr(n - r));
    printf("The Combinations of %d items taken %d at a time is %d\n", n, r, com);

    return 0;
}