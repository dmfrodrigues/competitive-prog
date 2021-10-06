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

lli trace(const VVI &M){
    const lli &N = M.size();
    lli ret = 0;
    FOR(i,0,N) ret += M[i][i];
    return ret;
}

lli numrows(const VVI &M){
    const lli &N = M.size();
    lli ret = 0;
    VB visited(N+1, false);
    FOR(i,0,N){
        bool repeated = false;
        FOR(j,0,N){
            if(visited[M[i][j]]){
                repeated = true;
                break;
            }
            visited[M[i][j]] = true;
        }
        fill(ALL(visited), false);
        if(repeated) ++ret;
    }
    return ret;
}

lli numcols(VVI M){
    const lli &N = M.size();
    FOR(i,0,N) FOR(j,0,i) swap(M[i][j], M[j][i]);
    return numrows(M);
}

int main(){
    lli T; cin >> T;
    FOR(t,0,T){
        lli N; cin >> N;
        VVI M(N, VI(N, 0));
        FOR(i,0,N) FOR(j,0,N) cin >> M[i][j];
        lli k = trace(M), r = numrows(M), c = numcols(M);
        cout << "Case #" << t+1 << ": " << k << " " << r << " " << c << "\n";
    }
    cout << flush;
    return 0;
}
