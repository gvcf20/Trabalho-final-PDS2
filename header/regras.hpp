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
    std::pair<unsigned, unsigned> pontos_sub_rodada_vencedor(std::pair<Dupla, Dupla>& duplas, std::vector<Carta>& cartas_jogadas, unsigned pt);
    std::pair<unsigned, unsigned> pontos_sub_rodada_empate(std::pair<Dupla, Dupla>& duplas, std::vector<Carta>& cartas_jogadas, unsigned pt);
    std::pair<Jogador, std::vector<Carta>> verifica_vencedor_SR(std::vector<Carta> mao_rodada, std::pair<Dupla,Dupla>& duplas);
    std::pair<Dupla, std::vector<Carta>> verifica_empate_SR(std::vector<Carta> mao_rodada, std::pair<Dupla,Dupla>& duplas);

};

#endif