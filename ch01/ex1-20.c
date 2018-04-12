// Replaces the tabs with the set amount of empty blanks 

#include <stdio.h>

#define BLANKS 4 // Number of blanks to replace the tab character

int main(){
     char c;
     int i = 0,j;
     while ( (c = getchar()) != EOF ){
          if ( c == '\t' ){
               for ( j = 0; j < BLANKS ; j++ )
                    putchar(' ');
          } else   
                    putchar(c); 
     }
     return 0;
} 

