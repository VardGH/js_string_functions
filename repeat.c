#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* repeat(const char *str, const int count)
{
    if (str == NULL || count < 0) {
        return NULL;
    }

    char *result = (char*)malloc((strlen(str) * count + 1) * sizeof(char));

    if (result == NULL) {
        return NULL;
    }

    strcpy(result, "");

    for (int i = 0; i < count; ++i) {
        strcat(result, str);
    }
    return result;   
}

int main()
{
    const char* str = "Hello ";
    int count = 3;

    char* repeated_str = repeat(str, count);
    if (repeated_str != NULL) {
        printf("Repeated string: %s\n", repeated_str);
        free(repeated_str);
    }
}