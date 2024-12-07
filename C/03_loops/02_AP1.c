// find the value of Nth term of this AP 1 5 9 13 .....

#include <stdio.h>

int main() {
    int n;
    printf("enter the term of AP 1,5,9,13... to find its value : ");
    scanf("%d",&n);

    int a=1;
    for ( int i = 1; i <=n ; i++)
    {
       
       printf("the value of %dth term of AP is %d\n",i, a);
       a = a + 4 ;
    }
    
    return 0;
}