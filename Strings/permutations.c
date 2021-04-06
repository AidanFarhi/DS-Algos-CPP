#include <stdio.h>

/* Prototypes */
void swap(char *str, int i, int j);
void permutations(char *str, int k);
void permutations_2(char *str, int l, int h);

void permutations(char *str, int k)
{
    static int check[10] = {0};
    static char res[10];

    if (str[k] == '\0')
    {
        res[k] = '\0';
        printf("%s\n", res);
    }
    else
    {
        for (int i = 0; str[i] != '\0'; ++i)
        {
            if (check[i] == 0)
            {
                res[k] = str[i];
                check[i] = 1;
                permutations(str, k+1);
                check[i] = 0;
            }
        }
    }
}

void permutations_2(char *str, int l, int h)
{
    if (l >= h)
    {
        printf("%s\n", str);
    }
    else
    {
        for (int i = l; i < h; i++)
        {
            swap(str, i, l);
            permutations_2(str, l+1, h);
            swap(str, i, l);
        }
    }
}

void swap(char *str, int i, int j)
{
    char temp = str[i];
    str[i] = str[j];
    str[j] = temp;
}

int main()
{
    char string[] = "ABC";
    permutations(string, 0);
    printf("-------------------\n");
    permutations_2(string, 0, 3);
}