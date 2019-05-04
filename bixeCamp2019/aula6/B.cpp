#include <bits/stdc++.h>
#define MAX 1010
using namespace std;

int di[] = {1, -1, 0, 0};
int dj[] = {0, 0, 1, -1};
int n, m;
int grid[MAX][MAX];
int cnt[MAX][MAX];

bool fora(int i, int j){
    return i < 0 || i >= n || j < 0 || j >= m;
}

void dfs(int i, int j){

    for(int k = 0; k < 4; k++){
        int i_i = i + di[k];
        int j_j = j + dj[k];
        if(fora(i_i, j_j) || !grid[i_i][j_j] || cnt[i_i][j_j])
            continue;

        cnt[i_i][j_j] = cnt[i][j] + 1;
        dfs(i_i, j_j);
    }

}



int main()
{
    cin >> n >> m;
    int ini_i, ini_j, fim_i, fim_j;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++){
            cin >> grid[i][j];
            if(grid[i][j] == 2)
                ini_i = i, ini_j = j;
            else if(grid[i][j] == 3)
                fim_i = i, fim_j = j;
        }
    }

    memset(cnt, 0, sizeof cnt);
    cnt[ini_i][ini_j] = 1;
    dfs(ini_i, ini_j);

    cout << cnt[fim_i][fim_j] << endl;
    return 0;
}
