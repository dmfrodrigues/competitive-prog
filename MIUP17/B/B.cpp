#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef unsigned long long int ulli;
#define FOR(i,b,e) for(lli (i) = (b); (i) < lli(e); ++(i))

typedef vector<string> VS; typedef vector<VS> VVS;
string lcs_str(const string& X, const string& Y){
	ulli L = X.size()+1, C = Y.size()+1; if(L < C) return lcs_str(Y, X);
	VVS LCS(2, VS(C, "")); ///LCS[0][] is the previous column; LCS[1][] is the current column
	///for reasons of memory efficiency, only the previous and current column are needed.
	FOR(i, 1, L){
		FOR(j, 1, C){
			string& s = LCS[1][j];
			s = LCS[0][j-1]; if(X[i-1] == Y[j-1]) s += string(1, X[i-1]);
			if( LCS[0][j  ].size() >  s.size() ||
			   (LCS[0][j  ].size() == s.size() && LCS[0][j  ] < s)) s = LCS[0][j  ];
			if( LCS[1][j-1].size() >  s.size() ||
			   (LCS[1][j-1].size() == s.size() && LCS[1][j-1] < s)) s = LCS[1][j-1];
		}
		LCS[0] = LCS[1];
	}
	return LCS[1][C-1];
}

int main(){
	string s0, s1; cin >> s0 >> s1;
	string ans = lcs_str(s0,s1);
	cout << ans.size() << endl;
	if(ans.size() != 0)
		cout << ans << endl;
	return 0;
}
