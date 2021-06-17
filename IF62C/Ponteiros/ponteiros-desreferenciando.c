#include <stdio.h>

int main()
{
  int *p; // ponteiro para inteiros
  int a = 231;
  int b = 7680;

  printf("&a vale %p\n", &a); // endereço de a
  printf("&b vale %p\n", &b); // endereço de b
  printf("&p vale %p\n", &p); // endereço de p

  printf("p vale %p\n", p); // valor de p (leitura)

  p = &a;                     // atribuir valor a p
  printf("p vale %p\n", p);   // ler valor de p
  printf("*p vale %d\n", *p); // desreferenciar p

  p = &b;
  printf("p vale %p\n", p);
  printf("*p vale %d\n", *p);

  *p = 500; // desreferenciar p
  printf("b vale %d\n", b);

  return 0;
}