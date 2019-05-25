#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long llu;

int main()
{
    llu dp[61];
    dp[0] = 0; dp[1] = 1;
    for(int i = 2; i <= 60; i++)
        dp[i] = dp[i-1] + dp[i-2];
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        cout << "Fib(" << n << ") = " << dp[n] << endl;
    }
    return 0;
}
