#include <bits/stdc++.h>
#define MAXN 10001
using namespace std;

int dp[MAXN][MAXN];
int V[MAXN], W[MAXN];
int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++)
        scanf("%d", &V[i]);
    for(int i = 1; i <= n; i++)
        scanf("%d", &W[i]);

    for(int i = 0; i <= n; i++)
        dp[i][0] = 0;
    for(int i = 0; i <= m; i++)
        dp[0][i] = 0;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            dp[i][j] = dp[i-1][j];
            if(W[i] <= j)
                dp[i][j] = max(dp[i][j], V[i] + dp[i-1][j-W[i]]);
        }
    }

    printf("%d\n", dp[n][m]);

    return 0;
}
