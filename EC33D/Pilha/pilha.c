#include<stdio.h>
#include<stdlib.h>

typedef struct lista{
  int info;
  struct lista* prox; 
}Lista;

typedef struct pilha{
  Lista* topo;  
}Pilha;

void push(Pilha* P, int valor){
   Lista* novo;
   novo = (Lista*) malloc(sizeof(Lista));
   novo->info = valor;
   novo->prox = P->topo;
   
   P->topo = novo;
}

void pop(Pilha* P){
    Lista* aux;
    aux=P->topo;
     
    if(P->topo!=NULL){
		P->topo=aux->prox;
		free(aux);		
    }
}

void imprime(Pilha *P)
{
  Lista* aux=P->topo;
  
  while(aux!=NULL){
	  printf("%d\n", aux->info);
	  aux=aux->prox;
   }	  
}


int main(){
	Pilha* P = (Pilha*) malloc(sizeof(Pilha));
	P->topo=NULL;	
	
	push(P, 5);
	push(P, 15);
	push(P, 10);
	
	imprime(P);
	printf("\n");
	
	pop(P);
	imprime(P);	
	
  return 0;
  
}