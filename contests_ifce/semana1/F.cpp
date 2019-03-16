#include <bits/stdc++.h>
#define MAXN 200010
using namespace std;

pair<int, int> progs[MAXN];
vector<int> adj[MAXN];
int ans[MAXN];
int valor[MAXN];

int bb(int fim, int valor){
    int ini = 1;
    int id = 0;
    while(ini <= fim){
        int meio = (ini + fim) / 2;
        if(progs[meio].first == valor){
            id = meio;
            fim = meio-1;
        }
        else if(progs[meio].first > valor)
            fim = meio-1;
        else ini = meio+1;
    }
    return id;
}


int main()
{
    int n, k;
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        cin >> progs[i].first;
        progs[i].second = i;
        valor[i] = progs[i].first;
    }
    sort(progs+1, progs+n+1);

    while(k--){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i = 1; i <= n; i++){
        int quarrel = 0;
        int fim = bb(i, progs[i].first)-1;
        for(int v: adj[progs[i].second]){
            if(bb(fim, valor[v]))
                quarrel++;
        }
        ans[progs[i].second] = fim - quarrel;
    }

    for(int i = 1; i <= n; i++){
        cout << ans[i];
        cout << (i == n? '\n':' ');
    }

    return 0;
}
