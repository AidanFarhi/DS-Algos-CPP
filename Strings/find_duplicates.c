#include <stdio.h>
#include <stdlib.h>

/* Function Prototypes */
char* find_dupes_compare(char *str);
char* find_dupes_hash(char *str);

/* Returns an array of chars. O(n^2) Time. */
char* find_dupes_compare(char *str)
{
    char *dupes = malloc(sizeof(char) * 256); // max length of input string
    int p = 0;
    for (int i = 0; str[i] != '\0'; ++i)
        for (int j = i+1; str[j] != '\0'; ++j)
            if ((str[i] >= 65 && str[i] <= 90) || (str[i] >= 97 && str[i] <= 122))
                if (str[i] == str[j])
                    dupes[p++] = str[i];
    return dupes;
}

/* Returns an array of chars. O(n) Time. */
char* find_dupes_hash(char *str)
{
    char *dupes = malloc(sizeof(char) * 256); // max length of input string
    int p = 0;
    int hash[123]; // chars' ASCII codes range from 65-122
    for (int i = 0; i < 123; i++) hash[i] = 0;  // fill with 0's to prevent garbage values
    for (int i = 0; str[i] != '\0'; ++i)
    {
        if ((str[i] >= 65 && str[i] <= 90) || (str[i] >= 97 && str[i] <= 122))
        {
            hash[str[i]]++;
            if (hash[str[i]] == 2) // we only need one copy of each duplicate
                dupes[p++] = str[i];
        }
    }
    return dupes;
}

/* Returns an array of chars. Lowercase strings only. */
char* find_dupes_bitwise(char *str)
{
    char *dupes = malloc(sizeof(char) * 256); // max length of input string
    int p = 0;
    long int hash, x = 0;  // this will give us 32 bits to work with
    for (int i = 0; str[i] != '\0'; ++i)  // iterate through string
    {
        x = 1;                 // assign 1 bit to x ex: [0 0 0 0 0 0 0 1] <-
        x = x << (str[i] - 97);  // left shift bit. - 97 because ASCII codes are from 97-122
        if ((x & hash) > 0)      // this means that the bit position in hash matched bit position in x
            dupes[p++] = str[i];
        else
            hash = x | hash;   // turn bit on in hash
    }
    return dupes;
}

void print_result(char *str)
{
    for (int i = 0; str[i] != '\0'; ++i)
        printf("%c ", str[i]);
    printf("\n");
}

int main()
{
    char buffer[256];
    char *dupes;
    while (1)
    {
        // Get string from user
        printf("Enter a string: ");
        fgets(buffer, 256, stdin);

        printf("--------------------\n");

        // Compare method
        dupes = find_dupes_compare(buffer);
        printf("With compare method:\n");
        print_result(dupes);
        free(dupes);

        printf("--------------------\n");

        // Hash method
        dupes = find_dupes_hash(buffer);
        printf("With hash method:\n");
        print_result(dupes);
        free(dupes); 

        printf("--------------------\n");

        // Bitwise method
        dupes = find_dupes_bitwise(buffer);
        printf("With bitwise method:\n");
        print_result(dupes);
        free(dupes); 
    }
}