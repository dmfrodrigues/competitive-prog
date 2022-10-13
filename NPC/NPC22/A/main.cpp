#include <bits/stdc++.h>
using namespace std;
#define FOR(i, b, e)            for(int i =(b); (i)  < (int)(e); ++(i))

int main(){
    int N; cin >> N;
    set<int> numbers;
    int x;
    for(int i = 0; i < N; ++i){
        cin >> x;
        numbers.insert(x);
    }
    for(int i = 0; i < N-1; ++i){
        cin >> x;
        numbers.erase(x);
    }
    cout << *numbers.begin() << endl;

    return 0;
}
