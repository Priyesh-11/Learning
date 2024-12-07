//today's {29-11-24} codes to write :
//2.Write a program to calculate Permutation nPr of given n and r.

#include <stdio.h>

int npr(int n)
{

    int npr = 1, i;

    for (int i = 1; i <= n; i++)
    {
        npr = npr * i;
    }
    return npr;
}

int main()
{

    int n, r;
    printf("enter n of permutation : \n");
    scanf("%d", &n);

    printf("enter r of permutation : \n");
    scanf("%d", &r);

    int per = npr(n) / (npr(n - r));
    printf("The Permutations of %d items taken %d at a time is %d\n", n, r, per);

    return 0;
}