/**
 * Dynamic programming
 * 
 * (i,n) -> n slices starting at i (inclusive) have not been taken, and it is
 * now Andrew's turn to play.
 * i ∈ [0,N)
 * n ∈ [0,N]
 * 
 * Instead of maximizing slices taken, Andrew (optimal player) wants to maximize
 * the slices added to the pizza, starting from any possible final combination.
 * Then, Ben considers all possible initial positions, and picks the one that
 * maximizes his own amount of pizza.
 * 
 * The possible operations in reverse order are the following. Andrew can play
 * the next move if:
 *  1. He gave the previous slice to Ben
 *  2. Ben ate the previous slice, meaning Ben gave the slice before that to
 *     Andrew; because Ben alternates between giving and taking, we know that,
 *     before Ben ate and before Ben gave, Andrew had a chance to play and ate
 *     it, as such passing the turn to Ben
 * 
 * The final states are:
 * - Ben ate the last slice, passing turn to Andrew who can no longer do
 *   anything else because there are no more slices. In which case the final
 *   state is DP[i,0] = 0
 * - Andrew ate the last slice, either because:
 *   - it was his turn and he chose to eat it, in which case DP[i,1] = 0
 *   - or Ben gave Andrew a slice. Because Ben alternates between taking and
 *     giving, we know that, before Ben gave Andrew a slice, it was Andrew that
 *     ate a slice and then passed turn to Ben, in which case DP[i,2] = 0
 * 
 * The initial states are:
 *  1. Andrew starts, in which case DP[i,N-2] is a solution, and the score is
 *     DP[i,N-2].
 *  2. Ben starts, in which case he eats and passes turn to Andrew. In which
 *     case DP[i,N-3] is a solution, and the score is DP[i,N-3] plus the
 *     possibility of Ben having taken the left or right slice that is missing.
 *     Check for these two possible cases.
 */

#include <bits/stdc++.h>
using namespace std;
typedef long long int           lli;
typedef unsigned long long int  ulli;
#define ALL(v)                  (v).begin() , (v).end()
#define FOR(i, b, e)            for(lli i =(b); (i)  < (lli)(e); ++(i))
typedef vector<lli>             VI;
typedef vector<VI>              VVI;
typedef vector<VVI>             VVVI;
typedef vector<bool>            VB;
typedef vector<VB>              VVB;
typedef pair< lli, lli>         PII;
typedef pair<ulli,ulli>         PUU;
typedef pair<PII,PII>           PPP;
#define X first
#define Y second
const lli INF = 100000000;

int N;

int mod(lli i){
    return (i+N)%N;
}

int main(){
    cin >> N;
    VI slices(N);
    FOR(n,0,N) cin >> slices[n];
    
    VVI DP(N, VI(N+1, INF));

    // Final states
    FOR(i,0,N){
        DP[i][0] = 0;
        DP[i][1] = 0;
        DP[i][2] = 0;
    }

    // Computations
    FOR(n,0,(N-2)+1){
        FOR(i,0,N){
            // a b c [l ... r] d e f
            const lli l = i, r = mod(n+i-1);
            const lli a = mod(l-3), b = mod(l-2), c = mod(l-1);
            const lli d = mod(r+1), e = mod(r+2); //, f = mod(r+3);
            // 1. Andrew gave Ben the previous slice to Ben
            {
                // Andrew gave Ben slice c
                DP[c][n+1] = min(DP[b][n+1], DP[i][n] + slices[c]);
                // Andrew gave Ben slice d
                DP[l][n+1] = min(DP[l][n+1], DP[i][n] + slices[d]);
            }
            // 2. Ben ate the previous slice: continues
            if(n+3 <= N-2){
                // Ben had [c ... r] and ate slice c, leaving [l ... r]
                if(slices[c] >= slices[r]){
                    // Ben had [b ... r] and gave slice b, leaving [c ... r]
                    if(slices[b] >= slices[r]){
                        // Andrew had [a ... r] and ate slice a, leaving [b ... r]
                        DP[a][n+3] = min(DP[a][n+3], DP[i][n] + slices[c]);
                        // Andrew had [b ... d] and ate slice d, leaving [b ... r]
                        DP[b][n+3] = min(DP[b][n+3], DP[i][n] + slices[c]);
                    }
                    // Ben had [c ... d] and gave slice d, leaving [c ... r]
                    if(slices[d] >= slices[c]){
                        // Andrew had [b ... d] and ate slice b, leaving [c ... d]
                        DP[b][n+3] = min(DP[b][n+3], DP[i][n] + slices[c]);
                        // Andrew had [c ... e] and ate slice e, leaving [c ... d]
                        DP[c][n+3] = min(DP[b][n+3], DP[i][n] + slices[c]);
                    }
                }
                // Ben had [l ... d] and ate slice d, leaving [l ... r]
                if(slices[d] >= slices[l]){
                    // Ben had [c ... d] and gave slice c, leaving [l ... d]
                    if(slices[c] >= slices[d]){
                        // Andrew had [b ... d] and ate b, leaving [c ... d]
                        DP[b][n+3] = min(DP[b][n+3], DP[i][n] + slices[d]);
                        // Andrew had [c ... e] and ate e, leaving [c ... d]
                        DP[c][n+3] = min(DP[c][n+3], DP[i][n] + slices[d]);
                    }
                    // Ben had [l ... e] and gave slice e, leaving [l ... d]
                    if(slices[e] >= slices[l]){
                        // Andrew had [c ... e] and ate slice c, leaving [l ... e]
                        DP[c][n+3] = min(DP[c][n+3], DP[i][n] + slices[d]);
                        // Andrew had [l ... f] and ate slice f, leaving [l ... e]
                        DP[l][n+3] = min(DP[l][n+3], DP[i][n] + slices[d]);
                    }
                }
            }
        }
    }

    /*
    cout << "\nn:\t";
    FOR(n,0,N+1)
        cout << n << "\t";
    cout << endl;
    FOR(i,0,N){
        cout << "i: " << i << "\t";
        FOR(n,0,N+1){
            cout << DP[i][n] << "\t";
        }
        cout << endl;
    }
    */

    // Solutions
    // 1. Andrew starts
    lli sol = 0;
    FOR(i,0,N){
        const lli n = N-2;
        sol = max(sol, DP[i][n]);
    }
    // 2. Ben starts
    FOR(i,0,N){
        const lli n = N-3;
        const lli l = i, r = mod(n+i-1);
        const lli c = mod(l-1);
        const lli d = mod(r+1);

        // Ben had [c ... r] and ate slice c, leaving [l ... r]
        if(slices[c] >= slices[r]){
            lli newSol = DP[i][n] + slices[c];
            sol = max(sol, newSol);
        }
        // Ben had [l ... d] and ate slice d, leaving [l ... r]
        if(slices[d] >= slices[l]){
            lli newSol = DP[i][n] + slices[d];
            sol = max(sol, newSol);
        }
    }

    cout << sol << endl;

    return 0;
}
