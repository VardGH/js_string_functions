#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char* substring(const char *str, const int start)
{
    if (str == NULL || start < 0) {
        return NULL;
    }

    char *result = (char*)malloc(sizeof(char) * (strlen(str) - start + 1));

    for (int i = start, j = 0; i < strlen(str); ++i) {
        result[j++] = str[i];
    }
    result[strlen(str) - start] = '\0';
    return result;
}

int main()
{
    const char* str = "Hello, World!";
    int start = 7;

    char* sub = substring(str, start);
    if (sub != NULL) {
        printf("Substring: %s\n", sub);
        free(sub);
    }

    return 0;
}