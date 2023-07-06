# Trabalho-final-PDS2
Trabalho final de pds. Data Final 27/06. Valor: 30 pontos

Tema: Truco

Grupo: Gabriel Vaz C.Ferreira, Bruno Kang Wu, Philip Ribeiro Costa, Gabriel Silva de Araujo

-----------------------------------------------------------------------------------------------------

O Truco é um jogo de cartas bastante popular no Brasil e em outros países da América Latina. Ele é jogado com um baralho espanhol ou um baralho brasileiro de 40 cartas. O Truco possui várias variações e regras regionais. Neste jogo, buscamos seguir o padrão do truco mineiro, porém com algumas alterações.

Regras básicas do jogo de Truco:

Número de jogadores: Quatro jogadores formando duas duplas.

Distribuição das cartas: No início de cada rodada, três cartas são distribuídas para cada jogador. 

Hierarquia das cartas: 
Folhas-QUATRO; Copas-SETE; As-ESPADA; OURO-SETE; TRÊS; DOIS; AS; REI; VALETE; RAINHA; SETE; CINCO; QUATRO; Os que não tiveram naipe especificados, podem ser de qualquer naipe exceto pelos 4 primeiros supracitados.

Rodadas e disputa: 
Para se ganhar um jogo, deve-se ganhar 2 partidas, e para se ganhar uma partida, deve-se ganhar 12 pontos, que são ganhos de dois em dois a cada rodada vencida. Por fim, para se ganhar uma rodada deve-se ganhar 5 pontos numa sub_rodada. 

Pontuação Sub rodada: Uma sub_rodada tem no máximo, 3 lances, de 
modo que se os 5 pontos não forem atingindos, a sub_rodada não distribui pontos para nenhuma das duplas. Dito isso, o primeiro lance da sub_rodada vale 3 pontos, a segunda 2, a terceira 3 e 2 pontos em caso de empate.

Valor das rodadas: Todas as rodadas valem 2 pontos. 

Pedido de truco: Cada jogador pode pedir truco desde que ainda não tenha sido peço por outro jogador na mesma rodada. Se a dupla adversária recusar o pedido, a dupla que pediu truco ganha os pontos automaticamente.

-----------------------------------------------------------------------------------------------------
Funções e Classes:

1 - Função main():

A função main() é a função principal do programa e é o ponto de entrada para a execução. O código começa com uma saudação aos seres humanos e pergunta se eles desejam jogar truco. Em seguida, aguarda a resposta do usuário.

Se o usuário digitar 'Y' (maiúsculo ou minúsculo), a mensagem "Você escolheu SIM. Vamos jogar truco!" será exibida, e o programa continuará a execução.
Se o usuário digitar 'N' (maiúsculo ou minúsculo), a mensagem "Você escolheu NÃO. Até a próxima!" será exibida, e o programa será encerrado.
Se o usuário digitar qualquer outra entrada, uma mensagem de "Entrada inválida!" será exibida, e o usuário será solicitado novamente a digitar 'Y' ou 'N'.
Em seguida, o programa continua com as seguintes etapas:

Cria um objeto Regras chamado regras.
Pergunta aos seres humanos se eles gostariam de saber as regras do truco e chama o método exibe_regra() do objeto regras para exibir as regras adaptadas.
Chama a função cadastro_jogadores() para permitir o cadastro dos jogadores e armazena o resultado no vetor jogadores.
Chama a função exibe_jogadores() para exibir a lista de jogadores cadastrados.
Cria um par de objetos Dupla chamado duplas usando a função set_duplas() com base nos jogadores cadastrados.
Define a quantidade de jogos vencidos para ambas as duplas como 0.
Entra em um loop while que executa o jogo até que uma das duplas vença 2 jogos.
Cria um objeto JOGO chamado jogo e chama o método comeca_jogo() para iniciar o jogo com as duplas.
Após o término do jogo, verifica se a primeira dupla (duplas.first) venceu 2 jogos. Se sim, exibe uma mensagem declarando a primeira dupla como vencedora. Caso contrário, exibe uma mensagem declarando a segunda dupla (duplas.second) como vencedora.
O programa retorna 0 para indicar que a execução foi concluída com sucesso.

