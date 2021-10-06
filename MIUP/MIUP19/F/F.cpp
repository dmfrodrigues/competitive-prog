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
    int N; cin >> N;
    
    uf union_find(N);

    map<string, int> names;
    map<string, int> emails;
    map<string, int> ips;

    string name, email, ip;
    FOR(i,0,N){
        cin >> name >> email >> ip;
        if(names .count(name )) union_find.union_set(i, names .at(name )); else names [name ] = i;
        if(emails.count(email)) union_find.union_set(i, emails.at(email)); else emails[email] = i;
        if(ips   .count(ip   )) union_find.union_set(i, ips   .at(ip   )); else ips   [ip   ] = i;
    }

    unordered_set<int> s;
    FOR(i,0,N) s.insert(union_find.find_set(i));

    cout << s.size() << endl;

    return 0;
}
