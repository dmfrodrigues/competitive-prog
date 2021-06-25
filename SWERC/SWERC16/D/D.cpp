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

lli NUM_SIM = 1000;

int N, D, C;

VB v1, v2;

/**
 * O(D)
 */
lli simulate(){
    lli ret = 1;
    VB vb1(N,false), vb2(N,false); lli c1 = 0, c2 = 0;
    while(true){
        ulli drawn = 0;
        lli j;
        FOR(i,0,D){
            do{ j = rand()%N; }while((drawn&(1L<<j)) != 0);
            drawn |= (1uL << j);
            if(v1[j] && !vb1[j]){ vb1[j] = true; ++c1; }
            if(v2[j] && !vb2[j]){ vb2[j] = true; ++c2; }
        }
        if(c1 >= C || c2 >= C) return ret;
        ++ret;
    }
}

int main(){
    cin >> N >> D >> C;
    lli in;
    v1 = VB(N, false); FOR(i,0,C){ cin >> in; v1[in-1] = true; }
    v2 = VB(N, false); FOR(i,0,C){ cin >> in; v2[in-1] = true; }
    lli total = 0;
    lli i = 0;

    // cout << "L52" << endl;

    for(i = 0; i < NUM_SIM; ++i){ //cout << "i=" << i << endl;
        total += simulate();
        NUM_SIM = (5000000*(i+1))/(D*total);
    }

    // cout << "L59" << endl;


    cout << fixed << setprecision(5);
    cout << double(total)/double(i) << endl;
    // cout << "NUM_SIM=" << NUM_SIM << endl;
    return 0;
}
