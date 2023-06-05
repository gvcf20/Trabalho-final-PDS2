#include "../header/regras.hpp"
#include "../header/sub_rodada.hpp"
#include <iostream>

std::vector<Carta> Regras::maior_carta(std::vector<Carta>& cartas){
    int min,minimal;
    std::vector <Carta> maior_carta;
    min = cartas[0].peso;
    for(std::size_t i = 0; i < cartas.size(); ++i){
        if (cartas[i].peso < min){
            minimal = cartas[i].peso;
            min = cartas[i].peso;
        }
    }
    for(std::size_t i = 0; i < cartas.size(); i++){
        if(minimal == cartas[i].peso){
            maior_carta.push_back(cartas[i]);
            
        }
    }
    return maior_carta;
    
}

 bool Vencedor::vencedor_sub_rodada(std::vector<Carta>& mao_rodada){
    Regras regras;
    std::vector<Carta> maior_carta = regras.maior_carta(mao_rodada);
    bool condicao = false;

    if(maior_carta.size() == 1){
        condicao = true;
    }
    return condicao;
}

bool Vencedor::empate_sub_rodada(std::vector<Carta>& mao_rodada){
    Regras regras;
    std::vector<Carta> maior_carta = regras.maior_carta(mao_rodada);
    bool condicao = false;

    if(maior_carta.size() > 1){
        condicao = true;
    }
    return condicao;
}

std::pair<Jogador, std::vector<Carta>> Vencedor::verifica_vencedor_SR(std::vector<Carta>& mao_rodada, std::pair<Dupla,Dupla>& duplas){

    Regras regras;
    std::pair<Jogador, std::vector<Carta>> dupla_winner;
    std::vector<Carta> mao_ganhadora = regras.maior_carta(mao_rodada);
    size_t j;

    for(size_t i = 0; i < mao_rodada.size(); ++i){
        if(mao_ganhadora[0] == mao_rodada[i]){
            j = i;
        }
    }
        if(j == 0){
            dupla_winner.first = duplas.first.duplinha.first;
            dupla_winner.second = mao_ganhadora;
        } else if(j == 1){
            dupla_winner.first = duplas.first.duplinha.second;
            dupla_winner.second = mao_ganhadora;
        } else if(j == 2){
            dupla_winner.first = duplas.second.duplinha.first;
            dupla_winner.second = mao_ganhadora;
        } else if(j == 3){
            dupla_winner.first = duplas.second.duplinha.first;
            dupla_winner.second = mao_ganhadora;
        }

    return dupla_winner;
}

