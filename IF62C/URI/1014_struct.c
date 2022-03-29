#include <stdio.h>
#include <string.h>

typedef struct{
  int km;
  float comb;
}Carro;


float consumo(Carro c){
  return c.km/c.comb;
}
void imprime(Carro c){
  printf("%d %.2f - %.2f km/l", c.km, c.comb,consumo(c));
     
  }

Carro criaCarro(int x, float y){
  Carro c;
  c.km = x;
  c.comb = y;
  return c;
}
int main(){

  Carro c1;
  c1 = criaCarro(500, 35.0);
  imprime(c1);
  
  return 0;
}
