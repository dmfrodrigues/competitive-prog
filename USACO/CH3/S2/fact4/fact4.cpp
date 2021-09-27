/*
ID: dmfrodr1
TASK: fact4
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

int main(){
    ifstream fin("fact4.in");
    ofstream fout("fact4.out");
    
    ///INPUT
    int N; fin >> N;

    ///PROCESSING
    vector<int> v(N+1, 0);
    FOR(i,2,N+1){
        long n = i;
        FOR(j, 2, N+1){
            while(n > 0 && n % j == 0){
                v[j]++;
                n /= j;
            }
        }
    }

    if(5 < v.size()){
        long m1 = min(v[2], v[5]);
        v[2] -= m1;
        v[5] -= m1;
    }

    int res = 1;
    FOR(i,2,N+1){
        FOR(j, 0, v[i]){
            res = (res*i)%10;
        }
    }

    ///OUTPUT
    fout << res << endl;

    return 0;
}
