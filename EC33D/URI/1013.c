/* 1013 Eh Maior */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main (){
  int a,b,c;
  	
  scanf("%d %d %d", &a, &b, &c);
  
  if ((a+b+abs(a-b))/2 < c)
      printf("%d eh o maior\n", c);
  else    
      printf("%d eh o maior\n", (a+b+abs(a-b))/2);
}
