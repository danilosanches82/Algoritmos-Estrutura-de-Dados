#include<stdio.h>
#include<stdlib.h>

typedef struct lista{
  char info;
  struct lista* prox; 
}Lista;

typedef struct pilha{
  Lista* topo;  
}Pilha;

typedef struct fila{
  Lista* ini; 
  Lista* fim; 
}Fila;

void insereFila(Fila* F, char* valor){
  Lista* novo;    
  novo=(Lista*) malloc(sizeof(Lista));
  novo->info=valor[0];  
  novo->prox=NULL;
  
  if(F->fim==NULL){
	  F->fim=novo;
	  F->ini=novo;
  }else{
	  F->fim->prox = novo;
	  F->fim=novo;
  }
}  

char removeFila(Fila* F){
	Lista *aux;	
	aux=F->ini;
  char c[1];
  c[0] = aux->info;
	if(F->ini!=NULL){
	    F->ini = aux->prox;
	    
	    if(F->ini==NULL)
	       F->fim = NULL;
	       
	    free(aux);	    
	}

  return c[0];   
}


void push(Pilha* P, char *valor){
   Lista* novo;
   novo = (Lista*) malloc(sizeof(Lista));
   novo->info = valor[0];
   novo->prox = P->topo;
   
   P->topo = novo;
}

char pop(Pilha* P){
    Lista* aux;
    aux=P->topo;
    char c[1]; 
    c[0] = P->topo->info; 
    if(P->topo!=NULL){
      P->topo=aux->prox;
      free(aux);		
    }

    return c[0];
}

void imprimePilha(Pilha *P)
{
  Lista* aux=P->topo;
  
  while(aux!=NULL){
	  printf("%c\n", aux->info);
	  aux=aux->prox;
   }	  
}

void imprimeFila(Fila *F)
{
  Lista* aux=F->ini;
  
  while(aux!=NULL){
	  printf("%c\n", aux->info);
	  aux=aux->prox;
   }	  
}

//Para testar, leia cada símbolo e se:
// 1. leu ( ou [: empilha o símbolo lido
// 2. leu ]: desempilha [
// 3. leu ): desempilha (
// Se alguma etapa falhar ou pilha não terminar vazia, a
// sequência é inválida
int eh_balanceada(Fila* F){
    char tmp1, tmp2;
    int ok = 1;
    
    Pilha* aux;
    aux = (Pilha*) malloc(sizeof(Pilha));
    aux->topo = NULL;

    while(F->ini !=NULL){
      tmp1 = removeFila(F);
      if (tmp1 == '[' || tmp1 == '('){
        push(aux, &tmp1);        
      }else{
        tmp2 = pop(aux);        
        if(tmp1 == ']' && tmp2 == '[')
          ok = 0;
        else if(tmp1 == ')' && tmp2 == '(')
          ok = 0;          
        else
          ok = 1;  
      }  
    }
    //Atualiza o fim para NULL
    if(F->ini == NULL)
      F->fim = NULL;

    if(aux->topo != NULL)
       ok=1;  

    return ok;    
}


int main(){
  //Gera a fila com a sequência a ser avaliada
	Fila* F=(Fila*) malloc(sizeof(Fila));
  F->ini=NULL;
  F->fim=NULL;
  //////////////////////////////////////////////

  //Caso 1 - Falha
  insereFila(F, "(");
	insereFila(F, "[");
	insereFila(F, "]");
  printf("Caso1: %d\n", eh_balanceada(F));  	
  //Caso 2 - Falha  
	insereFila(F, "(");
	insereFila(F, "[");
	insereFila(F, ")");
  insereFila(F, "]");
  printf("Caso2: %d\n", eh_balanceada(F));  	
  //Caso 3 - Falha  
	insereFila(F, "[");
	insereFila(F, "[");
	insereFila(F, ")");
  insereFila(F, ")");
  printf("Caso3: %d\n", eh_balanceada(F));  	
  //Caso 1 - Acerto
  insereFila(F, "[");
	insereFila(F, "[");
	insereFila(F, "]");
  insereFila(F, "]");
  printf("Caso4: %d\n", eh_balanceada(F));  	  	
  //Caso 2 - Acerto  
	insereFila(F, "(");
	insereFila(F, "[");
	insereFila(F, "(");
  insereFila(F, ")");
  insereFila(F, "(");
  insereFila(F, "[");
  insereFila(F, "]");
  insereFila(F, ")");
  insereFila(F, "]");
  insereFila(F, ")");
  printf("Caso5: %d\n", eh_balanceada(F));

  return 0;  
}