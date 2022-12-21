#include <stdio.h>
#include <string.h>

void revStr(char *start, char *end)
{
    for (char *st = start, *en = end - 1; st < en; ++st, --en)
    {
        char ch = *st;
        *st = *en;
        *en = ch;
    }
}

int intToStr(char *str, int number)
{
    char *end = str;
    while (number > 0)
    {
        *end = number % 10 + '0';
        number /= 10;
        ++end;
    }
    *end = '\0';
    revStr(str, end);
    return (end - str) / sizeof(char);
}

void zipStr(char *str)
{
    int left = 0;
    int size = 0;
    char current_letter = str[0];

    for (int i = 1; str[i - 1] != '\0'; ++i)
    {
        if (str[i] != current_letter)
        {
            int n = i - left;
            if (n != 1)
            {
                n = intToStr(str + size, n);
                size += n;
            }
            str[size] = current_letter;
            ++size;
            left = i;
            current_letter = str[i];
        }
    }
    str[size] = '\0';
}

int main()
{
    char str[1024];
    printf("Enter string  -> ");
    fgets(str, 1024, stdin);

    zipStr(str);

    printf("Result string -> ");
    fputs(str, stdout);

    return 0;
}
