#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    if(n < m) swap(n, m);
    int cnt = 0;
    while(n >= 2 and m >= 1){
        cnt++;
        n-=2;
        m-=1;
        if(n < m) swap(n, m);
    }
    cout << cnt << endl;
    return 0;
}

/*
Aulas da USP
Aula 1: Básico
Aula 2: Arrays, matrizes e funções
Aula 3: Ordenação, Busca binária e Complexidade
Aula 4: Guloso e STL
Aula 5: Recursão e two pointers
Aula 6: Grafos 1
Aula 7: Grafos 2
Aula 8: Programação Dinâmica
Aula 9: Segment Tree
Aula 10: Problemas clássicos
*/
