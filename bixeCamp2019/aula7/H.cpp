#include <bits/stdc++.h>

using namespace std;

const int MAXN = 510;
const int INF = 1e9 + 10;

int n, m, s, d;

int dist[MAXN];
int seen[MAXN];

vector<int> pai[MAXN];
int grafo[MAXN][MAXN];

int dijkstra(int S){

    for(int i = 0; i <= n; i++)
        dist[i] = INF;

    priority_queue<pair<int, int> > pq;
    dist[S] = 0;
    pq.push({-dist[S], S});

    while(!pq.empty()){
        int u = pq.top().second;
        pq.pop();
        if(seen[u]) continue;
        seen[u] = 1;
        for(int v = 0; v < n; v++){
            int w = grafo[u][v];
            if(w >= INF) continue;
            if(dist[u] + w < dist[v]){
                dist[v] = dist[u] + w;
                pai[v].clear();
                pai[v].push_back(u);
                pq.push({-dist[v], v});
            }
            else if(dist[u]+w == dist[v]){
                pai[v].push_back(u);
            }
        }
    }
    return dist[d];
}

void exclui_path(int v){

    for(auto u: pai[v]){
        if(u == -1) break;
        grafo[u][v] = INF;
        exclui_path(u);
    }
}


int main()
{
    while(cin >> n >> m and n+m){
        cin >> s >> d;

        memset(seen, 0, sizeof seen);
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                grafo[i][j] = INF;
        while(m--){
            int a, b, w;
            cin >> a >> b >> w;
            grafo[a][b] = w;
        }
        for(int i = 0; i < n; i++)
            pai[i].clear();
        pai[s].push_back(-1);
        int min_path = dijkstra(s);
        exclui_path(d);
        memset(seen, 0, sizeof seen);
        int ans = dijkstra(s);

        ans = (ans >= INF ? -1: ans);
        cout << ans << endl;

    }

    return 0;
}
