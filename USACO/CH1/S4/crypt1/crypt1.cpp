/*
ID: dmfrodr1
TASK: crypt1
LANG: C++11
*/
#include <bits/stdc++.h>
#define FOR(i,V)    for(auto& (i) : (V) )
using namespace std;

int N;
set<int> d;

string repr(int n){
    string ret = to_string(n);
    //cout << "repr, " << n << " " << ret << endl;
    return ret;
}

bool inset(string s){
    FOR(c,s)
        if(d.find(c-'0') == d.end())
            return false;
    return true;
}

bool isfine1(int n){
    string s = to_string(n);
    return (s.size() == 3 && inset(s));
}
bool isfine2(int n){
    string s = to_string(n);
    return (s.size() == 4 && inset(s));
}

int main(){
    ifstream fin("crypt1.in");
    ofstream fout("crypt1.out");
    fin >> N;
    int x;
    for(int i = 0; i < N; ++i){
        fin >> x;
        d.insert(x);
    }

    int c = 0;
    int n1, n2;
    FOR(i, d) FOR(j, d) FOR(k, d) FOR(l, d) FOR(m, d){
        n1 = 100*i + 10*j + 1*k;
        n2 = 10*l + 1*m;
        if(isfine1(n1*l) && isfine1(n1*m) && isfine2(n1*n2)) ++c;
    }

    fout << c << endl;

    return 0;
}
