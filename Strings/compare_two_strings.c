#include <stdio.h>

/* Will return -> 1 if same || 0 if not */
int compare_strings(char *str1, char *str2)
{
    int p1, p2 = 0;
    while (str1[p1] != '\0' || str2[p2] != '\0')
    {
        if (str1[p1] == '\0' || str2[p2] == '\0'|| str1[p1] != str2[p2])
            return 0;
        ++p1;
        ++p2;
    }
    return 1;
}

int main()
{
    char buffer1[256];
    char buffer2[256];
    while (1)
    {
        printf("Enter first string: ");
        fgets(buffer1, 256, stdin);
        printf("Enter second string: ");
        fgets(buffer2, 256, stdin);
        int res = compare_strings(buffer1, buffer2);
        (res == 1) ? printf("Strings are same.") : printf("Strings are different.");
        printf("\n");
    }
}