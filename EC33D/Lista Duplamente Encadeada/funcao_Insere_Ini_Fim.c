#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct listaD{
  int valor;
  struct listaD* prox;
  struct listaD* ant;
}ListaD;

ListaD* insereIni(ListaD* L, int info){
   ListaD* novo;
   novo = (ListaD*) malloc(sizeof(ListaD));
   novo->valor=info;
   novo->prox=L;
   novo->ant=NULL;
   
   if(L!=NULL)
      L->ant=novo;
   
   return novo;
}

ListaD* insereFim(ListaD *L,int info)
{
    ListaD *novo,*aux;
    novo=(ListaD*)malloc(sizeof(ListaD));
    novo->ant=NULL;
    novo->prox=NULL;
    novo->valor=info;
    if(L==NULL)
        return novo;
    else
    {
        aux=L;
        while(aux->prox!=NULL)
            aux=aux->prox;
        aux->prox=novo;
        novo->ant=aux;
    }
    return L;
}


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

  pRef = insereIni(pRef, 10);
  pRef = insereFim(pRef, 20);
  pRef = insereFim(pRef, 30);
  pRef = insereFim(pRef, 40);
  pRef = insereFim(pRef, 50);

  imprime(pRef);
  imprimeInvertido(pRef);

  return 0;
}
