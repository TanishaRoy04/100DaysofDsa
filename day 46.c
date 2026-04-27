Q91: Remove all vowels from a string.

/*
Sample Test Cases:
Input 1:
education
Output 1:
dctn

*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char str[100], result[100];
    int i, j = 0;

    // Input the string
    scanf("%s", str);

    for (i = 0; str[i] != '\0'; i++) {
        char ch = tolower(str[i]);
        // Check if character is NOT a vowel
        if (ch != 'a' && ch != 'e' && ch != 'i' && ch != 'o' && ch != 'u') {
            result[j++] = str[i];
        }
    }
    result[j] = '\0'; // Null-terminate the result string

    printf("%s", result);

    return 0
