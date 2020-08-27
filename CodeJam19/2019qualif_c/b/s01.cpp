#include <bits/stdc++.h>
using namespace std;
typedef long long int           lli;
typedef unsigned long long int  ulli;
#define ALL(v)                  (v).begin() , (v).end()
#define contain(Set,i)          ( (Set) & (1Lu<<(i)) )
#define mk(a,b)                 make_pair((a), (b))
#define FOR(i, b, e)            for(lli i =(b); (i)  < (lli)(e); ++(i))
//#define REP(i, b, e)            for(auto i =(b); (i) != (e); ++(i))
typedef vector<lli>             VI;
typedef vector<VI>              VVI;
typedef pair< lli, lli>         PII;
typedef pair<ulli,ulli>         PUU;
typedef pair<PII,PII>           PPP;
#define X first
#define Y second
const lli INF = 1000000000;

bool goodall(const string& s, const string& t){
    int a = 0, b = 0;
    FOR(i,0,s.size()*t.size()){
        if(c == 'R' && d == 'P') return false;
        if(c == 'P' && d == 'S') return false;
        if(c == 'S' && d == 'R') return false;
        ++a; a%=s.size();
        ++b; b%=t.size();
    }
    return true;
}

bool goodfirst(const string& s, const string& t){
    int N = min(s1.size(), s2.size());
    FOR(i,0,N){
        char c = s[i], d = t[i];
        if(c == 'R' && d == 'P') return false;
        if(c == 'P' && d == 'S') return false;
        if(c == 'S' && d == 'R') return false;
    }
    return true;
}

string solve(const vector<string>& v){
    set<string> st;
    st.insert("");
    FOR(i,0,500){
        set<string> st_;
        for(const auto& s:st){
            string s1 = s + "R";
            bool b = true; for(auto t:v) if(!goodfirst(s1, t)){ b = false; break; } if(b) st_.insert(s1);
            b = true; for(auto t:v) if(!goodall(s1, t)){ b = false; break; } if(b) return s1;

            string s1 = s + "P";
            bool b = true; for(auto t:v) if(!goodfirst(s1, t)){ b = false; break; } if(b) st_.insert(s1);
            b = true; for(auto t:v) if(!goodall(s1, t)){ b = false; break; } if(b) return s1;

            string s1 = s + "S";
            bool b = true; for(auto t:v) if(!goodfirst(s1, t)){ b = false; break; } if(b) st_.insert(s1);
            b = true; for(auto t:v) if(!goodall(s1, t)){ b = false; break; } if(b) return s1;
        }
        st = st_;
    }
    return "IMPOSSIBLE";
}

int main(){
    int T; cin >> T;
    FOR(t,0,T){
        int A; cin >> A;
        vector<string> v(A);
        for(auto& s:v) cin >> s;
        string ans = "";
        ans = solve(ans, v);
    }
    return 0;
}
