#include <bits/stdc++.h>

using namespace std;
const int MAXN = 111;

struct Pais{
	int id, ouro, prata, bronze;
};

bool comp(Pais a, Pais b)
{
	if(a.ouro != b.ouro) return a.ouro > b.ouro;
	if(a.prata != b.prata) return a.prata > b.prata;
	if(a.bronze != b.bronze) return a.bronze > b.bronze;
	return a.id < b.id;
}

int main()
{
	int n, m, o, p, b;
	Pais paises[MAXN];
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		paises[i].id = i;
		paises[i].ouro = 0;
		paises[i].prata = 0;
		paises[i].bronze = 0;
	}
	for(int i = 1; i <= m; i++){
		cin >> o >> p >> b;
		paises[o].ouro++;
		paises[p].prata++;
		paises[b].bronze++;
	}
	sort(paises+1, paises + n + 1, comp);
	for(int i = 1; i <= n; i++){
        cout << paises[i].id;
        cout << (i == n ? '\n': ' ');
    }
	return 0;
}
