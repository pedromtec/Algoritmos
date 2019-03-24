#include <bits/stdc++.h>

using namespace std;
int N;
double A;
int a[100010];

double sum(double corte){
    double s = 0.0;
    for(int i = 0; i < N; i++){
        if ((double)a[i] - corte > 0.0)
            s += (a[i] - corte);
    }
    return s;
}

int main()
{
    while(cin >> N >> A && N+A){


        double f = 0;
        for(int i = 0; i < N; ++i)
            cin >> a[i], f += a[i];

        if(f == A) cout << ":D\n";
        else if(f < A) cout << "-.-\n";
        else{
            double EPS = 1e-6;
            double ini = 0.0, fim = 10000.0;
            double ans = -1;
            while(fabs(fim-ini) > EPS){
                double meio = (fim+ini)/2.0;
                f = sum(meio);
                ans = meio;
                if(f < A){
                    fim = meio;
                }else ini = meio;
            }
            printf("%.4lf\n", ans);
        }
    }
    return 0;
}
