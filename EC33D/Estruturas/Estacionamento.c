#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
  int hora;
  int min;
  int sec;
}Hora;

typedef struct{
   int num;
   char marca[20];
   Hora* entrada;
   Hora* saida;
}Estacionamento;

int main(){

  Estacionamento* carro1;
  //Aloca o primeiro carro
  carro1 = (Estacionamento*) 
  malloc(sizeof(Estacionamento));

  carro1->entrada = (Hora*) malloc(sizeof(Hora));
  carro1->saida = (Hora*) malloc(sizeof(Hora));

  carro1->num = 123456;
  strcpy(carro1->marca, "Honda");
  carro1->entrada->hora = 13;
  carro1->entrada->min = 30;
  carro1->entrada->sec = 15;

  carro1->saida->hora = 14;
  carro1->saida->min = 30;
  carro1->saida->sec = 15;

  printf("%d\n%s\n%d:%d:%d\n%d:%d:%d\n",carro1->num,carro1->marca,carro1->entrada->hora,
    carro1->entrada->min,
    carro1->entrada->sec,
    carro1->saida->hora,
    carro1->saida->min,
    carro1->saida->sec);

  /*
  printf("%d\n", (int) sizeof(Estacionamento));
   printf("%d\n", (int) sizeof(Hora));
   printf("%d\n", (int) sizeof(Hora*));
    printf("%d\n", (int) sizeof(Estacionamento*));
  */
  
  
  return 0;
  
}
