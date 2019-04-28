#include <bits/stdc++.h>

using namespace std;

int main()
{
    map<char, int> freq;
    string s;
    cin >> s;
    for(auto c: s){
        freq[c]++;
    }

    int impares = 0;
    for(auto no: freq){
        if(no.second % 2 != 0) impares++;
    }

    if((int)s.size() % 2 == 0)
        cout << (!impares ? "Sim":"Nao") << endl;
    else
        cout << (impares == 1 ? "Sim":"Nao") << endl;

    return 0;
}
