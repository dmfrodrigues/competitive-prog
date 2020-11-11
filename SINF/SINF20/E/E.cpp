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

lli K;
lli N;
VI C;
lli M;

/**
 * Make up K
 */
lli solve(){
    map<lli, lli> DP; DP[0] = 1;
    FOR(i,0,N){
        map<lli,lli> DP_old = DP;
        for(const auto &p: DP_old){
            lli sum = p.first + C[i];
            if(sum <= K) DP[sum] += p.second;
        }
    }
    return DP[K];
}

list<VI> getPossibilities(lli M, lli start, unordered_set<lli> used){
    if(M == 0) return list<VI>(1, VI());
    if(M > N-start) return list<VI>();
    list<VI> ret;
    FOR(i,start,N){
        if(used.count(i)) continue;
        unordered_set<lli> used_ = used; used_.insert(i);
        list<VI> l = getPossibilities(M-1, i+1, used_);
        for(VI &v: l){
            v.push_back(i);
            ret.push_back(v);
        }
    }
    return ret;
}

bool sumsK(const VI &v){
    lli sum = 0;
    for(const lli &i:v) sum += C.at(i);
    return (sum == K);
}

lli howManySumK(const list<VI> &possibilities){
    lli ret = 0;
    for(const VI &v: possibilities)
        if(sumsK(v)) ++ret;
    return ret;
}

int main(){
    cin >> K >> M >> N;
    C = VI(N);
    FOR(i,0,N) cin >> C[i];
    lli ret = solve();
    list<VI> possibilities;
    FOR(i,0,M){
        list<VI> possibilities = getPossibilities(i, 0, unordered_set<lli>());
        ret -= howManySumK(possibilities);
    }

    cout << ret << endl;

    return 0;
}
