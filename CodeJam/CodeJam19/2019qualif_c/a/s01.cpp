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
    //lli N = max(s.size(), t.size())+10;
    FOR(i,0,1000000){
        char c = s[a], d = t[b];
        if(c == 'R' && d == 'P') return false;
        if(c == 'P' && d == 'S') return false;
        if(c == 'S' && d == 'R') return false;
        if(d == 'R' && c == 'P') return true;
        if(d == 'P' && c == 'S') return true;
        if(d == 'S' && c == 'R') return true;
        ++a; a%=s.size();
        ++b; b%=t.size();
    }
    return false;
}

bool goodfirst(const string& s, const string& t){
    int a = 0, b = 0;
    lli N = min(s.size(), t.size());
    FOR(i,0,N){
        char c = s[a], d = t[b];
        if(c == 'R' && d == 'P') return false;
        if(c == 'P' && d == 'S') return false;
        if(c == 'S' && d == 'R') return false;
        if(d == 'R' && c == 'P') return true;
        if(d == 'P' && c == 'S') return true;
        if(d == 'S' && c == 'R') return true;
        ++a; a%=s.size();
        ++b; b%=t.size();
    }
    return true;
}

string solve(const vector<string>& v){
    set<string> st;
    st.insert("");
    FOR(i,0,500){
        set<string> st_;
        //cout << "L48: "; for(auto s:st) cout << "-" << s << "- "; cout << endl;
        for(const auto& s:st){
            string s1; bool b;

            s1 = s + "R";
            b = true; for(auto t:v) if(!goodfirst(s1, t)){ b = false; break; } if(b)
            st_.insert(s1);
            b = true; for(auto t:v) if(!goodall(s1, t)){ b = false; st_.erase(s1); break; } if(b) return s1;

            s1 = s + "P";
            b = true; for(auto t:v) if(!goodfirst(s1, t)){ b = false; break; } if(b)
            st_.insert(s1);
            b = true; for(auto t:v) if(!goodall(s1, t)){ b = false; st_.erase(s1); break; } if(b) return s1;

            s1 = s + "S";
            b = true; for(auto t:v) if(!goodfirst(s1, t)){ b = false; break; } if(b)
            st_.insert(s1);
            b = true; for(auto t:v) if(!goodall(s1, t)){ b = false; st_.erase(s1); break; } if(b) return s1;
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
        string ans = solve(v);
        printf("Case #%Ld: %s\n", t+1, ans.c_str());
    }
    return 0;
}
