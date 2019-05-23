#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const long long INF = 100000000000000000;


bool comp(string &a, string &b){
    return a <= b;
}

int main()
{
    int n;
    cin >> n;
    ll custo[n+1];
    ll dp[n+1][2];
    memset(dp, -1, sizeof dp);
    for(int i = 0; i < n; i++)
        cin >> custo[i];

    dp[0][0] = 0;
    dp[0][1] = custo[0];

    string ant;
    cin >> ant;
    for(int i = 1; i < n; i++){
        string atual;
        cin >> atual;
        dp[i][0] = dp[i][1] = INF;

        string rant = ant;
        string ratual = atual;
        reverse(ratual.begin(), ratual.end());
        reverse(rant.begin(), rant.end());

        //dp[i][0]

        if(comp(ant, atual))
            dp[i][0] = min(dp[i][0], dp[i-1][0]);
        if(comp(rant, atual))
            dp[i][0] = min(dp[i][0], dp[i-1][1]);

        //dp[i][1]

        if(comp(ant, ratual))
            dp[i][1] = min(dp[i][1], custo[i] + dp[i-1][0]);
        if(comp(rant, ratual))
            dp[i][1] = min(dp[i][1], custo[i] + dp[i-1][1]);

        ant = atual;
    }
    ll ans = min(dp[n-1][0], dp[n-1][1]);
    cout << (ans >= INF ? -1 : ans) << endl;
}
