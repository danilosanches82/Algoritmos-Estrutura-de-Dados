#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int main(){
// aloca memória de forma dinâmica
int *nro = malloc(5 * sizeof(int));

// alterando valores
nro[0] = 1;
nro[1] = 5;
nro[2] = 2;
nro[3] = 4;
nro[4] = 6;

for (int i = 0; i < 5; i++)
  printf("%d ", nro[i]);

 return 0;
}