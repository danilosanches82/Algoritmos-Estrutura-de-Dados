/*Troca em Vetor I*/
#include<stdio.h>
#include<stdlib.h>

int main (){
  int size=6;
	int cont=0,*pIni, *pFim;
  int troca=0;
  int* num = (int*) malloc(size*sizeof(int));

  while (cont <size){
    scanf("%d", &num[cont]);
    cont++;
  }

  pIni = num;
  pFim = &num[size-1];
  cont=0;      
  while(cont < (int)(size/2)){
    troca = *pIni;
    *pIni = *pFim;
    *pFim = troca;

    cont++;
    pIni++;
    pFim--;
  } 
  
  cont = 0;
  while(cont<size){
    printf("N[%d] = %d\n", cont, num[cont]);
    cont++;  
  }  
}