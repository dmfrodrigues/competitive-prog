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

lli NMAX = 200000;
lli GMAX = 200;

void solve(const deque<lli> &g, VI &sol, lli l, lli r){
    // cout << "solve " << l << "," << r << endl;
    if(r-l <= 0) return;
    if(r-l == 1) {
        lli i = l;
        if(g[i] > g[i-1])
            sol[i] = max(sol[i], sol[i-1]+1);
        if(g[i] > g[i+1])
            sol[i] = max(sol[l], sol[i+1]+1);
        return;
    }

    lli i = min_element(g.begin()+l, g.begin()+r)-g.begin();
    // cout << "min index is " << i << endl;
    if(i == l){
        if(g[i] > g[i-1])
            sol[i] = max(sol[i], sol[i-1]+1);
        solve(g, sol, l+1, r);
    } else if(i == r-1){
        if(g[i] > g[i+1])
            sol[i] = max(sol[l], sol[i+ 1]+1);
        solve(g, sol, l, i);
    } else {
        sol[i] = 1;
        solve(g, sol, l, i);
        solve(g, sol, i+1, r);
    }
}

int main(){
    deque<lli> g(NMAX);
    lli i = 0;
    while(cin >> g[i]){ ++i; }
    g.resize(i);

    const lli &N = i;

    g.push_front(-1);
    g.push_back(-1);

    // FOR(i,0,N+2){
    //     cout << g[i] << " ";
    // }
    // cout << endl;

    VI sol(N+2, 1); sol[0] = 0; sol[N+1] = 0;
    solve(g, sol, 1, N+1);
    lli res = accumulate(ALL(sol), 0);

    // FOR(i,0,N+2){
    //     cout << sol[i] << " ";
    // }
    // cout << endl;

    cout << res << endl;

    return 0;
}
