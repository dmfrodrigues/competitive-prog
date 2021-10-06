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

lli solve(const VI &v){
    lli ret = 1;
    stack<lli> s;
    vector<lli> counter(1000001, 0);
    FOR(i,0,v.size()){
        lli m = v[i];
        while(!s.empty() && s.top() > m){
            lli n = s.top();
            ret = (ret*catalan(counter[n], MOD))%MOD;
            while(!s.empty() && s.top() == n){ s.pop(); --counter[n]; }
        }
        s.push(m); ++counter[m];
    }

    lli m = -1;
    while(!s.empty() && s.top() > m){
        lli n = s.top();
        ret = (ret*catalan(counter[n], MOD))%MOD;
        while(!s.empty() && s.top() == n){ s.pop(); --counter[n]; }
    }
    
    return ret;
}

int main(){
    // INPUT
    lli N; cin >> N;
    VI v(N);
    FOR(i,0,N) cin >> v[i];

    // PROCESS
    lli ret = solve(v);

    // OUTPUT
    cout << ret << endl;

    return 0;
}
