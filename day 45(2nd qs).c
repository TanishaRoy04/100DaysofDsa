Q90: Toggle case of each character in a string.

/*
Sample Test Cases:
Input 1:
Hello
Output 1:
hELLO

*/

/*Toggle case of each character in a string.
Input 1:
Hello
Output 1:
hELLO*/
#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    int i;

    printf("Enter a string: ");
    scanf("%s", str);  // For single word (no spaces). Use fgets for full sentences.

    for (i = 0; i < strlen(str); i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = str[i] - 32; // convert to uppercase
        } else if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = str[i] + 32; // convert to lowercase
        }
    }

    printf("Toggled case string: %s\n", str);

    return 0;
}