#include <bits/stdc++.h>
using namespace std;
typedef long long int           lli;
#define ALL(v)                  (v).begin() , (v).end()
#define FOR(i, b, e)            for(lli i =(b); (i)  < (lli)(e); ++(i))
typedef vector<lli>             VI;
typedef pair< lli, lli>         PII;
const lli INF = 1000000000000000;

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
	void addEdge(lli src, lli dst, lli c) {
		(*this)[src].push_back({src, dst, c});
        (*this)[dst].push_back({dst, src, c});
	}
};

lli dijkstra(const alGraph &g, lli src, lli trg, VI& dist) {
    dist = VI(g.size(), INF);
    set<PII> a; //cost so far, node
    dist[src] = 0; a.insert(make_pair(0, src));
    while(!a.empty()){
        lli cur = a.begin()->second; a.erase(a.begin());
        if(cur == trg) return dist[trg];
        for(const auto& e : g[cur])
            if (dist[e.to] > dist[cur] + e.c) {
                dist[e.to] = dist[cur] + e.c;
                a.insert(make_pair(dist[e.to], e.to));
            }
    }
    return INF;
}

int main(){
    lli NI_time; cin >> NI_time;
    lli N, M; cin >> N >> M;
    alGraph al(N+1);
    VI dist(N+1), prev(N+1);
    lli fr, to, t;
    FOR(i,0,M){
        cin >> fr >> to >> t;
        al.addEdge(fr, to, t);
    }
    lli SINF_time = dijkstra(al, 1, N, dist);
    if(NI_time > SINF_time) cout << "SINF" << endl;
    else                     cout << "NI" << endl;
    return 0;
}
