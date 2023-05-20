#include "../header/jogo.hpp"
#include "../header/rodada.hpp"
#include "../header/dupla.hpp"
#include <iostream>
#include <vector>

void começa_rodada(std::pair <Dupla, Dupla> duplas_h){
    Rodada rodada;
    rodada.distribui_cartas(duplas_h);
}

