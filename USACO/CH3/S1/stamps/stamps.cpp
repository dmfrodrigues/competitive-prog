/*
ID: dmfrodr1
TASK: stamps
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
    ifstream fin("stamps.in");
    ofstream fout("stamps.out");

    ///INPUT
    long K, N; fin >> K >> N;
    vector<long> v(N);
    FOR(i,0,N) fin >> v[i];

    const long MAXV = *max_element(ALL(v));

    ///PROCESSING
    vector<long> dp(MAXV * K + 1, INF);
    dp[0] = 0;
    for(const long &s: v){
        FOR(i,0,dp.size()-s){
            if(dp[i] < K){
                dp[i+s] = min(dp[i+s], dp[i]+1);
            }
        }
    }

    long res = -1;
    FOR(i,0,dp.size()){
        if(dp[i] == INF){
            res = i;
            break;
        }
    }
    if(res == -1) res = dp.size();
    res--;

    ///OUTPUT
    fout << res << endl;

    return 0;
}
