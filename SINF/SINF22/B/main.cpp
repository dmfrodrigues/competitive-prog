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

string solve(string s){
    // cout << "solve " << s << endl;
    if(s.empty()) return s;
    stringstream ss;
    int l = 0;
    while(l < (lli)s.size()){
        if('a' <= s[l] && s[l] <= 'z') ss << s[l++];
        else if(('0' <= s[l] && s[l] <= '9') || s[l] == '['){
            lli n = 0;
            while(l < (lli)s.size() && '0' <= s[l] && s[l] <= '9'){
                n = 10*n + (s[l] - '0');
                ++l;
            }
            n = max(n, 1LL);
            assert(s[l] == '[');

            int counter = 1;
            int j = l+1;
            while(j < (lli)s.size() && counter > 0){
                if(s[j] == '[') ++counter;
                if(s[j] == ']') --counter;
                ++j;
            }
            assert(counter == 0);
            assert(s[j-1] == ']');

            const string &s1 = solve(s.substr(l+1, (j-1)-(l+1)));
            for(int k = 0; k < n; ++k){
                ss << s1;
            }

            l = j;
        }

        // cout << "Solution of " << s.substr(l, r-l) << " is " << ss.str() << endl;
    }
    return ss.str();
}

int main(){
    string s; cin >> s;
    cout << solve(s) << endl;
    return 0;
}
