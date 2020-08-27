#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<lli,lli> PII;

map<lli,PII> m;

lli f(lli y){
    lli ret = 0;
    for(const auto &p: m){
        lli dy1 = p.second.first  - y;
        lli dy2 = p.second.second - y;
        if(dy1*dy2 >= 0) ret += 2*max(abs(dy1), abs(dy2));
        else             ret += 2*(abs(dy1)+abs(dy2));
    }
    return ret;
}

lli tersearch(lli l, lli r){
    lli l_, r_;
    while(l < r-1){
        l_ = l +   (r-l)/3;
        r_ = l + 2*(r-l)/3;
        if(f(l_) > f(r_)) l = l_+1;
        else              r = r_;
    } return l;
}

int main(){
    lli X, Y, N; cin >> X >> Y >> N;
    lli x, y;
    for(lli i = 0; i < N; ++i){
        cin >> x >> y;
        if(m.find(x) != m.end()) m[x] = PII(min(m[x].first, y), max(m[x].second, y));
        else                     m[x] = PII(y,y);
    }
    cout << f(tersearch(0, Y))+X-1 << endl;
    return 0;
}
