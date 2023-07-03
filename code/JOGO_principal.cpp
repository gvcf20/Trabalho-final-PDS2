#include "../header/jogo.hpp"
#include "../header/JOGO_principal.hpp"
#include "../header/rodada.hpp"
#include <iostream>
#include <vector>

void JOGO::comeca_jogo(std::pair <Dupla,Dupla>& duplas_h){

    Pede_Truco truquinho;
    Comeca_Rodada rodada;
    duplas_h.first.pontuacao = 0;
    duplas_h.second.pontuacao = 0;
    while(duplas_h.first.pontuacao < 12 && duplas_h.second.pontuacao < 12){
<<<<<<< HEAD
        truquinho.condition = false;
        truquinho.condition_aceitas = false;
        rodada.comeca_rodada(duplas_h, truquinho);
=======
        rodada.comeca_rodada(duplas_h);
>>>>>>> main
    }
    if(duplas_h.first.pontuacao == 12 || duplas_h.first.pontuacao > 12){
        duplas_h.first.jogos_vencidos += 1;
        std::cout << "-------------------------------------------------------------------" << std::endl;
         std::cout << "A dupla 1 ganhou um jogo e recebe 1 super ponto" << std::endl;
         std::cout << "Pontuação do jogo: " << duplas_h.first.jogos_vencidos << std::endl;
         std::cout << "Pontuação do jogo: " << duplas_h.second.jogos_vencidos << std::endl;
         std::cout << "-------------------------------------------------------------------" << std::endl;
        duplas_h.first.pontuacao = 0;
        duplas_h.second.pontuacao = 0;
        
    }
<<<<<<< HEAD
    else if(duplas_h.second.pontuacao == 12 || duplas_h.first.pontuacao > 12){
=======
    if(duplas_h.second.pontuacao >= 12){
>>>>>>> main
        duplas_h.second.jogos_vencidos += 1;
        std::cout << "-------------------------------------------------------------------" << std::endl;
         std::cout << "A dupla 2 ganhou um jogo e recebe 1 super ponto" << std::endl;
         std::cout << "Pontuação do jogo: " << duplas_h.first.jogos_vencidos << std::endl;
         std::cout << "Pontuação do jogo: " << duplas_h.second.jogos_vencidos << std::endl;
         std::cout << "-------------------------------------------------------------------" << std::endl;
        duplas_h.first.pontuacao = 0;
        duplas_h.second.pontuacao = 0;
        
    }
}

