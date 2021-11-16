/*
ID: dmfrodr1
TASK: humble
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
    long K; size_t N; fin >> K >> N;
    vector<long> primes(K);
    FOR(i,0,K){
        fin >> primes[i];
    }
    sort(primes.rbegin(), primes.rend());

    ///PROCESSING
    set<long> humble;
    humble.insert(1); N++;
    for(const long &p: primes){
        auto it = humble.begin();
        while(it != humble.end()){
            if(*it - 1 >= INF/p) break;
            humble.insert((*it) * p);
            ++it;

            if(humble.size() > N)
                humble.erase(--humble.end());
        }
    }

    ///OUTPUT
    fout << *humble.rbegin() << endl;

    return 0;
}
