/*
ID: dmfrodr1
TASK: numtri
LANG: C++11
*/
#include <bits/stdc++.h>
using namespace std;

typedef vector<long> VI;
typedef vector<VI>   VVI;

int main(){
    ///INPUT
    ifstream fin("numtri.in");
    ofstream fout("numtri.out");
    long N; fin >> N;
    VVI tri(N);
    for(long i = 0; i < N; ++i){
        tri[i] = VI(i+1);
        for(long &n:tri[i]) fin >> n;
    }
    ///PROCESSING
    VVI paths = tri;
    paths[0][0] = tri[0][0];
    for(long i = 1; i < N; ++i){
        for(long j = 0; j <= i; ++j){
            if     (j == 0) paths[i][j] = paths[i-1][j] + tri[i][j];
            else if(j == i) paths[i][j] = paths[i-1][j-1] + tri[i][j];
            else            paths[i][j] = max(paths[i-1][j-1], paths[i-1][j]) + tri[i][j];
        }
    }
    long ans = *max_element(paths[N-1].begin(), paths[N-1].end());
    ///OUTPUT
    fout << ans << endl;
    return 0;
}
