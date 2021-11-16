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

int time2int(const string &s){
    int h = stoi(s.substr(0, 2));
    int m = stoi(s.substr(3, 2));
    return h*60 + m;
}

int main(){
    string Ts_str, Te_str;
    int C;
    cin >> Ts_str >> Te_str >> C;
    int Ts = time2int(Ts_str);
    int Te = time2int(Te_str);
    int S; cin >> S;
    FOR(i,0,S){
        int A; cin >> A;
        vector<pair<int,int>> a;
        string Tj_str, Tk_str;
        int Tj, Tk;
        int D;
        FOR(j,0,A){
            cin >> Tj_str >> Tk_str >> D;
            Tj = time2int(Tj_str);
            Tk = time2int(Tk_str);
            Tj -= D;
            Tk += D;
            a.push_back(make_pair(Tj, Tk));
        }
        sort(ALL(a));
        
        bool alibi = true;

        int X, Y;

        // At beginning
        X = Ts;
        Y = min(Te, a[0].first);
        if(Y-X >= C) alibi = false;

        // At end
        X = max(Ts, a[A-1].second);
        Y = Te;
        if(Y-X >= C) alibi = false;

        // At middle
        FOR(i,0,A-1){
            X = max(Ts, a[i].second);
            Y = min(Te, a[i+1].first);
            if(Y-X >= C) alibi = false;
        }

        cout << (alibi ? "yes" : "no") << endl;
    }

    return 0;
}
