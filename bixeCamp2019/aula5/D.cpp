#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n],  p[n];
    for(int i = 0; i < n; i++)
        cin >> a[i] >> p[i];


    int total = 0;
    int acu = a[0];
    int id_min = 0;

    for(int i = 1; i < n; i++){
        if(p[i] < p[id_min]){
            total += (p[id_min] * acu);
            id_min = i;
            acu = a[i];
        }else acu += a[i];
    }

    total += (p[id_min] * acu);

    cout << total << endl;
    return 0;
}
