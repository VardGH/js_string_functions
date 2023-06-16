#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* pad_start(const char* str, int target_length)
{
    if (str == NULL || target_length <= 0 || target_length <= strlen(str)) {
        return NULL; 
    }

    char* result = (char*)malloc((target_length + 1) * sizeof(char));
    if (result == NULL) {
        return NULL;
    }

    strcpy(result, ""); // init

    while (strlen(result) + strlen(str) < target_length) {
        strcat(result, " ");
    }

    strcat(result, str); 

    return result;
}

char* pad_start2(const char* str, int target_length, const char* pad_string) {
    if (str == NULL || pad_string == NULL || target_length <= 0 || target_length <= strlen(str)) {
        return NULL; 
    }

    char* result = (char*)malloc((target_length + 1) * sizeof(char));
    if (result == NULL) {
        return NULL;
    }

    strcpy(result, ""); // init

    while (strlen(result) + strlen(str) < target_length) {
        strcat(result, pad_string);
    }

    strcat(result, str); 

    return result;
}

int main() 
{
    const char *str = "Hello";
    int target_length = 7;

    char* pad_str = pad_start(str, target_length);
    if (pad_str != NULL) {
        printf("Padded string: %s\n", pad_str);
        free(pad_str); 
    }

    const char *str2 = "Hello";
    int target_length2 = 10;
    const char* pad_string2 = "123";

    char* pad_str2 = pad_start2(str2, target_length2, pad_string2);
    if (pad_str2 != NULL) {
        printf("Padded string: %s\n", pad_str2);
        free(pad_str2);
    }

    return 0;
}
