#include <bits/stdc++.h>
#define NUMT long
#define MAXN 1005

using namespace std;

struct RECT{
    NUMT r1, c1, r2, c2;
};
NUMT L, C, m, M;
vector<string> X;
const NUMT TRIALS = 10;
const NUMT FAILMAX = 100;

bool test1(const RECT r){
    NUMT h = r.r2 - r.r1 + 1;
    NUMT w = r.c2 - r.c1 + 1;
    if(w*h < 2*m || M < w*h) return false;
    NUMT Mus = 0, Tom = 0;
    for(NUMT i = r.r1; i <= r.r2; ++i){
        for(NUMT j = r.c1; j <= r.c2; ++j){
            if(X[i][j] == 'M') ++Mus;
            else               ++Tom;
        }
    }
    return (m <= Mus && Mus <= M && m <= Tom && Tom <= M);
}


bool S[MAXN][MAXN];
void makeTrial(list<RECT>& s, NUMT& a){
    for(NUMT i = 0; i < L; ++i)
        for(NUMT j = 0; j < C; ++j)
            S[i][j] = 0;


    a = 0;
    s = list<RECT>();
    NUMT failCount = 0;
    while(true){
        RECT r;
        do{
            r = { rand()%L, rand()%C,
                  rand()%L, rand()%C };
            if(r.r1 > r.r2) swap(r.r1, r.r2);
            if(r.c1 > r.c2) swap(r.c1, r.c2);
        }while(!test1(r));
        ///DAQUI SAI UM RETANGULO VALIDO EM TAMANHO E INGREDIENTES
        bool fits = true;
        for(NUMT i = r.r1; i <= r.r2; ++i){
            for(NUMT j = r.c1; j <= r.c2; ++j){
                if(S[i][j]){
                    fits = false;
                    break;
                }
            }
            if(!fits) break;
        }
        if(fits){
            failCount = 0;
            for(NUMT i = r.r1; i <= r.r2; ++i)
                for(NUMT j = r.c1; j <= r.c2; ++j)
                    S[i][j] = 1;
            a += (r.r2-r.r1+1)*(r.c2-r.c1+1);
            s.push_back(r);
        }else{
            ++failCount;
            if(failCount >= FAILMAX) break;
        }
    }

}

int main(){
    ///INPUT
    cin >> L >> C >> m >> M;
    X = vector<string>(L);
    for(NUMT l = 0; l < L; ++l)
        cin >> X[l];
    ///PROCESSING
    list<RECT> sAbs; NUMT aAbs = 0;
    list<RECT> s   ; NUMT a    = 0;
    for(NUMT trial = 0; trial < TRIALS; ++trial){
        //cout << "trial: " << trial << endl;
        makeTrial(s, a);
        if(a > aAbs){
            aAbs = a;
            sAbs = s;
        }
    }
    ///OUTPUT
    cout << "MAX=" << L*C << endl;
    cout << aAbs << endl;
    cout << sAbs.size() << endl;
    /*
    for(const auto& r:sAbs){
        cout << r.r1 << " " << r.c1 << " " << r.r2 << " " << r.c2 << endl;
    }
    */
    /*
    for(NUMT i = 0; i < L; ++i){
        for(NUMT j = 0; j < C; ++j){
            cout << S[i][j];
        }
        cout << endl;
    }
    */
    return 0;
}
