#include <bits/stdc++.h>

using namespace std;

int main()
{

    int d[3];
    cin >> d[0] >> d[1] >> d[2];
    sort(d, d+3);
    if(d[2] < d[1] + d[0])
        printf("Sim\n");
    else printf("Nao\n");

    return 0;
}
