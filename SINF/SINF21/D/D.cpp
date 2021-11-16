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

const unordered_set<string> STRSET = {
    "1",
    "2",
    "3",
    "4",
    "5",
    "6",
    "7",
    "8",
    "9",
    "10",
    "11",
    "12",
    "13",
    "14",
    "15",
    "16",
    "17",
    "18",
    "19",
    "20",
    "21",
    "22",
    "23",
    "24",
    "25",
    "26"
};

unordered_map<lli, lli> DP;

string S;

lli solve(const lli &i){
    if(DP.count(i)) return DP[i];
    if(i <= 0) return DP[0] = 1;
    if(i == 1) return DP[1] = (STRSET.count(S.substr(0,1)) ? 1 : 0);
    lli sol = 0;
    string seq;
    seq = S.substr(i-1, 1); if(STRSET.count(seq)) sol += solve(i-1);
    seq = S.substr(i-2, 2); if(STRSET.count(seq)) sol += solve(i-2);
    DP[i] = sol;
    return sol;
}

int main(){
    cin >> S;
    // cout << S.size() << endl;

    cout << solve(S.size()) << endl;

    return 0;
}
