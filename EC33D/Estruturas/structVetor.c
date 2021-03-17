#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct aluno{
  char nome[30];
  int RA;
  float media;
}Aluno;

int main(){
  Aluno aluno[2];

  strcpy(aluno[0].nome, "Joao");
  aluno[0].RA = 123456;
  aluno[0].media = 10.0;

  printf("%s\t%d\t%.1f",aluno[0].nome, aluno[0].RA, aluno[0].media);

return (0);
}
