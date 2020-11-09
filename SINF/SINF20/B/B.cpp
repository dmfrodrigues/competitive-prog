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
    VI v;
    lli R1, R3, R7;
    {
        lli x;
        while(cin >> x){
            v.push_back(x);
        }
        const auto &N = v.size();
        R1 = v[N-3];
        R3 = v[N-2];
        R7 = v[N-1];
        v.pop_back();
        v.pop_back();
        v.pop_back();
    }
    const auto &N = v.size();
    
    VI DP(N, INF);
    DP[0] = min(min(R1, R3), R7);
    FOR(i,1,N){
        const auto &d = v[i];
        // Option 1: all days in [d, d+1)
        lli i1 = lower_bound(ALL(v), d)-v.begin(); //first day covered by our new hire
        lli c1 = (i1-1 < 0 ? 0 : DP[i1-1]) + R1;
        DP[i] = min(DP[i], c1);
        // Option 3: all days in [d-2, d+1)
        lli i3 = lower_bound(ALL(v), d-2)-v.begin(); //first day covered by our new hire
        lli c3 = (i3-1 < 0 ? 0 : DP[i3-1]) + R3;
        DP[i] = min(DP[i], c3);
        // Option 7: all days in [d-6, d+1)
        lli i7 = lower_bound(ALL(v), d-6)-v.begin(); //first day covered by our new hire
        lli c7 = (i7-1 < 0 ? 0 : DP[i7-1]) + R7;
        DP[i] = min(DP[i], c7);
        // cout << i1 << "," << c1 << " " << i3 << "," << c3 << " " << i7 << "," << c7 << endl;
    }

    // for(const auto &i: DP) cout << i << " ";
    // cout << endl;

    cout << DP[N-1] << endl;

    return 0;
}
