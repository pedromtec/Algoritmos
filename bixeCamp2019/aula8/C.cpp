#include <bits/stdc++.h>
#define f first
#define s second
#define pb push_back
#define lsb(x) ((x) & (-x))

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main()
{
    int n, s;
    cin >> s >> n;
    int w[n+1], v[n+1], dp[2][s+1];
    for(int i = 1; i <= n; i++)
        cin >> w[i] >> v[i];

    for(int j = 0; j <= s; j++)
        dp[0][j] = 0;
    dp[1][0] = 0;
    for(int i = 1; i <= n; i++){
        int obj = i % 2;
        for(int j = 1; j <= s; j++){
            dp[obj][j] = dp[!obj][j];
            if(w[i] <= j)
                dp[obj][j] = max(dp[obj][j], v[i] + dp[!obj][j-w[i]]);
        }
    }
    cout << dp[n%2][s] << endl;
    return 0;
}
