#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    string s;
    vector<char> st;
    cin >> n;
    cin >> s;
    int removidos = 0;
    for(char c: s){
        if(c != 'x') st.clear();
        else{
            if((int)st.size() == 2)
                removidos++;
            else
                st.push_back(c);
        }
    }
    cout << removidos << endl;
    return 0;
}
