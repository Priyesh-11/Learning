#include <stdio.h>

void swap(int* a, int* b); //function declare

int main() {

    int a;
    printf("enter number a : ");
    scanf("%d",&a);  //input a

    int b;
    printf("enter number b : ");
    scanf("%d",&b);  //input b

    swap(&a, &b);

    printf("the Swaped value of a is %d\n",a);
    printf("the Swaped value of b is %d\n",b);


    int *c = &a;
    printf("the address of %d is %p\n",a,c);
    int *d = &b;
    printf("the address of %d is %p\n",b,d);

    return 0;
}

void swap(int* x, int* y){

    int temp;
    temp = *x;
    *x = *y ;
    *y = temp;

    int *c = &*x;
    printf("the address of %d is %p\n",*x,c);
    int *d = &*y;
    printf("the address of %d is %p\n",*y,d);

    return;

}
