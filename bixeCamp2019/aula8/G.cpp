#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int MOD = 1e9 + 7;
int dp[10000001][4];
int main()
{
    int n;
    cin >> n;

    memset(dp, 0, sizeof dp);

    dp[0][0] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < 4; j++){
            for(int k = 0; k < 4; k++){
                if(k != j)
                    dp[i][j] = (dp[i][j] + dp[i-1][k]) % MOD;
            }
        }
    }

    cout << dp[n][0] << endl;

    return 0;
}
