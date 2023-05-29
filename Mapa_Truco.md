                         MAPA TRUCO

                ÚLTIMA ATUALIZAÇÃO 29/05/2023

Ao atuzalizar esse arquivo, atualizar a data e assinar a atuzalição ao final do texto, sem pagar os registros anteriores, para que possamos acompanhar o que vem sendo feito. Favor especificar novas classes e funções implementadas.



Nesse arquivo irei detalhar um mapa de tudo que precisa ser implementado para a criação de um jogo de truco.

Jogadores: 4 jogadores, cada um terá apenas um nome.

Duplas: 2 duplas, cada uma composta por 2 jogadores. Uma dupla irá armazenar pontuações referentes a: 
  
  
   I) Rodadas: 0 a 12
   II) Jogos: 0 a 2

   Para vencer uma rodada, uma dupla deve vencer 2 de 3 subrodadas. Ao vencer uma rodada a dupla ganha 2 pontos. Em caso de truco a rodada pode valer 4,6,9 ou 12 pontos, conforme os jogadores aceitam apostam.

   Ao obter 12 pontos nas rodadas, vence-se um jogo. Para que uma dupla vença a partida é necessário que vença dois jogos de até 3.


Vence uma sub rodada,a dupla em que um dos jogadores jogar a maior carta.
Na primeira sub rodada, se houver um empate, ambas as duplas pontuam 1 e a segunda sub rodada torna-se decisiva.

Mapa de como nosso código está sendo implementado:

Função main:

  1) Cadastro dos jogadores: jogadores cadastram seus nomes através da função cadastro_jogadores(), criando um vetor de "Jogador" de 4 posições.

  "Jogador" é uma estrutura que armazena o nome de um jogador e possui a função get_nome(), que pede que seja inserido uma string e armazena como nome do jogador.

  Após o cadastro dos jogadores, a função exibe_jogadores() printa o nome de cada jogador na tela

  2) Definição das duplas: o próprio jogo define as duplas por meio da função set_duplas(). Para isso, usa-se um par de duas "Dupla"

  "Dupla" é uma classe que irá armazenar um par de "Jogador", uma pontuação referente a uma sub_rodada, uma pontuação referente ao número de rodadas vencidas e um número de jogos vencidos.

  3) Início do jogo: Cria-se um JOGO jogo. A classe "JOGO" irá armazenar o par de Duplas cadastrado em 2. Além disso, irá possuir o método começa_rodada() e campeao().

  4) O jogo irá funcionar da seguinte maneira: Enquanto nenhuma das duplas obtiver 2 jogos, iremos começar um novo jogo (IMPLEMENTAR FUNÇÃO COMEÇA-JOGO). Agora, com um novo jogo criado, enquanto nenhuma das duplas atingir 12 pontos em rodadas, começaremos uma nova rodada, por meio da função começa_rodada(duplas) já implementada.

  A função começa_rodada() cria uma Rodada rodada. A classe Rodada armazena todos os métodos relativos a uma rodada. Inicialmente, acionamos o método distribui_cartas(duplas) e o método exibe_cartas(). Assim, cada jogador receberá 3 cartas e poderá vê-las. 

  Em seguida, criaremos as sub_rodadas. Necessariamente, haverá 2 sub_rodadas, caso a rodada não termine com 2 sub rodadas, faz-se necessário a criação de uma terceira sub_rodada de desempate. Dentro de uma sub rodada, o processo de pontuação já é feito automaticamente.

  Logo, enquanto a pontuação de sub rodadas de ambas as duplas for menor que 2, começaremos uma nova sub rodada. Em uma sub rodada, cada jogador joga uma carta com o método joga_carta() e usamos o método verifica_vencedor() para atribuir pontuação a dupla vencedora da sub rodada (PHILL ESTÁ TRABALHANDO NISSO NESSE EXATO MOMENTO). 

  Nesse momento, assim que uma das duplas atingir uma pontuação de sub rodada igual a 2, atribuímos mais 2 pontos a sua pontuação de rodadas (ESTOU IGNORANDO A POSSIBILIDADE DE PEDIR TRUCO POR ENQUANTO). Assim, se nenhuma das duplas atingir 12 pontos, damos início a outra rodada, que funcionará da mesma forma. Caso uma delas atinja tal pontuação, o laço é encerrado e um jogo é atribuído a dupla. Se, com isso, nenhuma dupla tiver vencido dois jogos, iniciaremos mais um jogo. Caso contrário declaramos a dupla com 2 jogos vencedora da PARTIDA.

  Notem que precisamos mudar nossa implementação.

  Precisamos criar uma PARTIDA. Para vencer uma PARTIDA, a dupla deve vencer 2 JOGOS.
  Após a criação da PARTIDA, criamos UM JOGO. Para vencer um JOGO, a dupla deve fazer 12 pontos em rodadas.
  Após criar um JOGO, criamos RODADAS até que uma dupla faça 12 pontos. 
  Após criar uma RODADA, criamos SUB RODADAS até que uma dupla vença 2 SUB RODADAS.


Esse mapa mental visa mapear a implementação de uma partida de truco. Por enquanto, já trabalhamos em um jogo, rodadas e estamos tentando declarar o vencedor de uma sub rodada perante todos os cenários possíveis.


DATA DE ATUALIZAÇÃO: 29/05/2023 GABRIEL VAZ
