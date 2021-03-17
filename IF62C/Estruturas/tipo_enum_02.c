#include<stdio.h>
#include<string.h>

typedef enum { BLACK, BLUE, GREEN, RED, YELLOW, WHITE } Color_type ;

char* color_name (Color_type c){
	switch (c){
		case BLACK   : return ("black")  ;
		case BLUE    : return ("blue")   ;
		case GREEN   : return ("green")  ;
		case RED     : return ("red")    ;
		case YELLOW  : return ("yellow") ;
		case WHITE   : return ("white")  ;
		default      : return ("") ;
	}
}

int main (){
	Color_type c1;
	c1 = BLUE ;
	printf ("Cor %s\n", color_name(c1)) ;
}