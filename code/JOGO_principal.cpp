#include "../header/jogo.hpp"
#include "rodada.cpp"
#include "../header/jogador.hpp"
#include "../header/dupla.hpp"
#include <iostream>
#include <vector>

void JOGO::comeca_rodada(std::pair <Dupla, Dupla>& duplas_h){
    Rodada rodada;
    rodada.distribui_cartas(duplas_h);
    rodada.exibe_cartas(duplas_h);
    rodada.joga_carta(duplas_h);
}

