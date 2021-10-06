/*
ID: dmfrodr1
TASK: inflate
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
const lli INF = 1000000000;

int main(){
    ifstream fin("inflate.in");
    ofstream fout("inflate.out");
    
    ///INPUT
    int M, N; fin >> M >> N;
    vector<long> points(N);
    vector<long> minutes(N);
    FOR(i,0,N){
        fin >> points[i] >> minutes[i];
    }

    ///PROCESSING
    vector<long> DP(M+1, 0);
    FOR(i,0,N){
        long m = minutes.at(i);
        long p = points.at(i);
        FOR(j,0,M-m+1){
            long j_ = j + m;
            DP.at(j_) = max(DP.at(j_), DP.at(j) + p);
        }
    }

    long res = *max_element(ALL(DP));

    ///OUTPUT
    fout << res << endl;

    return 0;
}
