#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;

namespace std{
    template<> struct hash<PII>{
        hash<int> h;
        size_t operator()(const PII &p) const{
            return 7919*h(p.first) + h(p.second);
        }
    };
}

unordered_map<PII, int> compressed;

string s;

int compress(PII p){
    auto it = compressed.find(p);
    if(compressed.find(p) != compressed.end()) return it->second;

    const int &l = p.first, &r = p.second;
    // Atomic path
    if(count(s.begin()+l, s.begin()+r, s[l]) == r-l){ compressed[p] = 1; return 1; }

    int ret = r-l;
    // Repetition of compressed
    for(int n = 2; n < r-l; ++n){
        if((r-l)%n != 0) continue;
        int w = (r-l)/n;
        bool good = true;
        for(int i = l+w; i < r; i += w){
            if(!equal(s.begin()+l, s.begin()+l+w, s.begin()+i)){
                good = false;
                break;
            }
        }
        if(good) ret = min(ret, compress(PII(l, l+w)));
    }
    // Concatenation of compressed
    for(int m = l+1; m < r; ++m)
        ret = min(ret, compress(PII(l, m))+compress(PII(m, r)));
    compressed[p] = ret; return compressed[p];
}

int main(){
    { int N; cin >> N; }
    cin >> s;
    cout << compress(PII(0, s.size())) << endl;
    return 0;
}
