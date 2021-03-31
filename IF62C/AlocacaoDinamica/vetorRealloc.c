#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int main(){
// aloca memória de forma dinâmica
int *nro = (int*) malloc(5 * sizeof(int));

// alterando valores
nro[0] = 1;
nro[1] = 5;
nro[2] = 2;
nro[3] = 4;
nro[4] = 6;

for (int i = 0; i < 5; i++)
  printf("%d ", nro[i]);

printf("\n%p\n", nro);

//Realloc para tamanho 10;
nro =  (int*) realloc(nro, 10*sizeof(int));
for(int i=5;i<10;i++)
    nro[i] = i+5; //Armazena o valor i + 5;

printf("%p\n", nro);

for (int i = 0; i < 10; i++)
  printf("%d ", nro[i]);

 return 0;
} 