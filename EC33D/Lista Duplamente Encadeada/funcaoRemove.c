ListaD* removeLista(ListaD *L, int info)
{
    ListaD *aux=L;
    
    if(L==NULL)
      return;
    
    while(aux!=NULL && aux->valor!=info)           
        aux=aux->prox;
    
    if(aux==NULL)
       return L;
       
     //Possui apenas 1 elemento
    if(aux->ant==NULL && aux->prox==NULL)
    {        
        free(aux);
        return NULL;
    }else if (aux->ant==NULL){ //primeria posição		
		L=aux->prox;
        L->ant=NULL;
        free(aux);
        return L;        
    }else if(aux->prox==NULL)         //Ultima posição
        {
            aux->ant->prox=NULL;
            free(aux);
        }
        //Está no meio da lista
        else
        {
            aux->ant->prox=aux->prox;
            aux->prox->ant=aux->ant;
            free(aux);
        }
    return L;
}