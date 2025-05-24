// 4. reverse of any number 

#include <stdio.h>

int main() {
    int num, reversed = 0, remainder;

    // Input from the user
    printf("Enter an integer: ");
    scanf("%d", &num);

    // Reverse the number
    while (num != 0) {
        remainder = num % 10;        // Get the last digit
        reversed = reversed * 10 + remainder; // Add it to the reversed number
        num /= 10;                  // Remove the last digit from the number
    }

    printf("Reversed number: %d\n", reversed);

    return 0;
}
