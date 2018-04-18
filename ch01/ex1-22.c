#include <stdio.h>
#define LINE_WIDTH 10
#define TAB_WIDTH 4

void main(){
     int col = 0,lc,j;
     char buffer[LINE_WIDTH+1]; // buffer stores 10 characters, the 11th is for null character
     char c;
     while ( ( c = getchar()) != '\n') {
          if ( col < LINE_WIDTH ){
        	 	 if ( c == '\t' ){
        	 	      for ( j = 0; j < TAB_WIDTH && col < LINE_WIDTH ; j++ ) // tab is replaced by 4 spaces
        	 	           buffer[col++] = ' ';
        	 	 } else
        	 	      buffer[col++] = c;
          } 
          if ( col == LINE_WIDTH){
               buffer[col++] = 0;
               printf("%s\n",buffer);
               col = 0;
          }
     }
     for ( j = 0; j < col; j++ )
          putchar(buffer[j]);
     putchar('\n');

}

