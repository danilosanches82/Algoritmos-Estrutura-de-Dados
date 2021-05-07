#include <stdio.h>
#include <stdlib.h>

typedef struct lista
{
	int elem;
	struct lista *prox;
}Lista;


void imprime(Lista* L){
  if (L !=NULL){
    printf("%d\n", L->elem);
    imprime(L->prox);
  }

}

Lista* insereFim_rec(Lista* L, int info){
      //Condição de parada da recursão
      if (L==NULL){
        Lista* novo = (Lista*) malloc(sizeof(Lista));
        novo->elem = info;
        novo->prox=NULL;
        return novo;
      }else{
        L->prox=insereFim_rec(L->prox, info); 
      }
      return L;
}

int main(){
    Lista* L = NULL;

    L = insereFim_rec(L, 10);
    L = insereFim_rec(L, 20);
    L = insereFim_rec(L, 30);
    L = insereFim_rec(L, 40);

    imprime(L);

    return 0;
}