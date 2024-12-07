#include <stdio.h>

int main() {

    int n;
    printf("enter a number : ");
    scanf("%d", &n); 

    int m;
    printf("enter another number : ");
    scanf("%d", &m); 

    int* x = &n;
    int* y = &m;

    printf("the value of n is %d\n",n);
    printf("the value of n using pointer is %d\n",*x);
    printf("the address of entred no %d is %p\n",n,x);

    printf("the value of m is %d\n",m);
    printf("the value of m using pointer is %d\n",*y);
    printf("the address of entred no %d is %p\n",m,y);


    return 0;
}