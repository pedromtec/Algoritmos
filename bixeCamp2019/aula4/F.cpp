#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int bar[n];
    for(int i = 0; i < n; i++)
        cin >> bar[i];

    int a = 0, ta = bar[0];
    int b = n-1, tb = bar[n-1];

    while(b-a > 1){
        if(ta < tb)
            ta += bar[++a];
        else if(ta > tb)
            tb += bar[--b];
        else{
            ta += bar[++a];
            tb += bar[--b];
            if(a == b)
            {
                b++;
                break;
            }
        }
    }

    if(n == 1) a = 0, b = n;

    printf("%d %d\n", a+1, n-b);
    return 0;
}
