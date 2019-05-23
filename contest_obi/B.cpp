#include <bits/stdc++.h>
#define pb push_back
using namespace std;

const int INF = 1e9 + 10;
typedef long long ll;
typedef pair<int, int> pii;


int main()
{
    int n, m;
    cin >> n >> m;
    int d;

    d = n/(m+1);

    if(n % (m+1) > d)
        d++;

    if(n <= m) d = 1;

    int uns = 0;
    vector<string> ans;
    for(int i = 0; i < n; ){
        if(uns == d and m){
            uns = 0;
            ans.pb("0");
            m--;
        }else{
            i++;
            ans.pb("1");
            uns++;
        }
    }

    for(int i = 0; i < m; i++)
        ans.pb("0");

    for(int i = 0; i <  ans.size(); i++){
        if(i == ans.size()-1)
            cout << ans[i] << "\n";
        else cout << ans[i] << " ";
    }


    return 0;
}
