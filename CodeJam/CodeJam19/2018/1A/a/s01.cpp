#include <bits/stdc++.h>
#define MAXD 105
#define FOR(i, n)       for(int i = 0 ; (i)  < (n); ++(i))
#define REP(i, b, e)    for(int i =(b); (i) != (e); ++(i))

using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<bool> VB;
typedef vector<VB> VVB;

class COUNT{
private:
    int R, C;
    int v[MAXD][MAXD];
public:
    COUNT(const VVB& in){
        R = in.size();
        C = in[0].size();

        v[0][0] = (in[0][0]? 1 : 0);
        REP(r, 1, R) v[r][0] = v[r-1][  0] + (in[r][0]? 1 : 0);
        REP(c, 1, C) v[0][c] = v[  0][c-1] + (in[0][c]? 1 : 0);
        REP(r, 1, R) REP(c, 1, C) v[r][c] = (in[r][c]? 1 : 0) + v[r][c-1] + v[r-1][c] - v[r-1][c-1];
    }
    int query(int r, int c)const{
        if(r < 0 || c < 0) return 0;
        return v[r][c];
    }
    int query(int r1, int r2, int c1, int c2)const{
        return (query(r2,c2) - query(r1-1,c2) - query(r2,c1-1) + query(r1-1,c1-1));
    }
    int sum()const{
        return query(R-1, C-1);
    }

    void print()const{
        FOR(r, R){
            cerr << "r=" << r << "   ";
            FOR(c, C){
                cerr << v[r][c] << "  ";
            } cerr << endl;
        }
    }
};

bool solve(const VVB& in, unsigned H, unsigned V){
    unsigned R = in.size();
    unsigned C = in[0].size();
    COUNT CNT(in);
    //CNT.print();
    /*Tudo*/
    {
        int s = CNT.sum();
        int n = (H+1)*(V+1);
        if(s%n != 0) return false;
        if(s == 0 && H+1 <= R && V+1 <= C) return true;
    }
    /*se i pertence a Vcuts, então existe um corte entre i e i+1*/
    /*Cortes verticais*/
    set<int> Vcuts;{
        int s = CNT.sum() / (V+1);
        int cleft = 0;
        for(unsigned c = 0; c < C; ++c){
            int t = CNT.query(0, R-1, cleft, c);
            if(t > s ){
                return false;
            }
            if(t == s){
                Vcuts.insert(c+1);
                cleft = c+1;
            }
        }
        if(Vcuts.size() != V+1) return false;
    }
    //cerr << "L79" << endl;
    /*Cortes horizontais*/
    set<int> Hcuts;{
        int s = CNT.sum() / (H+1);
        int rleft = 0;
        for(unsigned r = 0; r < R; ++r){
            int t = CNT.query(rleft, r, 0, C-1);
            if(t > s ) return false;
            if(t == s){
                Hcuts.insert(r+1);
                rleft = r+1;
            }
        }
        if(Hcuts.size() != H+1) return false;
    }


    Vcuts.insert(0);
    Hcuts.insert(0);

    //cerr << "Vcuts: "; for(auto i:Vcuts) cerr << i << " "; cerr << endl;
    //cerr << "Hcuts: "; for(auto i:Hcuts) cerr << i << " "; cerr << endl;

    int s = CNT.sum()/((H+1)*(V+1));
    for(auto Vit = Vcuts.begin(); next(Vit) != Vcuts.end(); ++Vit){
        for(auto Hit = Hcuts.begin(); next(Hit) != Hcuts.end(); ++Hit){
            //cerr << "("  << *Hit << ", " << *next(Hit)-1 << ", " << *Vit << ", " << *next(Vit)-1 << ")" << endl;
            int n = CNT.query(*Hit, *next(Hit)-1, *Vit, *next(Vit)-1);
            //cerr << "n=" << n << endl;
            if(n != s) return false;
        }
    }

    return true;
}

int main(){
    int T; cin >> T;
    for(int t = 0; t < T; ++t){
        int R, C, H, V;
        cin >> R >> C >> H >> V;
        VVB v(R, VB(C));
        string s; //cerr << "t=" << t << endl;
        for(int r = 0; r < R; ++r){
            cin >> s; //cerr << s << endl;
            for(int c = 0; c < C; ++c)
                v[r][c] = (s[c] == '@');
        } //cerr << "L105" << endl;
        bool b = solve(v, H, V);
        cout << "Case #" << t+1 << ": ";
        if(b) cout << "POSSIBLE"   << endl;
        else  cout << "IMPOSSIBLE" << endl;
    }

}
