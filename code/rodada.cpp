#include "../header/rodada.hpp"
#include "../header/sub_rodada.hpp"
#include "../header/embaralhamento.hpp"
#include "../header/dupla.hpp"
#include "../header/regras.hpp"

#include <iostream>
#include <vector>

std::vector<Carta> Rodada::dar_cartas(Baralho& baralho){
    std::vector<Carta> mao ={};
    for(int i = 0; i < 3; ++i){
        auto carta = baralho.pegar_cartas();
        mao.push_back(carta);
    }
    
    return mao;
}

void Rodada::distribui_cartas(std::pair<Dupla, Dupla>& duplas){
    Baralho baralho;
    baralho.inicializa_Baralho();
    embaralhar(baralho);
    std::vector<Carta> mao;
    duplas.first.duplinha.first.set_mao(dar_cartas(baralho));
    duplas.first.duplinha.second.set_mao(dar_cartas(baralho));
    duplas.second.duplinha.first.set_mao(dar_cartas(baralho));
    duplas.second.duplinha.second.set_mao(dar_cartas(baralho));

}

void Rodada::exibe_cartas(std::pair<Dupla, Dupla> duplas, unsigned j){
    std::vector<Carta> mao_jogador1;
    Jogador jogador;
    if(duplas.first.duplinha.first.mao.size() > 0){
        std::cout << "-------------------------------------------------------------------" << std::endl;
        std::cout << "Dupla 1 " << duplas.first.duplinha.first.nome_jogador << std::endl;
        for(int i = 0; i < j; ++i){
            std::cout << duplas.first.duplinha.first.mao[i].toString() << std::endl;
        }
        std::cout << "-------------------------------------------------------------------" << std::endl;
        std::cout << "Dupla 1 " << duplas.first.duplinha.second.nome_jogador << std::endl;
        for(int i = 0; i < j; ++i){
            std::cout << duplas.first.duplinha.second.mao[i].toString() << std::endl;
        }
        std::cout << "-------------------------------------------------------------------" << std::endl;
        std::cout << "Dupla 2 " << duplas.second.duplinha.first.nome_jogador << std::endl;
        for(int i = 0; i < j; ++i){
            std::cout << duplas.second.duplinha.first.mao[i].toString() << std::endl;
        }
        std::cout << "-------------------------------------------------------------------" << std::endl;
        std::cout << "Dupla 2 " << duplas.second.duplinha.second.nome_jogador << std::endl;
        for(int i = 0; i < j; ++i){
            std::cout << duplas.second.duplinha.second.mao[i].toString() << std::endl;
        }
        std::cout << "-------------------------------------------------------------------" << std::endl;
    }
}