2 - Função cadastro_jogadores():

Essa função solicita que o usuário insira os nomes dos jogadores e armazena os nomes em um vetor de objetos Jogador.
Dentro de um loop, cria um objeto Jogador chamado j e chama o método get_nome() para obter o nome do jogador.
Em seguida, o jogador é adicionado ao vetor Jogadores usando o método push_back().
Quando o tamanho do vetor Jogadores atinge 5, o loop é encerrado.
Por fim, o vetor Jogadores é retornado.

3 - Função exibe_jogadores(const std::vector<Jogador> jogs):

Essa função exibe os nomes dos jogadores presentes no vetor jogs.
Usa um loop for para iterar sobre o vetor jogs.
Em cada iteração, exibe o nome do jogador usando jogs[i].nome_jogador.
A função também imprime uma linha separadora antes e depois da lista de jogadores.

4 - Função set_duplas(std::vector<Jogador> jogadoress):

Essa função recebe um vetor de objetos Jogador chamado jogadoress e forma duas duplas a partir dele.
Cria duas variáveis do tipo Dupla, d1 e d2.
Atribui os jogadores correspondentes às posições 1 e 2 do vetor jogadoress às variáveis d1.duplinha.first e d1.duplinha.second, respectivamente.
Atribui os jogadores correspondentes às posições 3 e 4 do vetor jogadoress às variáveis d2.duplinha.first e d2.duplinha.second, respectivamente.
Cria um par de objetos Dupla chamado duplas e atribui d1 à primeira dupla e d2 à segunda dupla.
Por fim, retorna o par de duplas.

4 - Função exibe_duplas(const std::pair<Dupla, Dupla> duplas):

Essa função exibe as informações das duas duplas recebidas como parâmetro.
Exibe a informação da primeira dupla, incluindo o nome do primeiro jogador e o nome do segundo jogador.
Em seguida, exibe uma linha separadora e imprime "VS" para indicar a separação entre as duplas.
Exibe a informação da segunda dupla, incluindo o nome do primeiro jogador e o nome do segundo jogador.
A função também imprime linhas separadoras antes e depois da exibição das duplas.

5 - Função começa_jogo(std::pair <Dupla,Dupla>& duplas_h):

A função comeca_jogo é um método da classe JOGO e é responsável por iniciar o jogo de truco entre as duas duplas. Ela recebe como parâmetro uma referência para um par de objetos Dupla chamado duplas_h.

Dentro da função, são criados objetos Pede_Truco e Comeca_Rodada para lidar com o pedido de truco e o início de uma nova rodada, respectivamente.

A pontuação das duplas é inicializada como zero, atribuindo 0 às variáveis duplas_h.first.pontuacao e duplas_h.second.pontuacao.

Em seguida, há um loop que continua enquanto a pontuação de qualquer uma das duplas (duplas_h.first.pontuacao ou duplas_h.second.pontuacao) for menor que 12. Esse loop controla a sequência de rodadas do jogo.

Dentro do loop, são redefinidos os valores das variáveis truquinho.condition e truquinho.condition_aceitas para false, para lidar com os pedidos de truco durante a rodada.

É chamado o método comeca_rodada do objeto rodada, passando como parâmetros as duplas (duplas_h) e o objeto truquinho.

Após o término do loop, é verificado se a pontuação da primeira dupla (duplas_h.first.pontuacao) é igual a 12 ou maior que 12. Se isso for verdadeiro, significa que a primeira dupla ganhou o jogo.

Nesse caso, a variável jogos_vencidos da primeira dupla é incrementada em 1, indicando que ela venceu mais um jogo. Em seguida, é exibida uma mensagem informando que a dupla 1 ganhou um jogo e recebeu 1 super ponto. As pontuações dos jogos vencidos pelas duas duplas são exibidas. Em seguida, a pontuação das duplas é redefinida para 0.

No caso em que a pontuação da segunda dupla (duplas_h.second.pontuacao) é igual a 12 ou maior que 12, é feito um processo semelhante ao descrito acima, mas agora a variável jogos_vencidos da segunda dupla é incrementada.

