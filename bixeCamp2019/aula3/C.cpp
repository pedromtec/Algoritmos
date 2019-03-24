#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

bool isPrime(ll n){
    if(n <= 1) return false;
    for(int i = 2; i * i <= n; i++){
        if(n % i == 0)
            return false;
    }
    return true;
}

int main()
{
    ll n;

    cin >> n;

    cout << (isPrime(n)? 'S':'N') << endl;

    return 0;
}
