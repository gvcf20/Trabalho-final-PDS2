#ifndef RODADA_H
#define RODADA_H
#include "sub_rodada.hpp"
#include "dupla.hpp"
#include <vector>

class Rodada{
    
    public:
    std::vector<Carta> dar_cartas(Baralho& baralho);
    void distribui_cartas(std::pair<Dupla, Dupla>& duplas);
    void exibe_cartas(std::pair<Dupla, Dupla> duplas);
    
    private:

};

class Comeca_Rodada{
    public:
    void comeca_rodada(std::pair <Dupla,Dupla>& duplas_h);
};



#endif