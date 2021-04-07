#include<stdio.h>
#include<stdlib.h>

#define LIN 4
#define COL 6

void imprime(int **matriz){
  for (int i=0; i < LIN; i++){
    for (int j=0; j < COL; j++){
      printf("%d\t ", matriz[i][j]);
    }  
    printf("\n");  
  }
}


int main(){

  int **mat ;
  int i, j ;
  
  // aloca um vetor de LIN ponteiros para linhas
  mat = malloc (LIN * sizeof (int*)) ;
  
  // aloca cada uma das linhas (vetores de COL inteiros)
  for (i=0; i < LIN; i++)
    mat[i] = malloc (COL * sizeof (int)) ;
  
  // percorre a matriz
  for (i=0; i < LIN; i++)
    for (j=0; j < COL; j++)
      mat[i][j] = 0 ;        // acesso com sintaxe mais simples
  
  imprime(mat);
  // libera a memória da matriz
  for (i=0; i < LIN; i++)
    free (mat[i]) ;
  free (mat) ;

}