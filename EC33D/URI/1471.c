#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct lista{
  int valor;
  struct lista* prox;
}Lista;

Lista* insereIni(Lista* tempRef, int v){
    Lista* pNovo = (Lista*) malloc(sizeof(Lista)); 
    pNovo->valor = v;
    pNovo->prox = tempRef;

    return pNovo;
}

Lista* insereFim(Lista* tempRef, int v){
    Lista* pNovo = (Lista*) malloc(sizeof(Lista)); 
    pNovo->valor = v;
    pNovo->prox = NULL;

    //Verifca condição de lista vazia
    if (tempRef == NULL)
      return pNovo;

    Lista* pAux = tempRef;
    while(pAux->prox!=NULL)
      pAux = pAux->prox; 

    //Faz a ligação entre pAux e pNovo;   
    pAux->prox = pNovo;

    return tempRef;
}

Lista* removeLista(Lista* L, int info){
  Lista* aux=NULL, *ant=NULL;
  aux = L;
  if(aux==NULL)
  return NULL;

  while(aux!=NULL && aux->valor!=info){
    ant=aux;
    aux=aux->prox;
  }
  //Nao encontrou o elemento
  if(aux==NULL)
    return L;

  //Remove o primeiro elemento
  if(ant==NULL){
    L=aux->prox;
    free(aux);
    return L;
  }else{
    ant->prox=aux->prox;
    free(aux);
    //retorna a lista com as alterações
    return L;
  }
}

void imprime(Lista* L){
  Lista* aux =L;
  if(aux==NULL){
    printf("*\n");
  }else{
    while(aux!=NULL){
      printf("%d ",aux->valor);
      aux=aux->prox;
    }
    printf("\n");  
  }  
}

void limpaLista(Lista* L){
  Lista* aux=L;

  while(aux!=NULL){
    L = aux->prox;
    free(aux);
    aux=L;
  }
}

int main(){
  //Lista vazia;
  Lista* pR = NULL;
  Lista* pN = NULL;

  int i, n,r, info;
  scanf("%d %d", &n, &r);
  for(i=1; i <= r; i++){      
      scanf("%d", &info);
      pR = insereFim(pR, info);
  } 

  for(i=1; i <= n; i++)
      pN = insereFim(pN, i);
    
  Lista* aux = pR;
  while(aux!=NULL){
        pN = removeLista(pN, aux->valor);
        aux=aux->prox;  
  }
        
  imprime(pN);
  limpaLista(pN);
  limpaLista(pR);    
  
  return 0;
}  