#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;

#define FOR(i,n)        for (lli i = 0; i < (n); i++)

int main(){
	///Input
	lli N; cin >> N;
	vector<lli> vtr(N);
	FOR(i, N)
		cin >> vtr[i];
	///Processing
	map<lli, lli> mymap;
	for(const auto& n:vtr)
		mymap[n] = 0;
	for(const auto& n:vtr)
		++mymap[n];

	bool SinfWins = false;
	for(const auto& n:mymap){
		if(n.second % 2 == 1){
			SinfWins = true;
			break;
		}
	}
	///Output
	cout << (SinfWins? "Sinf" : "Ni") << endl;
	///
	return 0;
}

