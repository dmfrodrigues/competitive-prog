/*
ID: dmfrodr1
TASK: contact
LANG: C++11
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long int           lli;
typedef unsigned long long int  ulli;
#define ALL(v)                  (v).begin() , (v).end()
#define FOR(i, b, e)            for(lli i =(b); (i)  < (lli)(e); ++(i))
typedef vector<lli>             VI;
typedef vector<VI>              VVI;
typedef vector<bool>            VB;
typedef vector<VB>              VVB;
typedef pair< lli, lli>         PII;
typedef pair<ulli,ulli>         PUU;
typedef pair<PII,PII>           PPP;
#define X first
#define Y second
const lli INF = 1000000000;

long decode(vector<bool>::const_iterator a, vector<bool>::const_iterator b){
    long res = 0;
    while(a != b) res = (res << 1) + *(a++);
    return res;
}

vector<bool> encode(long n, size_t s){
    vector<bool> res(s);
    FOR(i,0,s){
        res[s-1-i] = (n%2);
        n >>= 1;
    }
    return res;
}

int main(){
    ifstream fin("contact.in");
    ofstream fout("contact.out");

    ///INPUT
    size_t A, B, N; fin >> A >> B >> N;
    list<string> strs;
    string sin;
    while(fin >> sin){
        strs.push_back(sin);
    }
    size_t C = 0;
    for(const string &s: strs){
        C += s.size();
    }
    vector<bool> v(C);
    size_t i = 0;
    for(const string &s: strs)
        for(const char &c: s)
            v.at(i++) = (c == '1');

    B = min(B, v.size());
    A = min(A, B);

    ///PROCESSING
    map<long, list<vector<bool>>> frequencies;
    FOR(i,A,B+1){
        long sz = 1<<i;
        long mask = sz-1;
        vector<long> f(sz);
        {
            long p = decode(v.begin(), v.begin()+i);
            ++f.at(p);
            FOR(j,i,v.size()){
                p = ((p << 1) & mask) + v.at(j);
                ++f.at(p);
            }
        }
        FOR(p, 0, f.size()){
            frequencies[f.at(p)].push_back(encode(p, i));
        }
    }

    while(frequencies.size() > N)
        frequencies.erase(frequencies.begin()->first);

    ///OUTPUT
    for(auto it = frequencies.rbegin(); it != frequencies.rend(); ++it){
        auto p = *it;
        if(p.first <= 0) break;
        fout << p.first;
        int idx = 0;
        for(const vector<bool> &v: p.second){
            if(idx == 0) fout << endl; else fout << " ";
            for(const bool &b: v) fout << (b ? '1' : '0');
            idx = (idx+1)%6;
        }
        fout << endl;
    }

    return 0;
}
