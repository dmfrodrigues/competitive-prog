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
const int TMAX = 10010;

int main(){
    vector<int> v(TMAX, -1);
    int N; cin >> N;
    int Sm, Em;
    FOR(i,0,N){
        cin >> Sm >> Em;
        v[Sm] = max(v[Sm], Em);
    }

    int sol = 0;
    int l = -1, r = -1;
    FOR(i,0,TMAX){
        if(l == -1){
            if(v[i] != -1){
                l = i;
                r = v[i];
            }
        } else {
            r = max(r, v[i]);
        }
        if(i == r){
            sol += 1;
            l = -1;
            r = -1;
        }
    }

    cout << sol << endl;

    return 0;
}
