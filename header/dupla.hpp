#ifndef DUPLA_H
#define DUPLA_H
#include "jogador.hpp"
#include "iostream"
#include "vector"


class Dupla {
    public:
    std::pair<Jogador, Jogador> duplinha;
    unsigned pontuacao = 0;
    unsigned jogos_vencidos = 0;

};
#endif