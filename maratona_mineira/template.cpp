#include <bits/stdc++.h>
#define lsb(x) ((x) & (-x))

using namespace std;

typedef  pair<int, int> pii;
typedef long long ll;
const int MAXN  = 2010;

int seen[MAXN][MAXN];
int freq_in[MAXN];

int main()
{
    int n;
    cin >> n;
    vector<pii> cobra;
    cobra.push_back({0, 0});
    seen[0][0] = 1;
    freq_in[0]++;
    while(true){
        pii ultimo = cobra[(int)cobra.size()-1];
        int linha = ultimo.second;
        int coluna = -1;
        for(int j = 0; j <= n; j++){
            if(seen[linha][j]) continue;
            if(coluna == -1)
                coluna = j;
            else if(freq_in[j] < freq_in[coluna])
                coluna = j;
        }

        if(coluna == -1) break;
        seen[linha][coluna] = seen[coluna][linha] = 1;

        cobra.push_back({linha, coluna});
    }

    cout << (int)cobra.size() << endl;
    return 0;
}
