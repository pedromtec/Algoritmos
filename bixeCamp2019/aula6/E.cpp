#include <bits/stdc++.h>
#define MAXN 510
using namespace std;

char maze[MAXN][MAXN];
int seen[MAXN][MAXN];


int n, m, k;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int empts_cells = 0;
int cont = 0;

bool fora(int i, int j){
    return i < 0 or i >= n or j < 0 or j >= m;
}

void dfs(int i, int j){


    if(empts_cells - cont == k) return;

    seen[i][j] = 1;
    ++cont;

    for(int w = 0; w < 4; w++){
        int di = i + dx[w];
        int dj = j + dy[w];
        if(fora(di, dj) or maze[di][dj] != '.' or seen[di][dj]) continue;
        dfs(di, dj);
    }

}
int main()
{

    cin >> n >> m >> k;
    int raiz_i, raiz_j;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> maze[i][j];
            if(maze[i][j] == '.')
            {
                empts_cells++;
                raiz_i = i;
                raiz_j = j;
            }
        }
    }
    dfs(raiz_i, raiz_j);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(maze[i][j] == '.' && !seen[i][j])
                maze[i][j] = 'X';
        }
        cout << maze[i] << endl;
    }

}
