#include <stdlib.h>

int main()
{
	int num[20], *ponteiro_para_num, diferenca;
	char str[30], nome[20], *ponteiro_para_str, *ponteiro_ajudante;

	//ponteiros e vetores;
	ponteiro_ajudante = nome;
	ponteiro_para_str = str;
	ponteiro_para_num = num;
	ponteiro_para_num += 3;	 // ponteiro_para_num = &num[3]
	*ponteiro_para_num = 10; // equivale a num[3] = 10
	ponteiro_para_str++;	 // ponteiro_para_str = &str[1]

	diferenca = ponteiro_para_str - ponteiro_ajudante;
	// CORRETO, mas o valor não tem
	// necessáriamente o sentido de "numero
	// de bytes entre ponteiro_ajudante e ponteiro_para_str".

	ponteiro_ajudante = str;
	ponteiro_para_str = &str[30];

	diferenca = ponteiro_para_str - ponteiro_ajudante;
	//  CONCEITUALMENTE CORRETO. diferenca == 30

	printf("diferenca = %d \n", diferenca);
	printf("ponteiro_ajudante = %u \n", ponteiro_ajudante);
	printf("ponteiro_para_str = %u \n", ponteiro_para_str);

	return 0;
}
