// stat path , only 2 steps at a time.

#include <stdio.h>

int path(int n);

int main()
{
    int n;
    printf("Enter Nth step of star path  : \n");
    scanf("%d", &n);

     path(n);

    printf("the %dth step of star path can be performed in %d ways\n", n, path(n));

    return 0;
}

int path(int a){

if (a <=2) return 1;

    
    int x = path(a - 1);
    int y = path(a - 2);
    int ans = x + y;

    return ans;
}