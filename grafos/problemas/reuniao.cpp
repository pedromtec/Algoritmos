//https://olimpiada.ic.unicamp.br/pratique/p2/2010/f1/reuniao/

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e2 + 10;
const int INF = 1e9 + 10;
typedef pair<int, int> pii;

vector<pii> adj[MAXN];
bool seen[MAXN];
int dist[MAXN], n;

int dijkstra(int S){
    for(int i = 0; i <= n; i++)
        dist[i] = INF;

    priority_queue<pii> pq;

    dist[S] = 0;
    pq.push({0, S});
    int max_dist = 0;
    while(!pq.empty()){
        int u = pq.top().second;
        pq.pop();
        if(seen[u]) continue;

        seen[u] = true;
        max_dist = max(max_dist, dist[u]);

        for(auto V: adj[u]){
            int v = V.first;
            int w = V.second;
            if(dist[v] > dist[u] + w){
                dist[v] = dist[u] + w;
                pq.push({-dist[v], v});
            }
        }

    }
    return max_dist;

}
int main()
{
    int m;
    cin >> n >> m;
    while(m--){
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    int ans = INF;
    for(int i = 0; i < n; i++){
        memset(seen,false, sizeof seen);
        ans = min(ans, dijkstra(i));
    }

    cout << ans << endl;
    return 0;
}
