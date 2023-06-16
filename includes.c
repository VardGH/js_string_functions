#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool includes(const char *str1, const char *str2)
{
    if (str1 == NULL || str2 == NULL) {
        return false;
    }

    int len1 = strlen(str1);
    int len2 = strlen(str2);

    if (len2 > len1) {
        return false;
    }

    for (int i = 0; i <= len1 - len2; ++i) {
        if (strncmp(str1 + i, str2, len2) == 0) {
            return true;
        }
    }

    return false;
}

int main() {
    const char* str1 = "The quick brown fox jumps over the lazy dog.";
    const char* str2 = "fox";

    bool result = includes(str1, str2);
    if (result) {
        printf("String '%s' includes '%s'\n", str1, str2);
    } else {
        printf("String '%s' does not include '%s'\n", str1, str2);
    }

    return 0;
}