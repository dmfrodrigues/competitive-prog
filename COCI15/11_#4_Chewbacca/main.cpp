/// https://dmoj.ca/problem/coci15c4p4
#include <iostream>
#include <vector>
#include <deque>

using namespace std;

typedef long long int NumT;

vector<NumT> solve(const NumT& N, const NumT& K, const vector< pair<NumT,NumT> >& queries){

    vector<NumT> ret(queries.size());

    for(NumT i = 0; i < queries.size(); ++i){

        deque<NumT> dqe_first;
        dqe_first.push_front(queries[i].first);
        while(dqe_first.front() != 1)
            dqe_first.push_front((dqe_first.front()-2)/K + 1);

        deque<NumT> dqe_second;
        dqe_second.push_front(queries[i].second);
        while(dqe_second.front() != 1)
            dqe_second.push_front((dqe_second.front()-2)/K + 1);

        while(dqe_first.front() == dqe_second.front()){
            dqe_first.pop_front();
            dqe_second.pop_front();
        }

        ret[i] = dqe_first.size() + dqe_second.size();

    }

    return ret;
}

int main(){
    NumT N, K, Q;
    cin >> N >> K >> Q;
    vector< pair<NumT,NumT> > queries(Q);
    for(NumT i = 0; i < Q; ++i)
        cin >> queries[i].first >> queries[i].second;

    vector<NumT> solution = solve(N, K, queries);

    for(NumT i = 0; i < solution.size(); ++i)
        cout << solution[i] << endl;

    return 0;
}
