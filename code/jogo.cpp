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