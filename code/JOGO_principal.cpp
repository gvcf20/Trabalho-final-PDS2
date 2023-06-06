#include "../header/jogo.hpp"
#include "../header/JOGO_principal.hpp"
#include "../header/rodada.hpp"
#include <iostream>
#include <vector>

void JOGO::comeca_jogo(std::pair <Dupla,Dupla>& duplas_h){

    Comeca_Rodada rodada;

    while(duplas_h.first.pontuacao <= 12 || duplas_h.second.pontuacao <= 12){
        rodada.comeca_rodada(duplas_h);
    }
    if(duplas_h.first.pontuacao >= 12){
        duplas_h.first.jogos_vencidos += 1;
        std::cout << "A dupla 1 ganhou um jogo" << std::endl;
    }
    else if(duplas_h.second.pontuacao >= 12){
        duplas_h.second.jogos_vencidos += 1;
        std::cout << "A dupla 1 ganhou um jogo" << std::endl;
    }
}

