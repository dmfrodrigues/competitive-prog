/*
ID: dmfrodr1
TASK: lamps
LANG: C++11
*/
#include <bits/stdc++.h>
#define FOR(i,b,e) for(int (i) = (b); (i) < (e); ++(i))

using namespace std;

int countbits(int n){
    int ret = 0;
    while(n){
        ret += n&1L;
        n >>= 1;
    }
    return ret;
}

bool is_consistent(const string &s, queue<int> on, queue<int> off){
    while(!on.empty()){
        int i = on.front(); on.pop();
        if(s[i-1] != '1') return false;
    }
    while(!off.empty()){
        int i = off.front(); off.pop();
        if(s[i-1] != '0') return false;
    }
    return true;
}

string makeString(int n, int N){
    string ret(N, '1');
    if(n&1) for(int i = 0; i < N; i += 1) ret[i] = (ret[i]-'0'+1)%2 + '0';
    if(n&2) for(int i = 0; i < N; i += 2) ret[i] = (ret[i]-'0'+1)%2 + '0';
    if(n&4) for(int i = 1; i < N; i += 2) ret[i] = (ret[i]-'0'+1)%2 + '0';
    if(n&8) for(int i = 0; i < N; i += 3) ret[i] = (ret[i]-'0'+1)%2 + '0';
    return ret;
}

int main(){
    ///INPUT
    ifstream fin("lamps.in");
    ofstream fout("lamps.out");
    int N, C; fin >> N >> C;
    int in;
    queue<int>  on; fin >> in; while(in != -1){ on.push(in); fin >> in; }
    queue<int> off; fin >> in; while(in != -1){off.push(in); fin >> in; }
    ///PROCESSING
    while(C >= 5) C -= 2;
    set<string> q;
    while(C >= 0){
        FOR(i, 0, 1L<<4){
            if(countbits(i) == C){
                string s = makeString(i, N);
                //cout << "s=" << s << endl;
                if(is_consistent(s, on, off)){
                    q.insert(s);
                }
            }
        }
        C -= 2;
    }
    if(q.empty()){
        fout << "IMPOSSIBLE" << endl;
    }else{
        for(const string &s:q){
            fout << s << endl;
        }
    }
    return 0;
}
