#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* pad_end(const char *str, const int target_length)
{
    if (str == NULL || target_length <= strlen(str)) {
        return NULL;
    }

    char *result = (char*)malloc((target_length + 1) * sizeof(char));

    int i;
    for (i = 0; i < strlen(str); ++i) {
        result[i] = str[i];
    }

    for (int j = 0; j < target_length - strlen(str); ++j, ++i) {
        result[i] = ' ';
    }
    result[i] = '\0';
    return result;
}

char* pad_end2(const char *str, const int target_length, const char *pad_string)
{
    if (str == NULL || pad_string == NULL || target_length <= 0 || target_length <= strlen(str)) {
        return NULL; 
    }
    
    char* result = (char*)malloc((target_length + 1) * sizeof(char));

    if (result == NULL) {
        return NULL;
    }

    strcpy(result, str);

    while (strlen(result) < target_length) {
        strcat(result, pad_string);
    }

    result[target_length] = '\0';

    return result;
}

int main()
{
    const char *str = "Hello";
    int target_length = 7;

    char* pad_str = pad_end(str, target_length);
    if (pad_str != NULL) {
        printf("Padded string: %s:\n", pad_str);
        free(pad_str); 
    }

    const char *str2 = "Hello";
    int target_length2 = 10;
    const char *pad_string = "567";

    char* pad_str2 = pad_end2(str2, target_length2, pad_string);
    if (pad_str2 != NULL) {
        printf("Padded string: %s\n", pad_str2);
        free(pad_str2);
    }

    return 0;
}