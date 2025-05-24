#include <stdio.h>

int main()
{
    int i = 0;
    char arr[] = "Priyesh is a good bou "; // string literal with \0 automatically added at the end

    while (arr[i] != '\0')
    {
        printf("%c", arr[i]);
        i++;
    }
    printf("\n");
    
    char arr1[]= "Priyesh"; 
    printf("%s", arr1); // %s is used to print a string


    return 0;
}