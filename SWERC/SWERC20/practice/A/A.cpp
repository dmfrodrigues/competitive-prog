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

int main(){
    // INPUT
    lli N, K; cin >> N >> K;
    VI v(N);
    FOR(i,0,N) cin >> v[i];
    sort(ALL(v));

    // PROCESS
    // first element is total weight
    // size_t is the index of the weight that was used to come up with it
    unordered_map<lli, size_t> s;
    lli W = 1000;
    while(s.size() < K){
        s = unordered_map<lli, size_t>();
        s[0] = -1;
        FOR(i,0,N){
            lli c = v[i];
            unordered_map<lli, size_t> s_prev = s;
            for(const pair<lli, size_t> &p: s_prev){
                lli w = p.first+c;
                if(w > W) continue;
                if(!s.count(w)){
                    s[w] = i;
                }
            }
        }
        W *= 2;
    }

    // OUTPUT
    map<lli, size_t> s_ord(ALL(s));
    size_t i = 0;
    vector<lli> l; l.reserve(N);
    for(const pair<lli, size_t> &p: s_ord){
        if(i >= K) break;
        lli w = p.first;
        cout << w << ":";
        l.resize(0);
        while(w > 0){
            size_t prev = s[w];
            l.push_back(v[prev]);
            w -= v[prev];
        }
        sort(ALL(l));
        for(const lli &vi: l) cout << " " << vi;
        cout << "\n";
        ++i;
    }

    return 0;
}
