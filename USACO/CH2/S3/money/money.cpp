/*
ID: dmfrodr1
TASK: money
LANG: C++11
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef vector<lli> VI;
typedef vector<VI> VVI;
typedef vector<bool> VB;
typedef vector<VB> VVB;
#define FOR(i,b,e) for(long (i) = (b); (i) < (e); ++(i))

#define NMAX 10002
#define VMAX 27

VVB b(NMAX, VB(VMAX, false));
VVI w(NMAX, VI(VMAX,     0));

VI vtr;

void fill_initials(lli N){
    ///INITIAL
    w[0][0] = 1; b[0][0] = 1;
    /** I==1 */{
        lli v = vtr[0];
        FOR(n,0,NMAX){
            w[n][1] = ( n%v ? 0 : 1 );
            b[n][1] = true;
        }
    }
}

lli f(lli N, lli I){
    if(b[N][I]) return w[N][I];

    lli r = 0;
    lli v = vtr[I-1];

    //for(lli n = 0; n <= N/v; ++n) r += f(N%v+n*v, I-1);
    r = f(N,I-1); if(N-v >= 0) r += f(N-v,I);

    w[N][I] = r;
    b[N][I] = true;
    return r;

}

int main(){
    ///INPUT
    ifstream fin("money.in");
    ofstream fout("money.out");
    lli V, N;
    fin >> V >> N;
    vtr = VI(V);
    for(lli &i:vtr) fin >> i;
    sort(vtr.begin(), vtr.end());
    ///PROCESSING
    fill_initials(N);
    fout << f(N,V) << endl;
    return 0;
}
