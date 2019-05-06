#include <bits/stdc++.h>
#define MAXN 100010
using namespace std;

vector<int> adj[MAXN];
bool has_cat[MAXN];
int n, m;

int dfs(int v, int p, int cats)
{
    if((int)adj[v].size() == 1 && v != 1)
        return 1;
    int sum = 0;
    for(auto u: adj[v]){
        if(u == p) continue;

        int cats_aux = has_cat[u] ? cats+1 : 0;
        if(cats_aux > m) continue;

        sum += dfs(u, v, cats_aux);
    }
    return sum;
}
int main()
{
    cin >> n >> m;
    for(int i = 1; i <= n; ++i)
        cin >> has_cat[i];

    for(int i = 1; i < n; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    cout << dfs(1, 0, has_cat[1]) << endl;

    return 0;
}
