/*
ID: dmfrodr1
TASK: concom
LANG: C++11
*/
#include <bits/stdc++.h>
using namespace std;
#define FOR(i,b,e) for(int (i) = (b); (i) < (e); ++(i))
typedef long long int lli;
typedef pair<lli,lli> PII;

#define NMAX 105

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
};

int main(){
    ///INPUT
    ifstream fin("concom.in");
    ofstream fout("concom.out");
    int N; fin >> N;
    alGraph al(NMAX);
    set<int> comps;
    int i, j, p;
    while(N--){
        fin >> i >> j >> p;
        al.addEdge(i, j, p);
        comps.insert(i); comps.insert(j);
    }
    ///PROCESSING
    set<PII> ret;

    for(const int &i:comps){
        set<int> s;
        set<int> s_prev;

        s.insert(i);
        while(s != s_prev){
            s_prev = s;
            map<int, int> perc_control;
            for(const int &j:s){
                for(const edge &e:al[j]){
                    perc_control[e.to] += e.c;
                }
            }
            for(const PII &p:perc_control){
                if(p.second > 50){
                    s.insert(p.first);
                }
            }
        }
        for(const int &j:s){
            if(j != i) ret.insert(PII(i,j));
        }
    }
    ///OUTPUT
    for(const PII &p:ret){
        fout << p.first << " " << p.second << endl;
    }
    return 0;
}
