## Dungeon Crawler
DUNGEON CRAWLER - Jogo avaliativo pedido em C para o curso de ciência da computação do 1°Semestre • Cesupa
# Professor
Pedro Henrique Sales Girotto
# Introdução
Um jogo de aventura é um gênero de videogame no qual o jogador assume o papel de protagonista em uma história interativa impulsionada pela exploração e/ou resolução de quebra-cabeças (Rollings & Adams 2003, p. 43). O foco do gênero na história permite que ele se baseie fortemente em outras mídias, literatura e filmes. Muitos jogos de aventura (texto e gráfico) são projetados para um único jogador, já que essa ênfase na história e no personagem dificulta o design multijogador (Hitchens 2002, p. 258). Colossal Cave Adventure é identificado ("The Colossal Cave Adventure page". rickadams.org. Retrieved 31 July 2020.) como o primeiro jogo de aventura, lançado pela primeira vez em 1976, enquanto outras séries de jogos de aventura notáveis incluem Zork, King's Quest, The Secret of Monkey Island e Myst.
# Sobre o jogo
JOGO:\n
O jogo é do estilo aventura/puzzle onde o objetivo é o jogador conseguir passar de três fases. Em cada fase o jogador deve se movimentar para pegar uma chave para abrir a porta fechada.\n
O jogador possui os seguintes comando:
W: O jogador movimenta uma unidade para cima;
A: O jogador movimenta uma unidade para esquerda;
S: O jogador movimenta uma unidade para baixo;
D: O jogador movimenta uma unidade para direita;
I: O jogador interage com o objeto que está em cima.
O jogo possui os seguintes elementos nas fases:
&: Símbolo que representa o jogador.
*: Símbolo que representa uma parede, o jogador ao se movimentar não pode passar pela parede.
@: Simbolo que representa a chave para abrir a porta para finalizar a fase, a porta abre no momento que o jogador interage com a chave.
D: Símbolo que representa a porta fechada.
=: Simbolo que representa a porta aberta quando o jogador interage com a chave.
O: Símbolo que representa um botão que o usuário pode interagir, o botão fica no chão e o jogador deve ficar em cima dele para poder interagir.
'#': Símbolo que representa um espinho. A fase é reiniciada quando o jogador toca no espinho, caso a fase seja reiniciada três vezes, o jogo volta para o menu principal.
'>': Símbolo que representa um teletransporte. O teletransporte sempre deve vir em pares, quando o jogador toca em um ele é transportado para o outro e vice-versa.
X: Símbolo que representa o monstro nível 1. Esse monstro tem um movimento aleatório para cima, para esquerda, para baixo e para direita. Caso o monstro toque no jogador, a fase é reiniciada.
V: Símbolo que representa o monstro nível 2. Esse monstro tem uma inteligência para seguir o jogador (há várias maneiras de implementar isso). Caso o monstro toque no jogador, a fase é reiniciada.
        O jogo possui um total de 8 telas:
Menu Principal: Menu com com três escolhas para o usuário (Jogar, Tutorial, Sair);
Tutorial: Texto ensinando o jogador a jogar o jogo;
Sair: Texto de despedida e encerramento do programa;
Fase 1: A Fase 1 é inicializada quando o jogador seleciona a opção Jogar no Menu Principal;
Fase 2: A Fase 2 é inicializada quando o jogador termina a Fase 1;
Fase 3: A Fase 3 é inicializada quando o jogador termina a Fase 2;
Vitória: Texto elogiando o jogador por ter conseguido terminar o jogo, depois dessa tela o jogador volta para o Menu Principal. Essa tela só pode ser acessada se o jogador finalizar a Fase 3;
Derrota: Texto caçoando o jogador, depois dessa tela o jogador volta para o Menu Principal. Essa tela só pode ser acessada quando o jogador perde em uma fase.
