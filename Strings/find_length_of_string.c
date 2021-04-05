#include <stdio.h>

int find_length(char *str)
{
    int len = 0;
    for (int i = 0; str[i] != '\0'; i++)
        ++len;
    return len;
}

int main()
{
    char *test = "Aidan Farhi";
    int len = find_length(test);
    printf("Length: %d\n", len);
}