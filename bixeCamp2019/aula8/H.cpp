#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    int n;
    while(cin >> n and n){

        ll ans = 0;
        for(int i = 1; i <= n; i++){
            ll formas = (n-i+1) * (n-i+1);
            ans += formas;
        }
        cout << ans << endl;
    }

    return 0;
}
