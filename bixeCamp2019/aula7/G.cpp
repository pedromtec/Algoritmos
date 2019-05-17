#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;

const int MAXN = 1e5 + 10;
const ll INF = 1e12 + 10;

int n, m;

ll dist[MAXN];
int seen[MAXN], pai[MAXN];
vector<pii> adj[MAXN];

ll dijkstra(int S){

    for(int i = 0; i <= n; i++)
        dist[i] = INF;

    priority_queue<pair<ll, int> > pq;
    dist[S] = 0;
    pq.push({-dist[S], S});

    while(!pq.empty()){
        int u = pq.top().second;
        pq.pop();
        if(seen[u]) continue;
        seen[u] = 1;
        for(auto V: adj[u]){
            int v = V.first;
            int w = V.second;
            if(dist[u] + w < dist[v]){
                dist[v] = dist[u] + w;
                pai[v] = u;
                pq.push({-dist[v], v});
            }
        }
    }
    return dist[n];
}

void path(int v){
    stack<int> st;
    while(v != -1){
        st.push(v);
        v = pai[v];
    }
    cout << st.top(); st.pop();
    while(!st.empty()){
        cout << " " << st.top();
        st.pop();
    }
    cout << endl;
}
int main()
{
    cin >> n >> m;
    while(m--){
        int a, b, w;
        cin >> a >> b >> w;
        adj[a].push_back({b, w});
        adj[b].push_back({a, w});
    }

    pai[1] = -1;
    ll ans = dijkstra(1);
    if(ans >= INF)
        cout << "-1\n";
    else
        path(n);

    return 0;
}
