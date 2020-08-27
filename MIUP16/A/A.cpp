#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define FOR(i,b,e) for(lli (i)=(b); (i) < lli(e); (i)++)
typedef deque<lli> DI;
typedef pair<lli,lli> PII;

lli kadane(const DI &a, PII &best_range){
    best_range = PII(0,1);
    lli best = a[0], current = a[0];
    PII curr_range(0,1);
    FOR(i,0,a.size()){
        if(a[i] > current){
            current = a[i];
            curr_range = PII(i,i+1);
        }else{
            if(a[i] > 0){
                current += a[i];
                curr_range.second = i+1;
            }
        }
        if(best < current){
            best = current;
            best_range = curr_range;
        }
    }
    return best;
}

lli get_median(const DI &d, const PII &p){
    vector<lli> v(d.begin()+p.first, d.begin()+p.second);
    sort(v.begin(), v.end());
    lli sz = v.size();
    return v[sz/2];
}

void query(const DI &d){
    PII p;
    kadane(d, p);
    cout << p.first << " " << p.second-1 << " " << get_median(d, p) << endl;;
}

int main(){
    deque<lli> d;
    char c; lli in;
    cin >> c;
    while(c != 'x'){
        switch(c){
            case 'q': query(d); break;
            case 'u': cin >> in; d.push_back(in); break;
        }
        cin >> c;
    }
    return 0;
}
