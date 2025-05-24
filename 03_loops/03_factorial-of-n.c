// 3. Find the Factorial of a Number

#include <stdio.h>

int main()
{

    int n, a = 1;
    printf("Enter any Natural number to find its factorial : \n");
    scanf("%d", &n);

    if (n < 0)
    {
        printf("the entered number %d is negative\n", n);
    }
    else
    {

        for (int i = 1; i <= n; i++)
        {
            // printf("%d\n",a);
            a = a * i;
        }
        printf("The factorial of the first %d natural numbers is : %d\n", n, a);
    }
    return 0;
}
