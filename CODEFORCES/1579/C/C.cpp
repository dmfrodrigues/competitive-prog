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

lli get_greatest_tick(const vector<vector<bool>> &painted, int i, int j){
    int limit = min((int)painted.size()-1, i);
    limit = min(limit, j);
    limit = min(limit, (int)painted[0].size()-j-1);
    FOR(h,0,limit+1){
        if(!painted[i-h][j-h] || !painted[i-h][j+h]){ return h-1; }
    }
    return limit;
}

int main(){
    int T; cin >> T;
    FOR(t,0,T){
        // INPUT
        int n, m, k; cin >> n >> m >> k;
        vector<vector<bool>> painted(n, vector<bool>(m, 0));
        string s;
        FOR(i,0,n){
            cin >> s;
            FOR(j,0,m){
                painted[i][j] = (s[j] == '*');
            }
        }

        // PROCESSING
        vector<vector<bool>> covered(n, vector<bool>(m, 0));
        FOR(i,0,n) FOR(j,0,m) {
            lli d = get_greatest_tick(painted, i, j);
            if(d < k) continue;
            FOR(h,0,d+1){
                covered[i-h][j-h] = true;
                covered[i-h][j+h] = true;
            }
        }

        bool yes = true;
        FOR(i,0,n) FOR(j,0,m){
            if(painted[i][j] && !covered[i][j]){ yes = false; }
        }

        // OUTPUT
        cout << (yes? "YES" : "NO") << endl;
    }

    return 0;
}
