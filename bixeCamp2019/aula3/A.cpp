#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int v[n];
    for(int i = 0; i < n; i++)
        cin >> v[i];
    sort(v, v+n);
    for(int i = 0; i < n; i++){
        cout << v[i];
        cout << (i == n-1 ? '\n':' ');
    }
    return 0;
}
