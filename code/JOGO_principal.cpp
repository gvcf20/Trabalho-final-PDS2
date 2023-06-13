#include "../header/jogo.hpp"
#include "../header/JOGO_principal.hpp"
#include "../header/rodada.hpp"
#include <iostream>
#include <vector>

void JOGO::comeca_jogo(std::pair <Dupla,Dupla>& duplas_h){

    Comeca_Rodada rodada;
    duplas_h.first.pontuacao = 0;
    duplas_h.second.pontuacao = 0;
    while(duplas_h.first.pontuacao < 12 && duplas_h.second.pontuacao < 12){
        rodada.comeca_rodada(duplas_h);
    }
    if(duplas_h.first.pontuacao >= 12){
        duplas_h.first.jogos_vencidos += 1;
        duplas_h.first.pontuacao = 0;
        duplas_h.second.pontuacao = 0;
        std::cout << "-------------------------------------------------------------------" << std::endl;
         std::cout << "A dupla 1 ganhou o primeiro jogo e recebe 1 super ponto" << std::endl;
         std::cout << "Pontuação do jogo: " << duplas_h.first.jogos_vencidos << std::endl;
         std::cout << "Pontuação do jogo: " << duplas_h.second.jogos_vencidos << std::endl;
         std::cout << "-------------------------------------------------------------------" << std::endl;
    }
    if(duplas_h.second.pontuacao >= 12){
        duplas_h.second.jogos_vencidos += 1;
        duplas_h.first.pontuacao = 0;
        duplas_h.second.pontuacao = 0;
        std::cout << "-------------------------------------------------------------------" << std::endl;
         std::cout << "A dupla 2 ganhou o primeiro jogo e recebe 1 super ponto" << std::endl;
         std::cout << "Pontuação do jogo: " << duplas_h.first.jogos_vencidos << std::endl;
         std::cout << "Pontuação do jogo: " << duplas_h.second.jogos_vencidos << std::endl;
         std::cout << "-------------------------------------------------------------------" << std::endl;
    }
}

