#include "../header/rodada.hpp"
#include "../header/cartas.hpp"
#include "embaralhamento.cpp"
#include <iostream>
#include <vector>


std::vector<Carta> distribui_cartas(std::pair<Dupla, Dupla> duplas){
    Baralho baralho;
    baralho.inicializa_Baralho();
    embaralhar(baralho);
    std::vector<Carta> mao;
    for (auto& jogador : duplas.first){

    }

}
    
