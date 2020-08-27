#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

typedef long int NumT;

vector<NumT> FcnFibonacci(const NumT& N){
    vector<NumT> ret(N+1);
    ret[0] = ret[1] = 1;
    for(NumT i = 2; i <= N; ++i){
        ret[i] = (ret[i-1] + ret[i-2])%(1000000000+7);
    }
    return ret;
}

bool isValid(const multiset<NumT>& Poss){
    for(multiset<NumT>::const_iterator it = Poss.begin(), it_ = ++Poss.begin(); it_ != Poss.end(); ++it, ++it_){
        if(*it == *it_) return false;
    }
    return true;
}

NumT solve(NumT x, const vector<NumT>& FibonacciVtr){
    multiset<NumT> possibility0;
    while(x != 0){
        NumT i = (--upper_bound(FibonacciVtr.begin(), FibonacciVtr.end(), x)) - FibonacciVtr.begin();
        possibility0.insert(i);
        x -= FibonacciVtr[i];
    }

    set< multiset<NumT> > possibilities;
    possibilities.insert(possibility0);

    NumT ret = 0;
    multiset<NumT> currPoss;
    multiset<NumT> assist;
    multiset<NumT> tmp;

//    cout << "POSS:" << endl;
//    for(set< multiset<NumT> >::iterator it = possibilities.begin(); it != possibilities.end(); ++it){
//        for(multiset<NumT>::iterator it_ = it->begin(); it_ != it->end(); ++it_)
//            cout << *it_ << " ";
//        cout << endl;
//    }cout << endl;



    while(possibilities.size() != 0){
        currPoss = *(--possibilities.end());
        possibilities.erase(--possibilities.end());
        if(isValid(currPoss)) ++ret;
        multiset<NumT> assist = currPoss;
        for(multiset<NumT>::iterator it = assist.begin(); it != assist.end(); ++it){
            if(*it-2 < 1) continue;
            tmp = currPoss;
            tmp.erase(tmp.find(*it));
            tmp.insert(*it - 1); tmp.insert(*it - 2);
            possibilities.insert(tmp);
        }

//        cout << "POSS:" << endl;
//        for(set< multiset<NumT> >::iterator it = possibilities.begin(); it != possibilities.end(); ++it){
//            for(multiset<NumT>::iterator it_ = it->begin(); it_ != it->end(); ++it_)
//                cout << *it_ << " ";
//            cout << endl;
//        }cout << endl;





    }

    return ret;
}

int main(){
    NumT N;
    cin >> N;
    vector<NumT> a(N);
    for(NumT i = 0; i < N; ++i)
        cin >> a[i];


    vector<NumT> FibonacciVtr = FcnFibonacci(105);

    NumT val = 0;
    for(NumT i = 0; i < N; ++i){
        val += FibonacciVtr[a[i]];
        cout << solve(val, FibonacciVtr) << endl;
    }
}
