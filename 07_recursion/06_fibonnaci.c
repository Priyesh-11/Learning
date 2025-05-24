// fibonacci seiries using recursion.

#include <stdio.h>

int fibo(int n);

int main()
{
    int n;
    printf("Enter Nth of fibonnaci series : \n");
    scanf("%d", &n);

     fibo(n);

    printf("the %dth value of fibonacci series is %d\n", n, fibo(n));

    return 0;
}

int fibo(int a){

if (a <=2) return 1;

    
    int x = fibo(a - 1);
    int y = fibo(a - 2);
    int ans = x + y;

    return ans;
}