Q93: Check if two strings are anagrams of each other.

/*
Sample Test Cases:
Input 1:
listen
silent
Output 1:
Anagrams

Input 2:
hello
world
Output 2:
Not anagrams

*/



#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char str1[100], str2[100];
    int count1[256] = {0}, count2[256] = {0};
    int i;

    // Input strings
    scanf("%s", str1);
    scanf("%s", str2);

    // If lengths differ, they can’t be anagrams
    if (strlen(str1) != strlen(str2)) {
        printf("Not anagrams\n");
        return 0;
    }

    // Count character frequencies for both strings
    for (i = 0; str1[i] != '\0'; i++) {
        count1[(unsigned char)tolower(str1[i])]++;
        count2[(unsigned char)tolower(str2[i])]++;
    }

    // Compare frequency arrays
    for (i = 0; i < 256; i++) {
        if (count1[i] != count2[i]) {
            printf("Not anagrams\n");
            return 0;
        }
    }

    printf("Anagrams\n");
    return 0;
}
