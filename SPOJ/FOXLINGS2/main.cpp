#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>

#define MAX 500000L

using namespace std;

typedef long long int lli;
typedef pair<lli,lli> pii;

struct uf{
    int p[MAX], rank[MAX], number[MAX];
    int size, sets;

    uf(int s){
        size = sets = s;
        for (int i = 0; i < size; i++){
            p[i]=i;
            rank[i]=0;
            number[i]=1;
        }
    }

    void link(int x, int y){
        if(x == y) return;
        if (rank[x] <= rank[y]){
            p[x] = y;
            --sets;
            number[y] += number[x];
            if (rank[x] == rank[y])
                rank[y]++;
        }
        else link(y, x);
    }
//
    int find_set(int x){
        if (x != p[x]) p[x] = find_set(p[x]);
        return p[x];
    }
//
//    int find_length(int x){
//        return number[ find_set(p[x]) ];
//    }
//
    void union_set(int x, int y){
        link(find_set(x), find_set(y));
    }
};

lli solveforme(lli sz, vector<pii> Edges){
    unordered_map<lli,lli> corresp;{
        unordered_set<lli> have_friends_set;
        for(const auto& e:Edges){
            have_friends_set.insert(e.first);
            have_friends_set.insert(e.second);
        }
        lli i = 0;
        for(const auto& obj:have_friends_set){
            corresp[obj] = i++;
        }
    }
    const lli& N = corresp.size();

    uf unionfind(N);
    for(const auto& e:Edges){
        unionfind.union_set(corresp[e.first], corresp[e.second]);
    }

    lli ret = 0;
    {
        lli curr;
        vector<bool> is_counted(N, false);
        for(lli i = 0; i < N; ++i){
            curr = unionfind.find_set(i);
            if(!is_counted[curr]){
                is_counted[curr] = true;
                ++ret;
            }
        }
    }

    lli do_not_have_friends = sz - N;

    ret += do_not_have_friends;

    return ret;
}

int main(){
/*
9 5
3 1
6 1
7 6
2 7
8 9


*/

    lli N, M; cin >> N >> M;
    vector<pii> Edges(M);{
        for(auto& e:Edges){
            cin >> e.first >> e.second;
            --e.first; --e.second;
        }
    }
    lli ans = solveforme(N, Edges);
    cout << ans << endl;
    return 0;
}

