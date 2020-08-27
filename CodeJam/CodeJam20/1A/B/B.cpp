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
#define POW(i) (1L << (i))

bool possible(lli N, lli R){
    if(N > POW(R)-1) return false;
    
    set<lli> swipe; 
    
    N = N - R + 1 - POW(R-1); //go to row R and swipe it
    swipe.insert(R);

    if(N < 0) return false;

    for(lli r = 1; r < R; r++){
        if((N+1)&POW(r-1)){ //if we add a 1, we see we can swipe row r
            N += 1; //add a 1
            N -= POW(r-1); //swipe r;
            swipe.insert(r);
        }
    }

    if(N == 0){
        
        for(const auto &i:swipe){
            cout << "SWIPED " << i << endl;;
        }
        cout << "NON-SWIPED: " << R-swipe.size() << " ROWS" << endl;

        return true;
    } else return false;

}

void solve(lli N){
    for(lli r = 1; r < 32; ++r){
        if(possible(N, r)){
            return;
        } else{
            cout << "solve, r=" << r << " failed" << endl;
        }
    }
}

int main(){
    lli T; cin >> T;
    FOR(t,0,T){
        lli N; cin >> N;
        solve(N);
    }
    return 0;
}
