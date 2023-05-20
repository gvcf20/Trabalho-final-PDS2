#include "../header/jogo.hpp" 
#include "jogador.cpp"
#include <vector>
#include <iostream>

std::vector<Jogador> cadastro_jogadores(){
    std::vector<Jogador> Jogadores;
    std::cout << "Vamos cadastrar os jogadores" << std::endl; 
    while(Jogadores.size() <= 4){
        Jogador j;
        j.get_nome();
        Jogadores.push_back(j);
    }
    return Jogadores;
}
void exibe_jogadores(std::vector<Jogador> jogs){
    for(std::size_t i = 0; i < jogs.size(); i++){
        std::cout << jogs[i].nome_jogador << std::endl;
    }
}

std::pair<Dupla, Dupla> set_duplas(std::vector<Jogador> jogadoress){
    Dupla d1;
    Dupla d2;
    d1.duplinha.first = jogadoress[0];
    d1.duplinha.second = jogadoress[1];
    d2.duplinha.first = jogadoress[2];
    d2.duplinha.second = jogadoress[3];
    std::pair<Dupla,Dupla> duplas;
    duplas.first = d1;
    duplas.second = d2;
    return duplas;
}