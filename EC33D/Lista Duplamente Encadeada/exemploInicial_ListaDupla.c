#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct listaD{
  int valor;
  struct listaD* prox;
  struct listaD* ant;
}ListaD;

void imprime(ListaD* L){
  ListaD* aux =L;
  while(aux!=NULL){
      printf("%d ",aux->valor);
      aux=aux->prox;
  }
  printf("\n");      
}

void imprimeInvertido(ListaD* L){
  ListaD* aux =L;

  while(aux->prox!=NULL)
    aux=aux->prox;

  while(aux!=NULL){
      printf("%d ",aux->valor);
      aux=aux->ant;
  }
  printf("\n");      
}

void limpaLista(ListaD* L){
  ListaD* aux=L;

  while(aux!=NULL){
    L = aux->prox;
    free(aux);
    aux=L;
  }
}

int main(){
  //Lista vazia;
  ListaD* pRef = NULL;
  pRef = (ListaD*) malloc(sizeof(ListaD));
  pRef->valor = 10;
  pRef->ant = NULL;
  pRef->prox = (ListaD*) malloc(sizeof(ListaD));
  pRef->prox->valor = 20;
  pRef->prox->prox = NULL;
  pRef->prox->ant = pRef;
  
  imprime(pRef);
  imprimeInvertido(pRef);

  return 0;
}