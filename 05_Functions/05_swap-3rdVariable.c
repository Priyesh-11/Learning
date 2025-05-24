#include <stdio.h>

int main() {

    int a;
    printf("enter number a : ");
    scanf("%d",&a);

    int b;
    printf("enter number b : ");
    scanf("%d",&b);

    int temp;
    temp = a;
    a = b ;
    b = temp;

    printf("the Swaped value of a is %d\n",a);
    printf("the Swaped value of b is %d\n",b);

    return 0;
}