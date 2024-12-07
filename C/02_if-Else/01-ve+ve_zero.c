#include <stdio.h>

int main() {
    float n;

    printf("Enter a to find its nature : ");
    scanf("%f", &n);

    if (n>0)
    {
       printf("Entered number %.2f is POSITIVE",n);

    }else if (n<0)
    {
         printf("Entered number %.2f is NEGATIVE",n);

    }else {
        
         printf("Entered number %.2f is ZERO",n);

    }
    
    

    return 0;
}