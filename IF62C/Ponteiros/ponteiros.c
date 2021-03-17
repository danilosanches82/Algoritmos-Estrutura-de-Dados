#include <stdio.h>

int main(void){

int b;
int *c;
b=10;
c=&b;
*c=11;
printf("\n%d\n",b);

return(0);
}
