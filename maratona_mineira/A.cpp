#include <bits/stdc++.h>
#define lsb(x) ((x) & (-x))

using namespace std;

typedef  pair<int, int> pii;
typedef long long ll;
const int MAXN  = 2000010;

vector<ll> xs[MAXN], ys[MAXN];

ll sum(ll k){
    return (k * (k-1))/2;
}
int main()
{
    ll n, q;
    cin >> n >> q;
    ll ans = (n*n) - q;


    while(q--){
        ll x, y;
        cin >> x >> y;
        ys[y].push_back(x);
        xs[x].push_back(y);
    }

    for(int i = 1; i <= n; i++){
        sort(xs[i].begin(), xs[i].end());
        sort(ys[i].begin(), ys[i].end());
    }
    for(int i = 1; i <= n; i++){

        if(xs[i].size() == 0) {
            ans += sum(n);
            continue;
        }

        ans += sum(xs[i][0]-1);

        for(int j = 1; j < xs[i].size(); j++){
            ans += sum(xs[i][j]-xs[i][j-1]-1);

        }
        ans += sum(n - xs[i][xs[i].size()-1]);

    }


    for(int i = 1; i <= n; i++){

        if(ys[i].size() == 0) {
            ans += sum(n);
            continue;
        }

        ans += sum(ys[i][0]-1);
        for(int j = 1; j < ys[i].size(); j++){
            ans += sum(ys[i][j]-ys[i][j-1]-1);
        }
        ans += sum(n - ys[i][ys[i].size()-1]);
    }

    cout << ans << endl;
    return 0;
}
