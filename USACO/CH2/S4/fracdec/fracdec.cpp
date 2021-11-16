/*
ID: dmfrodr1
TASK: fracdec
LANG: C++11
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long int           lli;
typedef unsigned long long int  ulli;
#define ALL(v)                  (v).begin() , (v).end()
#define FOR(i, b, e)            for(lli i =(b); (i)  < (lli)(e); ++(i))
typedef vector<lli>             VI;
typedef vector<VI>              VVI;
typedef vector<bool>            VB;
typedef vector<VB>              VVB;
typedef pair< lli, lli>         PII;
typedef pair<ulli,ulli>         PUU;
typedef pair<PII,PII>           PPP;
#define X first
#define Y second

int main(){
    // INPUT FILES
    ifstream fin("fracdec.in");
    ofstream fout("fracdec.out");
    // INPUT
    long N, D;
    fin >> N >> D;
    // PROCESS
    string sout = "";

    sout += to_string(long(N/D)) + ".";
    N -= long(N/D)*D;

    deque<short> number;
    unordered_map<long, size_t> so_far;
    size_t i;
    for(i = 0; true; i++){
        if(so_far.count(N)) break;
        so_far[N] = i;
        N *= 10;
        long quotient = N/D;
        number.push_back(quotient);
        N -= quotient*D;
        if(N == 0) break;
    }

    for(size_t j = 0; j < number.size(); ++j){
        if(N != 0 && j == so_far.at(N)) sout += "(";
        sout += to_string(number[j]);
    }

    if(N != 0) sout += ")";

    FOR(j,0,sout.size()){
        fout << sout[j];
        if((j+1)%76 == 0 && j+1 != sout.size()) fout << "\n";
    }

    fout << endl;
    
    return 0;
}
