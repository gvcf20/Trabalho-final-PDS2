#include "../header/jogo.hpp" 
#include <vector>
#include <iostream>

std::vector<Jogador> cadastro_jogadores(){
    std::vector<Jogador> Jogadores;
    std::cout << "Insira os nomes dos jogadores: " << std::endl; 
    while(Jogadores.size() < 5){
        Jogador j;
        j.get_nome();
        Jogadores.push_back(j);
    }
    return Jogadores;
}
void exibe_jogadores(const std::vector<Jogador> jogs){
    std::cout << "-------------------------------------------------------------------" << std::endl;
    for(std::size_t i = 0; i < jogs.size(); i++){
        std::cout << jogs[i].nome_jogador << std::endl;
    }
    std::cout << "-------------------------------------------------------------------" << std::endl;
}

std::pair<Dupla, Dupla> set_duplas(std::vector<Jogador> jogadoress){
    Dupla d1;
    Dupla d2;
    d1.duplinha.first = jogadoress[1];
    d1.duplinha.second = jogadoress[2];
    d2.duplinha.first = jogadoress[3];
    d2.duplinha.second = jogadoress[4];
    std::pair<Dupla,Dupla> duplas;
    duplas.first = d1;
    duplas.second = d2;
    return duplas;
}

void exibe_duplas(const std::pair<Dupla, Dupla> duplas) {
    std::cout << "Duplas formadas:" << std::endl;

    // Exibe informações da primeira dupla
    std::cout << "-------------------------------------------------------------------" << std::endl;
    std::cout << "Dupla 1:" << std::endl;
    std::cout << "Jogador 1: " << duplas.first.duplinha.first.nome_jogador << std::endl;
    std::cout << "Jogador 2: " << duplas.first.duplinha.second.nome_jogador << std::endl;
    std::cout << "-------------------------------------------------------------------" << std::endl;
    std::cout << "VS" << std::endl;
    std::cout << "-------------------------------------------------------------------" << std::endl;
    std::cout << "Dupla 2:" << std::endl;
    std::cout << "Jogador 1: " << duplas.second.duplinha.first.nome_jogador << std::endl;
    std::cout << "Jogador 2: " << duplas.second.duplinha.second.nome_jogador << std::endl;
}