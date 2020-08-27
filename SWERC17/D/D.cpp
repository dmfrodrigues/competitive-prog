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

#define	NEXT()	L = i; while (R<n && str[R-L] == str[R]) R++; Z[i] = R-L; R--;
VI z_arr(const string& str){
	lli n = str.length(), L = 0, R = 0, k; VI Z(n);
	FOR(i,1,n){
		if(i > R){ R = NEXT() }
		else{ k = i-L; if(Z[k] < R-i+1) Z[i] = Z[k]; else { NEXT() } }
	} return Z;
}
VI zsearch(string text, string pattern) {
	string concat = pattern + "$" + text;
	VI Z = z_arr(concat); VI ret;
	FOR(i, 0, concat.size()) if (Z[i] == (lli)pattern.size()) ret.push_back(i-pattern.size()-1);
	return ret;
}

int main(){
    /// INPUT
    string chain; cin >> chain;
    const lli N = chain.size();
    lli C; cin >> C;
    vector<string> pref(2*C); VI P(2*C);
    FOR(i,0,C){ cin >> pref[i] >> P[i]; pref[i+C] = string(pref[i].rbegin(), pref[i].rend()); P[i+C] = P[i]; }
    /// PROCESSING
    vector< vector<bool> > starts(2*C, vector<bool>(N, false));
    FOR(c,0,2*C){
        VI v = zsearch(chain, pref[c]);
        for(const lli &n:v) starts[c][n] = true;
    }


    VI DP(N, 0);

    FOR(c,0,2*C){
        if(starts[c][0]){
            lli newn = pref[c].size();
            DP[newn] = max(DP[newn], DP[0]+P[c]);
        }
    }

    FOR(n,0,N){
        if(n > 0) DP[n] = max(DP[n], DP[n-1]);
        FOR(c,0,2*C){
            if(starts[c][n]){
                lli newn = n+pref[c].size();
                DP[newn] = max(DP[newn], DP[n]+P[c]);
            }
        }
    }

    cout << DP[N-1] << endl;
    return 0;
}
