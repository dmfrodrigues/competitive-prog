/*
ID: dmfrodr1
TASK: sort3
LANG: C++11
*/
#include <bits/stdc++.h>
using namespace std;
#define FOR(i,b,e) for(int (i) = (b); (i) < (e); ++(i))

typedef vector<int> VI;

int solve(const VI &v){
    int N = v.size();
    int count[4] = {0};{
        for(const int &i:v) ++count[i];
    }
    partial_sum(count,count+4,count);
    int c[4][4] = {0}; //there are c[interval][val] elements equal to val in that interval

    for(int interval = 1; interval <= 3; ++interval){
        for(int i = count[interval-1]; i < count[interval]; ++i){
            ++c[interval][v[i]];
        }
    }
    int ret = 0;

    FOR(r,0,N) FOR(i,1,4) FOR(j,i+1,4){ //o numero q nao i ou j fica melhor
        FOR(r,0,3) FOR(i_,1,4) FOR(j_,i_+1,4){
            int n = min(c[i_][j_], c[j_][i_]);
            c[i_][j_] -= n; c[i_][i_] += n;
            c[j_][j_] += n; c[j_][i_] -= n;
            ret += n;
        }
        int k = 6-i-j;
        int n = min(c[i][k], c[k][3]);
        c[i][k] -= n; c[k][k] += n;
        c[i][j] += n; c[k][j] -= n;
        ret += n;
    }
    return ret;
}

int main(){
    ///INPUT
    ifstream fin("sort3.in");
    ofstream fout("sort3.out");
    int N; fin >> N;
    VI v(N);
    for(int &i:v) fin >> i;
    fout << solve(v) << endl;
    return 0;
}
