#include <iostream>
#include <vector>
#include <set>

using namespace std;

typedef long long int NumT;

void Fix_MajorRepresentation(multiset<NumT>& obj){
    multiset<NumT>::iterator it = obj.begin(); ++it;
    multiset<NumT>::iterator it_;
    multiset<NumT>::iterator it__;
    while(it != obj.end()){
        it_ = it; --it_;
        if(*it - *it_ == 1){
            it__ = obj.insert(*it + 1);
            obj.erase(it);
            obj.erase(it_);
            it = it__;
        }
        ++it;
    }

}

long long solve(const multiset<NumT>& MajorRepresentation){

}

int main(){
    NumT N;
    cin >> N;
    vector<NumT> a(N);
    for(NumT i = 0; i < N; ++i)
        cin >> a[i];

    vector<long long> solutions(N);
    multiset<NumT> MajorRepresentation;
    for(int i = 0; i < N; ++i){
        MajorRepresentation.insert(a[i]);
        Fix_MajorRepresentation(MajorRepresentation);

//        cout << "i= " << i << endl;
//        for(multiset<NumT>::iterator it = MajorRepresentation.begin(); it != MajorRepresentation.end(); ++it)
//            cout << *it << endl;
//        cout << endl;


        solutions[i] = solve(MajorRepresentation);
    }
    for(int i = 0; i < N; ++i)
        cout << solutions[i] << endl;
}
