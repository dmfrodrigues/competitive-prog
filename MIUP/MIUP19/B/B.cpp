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

lli X0;
lli a, b, m;
lli getRandom(){
    X0 = (a*X0 +b) % m;
    return X0;
}

lli Dl, Dh;
lli getDistance(){
    lli x = getRandom() % lli(Dh-Dl+1);
    return Dl + x;
}

int main(){
    lli E, j, p, l;
    cin >> Dl >> Dh >> X0 >> a >> b >> m >> E >> j >> p >> l;
    string terrain;
    cin >> terrain;

    lli pos = 0, dist = 0, Ec = 0;
    while(E > 0 && pos != l){
        lli d = getDistance();
        if(terrain[pos] == 'D') d = -d;
        lli newpos = max(min(pos+d, l), 0LL);

        if(E >= j){ // Make jump
            //cout << "(" << E << ") " << (newpos-pos>0 ? "+" : "") << newpos-pos << " to " << newpos << " ";
            Ec += j; E -= j;
            dist += abs(newpos-pos); pos = newpos;

            if(terrain[pos] == 'P'){ E += p; terrain[pos] = '.'; }
        } else { // Can't make jump
            Ec += E; E -= E;
        }
    }
    //cout << endl;

    cout << dist << endl;
    cout << Ec << endl;
    cout << (pos == l ? "yes" : "no") << endl;

    // cout << pos << " " << E << endl;

    return 0;
}