Essa função é responsável por controlar a sequência de rodadas do jogo de truco e determinar quando uma dupla vence um jogo.

6 - Função dar_cartas(Baralho& baralho):

A função dar_cartas é parte da classe Rodada. Ela é responsável por distribuir cartas de um baralho para os jogadores em uma rodada do jogo. A função não possui parâmetros.

Dentro da função, é criado um vetor vazio chamado mao para armazenar as cartas que serão distribuídas. Em seguida, um loop for é executado três vezes para distribuir três cartas.

A cada iteração do loop, a função pegar_cartas é chamada no objeto baralho para obter a próxima carta disponível. A carta é então adicionada ao vetor mao usando a função push_back.

Após o término do loop, o vetor mao contém as três cartas distribuídas. Esse vetor é retornado como resultado da função.

7 - Função distribui_cartas(std::pair<Dupla, Dupla>& duplas):

A função distribui_cartas é parte da classe Rodada. Ela é responsável por distribuir as cartas do baralho para os jogadores que fazem parte das duplas em uma rodada do jogo. A função recebe como parâmetro um par de objetos Dupla que contém os jogadores.

Dentro da função, são realizadas as seguintes etapas:

É criado um objeto Baralho chamado baralho.
É chamada a função inicializa_Baralho no objeto baralho, para preparar o baralho para distribuição.
É chamada a função embaralhar passando o objeto baralho, para embaralhar as cartas do baralho.
É criado um vetor vazio chamado mao para armazenar temporariamente as cartas distribuídas.
As cartas são distribuídas para os jogadores das duplas:
A função dar_cartas é chamada passando o objeto baralho, e o resultado (um vetor de cartas) é atribuído à mão do primeiro jogador da primeira dupla: duplas.first.duplinha.first.set_mao(dar_cartas(baralho)).
A função dar_cartas é chamada novamente passando o objeto baralho, e o resultado é atribuído à mão do segundo jogador da primeira dupla: duplas.first.duplinha.second.set_mao(dar_cartas(baralho)).
O mesmo processo é repetido para os jogadores da segunda dupla.
Após a execução da função, cada jogador da dupla possui suas cartas distribuídas, armazenadas em suas respectivas mãos.

8 - Função exibe_cartas(std::pair<Dupla, Dupla> duplas, unsigned j):

A função exibe_cartas pertence à classe Rodada. Ela é responsável por exibir as cartas dos jogadores das duplas em uma determinada rodada do jogo. A função recebe como parâmetros um par de objetos Dupla contendo os jogadores e um valor inteiro j que determina quantas cartas devem ser exibidas.

A função começa criando um vetor vazio chamado mao_jogador1 e um objeto Jogador chamado jogador. Em seguida, verifica se a mão do primeiro jogador da primeira dupla contém pelo menos uma carta. Se a condição for verdadeira, a função executa um padrão de exibição para cada jogador das duplas.

O padrão de exibição inclui um separador -------------------------, seguido pelo nome da dupla e o nome do jogador. Em seguida, um loop itera de 0 a j - 1, exibindo a representação em string de cada carta da mão do jogador usando a função toString(). Após a exibição das cartas do jogador, o separador é exibido novamente.

Essa função permite que as cartas dos jogadores das duplas sejam exibidas adequadamente, respeitando o número de cartas especificado por j e organizando-as por jogador e dupla.

9 - Função comeca_rodada(std::pair <Dupla, Dupla>& duplas_h, Pede_Truco truquinho):

A função comeca_rodada pertence à classe Comeca_Rodada. Ela é responsável por iniciar uma nova rodada do jogo, distribuir as cartas aos jogadores, realizar as sub-rodadas e determinar o vencedor da rodada.

A função começa criando objetos das classes Regras, Rodada e Vencedor para uso posterior. Em seguida, são declaradas algumas variáveis do tipo unsigned int para controlar pontos e índices relacionados à rodada.

A função também declara variáveis para armazenar informações sobre o vencedor de uma sub-rodada (jogador_vencedor_SR), informações sobre um empate em uma sub-rodada (Dupla_empate_SR) e informações de pontuação (pontuacao_SR). A pontuação é inicializada com 0 para ambas as duplas.

