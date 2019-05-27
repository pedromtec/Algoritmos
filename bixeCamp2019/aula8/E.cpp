#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
int main()
{
    int d, sumTime;
    cin >> d >> sumTime;
    pii days[d+1];
    for(int i = 1; i <= d; i++)
        cin >> days[i].first >> days[i].second;

    bool dp[d+1][sumTime+1];

    memset(dp, 0, sizeof dp);

    dp[0][0] = 1;
    for(int i = 1; i <= d; i++){
        for(int j = 0; j <= sumTime; j++){
            for(int t = days[i].first; t <= days[i].second; t++){
                if(t <= j){
                    dp[i][j] = dp[i][j] || dp[i-1][j-t];
                }
            }
        }
    }

    if(dp[d][sumTime]){
        vector<int> path;
        while(d){
            for(int t = days[d].first; t <= days[d].second; t++){
                if(t <= sumTime && dp[d-1][sumTime-t]){
                    path.push_back(t);
                    sumTime-=t;
                    break;
                }
            }
            --d;
        }
        reverse(path.begin(), path.end());
        cout << "YES" << endl;
        for(int i = 0, tam  = path.size(); i < tam; i++){
            cout << path[i];
            cout << (i+1 == tam? "\n":" ");
        }
    }
    else
        cout << "NO\n";

    return 0;
}
