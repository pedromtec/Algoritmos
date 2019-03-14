//https://br.spoj.com/problems/MOEDAS/
#include <bits/stdc++.h>
#define INF 1000000
using namespace std;

int main(){
    int m, n;
    while(cin >> m >> n and m){
        int moedas[n+1];
        int dp[m+1];
        for(int i = 0; i < n; i++)
            cin >> moedas[i];

        dp[0] = 0;
        for(int i = 1; i <= m; i++){
            dp[i] = INF;
            for(int j = 0; j < n; j++){
                if(i - moedas[j] >= 0)
                    dp[i] = min(dp[i], 1 + dp[i-moedas[j]]);
            }
        }

        if(dp[m] >= INF)
            cout << "Impossivel\n";
        else
            cout << dp[m] << endl;
    }
}
