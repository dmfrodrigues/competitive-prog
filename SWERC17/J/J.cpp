#include <bits/stdc++.h>
using namespace std;
#define FOR(i,n)        for (int i = 0; i < (n); i++)
typedef long long int lli;
typedef vector<lli> VI;

int main(){
    lli N; cin >> N;
    VI A(3, 0), B(3, 0);
    lli in;
    FOR(i, N){
        cin >> in;
        A[i%3] += in;
    }
    FOR(i, N){
        cin >> in;
        B[i%3] += in;
    }
    VI color = {A[0]*B[0] + A[2]*B[1] + A[1]*B[2],
                A[1]*B[0] + A[0]*B[1] + A[2]*B[2],
                A[2]*B[0] + A[1]*B[1] + A[0]*B[2]};
    cout << color[1] << " " << color[2] << " "<<color[0]<< endl;
    return 0;
}