A função chama o método distribui_cartas da classe Rodada para distribuir as cartas às duplas. Em seguida, cria um objeto da classe Sub_Rodada e inicializa as pontuações da sub-rodada como 0.

Dentro de um loop while, a função exibe as cartas dos jogadores, usando o método exibe_cartas da classe Rodada, e obtém uma carta jogada por um jogador chamando o método joga_carta da classe Sub_Rodada. Dependendo da carta jogada, diferentes condições são avaliadas.

Se um truco for recusado por uma das duplas, a pontuação da outra dupla é definida como 10 e o loop é interrompido. Caso contrário, verifica-se se o truco foi aceito (truquinho.condition_aceitas), e se sim, o valor de ganho é definido como 4.

Em seguida, é verificado se houve um vencedor na sub-rodada usando o método vencedor_sub_rodada da classe Vencedor. Se houver um vencedor, o método verifica_vencedor_SR é chamado para obter informações sobre o vencedor e calcular a pontuação da sub-rodada.

Se houver um empate na sub-rodada, o método verifica_empate_SR é chamado para obter informações sobre a dupla empatada e calcular a pontuação da sub-rodada. Dependendo se os jogadores empatados pertencem à mesma dupla, uma mensagem diferente é exibida.

Após o cálculo da pontuação da sub-rodada, os valores são adicionados às pontuações totais das duplas e os índices e variáveis relacionadas são atualizadas. O loop continua enquanto a pontuação de uma das duplas for menor que 5 e o índice for maior que 0.

No final do loop, é verificado qual dupla ganhou a rodada com base na pontuação da sub-rodada. A pontuação ganha (ganho) é adicionada à pontuação da dupla vencedora e mensagens são exibidas para informar o resultado.

Se houver empate na sub-rodada, uma mensagem é exibida informando que a sub-rodada foi resetada e não haverá pontuação.

10 - Função joga_carta(std::pair<Dupla, Dupla>& duplas, unsigned i, Pede_Truco& truquinho):

A função joga_carta faz parte da classe Sub_Rodada. Essa função é responsável por permitir que os jogadores joguem suas cartas durante uma sub-rodada do jogo.

A função recebe como parâmetros uma referência para um par de objetos Dupla (representando as duas duplas de jogadores) e seus índices correspondentes (1, 2, 3 ou 4) para identificar qual jogador está jogando.

No início da função, algumas variáveis são declaradas, incluindo índices para as cartas escolhidas pelos jogadores (i1, i2, i3 e i4), variáveis para lidar com pedidos de truco (jogador_truco_SR, jogador_aceita_truco_SR e sub_rodada_truco) e um objeto da classe Rodada.

A função então verifica se há um pedido de truco em andamento (truquinho.condition) e, se não houver, solicita um pedido de truco para o jogador atual através do método pede_truco do objeto truquinho. O resultado desse pedido é armazenado em jogador_truco_SR e a condição do pedido é atualizada em truquinho.condition.

Em seguida, verifica-se se o pedido de truco foi aceito (truquinho.condition_aceitas) e se o jogador atual é um dos jogadores da dupla que recebeu o pedido. Se essas condições forem atendidas, o pedido de truco é aceito utilizando o método aceita_truco do objeto truquinho. O resultado desse aceite é armazenado em jogador_aceita_truco_SR e a condição de aceite é atualizada em truquinho.condition_aceitas. Se o aceite for falso, a função retorna uma mensagem informando que o truco foi recusado.

Depois disso, um loop while é iniciado para permitir que o jogador atual escolha uma carta para jogar. O jogador é solicitado a digitar um número entre 0 e i, que representa a posição da carta em sua mão. A entrada do jogador é validada e, se for inválida, uma mensagem de erro é exibida. Caso contrário, a carta escolhida é adicionada ao vetor sub_rodada_truco.first e removida da mão do jogador.

A sequência de comandos descrita acima é repetida para os outros jogadores, permitindo que cada um escolha uma carta para jogar.

Após todos os jogadores escolherem suas cartas, a função retorna o par sub_rodada_truco, contendo o vetor de cartas jogadas pelos jogadores (sub_rodada_truco.first) e uma string vazia ou com informações relacionadas ao truco (sub_rodada_truco.second).

