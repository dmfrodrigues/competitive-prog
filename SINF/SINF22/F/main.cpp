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

bool left_turn(PII a, PII b, PII c) {
    return (a.X-c.X)*(b.Y-c.Y) >= (a.Y-c.Y)*(b.X-c.X);
}
vector<PII> convex_hull(vector<PII> S) {
    sort(S.begin(), S.end());
    vector<PII> top, bot; lli t = 0, b = 0;
    for(const auto& p : S){
        while(t>=2 && !left_turn(p,top[t-1],top[t-2])){ top.pop_back();t--; }
        top.push_back(p); t++;
        while(b>=2 && !left_turn(bot[b-2],bot[b-1],p)){ bot.pop_back();b--; }
        bot.push_back(p); b++;
    } S.clear();
    S.insert(S.end(), top. begin(), top. end()-1);
    S.insert(S.end(), bot.rbegin(), bot.rend()-1);
    return S;
}

int main(){
    lli N; cin >> N;
    vector<PII> v(N);
    FOR(i,0,N) cin >> v[i].X >> v[i].Y;

    auto sol = convex_hull(v);

    set<PII> s(sol.begin(), sol.end());
    for(const PII &p: s){
        cout << p.X << " " << p.Y << endl;
    }

    return 0;
}
