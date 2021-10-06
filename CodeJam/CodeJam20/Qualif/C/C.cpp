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

#define MAXN 10000

struct event{
    int l, r, i;
    bool operator<(const event &e) const{
        if     (l != e.l) return (l < e.l);
        else if(r != e.r) return (r < e.r);
        else              return (i < e.i);
    }
};

string solve(vector<event> v){
    sort(ALL(v));
    string s(v.size(), ' ');
    int goodC = 0, goodJ = 0;
    FOR(j,0,v.size()){
        if     (goodC <= v[j].l){ s[v[j].i] = 'C'; goodC = v[j].r; }
        else if(goodJ <= v[j].l){ s[v[j].i] = 'J'; goodJ = v[j].r; }
        else return "IMPOSSIBLE";
    }
    return s;
}

int main(){
    lli T; cin >> T;
    FOR(t,0,T){
        int N; cin >> N;
        vector<event> v(N);
        FOR(i,0,N){
            cin >> v[i].l >> v[i].r;
            v[i].i = i;
        }
        string sol = solve(v);
        cout << "Case #" << t+1 << ": " << sol << "\n";
    }
    cout << flush;
    return 0;
}
