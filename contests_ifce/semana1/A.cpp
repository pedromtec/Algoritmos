#include <bits/stdc++.h>

using namespace std;

int seen[1010];

int main()
{
    int n;
    cin >> n;
    int arr[n];
    vector<int> ans;
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    for(int i = n-1; i >= 0; i--){
        if(seen[arr[i]]) continue;
        seen[arr[i]] = 1;
        ans.push_back(arr[i]);
    }
    n = (int)ans.size();
    cout << n << endl;
    for(int i = n-1; i > 0; i--){
        cout << ans[i] << " ";
    }
    cout << ans[0] << endl;
    return 0;
}
