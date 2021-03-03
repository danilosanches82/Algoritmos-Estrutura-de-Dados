#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int main(){
	
int num[20], *pnum, diff;
char str[30], *pstr, *pn, nome[20];

//ponteiros e vetores;
pn = nome;
pstr = str;
pnum = num;
pnum += 3;  // pnum = &num[3] 
*pnum = 10; // equivale a num[3] = 10 
printf ("%p\n " , pstr) ;
pstr++; 	// pstr = &str[1] 

printf ( "\n \n %p \n" , pnum) ;
printf ( "%p\n" , &num[3]) ;
printf ( "%d\n" , num[3]) ;
printf ( "%p\n " , pstr ) ;
}

