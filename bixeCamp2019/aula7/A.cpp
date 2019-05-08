#include <bits/stdc++.h>
#define MAXN 51
using namespace std;

char grid[MAXN][MAXN];
int h, w;
int dx[] = {1, -1, 0, 0, 1, 1, -1, -1};
int dy[] = {0, 0, 1, -1, -1, 1, 1, -1};
int dist[MAXN][MAXN];

bool fora(int i, int j){
    return i < 0 || i >= h || j < 0 || j >= w;
}

int bfs(int i, int j){
    queue<pair<int, int> > q;
    memset(dist, -1, sizeof dist);
    int ans = 0;
    dist[i][j] = 1;
    q.push({i, j});
    while(!q.empty()){
        auto no = q.front();
        q.pop();
        i = no.first;
        j = no.second;
        ans = max(ans, dist[i][j]);
        for(int k = 0; k < 8; k++){
            int di = i + dx[k];
            int dj = j + dy[k];
            if(fora(di, dj) || dist[di][dj] != -1)
                continue;
            if(grid[i][j] + 1 != grid[di][dj])
                continue;
            dist[di][dj] = dist[i][j] + 1;
            q.push({di, dj});
        }
    }

    return ans;
}

int main()
{
    int caso = 0;
    while (cin >> h >> w && h + w) {
        for(int i = 0; i < h; i++)
            cin >> grid[i];
        int ans  = 0;
        for(int i = 0; i < h; i++){
            for(int j = 0; j < w; j++){
                if(grid[i][j] == 'A'){
                    ans = max(ans, bfs(i, j));
                }
            }
        }

        printf("Case %d: %d\n", ++caso, ans);
    }
    return 0;
}
