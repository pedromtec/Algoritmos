#include <bits/stdc++.h>
#define MAXN 100010
using namespace std;

int prefix_sum[MAXN];

int bb(int d, int ini, int fim, int t){
    int ans = -1;
    while(ini <= fim){
        int meio = (ini + fim) / 2;
        int valor = prefix_sum[meio] - prefix_sum[d];
        if(t < valor)
            fim = meio-1;
        else{
            ans = meio;
            ini = meio+1;
        }
    }
    return ans;
}

int main()
{
    int n, t;
    cin >> n >> t;
    for(int i = 1; i <= n; i++){
        int ti;
        cin >> ti;
        prefix_sum[i] = prefix_sum[i-1] + ti;
    }
    int ans = 0;
    for(int i = 1; i <= n; i++){
        int r = bb(i-1, i, n, t);
        if(r == -1) continue;
        ans = max(ans, r - i + 1);
    }
    cout << ans << endl;

    return 0;
}
