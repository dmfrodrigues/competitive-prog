#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;
#define two(n)          ( 1L << (n) )
#define contain(Set,i)  ( (Set) & two(i) )
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


/*
lli dist_const(lli x, lli y){
	 // axes symmetry 
	 x = abs(x);
	 y = abs(y);
	 // diagonal symmetry 
	 if (x < y) swap(x, y);
	 // 2 corner cases
	 if(x==1 && y == 0) return 3;
	 if(x==2 && y == 2) return 4;
	
	// main formula
	int delta = x-y;
	if(y>delta) return delta - 2*((delta-y)/3);
	else 		return delta - 2*((delta-y)/4);
}
*/
lli dist_const(lli x, lli y){
	x = abs(x);
	y = abs(y);
	if(y > x) swap(x, y);  
	if(x==2 && y==2) return 4;
	if(x==1 && y==0) return 3;

	if(y == 0 || 2*y <= x){
		lli xClass = x % 4;
		lli initX;
		if     (xClass == 0) initX = x/2;
		else if(xClass == 1) initX = 1 + (x/2);
		else if(xClass == 2) initX = 1 + (x/2);
		else                 initX = 1 + ((x+1)/2);

		if(xClass > 1) return initX - (y%2);
		else           return initX + (y%2);
	}else{
		lli diagonal = x - ((x-y)/2);
		if((x-y)%2 == 0){
			if(diagonal%3 == 0) return (diagonal/3)*2;
			if(diagonal%3 == 1) return ((diagonal/3)*2)+2;
			else                return ((diagonal/3)*2)+2;
		}else{
			return ((diagonal/3)*2)+1;
		}
	}
}


lli getdist(const lli N, const pii source, const pii& target){
	lli d = abs(source.V1 - target.V1) + abs(source.V2 - target.V2);
	if(d > 15){
		lli x = source.V1 - target.V1;
		lli y = source.V2 - target.V2;
		return dist_const(x, y);
	}else{
		VVI dist(N, VI(N, MAX_DIST));
		dist[source.V1][source.V2] = 0;
		deque< pair<lli, pii> > active; //cost so far, node
		active.push_back({dist[source.V1][source.V2], source});

		vector<pii> tmp;
		set<pii>::iterator it;
		while (!active.empty()){
			pii cur = active.front().second; active.pop_front();

			if(cur == target) return dist[cur.V1][cur.V2];

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
		return MAX_DIST;
	}
}

lli solve(const lli N, const vector<pii> inter){
	if(inter.size() <= 1) return 0;

	lli K = inter.size();
	VVI distMatrix(K, VI(K, 0));{
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

	VVI vtr(K, VI(two(K), MAX_DIST));
	VVI vtr_;

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
		vtr_ = vtr; vtr = VVI(K, VI(two(K), MAX_DIST));

		REP(curr, 1, (lli)vtr.size()){
			const VI& currvtr_ = vtr_[curr];
			//cout << "curr:" << curr << endl;
			FOR(state, (lli)currvtr_.size()){
				//cout << "state:" << bitset<BITSET_SZ>(state) << endl;
				if(currvtr_[state] == MAX_DIST) continue;
				REP(to, 1, K){ if(curr == to || contain(state, to)) continue;
					//cout << "to:" << to << endl;
					vtr[to][state + (1L<<(to))] = min(vtr[to][state + (1L<<(to))],
													  currvtr_[state]+distMatrix[curr][to]);
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
		ret = min(ret, *(vtr[i].end()-2) + distMatrix[i][0]);
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
