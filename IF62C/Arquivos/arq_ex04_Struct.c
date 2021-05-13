#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct usuario{
	char nome[30];
	int idade;
	int telefone;
}User;	

void main()
{
FILE *pf;

User u1;
strcpy(u1.nome, "Joao");
u1.idade = 20;
u1.telefone= 99999999;

if((pf = fopen("usuario.dat", "wb")) == NULL) /* Abre arquivo binário para escrita */
{
    printf("Erro na abertura do arquivo");
    exit(1);
}

if(fwrite(&u1, sizeof(User), 1,pf) != 1)     
    printf("Erro na escrita do arquivo");
    
fclose(pf);                                    

if((pf = fopen("usuario.dat", "rb")) == NULL) 
{
    printf("Erro na abertura do arquivo");
    exit(1);
}

User *userLido = (User*) malloc(sizeof(User));
if(fread(userLido, sizeof(User), 1,pf) != 1) 
    printf("Erro na leitura do arquivo");

printf("\nO valor de userLido eh': %s\t%d\t%d\t\n", userLido->nome,userLido->idade,userLido->telefone);
fclose(pf);
}

