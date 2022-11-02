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

const lli NMAX = 16;

lli pow2(const lli &k){
    return (1LL << k);
}

bool inset(const lli &s, const lli &k){
    return s & pow2(k);
}

lli first_set_bit(const lli &s){
    return __builtin_ctz(s);
}

lli remove_from_set(const lli &s, const lli &k){
    return s & (~pow2(k));
}

VI v(NMAX);
lli N;
lli K;
lli share;
unordered_map<lli, unordered_set<lli>> DP;

bool solve(lli k, lli s);

bool solve_wrapper(lli k, lli s){
    if(DP[k].count(s)) return true;
    else return solve(k, s);
}

bool solve(lli k, lli s){

    // cout << "solve " << k << " " << bitset<16>(s) << endl;
    
    lli i = first_set_bit(s);
    s = remove_from_set(s, i);
    lli share_so_far = v[i];
    unordered_map<lli, set<lli>> sums_of_coins_prev;
    if(share_so_far > share){
        /*cout << "L45" << endl;*/
        return false;
    }
    sums_of_coins_prev[share_so_far].insert(s);
    // cout << "Added " << share_so_far << ", " << s << endl;
    FOR(j,i+1,N){
        unordered_map<lli, set<lli>> sums_of_coins;
        if(inset(s, j)){
            // cout << j << " is in set" << endl;
            for(const auto &p: sums_of_coins_prev){
                lli old_sum = p.first;
                lli new_sum = old_sum + v[j];
                // cout << "new_sum=" << new_sum << endl;
                for(const lli &s_quasinew: p.second){
                    sums_of_coins[old_sum].insert(s_quasinew);
                    if(new_sum <= share)
                        sums_of_coins[new_sum].insert(remove_from_set(s_quasinew, j));
                    // cout << "Added " << new_sum << ", " << remove_from_set(s_quasinew, j) << endl;
                }
            }
            sums_of_coins_prev = sums_of_coins;
        }
    }
    if(!sums_of_coins_prev.count(share)){
        // cout << "L61" << endl;
        return false;
    }
    else {
        for(const lli &s_new: sums_of_coins_prev.at(share)){
            if(solve_wrapper(k-1, s_new)) return true;
        }
        // cout << "L66" << endl;
        return false;
    }
}

int main(){
    lli i = 0;
    while(cin >> v[i]) ++i;
    N = i-1;
    K = v[N];
    v.resize(N);

    const lli total = accumulate(ALL(v), 0);
    if(total % K != 0){ cout << "False" << endl; return 0; }
    share = total/K;

    // cout << "share=" << share << endl;

    DP[0].insert(0);
    cout << (solve(K, pow2(N)-1) ? "True" : "False") << endl;

    return 0;
}
