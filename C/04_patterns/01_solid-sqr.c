// solid square pattern

#include <stdio.h>

int main()
{
    int n, m;
    printf("enter n :");
    scanf("%d", &n);

    printf("enter m :");
    scanf("%d", &m);

    for (int i = 1; i <= n; i++)
    {
        for (int i = 0; i <= m; i++)
        {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}