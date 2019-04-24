#include <bits/stdc++.h>

using namespace std;

int f(int n){
    if(n == 1) return 0;
    return 1 + (n % 2 == 0? f(n/2): f(3*n+1));
}
int main()
{
    int n;
    cin >> n;
    cout << f(n) << endl;
    return 0;
}
