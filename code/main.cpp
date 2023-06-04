#include "JOGO_principal.cpp"
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


        while(duplas.first.jogos_vencidos < 2 && duplas.second.jogos_vencidos < 2){
            std::cout << " A PARTIDA VAI COMEÇAR " << std::endl;

            JOGO jogo;
            while(duplas.first.pontuacao < 12 && duplas.second.pontuacao < 12){
                jogo.comeca_rodada(duplas);

            }
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