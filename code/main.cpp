#include "../header/JOGO_principal.hpp"
#include <iostream>
#include <string>
#include <vector>

int main(){
    
    std::cout << "*Olá seres humanos, vocês desejam jogar truco [Y/N]?" << std::endl;
    std::cout << " -------------------------------------" << std::endl;
    char c; 
    std::cin >> c;
    std::cout << std::endl;
    if(c == 'Y'){
        
        std::vector<Jogador> jogadores = cadastro_jogadores();
        exibe_jogadores(jogadores);
        std::cout << " " << std::endl;
        std::pair<Dupla, Dupla> duplas = set_duplas(jogadores);
        exibe_duplas(duplas);
        std::cout << " " << std::endl;


        while(duplas.first.jogos_vencidos < 2 && duplas.second.jogos_vencidos < 2){
            std::cout << " A PARTIDA VAI COMEÇAR " << std::endl;
            std::cout << " " << std::endl;

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

    }

    return 0;
}