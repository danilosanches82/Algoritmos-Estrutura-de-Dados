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


int main(){
  //Lista vazia;
  Lista* pRef = NULL;
  
  //Insere o primeiro elemento
  pRef = insereIni(pRef, 10);
  pRef = insereIni(pRef, 20);
  pRef = insereFim(pRef, 30);

  printf("%d\t%d\t%d\n", pRef->valor, pRef->prox->valor, 
        pRef->prox->prox->valor);

return (0);
}
