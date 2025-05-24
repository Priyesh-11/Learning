//  1.Print the Sum of the First N Natural Numbers.

#include <stdio.h>

int main()
{

    int n, a = 0;
    printf("Enter any Natural number to find its sum : \n");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
    {
        a = a + i;
    }
    printf("The sum of the first %d natural numbers is : %d\n", n, a);

    return 0;
}
