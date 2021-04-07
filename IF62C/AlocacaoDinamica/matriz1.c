#include<stdio.h>
#include<stdlib.h>

#define LIN 4
#define COL 6

void imprime(int *matriz){
  for (int i=0; i < LIN; i++){
    for (int j=0; j < COL; j++){
      printf("%d\t ", matriz[(i*COL) + j]);
    }  
    printf("\n");  
  }
}


int main(){

  int *mat;
  int i, j;
  
  // aloca um vetor com todos os elementos da matriz
  mat = (int*) malloc(LIN * COL * sizeof (int)) ;
  
  // percorre a matriz
  for (i=0; i < LIN; i++)
    for (j=0; j < COL; j++)
      mat[(i*COL) + j] = 0 ; // calcula a posição de cada elemento
  
  imprime(mat);

  // libera a memória da matriz
  free (mat) ;
}