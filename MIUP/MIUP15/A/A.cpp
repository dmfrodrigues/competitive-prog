#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef vector<lli> VI;

int main(){
    ///INPUT
    lli N; cin >> N;
    VI R(N);
    for(auto &i:R) cin >> i;
    lli M; cin >> M;
    ///PROCESSING
    VI ret(N, 0);
    vector<bool> on(N, true);
    lli curr_server = N-1;
    lli curr_received = R[N-1];
    string s;
    while(M--){
        cin >> s;
        if(s == "S"){
            lli i; cin >> i; --i;
            on[i] = !on[i];         //altera-se o estado (ligado ou desligado) do servidor `i`
            if(!on[i] && curr_server == i)  //se ele tiver sido desligado e for o servidor atual, damos reset no numero de requests que o servidor ja atendeu nesta ronda
                curr_received = 0;
        }else{
            lli C; { stringstream ss; ss << s; ss >> C; } //converter `string` para `lli` e meter em `C`
            /**
             * Agora, vamos avançar um servidor de cada vez, e dar-lhe o maximo possivel de requests.
             * (Note-se que os `if` fora e dentro do `while loop` sao iguais)
             * Vamos dar `d` ao servidor atual; `d` = minimo entre os requests que falta atender (`C`) e o maximo de
             * requests que o servidor atual ainda consegue satisfazer (`R[curr_server] - curr_received`).
             * Agora vamos passar esses requests para o servidor atual:
             */
            if(on[curr_server]){
                lli d = min(C, R[curr_server] - curr_received);
                C -= d;                 //subtraindo `d` ao numero de requests que falta atender;
                ret[curr_server] += d;  //somando `d` ao numero de requests que foram atendidos pelo servidor atual
                curr_received += d;     //somando `d` ao numero de requests que o servidor atual ja atendeu nesta ronda
            }
            while(C){ //e agora faz-se o mesmo enquanto houver requests para distribuir;
                curr_server = (curr_server+1)%N; //incrementando o indice do servidor atual (e fazendo wrapping quando chega a `N`)
                curr_received = 0;               //e dando reset ao numero de requests servidos pelo servidor atual (o servidor acabou de mudar, é natural que ainda não tenha atendido nenhum request nesta ronda)
                if(on[curr_server]){             //os `if`s servem para saber se o servidor está ligado ou não; se estiver desligado, é ignorado, e passa-se para o servidor seguinte
                    lli d = min(C, R[curr_server] - curr_received);
                    C -= d;
                    ret[curr_server] += d;
                    curr_received += d;
                }
            }
        }
    }
    for(const lli &i:ret) cout << i << endl;
    return 0;
}
