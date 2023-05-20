#ifndef JOGO_H
#define JOGO_H
#include "../header/jogador.hpp"
#include "../header/cartas.hpp"
#include "../header/regras.hpp"
#include "../header/embaralhamento.hpp"
#include "../header/distribui_cartas.hpp"
#include "../header/rodada.hpp"
#include <vector>

class jogo{
    public:
    void acessa_jogador();

    private:
    std::vector<Jogador> jogadores;
    
};

std::vector<Jogador> cadastro_jogadores();
void exibe_jogadores(std::vector<Jogador> jogs);

#endif