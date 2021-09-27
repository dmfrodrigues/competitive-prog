/*
ID: dmfrodr1
TASK: humble
LANG: C++11
*/

// find minimum humble number h that is strictly bigger than last humble/p
// find minimum humble number h that is strictly bigger than int(last humble/p)

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
const long INF = (1L<<31)-1;

inline bool divided(long n, const vector<long> &primes){
    FOR(i,0,primes.size()){
        long p = primes.at(i);
        while((n % p) == 0) n /= p;
        if(n == 1) return true;
    }
    return false;
}

int main(){
    ifstream fin("humble.in");
    ofstream fout("humble.out");
    
    ///INPUT
    long K, N; fin >> K >> N;
    vector<long> primes(K);
    FOR(i,0,K){
        fin >> primes[i];
    }
    sort(ALL(primes));

    ///PROCESSING
    vector<long> humble(N+1, 1);
    for(long i = 1; i < N+1; ++i){
        long nextHumble = INF;
        for(const long &p: primes){
            long h = *upper_bound(humble.begin(), humble.begin()+i, humble[i-1]/p);
            nextHumble = min(nextHumble, h*p);
        }
        humble[i] = nextHumble;
    }

    ///OUTPUT
    fout << *humble.rbegin() << endl;

    return 0;
}
