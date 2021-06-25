#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <chrono>
#include <algorithm>

using namespace std;

const float TimeLimit = 10.0; ///330.0segundos é aprox. 5min30s
const int EXP = 20;

typedef long long int lli;
typedef pair<lli,lli> Point;

enum Tile{EMPTY, ROCK, BUSH};

class Map: public vector< vector<Tile> >{
public:
    lli x_sz;
    lli y_sz;
    Map(const lli& x_, const lli& y_, const Tile& obj):vector< vector<Tile> >(x_, vector<Tile>(y_, obj)),x_sz(x_),y_sz(y_){}
    void print(ofstream& strm){
        const Map& curr = *this;
        for(lli y = 0; y < y_sz; ++y){
            for(lli x = 0; x < x_sz; ++x){
                switch(curr[x][y]){
                    case EMPTY: strm << "."; break;
                    case ROCK:  strm << "#"; break;
                    case BUSH:  strm << "X"; break;
                    default:    strm << "\nERROR\n"; return;
                }
            }
            strm << "\n";
        }
    }
    void print(){
        const Map& curr = *this;
        for(lli y = 0; y < y_sz; ++y){
            for(lli x = 0; x < x_sz; ++x){
                switch(curr[x][y]){
                    case EMPTY: cout << "."; break;
                    case ROCK:  cout << "#"; break;
                    case BUSH:  cout << "X"; break;
                    default:    cout << "\nERROR\n"; return;
                }
            }
            cout << "\n";
        }
    }
};

short int countNeighbours(const Point& pt, const Map& myMap){
    const lli& XMAX = myMap.size(); const lli& YMAX = myMap[0].size();
    const lli& x = pt.first; const lli& y = pt.second;
    short int counter = 0;
    if(0 <= x-1   && myMap[x-1][y] == EMPTY) ++counter;
    if(0 <= y-1   && myMap[x][y-1] == EMPTY) ++counter;
    if(x+1 < XMAX && myMap[x+1][y] == EMPTY) ++counter;
    if(y+1 < YMAX && myMap[x][y+1] == EMPTY) ++counter;
    return counter;
}

Point findNeighbour(const Point& pt, const Map& myMap){
    const lli& XMAX = myMap.size(); const lli& YMAX = myMap[0].size();
    const lli& x = pt.first; const lli& y = pt.second;
    if(0 <= x-1   && myMap[x-1][y] == EMPTY) return Point(x-1,y);
    if(0 <= y-1   && myMap[x][y-1] == EMPTY) return Point(x,y-1);
    if(x+1 < XMAX && myMap[x+1][y] == EMPTY) return Point(x+1,y);
    if(y+1 < YMAX && myMap[x][y+1] == EMPTY) return Point(x,y+1);
    return Point(-1,-1);
}

lli getKids(const Map& myMap){
    const lli& Xsz = myMap.x_sz;
    const lli& Ysz = myMap.y_sz;

    lli ret = 0;
    Point pt;
    for(pt.second = 0; pt.second < Ysz; ++pt.second)
        for(pt.first = 0; pt.first < Xsz; ++pt.first)
            if(myMap[pt.first][pt.second] == EMPTY && countNeighbours(pt, myMap) == 1)
                ++ret;
    return ret;
}

Map solve(const Map& original, lli& answer){
    const lli& Xsz = original.x_sz;
    const lli& Ysz = original.y_sz;
    Map myMap(original);
    set<Point> points;
    lli x0, y0;
    do{
        x0 = rand()%Xsz;
        y0 = rand()%Ysz;
    }while(myMap[x0][y0] == ROCK);

    myMap[x0][y0] = EMPTY;
    if(0 <= x0-1  && myMap[x0-1][y0] == BUSH)
        points.insert(Point(x0-1,y0));
    if(0 <= y0-1  && myMap[x0][y0-1] == BUSH)
        points.insert(Point(x0,y0-1));
    if(x0+1 < Xsz && myMap[x0+1][y0] == BUSH)
        points.insert(Point(x0+1,y0));
    if(y0+1 < Ysz && myMap[x0][y0+1] == BUSH)
        points.insert(Point(x0,y0+1));

//    answer = 1;

    Point tmp, curr, neighbour;
    set<Point>::iterator it;
    lli minX = x0, maxX = x0, minY = y0, maxY = y0;
    while(!points.empty()){

//        myMap.print();

        tmp = Point(rand()%(maxX-minX+1) + minX, rand()%(maxY-minY+1) + minY);
        it = points.upper_bound(tmp); if(it == points.end()) --it;
        curr = *it; points.erase(it);
        if(countNeighbours(curr, myMap) == 1){
            neighbour = findNeighbour(curr, myMap);
//            if(countNeighbours(neighbour, myMap) != 1){
//                ///se == 1, é uma folha, e acrescenta-se uma folha a algo que era uma folha e agora não é.
//                ///nessa situação, o numero de folhas é constance: perde-se uma, ganha-se outra.
//                ///se não for uma folha, entao criou-se uma nova ramificação, sendo o novo espaço uma nova folha.
//                ++answer;
//            }
            const lli& x = curr.first; const lli& y = curr.second;
            myMap[x][y] = EMPTY;
            if(0 <= x-1  && myMap[x-1][y] == BUSH){points.insert(Point(x-1,y)); minX = min(minX, x-1);}
            if(0 <= y-1  && myMap[x][y-1] == BUSH){points.insert(Point(x,y-1)); minY = min(minY, y-1);}
            if(x+1 < Xsz && myMap[x+1][y] == BUSH){points.insert(Point(x+1,y)); maxX = max(maxX, x+1);}
            if(y+1 < Ysz && myMap[x][y+1] == BUSH){points.insert(Point(x,y+1)); maxY = max(maxY, y+1);}
        }
    }

    answer = getKids(myMap);

    return myMap;
}

