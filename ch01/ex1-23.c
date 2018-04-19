#include <stdio.h>
#define IN 1
#define OUT 0

int main(void){
     int c,quote = OUT;

     while ( (c = getchar()) != EOF ){
          if ( c == '\\'){         // check for quotes used with escape sequences i.e \"
               if ( ( c = getchar() ) == '\"' )
                    printf("\\\"");
          } else if ( c == '\"' )  // if there is no escape sequence use
               quote++;
          if ( quote % 2 )
               quote = IN;
          else 
               quote = OUT;
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
