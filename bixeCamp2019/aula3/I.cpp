#include <bits/stdc++.h>
#define MAXN 100010
using namespace std;

int v[MAXN], n, k;

int bb(int fim, int x){
    int ini = 0;
    while(ini <= fim){
        int meio = (ini+fim)/2;
        if(v[meio] == x)
            return meio;
        else if(v[meio] > x)
            fim = meio-1;
        else
            ini = meio+1;
    }
    return -1;
}

int main()
{
    int grupo[MAXN], grupo_atual = 0;
    map<int, int> cnt;
    cin >> n >> k;
    for(int i = 0; i < n; i++)
        cin >> v[i];

    sort(v, v+n);
    for(int i = 0; i < n; i++){
        if(v[i] % k == 0){
            int x = v[i] / k;
            int id = bb(i-1, x);
            if(id != -1){
                grupo[i] = grupo[id];
            }else
                grupo[i] = ++grupo_atual;
        }else{
            grupo[i] = ++grupo_atual;
        }
        cnt[grupo[i]]++;
    }

    int ans = 0;
    for(pair<int, int> pp: cnt){
        ans += (pp.second / 2 + pp.second % 2);
    }

    cout << ans << endl;

    return 0;
}
