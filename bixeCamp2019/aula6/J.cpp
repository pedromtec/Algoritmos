#include <bits/stdc++.h>
#define MAXN 510
using namespace std;

int g[MAXN][MAXN];
int cor[MAXN];
int n, m;

bool bipartido = true;
vector<int> adj[MAXN];
vector<int> g1, g2;

void dfs(int u, int p){

    if(cor[u]) g1.push_back(u);
    else g2.push_back(u);

    for(int v: adj[u]){
        if(v == p)  continue;
        if(cor[v] == -1){
            cor[v] = !cor[u];
            dfs(v, u);
        }
        else if(cor[v] == cor[u])
            bipartido = false;
    }

}

int main()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        cor[i] = 2;

    while(m--){
        int a, b;
        cin >> a >> b;
        g[a][b] = g[b][a] = 1;
    }

    for(int i = 1; i <= n; i++){
        for(int j = i+1; j <= n; j++){
            if(g[i][j]) continue;
            adj[i].push_back(j);
            adj[j].push_back(i);
        }
    }

    for(int i = 1; i <= n; i++){
        if(adj[i].size() > 0)
            cor[i] = -1;
        //printf("%d\n", cor[i]);
    }

    for(int u = 1; u <= n; u++){
        if(cor[u] == -1){
            cor[u] = 0;
            dfs(u, 0);

            if(bipartido){
                for(int u: g1)
                    if(adj[u].size() != g2.size())
                        bipartido = false;
                for(int u: g2)
                    if(adj[u].size() != g1.size())
                        bipartido = false;
            }
            if(!bipartido) break;
        }
    }

    if(bipartido){
        cout << "Yes\n";
        for(int i = 1; i <= n; i++){
            if(cor[i] == 0)
                cout << "a";
            else if(cor[i] == 1)
                cout << "c";
            else cout << "b";
        }
        cout << "\n";
    }else{
        cout << "No\n";
    }

    return 0;
}
