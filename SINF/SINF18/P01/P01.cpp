#include <bits/stdc++.h>

using namespace std;
#define FOR(i,n)        for (int i = 0; i < (n); i++)

int main(){
	int N; cin >> N;
	int ans = 0, tmp;
	FOR(i, N){
		cin >> tmp;
		ans += tmp;
	}
	cout << ans << endl;
	return 0;
}
