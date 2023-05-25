#include "../header/rodada.hpp"
#include "../header/cartas.hpp"
#include "../header/dupla.hpp"
#include "../header/jogador.hpp"
#include "../header/embaralhamento.hpp"
#include "../header/sub_rodada.hpp"
#include "../header/regras.hpp"
#include <iostream>
#include <vector>

std::vector<Carta> Rodada::dar_cartas(Baralho& baralho){
    std::vector<Carta> mao ={};
    for(int i = 0; i < 3; ++i){
        auto carta = baralho.pegar_cartas();
        mao.push_back(carta);
    }
    
    return mao;
}

void Rodada::distribui_cartas(std::pair<Dupla, Dupla>& duplas){
    Baralho baralho;
    baralho.inicializa_Baralho();
    embaralhar(baralho);
    std::vector<Carta> mao;
    duplas.first.duplinha.first.set_mao(dar_cartas(baralho));
    duplas.first.duplinha.second.set_mao(dar_cartas(baralho));
    duplas.second.duplinha.first.set_mao(dar_cartas(baralho));
    duplas.second.duplinha.second.set_mao(dar_cartas(baralho));

}

void Rodada::exibe_cartas(std::pair<Dupla, Dupla> duplas){
    std::vector<Carta> mao_jogador1;
    Jogador jogador;
    
    std::cout << "Dupla 1 " << duplas.first.duplinha.first.nome_jogador << std::endl;
    for(int i = 0; i < 3; ++i){
        std::cout << duplas.first.duplinha.first.mao[i].toString() << std::endl;
    }
    std::cout << "Dupla 1 " << duplas.first.duplinha.second.nome_jogador << std::endl;
    for(int i = 0; i < 3; ++i){
        std::cout << duplas.first.duplinha.second.mao[i].toString() << std::endl;
    }
    std::cout << "Dupla 2 " << duplas.second.duplinha.first.nome_jogador << std::endl;
    for(int i = 0; i < 3; ++i){
        std::cout << duplas.second.duplinha.first.mao[i].toString() << std::endl;
    }
    std::cout << "Dupla 2 " << duplas.second.duplinha.second.nome_jogador << std::endl;
    for(int i = 0; i < 3; ++i){
        std::cout << duplas.second.duplinha.second.mao[i].toString() << std::endl;
    }
}
