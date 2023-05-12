#include "../header/distribui_cartas.hpp"
#include "../header/cartas.hpp"
#include "../header/embaralhamento.hpp"
#include <iostream>
int main(){
    
    Baralho baralho;
    embaralhar(baralho);
    for(std::size_t i = 0; i < baralho.cartas_baralho.size(); ++i){
        std::cout << baralho.cartas_baralho[i].toString() << std::endl;
    }
    return 0;
}