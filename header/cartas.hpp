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
            {Naipes::COPAS, Tipos_Cartas::AS},
            {Naipes::COPAS, Tipos_Cartas::DOIS},
            {Naipes::COPAS, Tipos_Cartas::TRES},
            {Naipes::COPAS, Tipos_Cartas::QUATRO},
            {Naipes::COPAS, Tipos_Cartas::CINCO},
            {Naipes::COPAS, Tipos_Cartas::SEIS},
            {Naipes::COPAS, Tipos_Cartas::SETE},
            {Naipes::COPAS, Tipos_Cartas::REI},
            {Naipes::COPAS, Tipos_Cartas::RAINHA},
            {Naipes::COPAS, Tipos_Cartas::VALETE},
            {Naipes::OURO, Tipos_Cartas::AS},
            {Naipes::OURO, Tipos_Cartas::DOIS},
            {Naipes::OURO, Tipos_Cartas::TRES},
            {Naipes::OURO, Tipos_Cartas::QUATRO},
            {Naipes::OURO, Tipos_Cartas::CINCO},
            {Naipes::OURO, Tipos_Cartas::SEIS},
            {Naipes::OURO, Tipos_Cartas::SETE},
            {Naipes::OURO, Tipos_Cartas::REI},
            {Naipes::OURO, Tipos_Cartas::RAINHA},
            {Naipes::OURO, Tipos_Cartas::VALETE},
            {Naipes::ESPADA, Tipos_Cartas::AS},
            {Naipes::ESPADA, Tipos_Cartas::DOIS},
            {Naipes::ESPADA, Tipos_Cartas::TRES},
            {Naipes::ESPADA, Tipos_Cartas::QUATRO},
            {Naipes::ESPADA, Tipos_Cartas::CINCO},
            {Naipes::ESPADA, Tipos_Cartas::SEIS},
            {Naipes::ESPADA, Tipos_Cartas::SETE},
            {Naipes::ESPADA, Tipos_Cartas::REI},
            {Naipes::ESPADA, Tipos_Cartas::RAINHA},
            {Naipes::ESPADA, Tipos_Cartas::VALETE},
            {Naipes::FOLHAS, Tipos_Cartas::AS},
            {Naipes::FOLHAS, Tipos_Cartas::DOIS},
            {Naipes::FOLHAS, Tipos_Cartas::TRES},
            {Naipes::FOLHAS, Tipos_Cartas::QUATRO},
            {Naipes::FOLHAS, Tipos_Cartas::CINCO},
            {Naipes::FOLHAS, Tipos_Cartas::SEIS},
            {Naipes::FOLHAS, Tipos_Cartas::SETE},
            {Naipes::FOLHAS, Tipos_Cartas::REI},
            {Naipes::FOLHAS, Tipos_Cartas::RAINHA},
            {Naipes::FOLHAS, Tipos_Cartas::VALETE},
        };
    }

    Carta pegar_cartas() {
        auto carta = cartas_baralho.at(cartas_baralho.size() - 1);
        cartas_baralho.pop_back();
        return carta;
    }
};
#endif