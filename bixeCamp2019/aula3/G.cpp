#include <bits/stdc++.h>
#define PI 3.14159265359
#define MAXN 10010
#define EPS 1e-9
using namespace std;

double getVolume(double raio){ return PI * raio * raio; }

int n, m;

double volumes[MAXN];

bool can(double v){
    int cnt = 0;
    for(int i = 0; i < n; i++){
        cnt += (int)(volumes[i]/v);
    }
    return cnt >= m;
}

int main(){

    int t;

    cin >> t;

    while(t--){
        cin >> n >> m;
        m++;
        for(int i = 0; i < n; i++){
            double raio;
            cin >> raio;
            volumes[i] = getVolume(raio);
        }

        double ans = 0.0;

        double ini = 0.0, fim = MAXN;
        while(fabs(fim-ini) > EPS){
            double meio = (ini+fim)/2;
            double v = getVolume(meio);
            if(can(v)){
                ans = v;
                ini = meio;
            }else
                fim = meio;
        }

        printf("%.4lf\n", ans);

    }
    return 0;
}
