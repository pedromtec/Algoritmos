#include <bits/stdc++.h>
#define MAXN 100010
using namespace std;

typedef long long ll;

struct Op{
    int l, r, d;
};

ll dt_ops[MAXN];
ll a[MAXN];
ll dt_ans[MAXN];
Op ops[MAXN];

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    for(int i = 1; i <= m; i++)
        cin >> ops[i].l >> ops[i].r >> ops[i].d;

    while(k--){
        int x, y;
        cin >> x >> y;
        dt_ops[x]++;
        dt_ops[y+1]--;
    }

    ll f = 0;
    for(int i = 1; i <= m; i++){
        f += dt_ops[i];

        dt_ans[ops[i].l] += f*ops[i].d;
        dt_ans[ops[i].r+1] -= f*ops[i].d;
    }
    ll s = 0;
    for(int i = 1; i <= n; i++){
        s += dt_ans[i];

        cout << a[i] + s;

        cout << (i == n ? '\n' : ' ');
    }


    return 0;
}
