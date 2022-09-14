#include <stdio.h>

int main()
{
  int a = 231;
  int *ponteiro_direto;    // ponteiro direto
  int **ponteiro_indireto; // ponteiro indireto, equivale a int *(*p)

  ponteiro_direto = &a;                 // ponteiro_direto recebe o endereço de um int
  ponteiro_indireto = &ponteiro_direto; // ponteiro_indireto recebe o endereço de um ponteiro para int

  printf("a  está em %p e vale %d\n", &a, a);
  printf("ponteiro_direto está em %p e vale %p\n", &ponteiro_direto, ponteiro_direto);
  printf("ponteiro_indireto está em %p e vale %p\n", &ponteiro_indireto, ponteiro_indireto);

  printf("*ponteiro_direto  vale %d\n", *ponteiro_direto);
  printf("*ponteiro_indireto  vale %p\n", *ponteiro_indireto);
  printf("**ponteiro_indireto vale %d\n", **ponteiro_indireto);

  return 0;
}
