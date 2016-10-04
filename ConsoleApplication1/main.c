#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int valor;
}ELEMENTO;


typedef struct
{
	ELEMENTO elemento;
	ELEMENTO *proximo;
	ELEMENTO *anterior;
}ELEMENTO_NO;

typedef struct lista
{
	ELEMENTO *topo;
	int totalElementos;
}LISTA;

LISTA* CriarLista()
{
	LISTA *pLista = (LISTA *)malloc(sizeof(LISTA));
	pLista->topo = NULL;
	pLista->totalElementos = 0;

	return pLista;
}

int main()
{
	printf("Ola Mundo!\n");
	getchar();
	return 0;
}