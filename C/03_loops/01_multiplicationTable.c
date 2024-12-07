#include <stdio.h>

int main()
{
    int a;
    int i;

    printf("Enter a integer to find its multiplication table : ");
    scanf("%d", &a);

    for (i = 1; i <= 10; i++)
    {
        printf("The multiplication table of '%d' is '%d x %d' = '%d' \n", a, a, i, a * i);
    }
}