11 - Enumeração Naipes:

A enumeração Naipes representa os diferentes naipes de um baralho de cartas. Os naipes disponíveis são:

COPAS: Representa o naipe de Copas.
OURO: Representa o naipe de Ouro.
ESPADA: Representa o naipe de Espada.
FOLHAS: Representa o naipe de Folhas.
Essa enumeração é útil para categorizar as cartas do baralho de acordo com o seu naipe.

12 - Enumeração Tipos_Cartas:

A enumeração Tipos_Cartas define os diferentes tipos de cartas presentes em um baralho. Os tipos de cartas incluem:

AS: Representa o Ás.
DOIS: Representa o Dois.
TRES: Representa o Três.
QUATRO: Representa o Quatro.
CINCO: Representa o Cinco.
SEIS: Representa o Seis.
SETE: Representa o Sete.
REI: Representa o Rei.
RAINHA: Representa a Rainha.
VALETE: Representa o Valete.
Essa enumeração permite identificar o valor e o tipo de cada carta do baralho, facilitando o uso e a manipulação das cartas durante um jogo de cartas.

13 - Struct Carta:

A struct Carta representa uma carta de um baralho, contendo informações sobre seu naipe, tipo e peso.

Atributos:

naipes: Uma variável do tipo Naipes que indica o naipe da carta.
tipos_cartas: Uma variável do tipo Tipos_Cartas que indica o tipo da carta.
peso: Um número inteiro que representa o peso da carta.
Métodos:

operator==: Sobrecarga do operador de igualdade (==) para comparar duas cartas. Retorna true se as cartas tiverem o mesmo naipe e tipo, caso contrário, retorna false.
toString(): Retorna uma string representando a carta no formato "NAIPE - TIPO". O naipe é convertido em texto de acordo com o valor da enumeração Naipes, e o tipo é convertido em texto de acordo com o valor da enumeração Tipos_Cartas.
A struct Carta é utilizada para representar e manipular cartas individuais em um jogo de cartas.

14 - Struct Baralho:

A struct Baralho representa um baralho de cartas, contendo um vetor de cartas e métodos para inicializar o baralho e pegar cartas.

Atributos:

cartas_baralho: Um vetor de objetos do tipo Carta que armazena as cartas do baralho.
Métodos:

inicializa_Baralho(): Inicializa o baralho, preenchendo o vetor cartas_baralho com as cartas do jogo. Cada carta é representada por um objeto do tipo Carta com o naipe, tipo e peso correspondentes.
pegar_cartas(): Remove a última carta do baralho (cartas_baralho) e retorna essa carta. A carta é removida do vetor, simulando o ato de pegar uma carta do baralho.
A struct Baralho é utilizada para criar e manipular um baralho de cartas em um jogo de cartas. O baralho pode ser inicializado com todas as cartas e as cartas podem ser retiradas sequencialmente através do método pegar_cartas().

15 - Class Dupla:

A classe Dupla representa uma dupla de jogadores em um jogo. Ela contém informações sobre a dupla, como os jogadores que a compõem, a pontuação da dupla e o número de jogos vencidos pela dupla.

Atributos:

duplinha: Um par (std::pair) de objetos do tipo Jogador que representa os dois jogadores da dupla.
pontuacao: Um valor inteiro não negativo que indica a pontuação da dupla.
jogos_vencidos: Um valor inteiro não negativo que representa o número de jogos vencidos pela dupla.
A classe Dupla é utilizada para gerenciar informações relacionadas a uma dupla de jogadores em um jogo. Ela pode armazenar os jogadores da dupla, acompanhar a pontuação da dupla ao longo do jogo e registrar o número de jogos vencidos pela dupla.

16 - Class Jogador:

A classe Jogador representa um jogador em um jogo. Ela contém informações sobre o jogador, como seu nome e sua mão de cartas.

Atributos:

nome_jogador: Uma string que armazena o nome do jogador.
mao: Um vetor de objetos do tipo Carta que representa a mão de cartas do jogador.
Métodos:

