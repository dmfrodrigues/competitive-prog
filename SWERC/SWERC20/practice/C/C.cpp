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
const lli INF = 10000000000000000;

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

int main(){
    // INPUT
    lli N, S; cin >> N >> S;
    VI C(N);
    FOR(i,0,N) cin >> C[i];
    
    // PROCESSING
    segtree_short<lli> tree(C, INF, [](const lli& lhs, const lli& rhs){return min(lhs,rhs);});
    lli max_all_rounds = -INF;
    FOR(i,0,N){
        tree.update(i, tree.query(i, i+1)+N*S);
        lli min_round = tree.query(0,N) - (i+1)*S;

        max_all_rounds = max(max_all_rounds, min_round);
    }

    cout << max_all_rounds << endl;

    return 0;

}
