#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define FOR(i,b,e) for(lli (i) = (b); (i) < lli(e); ++(i))
typedef vector<string> VS;
typedef vector<VS> VVS;
typedef vector<lli> VI;
typedef vector<VI> VVI;

VVS M;

lli str2num(const string &s){
	if(s=="*") return 0;
	return stoi(s);
}

lli solve(){
	const lli &H = M.size(), &W = M[0].size();
	VVI D = VVI(H, VI(W, -1));
	D[0][0] = 0;
	lli ret = 0;
	while(D[H-1][W-1] == -1){
		VVI D_p = D;
		D = VVI(H, VI(W, -1));
		FOR(h,0,H) FOR(w,0,W) if(D_p[h][w] != -1){
			if(0 <= h-1 && (M[h][w] == "*" || M[h-1][w  ] == "*")){ D[h-1][w  ] = max(D[h-1][w  ], max(D_p[h][w], str2num(M[h-1][w  ]))); }
			if(H >  h+1 && (M[h][w] == "*" || M[h+1][w  ] == "*")){ D[h+1][w  ] = max(D[h+1][w  ], max(D_p[h][w], str2num(M[h+1][w  ]))); }
			if(0 <= w-1 && (M[h][w] == "*" || M[h  ][w-1] == "*")){ D[h  ][w-1] = max(D[h  ][w-1], max(D_p[h][w], str2num(M[h  ][w-1]))); }
			if(W >  w+1 && (M[h][w] == "*" || M[h  ][w+1] == "*")){ D[h  ][w+1] = max(D[h  ][w+1], max(D_p[h][w], str2num(M[h  ][w+1]))); }
			if(D_p[h][w] > 0){
				if(0 <= h-1) D[h-1][w  ] = max(D[h-1][w  ], D_p[h][w]-1);
				if(H >  h+1) D[h+1][w  ] = max(D[h+1][w  ], D_p[h][w]-1);
				if(0 <= w-1) D[h  ][w-1] = max(D[h  ][w-1], D_p[h][w]-1);
				if(W >  w+1) D[h  ][w+1] = max(D[h  ][w+1], D_p[h][w]-1);
			}
		}
		++ret;
	}
	return ret;
}

int main(){
	int W, H; cin >> W >> H;
	M = VVS(H, VS(W));
	for(VS &v:M) for(string &s:v) cin >> s;
	cout << solve() << endl;
	return 0;
}
