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

NUMT getCurrDiff(NUMT e, NUMT v, const vector< set<NUMT> >& ans){
    NUMT ret = 0;
    for(const auto& con:Con[e]){ ///Para cada ligacao do endpoint _e_
        if(ans[con.first].find(v) != ans[con.first].end()){ ///Se a cache con.first tiver o video _v_
            ret = max(ret, con.second); ///ret passa a ser o melhor entre si e a melhoria que essa ligacao providencia
        }
    }
    return ret;
}

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

    VVD Gain(C, VD(V));
    set<NUMT> ToChange;{
        for(NUMT v = 0; v < V; ++v)
            ToChange.insert(v);
    }

    //NUMT counter = 0;
    while(true){
        //++counter;
        //cout << "counter:" << counter << endl;
        NUMT bestc, bestv; bool changed = false; {
            double bestg = 0.0L;
            for(NUMT v = 0; v < V; ++v){
                for(NUMT c = 0; c < C; ++c){
                    if(S[v] > Avail[c]) continue; ///Se o video _v_ nao cabe na cache _c_, avançar
                    if(ToChange.find(v) != ToChange.end()){ //ToChange.erase(ToChange.find(v));
                        double& g = Gain[c][v];
                        g = 0.0;
                        for(const auto& e:Prov[c]){
                            NUMT d = getCurrDiff(e.first, v, ans); ///Se _e_ pede o video _v_, quanto é que ganha atualmente
                            g += max(double((e.second - d)*Req[e.first][v]), 0.0);
                        }
                        g *= pow(S[v], -1.0);
                    }
                    if(Gain[c][v] > bestg){ changed = true;
                        bestg = Gain[c][v];
                        bestc = c;
                        bestv = v;
                    }
                }
                if(ToChange.find(v) != ToChange.end()) ToChange.erase(ToChange.find(v));
            }
        }
        if(!changed) break;
        ans[bestc].insert(bestv);
        Avail[bestc] -= S[bestv];
        ToChange.insert(bestv);
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
