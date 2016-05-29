#include <stdio.h>
#include <locale.h>
//sesliharfleri '*' a �evirir
void vowel_to_star(char *);

int main(int argc, char *argv[])
{
  char mystring[] = "Cevat �akir KABAA�A�";
      vowel_to_star( mystring );
      puts( mystring );
  return 0;
}

void vowel_to_star( char *chr )
{
	setlocale(LC_ALL,"Turkish");//klavye dili t�rk�e olsun
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
             *chr = '*';//sesli bir harfse * yap
        }
     }
}
