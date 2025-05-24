




// #include <stdio.h>

// int grid(int n, int m);

// int main() {
//     int n, m;
//     printf("Enter the number of rows (n): ");
//     scanf("%d", &n);
//     printf("Enter the number of columns (m): ");
//     scanf("%d", &m);
    
//     int result = grid(n, m);
//     printf("The number of possible movements in a %d x %d grid with only right and down moves is: %d\n", n, m, result);
    
//     return 0;
// }

// int grid(int n, int m) {
//     // Base case: if one dimension is 1, there's only one way to reach the end
//     if (n == 1 || m == 1) 
//         return 1;

//     // Recursive case: sum of ways from the top and left cells
//     return grid(n - 1, m) + grid(n, m - 1);
// }
