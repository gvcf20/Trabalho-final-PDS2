#ifndef CARTAS_H
#define CARTAS_H
#include <iostream>
#include <vector>
#include <string>


enum class Naipes
{
    COPAS,
    OURO,
    ESPADA,
    FOLHAS
};

enum class Tipos_Cartas
{
    AS,
    DOIS,
    TRES,
    QUATRO,
    CINCO,
    SEIS,
    SETE,
    REI,
    RAINHA,
    VALETE

};

struct Carta
{
    Naipes naipes;
    Tipos_Cartas tipos_cartas;
    int peso;
    bool operator == (const Carta &c){
        if(naipes == c.naipes && tipos_cartas == c.tipos_cartas){
            return true;
        } return false;
    }
    std::string toString()
    {
        std::string tipoDaCarta = "";

        if (naipes == Naipes::COPAS)
        {
            tipoDaCarta = "COPAS - ";
        }
        else if (naipes == Naipes::OURO)
        {
            tipoDaCarta = "Ouro - ";
        }
        else if (naipes == Naipes::ESPADA)
        {
            tipoDaCarta = "Espada - ";
        }
        else if (naipes == Naipes::FOLHAS)
        {
            tipoDaCarta = "Folhas - ";
        }

        if (tipos_cartas == Tipos_Cartas::AS)
        {
            tipoDaCarta += "AS";
        }
        else if (tipos_cartas == Tipos_Cartas::DOIS)
        {
            tipoDaCarta += "DOIS";
        }
        else if (tipos_cartas == Tipos_Cartas::TRES)
        {
            tipoDaCarta += "TRES";
        }
        else if (tipos_cartas == Tipos_Cartas::QUATRO)
        {
            tipoDaCarta += "QUATRO";
        }
        else if (tipos_cartas == Tipos_Cartas::CINCO)
        {
            tipoDaCarta += "CINCO";
        }
        else if (tipos_cartas == Tipos_Cartas::SEIS)
        {
            tipoDaCarta += "SEIS";
        }
        else if (tipos_cartas == Tipos_Cartas::SETE)
        {
            tipoDaCarta += "SETE";
        }
        else if (tipos_cartas == Tipos_Cartas::REI)
        {
            tipoDaCarta += "REI";
        }
        else if (tipos_cartas == Tipos_Cartas::RAINHA)
        {
            tipoDaCarta += "RAINHA";
        }
        else if (tipos_cartas == Tipos_Cartas::VALETE)
        {
            tipoDaCarta += "VALETE";
        }

        return tipoDaCarta;
    }
};

struct Baralho{
    std::vector<Carta> cartas_baralho;
    void inicializa_Baralho()
    {
        cartas_baralho =  {
            {Naipes::COPAS, Tipos_Cartas::AS, 6},
            {Naipes::COPAS, Tipos_Cartas::DOIS, 5},
            {Naipes::COPAS, Tipos_Cartas::TRES, 4},
            {Naipes::COPAS, Tipos_Cartas::QUATRO, 13},
            {Naipes::COPAS, Tipos_Cartas::CINCO, 12},
            {Naipes::COPAS, Tipos_Cartas::SEIS, 11},
            {Naipes::COPAS, Tipos_Cartas::SETE, 1},
            {Naipes::COPAS, Tipos_Cartas::REI, 7},
            {Naipes::COPAS, Tipos_Cartas::RAINHA, 9},
            {Naipes::COPAS, Tipos_Cartas::VALETE, 8},
            {Naipes::OURO, Tipos_Cartas::AS, 6},
            {Naipes::OURO, Tipos_Cartas::DOIS, 5},
            {Naipes::OURO, Tipos_Cartas::TRES, 4},
            {Naipes::OURO, Tipos_Cartas::QUATRO, 13},
            {Naipes::OURO, Tipos_Cartas::CINCO, 12},
            {Naipes::OURO, Tipos_Cartas::SEIS, 11},
            {Naipes::OURO, Tipos_Cartas::SETE, 3},
            {Naipes::OURO, Tipos_Cartas::REI, 7},
            {Naipes::OURO, Tipos_Cartas::RAINHA, 9},
            {Naipes::OURO, Tipos_Cartas::VALETE, 8},
            {Naipes::ESPADA, Tipos_Cartas::AS, 2},
            {Naipes::ESPADA, Tipos_Cartas::DOIS, 5},
            {Naipes::ESPADA, Tipos_Cartas::TRES, 4},
            {Naipes::ESPADA, Tipos_Cartas::QUATRO, 13},
            {Naipes::ESPADA, Tipos_Cartas::CINCO, 12},
            {Naipes::ESPADA, Tipos_Cartas::SEIS, 11},
            {Naipes::ESPADA, Tipos_Cartas::SETE, 10},
            {Naipes::ESPADA, Tipos_Cartas::REI, 7},
            {Naipes::ESPADA, Tipos_Cartas::RAINHA, 9},
            {Naipes::ESPADA, Tipos_Cartas::VALETE, 8},
            {Naipes::FOLHAS, Tipos_Cartas::AS, 6},
            {Naipes::FOLHAS, Tipos_Cartas::DOIS, 5},
            {Naipes::FOLHAS, Tipos_Cartas::TRES, 4},
            {Naipes::FOLHAS, Tipos_Cartas::QUATRO, 0},
            {Naipes::FOLHAS, Tipos_Cartas::CINCO, 12},
            {Naipes::FOLHAS, Tipos_Cartas::SEIS, 11},
            {Naipes::FOLHAS, Tipos_Cartas::SETE, 10},
            {Naipes::FOLHAS, Tipos_Cartas::REI, 7},
            {Naipes::FOLHAS, Tipos_Cartas::RAINHA, 9},
            {Naipes::FOLHAS, Tipos_Cartas::VALETE, 8},
        };
    }

    Carta pegar_cartas() {
        auto carta = cartas_baralho.at(cartas_baralho.size() - 1);
        cartas_baralho.pop_back();
        return carta;
    }
};
#endif