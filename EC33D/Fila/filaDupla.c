#include<stdio.h>
#include<stdlib.h>

typedef struct lista{
  int info;
  struct lista* prox;
  struct lista* ant;
}ListaD;

typedef struct fila{
  ListaD* ini; 
  ListaD* fim; 
}Fila;

void insereFilaIni(Fila* F, int valor){
  ListaD* novo;
  novo=(ListaD*) malloc(sizeof(ListaD));
  novo->info=valor;
  novo->prox=F->ini;
  novo->ant=NULL;
  
  if(F->ini==NULL){
	  F->fim=novo;
	  F->ini=novo;
  }else{
	  F->ini->ant = novo;
	  F->ini=novo;
  }
}  

void insereFilaFim(Fila* F, int valor){
  ListaD* novo;
  novo=(ListaD*) malloc(sizeof(ListaD));
  novo->info=valor;
  novo->prox=NULL;
  novo->ant=F->fim;
  
  if(F->fim==NULL){
	  F->fim=novo;
	  F->ini=novo;
  }else{
	  F->fim->prox = novo;
	  F->fim=novo;
  }
}  


void removeFilaIni(Fila* F){
	ListaD *aux;	
	aux=F->ini;
	if(F->ini!=NULL){
		//posiciona o ini para a segunda posição
	    F->ini = aux->prox;	    
	    
	    if(F->ini==NULL) F->fim = NULL;
	    else F->ini->ant = NULL; //Atualiza o ponteiro 'ant' para NULL	       
	    free(aux);	    
	}   
}

void removeFilaFim(Fila* F){
	ListaD *aux;	
	aux=F->fim;
	if(F->fim!=NULL){
		//posiciona o fim para a posição anterior
	    F->fim = aux->ant;	    
	    
	    if(F->fim==NULL) F->ini = NULL;	       
	    else F->fim->prox = NULL;		       
		   
	    free(aux);	    
	}   
}

void imprime(Fila *F)
{
  ListaD* aux=F->ini;
  
  while(aux!=NULL){
	  printf("%d ", aux->info);
	  aux=aux->prox;
   }
   printf("\n");	  
}

int main(){
     
   Fila* F=(Fila*) malloc(sizeof(Fila));
   F->ini=NULL;
   F->fim=NULL;
   
   insereFilaIni(F,5);
   insereFilaIni(F,15);
   insereFilaFim(F,10);
   insereFilaFim(F,20);
   
   //Imprime fila original
   imprime(F);   
   
   //Remove Inicio
   removeFilaIni(F);
   
   //imprime(F);
   
   //Remove Fim
   removeFilaFim(F);
   
   imprime(F);      

}