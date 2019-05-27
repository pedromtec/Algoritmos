#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll MOD = 1e9 + 7;

int d, k;
int memo[110][2];

ll pd(int n, int passou){
    if(n < 0) return 0;

    if(memo[n][passou] != -1) return memo[n][passou];

    ll cnt = 0;

    for(int i = 1; i <= k; i++){
        if(i >= d) cnt += pd(n-i, 1);
        else cnt += pd(n-i, passou);
        cnt %= MOD;
    }

    return memo[n][passou] = cnt;
}

int main()
{
    int n;
    cin >> n >> k >> d;
    memset(memo, -1, sizeof memo);
    memo[0][1] = 1;
    memo[0][0] = 0;
    cout << pd(n, 0) << endl;
    return 0;
}
