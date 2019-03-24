#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, l;
    cin >> n >> l;
    int a[n];
    for(int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a+n);
    double dini = a[0];
    double dfim = l - a[n-1];
    double max_dist = max(dini, dfim);
    for(int i = 1; i < n; i++)
        max_dist = max(max_dist, (a[i]-a[i-1])/2.0);

    printf("%.9lf\n", max_dist);
    return 0;
}
