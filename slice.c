#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* slice(const char *str, const int index_start) {
    if (str == NULL) {
        return NULL;
    }

    int start_index;

    if (index_start >= 0) {
        start_index = index_start;
    } else {
        start_index = strlen(str) + index_start;
        if (start_index < 0) {
            start_index = 0;
        }
    }

    char* result = (char*)malloc((strlen(str) - start_index + 1) * sizeof(char));
    if (result == NULL) {
        return NULL;
    }

    for (int i = start_index, j = 0; i < strlen(str); ++i) {
        result[j++] = str[i];
    }
    result[strlen(str) - start_index] = '\0';

    return result;
}

int main() {
    const char *str = "Hello, World!";
    int index_start = -3;

    char *res = slice(str, index_start);
    if (res != NULL) {
        printf("Sliced string: %s\n", res);
        free(res);
    }

    return 0;
}
