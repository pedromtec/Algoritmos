#include <bits/stdc++.h>

using namespace std;

const int INF = 1e8+10;
int cortes[3];
int memo[4010];

int solve(int n){
    if(memo[n] != -1)
        return memo[n];

    int ans = -INF;
    for(int i = 0; i < 3; i++){
        if(n >= cortes[i])
            ans = max(ans, 1 + solve(n-cortes[i]));
    }
    return memo[n] = ans;
}

int main()
{
    int n;
    cin >> n >> cortes[0] >> cortes[1] >> cortes[2];
    memset(memo, -1, sizeof memo);
    memo[0] = 0;
    cout << solve(n) << endl;
    return 0;
}
