#include "../header/rodada.hpp"
#include "../header/cartas.hpp"
#include "../header/dupla.hpp"
#include "embaralhamento.cpp"
#include <iostream>
#include <vector>

std::vector<Carta> dar_cartas(Baralho& baralho){
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
    duplas.first.duplinha.first.mao = dar_cartas(baralho);
    duplas.first.duplinha.second.mao = dar_cartas(baralho);
    duplas.second.duplinha.first.mao = dar_cartas(baralho);
    duplas.second.duplinha.second.mao = dar_cartas(baralho);

}

void Rodada::exibe_cartas(std::pair<Dupla, Dupla> duplas){
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
std::vector<Carta> Rodada::joga_carta(std::pair<Dupla, Dupla>& duplas){
    
    int i1 = -1, i2 = -1, i3 = -1, i4 = -1;
    std::vector<Carta>mao_rodada;
        
    while(i1 < 0 || i1 > 2){
        std::cout << duplas.first.duplinha.first.nome_jogador <<" suas cartas estão numeradas de 0 a 2. Escolha uma, entre 0 e 2 para lançar: " << std::endl;
        std:: cin >> i1; std::cout << std::endl;
    }
    mao_rodada.push_back(duplas.first.duplinha.first.mao[i1]);
    duplas.first.duplinha.first.mao.erase(duplas.first.duplinha.first.mao.begin() + i1);

    while(i2 < 0 || i2 > 2){
        std::cout << duplas.first.duplinha.second.nome_jogador << " suas cartas estão numeradas de 0 a 2. Escolha uma, entre 0 e 2 para lançar: " << std::endl;
        std:: cin >> i2; std::cout << std::endl;
    }
    mao_rodada.push_back(duplas.first.duplinha.second.mao[i2]);
    duplas.first.duplinha.second.mao.erase(duplas.first.duplinha.second.mao.begin() + i2);    

    while(i3 < 0 || i3 > 2){
        std::cout << duplas.second.duplinha.first.nome_jogador << " Jogador 3, suas cartas estão numeradas de 0 a 2. Escolha uma, entre 0 e 2 para lançar: " << std::endl;
        std:: cin >> i3; std::cout << std::endl;
    }
    mao_rodada.push_back(duplas.second.duplinha.first.mao[i3]);
    duplas.second.duplinha.first.mao.erase(duplas.second.duplinha.first.mao.begin() + i3);

    while(i4 < 0 || i4 > 2){
        std::cout << duplas.second.duplinha.first.nome_jogador <<" Jogador 4, suas cartas estão numeradas de 0 a 2. Escolha uma, entre 0 e 2 para lançar: " << std::endl;
        std:: cin >> i4; std::cout << std::endl;
    }
    mao_rodada.push_back(duplas.second.duplinha.second.mao[i4]);
    duplas.second.duplinha.second.mao.erase(duplas.second.duplinha.second.mao.begin() + i4);

    return mao_rodada;
}


