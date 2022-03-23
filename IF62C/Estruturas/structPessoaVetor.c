#include <stdio.h>
#include <string.h>

typedef struct{
  int dia;
  int mes;
  int ano;
}Data;

typedef struct{
  char Nome[30];
  int idade;
  Data dataNasc;
}Pessoa;

void imprime(Pessoa info[], int qtde){
  for(int i =0; i <qtde; i++){
    printf("%s\n%d\n%d/%d/%d\n",
        info[i].Nome,
        info[i].idade,
        info[i].dataNasc.dia,
        info[i].dataNasc.mes,
        info[i].dataNasc.ano); 
    } 
}

int main(){

  //Declara duas pessoas
  // Pessoa p1;
  //  Pessoa p2;
  //Trabalhar no formato de vetor
  Pessoa p[2];//indices :0 e 1

  //Primeira pessoa
  strcpy(p[0].Nome, "Danilo");
  p[0].idade = 39;
  p[0].dataNasc.dia = 1;
  p[0].dataNasc.mes = 1;
  p[0].dataNasc.ano = 2000;

  //Segunda pessoa
  strcpy(p[1].Nome, "Joao");
  p[1].idade = 20;
  p[1].dataNasc.dia = 1;
  p[1].dataNasc.mes = 1;
  p[1].dataNasc.ano = 2000;

  //Argumentos: Nome do vetor e 
  // dimensão
  imprime(p, 2);
  
  return 0;
}
