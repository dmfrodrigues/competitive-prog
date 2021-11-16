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

class alGraph:public vector< deque<lli> >{ // Adjency List
public:
	alGraph(lli s):vector< deque<lli> >(s){}
	void addEdge(lli src, lli dst) {
		(*this)[src].push_back(dst);
	}
};

lli N, M, T;
alGraph g(0);

set<lli> cont;
vector< set<lli> > goal;

void annotate(lli n, lli r){
    if(goal[n].count(r)) return;
    if(goal[n].size() >= 2) return;
    goal[n].insert(r);
    for(const lli &u:g[n]) annotate(u, r);
}

int main(){
    cin >> N >> M >> T;
    g = alGraph(N);
    goal = vector< set<lli> >(N);
    lli a, b;
    FOR(m,0,M){
        cin >> a >> b;
        if(b == T) cont.insert(a);
        if(a == T) continue;
        g.addEdge(b, a);
    }
    for(const lli &r:cont) annotate(r, r);
    lli ans = 0;
    for(const lli &r:cont) if(goal[r].size() <= 1) ++ans;
    cout << ans << endl;
    for(const lli &r:cont) if(goal[r].size() <= 1) cout << r << endl;
    return 0;
}
