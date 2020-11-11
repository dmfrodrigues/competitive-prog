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
#define IN_SET(i, set)          ((1 << (i)) & (set))
#define ADD_SET(i, set)         ((1 << (i)) | (set))

int N;
vector<ulli> likes;

vector<unordered_map<ulli, lli> > DP;

lli solve(ulli S, int k){
    if(DP[k].count(S)) return DP[k][S];
    if(S == 0) return DP[k][S] = 1;
    if(k == 0) return DP[k][S] = 0;

    lli ret = solve(S, k-1);
    ulli good = S & likes[k-1];
    FOR(i,0,N){
        if(!IN_SET(i, good)) continue;
        ulli S_ = S & (~(1<<i));
        ret += solve(S_, k-1);
    }

    return DP[k][S] = ret;
}

int main(){
    string s;
    cin >> N; getline(cin, s);
    likes = vector<ulli>(N, 0);
    DP = vector<unordered_map<ulli, lli> >(N+1, unordered_map<ulli, lli>());
    FOR(i,0,N){
        getline(cin, s);
        lli j;
        stringstream ss(s);
        while(ss >> j) likes[i] = ADD_SET(j-1, likes[i]);
    }

    ulli unseated = (1<<N)-1;
    lli ret = solve(unseated, N);
    cout << ret << endl;

    return 0;
}
