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

class uf{
private:
	struct uf_node{ ulli p, rank, number; };
	vector<uf_node> v;
public:
	ulli sets;
	uf(ulli s):v(s), sets(s){
		FOR(i,0,s) v[i] = {ulli(i),0,1};
	}
	void link(ulli x, ulli y) {
		if(x == y) return;
		if (v[x].rank <= v[y].rank) {
			v[x].p = y; --sets;
			v[y].number += v[x].number;
			if (v[x].rank == v[y].rank) v[y].rank++;
		} else link(y, x);
	}
	ulli find_set(ulli x) {
		if (x != v[x].p) v[x].p = find_set(v[x].p);
		return v[x].p;
	}
	ulli find_length(ulli x) { //MAY NOT BE IMPORTANT
		return v[find_set(v[x].p)].number;
	}
	void union_set(ulli x, ulli y){
		link(find_set(x), find_set(y));
	}
};

int main(){
    lli n; cin >> n;
    vector<string> v(n);
    for(string &s:v) cin >> s;

    bool used[26] = {false};

    uf ufind(26);
    for(string &s:v){
        char c1 = s[0]; used[c1-'a'] = true;
        for(size_t i = 1; i < s.size(); ++i){
            ufind.union_set(c1-'a', s[i]-'a');
            used[s[i]-'a'] = true;
        }
    }
    cout << ufind.sets - count(used, used+26, false)<< endl;
    return 0;
}
