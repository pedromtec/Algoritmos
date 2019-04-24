#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        string a;
        cin >> a;
        stack<char> st;
        bool isValid = true;
        map<char, char> inv;
        inv['('] = ')';
        inv['{'] = '}';
        inv['['] = ']';

        for(char c: a){
            if(c == '(' or c == '{' or c == '[')
                st.push(c);
            else{
                if(st.empty() or inv[st.top()] != c){
                    isValid = false;
                    break;
                }else st.pop();

            }
        }
        if(!st.empty()) isValid = false;

        cout << (isValid ? 'S':'N') << endl;
    }
    return 0;
}
