#include <stdio.h>
#include <stdlib.h>
void main()
{
FILE *pf;
int vetor[5] = {1,2,3,4,5};
int *vetLido = (int*) malloc(5 * sizeof(int));
if((pf = fopen("arquivo.dat", "wb")) == NULL) /* Abre arquivo binário para escrita */
{
    printf("Erro na abertura do arquivo");
    exit(1);
}

if(fwrite(vetor, sizeof(int), 5,pf) != 5)     
    printf("Erro na escrita do arquivo");
    
fclose(pf);                                    

if((pf = fopen("arquivo.dat", "rb")) == NULL) 
{
    printf("Erro na abertura do arquivo");
    exit(1);
}
if(fread(vetLido, sizeof(int), 5,pf) != 5)  /* Le em pilido o valor da variável armazenada anteriormente */
    printf("Erro na leitura do arquivo");

printf("\nO valor de vetLido[3] eh: %d", vetLido[3]);
fclose(pf);
}

