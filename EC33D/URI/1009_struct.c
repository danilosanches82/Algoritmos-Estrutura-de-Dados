#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct vendedor{
  char nome[30];
  double salario;
  double vendas;
}Vendedor;

int main(){
  Vendedor v1;
  scanf("%s", v1.nome);
  scanf("%lf", &v1.salario);
  scanf("%lf", &v1.vendas);
  
  printf("TOTAL = R$ %.2f\n", (v1.vendas*0.15)+v1.salario);
  
return 0;
}