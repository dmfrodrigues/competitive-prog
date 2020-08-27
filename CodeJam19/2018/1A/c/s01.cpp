#include <bits/stdc++.h>
#define FOR(i, n)               for(int (i) = 0 ; (i)  < (n); ++(i))
#define LD long double

using namespace std;

typedef pair<LD, LD> PFF;

bool equal(LD a, LD b){
    LD c = a-b;
    if(c < 0.0L) c = -c;
    return (c < (LD)(1.0e-8));
}

struct KNAPSACK{
private:
    set<PFF> s;
public:
    KNAPSACK(){
        s.insert(PFF(0.0L, 0.0L));
    }

    void check(set<PFF>::iterator it1){
        auto it2 = next(it1); if(it2 == s.end()) return;
        LD l = max(it1->first , it2->first );
        LD r = min(it1->second, it2->second);
        if(l < r || equal(l,r)){
            l = min(it1->first , it2->first );
            r = max(it1->second, it2->second);
            s.erase(it1);
            s.erase(it2);
            auto it = s.insert(PFF(l, r)).first;
            check(it);
        }
    }

    void insert(PFF p){
        auto it = s.insert(p).first;
        auto it_ = it; --it_;
        bool b = false; if(it != s.begin()) b = true;
        check(it);
        if(b) check(it_);
    }

    void insertout(PFF p){
        set<PFF> prev(s);
        for(auto i:prev){
            insert(PFF(i.first+p.first, i.second+p.second));
        }
    }

    LD closest(LD P){
        auto it = s.upper_bound(PFF(P,P));
        if(it != s.end() && equal(P, it->first)) return P;
        return min(P, prev(it)->second);
    }
};

LD solve(vector<PFF> v, LD P){
    KNAPSACK K;

    LD sub = 0.0L;
    for(auto p:v){
        sub += 2.0L*(p.first+p.second);
    }
    P -= sub;

    for(auto p:v){
        LD half = min(p.first, p.second);
        LD diag = sqrt(p.first*p.first + p.second*p.second);
        K.insertout(PFF(2.0L*half, 2.0L*diag));
    }
    LD ans = K.closest(P);
    ans += sub;
    return ans;
}

int main(){
    int T; cin >> T;
    FOR(t, T){
        int N; LD P; cin >> N >> P;
        vector<PFF> v(N);
        for(auto& n:v) cin >> n.first >> n.second;
        LD ans = solve(v, P);
        printf("Case #%d: %.20Lf\n", t+1, ans);
    }


}
