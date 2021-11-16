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

ulli sheldon_number(ulli N, ulli M, ulli R){
    ulli ret = 0;
    FOR(i,0,R){
        ulli bit = (i%2 == 0 ? 1 : 0);
        ulli L   = (i%2 == 0 ? N : M);
        while(L > 0){
            ret = (ret << 1L) | bit;
            --L;
        }
    }
    return ret;
}

const ulli LMAX = 64;
const ulli NMAX = LMAX;
const ulli MMAX = LMAX;
const ulli RMAX = LMAX;
set<ulli> nums;
void init_numbers(){
    FOR(N,1,NMAX+1) FOR(M,1,MMAX+1) FOR(R,1,RMAX+1){
        ulli L = (R/2)*(N+M)+(R%2 ? N : 0);
        if(L <= LMAX) nums.insert(sheldon_number(N, M, R));
    }
}

// counts # of sheldon numbers that are less than N
ulli count_sheldon(ulli N){
    ulli ret = 0;
    for(const ulli &i: nums) if(i < N) ++ret;
    return ret;
}

int main(){
    init_numbers();
    ulli A, B; cin >> A >> B;
    cout << count_sheldon(B+1) - count_sheldon(A) << endl;
    return 0;
}
