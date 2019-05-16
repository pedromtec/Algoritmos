#include <bits/stdc++.h>
#define MAXN 10010
#define INF 200000010
using namespace std;

vector<pair<int, int> > adj[MAXN];
int seen[MAXN], dist[MAXN];

int dijkstra(int ori, int dest){

    priority_queue<pair<int, int> > pq;
    pq.push({0, ori});
    dist[ori] = 0;
    
    while(!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();
        if(seen[u]) continue;
        seen[u] = 1;
        if(u == dest) break;
        for(auto par: adj[u]){
            int v = par.first;
            int d = par.second;
            if(dist[u] + d < dist[v]){
                dist[v] = dist[u] + d;
                pq.push({-dist[v], v});
            }
        }
    }

    return dist[dest];
}

int main()
{
    int t;
    scanf("%d", &t);
    while(t--){

        int n, m;
        scanf("%d %d", &n, &m);

        for(int i = 1; i <= n; i++){
            adj[i].clear();
            seen[i] = 0;
            dist[i] = INF;
        }

        while(m--){
            int u, v, d;
            scanf("%d %d %d", &u, &v, &d);
            adj[u].push_back({v, d});
        }

        int ori, dest;
        scanf("%d %d", &ori, &dest);
        int ans = dijkstra(ori, dest);
        if(ans >= INF) printf("NO\n");
        else printf("%d\n", ans);

    }
    return 0;
}
