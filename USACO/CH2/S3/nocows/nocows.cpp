/*
ID: dmfrodr1
TASK: nocows
LANG: C++11
*/
#include <bits/stdc++.h>
#define FOR(i,b,e) for(long (i) = (b); (i) < (e); ++(i))

using namespace std;

#define NMAX 202
#define KMAX 102
#define MOD  9901

long POW2(long i){
    i = min(i, 10L);
    return (1L<<i);
}

bool b[NMAX][KMAX] = {false};
long v[NMAX][KMAX] = {0};

long f(long N, long K){
    //cout << N << " " << K << endl;
    if(b[N][K]) return v[N][K];
    long r = 0;
    //cout << (N%2==1) << endl;
    //cout << (2*K-1 <= N) << endl;
    //cout << (N <= POW2(K)-1) << endl;
    if(N==1 && K==1){
        r = 1;
    }else if((N%2==1) && (2*K-1 <= N) && (N <= POW2(K)-1)){
        for(long n = 1; n <= N-1; n += 2){
            long lef1 = f(n,K-1);
            long rig1 = 0;
            for(long k = 1; k <= K-2; ++k){
                rig1 = (rig1+f(N-1-n, k))%MOD;
            }
            rig1 = (2L*rig1           )%MOD;
            rig1 = (rig1+f(N-1-n, K-1))%MOD;
            r    = (r+lef1*rig1       )%MOD;
        }
    }
    r = r%MOD;
    v[N][K] = r;
    b[N][K] = true;
    return r;
}

int main(){
    ///INPUT
    ifstream fin("nocows.in");
    ofstream fout("nocows.out");
    long N,K; fin >> N >> K;
    ///PROCESSING
    fout << f(N,K) << endl;
    /*
    for(int k = 0; k < 4; ++k){
        for(int n = 0; n < 6; ++n){
            cout << v[n][k] << " ";
        }
        cout << endl;
    }
    */
    return 0;
}
