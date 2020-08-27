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
        vector<lli> v(3);
        cin >> v[0]  >> v[1] >> v[2];
        sort(ALL(v));
        lli ret = 0;


        if(v[2] >= v[0]+v[1]){
            ret = v[0]+v[1];
        }else{
            lli delta = (v[0]-v[1]+v[2])/2;
            v[0] -= delta; v[1] -= (v[2]-delta); ret += v[2]; v[2] = 0;
            ret += min(v[0], v[1]);
        }

        cout << ret << endl;

    }
    return 0;
}
