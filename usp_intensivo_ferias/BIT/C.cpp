#include <bits/stdc++.h>
#define f first
#define s second
#define pb push_back
#define lsb(x) ((x) & (-x))

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const int MAXN = 1e5 + 10;

int n, cont;
int BIT[MAXN];

int sum(int x){
    int ret = 0;
    for(; x > 0; x -= lsb(x))
        ret += BIT[x];
    return ret;
}

void update(int x, int v){
    for(; x <= cont; x += lsb(x))
        BIT[x] += v;
}

int query(int x, int y){
    if(x > cont || y > cont) return 0;
    return sum(y) - sum(x-1);
}

int main()
{
    cin >> n;
    int h[n+1];
    vector<int> aux;
    map<int, int> comp;
    for(int i = 1; i <= n; i++){
        cin >> h[i];
        aux.push_back(h[i]);
    }

    sort(aux.begin(), aux.end());
    for(int i = 0; i < n; i++){
        if(!comp.count(aux[i]))
            comp[aux[i]] = ++cont;
    }
    for(int i = 1; i <= n; i++){
        h[i] = comp[h[i]];
    }

    bool coberto[n+1];
    memset(coberto, true, sizeof coberto);
    for(int i = n; i >= 1; i--){
        coberto[i] = coberto[i] && query(h[i]+1, cont);
        update(h[i], 1);
    }
    memset(BIT, 0, sizeof BIT);
    for(int i = 1; i <= n; i++){

        coberto[i] = coberto[i] && query(h[i]+1, cont);
        update(h[i], 1);
    }
    int cnt = 0;
    for(int i = 1; i <= n; i++){
        if(coberto[i]) cnt++;
    }

    cout << cnt << endl;

    return 0;
}