float solve_ExistROCK(const string& in_Str, const Map& map_original, const lli& K){
//    /**Create output file =============================================*/
//    ofstream outstream("MyOut.out");
//    outstream << in_Str << "\n";
    /**Start computations =============================================*/
    lli factor = (lli(1)<<EXP)/(map_original.x_sz*map_original.x_sz);
    factor = max(factor, lli(1));

    lli answer = 0, max_answer = 0;
    Map myMap(map_original);
    ///Time
    chrono::time_point<std::chrono::system_clock> startT = chrono::system_clock::now();
    chrono::time_point<std::chrono::system_clock> endT = chrono::system_clock::now();
    chrono::duration<double> diff = endT-startT;

    for(lli index = 0; diff.count() < TimeLimit; ++index){
        if(index%factor == 0)
            cout << "index= " << index << ", time= " << diff.count() << " s, DIF: " << K - max_answer << " (" << min(10.0,10.0*(float)max_answer/(float)K) << "pts)" << endl;

        myMap = solve(map_original, answer);
        if(max_answer < answer){
            max_answer = answer;
//            outstream << "index= " << index << ", answer= " << answer << "\n";
//            outstream << "DIF: " << K - max_answer << " (" << min(10.0,10.0*(float)max_answer/(float)K) << "pts)\n";
//            myMap.print(outstream);
            if(max_answer >= K){
                cout << "max_answer >= K: SUCCESS" << endl;
                return 10.0;
            }
        }

        endT = chrono::system_clock::now();
        diff = endT-startT;
        ++index;
    }
    cout << "TimeLimit exceeded: program exit." << endl;
    return min(10.0,10.0*(float)max_answer/(float)K);
}

float solve_NOTExistROCK(const string& in_Str, Map& map_original, const lli& K){
//    /**Create output file =============================================*/
//    ofstream outstream("MyOut.out");
//    outstream << in_Str << "\n";

    const lli& X = map_original.x_sz; const lli& Y = map_original.y_sz;
    ///horizontal conetora
    for(lli x = 0; x < X; ++x)
        map_original[x][1] = EMPTY;
    ///verticais conetoras
    for(lli x = 1; x < X; x+= 3)
        for(lli y = 1; y < Y; ++y)
            map_original[x][y] = EMPTY;
    ///folhas da horizontal conetora
    for(lli x = 1; x < X; x += 2)
        map_original[x][0] = EMPTY;
    ///folhas da primeira vertical conetora
    for(lli y = 1; y < Y; y += 2)
        map_original[0][y] = EMPTY;
    ///folhas da esquerda das verticais conetoras
    for(lli x = 3; x < X; x += 3)
        for(lli y = 4; y < Y; y += 2)
            map_original[x][y] = EMPTY;
    ///folhas da direita das verticais conetoras
    for(lli x = 2; x < X; x += 3)
        for(lli y = 3; y < Y; y += 2)
            map_original[x][y] = EMPTY;
    ///
    lli answer = getKids(map_original);

    cout << "existROCK == false." << endl;
    cout << "DIF: " << K - answer << " (" << min(10.0,10.0*(float)answer/(float)K) << "pts)" << endl;
//    outstream << "answer= " << answer << "\n";
//    outstream << "DIF: " << K - answer << " (" << min(10.0,10.0*(float)answer/(float)K) << "pts)\n";
//    map_original.print(outstream);
    return min(10.0,10.0*(float)answer/(float)K);
}

int main(){

    const int N = 10;
    vector<float> results(N);
    srand(time(NULL));
    for(int i = 1; i <= N; ++i){
        /**Read input =============================================*/
        string in_Str = "00";
        cout << endl << "Read from:";
        sprintf(&in_Str[0], "%02d", i); in_Str = "tests/"+in_Str+".in";
        cout << in_Str << endl;
        ifstream instream(in_Str.c_str());
        if(!instream.is_open()){
            cout << "Failed to open input file" << endl;
            return 0;
        }
        lli X, Y, K; instream >> Y >> X >> K;
        Map map_original(X, Y, EMPTY);
        string s;
        bool existROCK = false;
        for(lli y = 0; y < Y; ++y){
            instream >> s;
            for(lli x = 0; x < X; ++x){
                switch(s[x]){
                    case '.': map_original[x][y] = EMPTY; break;
                    case '#': map_original[x][y] = ROCK; existROCK = true; break;
                    default: cout << "ERROR" << endl; return 0; break;
                }
                if(map_original[x][y] == EMPTY) map_original[x][y] = BUSH;
            }
        }
        /**Começar computaçoes=============================================*/
        if(existROCK)
            results[i-1] = solve_ExistROCK(in_Str, map_original, K);
        else
            results[i-1] = solve_NOTExistROCK(in_Str, map_original, K);
    }

    cout << endl << "results[]:" << endl;
    for(int i = 0; i < N; ++i)
        cout << "i= " << i << "    " << results[i] << endl;
    cout << endl << "TOTAL: " << accumulate(results.begin(),results.end(),0.0) << endl;
    return 0;
}
