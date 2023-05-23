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