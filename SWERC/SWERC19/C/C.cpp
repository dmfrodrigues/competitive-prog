#include <bits/stdc++.h>
using namespace std;
typedef long long int           lli;
#define FOR(i, b, e)            for(lli i =(b); (i)  < (lli)(e); ++(i))

const lli NMAX = 1000005;

int main(){
    unordered_set<string> st;
    lli N; cin >> N;
    string s;
    FOR(i,0,N){
        cin >> s;
        st.insert(s);
    }
    FOR(i,0,NMAX){
        if(st.find(to_string(i)) == st.end()){
            cout << i << endl;
            return 0;
        }
    }
}
