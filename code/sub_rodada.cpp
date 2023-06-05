#include "../header/jogo.hpp"
#include "../header/sub_rodada.hpp"
#include "../header/dupla.hpp"

#include <iostream>
#include <string>
#include <vector>

std::vector<Carta> Sub_Rodada::joga_carta(std::pair<Dupla, Dupla>& duplas, unsigned i){
    
    int i1 = -1, i2 = -1, i3 = -1, i4 = -1;
    std::vector<Carta>mao_rodada;
    Rodada rodada;
    //if(i > -1){    
        while(i1 < 0 || i1 > i){
            std::cout << duplas.first.duplinha.first.nome_jogador <<" suas cartas estão numeradas de 0 a " << i <<" Escolha uma, entre 0 e " << i << " para lançar: " << std::endl;
            std:: cin >> i1; std::cout << std::endl;
        }
        mao_rodada.push_back(duplas.first.duplinha.first.mao[i1]);
        duplas.first.duplinha.first.mao.erase(duplas.first.duplinha.first.mao.begin() + i1);

        while(i2 < 0 || i2 > i){
            std::cout << duplas.first.duplinha.second.nome_jogador <<" suas cartas estão numeradas de 0 a " << i <<" Escolha uma, entre 0 e " << i << " para lançar: " << std::endl;
            std:: cin >> i2; std::cout << std::endl;
        }
        mao_rodada.push_back(duplas.first.duplinha.second.mao[i2]);
        duplas.first.duplinha.second.mao.erase(duplas.first.duplinha.second.mao.begin() + i2);    

        while(i3 < 0 || i3 > i){
            std::cout << duplas.second.duplinha.first.nome_jogador << " suas cartas estão numeradas de 0 a " << i <<" Escolha uma, entre 0 e " << i << " para lançar: " << std::endl;
            std:: cin >> i3; std::cout << std::endl;
        }
        mao_rodada.push_back(duplas.second.duplinha.first.mao[i3]);
        duplas.second.duplinha.first.mao.erase(duplas.second.duplinha.first.mao.begin() + i3);

        while(i4 < 0 || i4 > i){
            std::cout << duplas.second.duplinha.second.nome_jogador <<" suas cartas estão numeradas de 0 a " << i <<" Escolha uma, entre 0 e " << i << " para lançar: " << std::endl;
            std:: cin >> i4; std::cout << std::endl;
        }
        mao_rodada.push_back(duplas.second.duplinha.second.mao[i4]);
        duplas.second.duplinha.second.mao.erase(duplas.second.duplinha.second.mao.begin() + i4);

        std::cout << "Cartas das mãos dos jogares: " << std::endl;
        std::cout << std::endl;
        rodada.exibe_cartas(duplas, i);
        std::cout << "Cartas jogadas: " << std::endl;
        std::cout << duplas.first.duplinha.first.nome_jogador << ": " << mao_rodada[0].toString() << std::endl;
        std::cout << duplas.first.duplinha.second.nome_jogador << ": "<< mao_rodada[1].toString() << std::endl;
        std::cout << duplas.second.duplinha.first.nome_jogador << ": " << mao_rodada[2].toString() << std::endl;
        std::cout << duplas.second.duplinha.second.nome_jogador << ": "<< mao_rodada[3].toString() << std::endl;
        std::cout << std::endl;
            //Vencedor vencedor;

        //     //std::cout << "O vencedor da rodada foi: " << vencedor.vencedor_sub_rodada(mao_rodada) << std::endl;
        //     //std::cout << PLACAR PARCIAL << std::endl;
        return mao_rodada;
        //}
    }

