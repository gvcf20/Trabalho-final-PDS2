#ifndef SUB_RODADA_H
#define SUB_RODADA_H
#include <iostream>
#include <vector>
#include<string>
#include "cartas.hpp"
#include "dupla.hpp"
#include "regras.hpp"

class Sub_Rodada{
    public:
    std::pair<std::vector<Carta>, std::string> joga_carta(std::pair<Dupla, Dupla>& duplas, unsigned i, Pede_Truco truquinho);
    
    friend class JOGO;
    friend class Vencedor;
    friend class Comeca_Rodada;
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
