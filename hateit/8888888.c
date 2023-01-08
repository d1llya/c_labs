#include <stdio.h>
 
#define ENG 26
#define RUS 32
#define N 5

void main() 
{ 
  int n = N;
  char c;
  do 
  {  
    c = getch();
    if (c >= 'A' && c <= 'Z') 
    {
      c = c + (n % ENG);
      if (c > 'Z') c = 'A' + (c - 'Z') - 1;
      printf("%c", c);      
    }
    if (c >= 'a' && c <= 'z') 
    {
      c = c + (n % ENG);
      if (c > 'z') c = 'a' + (c - 'z') - 1;
      printf("%c", c);    
    }
    if (c >= 'А' && c <= 'Я') 
    {
      c = c + (n % RUS);
      if (c > 'Я') c = 'А' + (c - 'Я') - 1;
      printf("%c", c);    
    }
    if (c >= 'а' && c <= 'я') 
    {
      c = c + (n % RUS);
      if (c > 'я') c = 'а' + (c - 'я') - 1;
      printf("%c", c);      
    }
  } 
  while (c != '\r');  
}
