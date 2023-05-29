
#include "../header/cartas.hpp"
#include "../header/jogo.hpp"
#include "../header/JOGO_principal.hpp"
#include "../header/rodada.hpp"
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
        if(duplas.first.jogos_vencidos < 2  && duplas.second.jogos_vencidos < 2){
            while(duplas.first.pontuacao_subrodada < 12 && duplas.second.pontuacao_subrodada < 12){
                jogo.comeca_rodada(duplas);
                duplas.first.pontuacao +=2;
            };
        } else {
            jogo.campeao(duplas);
        }
    
    }

    return 0;
}