/**
 * Cheated a bit here...
 * 
 * I had arrived at the conclusion that, if you can build the final sorted
 * vector for the first x indexes (i.e., in range [0, x-1]), you can then build
 * the rest.
 * Proof: Assume you have already sorted until index k-1 (assuming k-1 >= x-1 so
 * it meets the previous statement), and want to place the correct value v for
 * index k (k >= x) which is currently in index m (m >= k); the process is to
 * swap (0, m), then swap (0, k) {this is legal because k >= x}, and then swap
 * (0, m).
 * Explanation: the value v went from index m to 0 and then to k (thus ending in
 * the right place); the value that was in index 0 and was disturbed was first
 * moved to m, and then back to 0; the value that was in index k (which was
 * presumed to be the wrong value) was moved to index 0, and then to m (if v was
 * already in the right place, m=k and it goes back to where it was; otherwise,
 * it goes somewhere into the unsorted region).
 * 
 * You can be absolutely asured that you can build said well-sorted subarray
 * if you can guarantee you can always swap to the right while building the
 * subarray. This is the same as saying it must be possible to swap x with n-1,
 * which requires (n-1)-x >= x <=> n-1 >= 2x <=> n >= 2x+1.
 * 
 * The part where I cheat is when I see the tag "dsu" for this problem; stands
 * for "disjoint set union" aka union-find. So I wondered how it could help me,
 * and came to a very simple but important assumption (which I did not prove;
 * it makes some sense but it is so good that it is almost hard to believe):
 * that swapping is transitive. I.e., if you can swap (a,b) and (b,c), you can
 * also indirectly swap (a,c) by performing swaps (a,b), (b,c), (a,b), which
 * will cause b to end exactly where it was in the beginning. This transitivity
 * means that we can use union-find to say which sets of indexes can be swapped
 * among each other; after finding all disjoint sets, we just have to do a
 * simple processing step for each root:
 * - Create a new vector b;
 * - Given a root r, we can obtain the set of indexes I_r that belong to that
 * set, and the values that were in those indexes in vector a, V_r. Sort I_r and
 * V_r, and place value V_r[i] in b[I_r[i]];
 * - In the end, check if b is sorted.
 */

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

class uf{
private:
	vector<ulli> p, rank, number;
public:
	ulli sets;
	uf(ulli s):p(s), rank(s,0), number(s,1), sets(s){ FOR(i,0,s) p[i] = i; }
	void link(ulli x, ulli y) {
		if(x == y) return;
		if (rank[x] <= rank[y]) {
			p[x] = y; --sets;
			number[y] += number[x];
			if (rank[x] == rank[y]) rank[y]++;
		} else link(y, x);
	}
	ulli find_set (ulli x){ if(x!=p[x]) p[x] = find_set(p[x]); return p[x]; }
	ulli find_size(ulli x){ return number[find_set(p[x])]; }
	void union_set(ulli x, ulli y){ link(find_set(x), find_set(y)); }
	void compress(){ FOR(i,0,p.size()) find_set(i); }
};

int main(){
    int T; cin >> T;
    FOR(i,0,T){
        ///INPUT
        int n, x; cin >> n >> x;
        VI a(n);
        FOR(i,0,n) cin >> a[i];

        if(n >= 2*x){ cout << "YES" << endl; continue; }

        ///PROCESSING
        uf union_find(n);
        FOR(j,x,n) union_find.union_set(0, j);
        FOR(i,1,n){
            int j1 = i+x;
            if(j1 < n) union_find.union_set(i, j1);
        }
        union_find.compress();
        
        unordered_map<lli, set<lli>> indexes;
        unordered_map<lli, multiset<lli>> values;
        FOR(i,0,n){
            lli root = union_find.find_set(i);
            indexes[root].insert(i);
            values[root].insert(a[i]);
        }

        VI sorted(n);
        for(const auto &p: indexes){
            lli root = p.first;
            const set<lli> &is = p.second;
            const multiset<lli> &vs = values[root];

            auto it1 = is.begin();
            auto it2 = vs.begin();
            while(it1 != is.end()){
                sorted[*(it1++)] = *(it2++);
            }
        }

        ///OUTPUT
        cout << (is_sorted(ALL(sorted)) ? "YES" : "NO") << endl;

    }
    return 0;
}
