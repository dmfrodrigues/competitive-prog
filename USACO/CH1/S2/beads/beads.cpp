/*
ID: dmfrodr1
TASK: beads
LANG: C++11
*/
#include <bits/stdc++.h>

using namespace std;

int N;

int solve(string s){
    int l = 0;{
        char c = 'w';
        for(; l < N; ++l){
            if(s[l] != 'w'){
                if(c == 'w') c = s[l];
                else if(c != s[l]) break;
            }
            /*
            if(s[l] != 'w' && c == 'w') c = s[l];
            if(s[l] != 'w' && c != 'w' && c != s[l]) break;
            */
        }
    }
    int r = N-1;{
        char c = 'w';
        for(; r >= 0; --r){
            if(s[r] != 'w'){
                if(c == 'w') c = s[r];
                else if(c != s[r]) break;
            }
        }
    }
    int ret = min(l+(N-1-r), N);
    return ret;
}

int main(){
    ifstream fin("beads.in");
    ofstream fout("beads.out");

    fin >> N;
    string s; fin >> s;

    int ans = 0;
    for(int i = 0; i < N; ++i){
        string t = s.substr(N-i, i) + s.substr(0, N-i);
        int a = solve(t);
        ans = max(ans, a);
    }

    fout << ans << endl;

    return 0;
}
