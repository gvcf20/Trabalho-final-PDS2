#include "../header/jogo.hpp"
#include "../header/rodada.hpp"
#include "../header/jogador.hpp"
#include "../header/sub_rodada.hpp"
#include "../header/dupla.hpp"
#include "regras.cpp"
#include <iostream>
#include <vector>

std::vector<Carta> Sub_Rodada::joga_carta(std::pair<Dupla, Dupla>& duplas, unsigned i){
    
    int i1 = -1, i2 = -1, i3 = -1, i4 = -1;
    std::vector<Carta>mao_rodada;
    Rodada rodada;
        
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
    rodada.exibe_cartas(duplas);
    std::cout << "Cartas jogadas: " << std::endl;
    std::cout << duplas.first.duplinha.first.nome_jogador << ": " << mao_rodada[0].toString() << std::endl;
    std::cout << duplas.first.duplinha.second.nome_jogador << ": "<< mao_rodada[1].toString() << std::endl;
    std::cout << duplas.second.duplinha.first.nome_jogador << ": " << mao_rodada[2].toString() << std::endl;
    std::cout << duplas.second.duplinha.second.nome_jogador << ": "<< mao_rodada[3].toString() << std::endl;

    //Vencedor vencedor;

    //std::cout << "O vencedor da rodada foi: " << vencedor.vencedor_sub_rodada(mao_rodada) << std::endl;
    //std::cout << PLACAR PARCIAL << std::endl;
    return mao_rodada;
}

Dupla Sub_Rodada::verifica_vencedor(std::pair<Dupla, Dupla>& duplas, std::vector<Carta> cartas_jogadas){

    Vencedor vencedor;
    std::vector<Carta> mao_copiada1;
    std::vector<Carta> mao_copiada2;
    std::vector<Carta> mao_copiada3;
    std::vector<Carta> mao_copiada4;
   
    for(size_t i = 0; i < duplas.first.duplinha.first.mao.size(); ++i){
        mao_copiada1[i] = duplas.first.duplinha.first.mao[i];
    }
    for(size_t i = 0; i < duplas.first.duplinha.second.mao.size(); ++i){
        mao_copiada2[i] = duplas.first.duplinha.second.mao[i];
    }
    for(size_t i = 0; i < duplas.second.duplinha.first.mao.size(); ++i){
        mao_copiada3[i] = duplas.second.duplinha.first.mao[i];
    }
    for(size_t i = 0; i < duplas.second.duplinha.second.mao.size(); ++i){
        mao_copiada4[i] = duplas.second.duplinha.second.mao[i];
    }

    if(vencedor.vencedor_sub_rodada(cartas_jogadas)){
        
        for(size_t i = 0; i < duplas.first.duplinha.first.mao.size(); ++i){
            if(cartas_jogadas[0] == duplas.first.duplinha.first.mao[i]){
                std::cout << "A dupla 1 foi a ganhadora da primeira sub_rodada" << std::endl;
            }
        }

        for(size_t i = 0; i < duplas.first.duplinha.first.mao.size(); ++i){
            if(cartas_jogadas[0] == duplas.first.duplinha.second.mao[i]){
                std::cout << "A dupla 1 foi a ganhadora da primeira sub_rodada" << std::endl;
            }
        }

        for(size_t i = 0; i < duplas.first.duplinha.first.mao.size(); ++i){
            if(cartas_jogadas[0] == duplas.second.duplinha.first.mao[i]){
                std::cout << "A dupla 2 foi a ganhadora da primeira sub_rodada" << std::endl;
            }
        }

        for(size_t i = 0; i < duplas.first.duplinha.first.mao.size(); ++i){
            if(cartas_jogadas[0] == duplas.second.duplinha.second.mao[i]){
                std::cout << "A dupla 1 foi a ganhadora da primeira sub_rodada" << std::endl;
            }
        }

    } else if(vencedor.empate_sub_rodada(cartas_jogadas)){

    }
    
}

