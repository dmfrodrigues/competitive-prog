#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;
#define two(n)          ( 1L << (n) )
#define contain(Set,i)  ( (Set) & two(i) )
//#define ALL(v)          (v).begin() , (v).end()
#define FOR(i,n)        for (lli i = 0; i < (n); i++)
#define REP(i, b, e)    for (lli i=b; i<e; ++i)
#define V1              first
#define V2              second
typedef pair<lli,lli> pii;
typedef vector<lli> VI;
typedef vector<VI> VVI;

const lli MAX_DIST = numeric_limits<lli>::max();

inline bool is_valid_pt(const pii& pt, const lli& N){
	return (0 <= pt.first  && pt.first  < N &&
		    0 <= pt.second && pt.second < N);
}

lli heuristic_estimate(const pii& pt1, const pii& pt2){
	return 3*(abs(pt2.V1 - pt1.V1) + abs(pt2.V2 - pt1.V2));
}

lli getdist(const lli& N, const pii& source, const pii& target){
	set<pii> closedSet;
	set<pii> openSet; openSet.insert(source);
	map<pii, lli> cameFrom;
	map<pii, lli> gScore;
	gScore[source] = 0;
	map<pii, lli> fScore;
	fScore[source] = heuristic_estimate(source, target);
	while(!openSet.empty()){
		lli current = 
	}
/*

	VVI dist(N, VI(N, MAX_DIST));
	dist[source.V1][source.V2] = 0;
	deque< pair<lli, pii> > active; //cost so far, node
	active.push_back({dist[source.V1][source.V2], source});

	set<pii> targets_set(targets.begin(), targets.end());

	vector<pii> tmp;
	set<pii>::iterator it;
	while (!active.empty()){
		pii cur = active.front().second; active.pop_front();

		it = targets_set.find(cur);
		if(it != targets_set.end()){
			targets_set.erase(it);
			if(targets_set.empty()) break;
		}

		tmp = {
			{cur.V1+2, cur.V2+1}, //
			{cur.V1+2, cur.V2-1}, //
			{cur.V1-2, cur.V2+1}, //
			{cur.V1-2, cur.V2-1}, //
			{cur.V1+1, cur.V2+2}, //
			{cur.V1+1, cur.V2-2}, //
			{cur.V1-1, cur.V2+2}, //
			{cur.V1-1, cur.V2-2}  //
		};
		for(const auto& to:tmp){
			if(is_valid_pt(to, N) && dist[to.V1][to.V2] > dist[cur.V1][cur.V2]+1){
				dist[to.V1][to.V2] = dist[cur.V1][cur.V2]+1;
				active.push_back({dist[to.V1][to.V2], to});
			}
		}

	}

	VI ret(targets.size());
	FOR(i, (lli)targets.size()){
		const pii& pt = targets[i];
		ret[i] = dist[pt.V1][pt.V2];
	}
	return ret;
*/
}

lli solve(const lli& N, vector<pii> inter){
	if(inter.size() <= 1) return 0;
	//sort(ALL(inter));
	lli K = inter.size();
	VVI distMatrix(K);{
		/*
		FOR(i, K){
			distMatrix[i] = dijkstra(N, inter[i], inter);
		}
		*/
		FOR(i, K){
			distMatrix[i][i] = 0;
			REP(j, i+1, K){
				distMatrix[i][j] = distMatrix[j][i] = getdist(N, inter[i], inter[j]);
			}
		}
	}
	/*
	FOR(i, (int)distMatrix.size()){
		cout << "i=" << i << " ";
		FOR(j, (int)distMatrix[i].size()) cout << distMatrix[i][j] << " ";
		cout << endl;
	} cout << endl;
	*/
	vector< map<lli, lli> > vtr(K);
	vector< map<lli, lli> > vtr_;

	REP(curr, 1, K){
		vtr[curr][two(curr)] = distMatrix[0][curr];
	}

	FOR(round, K-2){
		/*
		cout << endl << endl << "ROUND=" << round << endl;
		FOR(curr, (int)vtr.size()){
			cout << "curr=" << curr << endl;
			FOR(state, (int)vtr[curr].size())
				cout << "    state=" << bitset<BITSET_SZ>(state) << " " << vtr[curr][state] << endl;
		}
		*/
		//vtr_ = vtr; vtr = VVI(K, VI(two(K), MAX_DIST));

		REP(curr, 1, (lli)vtr.size()){
			const auto& currvtr_ = vtr_[curr];
			//cout << "curr:" << curr << endl;
			for(const auto& state:currvtr_){
				//cout << "state:" << bitset<BITSET_SZ>(state) << endl;
				//if(currvtr_[state] == MAX_DIST) continue;
				REP(to, 1, K){
					if(curr != to && !contain(state.first, to)){
					//cout << "to:" << to << endl;
						if(vtr[to].find(state.first + two(to)) == vtr[to].end())
							vtr[to][state.first + two(to)] = MAX_DIST;
						vtr[to][state.first + two(to)] = min(vtr[to][state.first + two(to)], state.second+distMatrix[curr][to]);
					}
				}
			}
		}

	}
	/*
	cout << endl << endl << "END" << endl;
	FOR(curr, (lli)vtr.size()){
		cout << "curr=" << curr << endl;
		FOR(state, (lli)vtr[curr].size())
			cout << "    state=" << bitset<BITSET_SZ>(state) << " " << vtr[curr][state] << endl;
	}
	*/


	lli ret = MAX_DIST;
	REP(i, 1, K){
		ret = min(ret, (--vtr[i].end())->second + distMatrix[i][0]);
	}
	return ret;
}

int main(){
	lli T; cin >> T;
	FOR(t, T){
		lli N, K; cin >> N >> K;
		vector<pii> interesting(K);
		for(auto& p:interesting){
			cin >> p.first >> p.second;
			--p.first; --p.second;
		}
		lli ans = solve(N, interesting);
		cout << ans << endl;
	}
	return 0;
}
