#include <bits/stdc++.h>

using namespace std;

vector<int> adj[10010];
int x, max_dist;

void dfs(int v, int p, int d){
    if(d > max_dist){
        max_dist = d;
        x = v;
    }
    for(auto u: adj[v]){
        if(u == p) continue;
        dfs(u, v, d+1);
    }
}

int main()
{
    int n;
    cin >> n;
    for(int i = 1; i < n; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    max_dist = 0;
    dfs(1, 0, 0);
    max_dist = 0;
    dfs(x, 0, 0);
    cout << max_dist << endl;
    return 0;
}
