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

bool hasdigit(const string &s){
    FOR(i,0,s.size()){
        const char &c = s[i];
        if(c == '0' || 
           c == '1' || 
           c == '2' || 
           c == '3' || 
           c == '4' || 
           c == '5' || 
           c == '6' || 
           c == '7' || 
           c == '8' || 
           c == '9') return true;
    }
    return false;
}

bool hasvowel(const string &s){
    FOR(i,0,s.size()){
        const char &c = s[i];
        if(c == 'a' || 
           c == 'e' || 
           c == 'i' || 
           c == 'o' || 
           c == 'u' || 
           c == 'A' || 
           c == 'E' || 
           c == 'I' || 
           c == 'O' || 
           c == 'U') return true;
    }
    return false;
}

bool isvalid(const string &s){
    if(!isupper(s[0])) return false;
    if(count(ALL(s), ' ') <= 0) return false;
    if(hasdigit(s)) return false;
    if(!hasvowel(s)) return false;

    return true;
}

int main(){
    string dummy;
    lli N; cin >> N; getline(cin, dummy);
    vector<string> v(N); for(string &s: v) getline(cin, s);
    lli ret = 0;
    for(const string &s: v) if(isvalid(s)) ret++;
    cout << ret << endl;

    return 0;
}
