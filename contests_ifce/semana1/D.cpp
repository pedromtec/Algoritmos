#include <bits/stdc++.h>
#define MAXN 100010
#define INF 10000010
using namespace std;
typedef long long ll;
ll arr[MAXN], n;

ll solve(ll ant, int i, ll dif){
    if(i == n) return 0;

    ll op1 = arr[i];
    ll op2 = arr[i]+1;
    ll op3 = arr[i]-1;

    if(op1-ant == dif)
        return solve(op1, i+1, dif);
    if(op2-ant == dif)
        return 1 + solve(op2, i+1, dif);
    if(op3-ant == dif)
        return 1 + solve(op3, i+1, dif);
    return INF;
}

int main()
{

    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> arr[i];

    if(n == 1){
        cout << 0 << endl;
    }else{
        ll ans = INF;
        for(int i = -1; i <= 1; i++){
            for(int j = -1; j <= 1; j++){
                ll a1 = arr[0] + i;
                ll a2 = arr[1] + j;
                ll custo = abs(i) + abs(j);
                ans = min(ans, custo  + solve(a2, 2, a2-a1));
            }
        }
        cout << ( ans < INF ? ans : -1 ) << endl;
    }

    return 0;
}
