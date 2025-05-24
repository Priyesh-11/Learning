#include <stdio.h>

int sum(int a, int b);// declaration/ prototype


int main()
{
    int a, b;

    printf("enter your number to find its sum :");
    scanf("%d", &a);
    scanf("%d", &b);  // user input 
    
  int s= sum(a,b); // storing the return value 


        printf("the sum is : %d", s);  //printing the return value
    return 0;
} 
int sum(int a, int b){   //defination

return a+b;// return

}




// #include <stdio.h>

// int sum(int a, int b);

// int main()
// {
//     int a, b;

//     printf("Enter two numbers to find their sum:\n");
//     scanf("%d", &a);
//     scanf("%d", &b);

//     int result = sum(a, b); // Function call and storing the return value
//     printf("The sum is: %d\n", result); // Printing the sum

//     return 0;
// }

// int sum(int a, int b) {
//     return a + b; // Adding and returning the result
// }
