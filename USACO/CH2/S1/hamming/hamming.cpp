/*
ID: dmfrodr1
TASK: hamming
LANG: C++11
*/
#include <bits/stdc++.h>
using namespace std;
#define FOR(i,b,e) for(int (i) = (b); (i) < (e); ++(i))

typedef vector<int> VI ;
typedef vector<VI>  VVI;

int distance(int a, int b){
    int n = a^b;
    int ret = 0;
    while(n){
        ret += n&1;
        n >>= 1;
    }
    return ret;
}


int main(){
    ///INPUT
    ifstream fin("hamming.in");
    ofstream fout("hamming.out");
    int N, B, D; fin >> N >> B >> D;
    set<int> s;
    FOR(i,0,1<<B) s.insert(i);
    VI v(N);
    FOR(i,0,N){
        int n = *s.begin(); s.erase(s.begin()); v[i] = n;
        for(auto it = s.begin(); it != s.end();){
            int d = distance(n, *it);
            if(d < D) it = s.erase(it);
            else      ++it;
        }
    }
    bool firstTime = true;
    FOR(i,0,(int)v.size()){
        if(i%10==0 && !firstTime) fout << endl;
        firstTime = false;
        fout << v[i]; if((i != (int)v.size()-1) && ((i+1)%10!=0)) fout << " ";
    }
    fout << endl;
    return 0;
}