get_nome(): Retorna o nome do jogador.
set_mao(std::vector<Carta> cartas): Define a mão de cartas do jogador, recebendo um vetor de objetos do tipo Carta.
get_mao(): Retorna a mão de cartas do jogador.
Relacionamentos:

Sub_Rodada: A classe Jogador é amiga da classe Sub_Rodada, o que permite acesso aos membros privados da classe Jogador pela classe Sub_Rodada.
Rodada: A classe Jogador é amiga da classe Rodada, o que permite acesso aos membros privados da classe Jogador pela classe Rodada.
Vencedor: A classe Jogador é amiga da classe Vencedor, o que permite acesso aos membros privados da classe Jogador pela classe Vencedor.
A classe Jogador é utilizada para representar um jogador em um jogo. Ela armazena o nome do jogador e sua mão de cartas, além de fornecer métodos para acessar e definir essas informações. A amizade com outras classes permite o compartilhamento de informações e interações entre as classes relacionadas ao jogo.

17 - Class JOGO:

A classe JOGO representa o jogo em si. Ela é responsável por controlar o fluxo do jogo e realizar as ações necessárias para seu funcionamento.

Métodos:

comeca_jogo(std::pair<Dupla, Dupla>& duplas_h): Inicia o jogo com as duplas especificadas. Recebe como parâmetro um objeto std::pair contendo as duas duplas que participarão do jogo.

18 - Class Regras:

A classe Regras contém métodos relacionados às regras do jogo. Ela é responsável por determinar a maior carta entre um conjunto de cartas e exibir as regras do jogo.

Métodos:

maior_carta(std::vector<Carta>& cartas): Recebe um vetor de cartas como parâmetro e retorna a maior carta presente nesse vetor.
exibe_regra(): Exibe as regras do jogo.

A classe Regras é responsável por implementar as regras do jogo e fornecer funcionalidades relacionadas a essas regras. O método maior_carta recebe um vetor de cartas e determina a maior carta presente nesse vetor. O método exibe_regra é responsável por exibir as regras do jogo.

19 - Class Vencedor:

A classe Vencedor contém métodos relacionados à definição do vencedor de uma sub-rodada do jogo. Ela determina se houve um vencedor ou um empate na sub-rodada, calcula os pontos obtidos pelo vencedor ou empate, e verifica o vencedor da sub-rodada e as cartas jogadas.

Métodos:

vencedor_sub_rodada(std::vector<Carta>& mao_rodada): Recebe um vetor de cartas representando as cartas jogadas na sub-rodada e determina se houve um vencedor.
empate_sub_rodada(std::vector<Carta>& mao_rodada): Recebe um vetor de cartas representando as cartas jogadas na sub-rodada e determina se houve um empate.
pontos_sub_rodada_vencedor(std::pair<Dupla, Dupla>& duplas, std::vector<Carta>& cartas_jogadas, unsigned pt): Calcula os pontos obtidos pelo vencedor da sub-rodada com base nas cartas jogadas.
pontos_sub_rodada_empate(std::pair<Dupla, Dupla>& duplas, std::vector<Carta>& cartas_jogadas, unsigned pt): Calcula os pontos obtidos em caso de empate na sub-rodada com base nas cartas jogadas.
verifica_vencedor_SR(std::vector<Carta>& mao_rodada, std::pair<Dupla, Dupla>& duplas): Verifica o vencedor da sub-rodada com base nas cartas jogadas e retorna o jogador vencedor juntamente com as cartas jogadas.
verifica_empate_SR(std::vector<Carta>& mao_rodada, std::pair<Dupla, Dupla>& duplas): Verifica se houve um empate na sub-rodada com base nas cartas jogadas e retorna a dupla que empatou juntamente com as cartas jogadas.

20 - Class Pede_Truco:

A classe Pede_Truco representa a ação de pedir e aceitar um truco durante o jogo. Ela possui atributos para controlar as condições de pedir e aceitar truco, bem como métodos relacionados a essas ações.

Atributos:

condition: Uma variável booleana que indica se o truco foi pedido.
condition_aceitas: Uma variável booleana que indica se o truco foi aceito.
Métodos:

