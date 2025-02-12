#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 1000

typedef struct noArv{

	char letra;
	struct noArv *direita;
	struct noArv *esquerda;

} noArv;

noArv* novoNo(char letra);
void showposfixa(noArv *arvore);
int src(char *str, int inicio, int fim, char letra);
noArv* tree(char *infixa, char *prefixa, int inInicio, int inFim);

short indice;

int main ()
{

	short qtsCasos;
	char prefixa[MAXSIZE], infixa[MAXSIZE];

	while (scanf("%s %s", prefixa, infixa) != EOF)
	{

		int tam = strlen(prefixa);
		indice = 0;
		noArv *raiz = tree(infixa, prefixa, 0, tam - 1);
		showposfixa(raiz);
		printf("\n");

	}
    return 0;
}

noArv* novoNo(char letra)
{

	noArv *no = (noArv *) malloc(sizeof(noArv));
	no->letra = letra;
	no->esquerda = no->direita = NULL;

	return no;
}

int src(char *str, int inicio, int fim, char letra)
{

	short i;
	for (i = inicio; i <= fim; ++i)
		if (str[i] == letra)
			return i;

	return -1;

}

noArv* tree(char *infixa, char *prefixa, int inInicio, int inFim)
{

	int infixaIndice;

	if (inInicio > inFim)
		return NULL;

	noArv *no = novoNo(prefixa[indice++]);
	if (inInicio == inFim)
		return no;

	infixaIndice = src(infixa, inInicio, inFim, no->letra);
	no->esquerda = tree(infixa, prefixa, inInicio, infixaIndice - 1);
	no->direita = tree(infixa, prefixa, infixaIndice + 1, inFim);

	return no;

}

void showposfixa(noArv *no)
{

	if (no == NULL)
		return;

	showposfixa(no->esquerda);
	showposfixa(no->direita);
	printf("%c", no->letra);

}
