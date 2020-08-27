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

struct edge {
	lli to, c, b;
	bool operator<(const edge& e)const{
		if(c  != e.c ) return (c  < e.c );
        if(b  != e.b ) return (b  < e.b );
		return (to < e.to);
	}
};

class alGraph:public vector< deque<edge> >{ // Adjency List
public:
	alGraph(lli s):vector< deque<edge> >(s){}
	void addEdge(lli src, lli dst, lli c, lli b) {
		(*this)[src].push_back({dst, c, b});
	}
};

struct POS{
    lli to, c, b;
    bool operator<(const POS &p) const{
        if(c  != p.c ) return (c  < p.c );
        if(b  != p.b ) return (b  < p.b );
        return (to < p.to);
    }
    bool operator>(const POS &p) const{ return (p < *this); }
};

lli B;

lli dijkstra(const alGraph &g, lli src, lli trg) {
    priority_queue<POS, vector<POS>, greater<POS> > a; //cost so far, node
    a.push({src, 0, 0});
    while(!a.empty()){
        POS pos = a.top(); a.pop();
        if(pos.b > B) continue;
        if(pos.to == trg) return pos.c;
        for(const auto& e : g[pos.to]){
            a.push({e.to, pos.c+e.c, pos.b+e.b});
        }
    }
    return INF;
}

lli dist(const PII &a, const PII &b){
    lli dx = a.X - b.X, dy = a.Y - b.Y;
    return ceil(sqrt(dx*dx+dy*dy));
}

int main(){
    lli xs, ys; cin >> xs >> ys;
    lli xd, yd; cin >> xd >> yd;
    cin >> B;
    lli C0; cin >> C0;
    lli T; cin >> T;
    VI C(T+1); C[0] = C0;
    FOR(i,1,T+1) cin >> C[i];
    lli N; cin >> N;
    vector<PII> pos(N+2);
    vector< vector<PII> > links(N);
    FOR(i,0,N){
        cin >> pos[i].X >> pos[i].Y;
        lli l; cin >> l;
        links[i] = vector<PII>(l);
        FOR(j,0,l){
            cin >> links[i][j].first >> links[i][j].second;
        }
    }

    alGraph g(N+2);

    lli d;
    FOR(i,0,N){
        d = dist(pos[i], PII(xs, ys));
        g.addEdge(N  , i  , C[0]*d, d);
        g.addEdge(i  , N  , C[0]*d, d);
        d = dist(pos[i], PII(xd, yd));
        g.addEdge(N+1, i  , C[0]*d, d);
        g.addEdge(i  , N+1, C[0]*d, d);
        for(const PII &p:links[i]){
            d = dist(pos[i], pos[p.first]); g.addEdge(i, p.first, C[p.second]*d, d); g.addEdge(p.first, i, C[p.second]*d, d);
        }
    }

    lli ret = dijkstra(g, N, N+1);
    cout << ret << endl;

    return 0;
}
