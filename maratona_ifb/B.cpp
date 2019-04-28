#include <bits/stdc++.h>

using namespace std;


int main()
{
    int n;
    cin >> n;
    int l[n+1];
    for(int i = 0; i < n; i++){
        cin >> l[i];
    }
    pair<int, bool> dp[n+1];
    dp[n-1] = {0, true};
    for(int i = n-2; i >= 0; i--){

        if(l[i] < l[i+1]){
            dp[i].second = true;
            dp[i].first = (dp[i+1].second ? dp[i+1].first : 0) + 1;
        }
        else if(l[i] > l[i+1]){
            dp[i].second = false;
            dp[i].first = (!dp[i+1].second ? dp[i+1].first : 0) + 1;
        }else dp[i].first = 0;
    }

    int q;
    cin >> q;

    while(q--){
        int a, b;
        scanf("%d %d", &a, &b);
        string ans = (dp[a].second ? "crescente":"decrescente" );
        if(a + dp[a].first >= b)
            cout << ans << endl;
        else cout << "nenhum\n";

    }

    return 0;
}
