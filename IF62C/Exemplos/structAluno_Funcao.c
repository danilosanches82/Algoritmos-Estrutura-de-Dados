#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct aluno{
  char nome[30];
  int RA;
  float media;
}Aluno;

Aluno cadastroAluno(int RA, float media, char nome[]){
  Aluno tempAluno;

  strcpy(tempAluno.nome, nome);
  tempAluno.RA = RA;
  tempAluno.media = media;

  return tempAluno;
}

int main(){
  
  Aluno aluno = cadastroAluno(123456, 10.0, "Joao");

  printf("%s\t%d\t%.1f",aluno.nome, aluno.RA, aluno.media);

  return (0);
}