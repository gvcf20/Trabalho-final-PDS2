#ifndef JOGADOR_H
#define JOGADOR_H
#include "cartas.hpp"
#include <iostream>
#include <set>
#include <vector>

class Jogador{
    public:
    std::string nome_jogador;
    void get_nome();
    std::vector<Carta> mao;
};

#endif