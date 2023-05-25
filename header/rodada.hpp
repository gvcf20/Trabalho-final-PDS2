#ifndef RODADA_H
#define RODADA_H
#include "jogo.hpp"
#include "JOGO_principal.hpp"
#include <vector>

class Rodada{
    
    public:
    std::vector<Carta> dar_cartas(Baralho& baralho);
    void distribui_cartas(std::pair<Dupla, Dupla>& duplas);
    void exibe_cartas(std::pair<Dupla, Dupla> duplas);
    std::vector<Carta> joga_carta(std::pair<Dupla, Dupla>& duplas, unsigned i);
};


#endif