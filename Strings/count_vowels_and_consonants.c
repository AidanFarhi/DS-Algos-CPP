#include <stdio.h>
#include <stdlib.h>

/* A structure that will keep a record of counts */
typedef struct Counter
{
    int vowels;
    int consonants;
} Counter;

/* 1 == vowel, 0 == consonant, -1 = neither */
int is_vowel_or_consonant(char ch)  
{
    char check[] = "aeiouAEIOU";
    // First check if char is a vowel
    for (int c = 0; check[c] != '\0'; c++)
        if (ch == check[c])
            return 1;
    // Now check if it is a letter
    if (ch >= 65 && ch <= 90 || ch >= 97 && ch <= 122)
        return 0;
    // char is not a letter
    return -1;
}

/* Takes in a string and records vowel and consonent counts in a provided Counter struct */
void count_vowels_and_consonants(char *str, Counter *counts)
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        int check_value = is_vowel_or_consonant(str[i]);
        if (check_value == 1)
            counts->vowels++;
        else if (check_value == 0)
            counts->consonants++;
    }
}

int main()
{
    char buffer[256]; // buffer to hold string coming in from user
    Counter *counts = malloc(sizeof(Counter));
    while (1)
    {
        counts->consonants = 0;
        counts->vowels = 0;
        printf("Enter a string: ");
        gets(buffer);
        count_vowels_and_consonants(buffer, counts);
        printf("Vowels: %d Consonants: %d\n", counts->vowels, counts->consonants);
    }
    free(counts);
}
