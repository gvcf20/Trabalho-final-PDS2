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

void cadastro_jogadores();

#endif