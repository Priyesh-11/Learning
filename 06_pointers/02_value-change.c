#include <stdio.h>

int main() {

    int n;
    printf("enter a number : ");
    scanf("%d", &n); 


    int* x = &n;

    printf("the value of n using pointer is %d\n",*x);
    printf("the address of entred no %d is %p\n",n,x);

    int m;
    printf("enter a number to change previous number value : ");
    scanf("%d", &m); 
    *x = m;

 
 
    printf("the value of n using pointer is %d\n",*x);
    printf("the address of entred no %d is %p\n",n,x);

  


    return 0;
}