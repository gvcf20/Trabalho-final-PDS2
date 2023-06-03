#include "../header/jogo.hpp"
#include "../header/rodada.hpp"
#include "../header/jogador.hpp"
#include "../header/dupla.hpp"
#include "../header/sub_rodada.hpp"
#include "regras.cpp"

#include <iostream>
#include <vector>

void JOGO::comeca_jogo(std::pair <Dupla,Dupla>& duplas_h){

    Comeca_Rodada rodada;

    while(duplas_h.first.pontuacao <= 12 || duplas_h.second.pontuacao <= 12){
        rodada.comeca_rodada(duplas_h);
    }
    if(duplas_h.first.pontuacao >= 12){
        duplas_h.first.jogos_vencidos += 1;
    }
    else if(duplas_h.second.pontuacao >= 12){
        duplas_h.second.jogos_vencidos += 1;
    }
}

