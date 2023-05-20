#include "../header/jogo.hpp" 
#include "../header/jogador.hpp"
#include <iostream>
#include <string>

void Jogador::get_nome(){
    std::getline(std::cin, nome_jogador);
}