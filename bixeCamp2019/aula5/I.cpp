#include <bits/stdc++.h>

using namespace std;

int main()
{

    int n;
    map<long long, int> freq;
    cin >> n;
    while(n--){
        long long xi;
        cin >> xi;
        freq[xi]++;
    }
    long long id_max = 0;
    for(auto pp: freq){
        if(pp.second > freq[id_max])
            id_max = pp.first;
    }

    cout << id_max << endl;
    return 0;
}
