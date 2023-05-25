#ifndef REGRAS_H
#define REGRAS_H
#include "cartas.hpp"

class Regras {
    public:
    std::vector<Carta> maior_carta(std::vector<Carta>& cartas);
};

class Vencedor{
    public:
    bool vencedor_sub_rodada(std::vector<Carta> mao_rodada);
    bool empate_sub_rodada(std::vector<Carta> mao_rodada);
    bool verifica_casos(std::vector<Carta> mao_rodada);
};

#endif