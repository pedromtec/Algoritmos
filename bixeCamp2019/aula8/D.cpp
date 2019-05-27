#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
const int INF = 1e8 + 10;
int main()
{
    int c;
    cin >> c;
    while(c--){
        int n, k;
        cin >> n >> k;
        int packets[k+1];

        for(int i = 1; i <= k; i++)
            cin >> packets[i];

        int dp[k+1][k+1];

        for(int i = 0; i <= k; i++)
            dp[i][0] = 0;
        for(int i = 1; i <= k; i++)
            dp[0][i] = INF;

        for(int i = 1; i <= k; i++){
            for(int j = 1; j <= k; j++){
                dp[i][j] = dp[i-1][j];
                if(j >= i && packets[i] != -1)
                    dp[i][j] = min(dp[i][j-i] + packets[i], dp[i][j]);
            }
        }
        cout << ( dp[k][k] >= INF ? -1 : dp[k][k]) << endl;
    }



    return 0;
}
