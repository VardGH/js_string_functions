#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* trim_end(const char* str)
{
    if (str == NULL) {
        return NULL;
    }

    size_t str_length = strlen(str);

    // last non-whitespace 
    int last_index = str_length - 1;
    while (last_index >= 0 && (str[last_index] == ' ' || str[last_index] == '\t')) {
        last_index--;
    }

    char *result = (char*)malloc((last_index + 2) * sizeof(char));

    if (result == NULL) {
        return NULL;
    }

    for (int i = 0; i <= last_index; i++) {
        result[i] = str[i];
    }
    result[last_index + 2] = '\0';

    return result;
}

int main()
{
    const char *str = "      Hello, World!        ";

    char* trimmed_str = trim_end(str);
    if (trimmed_str != NULL) {
        printf("Trimmed string: \"%s\"\n", trimmed_str);
        free(trimmed_str);
    }

    return 0;
}
