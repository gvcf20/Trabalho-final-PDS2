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
std::pair<Jogador, std::vector<Carta>> Vencedor::verifica_casos(std::vector<Carta> mao_rodada, std::pair<Dupla,Dupla> duplas){

    Regras regras;
    std::pair<Jogador, std::vector<Carta>> dupla_winner;
    std::vector<Carta> mao_ganhadora = regras.maior_carta(mao_rodada);
    int j;
    if(vencedor_sub_rodada(mao_rodada) == true){

        for(size_t i = 0; i < mao_rodada.size(); ++i){
            if(mao_ganhadora[0] == mao_rodada[i]){
                j = i;
            }
        }
        if(j == 0){
            dupla_winner.first = duplas.first.duplinha.first;
            dupla_winner.second = mao_ganhadora;
        } else if(j == 1){
            dupla_winner.first = duplas.first.duplinha.second;
            dupla_winner.second = mao_ganhadora;
        } else if(j == 2){
            dupla_winner.first = duplas.second.duplinha.first;
            dupla_winner.second = mao_ganhadora;
        } else if(j == 3){
            dupla_winner.first = duplas.second.duplinha.first;
            dupla_winner.second = mao_ganhadora;
        }
    } else{

    }

}