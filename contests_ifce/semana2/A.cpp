#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    int cont = 0;
    int pot2 = 1;
    bool achou = false;
    while(n <= m){
        if(m % n == 0){
            int q = m / n;
            int aux = 0;
            while(q % 3 == 0){
                aux++;
                q /= 3;
            }
            if(q == 1){
                cont += aux;
                achou = true;
                break;
            }
        }
        cont++;
        n*=2;
    }

    if(achou) cout << cont << endl;
    else cout << -1 << endl;

    return 0;
}
