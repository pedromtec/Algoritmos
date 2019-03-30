#include <bits/stdc++.h>

using namespace std;

int main(){
    string s;
    cin >> s;
    int cnt = 0;
    stack<char> st;
    for(char c: s){
        if(st.empty() or st.top() != c)
            st.push(c);
        else
            st.pop(), cnt++;
    }

    cout << (cnt % 2 == 0? "No":"Yes") << endl;

    return 0;
}
