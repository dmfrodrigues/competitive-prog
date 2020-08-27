#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

typedef int QueryT;
typedef long long int SzT;
typedef long long int NumT;

const SzT SzT_INVALID = numeric_limits<SzT>::max();

SzT getK(const vector<NumT>& vtr, const SzT& L, const SzT& i, const SzT& j){
    SzT ret = 0;
    for(SzT n = 0; n < L; ++n){
        if(vtr[i+n] != vtr[j+n]) ++ret;
    }
    return ret;
}

bool getK_bool(const vector<NumT>& vtr, const SzT& L, const SzT& i, const SzT& j){
    for(SzT n = 0; n < L; ++n){
        if(vtr[i+n] != vtr[j+n]) return 1;
    }
    return 0;
}

vector< vector<SzT> > initialize_Matrix(const vector<NumT>& vtr, const SzT& L){
    const SzT& N = vtr.size();
    vector< vector<SzT> > matrix(N-L+1, vector<SzT>(N-L+1, SzT_INVALID));
    for(SzT i = 0; i < N-L+1; ++i){
        for(SzT j = i; j < N-L+1; ++j)
        matrix[i][j] = matrix[j][i] = getK(vtr, L, i, j);
    }
    return matrix;
}

vector< vector<bool> > initialize_Matrix_bool(const vector<NumT>& vtr, const SzT& L){
    const SzT& N = vtr.size();
    vector< vector<bool> > matrix(N-L+1, vector<bool>(N-L+1, 0));
    for(SzT i = 0; i < N-L+1; ++i){
        for(SzT j = i; j < N-L+1; ++j)
            matrix[i][j] = matrix[j][i] = getK_bool(vtr, L, i, j);
    }
    return matrix;
}

int main(){
    SzT N, L; cin >> N >> L;
    vector<NumT> a(N);
    for(SzT i = 0; i < N; ++i)
        cin >> a[i];
    QueryT Q; cin >> Q;
    vector<SzT> queries(Q);
    for(QueryT i = 0; i < Q; ++i)
        cin >> queries[i];







    if(Q == 1 && queries[0] == 0){
        vector< vector<bool> > matrix = initialize_Matrix_bool(a, L);

        SzT ksimilar_to_i;

        for(SzT i = 0; i < N-L+1; ++i){
            ksimilar_to_i = count(matrix[i].begin(), matrix[i].end(), false) - 1;
            cout << ksimilar_to_i << " ";
        }
        cout << endl;

        return 0;
    }

    vector< vector<SzT> > matrix = initialize_Matrix(a, L);

    SzT ksimilar_to_i;
    for(QueryT j = 0; j < Q; ++j){
        const SzT k = queries[j];
        for(SzT i = 0; i < N-L+1; ++i){
            ksimilar_to_i = 0;
            for(SzT n = 0; n < N-L+1; ++n){
                if(matrix[i][n] <= k){
                    ++ksimilar_to_i;
                }
            }
            --ksimilar_to_i;
            cout << ksimilar_to_i << " ";
        }
        cout << endl;
    }

//    for()


//    for(qT i = 0; i < )
}
