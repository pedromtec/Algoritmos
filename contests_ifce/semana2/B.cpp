#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int v[n+1];
    int max_seq = 0, seq_atual = 0;

    for(int i = 0; i < n; i++){
        cin >> v[i];
        if(v[i]) seq_atual++;
        else seq_atual = 0;
        max_seq = max(seq_atual, max_seq);
    }

    for(int i = 0; v[i]; i++){
        if(v[i]) seq_atual++;
        max_seq = max(seq_atual, max_seq);
    }

    cout << max_seq << endl;

    return 0;
}
