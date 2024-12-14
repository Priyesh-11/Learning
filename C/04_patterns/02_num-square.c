// number square pattern

#include <stdio.h>

int main()
{
    int n, m;
    printf("enter no. of rows : ");
    scanf("%d", &n);

    printf("enter no. of columns : ");
    scanf("%d", &m);

    for (int i = 1; i <= n; i++)
    {
        printf("\n%d column -> ",i);
        for (int j = 1; j <= m; j++)
        {
            printf("%d ",j);
        }
    }

    return 0;
}