/* 1071 Soma de Impares Consecutivos I */
#include <stdlib.h>
#include <stdio.h>


int main(){
int i, X, Y;
int soma=0;

scanf("%d %d", &X, &Y);

if(X < Y){
  for(i = X+1; i<Y; i++){
    if ((i%2) != 0)
    soma=soma+i;
  }
  printf("%d\n", soma);
}else if ( X > Y){
  for(i = Y+1; i<X; i++){
    if ((i%2) != 0)
    soma=soma+i;
  }
  printf("%d\n", soma);
}else{
  printf("%d\n", soma);
}

return(0);
}