#include <stdio.h>

int get_word_count(char *str)
{
    int count = 1;
    for (int i = 1; str[i] != '\0'; ++i)
        if (str[i-1] != ' ' && str[i] == ' ')
            ++count;
    return count;
}

int main()
{
    char buffer[256];
    while (1)
    {
        printf("Enter a sentence: ");
        gets(buffer);
        int count = get_word_count(buffer);
        printf("Number of words: %d\n", count);
    }
}

