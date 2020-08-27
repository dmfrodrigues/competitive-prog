#include <bits/stdc++.h>
using namespace std;
typedef long long int           lli;
typedef unsigned long long int  ulli;
#define ALL(v)                  (v).begin() , (v).end()
#define FOR(i, b, e)            for(lli i =(b); (i)  < (lli)(e); ++(i))
typedef vector<lli>             VI;
typedef vector<VI>              VVI;
typedef vector<bool>            VB;
typedef vector<VB>              VVB;
typedef pair< lli, lli>         PII;
typedef pair<ulli,ulli>         PUU;
typedef pair<PII,PII>           PPP;
#define X first
#define Y second
const lli INF = 1000000000;

const lli mu  = 350125310;
const lli lam = 182129209;
const lli step = 3000000;
const VI mu_sol  = {1498258, 1503135, 1499427, 1510615, 1488594, 1500434, 1503707, 1499080, 1503511, 1504922, 1504383, 1501707, 1497324, 1499696, 1515640, 1501929, 1501033, 1505109, 1503326, 1498401, 1499209, 1501479, 1503752, 1494099, 1502679, 1498122, 1507686, 1500320, 1503486, 1505896, 1495105, 1494370, 1503319, 1508255, 1507695, 1495229, 1495793, 1503452, 1500602, 1496388, 1500954, 1495732, 1506191, 1506865, 1508023, 1499880, 1497512, 1497839, 1506493, 1497630, 1506723, 1502413, 1504080, 1499469, 1490825, 1496798, 1503171, 1494031, 1493481, 1495539, 1493981, 1498813, 1514734, 1501639, 1512016, 1507615, 1497973, 1490152, 1503521, 1499263, 1498202, 1508436, 1503274, 1494010, 1494870, 1500043, 1490138, 1507707, 1511054, 1503235, 1500039, 1514259, 1497214, 1495291, 1500642, 1500989, 1508574, 1496029, 1509438, 1500844, 1490942, 1498888, 1506548, 1504215, 1498371, 1501079, 1498872, 1501100, 1504956, 1500154, 1499975, 1497392, 1501352, 1497176, 1492781, 1501224, 1494743, 1502958, 1498644, 1502066, 1496043, 1500521, 1497769, 1497190, 1499870, 1486417, 1061868}; //size=117
const VI lam_sol = {1488494, 1499310, 1502532, 1495134, 1494540, 1498474, 1505304, 1504281, 1496153, 1500524, 1506189, 1494794, 1500877, 1501833, 1497523, 1498106, 1496612, 1506254, 1486449, 1497728, 1504971, 1501359, 1496602, 1497350, 1501711, 1491523, 1501177, 1502267, 1503960, 1495123, 1503713, 1498123, 1500135, 1506666, 1502576, 1498312, 1489879, 1511765, 1505542, 1501925, 1505990, 1495450, 1501312, 1510399, 1495004, 1495584, 1503306, 1498930, 1492106, 1496242, 1497777, 1504566, 1499864, 1493954, 1501662, 1502217, 1499191, 1497809, 1490649, 1497222, 1064280}; //size=61
const VI mu_v    = {1611516670, 241479741103, 38803296781, 891568792743, 171026377942, 24473902285, 641099940086, 120078616969, 14112718818, 459992934005, 83248007737, 6620357676, 329031146994, 56608327843, 1202088386, 234323188514, 37349296386, 866153773131, 165860564948, 23423623727, 622741727028, 116353077724, 13354228762, 446735001036, 80552785887, 6072677726, 319458043535, 54666415645, 807311470, 227422736603, 35943646365, 841583890229, 160863512855, 22407748132, 604984856037, 112739509636, 12619930630, 433899929956, 77937262116, 5540033707, 310147760736, 52768306127, 421224956, 220674185952, 34570851523, 817588294774, 155984357764, 21415731952, 587645035156, 109212377002, 11901289737, 421338536015, 75388473090, 5021923689, 301091520582, 50930014590, 47523507, 214142117131, 33244800104, 794409746597, 151258698876, 20453692433, 570829185964, 105793488505, 11206260411, 409189858068, 72916691179, 4518737141, 292296134838, 49139934610, 1072246754882, 207776143636, 31950237454, 771781602051, 146659953560, 19518274761, 554478669836, 102467773271, 10530470029, 397377465370, 70512631458, 4030509852, 283762226666, 47405582216, 1041931361613, 201601781662, 30692099632, 749790137907, 142195453631, 18609763453, 538598461112, 99233116795, 9872154607, 385870524711, 68171034631, 3554026557, 275433596512, 45707572329, 1012251211594, 195566586555, 29466792348, 728372535169, 137834709208, 17722589590, 523091215660, 96085200428, 9232083997, 374682489219, 65899097615, 3092594895, 267368060404, 44070841770, 983642184332, 189755401031, 28282316870, 707668644954, 133624495703}; //size=117
const VI lam_v   = {516914, 213320471137, 33074507269, 791433134353, 150665044668, 20333317063, 568725099726, 105363635318, 11118953800, 407663794807, 72602179030, 4454720767, 291177168779, 48912393781, 1068269484544, 206964762495, 31782549017, 768850512682, 146064427222, 19397564493, 552368730897, 102035300196, 10441333753, 395819420123, 70194651191, 3966062967, 282635736438, 47173271267, 1037870710119, 200789870231, 30528085091, 746923268357, 141603787729, 18490265571, 536509711863, 98811843402, 9785985038, 384364333153, 67867144325, 3492522697, 274358548202, 45492182566, 1008486331820, 194803692470, 29309763482, 725627766979, 137281055555, 17611429352, 521148206276, 95683283946, 9149398605, 373237200776, 65605217162, 3031826579, 266305867583, 43855070484, 979870636290, 188991051429, 28128521923, 704980405206, 133077482701}; //size=61

const lli mu_sol_accum  = accumulate(ALL(mu_sol ), lli(0));
const lli lam_sol_accum = accumulate(ALL(lam_sol), lli(0));

const lli M = lli(1)<<40;
const lli x0 = 0x600DCAFE;
lli f(lli x){
    return (x+(x>>20)+12345)%M;
}

lli finish(lli N, lli x){
    lli ans = 0;
    while(N > 0){
        ans += (x%2==0 ? 1 : 0);
        x = f(x);
        --N;
    }
    return ans;
}

int main(){
    lli N; cin >> N;
    lli ans = 0;
    if(N <= mu){
        size_t i = 0;
        while(N-step >= 0){ ans += mu_sol [i++]; N -= step; }
        ans += finish(N, mu_v[i]);
    }else{
        ans += mu_sol_accum; N -= mu;
        lli k = N/lam; N -= k*lam; ans += k*lam_sol_accum;
        size_t i = 0;
        while(N-step >= 0){ ans += lam_sol[i++]; N -= step; }
        ans += finish(N, lam_v[i]);
    }
    cout << ans << endl;
    return 0;
}