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
    int N; cin >> N;
    unordered_map<lli, lli> m;
    FOR(i,0,N){
        lli D;
        cin >> D;
        m[D]++;
    }
    lli best_day = INF;
    lli best = 0;
    for(const auto &p: m){
        if(p.second > best || (p.second == best && p.first < best_day)){
            best_day = p.first;
            best = p.second;
        }
    }
    cout << best_day << endl;
    return 0;
}
