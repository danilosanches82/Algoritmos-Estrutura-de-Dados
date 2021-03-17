#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct lista{
  int valor;
  struct lista* prox;
}Lista;

Lista* insereFim(Lista* L, int v){
  Lista* aux = L;
  Lista* novo = (Lista*) malloc(sizeof(Lista));
    novo->valor = v;
    novo->prox = NULL;

  if(aux ==NULL)
    return novo;

  while(aux->prox !=NULL)
    aux = aux->prox;
  aux->prox = novo;

  return L;
}

int main(){

  Lista* pRef = NULL;
  int i, valor;

  for (i=0; i<10;i++){
	  scanf("%d", &valor);
    if(valor <= 0) 
      pRef = insereFim(pRef, 1);
    else
      pRef = insereFim(pRef, valor);  
  }

  //Percorre todos os elementos da lista
  Lista* aux = pRef;
  Lista* del = NULL;
  i =0;
  while(aux!=NULL){
    printf("X[%d] = %d\n", i, aux->valor);
    del = aux;
    aux = aux->prox;
    i++;
    free(del);
  }

  return 0;
}
