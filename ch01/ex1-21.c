// Replaces consecutive blanks by equivalent number of tabs and blanks

#include <stdio.h>
#define TABSTOP 4
#define OUT 0
#define IN 1

int main(void){
     char c;
     int i,blanks = 0,state = OUT;
     while ( ( c = getchar() ) != EOF ){
          if ( c == ' '){
               state = IN;
               blanks++;
          } else if ( state == IN ){
               state = OUT;
               for ( i = 0; i<=(blanks/TABSTOP); i++)
                     putchar('\t');
               for ( i = 0; i<( blanks - (blanks/TABSTOP)*TABSTOP ); i++)
                     putchar(' ');
               
               blanks = 0;
          }
          if ( c != ' ')
               putchar(c);
     }
     return 0;
}
