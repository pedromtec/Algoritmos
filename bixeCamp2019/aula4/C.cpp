#include <bits/stdc++.h>

using namespace std;

int n, k;
string s;

int get(char c){
    int i, j;
    int t = k;
    i = j = 0;
    int ans = 0;
    while(j < n){
        if(t < 0){
            if(s[i] != c) t++;
            i++;
            if(i > j) j = i;
        }else{
            if(s[j] != c)
                t--;
            j++;
        }
        ans = t < 0? ans: max(ans, j-i);
    }
    return ans;
}

int main()
{
    cin >> n >> k >> s;
    int ans = max(get('b'), get('a'));
    cout << ans << endl;
    return 0;
}
