#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define FOR(i,b,e) for(lli (i) = (b); (i) < lli(e); ++(i))
typedef vector<lli> VI;
typedef vector<VI> VVI;
typedef pair<lli,lli> PII;
#define X first
#define Y second

VVI M;
vector<string> D;

lli f(lli y, lli x){
    if(M[y][x] != -1) return M[y][x];
    set<PII> s;
    stack<PII> v;
    v.push(PII(x,y)); s.insert(PII(x,y));
    while(true){
        const PII &c = v.top();
        PII n = c;
        switch(D[c.Y][c.X]){
            case 'N': --n.Y; break;
            case 'S': ++n.Y; break;
            case 'W': --n.X; break;
            case 'E': ++n.X; break;
            default: break;
        }
        if(!(0 <= n.Y && n.Y < (lli)M.size() && 0 <= n.X && n.X < (lli)M[0].size())){ //sair do tabuleiro
            lli d = 1;
            while(!v.empty()){
                PII p = v.top(); v.pop();
                M[p.Y][p.X] = d;
                ++d;
            }
            return M[y][x];
        }
        if(M[n.Y][n.X] != -1){
            lli d = M[n.Y][n.X]+1;
            while(!v.empty()){
                PII p = v.top(); v.pop();
                M[p.Y][p.X] = d;
                ++d;
            }
            return M[y][x];
        }
        if(s.find(n) != s.end()){ //entrou num ciclo
            queue<PII> cycle;
            PII p;
            lli d = 0;
            p = v.top(); v.pop(); cycle.push(p);
            ++d;
            while(p != n){
                p = v.top(); v.pop(); cycle.push(p);
                ++d;
            }
            while(!cycle.empty()){
                p = cycle.front(); cycle.pop();
                M[p.Y][p.X] = d;
            }
            ++d;
            while(!v.empty()){
                p = v.top(); v.pop();
                M[p.Y][p.X] = d;
                ++d;
            }
            return M[y][x];
        }
        v.push(n); s.insert(n);
    }
}

int main(){
    /// INPUT
    lli R, C; cin >> R >> C;
    M = VVI(R, VI(C, -1)); D = vector<string>(R);
    FOR(i,0,R) cin >> D[i];
    /// PROCESSING
    lli Q; cin >> Q;
    FOR(i,0,Q){
        lli Y, X; cin >> Y >> X;
        cout << f(Y-1, X-1) << endl;
    }
    return 0;
}
