#include <bits/stdc++.h>
#define pb push_back
using namespace std;

const int INF = 1e9 + 10;
typedef long long ll;
typedef pair<int, int> pii;

ll pow_2(ll base, ll exp){
    ll ans = 1;
    for(ll i = 0; i < exp; i++)
        ans *= base;
    return ans;
}

int main()
{
    map<string, ll> freq;
    string musica = "";

    ll n, k;
    cin >> n >> k;

    for(int i = 0; i < n; i++){
        string num;
        cin >> num;
        musica += num;
    }

    for(int i = 0; i < (int)musica.size(); i++){
        string melodia = "";
        for(int j = i; j < (int)musica.size(); j++){
            melodia += musica[j];
            freq[melodia]++;
        }
    }

    ll maior = 0;
    for(auto par: freq){
        //cout << "melodia: " << par.first << " " << par.second << endl;
        ll p = (ll)pow_2((ll)par.first.size(), (ll)par.second);
        if(p > maior) maior = p;
    }
    //cout << maior << endl;
    if(maior >= k) cout << "Katakinho\n";
    else cout << "Leandro the Legend\n";
    return 0;
}
