#include <stdio.h>
#include <stdlib.h>

struct arv {
    int info;
    struct arv* esq;
    struct arv* dir;
};
typedef struct arv Arv;

Arv* abb_cria (void)
{
   return NULL;
}

void abb_imprime (Arv* a)
{
    if (a != NULL) {
        abb_imprime(a->esq);
        printf("%d\n",a->info);
        abb_imprime(a->dir);
    }
}

Arv* abb_busca (Arv* r, int v)
{
    if (r == NULL ) return NULL ;
    else if (r->info > v) return abb_busca (r->esq, v);
    else if (r->info < v) return abb_busca (r->dir, v);
    else return r;
}

Arv* abb_insere (Arv* a, int v)
{
    if (a==NULL) {
        a = (Arv*)malloc(sizeof(Arv));
        a->info = v;
        a->esq = a->dir = NULL;
    }
    else if (v < a->info)
         a->esq = abb_insere(a->esq,v);
    else /* v > a->info */
         a->dir = abb_insere(a->dir,v);
    return a;
}

       

Arv* abb_retira (Arv* r, int v)
{
    if (r == NULL)
       return NULL;
    else if (r->info > v)
         r->esq = abb_retira(r->esq, v);
    else if (r->info < v)
         r->dir = abb_retira(r->dir, v);
    else {/* achou o nó a remover */
    /* nó sem filhos */
        if (r->esq == NULL && r->dir == NULL) {
            free(r);
            r = NULL;
        }
        /* nó só tem filho à direita */
        else if (r->esq == NULL) {
            Arv* t = r;
            r = r->dir;
            free(t);
        }
        /* só tem filho à esquerda */
        else if (r->dir == NULL) {
            Arv* t = r;
            r = r->esq;
            free(t);
        }
        /* nó tem os dois filhos */
        else {
            Arv* f = r->esq;
            while (f->dir != NULL) {
                  f = f->dir;
            }
            r->info = f->info;            /* troca as informações */
            f->info = v;
            r->esq = abb_retira(r->esq,v);
        }
   }
   return r;
}

int maiorNo(Arv* r){
	int valor=0;
	if(r==NULL){
		return -1; 
	}else if(r->dir!=NULL){
		valor= maiorNo(r->dir);
    }else{
		return r->info;
    }
    return valor;
}


int calcAltura(Arv* a)
{
    int esq,dir;
    
    if(a==NULL) 
       return -1;
    
    esq = calcAltura(a->esq);
    dir = calcAltura(a->dir);
    
    if(esq>dir) 
       return ++esq;
    else 
       return ++dir;
}

int maiores(Arv* a, int x){
     int cont=0;
    if(a==NULL)
      return 0;
   
    cont += maiores(a->esq,x);
    cont += maiores(a->dir,x);
    
    if(a->info>x)
       return ++cont;
    else
       return cont;
}          


int main(){
  Arv* abb;
  abb = abb_cria();
  abb = abb_insere(abb, 15);
  abb = abb_insere(abb, 10);
  abb = abb_insere(abb, 22);
  abb = abb_insere(abb, 5);
  abb = abb_insere(abb, 12);
  abb = abb_insere(abb, 14);
  abb = abb_insere(abb, 23);
    
  abb_imprime (abb);
  
  //abb = abb_retira(abb, 6);
  
  //printf("\n");
  
  //abb_imprime (abb);
  
  printf("\nMaior:%d\n",maiorNo(abb));
  
  printf("\nMaiores:%d\n",maiores(abb,20));
  
  printf("\nAltura:%d\n",calcAltura(abb));

  return 0;
  
}