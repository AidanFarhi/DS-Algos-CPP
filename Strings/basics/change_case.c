#include <stdio.h>

void change_case(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] >= 65 && str[i] <= 90)
            str[i] += 32;
        else if (str[i] >= 97 && str[i] <= 122)
            str[i] -= 32;
    }
}

int main()
{
    char *test1 = "Hello";
    change_case(test1);
    printf("%s\n", test1);
   
}
