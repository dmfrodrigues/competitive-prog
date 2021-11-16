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

bool S[MAXN][MAXN];
bool checkFits(RECT R){
    for(NUMT i = R.r1; i <= R.r2; ++i)
        for(NUMT j = R.c1; j <= R.c2; ++j)
            if(S[i][j]) return false;
    return true;
}
void fillRECT(RECT R){
    for(NUMT i = R.r1; i <= R.r2; ++i)
        for(NUMT j = R.c1; j <= R.c2; ++j)
            S[i][j] = 1;
}

bool isValidRECT(const RECT r){
    if(r.r1 < 0 || r.c1 < 0 || r.r2 >= L || r.c2 >= C)
        return false;
    NUMT h = r.r2 - r.r1 + 1;
    NUMT w = r.c2 - r.c1 + 1;
    if(w*h < 2*m || M < w*h) return false;
    NUMT Mus = 0, Tom = 0;
    for(NUMT i = r.r1; i <= r.r2; ++i)
        for(NUMT j = r.c1; j <= r.c2; ++j)
            if(X[i][j] == 'M') ++Mus;
            else               ++Tom;
    return (m <= Mus && m <= Tom);
}

void emptyRECT(RECT R){
    for(NUMT i = R.r1; i < R.r2; ++i)
        for(NUMT j = R.c1; j < R.c2; ++j)
            S[i][j] = 0;
}

void makeTrial(list<RECT>& s, NUMT& a, RECT r){
    //emptyRECT(r);
    a = 0;
    s = list<RECT>();
    NUMT failCount = 0;
    while(true){
        //cout << "INSIDE MAKETRIAL" << endl;
        RECT R;
        do{
            R = { r.r1+rand()%(r.r2-r.r1), r.c1+rand()%(r.c2-r.c1),
                  r.r1+rand()%(r.r2-r.r1), r.c1+rand()%(r.c2-r.c1) };
            if(R.r1 > R.r2) swap(R.r1, R.r2);
            if(R.c1 > R.c2) swap(R.c1, R.c2);
            ++failCount;
        }while(!isValidRECT(R) && failCount < FAILMAX);
        if(failCount >= FAILMAX) break;
        ///DAQUI SAI UM RETANGULO VALIDO EM TAMANHO E INGREDIENTES
        if(checkFits(R)){
            failCount = 0;
            fillRECT(R);
            a += (R.r2-R.r1+1)*(R.c2-R.c1+1);
            s.push_back(R);
        }else{
            ++failCount;
            if(failCount >= FAILMAX) break;
        }
    }

}

list<RECT> solveRECT(RECT R){
    RECT r = R; --r.r2; --r.c2;
    if(isValidRECT(r)){
        return list<RECT>(1, r);
    }

    list<RECT> sAbs; NUMT aAbs = 0;
    list<RECT> s   ; NUMT a    = 0;
    for(NUMT trial = 0; trial < TRIALS; ++trial){
        //cout << "TRIAL=" << trial << endl;
        emptyRECT(R);
        //cout << "AFTER EMPTYRECT" << endl;
        makeTrial(s, a, R);
        //cout << "AFTER MAKETRIAL" << endl;
        if(a > aAbs){
            aAbs = a;
            sAbs = s;
        }
    }
    return sAbs;
}

NUMT countArea(const list<RECT>& ans){
    NUMT total = 0;
    for(const auto& it:ans)
        total += (it.r2-it.r1+1)*(it.c2-it.c1+1);
    return total;
}

int main(){
    ///INPUT
    cin >> L >> C >> m >> M;
    X = vector<string>(L);
    for(NUMT l = 0; l < L; ++l)
        cin >> X[l];
    ///PROCESSING
    list<RECT> ans;
    NUMT w = 1; //250
    NUMT h = 30; //200
    auto t1 = chrono::high_resolution_clock::now();
    for(NUMT l = 0; l+w <= C; l += h){
        for(NUMT u = 0; u+h <= L; u += w){
            //cout << "l,u=" << l <<"," << u << endl;
            auto lst = solveRECT({u, l, u+w, l+h});
            //cout << "done" << endl;
            for(const auto& it:lst)
                ans.push_back(it);
        }
    }
    auto t2 = chrono::high_resolution_clock::now();
    chrono::duration<double> time_span = chrono::duration_cast<chrono::duration<double>>(t2 - t1);
    ///OUTPUT
    cout << "TOOK " << time_span.count() << " SECONDS" << endl;
    cout << "MAX:" << L*C << endl;
    cout << "Total so far:" << countArea(ans) << endl;
    cout << ans.size() << endl;
    ///EXPAND

    emptyRECT({0,0,L,C});
    for(const auto& it:ans)
        fillRECT(it);


    for(NUMT i = 0; i < 100; ++i){
        list<RECT> l; NUMT a;
        makeTrial(l, a, {0,0,L,C});
        for(const auto& it:l)
            ans.push_back(it);
    }
    cout << "Total so far:" << countArea(ans) << endl;
    cout << ans.size() << endl;


    //for(const auto& r:ans) cout << r.r1 << " " << r.c1 << " " << r.r2 << " " << r.c2 << endl;


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
