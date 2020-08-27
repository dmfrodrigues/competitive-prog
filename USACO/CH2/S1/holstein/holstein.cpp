/*
ID: dmfrodr1
TASK: holstein
LANG: C++11
*/
#include <bits/stdc++.h>
using namespace std;
#define FOR(i,b,e) for(int (i) = (b); (i) < (e); ++(i))

typedef vector<int> VI ;
typedef vector<VI>  VVI;

VI v;
VVI g;

int count_binary(int n){
    int ret = 0;
    while(n){
        ret += n&1;
        n >>= 1;
    }
    return ret;
}

bool is_valid(int id){
    int i = 0;
    VI w(v.size(), 0);
    while(id){
        if(id&1){
            FOR(j,0,(int)w.size()){
                w[j] += g[i][j];
            }
        }
        id >>= 1;
        ++i;
    }
    FOR(j,0,(int)v.size()) if(w[j] < v[j]) return false;
    return true;
}

int main(){
    ///INPUT
    ifstream fin("holstein.in");
    ofstream fout("holstein.out");
    int V; fin >> V; v = VI(V); for(int &i:v) fin >> i;
    int G; fin >> G; g = VVI(G, VI(V));
    for(auto &w:g) for(int &i:w) fin >> i;
    ///PROCESS
    int sz_ans = 30;
    int id_ans = 0;
    FOR(id,0,1<<G){
        int sz = count_binary(id);
        if(is_valid(id)){
            if(sz < sz_ans || (sz == sz_ans && id < id_ans)){
                sz_ans = sz;
                id_ans = id;
            }
        }
    }
    fout << sz_ans;
    int i = 1;
    while(id_ans){
        if(id_ans&1) fout << " " << i;
        id_ans >>= 1;
        ++i;
    }
    fout << endl;
    return 0;
}
