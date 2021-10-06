/*
ID: dmfrodr1
TASK: runround
LANG: C++11
*/
#include <bits/stdc++.h>
typedef long long int lli;
#define FOR(i,b,e) for(lli (i) = (b); (i) < (e); ++(i))

using namespace std;

string num2str(lli M){
    string ret = "";
    while(M){
        ret = char('0'+M%10)+ret;
        M /= 10;
    }
    return ret;
}

int main(){
    ///INPUT
    ifstream fin("runround.in");
    ofstream fout("runround.out");
    lli M; fin >> M;
    ///PROCESSING
    while(true){
        ++M;
        string s = num2str(M);

        vector<bool> v(s.size(), false);
        int i = 0;
        while(!v[i]){
            v[i] = true;
            i = (i + s[i]-'0')%s.size();
        }
        if(i == 0 && find(v.begin(), v.end(), false) == v.end() &&
           set<char>(s.begin(), s.end()).size() == s.size()){
            fout << M << endl;
            return 0;
        }
    }
}
