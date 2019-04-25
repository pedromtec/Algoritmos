#include <bits/stdc++.h>

using namespace std;

const int MAXN = 200010;

struct seg{
    int x1, x2, len;
};
int n, h;

seg segs[MAXN];
int prefix_sum[MAXN];

int bb(int i){
    int ini = i+1, fim = n;
    int ans = i;
    int new_h = h;

    while(ini <= fim){
        int meio = (ini+fim) / 2;
        int distancia = prefix_sum[meio] - prefix_sum[i];
        if(distancia <= h){
            new_h = h - distancia;
            ans = meio;
            ini = meio+1;
        }else{
            fim = meio-1;
        }
    }
    if(new_h == 0)
        return segs[ans].x1;

    return segs[ans].x2 + new_h;
}
int main()
{
    cin >> n >> h;
    cin >> segs[1].x1 >> segs[1].x2;
    for(int i = 2; i <= n; ++i){
        cin >> segs[i].x1 >> segs[i].x2;
        prefix_sum[i] = prefix_sum[i-1] + (segs[i].x1 - segs[i-1].x2);
    }
    int ans = 0;
    for(int i = 1; i <= n; i++){
        ans = max(ans, bb(i) - segs[i].x1);
    }
    cout << ans << endl;
    return 0;
}
