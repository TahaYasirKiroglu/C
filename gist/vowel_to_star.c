#include <stdio.h>
#include <locale.h>
//sesliharfleri '*' a �evirir
void vowel_to_star(const char *);

int main(int argc, char *argv[])
{
  setlocale(LC_ALL,"Turkish"); //klavye dilini t�rk�eye ayarlama
  char mystring[] = "Taha Yasir K�ro�lu";
      vowel_to_star(mystring);
      puts(mystring);
  return 0;
}

void vowel_to_star(const char *pChr)
{
	char *chr=pChr;
     for( ; *chr ; chr++ ) 
     {
       switch( *chr )
       { 
         case 'a': case 'A':
         case 'e': case 'E':
         case '�': case 'I':
         case 'i': case '�':
         case 'o': case 'O':
         case '�': case '�':
         case 'u': case 'U':
         case '�': case '�':
             *chr='*';
             break;
        }
     }
}