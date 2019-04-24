#include <bits/stdc++.h>
#define MAXN 100010
#define MAXV 1000010
using namespace std;

typedef long long ll;

int n;
ll bit[MAXN];
bool isPrime[MAXV];


void crivo(){
    for(int i = 2; i < MAXV; i++){
        isPrime[i] = true;
    }

    for(int i = 2; i * i < MAXV; i++){
        if(isPrime[i]){
            for(int j = i * i; j < MAXV; j+=i)
                isPrime[j] = false;
        }
    }
}
ll get(int index)
{
    ll sum = 0;
    while(index > 0){
        sum += bit[index];
        index -= index & (-index);
    }
    return sum;
}


void update(int index, int val)
{
    while(index <= n){
        bit[index] += val;
        index += index & (-index);
    }
}


int main()
{
    int m;
    scanf("%d %d", &n, &m);
    crivo();
    for(int i = 1; i <= n; i++){
        int val;
        scanf("%d", &val);
        update(i, isPrime[val]);
    }

    while(m--){
        int x, y;
        char c;
        scanf(" %c %d %d", &c, &x, &y);
        if(c == 'S'){
            int ant = get(x) - get(x-1);
            int p = isPrime[y];
            if(ant && !p)
                update(x, -1);
            if(!ant && p)
                update(x,  1);
        }else{
            printf("%lld\n", get(y) - get(x-1));
        }
    }
    return 0;
}
