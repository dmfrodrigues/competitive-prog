#include <bits/stdc++.h>
using namespace std;
typedef long long int           lli;
typedef unsigned long long int  ulli;
#define ALL(v)                  (v).begin() , (v).end()
#define contain(Set,i)          ( (Set) & (1Lu<<(i)) )
#define mk(a,b)                 make_pair((a), (b))
#define FOR(i, b, e)            for(lli i =(b); (i)  < (lli)(e); ++(i))
//#define REP(i, b, e)            for(auto i =(b); (i) != (e); ++(i))
typedef vector<lli>             VI;
typedef vector<VI>              VVI;
typedef pair< lli, lli>         PII;
typedef pair<ulli,ulli>         PUU;
typedef pair<PII,PII>           PPP;
#define X first
#define Y second

bool isgood(PII p1, PII p2){

    if(p1.X == p2.X ||
       p1.Y == p2.Y ||
       p1.X-p1.Y == p2.X-p2.Y ||
       p1.X+p1.Y == p2.X+p2.Y)
          return false;
    return true;
}

vector<PII> solve(int R, int C){
    const int N1 = 100;
    const int N2 = 10000;
    for(int i = 0; i < N1; ++i){
        vector<PII> s;
        vector<PII> v;
        FOR(r,1,R+1) FOR(c,1,C+1) s.push_back({r,c});
        int j = 0; bool good = false;
        while(true){ //cout << "i=" << i<<", j=" << j << endl;
            //cout << "v="; for(auto i:v) cout << "(" << i.X << "," << i.Y << ") ";
            //cout << endl;
            //cout << "s="; for(auto i:s) cout << "(" << i.X << "," << i.Y << ") ";
            //cout << endl;

            if(j >= N2) break;
            if(s.empty()){ good = true; break; }
            int n = rand()%s.size(); //cout << "rand=" << n << endl;
            auto p = s[n]; //cout << "p=" << p.X << "," << p.Y << endl;
            //if(!v.empty()) cout << "v[v.size()-1]=" << v[v.size()-1].X << "," << v[v.size()-1].Y << endl;
            if(v.empty() || isgood(p, v[v.size()-1])){
                s.erase(s.begin()+n);
                v.push_back(p);
            }
            ++j;
        }
        if(good) return v;
    }
    return vector<PII>(0);
}

int main(){
    int T; cin >> T;
    int R, C;
    FOR(t,0,T){
        cin >> R >> C;
        auto v = solve(R,C);
        if(v.empty()) printf("Case #%Ld: IMPOSSIBLE\n", t+1);
        else{
            printf("Case #%Ld: POSSIBLE\n", t+1);
            for(auto p:v) printf("%Ld %Ld\n", p.first, p.second);
        }
    }
    return 0;
}
