#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){

    int n;

    while(cin >> n and n){
        vector<pair<int, int> > buys;
        priority_queue<pair<int, int> > sells;
        int b;
        for(int i = 1; i <= n; i++){
            cin >> b;
            if(b < 0) sells.push({-i, -b});
            else buys.push_back({i, b});
        }

        ll sum = 0;
        for(auto buy: buys){
            while(buy.second > 0){
                pair<int, int> sell = sells.top(); sells.pop();
                if(sell.second > buy.second){
                    sum += ((ll)buy.second * abs(buy.first + sell.first));
                    sells.push({sell.first, sell.second-buy.second});
                    buy.second = 0;
                }else{
                    buy.second -= sell.second;
                    sum += ((ll)sell.second * abs(buy.first + sell.first));
                }
            }

        }

        cout << sum << endl;


    }
    return 0;
}
