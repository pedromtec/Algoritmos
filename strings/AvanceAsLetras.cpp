//https://www.urionlinejudge.com.br/judge/pt/problems/view/1234
#include <bits/stdc++.h>

using namespace std;

int dist(char x, char y){
    if(x <= y)
        return y - x;

    int pos = y-'a' + 1;
    return 'z' - x + pos;
}

int main()
{
    int t;
    cin >> t;
    char s1[10010], s2[10010];
    while(t > 0){
        cin >> s1 >> s2;
        int soma = 0;
        for(int i = 0; s1[i] ; i++){
            soma += dist(s1[i], s2[i]);
        }
        cout << soma << endl;
        --t;
    }

    return 0;
}
