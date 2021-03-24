#include <stdio.h>
 
int main ()
{
  int a = 231 ;
  int *pd ;  // ponteiro direto
  int **pi ; // ponteiro indireto, equivale a int *(*p)
 
  pd = &a ;  // pd recebe o endereço de um int
  pi = &pd ; // pi recebe o endereço de um ponteiro para int
 
  printf ("a  está em %p e vale %d\n", &a, a) ;
  printf ("pd está em %p e vale %p\n", &pd, pd) ;
  printf ("pi está em %p e vale %p\n", &pi, pi) ;
 
  printf ("*pd  vale %d\n", *pd) ;
  printf ("*pi  vale %p\n", *pi) ;
  printf ("**pi vale %d\n", **pi) ;
 
  return 0 ;
}