#include "../header/jogo.hpp"
#include "../header/rodada.hpp"
#include "../header/jogador.hpp"
#include "../header/dupla.hpp"
#include "../header/sub_rodada.hpp"
#include <iostream>
#include <vector>

void JOGO::comeca_rodada(std::pair <Dupla, Dupla>& duplas_h){
    Rodada rodada;
    
    unsigned ptl = 0;
    rodada.distribui_cartas(duplas_h);
    rodada.exibe_cartas(duplas_h);
    Sub_Rodada sub_rodada;
    while(sub_rodada.pontuacao_sub_rodada_dupla1 < 5 || sub_rodada.pontuacao_sub_rodada_dupla2 < 5){
        
        ptl = ptl + 1;
        std::vector<Carta> cartas_jogadas;
        cartas_jogadas = sub_rodada.joga_carta(duplas_h, 2);
        sub_rodada.verifica_vencedor(duplas_h , cartas_jogadas, ptl);
        
    }
    if(sub_rodada.pontuacao_sub_rodada_dupla1 >= 5){
        duplas_h.first.pontuacao += 2;
    } else if (sub_rodada.pontuacao_sub_rodada_dupla2 >= 5){
        duplas_h.second.pontuacao += 2;
    }
}

