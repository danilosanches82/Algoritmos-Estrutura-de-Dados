#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
	int vetor[5]={1, 2, 3, 4, 5};
	char valor;  

	FILE *f = fopen("saidaVetor.data", "w+");

	/*Aplica quebra de linha após 3 caracteres*/
	for(int i = 0; i < 5; i++){
	  if(i==3)
		fprintf(f, "\n%d",vetor[i]);
	  else 
		fprintf(f, "%d",vetor[i]);  
	}

	fclose(f);

	/* abre novamente para a leitura  */
	f = fopen("saidaVetor.data", "a+");

	/*reposiciona o cursor 
	  na posição atual do arquivo*/
	if(fseek( f, 0, SEEK_SET ) != 0){
		printf("Erro no posicionamento de leitura/gravação!\n");
		exit(1);
	}

	/*Armazena os caracteres 10 a 14*/	
	for(int i = 10; i < 15; i++)
		fprintf(f, "\n%d",i);
		
	/*reposiciona o cursor 
	  na posição inicial do arquivo*/
	//fseek( f, 5, SEEK_SET );
	fseek( f, -5, SEEK_CUR );
	//rewind(f);

	/*Leitura com fgets*/
	char info[5];
	while( (fgets(info, sizeof(info), f))!=NULL )
		  printf("%s", info);

	fclose(f);
	return(0);
}

