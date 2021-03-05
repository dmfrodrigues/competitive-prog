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
const lli MOD = 1000000007;

VI CATALAN(1000, 0);
void init_catalan() {
    CATALAN[0] = 1;
    FOR(n,0,CATALAN.size()-1)
        FOR(i,0,n+1)
            CATALAN[n+1] = (CATALAN[n+1] + CATALAN[i]*CATALAN[n-i])%MOD;
}


lli solve(const VI::const_iterator &begin, const VI::const_iterator &end){
    if(begin == end) return 1;

    lli m = *min_element(begin, end);
    lli n = count(begin, end, m);
    lli ret = CATALAN[n]%MOD;

    VI::const_iterator left = begin;
    VI::const_iterator right;

    for(auto it = begin; it != end; ++it){
        if(*it == m){
            right = it;
            ret = (ret*solve(left, right))%MOD;
            left = it; ++left;
        }
    }
    right = end;
    ret = (ret*solve(left, right))%MOD;
    
    return ret;
}

int main(){
    init_catalan();

    // INPUT
    lli N; cin >> N;
    VI v(N);
    FOR(i,0,N) cin >> v[i];

    // PROCESS
    lli ret = solve(v.begin(), v.end());

    // OUTPUT
    cout << ret << endl;

    return 0;
}
