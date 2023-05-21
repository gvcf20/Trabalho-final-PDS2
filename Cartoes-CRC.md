Classe: Cartas
---------------------

Responsabilidades: 
Declarar todas as cartas existentes no baralho.
Define os naipes existentes.

Colaboradores: 
xxxxxxxx


Classe: Jogador
---------------------

Responsabilidades: 
Nome.
Dupla.
Cartas na mão.
Jogar uma carta.
Pedir Truco.
Aumentar.
Sair.

Colaboradores: 
Cartas.


Classe: Regras
---------------------

Responsabilidades: 
Cada jogador recebe 3 cartas.
Manutenção da ordem de jogo.
Define 12 como pontuação máxima de uma rodada.


Colaboradores: 
Cartas.


Classe: Mão
---------------------

Responsabilidades: 
Armazenar até 3 cartas.
exibir cartas.
adicionar 3 cartas.
remover cartas 1 a 1 a cada rodada.

Colaboradores: 
Cartas.
Jogador.


Classe: Mesa
---------------------

Responsabilidades: 
Exibir cartas na mesa.
Resetar para 0 cartas.
Adiciona cartas.

Colaboradores: 
Cartas.
Jogadores.


Classe: Dupla
---------------------

Responsabilidades: 
Mostrar a maior carta na mesa.
Adicionar pontos as duplas.
Definir a vez de cada jogador.
Pontuação atual da rodada.

Colaboradores: 
Cartas.
Regras.
Duplas.



Classe: Placar
---------------------

Responsabilidades: 
Exibe o placar.
Atualizada a cada rodada
Iniciar com 0 a 0

Colaboradores: 
Regras.
Rodada.
Dupla.



Classe: Valor_Rodada
---------------------

Responsabilidades: 
Inicializa em 0 x 0.
Aumenta um ponto a cada rodada.

Colaboradores: 
Cartas.
Dupla.



Classe:Vencedor
---------------------

Responsabilidades: 
Determinar vencedor.
Exibir Dupla vencedora.
Exibir placar.

Colaboradores: 
Rodada.
Placar.

