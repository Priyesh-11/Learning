// the index of students having marks less than 35.

#include <stdio.h>

int main()
{
    int marks[10];
    for (int i = 0; i < 10; i++)
    {
        printf("enter %d studemts marks : ", i + 1);
        scanf("%d", &marks[i]);
    }

    int c;
    for (int i = 0; i < 10; i++)
    {
        if (marks[i] < 35)
        {
            printf("the index of students having marks less than 35 is %d\n", i);
            c = 1;
        }
    }
    if (c != 1)
    {
        printf("no studet has marks less than 35");
    }

    return 0;
}