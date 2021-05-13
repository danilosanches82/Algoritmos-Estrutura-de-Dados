#include <stdio.h>
#include <string.h>

int main(void) {
char valor;  

FILE *f = fopen("saidaVetor.data", "w");

for(int i = 0; i < 15; i++){  
    fprintf(f, "%d",i);  
}

fclose(f);

/* abre novamente para a leitura  */
f = fopen("saidaVetor.data", "r");

/*Pega o tamnho do arquivo 
  em bytes*/
long int tamanho = 0;
fseek( f, 0, SEEK_END );
tamanho = ftell(f);

printf("\nTamanho %ld\t", tamanho);
fclose(f);
return(0);
}

