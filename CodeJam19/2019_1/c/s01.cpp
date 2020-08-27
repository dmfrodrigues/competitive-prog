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

int firstdiff(string s1, string s2){
    int ret = 0;
    while(ret < s1.size() && ret < s2.size() && s1[ret] == s2[ret])
        ++ret;
    return ret;
}

int solve(deque<string> v){
    for(auto& s:v) s = string(s.rbegin(), s.rend());
    set<string> bad;
    int ret = 0;
    while(v.size() > 1){
        int a = firstdiff(v[0], v[1]);
        if(a <= 0) v.pop_front();
        else{

        }
    }

}

int main(){
    int T; cin >> T;
    int N;
    FOR(t,0,T){
        cin >> N;
        deque<string> v(N);
        FOR(i,0,N) cin >> v[i];
        printf("Case #%d: %d\n", solve(v));
    }
    return 0;
}
