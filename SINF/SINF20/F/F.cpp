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

lli N;
vector<ulli> likes;

lli accepts(lli i, ulli taken){
    ulli a = likes[i] & (~taken);
    return __builtin_popcount(a);
}

lli solve(ulli unseated, ulli taken){
    if(unseated == 0) return 1;

    lli pickiest = -1;
    lli pickiest_num = INF;
    FOR(i,0,N){
        if(IN_SET(i, unseated)){
            lli acc = accepts(i, taken);
            if(acc < pickiest_num){
                pickiest = i;
                pickiest_num = acc;
            }
        }
    }

    lli ret = 0;

    ulli good = likes[pickiest] & (~taken);
    unseated &= (~(1 << pickiest));
    FOR(i,0,N){
        if(IN_SET(i, good)){
            ulli taken_ = ADD_SET(i, taken);
            ret += solve(unseated, taken_);
        }
    }
    return ret;
}

int main(){
    string s;
    cin >> N; getline(cin, s);
    likes = vector<ulli>(N, 0);
    FOR(i,0,N){
        getline(cin, s);
        lli j;
        stringstream ss(s);
        while(ss >> j) likes[i] = ADD_SET(j-1, likes[i]);
    }

    ulli unseated = (1<<N)-1;
    ulli taken = 0;
    lli ret = solve(unseated, taken);
    cout << ret << endl;

    return 0;
}
