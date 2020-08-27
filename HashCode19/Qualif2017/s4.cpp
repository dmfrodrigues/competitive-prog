#include <bits/stdc++.h>
#define NUMT long
#define MAXV 10005
#define MAXE 1005
using namespace std;
typedef pair<NUMT, NUMT> PNN;
typedef vector<double> VD;
typedef vector<VD> VVD;

NUMT V, E, R, C, X; //#videos, #endpoints, #requests, #caches, Size_cache
NUMT S[MAXV];
NUMT Ld[MAXE];        //latencia do datacenter para o endpoint _i_ está em Ld[_i_]
deque<PNN> Con[MAXE]; ///Conexoes; first -> ID da cache; second -> latencia da ligacao
NUMT Req[MAXE][MAXV]; ///O endpoint _i_ requer o video _j_ um total de Req[_i_][_j_] vezes

NUMT ReqGains[MAXE][MAXV];


struct STR2ORD{
    double g;
    NUMT c;
    NUMT v;
    bool operator<(const STR2ORD& obj)const{
        return (this->g > obj.g);
    }
};

NUMT getCurrDiff(NUMT e, NUMT v, const vector< set<NUMT> >& ans){
    NUMT ret = 0;
    for(const auto& con:Con[e]){ ///Para cada ligacao do endpoint _e_
        if(ans[con.first].find(v) != ans[con.first].end()){ ///Se a cache con.first tiver o video _v_
            ret = max(ret, con.second); ///ret passa a ser o melhor entre si e a melhoria que essa ligacao providencia
        }
    }
    return ret;

    //return ReqGains[e][v];
}

const NUMT INCLUDEROUND = 4;

vector< set<NUMT> > solve(){
    for(NUMT e = 0; e < E; ++e) ///Para cada endpoint
        for(auto& c:Con[e]) ///Para cada ligacao do endpoint _e_
            c.second = Ld[e] - c.second; ///AGORA, EM Con second ESTÁ O TEMPO POUPADO SE ESSA LIGACAO FOR USADA

    deque<PNN> Prov[MAXE]; ///Prov[_c_] contem os endpoints que a cache _c_ consegue fornecer, e a poupança
                           ///first -> ID do endpoint; second -> poupança
    for(NUMT e = 0; e < E; ++e)
        for(const auto& it:Con[e])
            Prov[it.first].push_back({e, it.second});

    NUMT Avail[MAXE]; fill(Avail, Avail+C, X); ///a cache _c_ possui Avail[c] espaço disponivel

    vector< set<NUMT> > ans(C);

    set<NUMT> ToChange;{
        for(NUMT v = 0; v < V; ++v)
            ToChange.insert(v);
    }

    set<STR2ORD> Gain;
    while(true){
        auto itg = Gain.begin();
        while(itg != Gain.end()){
            auto itv = ToChange.find(itg->v);
            if(itv != ToChange.end())
                itg = Gain.erase(itg);
            else
                ++itg;
        }
        {
            //for(NUMT v = 0; v < V; ++v){
            while(!ToChange.empty()){
                NUMT v = *ToChange.begin(); ToChange.erase(ToChange.begin());
                for(NUMT c = 0; c < C; ++c){
                    double g;
                    if(S[v] > Avail[c]){
                        g = -1.0;
                        continue;
                    }else{
                        g = 0.0;
                        bool changed = false;
                        for(const auto& e:Prov[c]){
                            NUMT d = getCurrDiff(e.first, v, ans); ///Se _e_ pede o video _v_, quanto é que ganha atualmente
                            double add = double(e.second - d)*Req[e.first][v];
                            if(add > 0.0){
                                changed = true;
                                g += add;
                            }
                        }
                        if(changed) g *= pow(S[v], -1.0);
                        else        g = -1.0;
                    }
                    Gain.insert({g,c,v});
                }
            }
        }
        auto it = Gain.begin();
        if(it->g <= 0.0) break;
        NUMT i;
        //cout << "START OVER" << endl;
        for(i = 0; i < INCLUDEROUND && it != Gain.end(); ++it){
            //cout << "i=" << i << endl;
            //if(ToChange.find(it->v) != ToChange.end()) continue;
            if(it->g <= 0.0){
                it = Gain.end();
                //cout << "L91" << endl;
                break;
            }
            if(S[it->v] < Avail[it->c]){
                //cout << "L95" << endl;
                ++i;
                ans[it->c].insert(it->v);
                for(const auto& con:Con[it->c]){
                    ReqGains[con.first][it->v] = max(ReqGains[con.first][it->v], con.second);
                }
                Avail[it->c] -= S[it->v];
                ToChange.insert(it->v);
            }
        }
        //cout << "OUT, i = " << i << ", it is end? " << (it == Gain.end()) << endl;
        if(it == Gain.end() && i==0) break;
    }
    return ans;
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
    NUMT Rv, Re, Rn;
    for(NUMT i = 0; i < R; ++i){
        cin >> Rv >> Re >> Rn;
        Req[Re][Rv] += Rn;
    }
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
