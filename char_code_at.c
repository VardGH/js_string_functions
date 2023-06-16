#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int char_code_at(const char *str, const int index)
{
    if (str == NULL || abs(index) > strlen(str)) {
        return '\0';
    }

    return (int)str[index];
}

int main() {
    const char* str = "Hello, world!";
    
    int result = char_code_at(str, 7);
    printf("ASCII value at index 7: %d\n", result);
    
    return 0;
}