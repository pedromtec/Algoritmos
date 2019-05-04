#include <bits/stdc++.h>
#define MAXN 100010
using namespace std;

set<int> adj[MAXN];

int main()
{
    int n, m;
    cin >> n >> m;
    while(m--){
        int a, b, t;
        cin >> t >> a >> b;
        if(t == 0)
            cout << adj[a].count(b) << endl;
        else{
            adj[a].insert(b);
            adj[b].insert(a);
        }
    }

    return 0;
}
