#include <stdio.h>
#include <locale.h>

//sesliharfleri '*' a cevirir
void vowel_to_star(char *);

int main( int argc, char *argv[] ){
	setlocale( LC_ALL,"Turkish" ); //klavye dilini turkceye ayarlama
	char mystring[] = "Taha Yasir K�ro�lu";
	  strVowel2Star( mystring );
	  puts( mystring );
	return 0;
}

void strVowel2Star( char *chr ){
	//setlocale(LC_ALL,"Turkish");//klavye dilini turkceye ayarla
     for( ; *chr ; chr++ ) {
       switch( *chr ){
         case 'a': case 'A':
         case 'e': case 'E':
         case '�': case 'I':
         case 'i': case '�':
         case 'o': case 'O':
         case '�': case '�':
         case 'u': case 'U':
         case '�': case '�':
             *chr = '*'; //sesli bir harfse * yap
             break;
        }
     }
}
