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

void Regras::exibe_regra(char c){
    if(c == 'Y' || c == 'y' || c == 's' || c == 'S'){

        std::cout << "-------------------------------------------------------------------" << std::endl;
        std::cout << "MANILHAS: A ordem das cartas mais fortes está disposta como segue: " << std::endl
        << "Folhas-QUATRO; Copas-SETE; As-ESPADA; OURO-SETE; TRÊS; DOIS; AS; REI; VALETE" << std::endl
        <<"; RAINHA; SETE; CINCO; QUATRO; Os que não tiveram naipe especificados, são"    << std::endl
        <<" de qualquer naipe exceto pelos 4 primeiros supracitados." << std::endl;
        std::cout << "-------------------------------------------------------------------" << std::endl;
        std::cout << "PONTUAÇÃO: Para se ganhar um jogo, deve-se ganhar 2 partidas, e " << std::endl
        <<"para se ganhar uma partida, deve-se ganhar 12 pontos, que são ganhos de dois " <<std::endl
        <<"em dois a cada rodada vencida. Por fim, para se ganhar uma rodada, deve-se de " << std::endl
        <<"ganhar 5 pontos numa sub_rodada. " <<std::endl;
        std::cout << "-------------------------------------------------------------------" << std::endl;
        std::cout << "Pontuação Sub rodada: Uma sub_rodada tem no máximo, 3 lances, de " <<std::endl
        <<"modo que se os 5 pontos não forem atingindos, a sub_rodada não distribui pon_" <<std::endl
        <<"tos para nenhuma das duplas. Dito isso, o primeiro lance da sub_rodada vale" <<std::endl
        <<" 3 pontos, a segunda 2, a terceira 3 e 2 pontos em caso de empate. É deixa_ " <<std::endl
        <<"xado a cargo dos jogadores como exercício, pensarem nas possibilidades relativas" <<std::endl
        <<"do sistema de pontuação e pesquisarem sobre as outras regras do truco. (Dica: " << std::endl
        << "abra o seu navegador e use o google e tente pesquisar digitando com o teclado.) " << std::endl; 
        std::cout << "-------------------------------------------------------------------" << std::endl;

        std::cout << "A partida vai começar ! " << std::endl;
    } else {
        std::cout << "A partida vai começar ! " << std::endl;
    }
}

 bool Vencedor::vencedor_sub_rodada(std::vector<Carta>& mao_rodada){
    Regras regras;
    std::vector<Carta> maior_carta;
    maior_carta = regras.maior_carta(mao_rodada);
    bool condicao = false;
    size_t a = 1;

    if(maior_carta.size() == a){
        condicao = true;
    }
    return condicao;
}

bool Vencedor::empate_sub_rodada(std::vector<Carta>& mao_rodada){
    Regras regras;
    std::vector<Carta> maior_carta;
    maior_carta = regras.maior_carta(mao_rodada);
    bool condicao = false;
    size_t a = 1;

    if(maior_carta.size() > a){
        condicao = true;
    }
    return condicao;
}

