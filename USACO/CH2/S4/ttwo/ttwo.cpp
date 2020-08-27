/*
ID: dmfrodr1
TASK: ttwo
LANG: C++11
*/
#include <bits/stdc++.h>
using namespace std;
#define FOR(i,b,e) for(int (i) = (b); (i) < (e); ++(i))

typedef pair<int,int> pos_t;
enum orient_t{
    NORTH,
    SOUTH,
    EAST,
    WEST
};

const int N = 10;
vector< vector<int> > map(N, vector<int>(N, 0));

const int NROUNDS = 160000;

void next_pos(pos_t &pos, orient_t &orient){
    
}

int main(){
    // INPUT FILES
    ifstream fin("ttwo.in");
    ofstream fout("ttwo.out");
    // INPUT
    pos_t C, F;
    orient_t Co = NORTH, Fo = NORTH;
    FOR(i,0,N){
        string s; fin >> s;
        FOR(j,0,N){
            map[i][j] = (s[j] == '*' ? 1 : 0);
            if(s[j] == 'F') F = pos_t(i,j);
            if(s[j] == 'C') C = pos_t(i,j);
        }
    }
    // PROCESSING
    int t;
    for(t = 0; t < NROUNDS; ++t){
        if(C == F) break;
        next_pos(C, Co);
        next_pos(F, Fo);
    }
    // RESULT
    if(t == NROUNDS) fout << 0 << endl;
    else fout << t << endl;

    return 0;
}
