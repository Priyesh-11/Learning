#include <stdio.h>

int main() {
    int n;

    printf("enter a number to find its divisiability by 5 and 11 :\n");
    scanf("%d",&n);

    if(n%5==0 &&  n%11==0)
    {
       printf("entered number %d is divisiabe by 5 and 11 :\n",n);

    }else{
        printf("entered number %d is not divisiabe by 5 and 11 :\n",n);
    }
    return 0;
}