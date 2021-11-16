#include <bits/stdc++.h>
using namespace std;
typedef long long int           lli;
typedef unsigned long long int  ulli;
#define ALL(v)                  (v).begin() , (v).end()
#define contain(Set,i)          ( (Set) & (1Lu<<(i)) )
#define mk(a,b)                 make_pair((a), (b))
#define FOR(i, b, e)            for(lli i =(b); (i)  < (lli)(e); ++(i))
//#define REP(i, b, e)            for(auto i =(b); (i) != (e); ++(i))
typedef vector<lli>             VI;
typedef vector<VI>              VVI;
typedef pair< lli, lli>         PII;
typedef pair<ulli,ulli>         PUU;
typedef pair<PII,PII>           PPP;
#define X first
#define Y second
const lli INF = 1000000000;

#define MAXN 2005
#define MOD  1000000013L

VVI DP(MAXN, VI(MAXN, -1));

VI v;

lli f(lli i, lli p){
    //cout << i << " " << p << " " << DP[i][p]<< endl;
    if(i < 0 || p < 0)   return 0;
    if(DP[i][p] != -1)   return DP[i][p];
    if(p > i)            return (DP[i][p] = 0);

    if(i == 0 && p == 0) return (DP[i][p] = 1);
    lli r = 0;
    if(v[i-1]){
        //FOR(q,0,p) r = (r+f(i-1,q))%MOD;
        r = f(i,p-1)+f(i-1,p-1);
    }else{
        //FOR(q,p,i) r = (r+f(i-1,q))%MOD;
        r = f(i,p+1)+f(i-1,p);
    }
    return (DP[i][p] = r%MOD);
}

int main(){
    lli N; cin >> N;
    v = VI(N-1);
    for(lli &i:v) cin >> i;
    lli ans = 0;
    FOR(p,0,N){
        ans = (ans+f(N-1,p))%MOD;
    }
    //cout << f(0,)
    /*
    FOR(i,0,N-1){
        cout << "i=" << i << " | ";
        FOR(p,0,i+1){
            cout << f(i,p) << " ";
        }
        cout << endl;
    }
    */
    cout << ans << endl;
    return 0;
}
