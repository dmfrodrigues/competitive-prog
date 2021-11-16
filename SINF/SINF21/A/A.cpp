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
    int N; cin >> N;
    VI v(N);
    FOR(i,0,N) cin >> v[i];
    lli best = -INF;
    lli s = 0;
    FOR(i,0,N){
        s = (s > 0 ? s : 0) + v[i];
        best = max(best, s);
    }
    cout << best << endl;
    
    return 0;
}
