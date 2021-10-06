#include <bits/stdc++.h>
using namespace std;
typedef long long int           lli;
typedef unsigned long long int  ulli;
#define ALL(v)                  (v).begin() , (v).end()
#define contain(Set,i)          ( (Set) & (1Lu<<(i)) )
#define mk(a,b)                 make_pair((a), (b))
#define FOR(i, b, e)            for(lli i =(b); (i)  < (lli)(e); ++(i))
//#define REP(i, b, e)            for(auto i =(b); (i) != (e); ++(i))
typedef vector<lli>             VI;
typedef vector<VI>              VVI;
typedef pair< lli, lli>         PII;
typedef pair<ulli,ulli>         PUU;
typedef pair<PII,PII>           PPP;
#define X first
#define Y second
const lli INF = 1000000000;

class alGraph:public vector< deque<lli> >{ // Adjency List
public:
	alGraph(lli s):vector< deque<lli> >(s){}
	void addEdge(lli src, lli dst) {
		(*this)[src].push_back(dst);
        (*this)[dst].push_back(src);
	}
};

alGraph al(0);
vector<bool> pref_original;
VI disag;

lli disagreements(lli i, const vector<bool> &v){
    lli ret = 0;
    for(const lli &to:al[i]){
        if(v[i] != v[to]) ++ret;
    }
    return ret;
}

lli margin(lli i, const vector<bool> &v){
    lli N1 = disag[i];
    lli N0 = al[i].size() - N1;
    //concorda com N0, discorda com N1

    //Atualmente, ele soma N1+(p==porig? 0 : 1) ao resultado.
    //Se virar, passa a somar N0+(p==porig? 1 : 0).
    lli diff = N0-N1+(v[i] == pref_original[i] ? 1 : -1); //diff é a diferença aplicada ao resultado final se ele virar
    return diff;
}

void invert_state(lli i, vector<bool> &v){
    v[i] = !v[i];
    for(const lli &to:al[i]){
        if(v[i] == v[to]) --disag[to];
        else              ++disag[to];
    }
    disag[i] = disagreements(i, v);
}

int main(){
    while(true){
        lli N, M; cin >> N >> M;
        if(M == 0 && N == 0) return 0;

        pref_original = vector<bool>(N);{
            bool b;
            FOR(i,0,N){
                cin >> b;
                pref_original[i] = b;
            }
        }

        al = alGraph(N);{
            lli fr, to;
            FOR(i,0,M){
                cin >> fr >> to;
                al.addEdge(fr-1,to-1);
            }
        }

        disag = VI(N);
        FOR(i,0,N) disag[i] = disagreements(i, pref_original);

        vector<bool> pref = pref_original, pref_p;
        do{
            pref_p = pref;
            lli best_i = 0;
            lli best_mar = margin(best_i, pref);
            FOR(i,0,N){
                lli mar = margin(i, pref);
                if(mar <= best_mar){
                    best_i = i;
                    best_mar = mar;
                }
            }
            //Agora, em best_i está o sujeito que, se trocado, reduz mais ao resultado final
            if(best_mar < 0){
                invert_state(best_i, pref);
            }
        }while(pref_p != pref);
        /*
        FOR(i,0,N) cout << pref[i] << " ";
        cout << endl;
        */
        lli ans = 0;
        FOR(i,0,N){
            ans += (pref[i] != pref_original[i] ? 2 : 0) + disagreements(i,pref);
        }
        assert(ans%2 == 0);
        ans /= 2;

        cout << ans << endl;
    }
    return 0;
}
