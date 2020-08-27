#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define FOR(i,b,e) for(lli (i) = (b); (i) < lli(e); ++(i))
typedef pair<lli,lli> PII;
typedef vector<string> VS;
typedef vector<VS> VVS;

unsigned long long eval(const VS &expr, const unsigned long long n){
    stack<bool> d;
    for(const string &s:expr){
        if(s == "*" || s == "+"){
            bool b1 = d.top(); d.pop();
            bool b2 = d.top(); d.pop();
            if(s == "*") d.push(b1 && b2);
            else         d.push(b1 || b2);
        }else if(s == "-"){
            bool b = d.top(); d.pop();
            d.push(!b);
        }else{
            unsigned i;{ stringstream ss; ss << s; ss >> i; }
            d.push(n&(1L<<i));
        }
    }
    return d.top();
}

int main(){
    unsigned N; cin >> N;
    VVS v(N);
    for(VS &w:v){
        lli F; cin >> F;
        w = VS(F);
        for(string &s:w) cin >> s;
    }
    lli ret = 0;
    for(unsigned long long i = 0; i < (1uL<<N); ++i, ++ret){
        for(unsigned j = 0; j < N; ++j){
            if((i&(1uL<<j)) != (eval(v[j], i)<<j)){
                --ret;
                break;
            }
        }
    }
    cout << ret << endl;
    return 0;
}
