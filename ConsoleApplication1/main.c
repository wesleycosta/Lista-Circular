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
	ELEMENTO_NO *topo;
	ELEMENTO_NO *incio;
	int totalElementos;
}LISTA;

LISTA* CriarLista()
{
	LISTA *pLista = (LISTA *)malloc(sizeof(LISTA));
	pLista->topo = NULL;
	pLista->totalElementos = 0;
	return pLista;
}

int ListaVazia(LISTA *pLista)
{
	return (!pLista->topo);
}

// VERIFICA SE DOIS ELEMENTOS SÃO IGUAIS
int Igual(ELEMENTO A, ELEMENTO B)
{
	return(A.valor == B.valor);
}

// BUSCA UM ELEMENTO DA LISTA, CASA NÃO EXISTA RETORNA NULL
ELEMENTO_NO *BuscarElemento(LISTA *pLista, ELEMENTO elemento)
{
	ELEMENTO_NO *pIndex = NULL;
	int index = 0;

	for (pIndex = pLista->topo; index < pLista->totalElementos; pIndex = pIndex->proximo)
		if (Igual(pIndex->elemento, elemento))
			return pIndex;

	return NULL;
}

// INSERE UM NOVO ELEMENTO DA LISTA
int Inserir(LISTA *pLista, ELEMENTO elemento)
{
	ELEMENTO_NO *novoElemento = (ELEMENTO_NO *)malloc(sizeof(ELEMENTO_NO));

	// VERIFICA SE O NOVO ELEMENTO FOI ALOCADO NA MEMORIA
	if (!novoElemento)
		return -1; // ERRO AO ALOCAR O NOVO ELEMENTO
	else
	{
		novoElemento->elemento = elemento;

		// VERIFICA SE A LISTA ESTA VAZIA
		if (ListaVazia(pLista))
		{
			novoElemento->proximo = novoElemento; // O PROXIMO DO NOVO ELEMENTO APONTA PARA O INICIO DA FILA  (NOVO ELEMENTO)
			novoElemento->anterior = novoElemento; // O ANTERIRO DO NOVO ELEMENTO APONTA PARA O FINAL DA FILA (NOVO ELEMENTO)
			pLista->incio = novoElemento; // INICIO DA FILA RECEBE O NOVO ELEMENTO
		}
		else
		{
			novoElemento->anterior = pLista->topo; // O ANTERIOR DO NOVO ELEMENTO APONTA PARA O ULTIMO ELEMENTO DA FILA
			novoElemento->proximo = pLista->incio; // O PROXIMO  DO NOVO ELEMENTO APONTA PARA O INICIO DA FILA

			pLista->topo->proximo = novoElemento;   // O PROXIMO DO ULTIMO ELEMNTO APONTA PARA O NOVO ELEMENTO
			pLista->incio->anterior = novoElemento; // O ANTERIOR DO INCIO APONTA PARA O FINAL DA LISTA
		}

		pLista->topo = novoElemento; // TOPO RECEBE O NOVO ELEMENTO
		return pLista->totalElementos++;
	}
}

int Remover(LISTA*pLista, ELEMENTO elemento)
{
	ELEMENTO_NO *elementoEncontrado = BuscarElemento(pLista, elemento);

	if (!elementoEncontrado)
		return -1;
	else
	{
		ELEMENTO_NO * elementoAntes = elementoEncontrado->anterior;
	}
}

// IMPRIME TODOS OS ELEMENTOS DA LISTA
void Imprimir(LISTA *pLista)
{
	ELEMENTO_NO *pIndex = pLista->topo;
	int index = 0;

	for (pIndex = pLista->topo; index < pLista->totalElementos; pIndex = pIndex->anterior)
		printf("[%d] - %d \n", index++, pIndex->elemento.valor);
}

int main()
{
	LISTA *pLista = CriarLista();
	ELEMENTO elemento;
	int i = 0;

	for (i = 1; i <= 5; i++)
	{
		elemento.valor = i;
		Inserir(pLista, elemento);
	}

	Imprimir(pLista);

	getchar();
	return 0;
}