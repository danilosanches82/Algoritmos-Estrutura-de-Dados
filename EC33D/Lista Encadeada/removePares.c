#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct lista{
  int valor;
  struct lista* prox;
}Lista;

Lista* removeLista(Lista*, int);

Lista* removePares(Lista* L){
    Lista* aux = L;
    while(aux!=NULL){
      if(aux->valor % 2 == 0){
        L = removeLista(L, aux->valor);
        aux = L;
      }else{
        aux=aux->prox; 
      }      
    }
   return L;
  }


Lista* removeLista(Lista* L, int info){
  Lista* aux = L;
  Lista* ant = NULL;

  //Procure pelo valor na lista
  while(aux != NULL && aux->valor != info){
     ant = aux;
     aux = aux->prox;
  }
  
  if(aux==NULL){//Nao achou o elemento
    return L;
  }else if(ant==NULL){ //Remove do inicio
        L = aux->prox; //Atualiza para segunda posicao
        free(aux);   
  } else{
    ant->prox = aux->prox;
    free(aux);
  }

  return L;
    
}

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
   Lista* aux = L; //Percorre lista
   Lista* maior = L;// Guarda o maior encontrado
   Lista* antMaior = NULL; // Sala o antereior ao maior
  Lista* antAux = NULL;

   //Laço para encontrar o maior
   while(aux != NULL){
     if(maior->valor < aux->valor){
       antMaior = antAux;//Salvo a posicao anterior
       maior = aux;
     }
     antAux = aux;
     aux =aux->prox;     
   }
  //30->60->NULL
   antMaior->prox = maior->prox;
   maior->prox = L;
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
  pRef = insereIni(pRef, 5);
  pRef = insereIni(pRef, 7);
  pRef = insereFim(pRef, 3);
  pRef = insereFim(pRef, 80);
  pRef = insereFim(pRef, 60);

  imprime(pRef);  

  pRef= deslocaMaior(pRef);

  imprime(pRef);  

  pRef= removeLista(pRef, 30);

  imprime(pRef);  

  pRef= removePares(pRef);

  imprime(pRef);  

return (0);
}
