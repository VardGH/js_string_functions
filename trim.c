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

    char* result = (char*)malloc((str_length - first_index + 1) * sizeof(char));
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

char* trim_end(const char* str)
{
    if (str == NULL) {
        return NULL;
    }

    size_t str_length = strlen(str);

    // last non-whitespace character
    int last_index = str_length - 1;
    while (last_index >= 0 && (str[last_index] == ' ' || str[last_index] == '\t')) {
        last_index--;
    }

    char* result = (char*)malloc((last_index + 2) * sizeof(char));

    if (result == NULL) {
        return NULL;
    }

    for (int i = 0; i <= last_index; i++) {
        result[i] = str[i];
    }
    result[last_index + 1] = '\0';

    return result;
}

char* trim(const char* str)
{
    if (str == NULL) {
        return NULL;
    }

    char* res = trim_start(str);
    if (res == NULL) {
        return NULL;
    }

    char* trimmed_str = trim_end(res);
    free(res);

    return trimmed_str;
}

int main()
{
    const char* str = "      Hello, World!        ";

    char* trimmed_str = trim(str);
    if (trimmed_str != NULL) {
        printf("Trimmed string: \"%s\"\n", trimmed_str);
        free(trimmed_str);
    }

    return 0;
}
