#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char at(const char *str, const int index)
{
    if (str == NULL || abs(index) > strlen(str)) {
        return '\0';
    }

    if (index >= 0) {
        return str[index];
    } else {
        return str[strlen(str) - abs(index)];
    }
}

int main()
{
    const char str[] = "Hello, world!";

    char result1 = at(str, 7);
    printf("Character at index 7: %c\n", result1);

    char result2 = at(str, -4);
    printf("Character at index -4: %c\n", result2);
    
    return 0;
}