void Comeca_Rodada::comeca_rodada(std::pair <Dupla, Dupla>& duplas_h){
    
    Regras regras;
    Rodada rodada;
    Vencedor vencedor;
    unsigned ptl = 1;
    unsigned indice = 2;
    unsigned j = 3;
    std::pair<Jogador, std::vector<Carta>> jogador_vencedor_SR;
    std::pair<Dupla, std::vector<Carta>> Dupla_empate_SR;
    std::pair<unsigned int, unsigned int> pontuacao_SR;
    pontuacao_SR.first = 0;
    pontuacao_SR.second = 0;
    Pede_Truco truquinho;
    truquinho.condition = false;
    truquinho.condition_aceitas = false;

    rodada.distribui_cartas(duplas_h);
    Sub_Rodada sub_rodada;
    sub_rodada.pontuacao_sub_rodada_dupla1 = 0;
    sub_rodada.pontuacao_sub_rodada_dupla2 = 0;

     while(sub_rodada.pontuacao_sub_rodada_dupla1 < 5 || sub_rodada.pontuacao_sub_rodada_dupla2 < 5){
        
        rodada.exibe_cartas(duplas_h,j);
        std::vector<Carta> cartas_jogadas;
        cartas_jogadas = sub_rodada.joga_carta(duplas_h, indice);
        std::vector<Carta> maior_carta;
        maior_carta = regras.maior_carta(cartas_jogadas);
        
        bool condicao;
        condicao = vencedor.vencedor_sub_rodada(cartas_jogadas);
        bool condicao1;
        condicao1 = vencedor.empate_sub_rodada(cartas_jogadas);

        if(condicao == true){
           
            jogador_vencedor_SR = vencedor.verifica_vencedor_SR(cartas_jogadas, duplas_h);
            pontuacao_SR = vencedor.pontos_sub_rodada_vencedor(duplas_h , cartas_jogadas, ptl);

            std::cout << "-------------------------------------------------------------------" << std::endl;
            std::cout <<"O jogador: " << jogador_vencedor_SR.first.nome_jogador <<
            " ganhou a partida com a carta: " << jogador_vencedor_SR.second[0].toString() << std::endl;
            std::cout << "-------------------------------------------------------------------" << std::endl;
        }

        else if(condicao1){
            Dupla_empate_SR = vencedor.verifica_empate_SR(cartas_jogadas, duplas_h);
            pontuacao_SR = vencedor.pontos_sub_rodada_vencedor(duplas_h , cartas_jogadas, ptl);

            if(Dupla_empate_SR.first.duplinha.first.nome_jogador == duplas_h.first.duplinha.first.nome_jogador
            && Dupla_empate_SR.first.duplinha.second.nome_jogador == duplas_h.first.duplinha.second.nome_jogador
            || Dupla_empate_SR.first.duplinha.first.nome_jogador == duplas_h.second.duplinha.first.nome_jogador
            && Dupla_empate_SR.first.duplinha.second.nome_jogador == duplas_h.second.duplinha.second.nome_jogador){
                
                std::cout << "-------------------------------------------------------------------" << std::endl;
                std::cout << "Não houve um empate entre os jogadores: " << Dupla_empate_SR.first.duplinha.first.nome_jogador 
                << " e " << Dupla_empate_SR.first.duplinha.second.nome_jogador << ", devido a terem jogado as cartas: "
                << Dupla_empate_SR.second[0].toString() << " e " << Dupla_empate_SR.second[1].toString()
                << " pois pertecem a mesma dupla. " << std::endl;
                std::cout << "-------------------------------------------------------------------" << std::endl;
            }
            else{
                
                std::cout << "-------------------------------------------------------------------" << std::endl;
                std::cout << "Houve um empate entre os jogadores: " << Dupla_empate_SR.first.duplinha.first.nome_jogador 
                << " e " << Dupla_empate_SR.first.duplinha.second.nome_jogador << ", devido a terem jogado as cartas: "
                << Dupla_empate_SR.second[0].toString() << " e " << Dupla_empate_SR.second[1].toString()
                << " que detém o mesmo peso. " << std::endl;
                std::cout << "-------------------------------------------------------------------" << std::endl;
            }

        }
        
        sub_rodada.pontuacao_sub_rodada_dupla1 += pontuacao_SR.first;
        sub_rodada.pontuacao_sub_rodada_dupla2 += pontuacao_SR.second;
        if(indice > 0){
            indice -= 1;
        } else break;
        ptl = ptl + 1;
        j = j - 1;

    }
     if(sub_rodada.pontuacao_sub_rodada_dupla1 >= 5){
        truquinho.condition = false;
        truquinho.condition_aceitas = false;
        duplas_h.first.pontuacao += 2;
        std::cout << "-------------------------------------------------------------------" << std::endl;
        std::cout << "A dupla 1 ganhou a primeira rodada e recebe 2 pontos" << std::endl;
        std::cout << "Pontuação atual: " << duplas_h.first.pontuacao << std::endl;
        std::cout << "Pontuação atual: " << duplas_h.second.pontuacao << std::endl;
        std::cout << "-------------------------------------------------------------------" << std::endl;
     } else if (sub_rodada.pontuacao_sub_rodada_dupla2 >= 5){
        truquinho.condition = false;
        truquinho.condition_aceitas = false;
        duplas_h.second.pontuacao += 2;
        std::cout << "-------------------------------------------------------------------" << std::endl;
        std::cout << "A dupla 2 ganhou a primeira rodada e recebe 2 pontos" << std::endl;
        std::cout << "Pontuação atual: " << duplas_h.first.pontuacao << std::endl;
        std::cout << "Pontuação atual: " << duplas_h.second.pontuacao << std::endl;
        std::cout << "-------------------------------------------------------------------" << std::endl;
    }
}

