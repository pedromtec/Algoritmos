#include <bits/stdc++.h>
#define MAXN 200010
#define MAXV 1000200100
using namespace std;


typedef long long ll;

ll w;
int n, m;
ll dt[MAXN];
ll heights[MAXN];


bool can(ll guess){
    memset(dt, 0, sizeof dt);
    ll sum = 0;
    ll days = 0;
    for(int i = 0; i < n; i++){
        ll h = heights[i] + sum + dt[i];
        ll dif = guess - h;
        if(dif > 0){
            days += dif;
            dt[i]+=dif;
            dt[i+w]-=dif;
        }

        sum += dt[i];
    }
    return m >= days;
}

int main(){

    cin >> n >> m >> w;

    for(int i = 0; i < n; i++){
        cin >> heights[i];
    }

    int ans = 0;
    int ini = 1, fim = MAXV;
    while(ini <= fim){
        int meio = (ini+fim) / 2;
        if(can(meio)){
            ans = meio;
            ini = meio+1;
        }else fim = meio-1;
    }

    cout << ans << endl;

    return 0;
}
