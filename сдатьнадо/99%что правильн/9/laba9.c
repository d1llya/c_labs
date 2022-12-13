#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() 
{
    // Объявляем строку для хранения исходной и новой строки
    char str[100], newstr[100];   
    system("chcp 1251 > nul");
    
    // Считываем исходную строку с консоли
    printf("Введите строку: ");
    fgets(str, 100, stdin);

    // Перебираем все символы в исходной строке
    int j = 0;
    for (int i = 0; i < strlen(str); i++) {
        
        // Если символ отличается от предыдущего, добавляем его в новую строку
        int count = 1;
        while (i < strlen(str) - 1 && str[i + 1] == str[i]) 
        {
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

    // Выводим получившуюся новую строку на экран
    for (int i = 0; i < j; i++)
    {
        printf("%c", newstr[i]);
    }

    system("pause");
    return 0;
}
