#include <bits/stdc++.h>
#define MAXN 10000010
using namespace std;

int isPrime[MAXN];

void crivo(){
    memset(isPrime, 1, sizeof isPrime);
    isPrime[0] = isPrime[1] = 0;
    for(int i = 2; i * i < MAXN; i++){
        if(isPrime[i]){
            for(int j = i * i; j < MAXN; j += i){
                isPrime[j] = 0;
            }
        }
    }
}


int main()
{
    ios::sync_with_stdio(false);
    crivo();
    int t;
    scanf("%d\n", &t);
    while(t--){
        int n;
        scanf("%d", &n);
        while(n){
            if(!isPrime[n]) break;
            n/=10;
        }
        printf("%c\n", (n ? 'N':'S'));
    }
    return 0;
}
