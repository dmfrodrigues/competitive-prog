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

VVI DP(101, VI(101, -1));

string S;

lli solve(int l, int r){
    // cout << "l,r=" << l << "," << r << endl;
    if(r-l <= 0) return 1;
    if(r-l == 1) return (STRSET.count(S.substr(l, 1)));
    if(DP[l][r] != -1) return DP[l][r];
    lli sol = 0;
    lli m = l + (r-l)/2;
    lli lsol = solve(l, m);
    lli rsol = solve(m, r);
    sol += lsol*rsol;
    if(m+1 >= 0 && m < r){
        string seq = S.substr(m-1, 2);
        if(STRSET.count(seq)){
            lsol = solve(l, m-1);
            rsol = solve(m+1, r);
            sol += lsol*rsol;
        }
    }
    DP[l][r] = sol;
    return sol;
}

int main(){
    cin >> S;

    cout << solve(0, S.size()) << endl;

    return 0;
}
