#ifndef RODADA_H
#define RODADA_H
#include "jogo.hpp"
#include "JOGO_principal.hpp"
#include <vector>

std::vector<Carta> dar_cartas(Baralho baralho);

class Rodada{
    
    public:
    std::vector<Carta> distribui_cartas(std::pair<Dupla, Dupla> duplas);
    void exibe_cartas(std::pair<Dupla, Dupla> duplas);
};


#endif