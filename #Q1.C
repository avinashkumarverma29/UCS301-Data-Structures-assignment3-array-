#include <stdio.h>
#include <string.h>
#include <ctype.h>

void removeVowels(char str[]) {
    int i, j = 0;
    int len = strlen(str);
    
    for (i = 0; i < len; i++) {
        // Convert character to lowercase to easily check for vowels
        char ch = tolower(str[i]);
        
        // Check if the character is NOT a vowel
        if (ch != 'a' && ch != 'e' && ch != 'i' && ch != 'o' && ch != 'u') {
            str[j++] = str[i];
        }
    }
    // Null-terminate the modified string
    str[j] = '\0';
}

int main() {
    char str[100];
    
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    
    // Remove the newline character if it exists from fgets
    str[strcspn(str, "\n")] = 0;
    
    removeVowels(str);
    
    printf("String after removing vowels: %s\n", str);
    
    return 0;
}