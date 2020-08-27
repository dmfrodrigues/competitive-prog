#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <limits>

using namespace std;

typedef long long int SzT;
typedef long long int NumT;

const NumT NumT_MAX = numeric_limits<NumT>::max();
const NumT NumT_MIN = numeric_limits<NumT>::min();

SzT LIS(vector<NumT> vtr){
    const SzT& N = vtr.size();
    vector<NumT> tmp(N+1, NumT_MAX); tmp[0] = NumT_MIN;
    SzT ret = 0;
    for(vector<NumT>::iterator it = vtr.begin(); it < vtr.end(); ++it){
        SzT newSz = lower_bound(tmp.begin(), tmp.begin()+ret+1, *it) - tmp.begin();
        ret = max(ret, newSz);
        if(tmp[newSz] == NumT_MAX){
            tmp[newSz] = *it;
        }else{
            tmp[newSz] = min(tmp[newSz], *it);
        }
    }
    return ret;
}

vector<NumT> LIS_complete(vector<NumT> vtr){
    const SzT& N = vtr.size();
    vector<NumT> tmp(N+1, NumT_MAX); tmp[0] = NumT_MIN;
    vector<SzT> LIS(N);
    SzT ret = 0;
    for(SzT i = 0; i < N; ++i){
        LIS[i] = lower_bound(tmp.begin(), tmp.begin()+ret+1, vtr[i]) - tmp.begin();
        ret = max(ret, LIS[i]);
        if(tmp[LIS[i]] == NumT_MAX){
            tmp[LIS[i]] = vtr[i];
        }else{
            tmp[LIS[i]] = min(tmp[LIS[i]], vtr[i]);
        }
    }
    return LIS;
}

int main(){
    SzT N; cin >> N;
    NumT X; cin >> X;
    vector<NumT> vtr(N);
    for(SzT i = 0; i < N; ++i)
        cin >> vtr[i];

    SzT answer;

    if(X == 0){
        answer = LIS(vtr);
        cout << answer << endl;
        return 0;
    }

    if(X == 1000000000){
        vector<SzT> leftVtr = LIS_complete(vtr);

        vector<NumT> vtr_ = vtr;
        reverse(vtr_.begin(), vtr_.end());
        for(vector<NumT>::iterator it = vtr_.begin(); it < vtr_.end(); ++it) *it = X-(*it);
        vector<SzT> rightVtr = LIS_complete(vtr);
        reverse(rightVtr.begin(), rightVtr.end());

        for(SzT i =   1; i <  N; ++i) leftVtr [i] = max(leftVtr [i], leftVtr [i-1]);
        for(SzT i = N-2; i >= 0; --i) rightVtr[i] = max(rightVtr[i], rightVtr[i+1]);

//        for(int i = 0; i < N; ++i){
//            cout << leftVtr[i] << "     " << rightVtr[i] << endl;
//        }

        answer = rightVtr[0];
        SzT tmp;
        for(SzT i = 0; i < (SzT)rightVtr.size()-1; ++i){
            tmp = leftVtr[i] + rightVtr[i+1];
            answer = max(answer, tmp);
        }

        cout << answer << endl;
        return 0;

    }



    answer = LIS(vtr);
    for(SzT a = N-1; a > 0; --a){
//        cout << answer << endl;
        vtr[a] += X;
        answer = max(answer, LIS(vtr));
    }
    cout << answer << endl;
    return 0;
}
