#include <stdio.h>
#include <string.h>
#include <ctype.h>

void removeVowels(char str[]) {
    int i = 0, j = 0;
    
    while (str[i] != '\0') {
        char ch = tolower(str[i]);
        if (ch != 'a' && ch != 'e' && ch != 'i' && ch != 'o' && ch != 'u') {
            str[j++] = str[i];
        }
        i++;
    }
    str[j] = '\0';
}

int main() {
    char str[100];
    
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = 0;
    
    removeVowels(str);
    
    printf("String after removing vowels: %s\n", str);
    return 0;
}