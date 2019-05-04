#include <bits/stdc++.h>

using namespace std;

const int MAXN = 110;
int seen[MAXN];

vector<int> adj[MAXN];

void dfs(int v){
    seen[v] = 1;
    for(auto u: adj[v]){
        if(!seen[u])
            dfs(u);
    }
}



int main(){
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1);
    bool ans = (n == m);
    for(int i = 1; i <= n && ans; i++)
        if(!seen[i]) ans = false;


    if(ans && n == m) cout << "FHTAGN!\n";
    else cout << "NO\n";

    return 0;
}
