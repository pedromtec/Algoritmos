//https://br.spoj.com/problems/TROCO13/
#include <bits/stdc++.h>
#define MAXM 1010
#define MAXV 100010
using namespace std;

int dp[MAXM][MAXV];
int moedas[MAXM];

/*
    f(n, v) = 1, se v == 0
    f(n, v) = 0, se n == 0
    f(n, v) = f(n-1, v-moedas[n]) se v >= moedas[n] or f(n-1, v)
*/

int main(){
    int v, m;
    cin >> v >> m;
    for(int i = 1; i <= m; i++)
        cin >> moedas[i];
    for(int i = 0; i <= v; i++)
        dp[0][i] = 0;
    dp[0][0] = 1;

    for(int i = 1; i <= m; i++){
        dp[i][0] = 1;
        for(int j = 1; j <= v; j++){
            if(j >= moedas[i])
                dp[i][j] = dp[i-1][j-moedas[i]];
            dp[i][j] = dp[i][j] or dp[i-1][j];
        }
    }
    cout << (dp[m][v] ? 'S' : 'N') << endl;
    return 0;
}