std::pair<Dupla, std::vector<Carta>> Vencedor::verifica_empate_SR(std::vector<Carta>& mao_rodada, std::pair<Dupla,Dupla>& duplas){

    Regras regras;
    std::pair<Dupla, std::vector<Carta>> dupla_empate;
    std::vector<Carta> mao_empate = regras.maior_carta(mao_rodada);

    if(mao_empate[0].peso == mao_rodada[0].peso && mao_empate[0].peso == mao_rodada[2].peso){
            
        dupla_empate.first.duplinha.first = duplas.first.duplinha.first;
        dupla_empate.first.duplinha.second = duplas.second.duplinha.first;
        dupla_empate.second.push_back(mao_empate[0]);
        dupla_empate.second.push_back(mao_empate[1]);
    }
    else if(mao_empate[0].peso == mao_rodada[0].peso && mao_empate[0].peso == mao_rodada[3].peso){
        
        dupla_empate.first.duplinha.first = duplas.first.duplinha.first;
        dupla_empate.first.duplinha.second = duplas.second.duplinha.second;
        dupla_empate.second.push_back(mao_rodada[0]);
        dupla_empate.second.push_back(mao_rodada[3]);
    }

    else if(mao_empate[0].peso == mao_rodada[1].peso && mao_empate[0].peso == mao_rodada[2].peso){

        dupla_empate.first.duplinha.first = duplas.first.duplinha.second;
        dupla_empate.first.duplinha.second = duplas.second.duplinha.first;
        dupla_empate.second.push_back(mao_rodada[1]);
        dupla_empate.second.push_back(mao_rodada[2]);
    }
    else if(mao_empate[0].peso == mao_rodada[1].peso && mao_empate[0].peso == mao_rodada[3].peso){
        
        dupla_empate.first.duplinha.first = duplas.first.duplinha.second;
        dupla_empate.first.duplinha.second = duplas.second.duplinha.second;
        dupla_empate.second.push_back(mao_rodada[1]);
        dupla_empate.second.push_back(mao_rodada[3]);
    }
    else if(mao_empate[0].peso == mao_rodada[0].peso && mao_empate[0].peso == mao_rodada[1].peso){

        dupla_empate.first.duplinha.first = duplas.first.duplinha.first;
        dupla_empate.first.duplinha.second = duplas.first.duplinha.second;
        dupla_empate.second.push_back(mao_empate[0]);
        dupla_empate.second.push_back(mao_empate[1]);
    }
    else if(mao_empate[0].peso == mao_rodada[2].peso && mao_empate[0].peso == mao_rodada[3].peso){

        dupla_empate.first.duplinha.first = duplas.second.duplinha.first;
        dupla_empate.first.duplinha.second = duplas.second.duplinha.second;
        dupla_empate.second.push_back(mao_empate[0]);
        dupla_empate.second.push_back(mao_empate[1]);
    }

    return dupla_empate;   

}

