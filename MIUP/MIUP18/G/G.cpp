#include <bits/stdc++.h>
typedef long long int lli;
#define FOR(i,b,e) for(lli (i) = (b); (i) < lli(e); (i)++)

using namespace std;
typedef vector<lli> VI;

lli kadane(const VI &a) { // maximum subarray
	lli best = 0, current = 0;
	FOR(i,0,a.size()){
		current += a[i];
		current = max(current, lli(0));
        best = max(best, current);
	}
	return best;
}

int main(){
    ///INPUT
    lli N; cin >> N;
    VI s(N); for(lli &i:s) cin >> i;
    ///PROCESSING
    lli ret;
    bool all_nonpos = true;
    for(const lli &i:s) if(i > 0){ all_nonpos = false; break; }
    if(all_nonpos){
        ret = *max_element(s.begin(), s.end());
    }else{
        lli S = accumulate(s.begin(), s.end(), lli(0));
        ret = kadane(s);
        for(lli &i:s) i = -i;
        ret = max(ret, S+kadane(s));
    }
    ///OUTPUT
    cout << ret << endl;
    return 0;
}
