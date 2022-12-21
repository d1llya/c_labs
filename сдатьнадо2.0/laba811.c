#include <stdio.h>
#include <unistd.h>
#include <stdio_ext.h>
#include <ctype.h>
#include <conio.h>

int mygetch()
{
    struct termios oldt, news;
    int c;
    tcgettattr(STDIN_FILENO, &oldt);
    news = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    c = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return c;
}

int main()
{
    {
    char message[100], ch;
    int i, key;
    printf("Enter a message to decrypt: ");
    gets(message);
    printf("Enter key: ");
    scanf("%d", &key);
    for(i = 0; message[i] != '\0'; ++i)
    {
    ch = message[i];
    if(ch >= 'a' && ch <= 'z')
    {
    ch = ch - key;
    if(ch < 'a')
    {
        ch = ch + 'z' - 'a' + 1;
    }
    message[i] = ch;
    }
else if(ch >= 'A' && ch <= 'Z'){
ch = ch - key;
if(ch < 'A'){
ch = ch + 'Z' - 'A' + 1;
}
message[i] = ch;
}
}
printf("Decrypted message: %s", message);
return 0;
}
}
