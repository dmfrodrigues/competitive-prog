#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define FOR(i,b,e) for(lli (i) = (b); (i) < lli(e); ++(i))
typedef vector<lli> VI;
typedef vector<VI> VVI;
typedef pair<lli,lli> PII;
#define X first
#define Y second
#define INF 100000

VVI flood_fill(lli W, lli H, const vector<PII> &v, lli &m){
    m = 0;
    VVI M(W, VI(H, INF));
    queue< pair<PII, lli> > q;
    for(const PII &p:v){
        q.push(make_pair(p, 0));
    }
    while(!q.empty()){
        auto a = q.front(); q.pop();
        const PII &p = a.first;
        const lli &d = a.second;
        if(d < M[p.X][p.Y]){
            M[p.X][p.Y] = d;
            m = max(m, d);
            if(0 <= p.X-1) q.push(make_pair(PII(p.X-1, p.Y  ), d+1));
            if(W >  p.X+1) q.push(make_pair(PII(p.X+1, p.Y  ), d+1));
            if(0 <= p.Y-1) q.push(make_pair(PII(p.X  , p.Y-1), d+1));
            if(H >  p.Y+1) q.push(make_pair(PII(p.X  , p.Y+1), d+1));
        }
    }
    return M;
}

int main(){
    /// INPUT
	int W, H, N; cin >> W >> H >> N;
    vector<PII> v(N);
    FOR(i,0,N) cin >> v[i].X >> v[i].Y;
    /// PROCESSING
    lli m;
    VVI M = flood_fill(W, H, v, m);
    /*
    FOR(y,0,H){
        FOR(x,0,W) cout << M[x][y] << " ";
        cout << endl;
    }
    */

    /// OUTPUT

	return 0;
}
