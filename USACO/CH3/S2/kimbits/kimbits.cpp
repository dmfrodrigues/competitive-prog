/*
ID: dmfrodr1
TASK: kimbits
LANG: C++11
*/
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

#define CMAX 60
VVI COMB(CMAX, VI(CMAX, 0));
lli combDP(lli n, lli k){
	if(COMB[n][k]) return COMB[n][k];
	k = min(k, n-k);
	if(k == 0) return COMB[n][k] = COMB[n][n-k] = 1;
	if(k == 1) return COMB[n][k] = COMB[n][n-k] = n;
	return COMB[n][k] = COMB[n][n-k] = combDP(n-1,k-1) + combDP(n-1,k);
}

lli how_many_before(lli X, lli N, lli L){
    lli res = 0;
    lli num_1s_usable = L;
    for(lli i = N-1; i >= 0; --i){
        const lli mask = (1L << i);
        if(X & mask){
            lli J = min(num_1s_usable, i);
            FOR(j, 0, J+1)
                res += combDP(i, j);
            --num_1s_usable;
        }
    }
    return res;
}

template<class F> lli binsearch(lli l, lli r, F f){
    while(r-l > 1){
        lli m = l+(r-l)/2;
        f(m) ? l = m : r = m;
    } return (f(l) ? l : -1);
}

int main(){
    ifstream fin("kimbits.in");
    ofstream fout("kimbits.out");

    ///INPUT
    lli N, L, I; fin >> N >> L >> I;

    ///PROCESSING
    lli X = binsearch(0, 1LL << N, [I, N, L](lli x){ return (I > how_many_before(x, N, L)); });
    cout << 0 << " " << (1LL << N) << endl;

    ///OUTPUT
    for(lli i = N-1; i >= 0; --i){
        fout << ((X & (1L << i)) ? 1 : 0);
    }
    fout << endl;

    return 0;
}
