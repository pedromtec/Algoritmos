#include <bits/stdc++.h>
#define MAXN 200010
using namespace std;

typedef long long ll;
ll n, m, dormitorios[MAXN], prefix_sum[MAXN];
int main()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> dormitorios[i];
        prefix_sum[i] = prefix_sum[i-1] + dormitorios[i];
    }
    ll dormitorio_atual = 1;
    for(int i = 1; i <= m; i++){
        ll b;
        cin >> b;
        b-=prefix_sum[dormitorio_atual-1];
        while(dormitorio_atual <= n && b > dormitorios[dormitorio_atual]){
            b-=dormitorios[dormitorio_atual];
            dormitorio_atual++;
        }
        cout << dormitorio_atual << " " << b << endl;
    }
    return 0;
}
