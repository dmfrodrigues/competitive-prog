#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;
typedef unsigned long long int ulli;

//#define ALL(v)          (v).begin() , (v).end()
//#define FOR(i,n)        for (lli i = 0; i < (n); i++)
//#define REP(i, b, e)    for (lli i=b; i<e; ++i)

const lli LOW_INF = numeric_limits<lli>::min();

//SEGMENT TREE
class segtree{
private:
	typedef lli T; //DEFINIR O QUE SE ESTA A GUARDAR NA SEGTREE
	inline T fcn(const T& arg1, const T& arg2)const{ return (arg1 > arg2? arg1:arg2); } //OPERA SOBRE ARGUMENTOS
	T T_NEUTRAL = LOW_INF; //DEFINIR VALOR NEUTRO

	ulli n;
	vector<T> tree;
public:
	segtree(const deque<T>& in){
		ulli sz = in.size()-1, p = 0;
		while(sz){ sz >>= 1; ++p; } n = sz = 1L<<p;
		tree = vector<T>(2*n, T_NEUTRAL); copy(in.begin(), in.end(), tree.begin()+n);
		for(ulli i = n-1; i > 0; --i)
			tree[i] = fcn(tree[i<<1], tree[i<<1 | 1]);
	}

	T query(ulli l, ulli r) const{
		T ret = T_NEUTRAL;
		l += n; r += n;
		for(; l < r; l>>=1, r>>=1){
			if(l&1) ret = fcn(ret, tree[l++]);
			if(r&1) ret = fcn(ret, tree[--r]);
		}
		return ret;
	}

	void print() const{
		ulli i = 1;
		cout << "segtree:" << endl;
		while(i < tree.size()){
			for(ulli j = i; j < 2*i; ++j){
				cout << tree[j] << " ";
			}cout << endl;
			i *= 2;
		}
	}
};



int main(){
	lli N, Q;
	while(true){
		///INPUT
		cin >> N; if(N == 0) break;
		cin >> Q;
		vector<lli> vtr(N);
		for(auto& m:vtr){
			cin >> m;
		}
		///PRE-PROCESSING
		deque<lli> vals;{
			vals.push_back(1);
			for(lli i = 1; i < N; ++i){
				if(vtr[i] != vtr[i-1]){
					vals.push_back(1);
				}else{
					++vals.back();
				}
			}
		}
		segtree sgt(vals);// sgt.print();
		vector<lli> sums(vals.size(), 0);{
			sums[0] = vals[0];
			for(lli i = 1; i < vals.size(); ++i)
				sums[i] = sums[i-1] + vals[i];
			//partial_sum(vals.begin(), vals.end(), sums.begin());
		}
		///SOLVE
		lli l, r;
		lli l_sums, r_sums;
		lli ans;
		for(lli q = 0; q < Q; ++q){
			cin >> l >> r;
			if(min(l, r) < 1 || max(l,r) > N || r < l) raise(SIGSEGV);

			l_sums = lower_bound(sums.begin(), sums.end(), l) - sums.begin()+1;	//cout << "l_sums:" << l_sums << endl;
			r_sums = upper_bound(sums.begin(), sums.end(), r) - sums.begin()  ;	//cout << "r_sums:" << r_sums << endl;
			if(l_sums <= r_sums){
				ans = sgt.query(l_sums, r_sums);
				if(l_sums > 0)					ans = max(ans, sums[l_sums-1] - l + 1);
				if(r_sums < (lli)vals.size())	ans = max(ans, vals[r_sums] - (sums[r_sums] - r));
			}else{
				ans = r - l + 1;
			}
			cout << ans << endl;
		}
	}

	return 0;
}

