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

Lista* deslocaMaior(Lista* L){
  Lista* aux = L; //começa da segunda posição
  Lista* ant = NULL; //armazena a posição anterior ao Aux
  Lista* antMaior = NULL; //armazena a posição anterior ao Maior elemento
  Lista* maior = L; //guarda o primeiro elemento
  int info=aux->valor; //guarda o conteudo do primeiro elemento

  if(aux==NULL)
  return NULL;

  while(aux!=NULL){
    if(info<aux->valor){
      info=aux->valor; 
      maior=aux;
      antMaior = ant;
    }
    ant = aux;        
    aux=aux->prox; 
  }

  //Primeira posição
  if(antMaior==NULL){
    return L;
  }else if(maior->prox==NULL) { //Ultima posição
    antMaior->prox =NULL;
    maior->prox=L;    
  } else{
    antMaior->prox = maior->prox;
    maior->prox=L;   
  } 

return maior;

}

void imprime(Lista* L){
  Lista* aux =L;
  while(aux!=NULL){
    printf("%d\t",aux->valor);
    aux=aux->prox;
  }  

  printf("\n");  
}

int main(){
  //Lista vazia;
  Lista* pRef = NULL;
  
  //Insere o primeiro elemento
  pRef = insereIni(pRef, 80);
  pRef = insereIni(pRef, 70);
  pRef = insereFim(pRef, 30);
  pRef = insereFim(pRef, 50);
  pRef = insereFim(pRef, 60);

  imprime(pRef);  

  pRef= deslocaMaior(pRef);

  imprime(pRef);  

return (0);
}
