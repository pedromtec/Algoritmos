#include <bits/stdc++.h>
#define pb push_back
using namespace std;

const int INF = 1e9 + 10;
typedef long long ll;
typedef pair<int, int> pii;
//a = 0, x = 1, b = 1
int units(int x, int a, int b){
    return abs(x-a) + abs(a-b) + (b-x);
}

int main()
{
    int n;
    cin >> n;
    ll a[n+1];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    ll ans = -1;
    for(int x = 0; x < n; x++){
        ll gasto = 0;
        for(int i = 0; i < n; i++){
            gasto = gasto + (units(x, i, 0) + units(x, 0, i)) * a[i];
        }
        //cout << gasto << endl;
        if(ans == -1) ans = gasto;
        else ans = max(ans, gasto);
    }
    cout << ans << endl;
    return 0;
}
