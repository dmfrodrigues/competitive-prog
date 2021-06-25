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
    int M, N; cin >> M >> N;
    VI f(M+N+1, 0);
    FOR(i,1,M+1) FOR(j,1,N+1) ++f[i+j];
    lli m = *max_element(ALL(f));
    FOR(i,0,f.size()) if(f[i] == m) cout << i << endl;
    return 0;
}
