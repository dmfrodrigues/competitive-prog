#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define FOR(i,b,e) for(lli (i) = (b); (i) < lli(e); ++(i))
#define INF 1000000
typedef vector<lli> VI;
typedef vector<bool> VB;

struct edge {
	lli fr, to, c;
	bool operator<(const edge& e)const{
		if(c  != e.c ) return (c  < e.c );
		if(fr != e.fr) return (fr < e.fr);
		return (to < e.to);
	}
	bool operator==(const edge& e)const{ return !(*this < e || e <  *this); }
	bool operator> (const edge& e)const{ return !(*this < e || *this == e); }
};

class alGraph:public vector< deque<edge> >{ // Adjency List
public:
	alGraph(lli s):vector< deque<edge> >(s){}
	void addEdge(lli src, lli dst, lli c = 0) {
		(*this)[src].push_back({src, dst, c});
	}
};

int main(){
    lli N, R, C; cin >> N >> R >> C;
    alGraph al(R);
    lli fr, to, val; char c;
    FOR(i,0,C){
        cin >> fr >> to >> c >> val;
        al.addEdge(fr, to, val*(c=='B'? 1 : -1 ));
    }
    lli ret = INF;
    VI mon(R, INF); VB vis(R, false);
    mon[0] = 0; vis[0] = true;
    VI mon_p;
    VB vis_p;
    FOR(i,0,N){
        mon_p = mon; vis_p = vis;
        mon = VI(R, INF); vis = VB(R, false);
        FOR(j,0,R) if(vis_p[j]){
            for(const edge &e:al[j]){
                mon[e.to] = min(mon[e.to], mon_p[e.fr]+e.c); vis[e.to] = true;
            }
        }
        if(vis[R-1]) ret = min(ret, mon[R-1]);
    }
    if(ret == INF) cout << "impossible" << endl;
    else if(ret<0) cout << "yes" << endl;
    else           cout << "no" << endl;
    return 0;
}
