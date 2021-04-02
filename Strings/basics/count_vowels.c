#include <stdio.h>

int is_vowel(char ch)  // 1 == true, 0 == false
{
    char check[] = "aeiouAEIOU";
    for (int c = 0; check[c] != '\0'; c++)
        if (ch == check[c])
            return 1;
    return 0;
}

int count_vowels(char *str)
{
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++)
        if (is_vowel(str[i]) == 1)
            count++;
    return count;
}

int main()
{
    char test[] = "Allo Wild Eye";
    int vowel_count = count_vowels(test);
    printf("Number of vowels: %d\n", vowel_count);
}

