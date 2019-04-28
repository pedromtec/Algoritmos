#include <bits/stdc++.h>

using namespace std;

int main()
{
    double G, D;
    double R;
    cin >> G >> D >> R;
    double X = R / ((100-D) / 100.0);

    double ans = (X / G) * 1000;

    printf("%.8lf\n", ans);

    return 0;
}
