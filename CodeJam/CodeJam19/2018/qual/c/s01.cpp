#include <bits/stdc++.h>
#define ALL(v)          (v).begin() , (v).end()
#define FOR(i, n)       for(int i = 0 ; (i)  < (n); ++(i))
#define REP(i, b, e)    for(int i =(b); (i) <= (e); ++(i))
#define ORIGIN          10

using namespace std;

typedef pair<int,int> PNN;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<bool> VB;
typedef vector<VB> VVB;

PNN decompose(int n){
    PNN ret;
    for(int i = 3, j;; ++i){
        j = n/i+(n%i?1:0);
        if(i > j) break;
        ret = make_pair(i,j);
    }
    return ret;
}

int I, J;
struct PNT{
    int n;
    int i,j;
    bool operator<(const PNT& obj)const{
        /*
        if(this->n != obj.n) return (this->n > obj.n);
        else{
            int d1 = min(i, I-i); int d1_ = min(obj.i, I-obj.i);
            int d2 = min(j, J-j); int d2_ = min(obj.j, J-obj.j);
            int d  =       d1*d2; int d_  = d1_*d2_;
            return (d1 > d2);
        }
        */
             if(n != obj.n) return (n > obj.n);
        else if(i != obj.i) return (i < obj.i);
        else                return (j < obj.j);
    }
};

bool isBad (PNT p){ return (p.i == -1 || p.j == -1); }
bool isGood(PNT p){ return (p.i ==  0 && p.j ==  0); }

int solve(int A){
    ///Obter I, J
    {
        PNN p = decompose(A);
        I = p.first-2; J = p.second-2;  //cerr << "I,J=" << I<<"," << J << endl;
    }
    VVB b(I+2, VB(J+2, false));
    VVI v(I, VI(J, 9));
    set<PNT> s;{
        FOR(i, I) FOR(j, J){ //cerr << "L52, i,j=" << i <<"," << j << endl;
            s.insert({9, i, j});
        }
    }
    int counter = 0;
    while(true){ ++counter;
        PNT p = *s.begin();

        //cerr << "s: "; for(auto k:s) cerr << k.n << ",(" << k.i <<","<<k.j<<")   "; cerr << endl;

        cout << p.i+ORIGIN << " " << p.j+ORIGIN << endl;


        //cerr << "p=" << p.i << " " << p.j << endl;

        PNT q; cin >> q.i >> q.j;
        if(isBad(q)) return counter;
        if(isGood(q)) return counter;

        q.i -= ORIGIN; q.j -= ORIGIN;
        if(!b[q.i+1][q.j+1]){ b[q.i+1][q.j+1] = true;
            REP(di, -1, +1) REP(dj, -1, +1){
                PNT r; r.i = q.i+di; r.j = q.j+dj;
                if(0 <= r.i && r.i < I && 0 <= r.j && r.j < J){
                    auto& sum = v[r.i][r.j];
                    s.erase(PNT({sum, r.i, r.j}));
                    --sum;
                    s.insert(PNT({sum, r.i, r.j}));
                }
            }
        }
        /*
        cerr << endl;
        for(int i = 0; i < b.size(); ++i){
            cerr << "i=" << i << " ";
            for(int j = 0; j < b[i].size(); ++j) cerr << b[i][j] << " ";
            cerr << endl;
        }
        */

    }
}

int main(){
    int T; cin >> T;
    FOR(i, T){
        int A; cin >> A;
        int r = solve(A);
        //cerr << r << " <==============================" << endl;
        if(r >= 1000) break;
    }
    return 0;
}
