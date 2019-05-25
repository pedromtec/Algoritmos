#include <bits/stdc++.h>
#define f first
#define s second
#define pb push_back
#define lsb(x) ((x) & (-x))

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const int MAXN = 2000010;

int BIT[MAXN], n;

int sum(int x){
    int ret = 0;
    for(; x > 0; x -= lsb(x))
        ret += BIT[x];
    return ret;
}

void update(int x, int v){
    for(; x <= n; x += lsb(x))
        BIT[x] += v;
}

int query(int x, int y){
    return sum(y) - sum(x-1);
}


int main()
{
    int caso = 0;
    while(cin >> n and n){
        memset(BIT, 0, sizeof BIT);
        if(caso) puts("");
        for(int i = 1; i <= n; i++){
            int v;
            scanf("%d", &v);
            update(i, v);
        }
        printf("Case %d:\n", ++caso);
        string op;
        while(true){
            cin >> op;
            if(op == "END") break;

            int x, y;
            scanf("%d %d",&x, &y);
            if(op == "M")
                printf("%d\n", query(x, y));
            else{
                update(x, -query(x, x));
                update(x, y);
            }
        }
    }

    return 0;
}
