#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* concat(const char *str1, const char *trim, const char *str2)
{
    char *result = (char*)malloc(strlen(str1) + strlen(trim) + strlen(str2) + 1);

    if (result == NULL) {
        printf("Memory allocation failed!");
        return NULL;
    }

    int i, j;
    for (i = 0; i < strlen(str1); ++i) {
        result[i] = str1[i];
    }

    for (j = 0; j < strlen(trim); ++i, ++j) {
        result[i] = trim[j];
    }

    for (j = 0; j < strlen(str2); ++i, ++j) {
        result[i] = str2[j];
    }
    result[i] = '\0';
    
    return result;
}

int main()
{
    const char *str1 = "Hello";;
    const char *str2 = "world!";

    char *result = concat(str1, ", ", str2);

    if (result != NULL) {
        printf("Concatenated string: %s\n", result);
        free(result);
    } else {
        printf("Failed to concatenate strings.\n");
    }

}