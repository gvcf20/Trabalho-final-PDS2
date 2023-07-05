#include "../header/JOGO_principal.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <limits>

int main(){
    
    std::cout << "*Olá seres humanos, vocês desejam jogar truco [Y/N]?" << std::endl;
    std::cout << " -------------------------------------" << std::endl;

    char resposta;
    while (true) {
        std::cin >> resposta;
        resposta = std::toupper(resposta);

        if (resposta == 'Y') {
            std::cout << "Você escolheu SIM. Vamos jogar truco!" << std::endl;
            break;
        } else if (resposta == 'N') {
            std::cout << "Você escolheu NÃO. Até a próxima!" << std::endl;
            return 0;
        } else {
            std::cout << "Entrada inválida! Por favor, digite Y para sim ou N para Não." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
        
        Regras regras;
        std::cout << "Seres humanos, os senhores gostariam de saber as regras do nosso truco? Fizemos algumas adaptações do truco convencional... : [Y/N]" << std::endl;
        regras.exibe_regra();
        std::vector<Jogador> jogadores = cadastro_jogadores();
        exibe_jogadores(jogadores);
        std::cout << " " << std::endl;
        std::pair<Dupla, Dupla> duplas = set_duplas(jogadores);
        exibe_duplas(duplas);
        duplas.first.jogos_vencidos = 0;
        duplas.second.jogos_vencidos = 0;
        
        while(duplas.first.jogos_vencidos < 2 && duplas.second.jogos_vencidos < 2){
            Regras regras;
    
            JOGO jogo;
            jogo.comeca_jogo(duplas);
        
        }

        if(duplas.first.jogos_vencidos = 2){
            std::cout << "Os Vencedores são: " << duplas.first.duplinha.first.nome_jogador
            << " e "
            << duplas.first.duplinha.second.nome_jogador << std::endl;
        } else{
            std::cout << "Os Vencedores são: " << duplas.second.duplinha.first.nome_jogador
            << " e "
            << duplas.second.duplinha.second.nome_jogador << std::endl;
        }


    return 0;
}