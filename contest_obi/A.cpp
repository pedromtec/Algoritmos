#include <bits/stdc++.h>
#define pb push_back
using namespace std;

const int INF = 1e9 + 10;
typedef long long ll;
typedef pair<int, int> pii;


int main()
{
    string s;
    cin >> s;
    for(char c: s){
        if(c == 'z') printf("%c", 'a');
        else printf("%c", c+1);
    }
    printf("\n");
    return 0;
}
