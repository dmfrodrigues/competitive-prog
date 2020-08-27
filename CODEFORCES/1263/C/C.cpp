#include <bits/stdc++.h>
using namespace std;
typedef long long int           lli;
typedef unsigned long long int  ulli;
#define ALL(v)                  (v).begin() , (v).end()
#define contain(Set,i)          ( (Set) & (1Lu<<(i)) )
#define mk(a,b)                 make_pair((a), (b))
#define FOR(i, b, e)            for(lli i =(b); (i)  < (lli)(e); ++(i))
//#define REP(i, b, e)            for(auto i =(b); (i) != (e); ++(i))
typedef vector<lli>             VI;
typedef vector<VI>              VVI;
typedef pair< lli, lli>         PII;
typedef pair<ulli,ulli>         PUU;
typedef pair<PII,PII>           PPP;
#define X first
#define Y second
const lli INF = 1000000000;

int main(){
    lli t; cin >> t;
    while(t--){
        lli n; cin >> n;
        queue<lli> ret; ret.push(0);
        lli k = n;
        while(k > 0){
            lli r = n/k;
            //printf("L26,k=%d,n=%d,r=%d\n", k,n,r);
            ret.push(r);
            k = n/(r+1);
        }
        cout << ret.size() << endl;
        while(!ret.empty()){
            cout << ret.front() << " ";
            ret.pop();
        }
        cout << endl;
    }
    return 0;
}
