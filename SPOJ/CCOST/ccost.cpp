#include <bits/stdc++.h>
using namespace std;
typedef long int           lli;
typedef unsigned long int  ulli;
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

template<class T> class segtree_short{
private:
	typedef T (*FCN)(const T&, const T&);
	FCN fcn; const T FCN_NEUTRAL;
	static const ulli n = 131072; //MANDATORILY A POWER OF 2 ====================
	T t[2*n];
public:
	segtree_short(T NEUTRAL, FCN f):fcn(f), FCN_NEUTRAL(NEUTRAL){
		fill(t, t+2*n, FCN_NEUTRAL);
	}
	segtree_short(vector<T> in, T NEUTRAL, FCN f):segtree_short(NEUTRAL, f){
		for(ulli i = 0; i < in.size(); ++i) update(i, in[i]);
	}
	T query(ulli l, ulli r)const{
		T ret = FCN_NEUTRAL;
		for(l += n, r += n; l < r; l>>=1, r>>=1){
			if(l&1) ret = fcn(ret, t[l++]);
			if(r&1) ret = fcn(ret, t[--r]);
		} return ret;
	}
	void update(ulli p, const T& obj){
		t[p += n] = obj;
		for(ulli i = p; i > 1; i>>=1)
			t[i>>1] = fcn(t[i], t[i^1]);
	}
};

const lli MAXX = 100005;

struct tree{
	lli x, y, v;
	bool operator<(const tree &t) const{
		return (y < t.y);
	}
};


void compress(vector<tree> &p, vector< pair<PII,PII> > &q){
	static set<lli> sx, sy;
	sx.clear(); sy.clear();
	cout << "L56" << endl;
	for(const tree &t:p){
		sx.insert(t.x);
		sy.insert(t.y);
	}
	cout << "L61" << endl;
	map<lli, lli> mx, my; size_t nx = 0, ny = 0;
	for(const lli &x:sx) mx[x] = nx++;
	for(const lli &y:sy) my[y] = ny++;
	for(tree &t:p){
		t.x = mx[t.x];
		t.y = my[t.y];
	}
	cout << "L69" << endl;
	for(pair<PII,PII> &pr:q){
		{ lli &x = pr.first .X; auto itx = mx.lower_bound(x); x = (itx == mx.end() ? MAXX : itx->second); }
		{ lli &y = pr.first .Y; auto ity = my.lower_bound(y); y = (ity == my.end() ? MAXX : ity->second); }
		{ lli &x = pr.second.X; auto itx = mx.lower_bound(x); x = (itx == mx.end() ? MAXX : itx->second); }
		{ lli &y = pr.second.Y; auto ity = my.lower_bound(y); y = (ity == my.end() ? MAXX : ity->second); }
	}
	cout << "L76" << endl;
}

lli NEUTRAL = 0;
lli (*f)(const lli&, const lli&) = [](const lli &a, const lli &b){ return a+b; };


void solve(vector<tree> &p, vector< pair<PII,PII> > &q){
	sort(ALL(p));
	static map<PII, lli> m;{
		m.clear();
		//cout << "L65" << endl;
		for(const pair<PII,PII> &pr:q){
			const PII &p1 = pr.first, &p2 = pr.second;
			m[p1] = 0;
			m[p2] = 0;
			m[PII(p1.X, p2.Y)] = 0;
			m[PII(p2.X, p1.Y)] = 0;
		}
		//cout << "L76" << endl;
		segtree_short<lli> s(NEUTRAL, f); lli next_pt = 0;
		//cout << "L78" << endl;
		for(auto it = m.begin(); it != m.end(); ++it){
			while(next_pt < lli(p.size()) && p[next_pt].x < it->first.X){
				const lli &y = p[next_pt].y;
				s.update(y, s.query(y, y+1)+p[next_pt].v);
				++next_pt;
			}
			it->second = s.query(0, it->first.Y);
		}
		//cout << "L87" << endl;
	}
	//cout << "L89" << endl;
	for(const pair<PII,PII> &pr:q){
		const PII &p1 = pr.first, &p2 = pr.second;
		lli ans = m[p2] - m[PII(p2.X, p1.Y)] - m[PII(p1.X, p2.Y)] + m[p1];
		//cout << ans << "\n";
	}
	cout << flush;
 	//cout << "L96" << endl;
}

int main(){
	lli T; cin >> T;
	vector<tree> p; p.reserve(MAXX);
	vector< pair<PII,PII> > q; q.reserve(MAXX);
	FOR(t,0,T){
		cout << "L109" << endl;
		lli N; cin >> N;
		p.resize(N); {
			FOR(i,0,N) cin >> p[i].x >> p[i].y >> p[i].v;
		}
		lli R; cin >> R;
		q.resize(R); {
			FOR(i,0,R){
				cin >> q[i].first.X >> q[i].first.Y >> q[i].second.X >> q[i].second.Y;
				++q[i].second.X; ++q[i].second.Y;
			}
		}
		cout << "L121" << endl;
		compress(p, q);
		cout << "L123" << endl;
		//for(const VI &v:p){ cout << v[0] << " " << v[1] << " " << v[2] << endl; }
		//for(const pair<PII,PII> &pr:q){ cout << pr.first.X << " " << pr.first.Y << " " << pr.second.X << " " << pr.second.Y << endl; }
		solve(p, q);
		cout << "L137" << endl;
	}
    return 0;
}
