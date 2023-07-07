#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.hpp"
#include <iostream>
#include "header/cartas.hpp"
#include "header/regras.hpp"
#include "code/regras.cpp"
#include "header/dupla.hpp"
#include "header/sub_rodada.hpp"
#include "header/rodada.hpp"
#include "header/jogo.hpp"
#include "header/JOGO_principal.hpp"


TEST_CASE("Cadastro de Jogadores") {
    // Configurar a entrada do usuário para simular a inserção de nomes
    std::istringstream input("João\nMaria\nCarlos\nAna\n");

    // Redirecionar a entrada padrão para o fluxo de entrada simulado
    std::streambuf* oldCin = std::cin.rdbuf(input.rdbuf());

    // Chamar a função de cadastro de jogadores
    std::vector<Jogador> jogadores = cadastro_jogadores();

    // Restaurar o fluxo de entrada padrão
    std::cin.rdbuf(oldCin);

    // Verificar se o vetor de jogadores possui o tamanho correto
    CHECK(jogadores.size() == 4);

    // Verificar os nomes dos jogadores individualmente
    CHECK(jogadores[0].nome_jogador == "João");
    CHECK(jogadores[1].nome_jogador == "Maria");
    CHECK(jogadores[2].nome_jogador == "Carlos");
    CHECK(jogadores[3].nome_jogador == "Ana");
}

TEST_CASE("Exibição de Jogadores") {
    // Configurar a saída padrão para redirecionar para um fluxo de saída simulado
    std::ostringstream output;
    std::streambuf* oldCout = std::cout.rdbuf(output.rdbuf());

    // Criar um vetor de jogadores para exibir
    std::vector<Jogador> jogadores;
    jogadores[0].nome_jogador = "João";
    jogadores[1].nome_jogador = "Maria";
    jogadores[2].nome_jogador = "Carlos";
    jogadores[3].nome_jogador = "Ana";

    // Chamar a função de exibição de jogadores
    exibe_jogadores(jogadores);

    // Restaurar o fluxo de saída padrão
    std::cout.rdbuf(oldCout);

    // Verificar se a saída corresponde ao esperado
    std::string expectedOutput = "-------------------------------------------------------------------\n"
                                 "João\n"
                                 "Maria\n"
                                 "Carlos\n"
                                 "Ana\n"
                                 "-------------------------------------------------------------------\n";
    CHECK(output.str() == expectedOutput);
}

TEST_CASE("Definição de Duplas") {
    // Criar um vetor de jogadores para definir as duplas
    std::vector<Jogador> jogadores;
    jogadores[0].nome_jogador = "João";
    jogadores[1].nome_jogador = "Maria";
    jogadores[2].nome_jogador = "Carlos";
    jogadores[3].nome_jogador = "Ana";

    // Chamar a função para definir as duplas
    std::pair<Dupla, Dupla> duplas = set_duplas(jogadores);

    // Verificar se as duplas foram definidas corretamente
    CHECK(duplas.first.duplinha.first.nome_jogador == "Maria");
    CHECK(duplas.first.duplinha.second.nome_jogador == "Carlos");
    CHECK(duplas.second.duplinha.first.nome_jogador == "Ana");
    CHECK(duplas.second.duplinha.second.nome_jogador == "Pedro");
}

TEST_CASE("Exibição de Duplas") {
    // Criar as duplas para serem exibidas
    Dupla d1, d2;
    std::vector<Jogador> jogadoress;
    jogadoress[0].nome_jogador = "João";
    jogadoress[1].nome_jogador = "Maria";
    jogadoress[2].nome_jogador = "Carlos";
    jogadoress[3].nome_jogador = "Ana";

    d1.duplinha.first = jogadoress[1];
    d1.duplinha.second = jogadoress[2];
    d2.duplinha.first = jogadoress[3];
    d2.duplinha.second = jogadoress[4];
    std::pair<Dupla,Dupla> duplas;
    duplas.first = d1;
    duplas.second = d2;

    // Redirecionar saída padrão para um stringstream
    std::stringstream output;
    std::streambuf* oldOutput = std::cout.rdbuf(output.rdbuf());

    // Chamar a função para exibir as duplas
    exibe_duplas(duplas);

    // Restaurar a saída padrão
    std::cout.rdbuf(oldOutput);

    // Verificar se a saída está correta
    std::string expectedOutput = "Duplas formadas:\n"
                                 "-------------------------------------------------------------------\n"
                                 "Dupla 1:\n"
                                 "Jogador 1: João\n"
                                 "Jogador 2: Maria\n"
                                 "-------------------------------------------------------------------\n"
                                 "VS\n"
                                 "-------------------------------------------------------------------\n"
                                 "Dupla 2:\n"
                                 "Jogador 1: Carlos\n"
                                 "Jogador 2: Ana\n"
                                 "-------------------------------------------------------------------\n";

    CHECK(output.str() == expectedOutput);
}
//Então profesor, o arquivo doctest está apresentando erro, mas pegamos o arquivo do githubs como o senhor havia indicado.
//Por isso, não conseguimos testar o doctest e não implementamos mais testes, pois nem sabemos se funcionará. No mais, agradeço
//a atenção e lhe desejo boas férias.


