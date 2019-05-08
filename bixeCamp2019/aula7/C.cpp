#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;

const int MAXN = 110;
int n;
int grid[MAXN][MAXN];

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int dist[MAXN][MAXN];


bool fora(int i, int j){
    return i < 0 || i >= n || j < 0 || j >= n;
}

int bfs(pair<int, int> u, pair<int, int> d){
    deque<pair<int, int> > dq;
    dist[u.f][u.s] = 0;
    dq.push_back(u);
    
    while(!dq.empty()){

        u = dq.front();
        dq.pop_front();
        if(u == d) break;

        for(int k = 0; k < 4; k++){
            pair<int, int> v;
            v.f = u.f + dx[k];
            v.s = u.s + dy[k];

            if(fora(v.f, v.s) || dist[v.f][v.s] != -1) continue;

            int custo = grid[v.f][v.s];
            dist[v.f][v.s] = dist[u.f][u.s] + custo;

            if(custo)
                dq.push_back(v);
            else dq.push_front(v);
        }
    }
    return dist[d.f][d.s];
}


int main()
{
    cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> grid[i][j];

    memset(dist, -1, sizeof dist);
    pair<int, int> u, v;
    u.f = 0; u.s = 0;
    v.f = n-1, v.s = n-1;
    cout << bfs(u, v) << endl;
}
