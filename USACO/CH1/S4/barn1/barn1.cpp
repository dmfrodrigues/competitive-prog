/*
ID: dmfrodr1
TASK: barn1
LANG: C++11
*/
#include <bits/stdc++.h>
#define MAXC 205
using namespace std;

int M, S, C;
int x[MAXC];

int main(){
    ifstream fin("barn1.in");
    ofstream fout("barn1.out");

    fin >> M >> S >> C;
    for(int i = 0; i < C; ++i) fin >> x[i];
    sort(x, x+C);

    int d[MAXC];
    for(int i = 0; i < C-1; ++i)
        d[i] = -(x[i+1]-x[i]-1);
    sort(d, d+C-1);

    int ans = x[C-1]-x[0]+1;

    int i = 0;
    --M;
    while(M && i < C-1){
        ans -= -d[i++];
        --M;
    }
    fout << ans << endl;


    return 0;
}
