#include <stdlib.h>
#include <string.h>
#include <stdio.h>

//1009 URI
typedef struct vendedor{
  char nome[30];
  double salario;
  double vendas;
  double total; // saçario com bonus
}Vendedor;

Vendedor cadastroVendedor(double salario, double vendas, char nome[]){
  Vendedor tempV;

  strcpy(tempV.nome, nome);
  tempV.salario = salario;
  tempV.vendas = vendas;
  tempV.total = (tempV.vendas * 0.15) + tempV.salario;
  return tempV;
}

int main(){
  char nome[30];
  double s, v;
  scanf("%s", nome);
  scanf("%lf", &s);
  scanf("%lf", &v);
 
  Vendedor v1 = cadastroVendedor(s,v,nome);

  printf("TOTAL = R$ %.2f\n",v1.total);

  return 0;
}
