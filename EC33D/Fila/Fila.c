#include<stdio.h>
#include<stdlib.h>

typedef struct lista{
  int info;
  struct lista* prox; 
}Lista;

typedef struct fila{
  Lista* ini; 
  Lista* fim; 
}Fila;

void insereFila(Fila* F, int valor){
  Lista* novo;
  novo=(Lista*) malloc(sizeof(Lista));
  novo->info=valor;
  novo->prox=NULL;
  
  if(F->fim==NULL){
	  F->fim=novo;
	  F->ini=novo;
  }else{
	  F->fim->prox = novo;
	  F->fim=novo;
  }
}  

void removeFila(Fila* F){
	Lista *aux;	
	aux=F->ini;
	if(F->ini!=NULL){
	    F->ini = aux->prox;
	    
	    if(F->ini==NULL)
	       F->fim = NULL;
	       
	    free(aux);	    
	}   
}


void imprime(Fila *F)
{
  Lista* aux=F->ini;
  
  while(aux!=NULL){
	  printf("%d\n", aux->info);
	  aux=aux->prox;
   }	  
}

//5->15->10->NULL
int main(){
   //Cria a Fila vazia (nó sentinela)
   
   Fila* F=(Fila*) malloc(sizeof(Fila));
   F->ini=NULL;
   F->fim=NULL;
   
   insereFila(F,5);
   insereFila(F,15);
   insereFila(F,10);
   
   removeFila(F);
   removeFila(F);
   
   imprime(F);   

  return 0;
}
