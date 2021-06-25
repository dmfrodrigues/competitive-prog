/// GENETICS
/// https://boi18-day2-open.kattis.com/problems/boi18.genetics

#include <iostream>
#include <vector>
#include <algorithm>

unsigned int M, N, K;
unsigned int M_K;

void InicializarTree()

bool DiferePorK(const std::string& str1, const std::string& str2){
    unsigned int dif = 0;
    for(unsigned int i = 0; i < str1.size(); ++i){
        if(str1[i]!=str2[i]){
            ++dif;
            if((dif > K)      ||
               (i+1-dif > M_K)){return false;}
        }
    }
    return true;
}

typedef std::vector< std::pair<std::string,bool> > MyVtr;

int resolver1(const MyVtr& sequencias, const int& K){
    const int& N = sequencias.size();

    MyVtr sequencias_forward = sequencias;
    MyVtr sequencias_reverse = sequencias;

    for(MyVtr::iterator i = sequencias_forward.begin(); i < sequencias_forward.end(); ++i){
        if(i->second){
            bool isK;
            for(MyVtr::iterator j = i+1; j < sequencias_forward.end(); ++j){
                if(j->second){
                    isK = DiferePorK(i->first, j->first);
                    if(!isK){
                        i->second = false;
                        j->second = false;
                        break;
                    }
                }
            }
        }
    }
//    for(MyVtr::iterator i = sequencias_forward.begin(); i < sequencias_forward.end(); ++i)
//        std::cout << i->second << std::endl;
//    std::cout << std::endl;

    for(MyVtr::reverse_iterator i = sequencias_reverse.rbegin(); i < sequencias_reverse.rend(); ++i){
        if(i->second){
            bool isK;
            for(MyVtr::reverse_iterator j = i+1; j < sequencias_reverse.rend(); ++j){
                if(j->second){
                    isK = DiferePorK(i->first, j->first);
                    if(!isK){
                        i->second = false;
                        j->second = false;
                        break;
                    }
                }
            }
        }
    }

//    for(MyVtr::iterator i = sequencias_reverse.begin(); i < sequencias_reverse.end(); ++i)
//        std::cout << i->second << std::endl;
//    std::cout << std::endl;

    std::vector<bool> is_villain(N);
    for(int i = 0; i < N; ++i)
        is_villain[i] = sequencias_forward[i].second && sequencias_reverse[i].second;

//    for(int i = 0; i < N; ++i)
//        std::cout << "i=" << i << ", " << is_villain[i] << std::endl;
//    std::cout << std::endl;

    int resposta = std::find(is_villain.begin(), is_villain.end(), true) - is_villain.begin() + 1;
    return resposta;
}

int resolver2(MyVtr sequencias, const int& K){
//
    MyVtr::iterator sequencias_end = sequencias.end();
    for(MyVtr::iterator i = sequencias.begin(); i < sequencias_end; ++i){
        if(!i->second) continue;
        for(MyVtr::iterator j = i+1; j < sequencias_end; ++j){
            if(!j->second) continue;
            if(!DiferePorK(i->first, j->first)){
                i->second = false;
                j->second = false;
                break;
            }
        }
    }




//    std::cout << "may be villain:" << std::endl;
//    for(MyVtr::const_iterator i = sequencias.begin(); i < sequencias.end(); ++i)
//        std::cout << i->second << std::endl;
//    std::cout << std::endl;

    for(MyVtr::iterator i = sequencias.begin(); i < sequencias_end; ++i){
        if(!i->second) continue;
        bool correto = true;
        for(MyVtr::iterator j = sequencias.begin(); j < sequencias_end; ++j){ if(j == i) continue;
            if(!DiferePorK(i->first, j->first)){
                correto = false;
                break;
            }
        }
        if(correto) return (i-sequencias.begin()+1);
    }
    return 0;
}

int main(){
/*
5 10 2
AAAATTAAAA
AAAAAGGAAA
AAGGAAAAAA
AAAAAAAAAA
AABAAAABAA
-> 4
*/

//    int N, M, K;
//    MyVtr sequencias;
//
//    while(true){
//        std::cin >> N >> M >> K;
//        sequencias = MyVtr(N, std::pair<std::string,bool>(std::string(),true));
//        for(int i = 0; i < N; ++i)
//            std::cin >> sequencias[i].first;
//        std::cout << comparar(sequencias[0].first, sequencias[1].first, K) << std::endl;
//    }

    std::cin >> N >> M >> K;
    M_K = M-K;
    MyVtr sequencias(N, std::pair<std::string,bool>(std::string(),true));
    for(unsigned int i = 0; i < N; ++i)
        std::cin >> sequencias[i].first;

    for(long int i = 0; i < 300000; ++i)
        resolver2(sequencias, K);

    std::cout << resolver2(sequencias, K) << std::endl;


    return 0;
}
