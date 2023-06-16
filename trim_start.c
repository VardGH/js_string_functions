#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* trim_start(const char* str)
{
    if (str == NULL) {
        return NULL;
    }

    size_t str_length = strlen(str);

    // first non-whitespace character
    int first_index = 0;
    while (first_index < str_length && (str[first_index] == ' ' || str[first_index] == '\t')) {
        first_index++;
    }

    char *result = (char*)malloc((str_length - first_index + 1) * sizeof(char));
    if (result == NULL) {
        return NULL;
    }

    int i;
    for (i = 0; i < str_length - first_index; i++) {
        result[i] = str[first_index + i];
    }
    result[i] = '\0';

    return result;
}

int main()
{
    const char* str = "      Hello, World!        ";

    char* trimmed_str = trim_start(str);
    if (trimmed_str != NULL) {
        printf("Trimmed string: \"%s\"\n", trimmed_str);
        free(trimmed_str);
    }

    return 0;
}
