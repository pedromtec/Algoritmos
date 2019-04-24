#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll MOD  = 1000000007;

ll pot(ll base, ll exp){
    if(exp == 0) return 1;

    ll ans = pot(base, exp / 2);

    ans = (ans * ans) % MOD;

    if(exp % 2 != 0) ans = ans * base;

    return ans % MOD;
}

int main()
{
    int t;
    scanf("%d", &t);

    while(t--){
        ll a, x, y, k;

        scanf("%lld %lld %lld %lld", &a, &x, &y, &k);
        ll exp = (ll)2*k - 1;
        x%=MOD;
        y%=MOD;
        x = (x * y) % MOD;

        printf("%lld\n", (pot(a%MOD, exp) * x) % MOD );
    }
    return 0;
}
