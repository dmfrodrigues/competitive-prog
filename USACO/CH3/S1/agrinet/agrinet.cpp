/*
ID: dmfrodr1
TASK: agrinet
LANG: C++11
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
	alGraph transpose() const{
		alGraph GT(size());
		FOR(u,0,size()) for(const edge &e:(*this)[u]) GT.addEdge(e.to, e.fr, e.c);
		return GT;
	}
};

#define ADDADJ(s) v[s] = true; for(auto e:g[s]) if(!v[e.to]) a.push(e);
lli prim(const alGraph& g, set<edge>& mst){
    lli minimum = 0;
    vector<bool> v(g.size(), false);
    priority_queue<edge, vector<edge>, greater<edge> > a;
    FOR(i,0,g.size()){
        if(v[i]){continue;} ADDADJ(i);
        while(!a.empty()){
            auto c = a.top(); a.pop();
            if(v[c.to]){continue;} ADDADJ(c.to);
            mst.insert(c); minimum += c.c;
        }
    }
	return minimum;
}

int main(){
    ifstream fin("agrinet.in");
    ofstream fout("agrinet.out");
    
    ///INPUT
    int N, c; fin >> N;
    alGraph g(N);
    FOR(i,0,N) FOR(j,0,N){
        fin >> c;
        if(i == j) continue;
        g.addEdge(i, j, c);
        cout << i << " " << j << " " << c << endl;
    }

    ///PROCESSING
    set<edge> mst;
    lli res = prim(g, mst);    

    ///OUTPUT
    fout << res << endl;

    return 0;
}
