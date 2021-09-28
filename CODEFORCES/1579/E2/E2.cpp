/**
 * A greedy solution works:
 * When deciding to place a number with index i on the left or right, the
 * order of the already-placed numbers (index <i) does not matter:
 * - if a[i] is placed to the left, it will add to the penalty the equivalent
 * to the amount of numbers with index <i that are greater than a[i];
 * - if a[i] is placed to the right, it will add to the penalty the equivalent
 * to the amount of numbers with index <i that are less than a[i].
 * 
 * So now we only have to find a fast way to decide if we want to place the
 * number to the left or to the right.
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


#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update

using namespace __gnu_pbds;
///General definitions
template<class Key, class T, class CMP> using orderstat =
    tree<Key, T, CMP, rb_tree_tag, tree_order_statistics_node_update>;
template<class Key> using orderstat_multiset = orderstat<Key, null_type, less_equal<Key> >;

template<class Key> struct os_multiset: public orderstat_multiset<Key>{
    size_t erase(const Key& val){
        auto it = this->lower_bound(val-1); size_t ret = 0;
        while(*it == val){
            orderstat_multiset<Key>::erase(it); ++ret;
            it = this->lower_bound(val-1);
        } return ret;
    }
};

lli solve(const vector<lli> &a){
    const size_t &N = a.size();

    lli res = 0;

    os_multiset<lli> s;
    FOR(i,0,N){
        lli les = s.order_of_key(a[i]);
        lli leq = s.order_of_key(a[i]+1);
        lli gre = s.size() - leq;

        res += min(les, gre);
        s.insert(a[i]);
    }

    return res;
}

int main(){
    int T; cin >> T;
    list<lli> d;
    FOR(t,0,T){
        // INPUT
        lli N; cin >> N;
        VI a(N);
        FOR(i,0,N) { cin >> a[i]; --a[i]; }

        // PROCESSING
        vector<bool> left(N, false);
        
        lli res = solve(a);

        // OUTPUT
        cout << res << endl;
    }

    return 0;
}
