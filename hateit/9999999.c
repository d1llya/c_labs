#include <stdio.h>
#include <string.h>
int main() 
{
    char str[100], newstr[100]; 
    printf("Введите строку: ");
    fgets(str, 100, stdin);
    int j = 0;
    for (int i = 0; i < strlen(str); i++) 
    {
        int count = 1;
        while (i < strlen(str) - 1 && str[i + 1] == str[i]) 
        {
            if (str[i] == ' ') 
            {
                break;
            }
            count++;
            i++;
        }
        if (count != 1) 
        {
            newstr[j++] = '0' + count;
            newstr[j++] = str[i - 1];
        }
        else 
        {
            newstr[j++] = str[i];
        }
    }
    for (int i = 0; i < j; i++) 
    {
        printf("%c", newstr[i]);
    }
    return 0;
}
