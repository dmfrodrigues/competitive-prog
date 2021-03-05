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
// 10^9+7; prime

PII find_bezout(lli a, lli b){
    if(b == 0) return PII(1,0);
    PII u = find_bezout(b, a%b);
    return PII(u.Y, u.X-(a/b)*u.Y);
}

lli inv(lli a, lli MOD){
    return find_bezout(a, MOD).X%MOD;
}

lli factorial(lli n, lli MOD){
    lli ret = 1;
    FOR(i,1,n+1) ret = (ret*i)%MOD;
    return ret;
}

lli catalan(lli n, lli MOD){
    lli ret = factorial(2*n, MOD)*inv(factorial(n+1, MOD)*factorial(n, MOD), MOD);
    return (ret%MOD + MOD)%MOD;
}

lli solve(const VI::const_iterator &begin, const VI::const_iterator &end){
    if(begin == end) return 1;

    lli m = *min_element(begin, end);
    lli n = count(begin, end, m);
    lli ret = catalan(n, MOD);

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
