#include "../header/jogo.hpp"
#include "../header/rodada.hpp"
#include "../header/jogador.hpp"
#include "../header/dupla.hpp"
#include "../header/sub_rodada.hpp"
#include <iostream>
#include <vector>

void JOGO::comeca_rodada(std::pair <Dupla, Dupla>& duplas_h){
    Rodada rodada;
    rodada.distribui_cartas(duplas_h);
    rodada.exibe_cartas(duplas_h);
    Sub_Rodada sub_rodada;
    std::vector<Carta> cartas_jogadas;
    cartas_jogadas = sub_rodada.joga_carta(duplas_h, 2);
    sub_rodada.verifica_vencedor(duplas_h , cartas_jogadas, 1);
}

void JOGO::campeao(std::pair <Dupla,Dupla>& duplas_h){
    if(duplas_h.first.pontuacao = 12){
        std::cout << "Os grandes vencedores são: "<< duplas_h.first.duplinha.first.nome_jogador << " e " << duplas_h.first.duplinha.second.nome_jogador<< std::endl; 
    } else{
        std::cout << "Os grandes vencedores são: "<< duplas_h.second.duplinha.first.nome_jogador << " e " << duplas_h.second.duplinha.second.nome_jogador<< std::endl;
    }
}