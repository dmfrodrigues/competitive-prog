/// NINETY-NINE
/// https://boi18-practice-open.kattis.com/problems/boi18.ninetynine/en
#include <iostream>
#include <cstdlib>

int main(){
    int total = 1;
    std::cout << total << std::endl;
    while(true){
        std::cin >> total;
        if(total >= 99){//std::cout << "FALHOU." << std::endl;
            return 0;
        }
        if(99-total <= 2){
            total = 99;
            std::cout << total << std::endl;//std::cout << "SUCESSO!" << std::endl;
            return 0;
        }
        int quanto_adicionar = 3 - total%3;
        if(quanto_adicionar == 1 || quanto_adicionar == 2){
            total += quanto_adicionar;
        }else{
            total += 1 + rand()%2;
        }
        std::cout << total << std::endl;
    }
    return 0;
}
