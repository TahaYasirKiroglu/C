#include <stdio.h>
#include <ctype.h>
#define al(c) c=getchar()
char karakter_kontrol( int * );
int mors_et( void );

int main(int argc, char* argv[])
{
   mors_et(); 
   return 0;   
} 
int mors_et( void )
{
    int c;
    char alfabe[][7] = { "-.-.--", "...-..-", ".-...", ".----."
                    ,"-.--.", "-.--.-", ".-.-.", "--..--" 
                    ,"-....-", ".-.-.-", "-..-.", "-----" 
                    ,".----", "..---", "...--", "....-" 
                    ,".....", "-....", "--...", "---.."
                    ,"----.", "---...", "-.-.-.", "-...-"
                    ,"..--..", ".--.-.", ".-", "-...", "-.-."
                    ,"-..", ".", "..-.", "--.", "....", ".."
                    ,".---", "-.-", ".-..", "--", "-.", "---"
                    ,".--.", "--.-", ".-.", "...", "-", "..-"
                    ,"...-", ".--", "-..-", "-.--", "--.." };
    for(al(c) ; c != EOF ; al(c))
    {
      c = toupper( c );
      c = karakter_kontrol(&c);
      if( c == 'e' ) //eof ise bitir
          break;
      else if( c == 'b' )//bo�luk karakteriyse ' / ' bas
          printf(" / ");
      else if( c== 'n' )
          putchar('\n');
      else if( c == 'g' ) //ge�ersizse deam et
          continue;
      else
          printf("%s ", alfabe[ c ] );
    }
     putchar('\n'); //terminal kullan�c�lar� i�in
   return 0;
}
//karakterin de�erini kontol eder ve dizideki de�erini d�nd�r�r
//eof ise 'e', bo�luk ise 'b', ge�ersiz ise 'g' de�erlerini d�nd�r�r. 
char karakter_kontrol( int* chr ){
      char harf;
      if( *chr == '\n' )
          harf = 'n';
      else if( isspace( *chr ))
          harf = 'b';
      else if( *chr == EOF )
          harf = 'e';
      else if(( '>' < *chr ) && ( *chr < '[' ))
          harf = *chr-39;
      else if(( '*' < *chr ) && ( *chr < '<' ))
          harf = *chr-37;
      else
      {
          switch(*chr)//ustteki kurallara uymayanlar
          {
            case '!':  harf = 0;   break;
            case '$':  harf = 1;   break;
            case '&':  harf = 2;   break;
            case '"':  harf = 3;   break;
            case '(':  harf = 4;   break;
            case ')':  harf = 5;   break;
            case '=':  harf = 23;  break;
            default:   harf = 'g'; //Ge�erli harflerden de�illerse devam ettir
          }
      }        
   return harf;
}
