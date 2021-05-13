#include <stdio.h>
#include <string.h>

int main(void) {
int vetor[5]={1, 2, 3, 4, 5};
char valor;  

FILE *f = fopen("saidaVetor.data", "w+");

for(int i = 0; i < 5; i++){
  if(i==3)
    fprintf(f, "\n%d",vetor[i]);
  else 
    fprintf(f, "%d",vetor[i]);  
} 

fclose(f);


/* abre novamente para a leitura  */
f = fopen("saidaVetor.data", "r");

int linha=0; 

/*Leitura com fgets*/
  char info[10]; /*armazena a linha em info*/
  while( (fgets(info, sizeof(info), f))!=NULL ){
      printf("%s", info);
      linha++;
  }

printf("\nLinha %d\t", linha);
fclose(f);
return(0);
}

