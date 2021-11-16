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

class amGraph: public VVI{  // Adjency Matrix
public:
	amGraph(lli s, lli val = INF):VVI(s, VI(s, val)){}
	void addEdge(lli src, lli dst, lli c){
		(*this)[src][dst] = c;
	}
};

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

class elGraph: public deque<edge>{  // Edge List
public:
	lli n;
	elGraph(lli s):deque<edge>(){n = s;}
	void addEdge(lli src, lli dst, lli c){
		this->push_back({src,dst,c});
	}
};

lli dijkstra(const alGraph &g, lli src, lli trg, VI& dist, VI& prev) {
    if(dist.size() != g.size() || prev.size() != g.size()) return INF;
    fill(ALL(dist), INF); fill(ALL(prev),  -1);
    vector<bool> v(g.size(), false);
    priority_queue<PII, vector<PII>, greater<PII> > a; //cost so far, node
    dist[src] = 0; prev[src] = -1; a.push({0, src});
    while(!a.empty()){
        lli cur = a.top().second; a.pop();
        if(cur == trg) return dist[cur];
        if(v[cur]){ continue; } v[cur] = true;
        for(const auto& e : g[cur])
            if (dist[e.to] > dist[cur] + e.c) {
                dist[e.to] = dist[cur] + e.c;
                prev[e.to] = cur;
                a.push({dist[e.to], e.to});
            }
    }
    return INF;
}

template<class T> class segtree_sparse{
private:
	typedef T (*FCN)(const T&, const T&); // DONT CHANGE =======================
	FCN fcn;
	const T FCN_NEUTRAL;
	static const ulli MAX_INDEX = ulli(1)<<31;
	struct node{
		node *left = NULL, *right = NULL;
		ulli l, r; T v;
		node(ulli l_, ulli r_, T v_):l(l_),r(r_),v(v_){}
	};
	node *root = new node(0, MAX_INDEX, FCN_NEUTRAL);
	void expand(node *c){
		if(c->left == NULL){
			ulli m = (c->l + c->r)/2;
			c->left  = new node(c->l, m   , FCN_NEUTRAL);
			c->right = new node(m   , c->r, FCN_NEUTRAL);
		}
	}
	void update(ulli p, T v, node *c){
		if(c->l == p && c->r == p+1) c->v = v;
		else if(c->l <= p && p < c->r){
			expand(c);
			update(p, v, c->left);
			update(p, v, c->right);
			c->v = fcn(c->left->v, c->right->v);
		}
	}
	T query(ulli l, ulli r, node *c){
		if(c == NULL || c->r <  l || r <  c->l) return FCN_NEUTRAL;
		if(             l <= c->l && c->r <= r) return c->v;
		return fcn(query(l, r, c->left), query(l, r, c->right));
	}
public:
	segtree_sparse(T NEUTRAL, FCN f):fcn(f), FCN_NEUTRAL(NEUTRAL){}
	segtree_sparse(vector<T> in, T NEUTRAL, FCN f):segtree_sparse(NEUTRAL, f){
		for(ulli i = 0; i < in.size(); ++i) update(i, in[i]);
	}
	void update(ulli p, T v){ update(p, v, root); }
	T query(ulli l, ulli r){ return query(l, r, root); }
};

struct triple{
    lli A, B, C;
    bool operator<(const triple &t) const{
        if     (A != t.A) return (A < t.A);
        else if(B != t.B) return (B < t.B);
        else              return (C < t.C);
    }
};

int main(){
    lli N; cin >> N; alGraph g(N);{
        lli E; cin >> E;
        lli src, dst, c;
        for(lli i = 0; i < E; ++i){
            cin >> src >> dst >> c;
            g.addEdge(src, dst, c);
            g.addEdge(dst, src, c);
        }
    }
    VI d0(N), d1(N), d2(N), prev(N);{
        dijkstra(g, 0, -1, d0, prev);
        dijkstra(g, 1, -1, d1, prev);
        dijkstra(g, 2, -1, d2, prev);
    }
    vector<triple> v(N);{
        for(lli i = 0; i < N; ++i)
            v[i] = triple({d0[i], d1[i], d2[i]});
        sort(ALL(v));
    }
    segtree_sparse<lli> s_leq(INF, [](const lli &a, const lli &b){ return min(a,b); });
    segtree_sparse<lli> s_les(INF, [](const lli &a, const lli &b){ return min(a,b); }); lli les_index = 0;
    vector<bool> useful(N, false);
    for(lli i = 0; i < N; ++i){
        const triple &t = v[i];

        while(v[les_index].A < t.A){
            if(useful[les_index]){
                s_les.update(v[les_index].B, min(s_les.query(v[les_index].B, v[les_index].B+1), v[les_index].C));
            }
            ++les_index;
        }

        lli Cmin1 = s_leq.query(0, t.B+1);
        if(Cmin1 < t.C) continue; // If A,B <=, and C<
        lli Cmin2 = s_les.query(0, t.B+1);
        if(Cmin2 <= t.C) continue; //If B,C <=, and A<
        lli Cmin3 = s_leq.query(0, t.B);
        if(Cmin3 <= t.C) continue; // If A,C <= and B<

        useful[i] = true;
        s_leq.update(t.B, min(s_leq.query(t.B, t.B+1), t.C));
    }
    cout << count(ALL(useful), true) << endl;
    return 0;
}
