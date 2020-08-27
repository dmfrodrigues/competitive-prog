#include <bits/stdc++.h>
#define NUMT long
#define MAXV 10005
#define MAXE 1005
#define MAXR 1000005
using namespace std;
typedef pair<NUMT, NUMT> PNN;
typedef vector<double> VD;
typedef vector<VD> VVD;

NUMT V, E, R, C, X; //#videos, #endpoints, #requests, #caches, Size_cache
NUMT S[MAXV];
NUMT Ld[MAXE];        //latencia do datacenter para o endpoint _i_ está em Ld[_i_]
deque<PNN> Con[MAXE]; ///Conexoes; first -> ID da cache; second -> latencia da ligacao
NUMT Req[MAXR][3];

const NUMT FAILMAX = 10000000;
const NUMT NUMTRIALS = 40;

vector<set<NUMT> > make_trial(){
    vector<set<NUMT> > ans(C);
    vector<NUMT> avail(C, X);
    NUMT failc = 0;
    while(failc < FAILMAX){
        NUMT v = rand()%V, c = rand()%C;
        if(avail[c] >= S[v]){
            ans[c].insert(v);
            avail[c] -= S[v];
        }else ++failc;
    }
    return ans;
}

double get_points(const vector<set<NUMT> >& s){
    double p = 0;
    for(NUMT t = 0; t < R; ++t){
        const NUMT& Rv = Req[t][0], Re = Req[t][1], Rn = Req[t][2];
        NUMT L = Ld[Re];
        for(const auto& c:Con[Re])
            if(s[c.first].find(Rv) != s[c.first].end())
                L = min(L, c.second);
        p += double(Rn)*double(Ld[Re]-L);
    }
    double totalNumReq = 0.0L; for(NUMT i = 0; i < R; ++i) totalNumReq += double(Req[i][2]);
    p /= totalNumReq;
    return p;
}

vector< set<NUMT> > solve(){
    vector<set<NUMT> > bests; double bestp = 0;
    vector<set<NUMT> >     s; double     p = 0;
    for(NUMT i = 0; i < NUMTRIALS; ++i){
        cerr << "test " << i << endl;
        s = make_trial();
        cerr << "done test" << endl;
        p = get_points(s);
        if(p > bestp){
            bestp = p;
            bests = s;
            cerr << "NEW BEST: " << p << " ms" << endl;
        }
    }
    return bests;
}

int main(){
    ///INPUT
    cin >> V >> E >> R >> C >> X;
    for(NUMT i = 0; i < V; ++i)
        cin >> S[i];
    for(NUMT i = 0; i < E; ++i){
        cin >> Ld[i];
        NUMT K; cin >> K;
        PNN in;
        for(NUMT j = 0; j < K; ++j){
            cin >> in.first >> in.second;
            Con[i].push_back(in);
        }
    }
    for(NUMT i = 0; i < R; ++i)
        cin >> Req[i][0] >> Req[i][1] >> Req[i][2];
    ///PROCESSING
    vector< set<NUMT> > ans = solve();
    ///OUTPUT
    cout << ans.size() << endl;
    for(NUMT i = 0; i < C; ++i){
        cout << i;
        for(const auto& it:ans[i]){
            cout << " " << it;
        }
        cout << endl;
    }
    return 0;
}
