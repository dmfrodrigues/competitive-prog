//O(N²+L[N*N])

#include <bits/stdc++.h>

using namespace std;
//typedef long long int lli;
#define ALL(v)          (v).begin() , (v).end()
#define FOR(i,n)        for (int i = 0; i < (n); i++)
#define REP(i, b, e)    for (int i=b; i!=e; ++i)

int z_arr(const string& str){ 
	int n = str.length();
	vector<int> Z(n);
	int L = 0, R = 0, k;
	REP(i,1,n){
		if(i > R){ 
			L = R = i; 
			while (R<n && str[R-L] == str[R]) 
				R++; 
			Z[i] = R-L; 
			R--; 
		}else{
			k = i-L;
			if(Z[k] < R-i+1){ 
				Z[i] = Z[k]; 
			}else{ 
				L = i; 
				while(R<n && str[R-L] == str[R]) 
					R++; 
				Z[i] = R-L; 
				R--; 
			} 
		} 
	}
	return *max_element(ALL(Z)); 
}

string solve(vector<string> strs){
	int N = strs.size();

	vector<string> prefixes;{
		const string& s = strs[0];
		prefixes = vector<string>(s.size());
		FOR(i, (int)s.size()){
			prefixes[i] = string(s, i);
		}
	}

	unsigned int new_sz;

	string best_str;{
		string& pref = prefixes[0];
		FOR(i, N){
			new_sz = z_arr(pref + "$" + strs[i]);
			pref = string(pref, 0, new_sz);
		}
		best_str = pref;
	}

	for(auto& pref:prefixes){ ///prefixo i
		for(const auto& s:strs){
			new_sz = z_arr(pref + "$" + s);
			pref = string(pref, 0, new_sz);
			if(new_sz <= best_str.size()){
				break;
			}
		}
		if(pref.size() > best_str.size()){
			best_str = pref;
		}
	}
	return best_str;
}

int main(){
	int N, L; cin >> N >> L;
	vector<string> mystrs(N);
	for(auto& s:mystrs){
		cin >> s;
	}
	string ans = solve(mystrs);
	cout << ans << endl;
	return 0;
}
