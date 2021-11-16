#include <bits/stdc++.h>
using namespace std;
typedef long long unsigned ulli;
typedef long unsigned uli;
#define FOR(i,a,b) for(ulli (i) = (a); (i) < (b); ++(i))

const uli MAX   =   3000000;
const uli MAX_C = 100000000;

typedef unsigned long long uint64;
uint64 state[2];
void set_seed(uint64 seed){
    state[0] = seed;
    state[1] = seed ^ 0x7263d9bd8409f526;
}
uint64 xoroshiro128plus() {
    uint64 s0 = state[0];
    uint64 s1 = state[1];
    uint64 result = s0 + s1;
    s1 ^= s0;
    state[0] = ((s0 << 55) | (s0 >> 9)) ^ s1 ^ (s1 << 14);
    state[1] = (s1 << 36) | (s1 >> 28);
    return result;
}

int main(){
    uli N; cin >> N; const ulli MASK = (ulli(1)<<N)-1;
    ulli sa, sb, sc, sd; cin >> sa >> sb >> sc >> sd;
    uli a =   287; set_seed(sa); ulli va; FOR(i,0,a) va = xoroshiro128plus() & MASK;
    uli b = 17609; set_seed(sb); ulli vb; FOR(i,0,b) vb = xoroshiro128plus() & MASK;
    cout << "L27\n";
    unordered_map<ulli, uli> valuesd;{
        set_seed(sd);
        for(uli i = 1; i <= MAX; ++i){
            //if(i % 100 == 0) cout << "i=" << i << "\n";
            valuesd[xoroshiro128plus() & MASK] = i;
        }
    }
    //cout << "L34\n";
    set_seed(sc);
    for(uli c = 1; c < MAX_C; ++c){
        //if(c % 100 == 0) cout << "c=" << c << "\n";
        const ulli vc = xoroshiro128plus() & MASK;
        const ulli vd = va ^ vb ^ vc;
        const auto it = valuesd.find(vd);
        if(it != valuesd.end()){
            const uli d = it->second;
            cout << a << " " << b << " " << c << " " << d << "\n";
            return 0;
        }
    }
    cout << "FAILED" << endl;
    return 0;
}
