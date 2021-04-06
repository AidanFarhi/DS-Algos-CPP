#include <stdio.h>

/* Returns 1 for True | 0 for False. */
int are_anagrams(char *str1, char *str2)
{
    int hash[57];
    for (int i = 0; i < 57; ++i) hash[i] = 0; // prevent garbage values
    // iterate through both strings and add each char to hash
    for (int j = 0; str1[j] != '\0' || str2[j] != '\0'; ++j)
    {
        if(str1[j] >= 65 && str1[j] <= 90 || str1[j] >= 97 && str1[j] <= 122)
            ++hash[str1[j]-65];  // -65 because lowest possible ASCII code is 65
        if(str2[j] >= 65 && str2[j] <= 90 || str2[j] >= 97 && str2[j] <= 122)
            ++hash[str2[j]-65];  // -65 because lowest possible ASCII code is 65
    }
    // Now check if each hash value is equal. Odd number means one string had an extra letter.
    for (int k = 0; k < 57; ++k)
        if (hash[k] % 2 != 0)
            return 0;
    return 1;
}

int main()
{
    char test1[] = "myfreind";
    char test2[] = "ymifrnde";
    int result = are_anagrams(test1, test2);
    if (result > 0)
        printf("Anagrams.\n");
    else
        printf("Not Anagrams.\n");
}