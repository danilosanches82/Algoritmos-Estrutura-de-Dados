#include <stdio.h>

int main(void)
{
  int b, *c;

  b = 10;
  c = &b;
  *c = 11;

  printf("b = %d\n", b);

  return 0;
}
