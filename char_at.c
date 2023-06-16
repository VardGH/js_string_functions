#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char char_at(const char *str, const int index)
{
    if (str == NULL || index > strlen(str)) {
        return '\0';
    }

    return str[index];
}

int main()
{
    const char str[] = "Hello, world!";

    char result1 = char_at(str, 7);
    printf("Character at index 7: %c\n", result1);
    
    return 0;
}