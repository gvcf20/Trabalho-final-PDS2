
#include "../header/cartas.hpp"
#include "../header/jogo.hpp"
#include "../header/JOGO_principal.hpp"
#include "../header/embaralhamento.hpp"
#include "../header/rodada.hpp"
#include <iostream>
#include <string>
#include <vector>

int main(){
    
    
    std::cout << "*Olá seres humanos, vocês desejam jogar truco [Y/N]?" << std::endl;
    char c; 
    std::cin >> c;
    std::cout << std::endl;
    if(c == 'Y'){
        std::vector<Jogador> jogadores = cadastro_jogadores();
        exibe_jogadores(jogadores);
        std::pair<Dupla, Dupla> duplas = set_duplas(jogadores);
        exibe_duplas(duplas);

        JOGO jogo;
        while(duplas.first.pontuacao < 12){
            
            jogo.comeca_rodada(duplas);
            duplas.first.pontuacao +=2;
            std::cout <<"SUS==================" << std::endl;
        };

    }

    return 0;
}