#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define true 1
#define false 0
#define MAXSIZE 35

bool visitados[MAXSIZE];
char adj[MAXSIZE][MAXSIZE];
char vertices[MAXSIZE];

int tam;
int m, n;

void dfs(int);
int compara(const void *, const void *);

int main ()
{

	char a, b;
	int i, j, casos;
	int caso = 0;

	scanf("%d", &casos);

	while (casos--)
	{

		scanf("%d %d", &m, &n);

		
		for (i = 0; i < n; ++i)
		{

			scanf(" %c %c", &a, &b);
			adj[a - 'a'][b - 'a'] = 1;
			adj[b - 'a'][a - 'a'] = 1;

		}
		
		printf("Case #%d:\n", ++caso);
		int ans = 0;
		for (i = 0; i < m; ++i)
		{

			if (!visitados[i])
			{

				++ans, dfs(i);
				qsort(vertices, tam, sizeof(char), compara);
				for (j = 0; j < tam; ++j)
					printf("%c,", vertices[j] + 'a');

				printf("\n");

			}

			tam = 0;

		}

		printf("%d connected components\n", ans);
		printf("\n");
		memset(visitados, false, sizeof(visitados));
		memset(adj, 0, sizeof(adj));

	}
    return 0;
}


void dfs(int u)
{

	int i;
	visitados[u] = true;
	vertices[tam++] = u;
	for (i = 0; i < m; ++i)
		if (adj[u][i])
			if (!visitados[i])
				dfs(i);

}

int compara(const void *a, const void *b)
{
    char x = *((char*)a);
    char y = *((char*)b);

	if (x == y)
		return 0;
	else if (x > y)
		return 1;
	else
		return -1;
}
