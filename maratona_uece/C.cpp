#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m, p;
    cin >> n >> m >> p;
    int res = 0;
    for(int i = 0; i < n; i++){
        int maior = 0, sum = 0;

        for(int j = 0; j < m; j++){
            int pont;
            scanf("%d", &pont);
            if(pont > maior) maior = pont;
            sum += pont;
        }

        res += (max(sum, maior));
    }

    cout << res << endl;
    return 0;
}
