#include <bits/stdc++.h>

using namespace std;

int main(){

    int n, k;
    cin >> n;
    int casas[n];
    set<int> seen;
    for(int i = 0; i < n; i++)
        cin >> casas[i];
    cin >> k;
    for(int i = 0; i < n; i++){
        int x = k - casas[i];
        if(seen.count(x)){
            cout << x << " " << casas[i] << endl;
            break;
        }
        seen.insert(casas[i]);
    }
    return 0;
}
