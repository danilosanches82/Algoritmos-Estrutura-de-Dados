#include <stdlib.h>
#include <string.h>

int main(){
	
int num[20], *pnum, diff;
char str[30], *pstr, *pn, nome[20];

//ponteiros e vetores;
pn = nome;
pstr = str;
pnum = num;
pnum += 3;  // pnum = &num[3] 
*pnum = 10; // equivale a num[3] = 10 
pstr++; 	// pstr = &str[1] 


diff = pstr - pn;  
// CORRETO, mas o valor não tem
// necessáriamente o sentido de "numero
// de bytes entre pn e pstr".
//


pn = str;
pstr = &str[30];

diff = pstr - pn; 
//  CONCEITUALMENTE CORRETO. diff == 30 

printf("%d \n", diff);
printf("%u \n", pn);
printf("%u \n", pstr); 
}
