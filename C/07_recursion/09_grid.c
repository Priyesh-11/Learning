// grid of n * m where can only go right and down

int grid (int n, int m);

#include <stdio.h>

int main() {
    int n;
    printf("enter n of grid : ");
    scanf("%d",&n);

    int m;
    printf("enter m of grid : ");
    scanf("%d",&m);
    
    grid(n,m);

    printf("the number of possible movement in %d x %d grid wth only right down movws is %d", n,m, grid(n,m));
     
    return 0;
}

int grid(int n, int m){

    int ways = 0;

    if(n == 1 || m == 1) return 1;
//     if(n==1){
//     ways +=  grid(n,m-1);
//     }
//     if(m==1){
//     ways +=  grid(n-1,m);
// }
    else{
    ways = grid(n-1,m) + grid(n,m-1);
    }

   // printf("%d",ways);

    return ways;
}