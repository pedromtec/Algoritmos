#include <bits/stdc++.h>
#define INF 100000000
using namespace std;

int c;
map<pair<int, int>, int> dist;

int bfs(int a, int b){
    queue<pair<int, int> > q;
    dist.clear();
    q.push({0, 0});
    dist.insert({{0, 0}, 0});
    while(!q.empty()){
        int aa = q.front().first;
        int bb = q.front().second;
        q.pop();
        if(aa == c or bb == c)
            return dist.at({aa, bb});

        vector<pair<int, int> > childs = {{aa, 0}, {0, bb}, {a, bb}, {aa, b}};

        if(aa >= b-bb)
            childs.push_back({aa - (b-bb), b});
        else
            childs.push_back({0, bb+aa});

        if(bb >= a-aa)
            childs.push_back({a, bb - (a-aa)});
        else
            childs.push_back({aa+bb, 0});

        for(pair<int, int> child: childs){
            if(!dist.count(child)){
                int d = dist.at({aa, bb}) + 1;
                dist.insert({child, d});
                q.push(child);
            }
        }

    }

    return -1;
}

int main()
{
    int t;
    cin >> t;
    while(t--){
        int a, b;
        cin >> a >> b >> c;
        cout << bfs(a, b) << endl;
    }
    return 0;
}
