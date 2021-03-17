#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct lista{
  int valor;
  struct lista* prox;
}Lista;

int main(){
  Lista *listaInt;
  listaInt = (Lista*) malloc(sizeof(Lista));
  listaInt->valor = 10;
  
  listaInt->prox = (Lista*) malloc(sizeof(Lista));
  listaInt->prox->valor = 20;
  listaInt->prox->prox = (Lista*) malloc(sizeof(Lista));
  listaInt->prox->prox->valor = 30;
  listaInt->prox->prox->prox = NULL;

  printf("%d\t%d\t%d\n",listaInt->valor, listaInt->prox->valor, listaInt->prox->prox->valor);

  free(listaInt->prox->prox);
  free(listaInt->prox);
  free(listaInt);

return (0);
}
