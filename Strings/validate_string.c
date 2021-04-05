#include <stdio.h>

/* Check if string is letters and/or numbers. returns -> 1 if valid || 0 invalid */
int valid_string(char *str)
{
    for (int i = 0; str[i] != '\0'; ++i)
    {
        char ch = str[i];
        if (!(ch >= 64 && ch <= 90) &&   // 'A' - 'Z' 
            !(ch >= 97 && ch <= 122) &&  // 'a' - 'z'
            !(ch >= 48 && ch <= 57))     // '0' - '9'
            return 0;
    }
    return 1;
}

int main()
{
    char buffer[256];
    while (1)
    {
        printf("Enter a string to validate: ");
        gets(buffer);
        int result = valid_string(buffer);
        (result == 1) ? printf("Valid String.\n") : printf("Invalid String.\n");
    }
}