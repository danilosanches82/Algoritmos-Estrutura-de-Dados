//1075 - Resto 2
#include<stdio.h>

int resto2(int i, int valor){
	if(i%valor==2)
    return i;
  else
    return 0;  
}	

int main( ) {
  int N, cont=1;
  scanf("%d",&N);

  while(cont < 10000){
    if(resto2(cont,N)!=0)
      printf("%d\n", resto2(cont,N));
    cont++;
  }

return (0);
}
