#include <bits/stdc++.h>
#define lsb(x) ((x) & (-x))

using namespace std;

typedef  pair<int, int> pii;
typedef long long ll;
const int MAXN  = 200010;

vector<int> adj[MAXN];
bool seen[MAXN];
int tempo[MAXN];

void dfs(int u){
    seen[u] = 1;
    for(auto v: adj[u]){
        if(seen[v]) continue;
        tempo[v] = min(tempo[v], tempo[u]);
        dfs(v);
    }
}
int main()
{
    int n;
    cin >> n;
    int raiz;
    for(int i = 1; i <= n; i++){
        int pi;
        cin >> pi;
        if(pi == -1){
            raiz = i;
            continue;
        }
        adj[i].push_back(pi);
        adj[pi].push_back(i);
    }

    for(int i = 1; i <= n; i++){
        int bi;
        cin >> bi;
        tempo[bi] = i;
    }

    dfs(raiz);

    for(int i = 1; i <= n; i++){
        cout << tempo[i];
        cout << (i == n?"\n":" ");
    }
    return 0;
}
