#include "../header/distribui_cartas.hpp"
#include "../header/cartas.hpp"
#include "../header/jogo.hpp"
#include "../header/embaralhamento.hpp"
#include <iostream>
#include <string>

int main(){
    
    
    std::cout << "*Olá seres humanos, vocês desejam jogar truco [Y/N]?" << std::endl;
    char c; 
    std::cin >> c;
    std::cout << std::endl;
    if(c == 'Y'){
        cadastro_jogadores();
        
    }

    return 0;
}