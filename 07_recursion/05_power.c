// calculate power using recursion

#include <stdio.h>

int power(int a, int b);

int main() {
    int a,b;
    printf("Enter base : \n");
    scanf("%d",&a);

    printf("Enter power : \n");
    scanf("%d",&b);

    power(a,b);

    printf("the base %d raised to power %d is %d\n",a,b,power(a,b));

    return 0;
}


int power(int a, int b){

    if (b==0) return 1;
    
    return a*power(a,b-1);

}