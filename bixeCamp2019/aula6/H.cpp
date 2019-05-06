#include <bits/stdc++.h>
#define MAXN 200010
using namespace std;

vector<int> adj[MAXN];
bool cicle, seen[MAXN];

void dfs(int u){
    seen[u] = 1;
    for(auto v: adj[u]){
        if(!seen[v])
            dfs(v);
    }
    if(adj[u].size() != 2)
        cicle = false;
}

int main()
{
    int n, m;
    cin >> n >> m;
    while(m--){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int cnt = 0;
    for(int i = 1; i <= n; i++){
        if(!seen[i]){
            cicle = true;
            dfs(i);
            if(cicle)
                cnt++;
        }
    }

    cout << cnt << endl;
    
    return 0;
}
