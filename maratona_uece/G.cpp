#include <bits/stdc++.h>
#define MAX 101000
using namespace std;

struct Aresta{
    int a, b;
};

int cor[MAX];
bool isBipartido = true;
vector<int> g[MAX];
vector<Aresta> arestas;
int n, m;

void dfs(int u){
    for(int v: g[u]){
        if(cor[v] == -1)
        {
            cor[v] = !cor[u];
            dfs(v);
        }else if(cor[v] == cor[u])
            isBipartido = false;
    }
}

bool can(int k){
    for(int i = 0; i <= n; i++)
        g[i].clear();

    for(int i = 0; i <= k; i++){
        int a = arestas[i].a;
        int b = arestas[i].b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    isBipartido = true;
    memset(cor, -1, sizeof cor);
    for(int i = 1; i <= n; i++){
        if(cor[i] == -1){
            cor[i] = 1;
            dfs(i);
        }
    }

    return isBipartido;

}




int main()
{

    cin >> n >> m;
    memset(cor, -1, sizeof cor);
    for(int i = 0; i < m; i++){
        Aresta aresta;
        cin >> aresta.a >> aresta.b;
        arestas.push_back(aresta);

    }

    int ini = 0, fim = m-1, ans = -1;
    while(ini <= fim){
        int meio = (ini+fim)/2;

        if(can(meio)){
            ini = meio+1;
            ans = meio;
        }else fim = meio-1;

    }

    for(int i = 0; i < m; i++){
        if(i <= ans) printf("Sim\n");
        else printf("Nao\n");
    }

    return 0;
}
