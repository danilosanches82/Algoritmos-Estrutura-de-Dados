/* 1172 Substituição em Vetor I*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main (){
  int size=10;
	int cont=0,num[size], *pnum;
	
  pnum = num;

  while (cont <size){
    scanf("%d", &num[cont]);
        
    if(*pnum <= 0) 
       *pnum = 1;
    
    pnum++;
    cont++;
  }
  
  cont = 0;
  pnum = num;
  while(cont<size){
    printf("X[%d] = %d\n", cont, *pnum);
    cont++;
    pnum++;
  }  
}