#include "../header/embaralhamento.hpp"
#include <iostream>
#include <algorithm>
#include <random>
#include <chrono>

void embaralhar(Baralho& baralho){
    auto rng = std::default_random_engine {};
    auto now = std::chrono::system_clock::now();

    auto now_ms = std::chrono::time_point_cast<std::chrono::milliseconds>(now);

    auto epoch = now_ms.time_since_epoch();

    auto value = std::chrono::duration_cast<std::chrono::milliseconds>(epoch);

    long seed = value.count();
    rng.seed(seed);
    std::shuffle(std::begin(baralho.cartas_baralho), std::end(baralho.cartas_baralho), rng);

}