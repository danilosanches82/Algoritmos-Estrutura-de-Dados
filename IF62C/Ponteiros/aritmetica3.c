
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int main()
{
  int num[20], *ponteiro_para_num;
  char string[30], *ponteiro_para_string, *ponteiro_para_nome, nome[20];

  //ponteiros e vetores;
  ponteiro_para_nome = nome;
  ponteiro_para_string = string;
  ponteiro_para_num = num;
  ponteiro_para_num += 3;	 // ponteiro_para_num = &num[3]
  *ponteiro_para_num = 10; // equivale a num[3] = 10

  printf("ponteiro_para_string (&string[0]) = %p\n ", ponteiro_para_string);
  ponteiro_para_string++; // ponteiro_para_string = &string[1]

  printf("ponteiro_para_num = %p\n", ponteiro_para_num);
  printf("&num[3] = %p\n", &num[3]);
  printf("num[3] %d\n", num[3]);
  printf("ponteiro_para_string = %p\n ", ponteiro_para_string);

  return 0;
}
