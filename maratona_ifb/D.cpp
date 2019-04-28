#include <bits/stdc++.h>

using namespace std;

vector<vector<int> > nums;

vector<int> next(vector<int> &num){
    vector<int> next_num;
    int ant  = num[0];
    int cont = 1;
    for(int i = 1; i < num.size(); i++){
        if(num[i] == ant) cont++;
        else{
            next_num.push_back(cont);
            next_num.push_back(ant);
            cont = 1;
        }
        ant = num[i];
    }
    next_num.push_back(cont);
    next_num.push_back(ant);

    return next_num;
}

void gera(){
    nums.push_back({0});
    nums.push_back({1});
    for(int i = 2; i <= 30; i++)
        nums.push_back(next(nums[i-1]));
}


int main()
{
    int n;
    cin >> n;
    gera();
    for(int i = 0; i < nums[n].size(); i++)
        cout << nums[n][i];
    cout << endl;
    return 0;
}
