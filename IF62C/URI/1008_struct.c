#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct funcionario{
  int codigo;
  int horas_t;
  float valor_h;
}Funcionario;

int main(){
  Funcionario f1;
  scanf("%d", &f1.codigo);
  scanf("%d", &f1.horas_t);
  scanf("%f", &f1.valor_h);
  
  printf("NUMBER = %d\nSALARY = U$ %.2f\n", f1.codigo, (f1.horas_t*f1.valor_h));
  
return (0);
}