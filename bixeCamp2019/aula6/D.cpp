#include <bits/stdc++.h>

using namespace std;
const int MAXN = 110;
int pai[MAXN], seen[MAXN];
vector<int> adj[MAXN];
bool cicle = false;

void dfs(int v){
    seen[v] = 1;
    for(auto u: adj[v]){
        if(u == pai[v]) continue;
        if(!seen[u]){
            pai[u] = v;
            dfs(u);
        }else
            cicle = true;
    }
}



int main(){
    int n, m;
    cin >> n >> m;
    while(m--){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i = 1; i <= n; i++){
        if(!seen[i]){
            pai[i] = i;
            dfs(i);
        }
    }
    if(cicle)
        cout << "FHTAGN!\n";
    else cout << "NO\n";

    return 0;
}
