#include <stdio.h>

int main() {
    char n;

    printf("Enter a letter to find its nature : \n");
    scanf("%c", &n);

    if (n=='a',n=='e',n=='i',n=='o',n=='u', n=='A',n=='E',n=='I',n=='O',n=='U')
    {
       printf("Entered Letter %c is VOWEL\n",n);

    }else {
        
         printf("Entered Letter %c is CONSONANT\n",n);

    }
    

    return 0;
}