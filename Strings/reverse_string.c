#include <stdio.h>

void reverse_string(char *str)
{
    int len;  // First find length of string
    for (len = 0; str[len+1] != '\0'; ++len);
    int i = 0;
    while (i < len) // Now reverse
    {
        char temp = str[i];
        str[i++] = str[len];
        str[len--] = temp;
    }
}

int main()
{
    char buffer[256];
    while (1)
    {
        printf("Enter a string: ");
        fgets(buffer, 256, stdin);
        reverse_string(buffer);
        printf("Reversed: %s\n", buffer);
    }
}