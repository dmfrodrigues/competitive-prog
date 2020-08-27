#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define FOR(i,b,e) for(lli (i) = (b); (i) < (e); ++(i))
typedef vector<lli> VI;

#define INF 1000

#define TMAX 26
class trie_i {
public:
    trie_i *c[TMAX] = {NULL};
    lli val = 0;
    ~trie_i(){ for(const auto &p:c) if(p) delete p; }
    template<class IT> lli insert(IT s, IT e){
        trie_i *t = this;
        while(s != e){
            if(!t->c[*s-'A']) t->c[*s-'A'] = new trie_i();
            t = t->c[*s-'A']; ++s;
        }return ++(t->val);
    }
    lli insert(const string &s){ return insert(s.begin(), s.end()); }
    template<class IT> queue<lli> prefixes(IT s, IT e){
        trie_i *t = this;
        queue<lli> ret;
        lli i = 0;
        while(s != e && t->c[*s-'A']){
            t = t->c[*s-'A'];
            ++s; ++i; if(t->val) ret.push(i);
        }
        return ret;
    }
    queue<lli> prefixes(const string &s){ return prefixes(s.begin(), s.end()); }
};

trie_i t;

lli solve(const string &s){
    const lli N = s.size();
    VI DP(N+1, INF);
    DP[0] = 0;
    FOR(i,0,N+1){
        queue<lli> q = t.prefixes(s.begin()+i, s.end());
        while(!q.empty()){
            lli j = q.front(); q.pop();
            DP[i+j] = min(DP[i+j], DP[i]+1);
        }
    }
    return DP[N];
}

int main(){
    lli P; cin >> P;
    while(P--){
        string s; cin >> s;
        t.insert(s);
    }
    lli S; cin >> S;
    while(S--){
        string s; cin >> s;
        lli ans = solve(s);
        if(ans != INF) cout << ans << endl;
        else           cout << "no" << endl;
    }
    return 0;
}
