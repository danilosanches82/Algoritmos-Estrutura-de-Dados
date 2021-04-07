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
 
// aloca um vetor com todos os elementos da matriz
mat[0] = malloc (LIN * COL * sizeof (int)) ;
 
// ajusta os demais ponteiros de linhas (i > 0)
for (i=1; i < LIN; i++)
  mat[i] = mat[0] + i * COL ;
 
// percorre a matriz
for (i=0; i < LIN; i++)
  for (j=0; j < COL; j++)
    mat[i][j] = 0 ;
 
imprime(mat);
// libera a memória da matriz
free (mat[0]) ;
free (mat) ;

}