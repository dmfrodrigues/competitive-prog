/*
ID: dmfrodr1
TASK: subset
LANG: C++11
*/
#include <bits/stdc++.h>
#define FOR(i,b,e) for(long long (i) = (b); (i) < (e); ++(i))
#define NMAX 45
#define SMAX NMAX*(NMAX+1)/2

using namespace std;

long long v[NMAX][SMAX];

int main(){
    ///INPUT
    ifstream fin("subset.in");
    ofstream fout("subset.out");
    long long N; fin >> N;
    ///PROCESSING
    long long S = N*(N+1)/2;
    if(S%2){ fout << 0 << endl; return 0; }
    else   { S /= 2; }

    //cout << S << endl;

    long long ret = 0;
    v[0][0] = 1;
    FOR(i,1,N+1){
        /*
        cout << "i=" << i << endl;
        cout << "  ";
        FOR(b,0,N*(N+1)/2+1)
            cout << b << " ";
        cout << endl;
        */
        /*
        FOR(a,0,N+1){
            cout << "a=" << a << " ";
            FOR(b,0,N*(N+1)/2+1)
                cout << v[a][b] << " ";
            cout << endl;
        }
        */
        FOR(j,0,i){
            FOR(k,0,SMAX-i){
                v[i][k+i] += v[j][k];
                if(k+i == S){
                    //cout << "adding v[" << j << "][" << k << "] == " << v[j][k] << endl;
                    ret += v[j][k];
                }
            }
        }
    }

    fout << ret/2 << endl;

    return 0;
}
