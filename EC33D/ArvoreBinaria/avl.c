/*
 * Código fonte árvore do tipo AVL
 */ 

#include<stdio.h>
#include<stdlib.h>
typedef struct Arvore
{
    int info;
    int fbal;
    struct Arvore* esq;
    struct Arvore* dir;
}Arv;


Arv* criaVazio();
Arv* insereAVL(Arv* a,int info);
Arv* balanceiaArv(Arv* a);
void imprimeArv(Arv* a);
void imprimeFbal(Arv* a);
int calculaAltura(Arv* a);
void calculaFbal(Arv* a);
int verificaDesbalanceada(Arv* a);


Arv* criaVazio()
{
    return NULL;
}
void imprimeArv(Arv* a)
{
    if(a!=NULL)
    {
        imprimeArv(a->esq);
        printf("%d  ",a->info);
        imprimeArv(a->dir);
    }
}
void imprimeFbal(Arv* a)
{
    if(a!=NULL)
    {
        imprimeFbal(a->esq);
        printf("%d  ",a->fbal);
        imprimeFbal(a->dir);
    }
}
int calculaAltura(Arv* a)
{
    int esq,dir;
    if(a==NULL) return -1;
    esq = calculaAltura(a->esq);
    dir = calculaAltura(a->dir);
    if(esq>dir) return esq + 1;
    else return dir + 1;
}
void calculaFbal(Arv* a)
{
    if(a!=NULL)
    {
        calculaFbal(a->esq);
        a->fbal = calculaAltura(a->esq) - calculaAltura(a->dir);
        calculaFbal(a->dir);
    }
}

int verificaDesbalanceada(Arv* a)
{
    if(a!=NULL)
    {
        if((a->fbal==2)||(a->fbal==-2))
            return 1;
        else
            return 0+verificaDesbalanceada(a->esq)+verificaDesbalanceada(a->dir);
    }
    else
        return 0;
}
        

Arv* insereAVL(Arv* a,int info)
{
    if(a!=NULL)
    {
        if(a->info>info)
        {
            a->esq = insereAVL(a->esq,info);
            //return a;
        }
        if(a->info<info)
        {
            a->dir = insereAVL(a->dir,info);
            //return a;
        }
        
        if(((calculaAltura(a->esq)-calculaAltura(a->dir))==2)||
            (((calculaAltura(a->esq)-calculaAltura(a->dir))==-2))){
		    a = balanceiaArv(a); 
		}		
		return a;	
        
    }
    else
    {
        Arv* b = (Arv*)malloc(sizeof(Arv));
        b->info = info;
        b->esq = (Arv*)NULL;
        b->dir = (Arv*)NULL;
        b->fbal = 0;
        return b;
    }
}
Arv* balanceiaArv(Arv* a)
{
    if(a!=NULL)
    {
        a->esq = balanceiaArv(a->esq);
        a->dir = balanceiaArv(a->dir);
        if(((calculaAltura(a->esq)-calculaAltura(a->dir))==2)||(((calculaAltura(a->esq)-calculaAltura(a->dir))==-2)))
        {
            if(a->esq!=NULL)
            {
                if(((calculaAltura(a->esq)-calculaAltura(a->dir))==2)&&(((calculaAltura(a->esq->esq)-calculaAltura(a->esq->dir))>0)))//caso de rotação direita somente
                {
                    Arv* temp;
                    Arv* q;
                    q = a->esq;
                    temp = q->dir;
                    q->dir = a;
                    a->esq = temp;
                    a = q;
                    return a;
                }
                if(((calculaAltura(a->esq)-calculaAltura(a->dir))==2)&&((calculaAltura(a->esq->esq)-calculaAltura(a->esq->dir))<0))//caso de rotação esquerda-direita
                {
                    Arv* temp;
                    Arv* q;
                    q = a->esq->dir;
                    temp = q->esq;
                    q->esq = a->esq;
                    a->esq->dir = temp;
                    a->esq = q;
                    q = a->esq;
                    temp = q->dir;
                    q->dir = a;
                    a->esq = temp;
                    a = q;
                    return a;
                }
            }
            if(a->dir!=NULL)
            {
                if(((calculaAltura(a->esq)-calculaAltura(a->dir))==-2)&&(((calculaAltura(a->dir->esq)-calculaAltura(a->dir->dir))<0)))//caso de rotacao esquerda somente
                {
                    Arv* temp;
                    Arv* q;
                    q = a->dir;
                    temp = q->esq;
                    q->esq = a;
                    a->dir = temp;
                    a = q;
                    return a;
                }
                if(((calculaAltura(a->esq)-calculaAltura(a->dir))==-2)&&(((calculaAltura(a->dir->esq)-calculaAltura(a->dir->dir))>0))) //caso de rotacao direita-esquerda somente
                {
                    Arv* temp;
                    Arv* q;
                    q = a->dir->esq;
                    temp = q->dir;
                    q->dir = a->dir;
                    a->dir->esq = temp;
                    a->dir = q;c
                    q = a->dir;
                    temp = q->esq;
                    q->esq = a;
                    a->dir = temp;
                    a = q;
                    return a;
                }
            }
        }
        else
            return a;
    }
    else
        return a;
}

int main()
{
    Arv* root = NULL;
    Arv* avl;
    int op=0,info;
    while(info!=-1)
    {
        printf("\n\nDigite um numero para inserir na arvore: ");
        scanf("%d",&info);
        root = insereAVL(root,info);
        calculaFbal(root);
        /*
        while(verificaDesbalanceada(root))
        {
            avl = balanceiaArv(root);
            calculaFbal(avl);
            root = avl;
            calculaFbal(root);
        }*/
        printf("\n\nArvore:\n\n");
        imprimeFbal(root);
        printf("\n");
        imprimeArv(root);
    }
}
