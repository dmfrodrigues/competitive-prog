#include <bits/stdc++.h>
using namespace std;
typedef int32_t lli;
#define FOR(i,b,e)        for(lli (i) = (b); (i) < (e); ++(i))
typedef pair<lli,lli> PII;
typedef vector<lli> VI;
const lli INF = 1000000000;

unordered_map<string,lli> m;
lli freeint(const string& s){
    if(m.find(s) == m.end()) m[s] = m.size();
    return m[s];
}

struct recipe{
    lli a, c, p;
};

lli B, N;

vector<recipe> recipes[10001];
bool v_done[10001];
PII v[10001]; //(cost, prestige)

void get_cp(lli i){
    if(v_done[i]) return;
    v_done[i] = true;
    PII &vi = v[i];
    if(recipes[i].empty()){ vi = PII(0,0); return; }
    vi = PII(B, 0);
    for(const recipe &r:recipes[i]){
        get_cp(r.a);
        lli c = v[r.a].first  + r.c;
        lli p = v[r.a].second + r.p;
        if(c > B) continue;
        if(c < vi.first || (c == vi.first && p > vi.second)) vi = PII(c,p);
    }
}

int main(){
    FOR(i,0,10001){
        recipes[i].reserve(128);
    }
    /**
     * K - number of dishes
     * N - Number of recipes
     * B - budget
     */
    /** O(N) */
    lli K = 0;{
        cin >> B >> N;
        string ss, sa, sb; lli i, a, c, p;
        while(N--){
            cin >> ss >> sa >> sb >> c >> p;
            i = freeint(ss);
            a = freeint(sa);
            recipes[i].push_back({a,c,p});
        }
        K = m.size();
    }

    /** O(N) */
    FOR(i,0,K){ get_cp(i); }

    /** O(K log K) */
    sort(v, v+K, std::greater<PII>());

    lli bnew, pnew;
    map<lli,lli> prest; prest[0] = 0;
    for(const auto &pr:v){
        const lli &c = pr.first, &p = pr.second;
        if(c == 0) continue;
        auto it = prest.upper_bound(B-c);
        if(it == prest.begin()) continue;
        --it;
        while(true){
            bnew = it->first  + c;
            pnew = it->second + p;
            auto ret_p = prest.insert(PII(bnew, pnew));
            if(!ret_p.second) ret_p.first->second = max(ret_p.first->second, pnew);
            if(it == prest.begin()) break;
            --it;
        }
        /*
        for(lli b = B-c; b >= 0; --b){
            lli bnew = b+c;
            lli pnew = prest[b]+p;
            prest[bnew] = max(prest[bnew], pnew);
        }
        */
    }
    PII best = *prest.begin();
    for(const PII &p:prest){
        if(p.first > B) break;
        if(p.second > best.second) best = p;
    }
    cout << best.second << endl << best.first << endl;
    return 0;
}
