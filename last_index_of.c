#include <stdio.h>
#include <string.h>

int last_index_of(const char* str1, const char* str2) {
    if (str1 == NULL || str2 == NULL) {
        return -1; 
    }

    int len1 = strlen(str1);
    int len2 = strlen(str2);

    if (len2 > len1) {
        return -1;
    }

    for (int i = len1 - len2; i >= 0; --i) {
        if (strncmp(str1 + i, str2, len2) == 0) {
            return i; 
        }
    }

    return -1; 
}


int main() {
    const char* str1 = "The quick brown fox jumps over the lazy dog. If the dog barked, was it really lazy?";
    const char* str2 = "dog";

    int index = last_index_of(str1, str2);
    if (index != -1) {
        printf("The index of the first '%s' from the end is %d\n", str2, index);
    } else {
        printf("Substring '%s' not found in '%s'\n", str2, str1);
    }

    return 0;
}