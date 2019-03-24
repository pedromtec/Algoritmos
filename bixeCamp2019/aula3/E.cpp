#include <bits/stdc++.h>

using namespace std;

struct Carro{
    int id;
    int tempo_total;
};

typedef struct Carro Carro;

bool comp(Carro a, Carro b){
    return a.tempo_total < b.tempo_total;
}
int main()
{
    int n, m;
    cin >> n >> m;

    Carro carros[n];

    for(int i = 0; i < n; i++){
        int tempo;
        carros[i].id = i+1;
        carros[i].tempo_total = 0;
        for(int j = 0; j < m; j++){
            cin >> tempo;
            carros[i].tempo_total += tempo;
        }
    }
    sort(carros, carros+n, comp);

    for(int i = 0; i < 3; i++){
        cout << carros[i].id << endl;
    }

    return 0;
}
