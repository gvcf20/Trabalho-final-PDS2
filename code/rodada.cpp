#include "../header/rodada.hpp"
#include "../header/cartas.hpp"
#include "embaralhamento.cpp"
#include <iostream>
#include <vector>

std::vector<Carta> dar_cartas(Baralho baralho){
    std::vector<Carta> mao ={};
    for(int i = 0; i < 3; ++i){
        mao.push_back(baralho.pegar_cartas());
    }
    return mao;
}

std::vector<Carta> Rodada::distribui_cartas(std::pair<Dupla, Dupla> duplas){
    Baralho baralho;
    baralho.inicializa_Baralho();
    embaralhar(baralho);
    std::vector<Carta> mao;
    duplas.first.duplinha.first.mao = dar_cartas(baralho);
    duplas.first.duplinha.second.mao = dar_cartas(baralho);
    duplas.second.duplinha.first.mao = dar_cartas(baralho);
    duplas.second.duplinha.second.mao = dar_cartas(baralho);
    return mao;

}

void Rodada::exibe_cartas(std::pair<Dupla, Dupla> duplas){
    for(int i = 0; i < 3; ++i){
        std::cout << duplas.first.duplinha.first.mao[i].toString() << std::endl;
    }
    for(int i = 0; i < 3; ++i){
        std::cout << duplas.first.duplinha.second.mao[i].toString() << std::endl;
    }
    for(int i = 0; i < 3; ++i){
        std::cout << duplas.second.duplinha.first.mao[i].toString() << std::endl;
    }
    for(int i = 0; i < 3; ++i){
        std::cout << duplas.second.duplinha.second.mao[i].toString() << std::endl;
    }
}

    
