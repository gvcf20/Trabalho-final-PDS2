#include "../header/jogo.hpp" 
#include "../header/jogador.hpp"
#include <iostream>
#include <vector>
#include <string>

void Jogador::get_nome(){
    std::string nome;
    std::getline(std::cin, nome);
    nome_jogador = nome;
}
void Jogador::set_mao(std::vector<Carta> mao){
    this->mao = mao;
}
std::vector<Carta> Jogador::get_mao(std::vector<Carta> cartas){
    std::vector<Carta> mao;
    for(std::size_t i = 0; i < cartas.size(); i++){
        mao[i] = cartas[i];
    }
    return mao;
}