//https://www.urionlinejudge.com.br/judge/pt/problems/view/1234
#include <bits/stdc++.h>

using namespace std;

char lowerCase(char letra){
    if(letra >= 'A' && letra <= 'Z')
        return letra + 32;
    return letra;
}

char upperCase(char letra){
    if(letra >= 'a' && letra <= 'z')
        return letra - 32;
    return letra;
}

int main()
{
    char s[55];
    while(scanf("%[^\n]", s) != EOF){
        getchar();
        int cont = 0;
        for(int i = 0; s[i] != '\0'; i++){
            if(s[i] != ' '){
                if(cont % 2 == 0)
                    s[i] = upperCase(s[i]);
                else
                    s[i] = lowerCase(s[i]);
                cont++;
            }
        }
        cout << s << endl;
    }
    return 0;
}
