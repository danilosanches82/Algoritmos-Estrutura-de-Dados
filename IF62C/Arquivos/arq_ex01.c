#include <stdio.h>

int main(void) {
int vetor[5]={1, 2, 3, 4, 5};
char valor;  

FILE *f = fopen("saidaVetor.data", "w+");

for(int i = 0; i < 5; i++)
  fprintf(f, "%d",vetor[i]);

fclose(f);


/* abre novamente para a leitura  */
f = fopen("saidaVetor.data", "r");
    
while (fscanf(f,"%c",&valor) !=EOF)
     printf("%c\n",valor);

fclose(f);
return(0);
}


