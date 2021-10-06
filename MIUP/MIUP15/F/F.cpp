#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define FOR(i,b,e) for(lli (i) = (b); (i) < lli(e); ++(i))
typedef pair<lli,lli> PII;
#define X first
#define Y second

lli dist(const PII &p1, const PII &p2){
    return (p1.X-p2.X)*(p1.X-p2.X)+(p1.Y-p2.Y)*(p1.Y-p2.Y);
}

PII solve(const vector<PII> &v){
    const lli N = v.size();
    PII ret(0,0); lli d = dist(v[ret.first], v[ret.second]);
    lli j = 0;
    FOR(i,0,N){
        lli prev_d = dist(v[i], v[j]);
        while(dist(v[i], v[(j+1)%N]) >= prev_d){
            j = (j+1)%N;
            prev_d = dist(v[i], v[j]);
            if(prev_d > d){
                d = prev_d;
                ret.first = i;
                ret.second = j;
            }
        }
    }
    return ret;
}

int main(){
    int N; cin >> N;
    while(N--){
        lli K; cin >> K;
        vector<PII> v(K);
        for(PII &p:v) cin >> p.X >> p.Y;
        PII ret = solve(v);
        cout << ret.first << " " << ret.second << endl;
    }
    return 0;
}
