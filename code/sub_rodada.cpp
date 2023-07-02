#include "../header/jogo.hpp"
#include "../header/sub_rodada.hpp"
#include "../header/dupla.hpp"

#include <iostream>
#include <string>
#include <vector>

std::pair<std::vector<Carta>,std::string> Sub_Rodada::joga_carta(std::pair<Dupla, Dupla>& duplas, unsigned i, Pede_Truco truquinho){
    
    int i1 = -1, i2 = -1, i3 = -1, i4 = -1;
    std::pair<bool,std::string> jogador_truco_SR;
    std::pair<bool,std::string> jogador_aceita_truco_SR;
    std::pair<std::vector<Carta>,std::string> sub_rodada_truco;
    std::vector<Carta>mao_rodada;
    Rodada rodada;
    
    if(truquinho.condition == false){
        jogador_truco_SR = truquinho.pede_truco(duplas, 1);
        truquinho.condition = jogador_truco_SR.first;
    }
    if(truquinho.condition == true && truquinho.condition_aceitas == false && 
    jogador_truco_SR.second == duplas.second.duplinha.first.nome_jogador ||
    jogador_truco_SR.second == duplas.second.duplinha.second.nome_jogador){
        jogador_aceita_truco_SR = truquinho.aceita_truco(duplas,1);
        truquinho.condition_aceitas= jogador_aceita_truco_SR.first;
        if(truquinho.condition_aceitas == false){
            sub_rodada_truco.second = "Truco recusado dupla 1";
            return sub_rodada_truco;
        }
    }

    while(i1 < 0 || i1 > i){
        std::cout << duplas.first.duplinha.first.nome_jogador <<" suas cartas estão numeradas de 0 a " << i <<" Escolha uma, entre 0 e " << i << " para lançar: " << std::endl;
        std:: cin >> i1; std::cout << std::endl;
    }
    mao_rodada.push_back(duplas.first.duplinha.first.mao[i1]);
    duplas.first.duplinha.first.mao.erase(duplas.first.duplinha.first.mao.begin() + i1);
    

   if(truquinho.condition == false){
        jogador_truco_SR = truquinho.pede_truco(duplas, 3);
        truquinho.condition = jogador_truco_SR.first;
    }
    if(truquinho.condition == true && truquinho.condition_aceitas == false && 
    jogador_truco_SR.second == duplas.first.duplinha.first.nome_jogador ||
    jogador_truco_SR.second == duplas.first.duplinha.second.nome_jogador){
        jogador_aceita_truco_SR = truquinho.aceita_truco(duplas,3);
        truquinho.condition_aceitas= jogador_aceita_truco_SR.first;
        if(truquinho.condition_aceitas == false){
            pontuacao_sub_rodada_dupla1 = 10;
            sub_rodada_truco.second = "Truco recusado dupla 2";
            return sub_rodada_truco;
        }
    }

    while(i3 < 0 || i3 > i){
        std::cout << duplas.second.duplinha.first.nome_jogador << " suas cartas estão numeradas de 0 a " << i <<" Escolha uma, entre 0 e " << i << " para lançar: " << std::endl;
        std:: cin >> i3; std::cout << std::endl;
    }
    mao_rodada.push_back(duplas.second.duplinha.first.mao[i3]);
    duplas.second.duplinha.first.mao.erase(duplas.second.duplinha.first.mao.begin() + i3);  

    if(truquinho.condition == false){
        jogador_truco_SR = truquinho.pede_truco(duplas, 2);
        truquinho.condition = jogador_truco_SR.first;
    }
    if(truquinho.condition == true && truquinho.condition_aceitas == false && 
    jogador_truco_SR.second == duplas.second.duplinha.first.nome_jogador ||
    jogador_truco_SR.second == duplas.second.duplinha.second.nome_jogador){
        jogador_aceita_truco_SR = truquinho.aceita_truco(duplas,2);
        truquinho.condition_aceitas= jogador_aceita_truco_SR.first;
        if(truquinho.condition_aceitas == false){
            sub_rodada_truco.second = "Truco recusado dupla 1";
            return sub_rodada_truco;
        }
    }

    while(i2 < 0 || i2 > i){
        std::cout << duplas.first.duplinha.second.nome_jogador <<" suas cartas estão numeradas de 0 a " << i <<" Escolha uma, entre 0 e " << i << " para lançar: " << std::endl;
        std:: cin >> i2; std::cout << std::endl;
    }
    mao_rodada.push_back(duplas.first.duplinha.second.mao[i2]);
    duplas.first.duplinha.second.mao.erase(duplas.first.duplinha.second.mao.begin() + i2); 

    if(truquinho.condition == false){
        jogador_truco_SR = truquinho.pede_truco(duplas, 4);
        truquinho.condition = jogador_truco_SR.first;
    }
    if(truquinho.condition == true && truquinho.condition_aceitas == false && 
    jogador_truco_SR.second == duplas.first.duplinha.first.nome_jogador ||
    jogador_truco_SR.second == duplas.first.duplinha.second.nome_jogador){
        jogador_aceita_truco_SR = truquinho.aceita_truco(duplas,4);
        truquinho.condition_aceitas= jogador_aceita_truco_SR.first;
        if(truquinho.condition_aceitas == false){
            sub_rodada_truco.second = "Truco recusado dupla 2";
            return sub_rodada_truco;
        }
    }

    while(i4 < 0 || i4 > i){
        std::cout << duplas.second.duplinha.second.nome_jogador <<" suas cartas estão numeradas de 0 a " << i <<" Escolha uma, entre 0 e " << i << " para lançar: " << std::endl;
        std:: cin >> i4; std::cout << std::endl;
    }
    mao_rodada.push_back(duplas.second.duplinha.second.mao[i4]);
    duplas.second.duplinha.second.mao.erase(duplas.second.duplinha.second.mao.begin() + i4);

    std::cout << "-------------------------------------------------------------------" << std::endl;
    std::cout << "Cartas das mãos dos jogares: " << std::endl;
    std::cout << std::endl;
    rodada.exibe_cartas(duplas, i);
    std::cout << "-------------------------------------------------------------------" << std::endl;
    std::cout << "Cartas jogadas: " << std::endl;
    std::cout << duplas.first.duplinha.first.nome_jogador << ": " << mao_rodada[0].toString() << std::endl;
    std::cout << "-------------------------------------------------------------------" << std::endl;
    std::cout << duplas.second.duplinha.first.nome_jogador << ": "<< mao_rodada[2].toString() << std::endl;
    std::cout << "-------------------------------------------------------------------" << std::endl;
    std::cout << duplas.first.duplinha.second.nome_jogador << ": " << mao_rodada[1].toString() << std::endl;
    std::cout << "-------------------------------------------------------------------" << std::endl;
    std::cout << duplas.second.duplinha.second.nome_jogador << ": "<< mao_rodada[3].toString() << std::endl;
    std::cout << "-------------------------------------------------------------------" << std::endl;
    std::cout << std::endl;
    for(size_t i = 0; i < mao_rodada.size(); ++i){
        sub_rodada_truco.first[i] = mao_rodada[i];
    }
    sub_rodada_truco.second = "Nenhum pedido de Truco";
    return sub_rodada_truco;
    //}
    }

