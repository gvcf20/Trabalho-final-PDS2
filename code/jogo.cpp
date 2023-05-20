#include "../header/jogo.hpp" 
#include "../header/jogador.hpp"
#include <vector>
#include <iostream>

void cadastro_jogadores(){
    std::vector<Jogador> Jogadores;
    std::cout << "Vamos cadastrar os jogadores" << std::endl; 
    while(Jogadores.size() <= 3){
        Jogador j;
        j.get_nome();
        Jogadores.push_back(j);
    }
}
