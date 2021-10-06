/*
ID: dmfrodr1
TASK: ttwo
LANG: C++11
*/
#include <bits/stdc++.h>
using namespace std;
#define FOR(i,b,e) for(int (i) = (b); (i) < (e); ++(i))

struct pos_t: public pair<int,int> {
    pos_t():pair<int,int>(){}
    pos_t(int a, int b):pair<int,int>(a,b){}
    pos_t operator+(const pos_t &pos){
        return pos_t(this->first + pos.first, this->second + pos.second);
    }
};

enum orient_t{
    NORTH = 0,
    EAST  = 1,
    SOUTH = 2,
    WEST  = 3
};

pos_t delta(const orient_t &orient){
    switch(orient){
        case NORTH: return pos_t(-1, 0);
        case SOUTH: return pos_t(+1, 0);
        case EAST : return pos_t(0, +1);
        case WEST : return pos_t(0, -1);
    }
    throw invalid_argument("");
}

orient_t turn_right(const orient_t &orient){
    return orient_t((int(orient) + 1)%4);
}

const int N = 10;
vector< vector<int> > Map(N, vector<int>(N, 0));

const int NROUNDS = 160000;

void next_pos(pos_t &pos, orient_t &orient){
    pos_t next_pos = pos + delta(orient);
    bool is_outside  = !(0 <= next_pos.first  && next_pos.first  < 10 &&
                         0 <= next_pos.second && next_pos.second < 10);
    if(is_outside || Map[next_pos.first][next_pos.second]) orient = turn_right(orient);
    else                                                   pos    = next_pos;
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
            Map[i][j] = (s[j] == '*' ? 1 : 0);
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
