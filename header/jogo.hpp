#ifndef JOGO_H
#define JOGO_H
#include "../header/jogador.hpp"
#include "../header/cartas.hpp"
#include "../header/regras.hpp"
#include "../header/embaralhamento.hpp"
#include "../header/rodada.hpp"
#include "dupla.hpp"
#include <vector>

std::vector<Jogador> cadastro_jogadores();
void exibe_jogadores(const std::vector<Jogador> jogs);
std::pair<Dupla, Dupla> set_duplas(std::vector<Jogador> jogadoress);
void exibe_duplas(const std::pair<Dupla, Dupla> duplas);

#endif