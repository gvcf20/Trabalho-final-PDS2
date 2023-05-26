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
    void set_mao(std::vector<Carta> cartas);
    std::vector<Carta> get_mao(std::vector<Carta> mao);
    friend class Sub_Rodada;
    friend class Rodada;
    
    private:
    std::vector<Carta> mao;
    
};

#endif