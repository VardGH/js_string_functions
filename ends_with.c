#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool ends_with(const char *str1, const char *str2)
{
    const int len1 = strlen(str1);
    const int len2 = strlen(str2);
    
    if (len2 > len1) {
        return false;
    }

    for (int i = len2 - 1, j = 0; i >= 0; --i) {
        if (str1[len1 - j - 1] != str2[i]) {
            return false;
        }
        ++j;
    }
    return true; 
}

int main()
{
    const char *str1 = "Cats are the best!";
    const char *str2 = "best";
    const char *str3 = "best!";

    bool result1 = ends_with(str1, str2);
    bool result2 = ends_with(str1, str3);

    printf("%s\n", result1 ? "true" : "false");
    printf("%s\n", result2 ? "true" : "false");

}