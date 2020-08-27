#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

struct TRIPLE{
    vector<lli> v;
    TRIPLE(lli t, lli x, lli y):v({t,x,y}){}
    bool operator<(const TRIPLE &obj)const{
        return (v < obj.v);
    }
};

int main(){
    lli B, O; cin >> B >> O;
    vector< deque<TRIPLE> > birds(B);
    lli b, t, x, y;
    while(O--){
        cin >> b >> t >> x >> y;
        birds[b].push_back(TRIPLE(t,x,y));
    }
    lli T; cin >> T;
    while(T--){
        lli N; cin >> N;
        map<TRIPLE, lli> m;
        lli b;
        for(lli i = 0; i < N; ++i){
            cin >> b;
            for(const TRIPLE &tr:birds[b]) ++m[tr];
        }
        lli ret = 0;
        for(const auto &p:m) if(p.second >= N) ++ret;
        cout << ret << endl;
    }
    return 0;
}
