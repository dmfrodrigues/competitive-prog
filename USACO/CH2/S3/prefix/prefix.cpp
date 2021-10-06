/*
ID: dmfrodr1
TASK: prefix
LANG: C++11
*/
#include <bits/stdc++.h>
#define FOR(i,b,e) for(long (i) = (b); (i) < (e); ++(i))

using namespace std;

#define SMAX 200005

bool v[200005];

int main(){
    ///INPUT
    ifstream fin("prefix.in");
    ofstream fout("prefix.out");
    string in;
    deque<string> primitives;{
        fin >> in;
        while(in != "."){
            primitives.push_back(in);
            fin >> in;
        }
    }
    string seq = "";{
        while(fin >> in) seq += in;
    }
    const long &S = seq.size();
    ///PROCESSING
    fill(v,v+SMAX,false);
    v[0] = true;
    long ret = 0;
    FOR(i,0,S){
        if(v[i]){
            for(const string &p:primitives){
                if(p == seq.substr(i, p.size())){
                    v[i+p.size()] = true;
                    ret = max(ret, long(i+p.size()));
                }
            }
        }
    }
    fout << ret << endl;
    return 0;
}
