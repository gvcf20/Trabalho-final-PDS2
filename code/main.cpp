
#include "../header/cartas.hpp"
#include "../header/jogo.hpp"
#include "../header/JOGO_principal.hpp"
#include "../header/embaralhamento.hpp"
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
        std::pair<Dupla, Dupla> duplas = set_duplas(jogadores);
        JOGO jogo;
<<<<<<< HEAD
        while(duplas.first.pontuação < 12 || duplas.second.pontuação < 12){
            jogo.começa_rodada();
        }
=======
        while(duplas.first.pontuação < 12){
            jogo.começa_rodada(duplas);
            duplas.first.pontuação +=2;
        };

>>>>>>> 55c48188433769aaa35df4d7979db9292435c6de
    }

    return 0;
}