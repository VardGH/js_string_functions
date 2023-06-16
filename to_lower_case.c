#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* to_lower_case(const char *str)
{
    if (str == NULL) {
        return NULL;
    }

    char *result = (char*)malloc(strlen(str) + 1);

    for (int i = 0; i < strlen(str); ++i) {
        if ('A' <= str[i] && str[i] <= 'Z') {
            result[i] = str[i] + ' ';
        } else {
            result[i] = str[i];
        }
    }
    result[strlen(str)] = '\0';

    return result;
}

int main()
{
    const char* str = "Hello, World!";

    char* to_lower = to_lower_case(str);
    if (to_lower != NULL) {
        printf("to_lower_case: %s\n", to_lower);
        free(to_lower);
    }

    return 0;
}