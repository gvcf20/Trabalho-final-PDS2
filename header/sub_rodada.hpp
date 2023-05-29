#ifndef SUB_RODADA_H
#define SUB_RODADA_H
#include <iostream>
#include <vector>
#include<string>
#include "cartas.hpp"

class Sub_Rodada{
    public:
    std::vector<Carta> joga_carta(std::pair<Dupla, Dupla>& duplas, unsigned i);
    Dupla verifica_vencedor(std::pair<Dupla, Dupla>& duplas, std::vector<Carta> cartas_jogadas, unsigned pt);
    friend class JOGO;
    private:
    unsigned pontuacao_sub_rodada_dupla1;
    unsigned pontuacao_sub_rodada_dupla2;
};
//Este método estará responsável por avaliar as sub_partidas. Nesse sentido, sub_partidas
//seriam relacionadas ao lance em que cada jogador joga suas cartas e avaliamos quem ganhou
//temos cinco situações possiveis: uma dupla vence a primeira e a segunda;
//Uma dupla ganha a primera e empata a segunda;
//Uma dupla empata a primeira e ganha na segunda;
//uma dupla ganha na primeira, perde na segunda e ganha na terceira
//Uma dupla ganha na primeira, perde na segunda e empata na terceira e o peso da primeira
//sub_rodada é maior que as demais



#endif 