pede_truco(std::pair<Dupla, Dupla>& duplas, unsigned i): Método que permite que um jogador peça truco para a dupla adversária. Recebe como parâmetro a referência para o objeto std::pair<Dupla, Dupla> que representa as duplas do jogo e o índice i que indica o jogador que está pedindo truco. Retorna um std::pair contendo um valor booleano indicando se o truco foi pedido e uma string com uma mensagem informativa.
aceita_truco(std::pair<Dupla, Dupla>& duplas, unsigned i): Método que permite que um jogador aceite o truco. Recebe como parâmetro a referência para o objeto std::pair<Dupla, Dupla> que representa as duplas do jogo e o índice i que indica o jogador que está aceitando o truco. Retorna um std::pair contendo um valor booleano indicando se o truco foi aceito e uma string com uma mensagem informativa.
pt_truco(bool condicao): Método que retorna a pontuação correspondente ao truco, dependendo se o truco foi aceito (true) ou não (false). Recebe como parâmetro um valor booleano que indica se o truco foi aceito. Retorna um valor inteiro representando a pontuação correspondente ao truco.

21 - Class Rodada:

A classe Rodada representa uma rodada do jogo. Ela é responsável por distribuir cartas, exibir as cartas dos jogadores e realizar outras ações relacionadas à rodada.

Métodos:

dar_cartas(Baralho& baralho): Método que recebe um objeto Baralho por referência e retorna um vetor de cartas. Esse método permite dar as cartas para a rodada, obtendo-as do baralho.
distribui_cartas(std::pair<Dupla, Dupla>& duplas): Método que recebe um objeto std::pair<Dupla, Dupla> por referência, representando as duplas do jogo. Esse método distribui as cartas para os jogadores das duplas.
exibe_cartas(std::pair<Dupla, Dupla> duplas, unsigned j): Método que recebe um objeto std::pair<Dupla, Dupla> contendo as duplas do jogo e um valor inteiro j que representa o jogador. Esse método exibe as cartas do jogador j.

21 - Class Comeca_Rodada:

A classe Comeca_Rodada é responsável por iniciar uma rodada do jogo. Ela realiza as ações necessárias para começar uma nova rodada, como distribuir as cartas, gerenciar pedidos de truco e realizar as jogadas dos jogadores.

Métodos:

comeca_rodada(std::pair<Dupla, Dupla>& duplas_h, Pede_Truco truquinho): Método que inicia uma nova rodada do jogo. Recebe um objeto std::pair<Dupla, Dupla> por referência, representando as duplas do jogo, e um objeto Pede_Truco que gerencia os pedidos de truco. Esse método realiza as ações necessárias para começar a rodada, como distribuir as cartas, gerenciar os pedidos de truco e realizar as jogadas dos jogadores.

Relacionamentos:

A classe Comeca_Rodada possui um relacionamento de agregação com as classes Dupla e Pede_Truco, uma vez que recebe objetos dessas classes como parâmetros em seu método comeca_rodada.

22 - Class Sub_Rodada:

A classe Sub_Rodada representa uma subrodada do jogo, na qual os jogadores de cada dupla realizam suas jogadas e uma carta é jogada em cada turno. Essa classe é responsável por gerenciar as ações relacionadas a uma subrodada, como jogar cartas, verificar o vencedor e manter a pontuação da subrodada.

Métodos:

joga_carta(std::pair<Dupla, Dupla>& duplas, unsigned i, Pede_Truco& truquinho): Método que permite que um jogador de uma dupla jogue uma carta durante a subrodada. Recebe como parâmetros um objeto std::pair<Dupla, Dupla> por referência, representando as duplas do jogo, um valor unsigned i que indica o índice do jogador na dupla que está realizando a jogada, e um objeto Pede_Truco& truquinho que gerencia os pedidos de truco. Esse método retorna um objeto std::pair<std::vector<Carta>, std::string> contendo as cartas jogadas na subrodada até o momento e uma mensagem indicando o resultado da jogada.

Relacionamentos:

A classe Sub_Rodada possui relacionamentos de amizade com as classes JOGO, Vencedor e Comeca_Rodada, permitindo o acesso aos membros privados dessas classes.

-----------------------------------------------------------------------------------------------------