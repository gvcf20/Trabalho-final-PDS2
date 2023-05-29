#ifndef DUPLA_H
#define DUPLA_H
#include "jogador.hpp"
#include "iostream"
#include "vector"


class Dupla {
    public:
    std::pair<Jogador, Jogador> duplinha;
    unsigned int pontuacao = 0;
    unsigned int rodadas_vencidas = 0;

};

#endif