std::pair<unsigned, unsigned> Vencedor::pontos_sub_rodada_vencedor(std::pair<Dupla, Dupla>& duplas, std::vector<Carta>& cartas_jogadas, unsigned pt){

    Vencedor vencedor;
    Regras regras;
    Sub_Rodada sub;
    std::vector<Carta> mao_maior = regras.maior_carta(cartas_jogadas);
    std::pair<unsigned, unsigned> pontuacao_sub_rodada;
    pontuacao_sub_rodada.first = 0;
    pontuacao_sub_rodada.second = 0;

    if(vencedor.vencedor_sub_rodada(cartas_jogadas)){
        
        if(mao_maior[0] == cartas_jogadas[0]){
            std::cout << "A dupla 1 foi a ganhadora da " << pt << "° sub_rodada" << std::endl;
            if(pt == 1){
                pontuacao_sub_rodada.first = pontuacao_sub_rodada.first + 3;
            } else if(pt == 2){
                pontuacao_sub_rodada.first = pontuacao_sub_rodada.first + 2;
            } else if(pt == 3){
                pontuacao_sub_rodada.first = pontuacao_sub_rodada.first + 3;
            } else{
                std::cout <<"Número de sub_rodadas inválidas!!!! " << std::endl;
                return pontuacao_sub_rodada;
            }
        }

        if(mao_maior[0] == cartas_jogadas[1]){
            std::cout << "A dupla 1 foi a ganhadora da " << pt << "° sub_rodada" << std::endl;
            if(pt == 1){
                pontuacao_sub_rodada.first = pontuacao_sub_rodada.first + 3;
            } else if(pt == 2){
                pontuacao_sub_rodada.first = pontuacao_sub_rodada.first + 2;
            } else if(pt == 3){
                pontuacao_sub_rodada.first = pontuacao_sub_rodada.first + 3;
            } else{
                std::cout <<"Número de sub_rodadas inválidas!!!! " << std::endl;
                return pontuacao_sub_rodada;
            }
        }

        if(mao_maior[0] == cartas_jogadas[2]){
            std::cout << "A dupla 2 foi a ganhadora da " << pt << "° sub_rodada" << std::endl;
            if(pt == 1){
                pontuacao_sub_rodada.second = pontuacao_sub_rodada.second + 3;
            } else if(pt == 2){
                pontuacao_sub_rodada.second = pontuacao_sub_rodada.second + 2;
            } else if(pt == 3){
                pontuacao_sub_rodada.second = pontuacao_sub_rodada.second + 3;
            } else{
                std::cout <<"Número de sub_rodadas inválidas!!!! " << std::endl;
                return pontuacao_sub_rodada;
            }
        }

        if(mao_maior[0] == cartas_jogadas[3]){
            std::cout << "A dupla 2 foi a ganhadora da " << pt << "° sub_rodada" << std::endl;
            if(pt == 1){
                pontuacao_sub_rodada.second = pontuacao_sub_rodada.second + 3;
            } else if(pt == 2){
                pontuacao_sub_rodada.second = pontuacao_sub_rodada.second + 2;
            } else if(pt == 3){
                pontuacao_sub_rodada.second = pontuacao_sub_rodada.second + 3;
            } else{
                std::cout <<"Número de sub_rodadas inválidas!!!! " << std::endl;
                return pontuacao_sub_rodada;
            }
        }
        return pontuacao_sub_rodada;
    }
}
    std::pair<unsigned, unsigned> Vencedor::pontos_sub_rodada_empate(std::pair<Dupla, Dupla>& duplas, std::vector<Carta>& cartas_jogadas, unsigned pt){   
    
    Vencedor vencedor;
    Regras regras;
    Sub_Rodada sub;
    std::vector<Carta> mao_maior = regras.maior_carta(cartas_jogadas);
    std::pair<unsigned, unsigned> pontuacao_sub_rodada;
    pontuacao_sub_rodada.first = 0;
    pontuacao_sub_rodada.second = 0;
    if(vencedor.empate_sub_rodada(cartas_jogadas)){

        std::vector<Carta> empate_carta = regras.maior_carta(cartas_jogadas);
        size_t i = empate_carta.size();

            if(empate_carta[0].peso == cartas_jogadas[0].peso && empate_carta[0].peso == cartas_jogadas[2].peso
            || empate_carta[0].peso == cartas_jogadas[0].peso && empate_carta[0].peso == cartas_jogadas[3].peso){
                pontuacao_sub_rodada.first +=2;
                pontuacao_sub_rodada.second +=2;
            }

            else if(empate_carta[0].peso == cartas_jogadas[1].peso && empate_carta[0].peso == cartas_jogadas[2].peso
            || empate_carta[0].peso == cartas_jogadas[1].peso && empate_carta[0].peso == cartas_jogadas[3].peso){
                pontuacao_sub_rodada.first +=2;
                pontuacao_sub_rodada.second +=2;
            }
            else if(empate_carta[0].peso == cartas_jogadas[0].peso && empate_carta[0].peso == cartas_jogadas[1].peso){
                    
                std::cout << "A dupla 1 foi a ganhadora da " << pt << "° sub_rodada" << std::endl;
                if(pt == 1){
                    pontuacao_sub_rodada.first = pontuacao_sub_rodada.first + 3;
                } else if(pt == 2){
                    pontuacao_sub_rodada.first = pontuacao_sub_rodada.first + 2;
                } else if(pt == 3){
                    pontuacao_sub_rodada.first = pontuacao_sub_rodada.first + 3;
                } else{
                    std::cout <<"Número de sub_rodadas inválidas!!!! " << std::endl;
                    return pontuacao_sub_rodada;
                }
            }
            else if(empate_carta[0].peso == cartas_jogadas[2].peso && empate_carta[0].peso == cartas_jogadas[3].peso){
                    std::cout << "A dupla 2 foi a ganhadora da " << pt << "° sub_rodada" << std::endl;
                if(pt == 1){
                    pontuacao_sub_rodada.second = pontuacao_sub_rodada.second + 3;
                } else if(pt == 2){
                    pontuacao_sub_rodada.second = pontuacao_sub_rodada.second + 2;
                } else if(pt == 3){
                    pontuacao_sub_rodada.second = pontuacao_sub_rodada.second + 3;
                } else{
                    std::cout <<"Número de sub_rodadas inválidas!!!! " << std::endl;
                    return pontuacao_sub_rodada;
        
            }
            return pontuacao_sub_rodada;
        }
    }
}