std::pair<Jogador, std::vector<Carta>> Vencedor::verifica_vencedor_SR(std::vector<Carta>& mao_rodada, std::pair<Dupla,Dupla>& duplas){

    Regras regras;
    std::pair<Jogador, std::vector<Carta>> dupla_winner;
    std::vector<Carta> mao_ganhadora = regras.maior_carta(mao_rodada);
    size_t j = 0;

    for(size_t i = 0; i < mao_rodada.size(); ++i){
        if(mao_ganhadora[0] == mao_rodada[i]){
            j = i;
        }
    }
        if(j == 0){
            dupla_winner.first = duplas.first.duplinha.first;
            dupla_winner.second = mao_ganhadora;
        } else if(j == 2){
            dupla_winner.first = duplas.second.duplinha.first;
            dupla_winner.second = mao_ganhadora;
        } else if(j == 1){
            dupla_winner.first = duplas.first.duplinha.second;
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

    if(mao_empate[0].peso == mao_rodada[0].peso && mao_empate[0].peso == mao_rodada[1].peso){
            
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

    else if(mao_empate[0].peso == mao_rodada[2].peso && mao_empate[0].peso == mao_rodada[1].peso){

        dupla_empate.first.duplinha.first = duplas.first.duplinha.second;
        dupla_empate.first.duplinha.second = duplas.second.duplinha.first;
        dupla_empate.second.push_back(mao_rodada[2]);
        dupla_empate.second.push_back(mao_rodada[1]);
    }
    else if(mao_empate[0].peso == mao_rodada[2].peso && mao_empate[0].peso == mao_rodada[3].peso){
        
        dupla_empate.first.duplinha.first = duplas.first.duplinha.second;
        dupla_empate.first.duplinha.second = duplas.second.duplinha.second;
        dupla_empate.second.push_back(mao_rodada[2]);
        dupla_empate.second.push_back(mao_rodada[3]);
    }
    else if(mao_empate[0].peso == mao_rodada[0].peso && mao_empate[0].peso == mao_rodada[2].peso){

        dupla_empate.first.duplinha.first = duplas.first.duplinha.first;
        dupla_empate.first.duplinha.second = duplas.first.duplinha.second;
        dupla_empate.second.push_back(mao_rodada[0]);
        dupla_empate.second.push_back(mao_rodada[2]);
    }
    else if(mao_empate[0].peso == mao_rodada[1].peso && mao_empate[0].peso == mao_rodada[3].peso){

        dupla_empate.first.duplinha.first = duplas.second.duplinha.first;
        dupla_empate.first.duplinha.second = duplas.second.duplinha.second;
        dupla_empate.second.push_back(mao_rodada[1]);
        dupla_empate.second.push_back(mao_rodada[3]);
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

        if(mao_maior[0] == cartas_jogadas[2]){
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

    return pontuacao_sub_rodada;
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

            if(empate_carta[0].peso == cartas_jogadas[0].peso && empate_carta[0].peso == cartas_jogadas[1].peso
            || empate_carta[0].peso == cartas_jogadas[0].peso && empate_carta[0].peso == cartas_jogadas[3].peso){
                pontuacao_sub_rodada.first +=2;
                pontuacao_sub_rodada.second +=2;
            }

            else if(empate_carta[0].peso == cartas_jogadas[2].peso && empate_carta[0].peso == cartas_jogadas[1].peso
            || empate_carta[0].peso == cartas_jogadas[1].peso && empate_carta[0].peso == cartas_jogadas[3].peso){
                pontuacao_sub_rodada.first +=2;
                pontuacao_sub_rodada.second +=2;
            }
            else if(empate_carta[0].peso == cartas_jogadas[0].peso && empate_carta[0].peso == cartas_jogadas[2].peso){
                    
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
            else if(empate_carta[0].peso == cartas_jogadas[1].peso && empate_carta[0].peso == cartas_jogadas[3].peso){
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
        return pontuacao_sub_rodada;

       
    }

    return pontuacao_sub_rodada;    

} 

std::pair<bool,std::string> Pede_Truco::pede_truco(std::pair<Dupla, Dupla>& duplas, unsigned i){
    std::pair<bool,std::string> jogador_truco;
    char pede;
    bool condicao = false;
    if(i == 1){
        std::cout << "O jogador " << duplas.first.duplinha.first.nome_jogador
        << " Deseja pedir truco? " << std::endl;
    } else if(i == 2){
        std::cout << "O jogador " << duplas.first.duplinha.second.nome_jogador
        << " Deseja pedir truco? " << std::endl;
    } else if(i == 3){
        std::cout << "O jogador " << duplas.second.duplinha.first.nome_jogador
        << " Deseja pedir truco? " << std::endl;
    } else if(i == 4){
        std::cout << "O jogador " << duplas.second.duplinha.second.nome_jogador
        << " Deseja pedir truco? " << std::endl;
    }
    std::cout << std::endl;
    while(pede != 'N' && pede != 'n' && pede != 'Y' && pede != 'n'){
        std::cout << "Y/N? " << std::endl;
        std::cin >> pede;
    } 
    std::cout << std::endl;
    if(pede == 'Y'){
        condicao = true;
    }
    if(i == 1){
        jogador_truco.first = condicao;
        jogador_truco.second = duplas.first.duplinha.first.nome_jogador;
    }
    else if(i == 2){
        jogador_truco.first = condicao;
        jogador_truco.second = duplas.first.duplinha.second.nome_jogador;
    }
    else if(i == 3){
        jogador_truco.first = condicao;
        jogador_truco.second = duplas.second.duplinha.first.nome_jogador;
    }
    else if(i == 4){
        jogador_truco.first = condicao;
        jogador_truco.second = duplas.second.duplinha.second.nome_jogador;
    }
    return jogador_truco;
    
}
std::pair<bool,std::string> Pede_Truco::aceita_truco(std::pair<Dupla, Dupla>& duplas, unsigned i){
    std::pair<bool,std::string> jogador_truco;
    char aceita;
    bool condicao = false;
    if(i == 1){
        std::cout << "O jogador " << duplas.first.duplinha.first.nome_jogador
        << " Deseja aceitar o pedido de truco? Y/N" << std::endl;
    } else if(i == 2){
        std::cout << "O jogador " << duplas.first.duplinha.second.nome_jogador
        << " Deseja aceitar o pedido de truco? Y/N" << std::endl;
    } else if(i == 3){
        std::cout << "O jogador " << duplas.second.duplinha.first.nome_jogador
        << " Deseja aceitar o pedido de truco? Y/N" << std::endl;
    } else if(i == 4){
        std::cout << "O jogador " << duplas.second.duplinha.second.nome_jogador
        << " Deseja aceitar o pedido de truco? Y/N" << std::endl;
    }
    std::cout << std::endl;
    while(aceita != 'N' && aceita != 'n' && aceita != 'Y' && aceita != 'n'){
        std::cout << "Y/N? " << std::endl;
        std::cin >> aceita;
    } 
    if(aceita == 'Y'){
        condicao = true;
    }
    if(i == 1){
        jogador_truco.first = condicao;
        jogador_truco.second = duplas.first.duplinha.first.nome_jogador;
    }
    else if(i == 2){
        jogador_truco.first = condicao;
        jogador_truco.second = duplas.first.duplinha.second.nome_jogador;
    }
    else if(i == 3){
        jogador_truco.first = condicao;
        jogador_truco.second = duplas.second.duplinha.first.nome_jogador;
    }
    else if(i == 4){
        jogador_truco.first = condicao;
        jogador_truco.second = duplas.second.duplinha.second.nome_jogador;
    }
    return jogador_truco;
} 

unsigned Pede_Truco::pt_truco(bool condicao){
    if (condicao == false){

    }
}