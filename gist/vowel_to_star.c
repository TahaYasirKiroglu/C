#include <stdio.h>
#include <locale.h>
<<<<<<< HEAD
//sesliharfleri '*' a �evirir
void vowel_to_star(char *);

int main(int argc, char *argv[])
{
  char mystring[] = "Cevat �akir KABAA�A�";
      vowel_to_star( mystring );
      puts( mystring );
=======
//sesliharfleri '*' a çevirir
void vowel_to_star(const char *);

int main(int argc, char *argv[])
{
  setlocale(LC_ALL,"Turkish"); //klavye dilini türkçeye ayarlama
  char mystring[] = "Taha Yasir Kiroglu";
      vowel_to_star(mystring);
      puts(mystring);
>>>>>>> origin/master
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
         case 'ı': case 'I':
         case 'i': case 'İ':
         case 'o': case 'O':
         case 'ö': case 'Ö':
         case 'u': case 'U':
<<<<<<< HEAD
         case '�': case '�':
             *chr = '*';//sesli bir harfse * yap
=======
         case 'ü': case 'Ü':
             *chr='*';
             break;
>>>>>>> origin/master
        }
     }
}
