#include <stdio.h>

int main() {

    int a;
    printf("enter number a : ");
    scanf("%d",&a);

    int b;
    printf("enter number b : ");
    scanf("%d",&b);

    a = a + b;
    b = a - b;
    a = a - b;

    printf("the Swaped value of a is %d\n",a);
    printf("the Swaped value of b is %d\n",b);

    return 0;
}