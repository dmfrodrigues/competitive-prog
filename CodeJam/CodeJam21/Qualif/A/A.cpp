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

size_t Reversort(VI &L){
    size_t ret = 0;
    FOR(idx, 0, L.size()-1){
        auto i = L.begin() + idx;
        auto j = min_element(i, L.end())+1;
        reverse(i, j);
        ret += (j - i);
    }
    return ret;
}

int main(){
    int T; cin >> T;
    FOR(t,0,T){
        int N; cin >> N;
        VI v(N);
        for(auto &i: v) cin >> i;
        cout << "Case #" << t+1 << ": " << Reversort(v) << endl;
    }

    return 0;
}
