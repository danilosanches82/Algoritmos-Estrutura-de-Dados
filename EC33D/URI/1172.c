/*1172 Substituição em Vetor I*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main (){
	int i, num[10], *pnum;
	pnum = num;

  for (i=0; i<10;i++){
	  scanf("%d", &num[i]);
    if(num[i] <= 0)  num[i] = 1;
  }

  for (i=0; i<10;i++)
    printf("X[%d] = %d\n", i, num[i]);
}
