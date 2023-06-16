#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* replace(const char *str, const char *pattern, const char *replacement) {
    if (str == NULL || pattern == NULL || replacement == NULL) {
        return NULL;
    }

    int str_length = strlen(str);
    int pattern_length = strlen(pattern);
    int replacement_length = strlen(replacement);

    int count = 0;
    const char* pos = str;
    while ((pos = strstr(pos, pattern)) != NULL) {
        ++count;
        pos += pattern_length;
    }

    int result_length = str_length + (replacement_length - pattern_length) * count;

    char*result = (char*)malloc((result_length + 1) * sizeof(char));
    if (result == NULL) {
        return NULL;
    }

    const char *source = str;
    char *destination = result;

    while ((pos = strstr(source, pattern)) != NULL) {
        int segment_length = pos - source;

        strncpy(destination, source, segment_length);
        destination += segment_length;

        strncpy(destination, replacement, replacement_length);
        destination += replacement_length;

        source = pos + pattern_length;
    }

    strcpy(destination, source);

    return result;
}

int main() {
    const char *str = "The quick brown fox jumps over the lazy dog. If the dog reacted, was it really lazy?";
    const char *pattern = "dog";
    const char *replacement = "monkey";

    char *res = replace(str, pattern, replacement);
    if (res != NULL) {
        printf("Replaced string: %s\n", res);
        free(replacresed_str);
    }

    return 0;
}