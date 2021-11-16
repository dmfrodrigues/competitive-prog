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

typedef pair<pair<lli,lli>, lli> competition_t;
#define START first.first
#define END first.second
#define PRIZE second

int main(){
    lli N, K; cin >> N >> K;
    vector<competition_t> comp(N);
    FOR(i,0,N){
        cin >> comp[i].START >> comp[i].END >> comp[i].PRIZE;
    }
    sort(ALL(comp));

    vector<map<lli, lli>> DP(K+1);
    DP[0][0] = 0;
    lli sol = 0;
    FOR(k,0,K){
        size_t comp_idx_start = 0;
        for(const auto &p: DP[k]){
            lli x = p.first;
            lli v = p.second;
            while(comp_idx_start < comp.size() && comp[comp_idx_start].START < x) ++comp_idx_start;
            // cout << "k,x,v,comp_idx_start=" << k << "," << x << "," << v << "," << comp_idx_start << endl;
            FOR(comp_idx, comp_idx_start, comp.size()){
            // if(comp_idx_start >= comp.size()) continue;
                const competition_t &c = comp[comp_idx];
                lli newk = k+1;
                lli newx = c.END + 1;
                lli newv = v + c.PRIZE;
                lli &dp = DP[newk][newx];
                dp = max(dp, newv);
                sol = max(sol, dp);
            }
        }
    }

    cout << sol << endl;

    return 0;
}
