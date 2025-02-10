#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define true 1
#define false 0
#define MAXSIZE 10040

int in[MAXSIZE];
int vis[MAXSIZE];
int out[MAXSIZE];
int adj[MAXSIZE];

int n;
bool solve();

int main(int argc, char **argv)
{

    scanf("%d", &n);
    printf("%s\n", solve() ? "S" : "N");
        
    return 0;

}

bool solve()
{

    int i, u, v;
    int ans = 0;

    for (i = 1; i <= n; ++i)
    {

        scanf("%d %d", &u, &v);
        adj[u] = v;
        ++out[u];
        ++in[v];

    }

    for (i = 1; i <= n; ++i)
        if (in[i] != 1 || out[i] != 1)
            return false;

    i = 1;
    while (vis[i] == false)
        vis[i] = true, ++ans, i = adj[i];

    if (ans != n)
        return false;

    return true;

}
