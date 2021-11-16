#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;
#define ALL(v) (v).begin(), (v).end()

int main(){
    int P; cin >> P;
    vector<string> s(P); vector<int> v(P);{
        for(int i = 0; i < P; ++i){
            cin >> s[i] >> v[i];
            v[i] *= 100;
        }
    }
    int sum_all = 0, min_all = 0, max_all = 0;{
        for(int i = 0; i < P; ++i){
            sum_all += v[i];
            min_all += max(0    , v[i]-50);
            max_all += min(10000, v[i]+49);
        }
    }
    if(min_all > 10000 || max_all < 10000){
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    vector<PII> ret(P);
    for(int i = 0; i < P; ++i){
        int min_rest = min_all - max(0    , v[i]-50);
        int max_rest = max_all - min(10000, v[i]+49);
        int a = 10000-max_rest, b = 10000-min_rest;
        a = max(a, v[i]-50); b = min(b, v[i]+49);
        a = max(a, 0); b = min(b, 10000);
        ret[i] = PII(a,b);
    }
    cout << setprecision(2) << fixed;
    for(int i = 0; i < P; ++i){
        int a = ret[i].first, b = ret[i].second;
        cout << s[i] << " " << a/100.0 << " " << b/100.0 << endl;
    }
    return 0;
}
