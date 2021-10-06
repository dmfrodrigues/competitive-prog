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

int main(){
    int T; cin >> T;
    FOR(t,0,T){
        // INPUT
        int N; cin >> N;
        VI a(N);
        FOR(i,0,N) cin >> a[i];

        // PROCESSING
        list<PII> lst;

        lli max_idx = max_element(ALL(a)) - a.begin();
        lli total = accumulate(ALL(a), 0LL);
        total -= a[max_idx];
        lli l = 0, r = N-1;
        while(l < r && a[l] <= 0) ++l;
        while(l < r && a[r] <= 0) --r;
        while(l < r && total > a[max_idx]){

            if(l == max_idx) ++l;
            else if(r == max_idx) --r;
            else {
                if(a[l] > 0 && a[r] > 0){
                    --a[l];
                    --a[r];
                    total -= 2;
                    lst.push_back({l, r});
                }

                if(total <= a[max_idx]){
                    break;
                }
            }

            if(a[l] <= 0) ++l;
            if(a[r] <= 0) --r;
        }

        FOR(i,l,r+1){
            if(i == max_idx) continue;
            while(a[max_idx] > 0 && a[i] > 0){
                --a[max_idx];
                --a[i];
                --total;
                lst.push_back({max_idx, i});
            }
        }

        cout << lst.size() << "\n";
        for(const PII &p: lst){
            cout << p.first+1 << " " << p.second+1 << "\n";
        }

        cout << flush;

        // OUTPUT
    }

    return 0;
}
