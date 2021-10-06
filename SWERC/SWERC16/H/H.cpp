#include <bits/stdc++.h>
using namespace std;
typedef long long int           lli;
typedef unsigned long long int  ulli;
#define ALL(v)                  (v).begin() , (v).end()
#define RALL(v)                 (v).rbegin() , (v).rend()
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

lli ceiling(lli a, lli b){ return a/b+(a%b ? 1 : 0); }

lli D, H;

namespace std{
    template<> struct hash<VI>{
        size_t operator()(const VI &v) const{
            size_t ret = v.size();
            for(const lli &i:v) ret ^= i + 0x9e3779b9 + (ret << 6) + (ret >> 2);
            return ret;
        }
    };
}

unordered_map<VI, lli> m;

lli f(VI v){
    sort(RALL(v));
    auto it = m.find(v);
    if(it != m.end()) return it->second;
    lli &ret = m[v]; ret = 0;
    FOR(i,0,v.size()){
        --v[i];
        if(v[i] >= 0) ret += f(v);
        ++v[i];
    }
    return ret;
}

int main(){
    cin >> D >> H;
    m[VI(D,0)] = 1;
    stack<VI> q; q.push(VI(0));
    queue<VI> selected;
    set<lli> s;

    while(!q.empty()){
        VI v = q.top(); q.pop();
        lli s = accumulate(ALL(v),0);
        if(lli(v.size()) == D){
            if(s == H-1) selected.push(v);
            continue;
        }
        lli nmin = ceiling(H-1-s, D-v.size());
        lli nmax = H-s;
        if(!v.empty()) nmax = min(nmax, v[v.size()-1]+1);

        v.push_back(0);
        FOR(n,nmin,nmax){
            v[v.size()-1] = n;
            q.push(v);
        }
    }

    set<lli> ret;
    while(!selected.empty()){
        VI v = selected.front(); selected.pop();
        lli r = f(v);
        ret.insert(r);
    }

    for(const lli &i:ret){
        cout << i << "\n";
    }
    cout << flush;

    return 0;
}
