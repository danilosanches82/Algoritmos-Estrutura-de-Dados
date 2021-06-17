#include <stdio.h>

int main()
{
	int num[20], *ponteiro_para_num;
	char str[30], nome[20], *ponteiro_para_str, *ponteiro_ajudante;

	ponteiro_ajudante = nome;
	ponteiro_para_str = str;
	ponteiro_para_num = num;

	printf("nome =              %p\n", nome);
	printf("ponteiro_ajudante = %p\n", ponteiro_ajudante);
	printf("str =               %p\n", str);
	printf("ponteiro_para_str = %p\n", ponteiro_para_str);
	printf("num =               %p\n", num);
	printf("ponteiro_para_num = %p\n", ponteiro_para_num);

	return 0;
}
