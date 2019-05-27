#include <bits/stdc++.h>
#define lsb(x) ((x) & (-x))

using namespace std;

typedef  pair<int, int> pii;
typedef long long ll;


int main()
{
    map<string, set<string> > recebe;

    int n;
    cin >> n;
    bool flag  = true;
    string ans = "";
    while(n--){
        string a, b;
        cin >> a >> b;
        if(a == b) {
            flag = false;
            ans = a;
        }
        recebe[b].insert(a);
    }
    if(!flag){
        cout << 1 << endl;
        cout << ans << endl;
    }else{
        flag = false;
        for(auto r: recebe){
            set<string> pessoas = r.second;
            if(pessoas.size() >= 2){
                flag = true;
                vector<string> mentirosos;
                for(auto pessoa: pessoas){
                    if(recebe[pessoa].size() > 0)
                        mentirosos.push_back(pessoa);
                }
                cout << mentirosos.size() << endl;
                for(auto mentiro: mentirosos){
                    cout << mentiro << endl;
                }
            }
        }
        if(!flag){
            cout << 0 << endl;
        }
    }
    return 0;
}
