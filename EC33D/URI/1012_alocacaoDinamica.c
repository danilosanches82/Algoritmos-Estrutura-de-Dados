#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct area{
  double a;
  double b;
  double c;
}Area;

int main(){
  Area *forma_g;
  forma_g = (Area*) malloc(sizeof(Area));

  scanf("%lf %lf %lf", &forma_g->a, &forma_g->b, &forma_g->c);
  
  //Dica:
  //https://matematicabasica.net/area-e-perimetro/#:~:text=A%20%C3%A1rea%20de%20uma%20figura,altura%20(h)%20do%20objeto.
  printf("TRIANGULO: %.3f\n", (forma_g->a*forma_g->c)/2 );
  printf("CIRCULO: %.3f\n", (3.14159*(forma_g->c*forma_g->c)));
  printf("TRAPEZIO: %.3f\n", ((forma_g->a+forma_g->b)*forma_g->c)/2);
  printf("QUADRADO: %.3f\n", (forma_g->b * forma_g->b));
  printf("RETANGULO: %.3f\n", (forma_g->a * forma_g->b));

  free(forma_g);
  
return 0;
}