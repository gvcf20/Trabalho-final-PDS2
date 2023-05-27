#ifndef REGRAS_H
#define REGRAS_H
#include "cartas.hpp"
#include "dupla.hpp"

class Regras {
    public:
    std::vector<Carta> maior_carta(std::vector<Carta>& cartas);
};

class Vencedor{
    public:
    bool vencedor_sub_rodada(std::vector<Carta> mao_rodada);
    bool empate_sub_rodada(std::vector<Carta> mao_rodada);
    std::pair<Jogador, std::vector<Carta>> verifica_casos(std::vector<Carta> mao_rodada, std::pair<Dupla,Dupla> duplas);
};

#endif