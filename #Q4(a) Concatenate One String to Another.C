#include <stdio.h>

void stringConcatenate(char str1[], char str2[]) {
    int i = 0, j = 0;
    
    // Find the end of the first string
    while (str1[i] != '\0') {
        i++;
    }
    
    // Copy characters from the second string to the end of the first
    while (str2[j] != '\0') {
        str1[i] = str2[j];
        i++;
        j++;
    }
    
    // Null-terminate the combined string
    str1[i] = '\0';
}

int main() {
    char str1[200], str2[100];
    
    printf("Enter the first string: ");
    fgets(str1, sizeof(str1), stdin);
    str1[strcspn(str1, "\n")] = 0; // Remove newline
    
    printf("Enter the second string to concatenate: ");
    fgets(str2, sizeof(str2), stdin);
    str2[strcspn(str2, "\n")] = 0;
    
    stringConcatenate(str1, str2);
    
    printf("Concatenated string: %s\n", str1);
    return 0;
}