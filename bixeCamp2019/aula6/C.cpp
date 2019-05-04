#include <bits/stdc++.h>
#define MAXN 1010
using namespace std;

int seen[MAXN];
vector<int> adj[MAXN];

void dfs(int v){
    seen[v] = 1;
    for(int u: adj[v]){
        if(!seen[u])
            dfs(u);
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    while(m--){
        int i, j;
        cin >> i >> j;
        adj[i].push_back(j);
        adj[j].push_back(i);
    }

    int cnt = 0;
    for(int i = 1; i <= n; i++)
    {
        if(!seen[i]){
            dfs(i);
            cnt++;
        }
    }

    cout << cnt << endl;
    return 0;
}
