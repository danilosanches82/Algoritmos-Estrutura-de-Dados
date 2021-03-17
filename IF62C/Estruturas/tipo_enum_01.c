#include <stdio.h>
#include <string.h>

typedef enum { BLACK, BLUE, GREEN, RED, YELLOW, WHITE } Color_type ;

void color_name (Color_type c, char nome[]){
  switch (c){
		case BLACK   : strcpy(nome,"black");break;
		case BLUE    : strcpy(nome,"blue");break;
		case GREEN   : strcpy(nome,"green");break;
		case RED     : strcpy(nome,"red");break;
		case YELLOW  : strcpy(nome,"yellow");break;
		case WHITE   : strcpy(nome,"white");break;
		default      : strcpy(nome," ");
	}  
}

int main (){
	Color_type c1;
  char color[10];
  c1 = RED ;
  color_name(c1, color);
	printf ("Cor %s\n", color) ;
}