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

void solve(const vector<lli> &p, const vector<lli> &val2idx, vector<bool> &left){
    lli ignore_from = p.size();
    for(lli num = 0; num < val2idx.size(); ++num){
        lli idx = val2idx[num];
        if(idx < ignore_from) {
            left[idx] = true;
            ignore_from = idx;
        }
    }
}

int main(){
    int T; cin >> T;
    list<lli> d;
    FOR(t,0,T){
        // INPUT
        lli N; cin >> N;
        VI p(N);
        FOR(i,0,N) { cin >> p[i]; --p[i]; }

        // PROCESSING
        VI val2idx(N);
        FOR(i,0,N){
            val2idx[p[i]] = i;
        }
        vector<bool> left(N, false);
        
        solve(p, val2idx, left);
        
        
        FOR(i,0,N){
            bool b = left.at(i);
            if(b){ d.push_front(p.at(i)); }
            else { d.push_back(p.at(i));  }
        }

        // OUTPUT
        bool first = true;
        while(!d.empty()){
            lli x = d.front(); d.pop_front();
            if(!first) cout << " ";
            cout << x + 1;
            first = false;
        }
        cout << endl;
    }

    return 0;
}
