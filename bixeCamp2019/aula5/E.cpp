#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    while(cin >> n and n){
        int trucks[n+1];
        for(int i = 1; i <= n; i++)
            cin >> trucks[i];
        stack<int> st;
        int ordem = 1;
        for(int i = 1; i <= n; i++){
            st.push(trucks[i]);
            while(!st.empty() and st.top() == ordem)
                st.pop(), ++ordem;
        }

        cout << (st.empty() ? "yes":"no") << endl;
    }
    return 0;
}
