#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool starts_with(const char *str1, const char *str2)
{
    const int len1 = strlen(str1);
    const int len2 = strlen(str2);

    if (len2 > len1) {
        return false;
    }

    for (int i = 0; i < len2; ++i) {
        if (str1[i] != str2[i]) {
            return false;
        }
    }
    return true; 
}

int main()
{
    const char *str1 = "Cats are the best!";
    const char *str2 = "Cats a";
    const char *str3 = "best!";

    bool result1 = starts_with(str1, str2);
    bool result2 = starts_with(str1, str3);

    printf("%s\n", result1 ? "true" : "false");
    printf("%s\n", result2 ? "true" : "false");
    
    return 0;
}
