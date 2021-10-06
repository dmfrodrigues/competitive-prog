//https://codeforces.com/gym/101635

#include <bits/stdc++.h>
using namespace std;

#define ALL(v)          (v).begin() , (v).end()
typedef long long int lli;
typedef lli lli;
#define FOR(i,b,e)        for(lli (i) = (b); (i) < (e); ++(i))
typedef pair<lli,lli> PII;
typedef vector<lli> VI;
#define INF 1000000000L
#define MAXP 10001
#define MAXB 10001

lli freeint(const string& s){
    static unordered_map<string,lli> m;
    if(m.find(s) == m.end()) m[s] = m.size();
    return m[s];
}

struct recipe{
    lli b; lli c; lli p;
};

lli B, N; //Budget, Numero de receitas
deque<recipe> recipes[MAXP]; //Receitas
PII v[MAXP]; //Possibilidades
bool v_done[MAXP];

void get_cp(lli i){
    if(v_done[i]) return;
    v_done[i] = true;
    PII &vi = v[i]; vi = PII(INF, 0);
    if(recipes[i].empty()){ v[i] = PII(0, 0); return; }
    for(const recipe& r:recipes[i]){
        get_cp(r.b);
        lli c = v[r.b].first  + r.c;
        lli p = v[r.b].second + r.p;
        if(c > B) continue;
        if(c < vi.first || (c == vi.first && p > vi.second)){ vi = PII(c, p); }
    }
}

int main(){
    lli K = 0;

    cin >> B >> N;
    string d, b, a; lli d_, b_, c_, p_;
    unordered_map<lli, deque<recipe> > R_; //Receitas
    FOR(i, 0, N){
        cin >> d >> b >> a >> c_ >> p_;
        d_ = freeint(d);
        b_ = freeint(b);
        R_[d_].push_back({b_, c_, p_});
        R_[b_];// R[a];
    }

    K = R_.size();

    for(const auto& it:R_)
        recipes[it.first] = it.second;


    FOR(i, 0, K) if(!v_done[i]) get_cp(i);


    sort(v, v+K);

    VI prest(B+1, 0);
    FOR(i, 0, K){ //PARA CADA PRATO
        const auto& pr = v[i];
        for(lli b = B-pr.first; b >= 0; --b){
            lli bnew =       b  + pr.first;
            lli pnew = prest[b] + pr.second;
            prest[bnew] = max(prest[bnew], pnew);
        }
    }
    lli p = prest[B];
    lli c = B;
    while(c >= 0 && prest[c] == p) --c;
    ++c;
    cout << p << endl;
    cout << c << endl;
    return 0;
}
