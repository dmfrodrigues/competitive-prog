/*
ID: dmfrodr1
TASK: gift1
LANG: C++11
*/
#include <bits/stdc++.h>

using namespace std;

map<string, int> m;

int main() {
    ofstream fout ("gift1.out");
    ifstream fin ("gift1.in");

    int NP; fin >> NP;
    vector<string> vtr(NP);
    for(int i = 0; i < NP; ++i){
        fin >> vtr[i];
        m[vtr[i]] = 0;
    }

    for(int i = 0; i < NP; ++i){
        string from; fin >> from;
        int money, sz; fin >> money >> sz;
        m[from] -= money;
        if(sz == 0){
            m[from] += money;
        }else{
            m[from] += money%sz;
            for(int j = 0; j < sz; ++j){
                string to; fin >> to;
                m[to] += money/sz;
            }
        }
    }

    for(int i = 0; i < NP; ++i){
        fout << vtr[i] << " " << m[vtr[i]] << endl;
    }



    return 0;
}
