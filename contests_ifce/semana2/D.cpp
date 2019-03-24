#include <bits/stdc++.h>

using namespace std;


int main()
{
    map<char, vector<int> > freqL;
    map<char, vector<int> > freqR;
    vector<pair<int, int > > sol;
    int n;
    cin >> n;
    string l, r;
    cin >> l >> r;

    for(int i = 0; i < (int)l.size(); i++)
        freqL[l[i]].push_back(i+1);
    for(int i = 0; i < (int)r.size(); i++)
        freqR[r[i]].push_back(i+1);

    for(char c: l){

        if(c == '?') continue;

        int tamL = (int)freqL[c].size();
        int tamR = (int)freqR[c].size();

        //cout << tamL << " " <<  tamR << endl;
        if(tamL < tamR){
            while(freqL[c].size() > 0){
                int i = (int)freqL[c].size()-1;
                int j = (int)freqR[c].size()-1;
                sol.push_back({freqL[c][i], freqR[c][j]});
                freqL[c].pop_back();
                freqR[c].pop_back();

            }
        }
        else{
            while(freqR[c].size() > 0){
                int i = (int)freqL[c].size()-1;
                int j = (int)freqR[c].size()-1;
                sol.push_back({freqL[c][i], freqR[c][j]});
                freqL[c].pop_back();
                freqR[c].pop_back();

            }
        }
    }


    vector<int> letrasL;
    vector<int> letrasR;

    for(pair<char, vector<int> > pp: freqL){
        if(pp.first == '?') {

        //    printf("%c\n", pp.first);
            continue;
        }
        for(int id: pp.second)
            letrasL.push_back(id);
    }

    for(pair<char, vector<int> > pp: freqR){
        if(pp.first == '?')
            continue;

        for(int id: pp.second)
            letrasR.push_back(id);
    }

    while(letrasL.size() > 0 && freqR['?'].size() > 0){
        //puts("oi\n");
        int i = letrasL.size()-1;
        int j = freqR['?'].size()-1;
        sol.push_back({letrasL[i], freqR['?'][j]});
        letrasL.pop_back();
        freqR['?'].pop_back();
    //    cout << sol.size() << endl;
    }

    //puts("------------------------------------------");

    while(letrasR.size() > 0 && freqL['?'].size() > 0){
        int i = letrasR.size()-1;
        int j = freqL['?'].size()-1;
        sol.push_back({freqL['?'][j], letrasR[i]});
        letrasR.pop_back();
        freqL['?'].pop_back();
    //    cout << sol.size() << endl;
    }

    //puts("------------------------------------------");

    while(freqR['?'].size() > 0 && freqL['?'].size() > 0){
        int i = freqR['?'].size()-1;
        int j = freqL['?'].size()-1;
        sol.push_back({freqL['?'][i], freqR['?'][j]});
        freqR['?'].pop_back();
        freqL['?'].pop_back();
    //    cout << sol.size() << endl;
    }

    cout << sol.size() << endl;

    for(pair<int, int> pp: sol){
        printf("%d %d\n", pp.first, pp.second);
    }
    return 0;
}
