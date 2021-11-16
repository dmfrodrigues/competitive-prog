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

template<class F> lli binsearch(lli l, lli r, F f){
    while(r-l > 1){
        lli m = l+(r-l)/2;
        f(m) ? l = m : r = m;
    } return (f(l) ? l : -1);
}

lli M, N;
VVI v;

bool is_possible(lli L){
    vector<vector<bool>> visited(M, vector<bool>(N, false));
    queue<PII> q;

    if(v[0][0] >= L) { q.push(make_pair(0, 0)); }
    while(!q.empty()){
        PII u = q.front(); q.pop();
        // cout << "u=" << u.X << "," << u.Y << endl;
        if(visited[u.X][u.Y]) continue;
        visited[u.X][u.Y] = true;
        if(u.X-1 >= 0 && v[u.X-1][u.Y] >= L) q.push(make_pair(u.X-1, u.Y));
        if(u.X+1 <  M && v[u.X+1][u.Y] >= L) q.push(make_pair(u.X+1, u.Y));
        if(u.Y-1 >= 0 && v[u.X][u.Y-1] >= L) q.push(make_pair(u.X, u.Y-1));
        if(u.Y+1 <  N && v[u.X][u.Y+1] >= L) q.push(make_pair(u.X, u.Y+1));
    }

    return visited[M-1][N-1];
}

int main(){
    cin >> M >> N;
    v = VVI(M, VI(N));
    FOR(x,0,M) FOR(y,0,N) cin >> v[x][y];
    
    lli sol = binsearch(0, 1000000005L, is_possible);
    cout << sol << endl;

    // cout << is_possible(0) << endl;
    // cout << is_possible(1) << endl;
    // cout << is_possible(2) << endl;
    // cout << is_possible(3) << endl;
    // cout << is_possible(4) << endl;
    // cout << is_possible(5) << endl;

    return 0;
}
