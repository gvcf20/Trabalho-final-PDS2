#include "../header/jogo.hpp"
#include "../header/rodada.hpp"
#include "../header/jogador.hpp"
#include "../header/sub_rodada.hpp"
#include "../header/dupla.hpp"
#include "regras.cpp"
#include <iostream>
#include <string>
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

Dupla Sub_Rodada::verifica_vencedor(std::pair<Dupla, Dupla>& duplas, std::vector<Carta> cartas_jogadas, unsigned pt){

    Vencedor vencedor;
    Regras regras;
    std::vector<Carta> mao_maior = regras.maior_carta(cartas_jogadas);

    if(vencedor.vencedor_sub_rodada(cartas_jogadas)){
        
        for(size_t i = 0; i < duplas.first.duplinha.first.mao.size(); ++i){

            if(mao_maior[0] == duplas.first.duplinha.first.mao[i]){
                std::cout << "A dupla 1 foi a ganhadora da " << pt << "° sub_rodada" << std::endl;
                if(pt == 1){
                    pontuacao_sub_rodada_dupla1 = pontuacao_sub_rodada_dupla1 + 3;
                } else if(pt == 2){
                    pontuacao_sub_rodada_dupla1 = pontuacao_sub_rodada_dupla1 + 2;
                } else if(pt == 3){
                    pontuacao_sub_rodada_dupla1 = pontuacao_sub_rodada_dupla1 + 3;
                } else{
                    std::cout <<"Número de sub_rodadas inválidas!!!! " << std::endl;
                    return;
                }
            }
        }

        for(size_t i = 0; i < duplas.first.duplinha.first.mao.size(); ++i){

            if(mao_maior[0] == duplas.first.duplinha.second.mao[i]){
                std::cout << "A dupla 1 foi a ganhadora da " << pt << "° sub_rodada" << std::endl;
                if(pt == 1){
                    pontuacao_sub_rodada_dupla1 = pontuacao_sub_rodada_dupla1 + 3;
                } else if(pt == 2){
                    pontuacao_sub_rodada_dupla1 = pontuacao_sub_rodada_dupla1 + 2;
                } else if(pt == 3){
                    pontuacao_sub_rodada_dupla1 = pontuacao_sub_rodada_dupla1 + 3;
                } else{
                    std::cout <<"Número de sub_rodadas inválidas!!!! " << std::endl;
                    return;
                }
            }
        }

        for(size_t i = 0; i < duplas.first.duplinha.first.mao.size(); ++i){

            if(mao_maior[0] == duplas.second.duplinha.first.mao[i]){
                std::cout << "A dupla 2 foi a ganhadora da " << pt << "° sub_rodada" << std::endl;
                if(pt == 1){
                    pontuacao_sub_rodada_dupla2 = pontuacao_sub_rodada_dupla1 + 3;
                } else if(pt == 2){
                    pontuacao_sub_rodada_dupla2 = pontuacao_sub_rodada_dupla1 + 2;
                } else if(pt == 3){
                    pontuacao_sub_rodada_dupla2 = pontuacao_sub_rodada_dupla1 + 3;
                } else{
                    std::cout <<"Número de sub_rodadas inválidas!!!! " << std::endl;
                    return;
                }
            }
        }
        for(size_t i = 0; i < duplas.first.duplinha.first.mao.size(); ++i){

            if(mao_maior[0] == duplas.second.duplinha.second.mao[i]){
                std::cout << "A dupla 2 foi a ganhadora da " << pt << "° sub_rodada" << std::endl;
                if(pt == 1){
                    pontuacao_sub_rodada_dupla2 = pontuacao_sub_rodada_dupla1 + 3;
                } else if(pt == 2){
                    pontuacao_sub_rodada_dupla2 = pontuacao_sub_rodada_dupla1 + 2;
                } else if(pt == 3){
                    pontuacao_sub_rodada_dupla2 = pontuacao_sub_rodada_dupla1 + 3;
                } else{
                    std::cout <<"Número de sub_rodadas inválidas!!!! " << std::endl;
                    return;
                }
            }
        }
        
        } else if(vencedor.empate_sub_rodada(cartas_jogadas)){
            
            std::vector<Carta> empate_carta = regras.maior_carta(cartas_jogadas);
            size_t i = empate_carta.size();
            for(size_t j = 0; j < 4; ++j){
                if(empate_carta[0] == duplas.first.duplinha.first.mao[j] && empate_carta[0] == duplas.second.duplinha.first.mao[j]
                || empate_carta[0] == duplas.first.duplinha.first.mao[j] && empate_carta[0] == duplas.second.duplinha.second.mao[j]){
                    pontuacao_sub_rodada_dupla1 +=2;
                    pontuacao_sub_rodada_dupla2 +=2;
        }

                else if(empate_carta[0] == duplas.first.duplinha.second.mao[j] && empate_carta[0] == duplas.second.duplinha.first.mao[j]
                || empate_carta[0] == duplas.first.duplinha.second.mao[j] && empate_carta[0] == duplas.second.duplinha.second.mao[j]){
                    pontuacao_sub_rodada_dupla1 +=2;
                    pontuacao_sub_rodada_dupla2 +=2;
        }
                else if(empate_carta[0] == duplas.first.duplinha.first.mao[j] && empate_carta[0] == duplas.first.duplinha.second.mao[j]){
                    
                    std::cout << "A dupla 1 foi a ganhadora da " << pt << "° sub_rodada" << std::endl;
                if(pt == 1){
                    pontuacao_sub_rodada_dupla1 = pontuacao_sub_rodada_dupla1 + 3;
                } else if(pt == 2){
                    pontuacao_sub_rodada_dupla1 = pontuacao_sub_rodada_dupla1 + 2;
                } else if(pt == 3){
                    pontuacao_sub_rodada_dupla1 = pontuacao_sub_rodada_dupla1 + 3;
                } else{
                    std::cout <<"Número de sub_rodadas inválidas!!!! " << std::endl;
                    return;
                }
            }
            else if(empate_carta[0] == duplas.second.duplinha.first.mao[j] && empate_carta[0] == duplas.second.duplinha.second.mao[j]){
                    std::cout << "A dupla 2 foi a ganhadora da " << pt << "° sub_rodada" << std::endl;
                if(pt == 1){
                    pontuacao_sub_rodada_dupla2 = pontuacao_sub_rodada_dupla1 + 3;
                } else if(pt == 2){
                    pontuacao_sub_rodada_dupla2 = pontuacao_sub_rodada_dupla1 + 2;
                } else if(pt == 3){
                    pontuacao_sub_rodada_dupla2 = pontuacao_sub_rodada_dupla1 + 3;
                } else{
                    std::cout <<"Número de sub_rodadas inválidas!!!! " << std::endl;
                    return;
                }
            }

        }
    }
}
    

