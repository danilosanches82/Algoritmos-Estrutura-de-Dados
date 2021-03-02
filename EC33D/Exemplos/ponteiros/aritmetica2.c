#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main (){
	int num[20], *pnum;
	char str[30], *pstr, *pn, nome[20];
	pn = nome;
	pstr = str;
	pnum = num;
	printf("%p\n", nome);
  printf("%p\n", pn);
  printf("%p\n", str);
  printf("%p\n", pstr);
  printf("%p\n", num);
  printf("%p\n", pnum);
}
