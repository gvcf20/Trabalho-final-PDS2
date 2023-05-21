#include "../header/embaralhamento.hpp"
#include <iostream>
#include <algorithm>
#include <random>

void embaralhar(Baralho& baralho){
    auto rng = std::default_random_engine {};
    std::shuffle(std::begin(baralho.cartas_baralho), std::end(baralho.cartas_baralho), rng);

}