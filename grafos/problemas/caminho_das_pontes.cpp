#include <bits/stdc++.h>
#define pb push_back
using namespace std;

const int MAXN = 1e3 + 10;
const int INF = 1e9 + 10;

typedef pair<int, int> pii;

int dist[MAXN];
bool vis[MAXN];

vector<pii> adj[MAXN];

int n;

int dijkstra(int S){
    for(int i = 0; i <= n+1; i++){
        vis[i] = 0;
        dist[i] = INF;
    }
    priority_queue<pii> pq;
    dist[S] = 0;
    pq.push({-dist[S], S});
    while(!pq.empty()){
        int u = pq.top().second;
        pq.pop();
        if(vis[u]) continue;
        vis[u] = 1;
        for(pii V: adj[u]){
            int v = V.first;
            int w = V.second;
            if(dist[u] + w < dist[v]){
                dist[v] = dist[u] + w;
                pq.push({-dist[v], v});
            }
        }
    }
    return dist[n+1];
}

int main()
{
    int m;
    cin >> n >> m;
    while(m--){
        int s, t, b;
        cin >> s >> t >> b;
        adj[s].pb({t, b});
        adj[t].pb({s, b});
    }
    cout << dijkstra(0) << endl;
}
