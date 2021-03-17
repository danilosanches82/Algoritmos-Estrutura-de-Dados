#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int main(){
  int a,b,c;
  int ca,cb, cc; //Cópia das variáveis 
  int *pa, *pb, *pc;

  scanf("%d %d %d", &a, &b, &c);
  
  //Faz uma cópia de a,b, c
  ca =a;
  cb = b;
  cc = c;

  //Atribui os endereços aos ponteiros
  pa = &a;
  pb = &b;
  pc = &c;

  // Faz a seleção baseado na ordem crescente
  if (a > c){
 *pa = *pc;
    *pc = ca;     
  }   
  if (a > b){
    *pa = *pb;
    *pb = ca;
  }  
  if (b > c){
    *pb = *pc;
    *pc = cb;
  }

  printf("%d\n%d\n%d\n",
          a,b,c);    
  printf("\n%d\n%d\n%d\n",
          ca,cb,cc);                      

return 0;
} 
