#include <bits/stdc++.h>
#define ALL(v)                  (v).begin() , (v).end()
#define FOR(i, n)               for(long i = 0 ; (i)  < (n); ++(i))
#define REP(i, b, e)            for(auto i =(b); (i) != (e); ++(i))
#define NUMT long
#define MAXN    100005

using namespace std;

deque<NUMT> even, odd;
deque<NUMT> v;

NUMT solve(){
    sort(ALL(even));
    sort(ALL(odd ));

    //cerr << "even: "; for(auto i:even) cerr << i << " "; cerr << endl;
    //cerr << "odd : "; for(auto i:odd ) cerr << i << " "; cerr << endl;

    v.clear();

    while(!even.empty() || !odd.empty()){
        if(!even.empty()){ v.push_back(even.front()); even.pop_front(); }
        if(!odd .empty()){ v.push_back(odd .front()); odd .pop_front(); }
    }

    //cerr << "v: "; for(auto i:v ) cerr << i << " "; cerr << endl;

    for(long i = 0; i < v.size()-1; ++i){
        //cerr << "i=" << i << endl;
        if(v[i] > v[i+1]){
            //cerr << "v[i]=" << v[i] << ", v[i+1]=" << v[i+1] << endl;
            return i;
        }
    }

    return -1;
}

int main(){
    unsigned T; cin >> T;
    FOR(t, T){
        NUMT N; cin >> N;
        even.resize(N/2+N%2); odd.resize(N/2);
        FOR(i,N){
            if(i%2 == 0) cin >> even[i/2];
            else         cin >> odd [i/2];
        }
        NUMT ans = solve();
        cout << "Case #" << t+1 << ": ";
        if(ans == -1) cout << "OK" << endl;
        else          cout << ans  << endl;
    }
    return 0;
}
