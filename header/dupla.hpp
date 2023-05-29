#ifndef DUPLA_H
#define DUPLA_H
#include "jogador.hpp"
#include "iostream"
#include "vector"


class Dupla {
    public:
    std::pair<Jogador, Jogador> duplinha;
    unsigned int pontuacao_subrodada = 0;
    unsigned int pontuacao_rodadas = 0;
    unsigned int jogos_vencidos = 0;

};

#endif