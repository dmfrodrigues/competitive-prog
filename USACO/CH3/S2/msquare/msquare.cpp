/*
ID: dmfrodr1
TASK: msquare
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

ifstream fin("msquare.in");
ofstream fout("msquare.out");

namespace std{
    template<> struct hash<vector<int>>{
        size_t operator()(const vector<int> &v) const{
            size_t ret = v.size();
            for(const int &i:v) ret ^= i + 0x9e3779b9 + (ret<<6) + (ret>>2);
            return ret;
        }
    };
}

typedef vector<int> msquare;

msquare move_A(const msquare &s){
    return msquare({
        s[7], s[6], s[5], s[4],
        s[3], s[2], s[1], s[0]
    });
}

msquare move_B(const msquare &s){
    return msquare({
        s[3], s[0], s[1], s[2],
        s[5], s[6], s[7], s[4]
    });
}

msquare move_C(const msquare &s){
    return msquare({
        s[0], s[6], s[1], s[3],
        s[4], s[2], s[5], s[7]
    });
}

msquare revert_A(const msquare &s){
    return msquare({
        s[7], s[6], s[5], s[4],
        s[3], s[2], s[1], s[0]
    });
}

msquare revert_B(const msquare &s){
    return msquare({
        s[1], s[2], s[3], s[0],
        s[7], s[4], s[5], s[6]
    });
}

msquare revert_C(const msquare &s){
    return msquare({
        s[0], s[2], s[5], s[3],
        s[4], s[6], s[1], s[7]
    });
}

void bfs(const msquare &source, map<msquare, lli> &dist) {
    msquare s = {1,2,3,4,5,6,7,8};
    do {
        dist[s] = INF;
    } while(next_permutation(ALL(s)));

	queue<msquare> q;
	dist[source] = 0; q.push(source);
	while (!q.empty()){
		msquare cur = q.front(); q.pop();
        lli d = dist[cur]+1;
        
        msquare a = revert_A(cur); lli &da = dist[a]; if(da == INF){ da = d; q.push(a); }
        msquare b = revert_B(cur); lli &db = dist[b]; if(db == INF){ db = d; q.push(b); }
        msquare c = revert_C(cur); lli &dc = dist[c]; if(dc == INF){ dc = d; q.push(c); }
	}
}

const msquare INITIAL = {1,2,3,4,5,6,7,8};

int main(){

    ///INPUT
    msquare v(8);
    FOR(i,0,8) fin >> v[i];

    ///PROCESSING
    map<msquare, lli> dist;
    bfs(v, dist);

    msquare s = INITIAL;
    list<char> moves;
    while(s != v){
        lli d = dist[s];

        msquare a = move_A(s); lli da = dist[a];
        msquare b = move_B(s); lli db = dist[b];
        msquare c = move_C(s); lli dc = dist[c];
        
        if     (da < d){ moves.push_back('A'); s = a; }
        else if(db < d){ moves.push_back('B'); s = b; }
        else if(dc < d){ moves.push_back('C'); s = c; }
    }

    ///OUTPUT
    fout << moves.size() << endl;
    for(const char &c: moves) fout << c;
    fout << endl;

    return 0;
}
