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

const lli RMAX = 100000;

lli E;
VI R;
VI T;
vector<list<size_t> > children;
VI sol;
segtree_short<lli> tree(0, [](const lli &lhs, const lli &rhs){ return lhs + rhs; });

void solve(lli i){
    lli prev = tree.query(0, R[i]);
    for(const lli &child: children[i])
        solve(child);
    sol[i] = tree.query(0, R[i]) - prev;
    tree.update(R[i], tree.query(R[i], R[i]+1) + T[i]);
}

int main(){
    // INPUT
    cin >> E;
    R = VI(E);
    T = VI(E);
    children = vector<list<size_t> >(E);
    lli director;
    FOR(i,0,E){
        lli m;
        cin >> m >> R[i] >> T[i];
        if(m == -1) director = i;
        else {
            --m;
            children[m].push_back(i);
        }
    }

    // PROCESS
    sol = VI(E);
    solve(director);

    // OUTPUT
    FOR(i,0,E){
        cout << sol[i] << endl;
    }

    return 0;
}
