#include <bits/stdc++.h>
#define f first
#define s second
#define pb push_back
#define lsb(x) ((x) & (-x))

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int MAXN = 1e5 + 10;

int n;
int a[MAXN], BIT[MAXN];

int sum(int i){
    int s = 0;
    for(; i > 0; i -= lsb(i))
        s += BIT[i];
    return s;
}

void update(int i, int v){
    for(; i <= n; i += lsb(i))
        BIT[i] += v;
}

int main()
{
    while(cin >> n and n){
        memset(BIT, 0, sizeof BIT);
        for(int i = 1; i <= n; i++)
            cin >> a[i];

        int cnt = 0;
        for(int i = n; i >= 1; i--)
        {
            cnt += sum(a[i]-1);
            update(a[i], 1);
        }

        cout << (cnt % 2 == 0 ? "Carlos": "Marcelo") << endl;
    }
    return 0;
}
