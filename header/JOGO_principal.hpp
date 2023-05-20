#ifndef JOGO_PRINCIPAL_H
#define JOGO_PRINCIPAL_H
#include "jogo.hpp"
#include "jogador.hpp"
#include "dupla.hpp"
#include <iostream>
#include <vector>

class JOGO{
    public:
    std::pair<Dupla,Dupla> duplas;
    void começa_rodada();
    private:

};


#endif