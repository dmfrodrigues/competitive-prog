#include <bits/stdc++.h>
using namespace std;
typedef long long int           lli;
#define FOR(i, b, e)            for(lli i =(b); (i)  < (lli)(e); ++(i))

int main(){
    unordered_map<string, lli> m;
    lli N; cin >> N;
    string s;
    FOR(i,0,N){
        cin >> s;
        ++m[s];
        if(m[s]*2 > N){
            cout << s << endl;
            return 0;
        }
    }
    cout << "NONE" << endl;
    return 0;
}
