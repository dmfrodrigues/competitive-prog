/**
 * Greedy always gets result below or equal to 2001.
 * 
 */

#include <bits/stdc++.h>
using namespace std;
#define ALL(v)                  (v).begin() , (v).end()
#define FOR(i, b, e)            for(int i =(b); (i)  < (int)(e); ++(i))
typedef vector<int>             VI;
#define X first
#define Y second
const int INF = 1000000000;

int main(){
    int T; cin >> T;
    FOR(t,0,T){
        // INPUT
        int N; cin >> N;
        VI a(N);
        FOR(i,0,N) cin >> a[i];

        // PROCESSING
        VI DP(2002, INF);
        DP[0] = 0;

        FOR(i,0,N){
            VI prev = DP;
            fill(ALL(DP), INF);
            int d = a[i];

            FOR(l,0,prev.size()){
                int r = prev[l];
                if(r >= INF) continue;

                // To the right
                int l1 = l+d;
                int r1 = max(r-d, 0);
                if(l1 < (int)DP.size() && r1 < (int)DP.size()){
                    DP[l1] = min(DP[l1], r1);
                    DP[r1] = min(DP[r1], l1);
                }

                // To the left
                int r2 = r+d;
                int l2 = max(l-d, 0);
                if(l2 < (int)DP.size() && r2 < (int)DP.size()){
                    DP[r2] = min(DP[r2], l2);
                    DP[l2] = min(DP[l2], r2);
                }
            }
        }

        int res = INF;
        FOR(i,0,DP.size())
            res = min(res, i+DP[i]);

        // OUTPUT
        cout << res << endl;
    }

    return 0;
}
