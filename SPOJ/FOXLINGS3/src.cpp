#include <bits/stdc++.h>

using namespace std;
#define ALL(v)          (v).begin() , (v).end()

#define FOR(i,n)        for (int i = 0; i < (n); i++)
#define REP(i, b, e)    for (typeof(e) i=b; i!=e; ++i)

typedef long long int lli;
typedef pair<lli,lli> pii;

const int& INF = numeric_limits<int>::max();

struct node{ int p, rank, number; };
class uf: public vector<node>{
public:
	int sets;

	uf(int s):vector<node>(s){
		sets = s;
		uf& me = *this;
		FOR(i,s)
			me[i] = {i,0,1};
	}

	void link(const int& x, const int& y) {
		uf& me = *this;
		if(x == y) return;
		if (me[x].rank <= me[y].rank) {
			me[x].p = y;
			--sets;
			me[y].number += me[x].number;
			if (me[x].rank == me[y].rank)
				me[y].rank++;
		} else link(y, x);
	}

	int find_set(const int& x) {
		uf& me = *this;
		if (x != me[x].p)
			me[x].p = find_set(me[x].p);
		return me[x].p;
	}
	//Esta funcao pode nao ser importante
	int find_length(const int& x) {
		uf& me = *this;
		return me[find_set(me[x].p)].number;
	}

	void union_set(const int& x, const int& y) {
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
