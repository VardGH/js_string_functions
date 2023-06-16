#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* to_upper_case(const char *str)
{
    if (str == NULL) {
        return NULL;
    }

    char *result = (char*)malloc(strlen(str) + 1);

    for (int i = 0; i < strlen(str); ++i) {
        if ('a' <= str[i] && str[i] <= 'z') {
            result[i] = str[i] - ' ';
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

    char* to_upper = to_upper_case(str);
    if (to_upper != NULL) {
        printf("to_lower_case: %s\n", to_upper);
        free(to_upper);
    }

    return 0;
}