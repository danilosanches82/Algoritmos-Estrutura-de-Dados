#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
   int info;
   struct lista* prox;	
}Lista;

typedef struct fila{
   Lista* ini;
   Lista* fim;
}Fila;

void imprime(Fila* F){
	Lista* aux = F->ini;
	while(aux!=NULL){
		printf("%d ",aux->info);
		aux=aux->prox;		
    }
    printf("\n");
}

void insereFila(Fila* F, int valor){
	Lista* novo;
	novo=(Lista*) malloc(sizeof(Lista));
	novo->info=valor;
	novo->prox=NULL;
	if(F->ini==NULL){
		F->ini=novo;
		F->fim=novo;
    }else{
		F->fim->prox=novo;
		F->fim = novo;
	}
}

int removeFila(Fila* F){
	Lista* aux=F->ini;
	int v=0;
	
	if(aux!=NULL){
		F->ini = aux->prox;
		v=aux->info;
		free(aux);
		
		if(F->ini==NULL)
		   F->fim=NULL;	
	}
	return v;
}

///////   Funções Lista ////////////// 

Lista* insereFim(Lista* ref, int elem){
     if(ref == NULL){
		 ref = (Lista*) malloc(sizeof(Lista));
		 ref->info = elem;
		 ref->prox = NULL;
		 return ref;
       }
     Lista* aux = ref;
     while(aux->prox!=NULL)
           aux=aux->prox;
     
     Lista* novo = (Lista*) malloc(sizeof(Lista));
     novo->info=elem;
     novo->prox = NULL;
     
     aux->prox = novo;
     
     return ref;           
}
	 
Lista* removeLista(Lista* L, int valor){
  Lista* aux=NULL, *ant=NULL;  
  aux = L;
  if(aux==NULL)
    return NULL;
  
  while(aux!=NULL && 
        aux->info!=valor){
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
////////////////////////////////////////////////

void removePares(Fila* F){
 Lista* L = NULL;
 int valor;
  
 while(F->ini!=NULL){
   if(F->ini->info % 2 != 0)	 	 
	  L = insereFim(L,removeFila(F));
   else
	  printf("Descartando: %d\n", removeFila(F));
 }
  
 while(L!=NULL){
   valor = L->info; 	 
   insereFila(F, valor);
   L = removeLista(L,valor);
 }   
}


int main(){
	Fila* F = (Fila*) malloc(sizeof(Fila));
	F->ini = NULL;
	F->fim = NULL;
	insereFila(F, 1);
	insereFila(F, 2);
	insereFila(F, 3);
	insereFila(F, 4);
	insereFila(F, 5);
	insereFila(F, 8);
	insereFila(F, 10);
	insereFila(F, 15);
	imprime(F);	
	removePares(F);
	imprime(F);	

  return 0;
}