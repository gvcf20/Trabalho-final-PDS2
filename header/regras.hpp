#ifndef REGRAS_H
#define REGRAS_H
#include "cartas.hpp"
#include "dupla.hpp"

class Regras {
    public:
    std::vector<Carta> maior_carta(std::vector<Carta>& cartas);
    void exibe_regra(char c);
};

class Vencedor{

    public:
    bool vencedor_sub_rodada(std::vector<Carta>& mao_rodada);
    bool empate_sub_rodada(std::vector<Carta>& mao_rodada);
    std::pair<unsigned, unsigned> pontos_sub_rodada_vencedor(std::pair<Dupla, Dupla>& duplas, std::vector<Carta>& cartas_jogadas, unsigned pt);
    std::pair<unsigned, unsigned> pontos_sub_rodada_empate(std::pair<Dupla, Dupla>& duplas, std::vector<Carta>& cartas_jogadas, unsigned pt);
    std::pair<Jogador, std::vector<Carta>> verifica_vencedor_SR(std::vector<Carta>& mao_rodada, std::pair<Dupla,Dupla>& duplas);
    std::pair<Dupla, std::vector<Carta>> verifica_empate_SR(std::vector<Carta>& mao_rodada, std::pair<Dupla,Dupla>& duplas);

};

class Pede_Truco{
    public:
        bool condition;
        bool condition_aceitas;
        std::pair<bool,std::string> pede_truco(std::pair<Dupla, Dupla>& duplas, unsigned i);
        std::pair<bool,std::string> aceita_truco(std::pair<Dupla, Dupla>& duplas, unsigned i);
        unsigned pt_truco(bool condicao);
};

#endif