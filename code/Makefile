
truco: main.o embaralhamento.o jogador.o JOGO_principal.o jogo.o regras.o rodada.o sub_rodada.o
	g++ -std=c++17  main.o embaralhamento.o jogador.o JOGO_principal.o jogo.o regras.o rodada.o sub_rodada.o -o truco

main.o: main.cpp
	g++ -c main.cpp

embaralhamento.o: embaralhamento.cpp ../header/embaralhamento.hpp ../header/cartas.hpp
	g++ -c embaralhamento.cpp	

jogador.o: jogador.cpp ../header/jogador.hpp
	g++ -c jogador.cpp 

JOGO_principal.o: JOGO_principal.cpp ../header/JOGO_principal.hpp
	g++ -c JOGO_principal.cpp	

jogo.o: jogo.cpp ../header/jogo.hpp
	g++ -c jogo.cpp

regras.o: regras.cpp ../header/regras.hpp
	g++ -c regras.cpp 

rodada.o: rodada.cpp ../header/rodada.hpp 
	g++ -c rodada.cpp 

sub_rodada.o: sub_rodada.cpp ../header/sub_rodada.hpp
	g++ -c sub_rodada.cpp				

clean:
	rm *.o truco 