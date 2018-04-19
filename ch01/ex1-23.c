#include <stdio.h>
#define IN 1
#define OUT 0

int main(void){
     int c,i,quote = OUT;

     while ( (c = getchar()) != EOF ){
          if ( c == '\"' )    // if there is a double quote
               quote++;
          if ( quote % 2 )    // if there is a odd number ( only 1 ) quote
               quote = IN;
          else
               quote = OUT;   // if even number of quote
          if ( c == '/' && quote == OUT){    // check for comments if it is out of a quote
               switch( c = getchar() ){      // get another character
                    case '/':                // single line quote, ignore until newline 
                         while ( (c = getchar() ) != '\n' &&  c != EOF );
                         putchar(c);         // print the new line character
                         break;
                    case '*':                // Multi line comment
                         while ( (c = getchar())!= EOF ){
                              if (  c == '*' ){       // check for ending of multiline comment 
                                   if ( (c = getchar()) == '/')
                                        break;
                              } 
                         }
                         break;
                    default:
                         printf("/%c",c); // if it is not a comment, print the / with the character we get
                         break;

               }
          } else{
               putchar(c);
          }

     }
     return 0;
}
