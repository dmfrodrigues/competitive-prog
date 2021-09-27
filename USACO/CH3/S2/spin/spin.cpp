/*
ID: dmfrodr1
TASK: spin
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
    ifstream fin("spin.in");
    ofstream fout("spin.out");

    ///INPUT
    vector<int> v(5);
    vector<vector<bool>> w(5, vector<bool>(360, false));
    FOR(i,0,5){
        fin >> v[i];
        int N; fin >> N;
        int start, extent;
        FOR(j,0,N){
            fin >> start >> extent;
            FOR(k,start,start+extent+1){
                w[i][k%360] = true;
            }
        }
    }

    ///PROCESSING
    int res = -1;
    FOR(t,0,360){
        FOR(x,0,360){
            bool b = true;
            FOR(i,0,5){
                long dx = ((x - t*v[i])%360 + 360)%360;
                b &= w[i][dx];
            }
            if(b){
                res = t;
                break;
            }
        }
        if(res != -1) break;
    }

    ///OUTPUT
    if(res != -1) fout << res << endl;
    else fout << "none" << endl;

    return 0;
}
