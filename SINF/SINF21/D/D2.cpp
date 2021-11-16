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

int main(){
    string S; cin >> S;
    // cout << S.size() << endl;

    vector<int> DP(S.size(), 0);
    DP[0] = (STRSET.count(S.substr(0, 1)) ? 1 : 0);
    lli i = 1;
    if(i < (lli)S.size()){
        if(STRSET.count(S.substr(i, 1))) DP[i] += DP[i-1];
        if(STRSET.count(S.substr(i-1, 2))) DP[i] += 1;
    }

    FOR(i,2,S.size()){
        if(STRSET.count(S.substr(i, 1))) DP[i] += DP[i-1];
        if(STRSET.count(S.substr(i-1, 2))) DP[i] += DP[i-2];
    }

    // FOR(i,0,S.size()) cout << DP[i] << " ";
    // cout << endl;

    cout << DP[S.size()-1] << endl;

    return 0;
}
