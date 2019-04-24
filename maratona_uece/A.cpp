#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, P = 0, I = 0;
    cin >> n;
    for(int i = 0; i < n; i++){
        int ni;
        cin >> ni;
        if(ni & 1)
            I++;
        else P++;
    }

    printf("%d %d\n", P, I);


    return 0;
}
