#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        k+=2;
        int h[n+1];
        for(int i = 0; i < n; i++)
            cin >> h[i];
        map<int, int> maxs, mins;
        int l = 0, r = 0, ans = 0;
        while(r < n and r < k){
            mins[h[r]]++;
            maxs[-h[r]]++;
            r++;
        }

        r--;
        while(1){
            int h1 = mins.begin()->first;
            int h2 = -maxs.begin()->first;
            ans = max(ans, h2-h1);
            if(r+1 == n) break;

            mins[h[l]]--;
            if(!mins[h[l]]) mins.erase(h[l]);
            maxs[-h[l]]--;
            if(!maxs[-h[l]]) maxs.erase(-h[l]);

            l++;
            r++;
            mins[h[r]]++;
            maxs[-h[r]]++;
        }

        cout << ans << endl;
    }
    return 0;
}
