/**
O(DX+XY)

Para calcular os tuplos (l,r,h):
Para cada ponto (x,y), sabemos qual é o quadrado com menor y que está ocupado, e que está desocupado
começamos em y=0;
Se estiver algum ocupado em (l,r,y,y+1), então procura-se a primeira linha toda livre, e muda-se y para isso
Se estiver tudo livre em (l, r, y, y+1), procura-se o mínimo dos 1ºs y's ocupados, e temos um intervalo


Para cada tuplo (l,r,h), sabemos quantas hipóteses existem para um retângulo em [l,r) com altura h
Precisamos de saber para todos os valores de l e r, mas apenas para os valores de h que for preciso saber

O(DX) ou O(DX log X): Para cada par (l, l+s[d]), l em [0, X-w[d]), perguntar quantos desses retângulos de altura h é possível meter


*/
