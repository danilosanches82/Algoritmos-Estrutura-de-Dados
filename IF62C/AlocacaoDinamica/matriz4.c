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
 
// aloca um vetor com os ponteiros e os elementos da matriz
mat = malloc (LIN * sizeof (int*) + LIN * COL * sizeof (int)) ;
 
// ajusta o ponteiro da primeira linha
mat[0] = (int*) (mat + LIN) ;
 
// ajusta os ponteiros das demais linhas (i > 0)
for (i=1; i < LIN; i++)
  mat[i] = mat[0] + (i * COL) ;
 
// percorre a matriz
for (i=0; i < LIN; i++)
  for (j=0; j < COL; j++)
    mat[i][j] = i ;

imprime(mat); 
// libera a memória da matriz
free (mat) ;

}