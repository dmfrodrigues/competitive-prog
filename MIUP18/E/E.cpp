#include <bits/stdc++.h>
using namespace std;

int main(){
    int N; cin >> N;
    multiset<int> d;
    for(int in, i = 0; i < N; ++i){ cin >> in; d.insert(in); }
    while(!d.empty()){
        if(accumulate(d.begin(), d.end(), 0) != int(d.size()*(d.size()-1))){
            cout << "reject" << endl;
            return 0;
        }
        multiset<int> d_new;
        int c = *d.begin(); d.erase(d.begin());
        if(c%2){
            auto it = d.begin();
            while(it != d.end() && *it%2 == 0) ++it;
            assert(it != d.end());
            d_new.insert(*it-1); d.erase(it); c -= 1;
        }
        int n = d.size() - c/2;
        while(n--){
            int i = *d.begin(); d.erase(d.begin());
            if(i-2 < 0){
                cout << "reject" << endl;
                return 0;
            }
            d_new.insert(i-2);
        }
        d_new.insert(d.begin(), d.end());
        d = d_new;
    }
    cout << "fair" << endl;
    return 0;
}
