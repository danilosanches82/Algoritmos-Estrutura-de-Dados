//1006 - Média 2

#include<stdio.h>

float media(float a, float b, float c){
  return (a*2 + b*3 + c*5)/(2+3+5);
}

int main( ) {
  float n1, n2, n3;
  scanf("%f",&n1);
  scanf("%f",&n2);
  scanf("%f",&n3);

  printf("MEDIA = %.1f\n", media(n1,n2,n3));
  
return (0);
}
