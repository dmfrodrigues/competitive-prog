#include <iostream>
#include <vector>
#include <deque>
#include <set>
#include <numeric>

using namespace std;

typedef unsigned int NumT;

deque<NumT> factorize(NumT N){
    deque<NumT> FactorsDqe;
    for(NumT n = 2; n <= N; ++n){
        while(N%n == 0){
            FactorsDqe.push_back(n);
            N /= n;
        }
    }
    return FactorsDqe;
}

NumT countToys(const multiset<NumT>& possibility){
    return accumulate(possibility.begin(), possibility.end(), 0) - possibility.size();
}

typedef set< multiset<NumT> > PossT;

set<NumT> solve(const deque<NumT>& Factors){
    const NumT& N = Factors.size();
    PossT possibilities;

    multiset<NumT> init_Multiset;
    init_Multiset.insert(Factors.front());
    possibilities.insert(init_Multiset);

//    possibilities.begin()->insert(Factors.front());
    PossT prev_possibilities;


//    cout << endl;
//    cout << "i = " << 0 << endl;
//    for(PossT::iterator it = possibilities.begin(); it != possibilities.end(); ++it){
//        for(multiset<NumT>::iterator it_ = it->begin(); it_ != it->end(); ++it_)
//            cout << *it_ << " ";
//        cout << endl;
//    }
//    cout << endl;


    multiset<NumT> tmp;
    for(NumT i = 1; i < N; ++i){

        prev_possibilities = possibilities;
        possibilities.clear();
        const NumT& currFactor = Factors[i];
        for(PossT::iterator it = prev_possibilities.begin(); it != prev_possibilities.end(); ++it){ ///Só acrescentar
            tmp = *it;
            tmp.insert(currFactor);
            possibilities.insert(tmp);
        }


//        cout << endl;
//        cout << "i = " << i << endl;
//        for(PossT::iterator it = possibilities.begin(); it != possibilities.end(); ++it){
//            for(multiset<NumT>::iterator it_ = it->begin(); it_ != it->end(); ++it_)
//                cout << *it_ << " ";
//            cout << endl;
//        }
//        cout << endl;




        for(PossT::iterator it = prev_possibilities.begin(); it != prev_possibilities.end(); ++it){
            const multiset<NumT>& curr_poss = *it;
            multiset<NumT> assist = curr_poss;
            for(multiset<NumT>::iterator it_ = assist.begin(); it_ != assist.end(); ++it_){
                tmp = curr_poss;
                tmp.erase(tmp.find(*it_));
                tmp.insert(*it_ * currFactor);
                possibilities.insert(tmp);
            }
        }



//        cout << endl;
//        cout << "i = " << i << endl;
//        for(PossT::iterator it = possibilities.begin(); it != possibilities.end(); ++it){
//            for(multiset<NumT>::iterator it_ = it->begin(); it_ != it->end(); ++it_)
//                cout << *it_ << " ";
//            cout << endl;
//        }
//        cout << endl;



    }




    set<NumT> Good;
    for(PossT::iterator it = possibilities.begin(); it != possibilities.end(); ++it){
        Good.insert(countToys(*it));
    }

    return Good;

}

int main(){
    NumT N;
//    while(true){
        cin >> N;
        deque<NumT> Factors = factorize(N);
//        cout << "Factors: ";
//        for(NumT i = 0; i < Factors.size(); ++i)
//            cout << Factors[i] << " ";
//        cout << endl;
//    }

    if(N == 1){
        cout << "1" << endl << "0" << endl;
        return 0;
    }


    set<NumT> solution = solve(Factors);
    cout << solution.size() << endl;
    for(set<NumT>::iterator it = solution.begin(); it != solution.end(); ++it){
        cout << *it << " ";
    }cout << endl;

    return 0;
}
