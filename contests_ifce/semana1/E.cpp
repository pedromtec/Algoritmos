#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main()
{
    ll n, m;
    cin >> n >> m;
    ll ai;
    cin >> ai;
    ll soma = ai, max_soma = ai, min_soma = ai;
    for(int i = 1; i < n; i++){
        cin >> ai;
        soma+=ai;
        max_soma = max(max_soma, soma);
        min_soma = min(min_soma, soma);
    }
    ll ans = m+1;
    if(max_soma > 0)
        ans = m - max_soma + 1;
    if(min_soma < 0)
        ans += min_soma;
    ans = max(ans, 0ll);
    cout << ans << endl;
    return 0;
}
