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

VI solve(VI v, const lli &c){
    const lli &N = v.size();
    FOR(i,0,N) v[i] = v[i] - c*i;
    
    VI ret(N, 0);
    lli minPast = v[0];

    FOR(i,0,N){
        minPast = min(minPast, v[i]);
        ret[i] = v[i] - minPast;
    }

    return ret;
}

int main(){
    lli N, c; cin >> N >> c;
    VI v(N);
    FOR(i,0,N) cin >> v[i];

    VI sol1 = solve(v, c);
    // FOR(i,0,N) cout << sol1[i] << " "; cout << endl;

    FOR(i,0,N) v[i] = -v[i];
    VI sol2 = solve(v, c);
    // FOR(i,0,N) cout << sol2[i] << " "; cout << endl;

    FOR(i,0,N){
        cout << (i==0? "" : " ") << max(sol1[i], sol2[i]);
    }
    cout << endl;

    return 0;
}
