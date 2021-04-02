#include <stdio.h>

int main()
{
    // A single char
    char temp = 'A';
    printf("Char: %c\n", temp);
    printf("ASCII value: %d\n", temp);

    // An array of chars
    char str[5] = {'A', 'B', 'C', 'D', '\0'};
    char str2[] = {'A', 'B', 'C', 'D', '\0'};
    char str3[5] = {65, 66, 67, 68, '\0'};

    // name     you must include \0 at end as a terminator
    char name[10] = {'a', 'i', 'd', 'a', 'n', '\0'};

    // or do it the easy way - string will be on stack
    char name2[] = "Aidan";

    // or this way - string will be on heap
    char *name3 = "Aidan Farhi";

    // print them out
    printf("%s\n", str);
    printf("%s\n", str2);
    printf("%s\n", str3);
    printf("%s\n", name);
    printf("%s\n", name2);
    printf("%s\n", name3);
}