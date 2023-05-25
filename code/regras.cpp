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
    int posição_jogador;
    std::vector<Carta> maior_carta = regras.maior_carta(mao_rodada);
    for(size_t i = 0; i < mao_rodada.size(); ++i){
        if(mao_rodada[i] == maior_carta[0]){
            posição_jogador = i;
        }
    }
}