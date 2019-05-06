#include <bits/stdc++.h>

using namespace std;
vector<int> adj[110];
int grau[110];

int main()
{
    int n;
    int teste = 0;

    while(cin >> n and n){

        memset(grau,0, sizeof grau);

        for(int i = 1; i <= n; i++)
            adj[i].clear();


        for(int i = 1; i < n; i++){
            int a, b;
            cin >> a >> b;
            grau[a]++;
            grau[b]++;

            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        queue<int> q;
        for(int i = 1; i <= n; i++){
            if(grau[i] <= 1)
                q.push(i);
        }
        int u;

        while(!q.empty()){
            u = q.front();
            q.pop();
            grau[u]--;
            for(auto v: adj[u]){
                if(grau[v])
                    grau[v]--;
                if(grau[v] == 1)
                    q.push(v);
            }
        }

        printf("Teste %d\n", ++teste);
        printf("%d\n\n", u);
    }

}
