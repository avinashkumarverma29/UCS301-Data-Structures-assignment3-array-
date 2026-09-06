#include <stdio.h>

char toLowerChar(char ch) {
    // Check if the character is uppercase
    if (ch >= 'A' && ch <= 'Z') {
        return ch + 32; // Convert to lowercase using ASCII offset
    }
    return ch; // Return as-is if not uppercase
}

int main() {
    char ch;
    
    printf("Enter an uppercase character: ");
    scanf(" %c", &ch);
    
    printf("Lowercase character: %c\n", toLowerChar(ch));
    return 0;
}