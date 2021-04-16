#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int fatorial (int n){
  if (n == 0)
    return 1;
  else if (n<0){
    printf("\nErro: fatorial de numero negativo!\n");  
    exit(0);
  }
  return n*fatorial(n-1);
}

int main(){

  int n, fat=1;
  scanf("%d", &n);
  fat=fatorial(n);
  printf("O fatorial de %d eh: %d", n,fat);
  return 0;
}