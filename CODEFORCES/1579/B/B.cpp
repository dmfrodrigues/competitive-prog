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

struct move_t {
    int l, r, d;
};

void rotate_right(VI &a, const move_t &m){
    lli rotated = a[m.r];
    for(lli i = m.r-1; i >= m.l; --i)
        a[i+1] = a[i];
    a[m.l] = rotated;
}

int main(){
    int T; cin >> T;
    FOR(t,0,T){
        // INPUT
        int N; cin >> N;
        VI a(N);
        FOR(i,0,N) cin >> a[i];

        // PROCESSING
        list<move_t> moves;
        FOR(i,1,N){
            int l = upper_bound(a.begin(), a.begin()+i, a[i]) - a.begin();
            int r = i;
            int d = (r-l+1)-1;
            if(l != r){
                move_t m = {l, r, d};
                rotate_right(a, m);
                moves.push_back(m);
            }
        }

        FOR(i,1,N){
            assert(a[i-1] <= a[i]);
        }

        // OUTPUT
        cout << moves.size() << endl;
        for(const move_t &m: moves){
            cout << m.l+1 << " " << m.r+1 << " " << m.d << endl;
        }
    }

    return 0;
}
