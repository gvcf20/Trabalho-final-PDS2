#ifndef SUB_RODADA_H
#define SUB_RODADA_H
#include <iostream>
#include <vector>
#include<string>
#include "cartas.hpp"
#include "dupla.hpp"

class Sub_Rodada{
    public:
    std::vector<Carta> joga_carta(std::pair<Dupla, Dupla>& duplas, unsigned i);
    
    friend class JOGO;
    friend class Vencedor;
    friend class Comeca_Rodada;
    private:
    unsigned pontuacao_sub_rodada_dupla1;
    unsigned pontuacao_sub_rodada_dupla2;
};



#endif 
