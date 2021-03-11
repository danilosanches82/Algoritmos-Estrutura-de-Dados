#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct produto{
  int codigo;
  int qtde;
  float valor;
}Produto;

//com vetor
int main(){
  Produto prod[2];
  scanf("%d %d %f", &prod[0].codigo, &prod[0].qtde, &prod[0].valor);
  scanf("%d %d %f", &prod[1].codigo, &prod[1].qtde, &prod[1].valor);
  
  
  printf("VALOR A PAGAR: R$ %.2f\n",
  ((prod[0].qtde * prod[0].valor) + (prod[1].qtde * prod[1].valor)));
  
return (0);
}