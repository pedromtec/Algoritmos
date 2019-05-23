#include <bits/stdc++.h>
#define pb push_back
using namespace std;

const int MAXN = 1e5 + 10;
const int INF = 1e9 + 10;
typedef long long ll;
typedef pair<int, int> pii;


int main()
{
    vector<int> lanches[MAXN];
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        int k;
        scanf("%d", &k);
        for(int j = 0; j < k; j++){
            int t;
            scanf("%d", &t);
            lanches[i].pb(t);
        }
    }

    for(int i = 0; i < n; i++){
        int d;
        scanf("%d", &d);
        for(int j = 0; j < lanches[d].size(); j++){
            printf("%d", lanches[d][j]);
            if(j == lanches[d].size()-1)
                cout << "\n";
            else cout << " ";
        }
    }
    return 0;
}
