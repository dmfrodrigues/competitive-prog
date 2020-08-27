#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long  ULLI;
#define ALL(v)                  (v).begin(), (v).end()
#define FOR(i, n)               for(int (i) =   0; (i) != (n); ++(i))
#define REP(i, b, e)            for(int (i) = (b); (i) != (e); ++(i))
typedef vector<ULLI>             VI;

bool solve(int N, int B, int F){ //cerr << endl;
    vector<string> data(5);{
        for(int i = 0, n = 1; i < 5; ++i, n <<= 1){
            string s = "";
            while(s.size() < N)
                s += string(n,'0')+string(n, '1');
            s.erase(N);
            //cerr << "ask " << s << endl;
            cout << s << endl;
            cin >> data[i];
            //cerr << "ans " << data[i] << endl;
        }
        //cerr << endl;
    }
    vector<int> w;{
        string s = data[4];
        for(int i = 0; i < N; i += 32){
            int k;

            k = s.find_first_not_of('0');
            if(k == string::npos){
                w.insert(w.end(), s.size(), i);
                break;
            }
            w.insert(w.end(), k, i   ); s.erase(0, k);

            k = s.find_first_not_of('1');
            if(k == string::npos){
                w.insert(w.end(), s.size(), i+16);
                break;
            }
            w.insert(w.end(), k, i+16); s.erase(0, k);
        }
    }
    for(int n = 1, i = 0; i < 5-1; ++i, n <<= 1){
        const string& cur = data[i];
        FOR(j, N-B){
            if(cur[j] == '1'){
                w[j] += n;
            }
        }
    }
    //for(auto i:w) cerr << i << " ";// cerr << endl;
    set<int> s(ALL(w));
    bool first = true;
    //cerr << "resp -";

    for(int i = 0; i < N; ++i){
        if(s.find(i) == s.end()){
            if(first){ cout <<        i;/* cerr <<        i;*/ first = false; }
            else     { cout << " " << i;/* cerr << " " << i; */               }
        }
    }
    //cerr << "-" << endl;
    //cerr << "L60" << endl;
    cout << endl;

    int b;
    cin >> b;
    return (b == 1);
}

int main(){
    int T; cin >> T;
    for(int t = 0; t < T; ++t){
        int N, B, F; cin >> N >> B >> F;
        if(!solve(N,B,F)) return 0;
    }
    return 0;
}
