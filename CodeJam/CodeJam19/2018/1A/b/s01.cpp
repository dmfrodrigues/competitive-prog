#include <bits/stdc++.h>
#define FOR(i, n)               for(INT (i) = 0 ; (i)  < (n); ++(i))

using namespace std;

typedef long long int INT;
typedef vector<INT> VI;

bool isPossible(INT R, INT B, const VI& M, const VI& S, const VI& P, INT T){
    INT C = M.size();

    VI N(C);{
        FOR(i, C){
            N[i] = min(M[i], (T-P[i])/S[i]);
            N[i] = max(N[i], (INT)0);
        }
        sort(N.rbegin(), N.rend());
    }
    //cerr << "N: "; for(auto i:N) cerr << i << " "; cerr << endl;
    FOR(i, R){
        B -= N[i];
        if(B <= 0) return true;
    }
    return false;
}

INT solve(INT R, INT B, const VI& M, const VI& S, const VI& P){
    INT left = 0;
    INT right = numeric_limits<INT>::max();
    INT mid; bool b;
    //cerr << "[" << left << "," << right << "]" << endl;
    while(left < right-1){
        mid = (left+right-1)/2;
        b = isPossible(R, B, M, S, P, mid); //cerr << "mid=" << mid << ", possible:" << b << endl;
        if(b){
            right = mid+1;
        }else{
            left = mid+1;
        }
        //cerr << "[" << left << "," << right << "]" << endl;
    }
    return left;
}

int main(){
    INT T; cin >> T;
    FOR(t, T){
        INT R, B, C; cin >> R >> B >> C;
        VI M(C), S(C), P(C);
        FOR(i,C) cin >> M[i] >> S[i] >> P[i];
        INT ans = solve(R, B, M, S, P);
        printf("Case #%Ld: %Ld\n", t+1, ans);
    }
}
