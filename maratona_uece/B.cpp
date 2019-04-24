#include <bits/stdc++.h>
#define MAX 1010

using namespace std;

int dist[MAX][MAX];
char grid[MAX][MAX];

int di[] = {1, -1, 0, 0};
int dj[] = {0, 0, 1, -1};

int n, m;

bool fora(int i, int j){
    return i < 0 or i >= n or j < 0 or j >= m;
}


int dijkstra(pair<int, int> ori, pair<int, int> dest) {

    memset(dist, 0x3f, sizeof dist);
    dist[ori.first][ori.second] = 0;
    priority_queue< pair<int, pair<int, int> > > pq;
    pq.push({0, ori});
    while(!pq.empty()) {

        auto p = pq.top(); pq.pop();
        int d = -p.first;
        pair<int, int> u = p.second;

        if(u.first == dest.first and u.second == dest.second)
            return d;
        if(d > dist[u.first][u.second]) continue;

        for(int k = 0; k < 4; k++){
            pair<int, int> v;
            v.first = u.first + di[k];
            v.second = u.second + dj[k];
            if(fora(v.first, v.second) or grid[v.first][v.second] == '#') continue;
            int custo = 0;
            if(grid[v.first][v.second] == '2')
                custo = 1;
            if(d + custo < dist[v.first][v.second]){
                dist[v.first][v.second] = d + custo;
                pq.push({-dist[v.first][v.second], v});
            }
        }
    }
    return -1;
}


int main(){



    cin >> n >> m;

    pair<int, int> origem, dest;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> grid[i][j];
            if(grid[i][j] == 'I')
                origem.first = i, origem.second = j;
            if(grid[i][j] == 'F')
                dest.first = i, dest.second = j;
        }
    }
    //printf("%d %d\n%d %d\n", origem.first, origem.second, dest.first, dest.second);
    int ans = dijkstra(origem, dest);
    cout << ans << endl;

    return 0;
}
