//1005 - Média 1 - Função
#include<stdio.h>

float media(float, float);


float media( float a, float b){
 return (a*3.5 + b*7.5)/(3.5+7.5);
  
}
int main( ) {
  float n1, n2;
  scanf("%f",&n1);
  scanf("%f",&n2);

  printf("MEDIA = %.5f\n",
    media(n1,n2));
  
return (0);
}
