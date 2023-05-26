#include "../header/cartas.hpp"
#include "../header/regras.hpp"
#include <iostream>

std::vector<Carta> Regras::maior_carta(std::vector<Carta>& cartas){
    int min,minimal;
    std::vector <Carta> maior_carta;
    cartas[0].peso = min;
    for(std::size_t i = 0; i < cartas.size(); i++){
        if (cartas[i].peso < min){
            minimal = min;
        }
    }
    for(std::size_t i = 0; i < cartas.size(); i++){
        if(minimal = cartas[i].peso){
            maior_carta.push_back(cartas[i]);
        }
    }
    return maior_carta;
    
}

bool Vencedor::vencedor_sub_rodada(std::vector<Carta> mao_rodada){
    Regras regras;
    std::vector<Carta> maior_carta = regras.maior_carta(mao_rodada);
    size_t i = 1;
    return mao_rodada.size() == i;
}

bool Vencedor::empate_sub_rodada(std::vector<Carta> mao_rodada){
    Regras regras;
    std::vector<Carta> maior_carta = regras.maior_carta(mao_rodada);
    size_t i = 1;
    return mao_rodada.size() != i;
}