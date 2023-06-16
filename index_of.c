#include <string.h>
#include <stdio.h>

int index_of(const char *str1, const char *str2) 
{
    if (str1 == NULL || str2 == NULL) {
        return -1; 
    }

    int len1 = strlen(str1);
    int len2 = strlen(str2);

    if (len2 > len1) {
        return -1;
    }

    for (int i = 0; i <= len1 - len2; ++i) {
        if (strncmp(str1 + i, str2, len2) == 0) {
            return i; 
        }
    }
    return -1;
}

int main() {
    const char* str1 = "Hello, world!";
    const char* str2 = "world";

    int index = index_of(str1, str2);
    if (index != -1) {
        printf("Substring '%s' found at index %d in '%s'\n", str2, index, str1);
    } else {
        printf("Substring '%s' not found in '%s'\n", str2, str1);
    }

    return 0;
}