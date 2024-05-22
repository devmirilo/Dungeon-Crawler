#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

#define VERMELHO     "\x1b[31m"
#define VERDE   "\x1b[32m"
#define AZUL    "\x1b[34m"
#define RESET   "\x1b[0m"
#define AMARELO "\x1b[33m"
#define PRETO "\x1b[30m"

// Variaveis para controlar se o jogador possui as chaves
int chave1_obtida = 0; // Inicialmente o jogador nao possui a chave 1
int chave2_obtida = 0; // Inicialmente o jogador nao possui a chave 2
int chave3_obtida = 0; // Inicialmente o jogador nao possui a chave 3
int botao_acionado = 0;
// Vida
int vida = 3;
//Voids
void tutorial();
void lore();
void vitoria();
void fase1();
void fase2();
void fase3();
void morte();
void sair();
//Menu Inicial
void menu() {
    char menu1;
    do {
        system("cls");
        system("color 07");
        printf("\n\n");
        printf("\t\t\t\t\t\t       > ###   ###  ####  ###  ##  ##  ## <\n");
        printf("\t\t\t\t\t\t       > #### ####  ##    #### ##  ##  ## <\n");
        printf("\t\t\t\t\t\t       > ## ### ##  ####  ## ####  ##  ## <\n");
        printf("\t\t\t\t\t\t       > ##     ##  ##    ##  ###  ##  ## <\n");
        printf("\t\t\t\t\t\t       > ##     ##  ####  ##   ##  ###### <\n");
        
        printf("\n\n");
        printf("\t\t\t\t\t\t         -----------------------------\n\n");
        printf(VERDE"\t\t\t\t\t\t\t         |===========|\n");
        printf(VERDE"\t\t\t\t\t\t\t         |   JOGAR   |\n");
        printf(VERDE"\t\t\t\t\t\t\t         |     1     |\n");
        printf(VERDE"\t\t\t\t\t\t\t         |===========|\n\n");
    
        printf(AZUL"\t\t\t\t\t\t\t         |===========|\n");
        printf(AZUL"\t\t\t\t\t\t\t         |  TUTORIAL |\n");
        printf(AZUL"\t\t\t\t\t\t\t         |     2     |\n");
        printf(AZUL"\t\t\t\t\t\t\t         |===========|\n\n");

        printf(VERMELHO"\t\t\t\t\t\t\t         |===========|\n");
        printf(VERMELHO"\t\t\t\t\t\t\t         |   SAIR    |\n");
        printf(VERMELHO"\t\t\t\t\t\t\t         |     3     |\n");
        printf(VERMELHO"\t\t\t\t\t\t\t         |===========|\n\n"RESET);

        printf("\t\t\t\t\t\t        ------------------------------\n");
        printf("\n\t\t\t\t\t\t\t==> ");
        scanf(" %c", &menu1);
        getchar();
        if (menu1 == '1') {
            lore();
            getch();
            system("color 4");
            fase1();
        } else if (menu1 == '2') {
            tutorial();
        } else if (menu1 == '3') {
            sair();
        } else {
            system("cls");
            printf("Opcao invalida. Tente novamente!\n");
            getch();
            system("cls");
        }
    } while (menu1 != '3');
}
// vitoria
void vitoria() {
    system("cls");
    system("color 07");
    printf("\n\n");
    printf(VERDE"\t\t\t\t\t\t       > #       #  ###  ########     ###     ######     ###       ###         <\n");
    printf("\t\t\t\t\t\t       > ##     ##          ###     ##   ##   ##   ##             ## ##        <\n");
    printf("\t\t\t\t\t\t       >  ##   ##   ###     ###    ##     ##  ######     ###     ##   ##       <\n");
    printf("\t\t\t\t\t\t       >   ## ##    ###     ###     ##   ##   ##   ##    ###    #########      <\n");
    printf("\t\t\t\t\t\t       >    ###     ###     ###       ###     ##    ##   ###   ##       ##     <\n"RESET);
    printf("\t\t\t\t\t\t                          Obrigado por jogar, novos jogos em breve!             ");
    getch();
    exit(0);
}
// historia
void lore(){
    system("cls");
    system("color 05");
    printf("\n\t\t\t\t\t\t   ---------------------------------------------------####-----------------------------------------------------------\n"
             "\t\t\t\t\t\t   | Era uma vez, ha muito tempo, na era medieval, um homem chamado Gaguinho. Gaguinho era apaixonado por uma moca   |\n"
             "\t\t\t\t\t\t   | chamada Fefe, mas ela tinha um pai muito bravo e com uma magia muito poderosa. Certo dia, Gaguinho decidiu pedir|\n"
             "\t\t\t\t\t\t   | a mao de Fefe em casamento, mas o pai dela surtou e mandou Gaguinho para outra dimensao. Nessa dimensao, ele    |\n"
             "\t\t\t\t\t\t   | teria que passar por tres niveis para se tornar apto a casar com a filha do mago.                               |\n"
             "\t\t\t\t\t\t   ---------------------------------------------------####-----------------------------------------------------------\n"
             "\t\t\t\t\t\t   | Essas fases nao eram faceis; havia de tudo, desde espinhos ate capangas do poderoso mago. O capanga mais        |\n"
             "\t\t\t\t\t\t   | poderoso era o Vetor 'V'. Sera que nosso Gaguinho conseguiu cumprir seu objetivo?                               |\n\n"
             "\t\t\t\t\t\t                                         PRESSIONE QUALQUER TECLA PARA CONTINUAR                                     |");
}
//Tela da Morte
void morte(){
    system("cls");
    printf("\n\n");
    printf(VERMELHO"\t\t\t\t\t\t       > ##   ##     ###     ######    ######    #######   ##   ##    <\n");
    printf(        "\t\t\t\t\t\t       > ### ###   ##   ##   ##   ##   ##   ##   ##        ##   ##    <\n");
    printf(        "\t\t\t\t\t\t       > #######  ##     ##  ######    ######    #######   ##   ##    <\n");
    printf(        "\t\t\t\t\t\t       > ##   ##   ##   ##   ##   ##   ##   ##   ##        ##   ##    <\n");
    printf(        "\t\t\t\t\t\t       > ##   ##     ###     ##    ##  ##    ##  #######   #######    <\n\n\n"RESET);
    printf(        "\t\t\t\t\t\t            Pressione qualquer tecla para voltar para o comeco!!");
    vida = 3;
    getch();
    return menu();
}
//Tutorial
void tutorial(){
    system("cls");
    printf(VERDE"\n\t\t\t\t\t\t   ---------------------------------------------------####----------------------------------------------------------\n"
                   "\t\t\t\t\t\t   |   O jogo eh do estilo aventura/puzzle onde o objetivo eh o passar de tres fases. Em cada fase o jogador deve  |\n"
                   "\t\t\t\t\t\t   |   se passar de tres fases. Em cada fase o jogador deve se movimentar para pegar uma chave para abrir a porta  |\n"
                   "\t\t\t\t\t\t   |    fechada.                                                                                                   |\n"
                   "\t\t\t\t\t\t   ---------------------------------------------------####----------------------------------------------------------\n"
                   "\t\t\t\t\t\t   |   O jogador possui os seguintes comandos:                                                                     |\n"
                   "\t\t\t\t\t\t   |   O: Simbolo que representa o botao(abre passagens secretas)                                                  |\n"
                   "\t\t\t\t\t\t   |   W: O jogador movimenta uma unidade para cima.                                                               |\n"
                   "\t\t\t\t\t\t   |   A: O jogador movimenta uma unidade para a esquerda.                                                         |\n"
                   "\t\t\t\t\t\t   |   S: O jogador movimenta uma unidade para baixo.                                                              |\n"
                   "\t\t\t\t\t\t   |   D: O jogador movimenta uma unidade para direita.                                                            |\n"
                   "\t\t\t\t\t\t   |   T: O jogador interage com o objeto que ele estiver em cima.                                                 |\n"
                   "\t\t\t\t\t\t   ---------------------------------------------------####----------------------------------------------------------\n"
                   "\t\t\t\t\t\t   |   @: Simbolo que representa o jogador.                                                                        |\n"
                   "\t\t\t\t\t\t   |   #: Simbolo que representa uma parede, o jogador nao pode passar pela parede.                                |\n"
                   "\t\t\t\t\t\t   |   &: Simbolo que representa a chave para abrir a porta para finalizar a fase,                                 |\n"
                   "\t\t\t\t\t\t   |   a porta abre no momento em que o jogador interage com a chave.                                              |\n"
                   "\t\t\t\t\t\t   |   D: Simbolo que representa uma porta fechada.                                                                |\n"
                   "\t\t\t\t\t\t   |   =: Simbolo que representa uma porta que foi aberta quando o jogador interagiu com a chave.                  |\n"
                   "\t\t\t\t\t\t   |   *: Simbolo que representa um espinho(tira uma vida).                                                        |\n"
                   "\t\t\t\t\t\t   |   >: simbolo que representa um teletransporte.O teletransporte sempre deve                                    |\n"
                   "\t\t\t\t\t\t   |   vir em par, quando o jogador toca em um ele e transportado para outro e vice-versa.                         |\n"
                   "\t\t\t\t\t\t   |   O guardiao do portal, jogue uma rodada e derrote o oponente para passar pelo portal vencer o jogo.          |\n"
                   "\t\t\t\t\t\t   ---------------------------------------------------####----------------------------------------------------------\n"
                   "\t\t\t\t\t\t   |     O JOGADOR APENAS UMA VIDA, SE ELE TOCAR EM QUALQUER OBJETO QUE DE DANO, ELE VOLTARA PARA O MENU PRINCIPAL.|\n"
                   "\t\t\t\t\t\t   --------------------------------------------------####----------------------------------------------------------\n"RESET);
    getch();
    system("cls");
}
void sair(){
    system("cls");
    printf("\n\n");
    printf(VERMELHO"\t\t\t\t\t\t       > ######    ###    ###  ######    <\n");
    printf("\t\t\t\t\t\t       > ##      ##   ##       ##   ##   <\n");
    printf("\t\t\t\t\t\t       > ######  #######  ###  ######    <\n");
    printf("\t\t\t\t\t\t       >     ##  ##   ##  ###  ##   ##   <\n");
    printf("\t\t\t\t\t\t       > ######  ##   ##  ###  ##    ##  <\n\n\n"RESET);
    printf("\t\t\t\t\t\t          Deseja sair do jogo? (S/N): ");
    char resposta;
    scanf(" %c", &resposta);
        if(resposta == 'S' || resposta == 's') {
            printf("Voce saiu do jogo.\n");
            system("cls");
            exit(0);
        }
        if(resposta == 'n' || resposta == 'N'){
            return menu();
        }
    exit(0);
    }
//Fase 1
void fase1(){
    int i, j;
    int chave1_obtida = 0;
    int chave2_obtida = 0;
    int chave3_obtida = 0;
    system("cls");
        //Criar o Mapa
        char mapa1[10][10];
        //Posicao inicial do jogador
        int x = 8, y = 8;
        for(i = 0; i < 10; i++){
            for(j = 0; j < 10; j++){
                //Paredes externas
                if(i == 0 || i == 9){
                    mapa1[i][j] = '*';
                }
                else if (j == 0 || j == 9){
                    mapa1[i][j] = '*';
                }
                //Parede interna
                else if ((i == 3 && (j > 0 && j < 4)) || (i == 3 && (j > 5 && i < 10))){
                    mapa1[i][j] = '*';
                }
                else if (i == 6 && (j > 0 && j < 4)){
                    mapa1[i][j] = '*';
                }
                else if(j == 3 && i < 4){
                    mapa1[i][j] = '*';
                }
                else if(j == 3 && i > 5){
                    mapa1[i][j] = '*';
                }
                else if(j == 6 && i < 4){
                    mapa1[i][j] = '*';
                }
                //Espacos Vazios
                else if (i > 0 && i < 9){
                    mapa1[i][j] = ' ';
                }
            }
        }
        //Posicao inicial do monstro
        //Colocar os elementos no mapa
        char chave1 = '@', chave2 = '@', chave3 = '@', porta1 = 'D', porta2 = 'D', porta3 = 'D';
        mapa1[1][3] = porta1;
        mapa1[1][8] = chave1;
        mapa1[6][2] = porta2;
        mapa1[2][1] = chave2;
        mapa1[3][7] = '=';
        mapa1[x][y] = '&';
        mapa1[9][1] = porta3;
        mapa1[8][2] = chave3;

        while(1){
            for(i = 0; i < 10; i ++){
                for(j = 0; j < 10; j ++){
                    printf("%c ", mapa1[i][j]);
                }
                printf("\n");
            }
            printf("\n Vidas: %d", vida);
            printf("\n\nPressione 'q' para sair.\n");
            int mov = getch();
            //Movimentacao do jogador
            if(mov == 'w'){
                if(mapa1[x-1][y] != '*'){
                    if(((mapa1[x-1][y] == porta1) && (chave1_obtida == 0)) ||
                       ((mapa1[x-1][y] == porta2) && (chave2_obtida == 0)) || 
                       ((mapa1[x-1][y] == porta3) && (chave3_obtida == 0))) {
                        printf("A porta esta trancada, ache a chave respectiva para ela");
                    }
                    else if (((mapa1[x-1][y] == porta1) && (chave1_obtida == 1)) ||
                             ((mapa1[x-1][y] == porta2) && (chave2_obtida == 1)) ||
                             ((mapa1[x-1][y] == porta3) && (chave3_obtida == 1))) {
                        x--;
                        mapa1[x+1][y] = ' ';
                    }
                    else if((mapa1[x][y] == mapa1[1][3]) || (mapa1[x][y] == mapa1[6][2]) ||(mapa1[x][y] == mapa1[9][1]) || (mapa1[x][y] == mapa1[3][7])){
                        x--;
                        mapa1[x+1][y] = '=';
                    }
                    else{
                        x--;
                        mapa1[x+1][y] = ' ';
                    }
                    if((((mapa1[x+1][y] == mapa1[1][8]) && chave1_obtida == 0) || ((mapa1[x+1][y] == mapa1[2][1]) && chave2_obtida == 0) || ((mapa1[x+1][y] == mapa1[8][2]) && chave3_obtida == 0)) ){
                        mapa1[x+1][y] = '@';
                    }
                }
            }
            else if(mov == 's'){
                if(mapa1[x+1][y] != '*'){
                    if (((mapa1[x+1][y] == porta1) && (chave1_obtida == 0)) || 
                        ((mapa1[x+1][y] == porta2) && (chave2_obtida == 0)) || 
                        ((mapa1[x+1][y] == porta3) && (chave3_obtida == 0))){
                        printf("A porta esta trancada, ache a chave respectiva para ela");
                    }
                    else if(((mapa1[x+1][y] == porta1) && (chave1_obtida == 1)) ||
                            ((mapa1[x+1][y] == porta2) && (chave2_obtida == 1)) || 
                            ((mapa1[x+1][y] == porta3) && (chave3_obtida == 1))){
                        x++;
                        mapa1[x-1][y] = ' ';
                    }
                    else if((mapa1[x][y] == mapa1[1][3]) || (mapa1[x][y] == mapa1[6][2]) ||(mapa1[x][y] == mapa1[9][1]) || (mapa1[x][y] == mapa1[3][7])){
                        x++;
                        mapa1[x-1][y] = '=';
                    }
                    else{
                        x++;
                        mapa1[x-1][y] = ' ';
                    }
                    if((((mapa1[x-1][y] == mapa1[1][8]) && chave1_obtida == 0) || ((mapa1[x-1][y] == mapa1[2][1]) && chave2_obtida == 0) || ((mapa1[x-1][y] == mapa1[8][2]) && chave3_obtida == 0)) ){
                        mapa1[x-1][y] = '@';
                    }
                }  
            }
            else if(mov == 'a'){
                if (mapa1[x][y-1] != '*'){
                    if (((mapa1[x][y-1] == porta1) && (chave1_obtida == 0)) || 
                        ((mapa1[x][y-1] == porta2) && (chave2_obtida == 0)) || 
                        ((mapa1[x][y-1] == porta3) && (chave3_obtida == 0))){
                        printf("A porta esta trancada, ache a chave respectiva para ela");
                    }
                    else if(((mapa1[x][y-1] == porta1) && (chave1_obtida == 1)) || 
                            ((mapa1[x][y-1] == porta2) && (chave2_obtida == 1)) || 
                            ((mapa1[x][y-1] == porta3) && (chave3_obtida == 1))){
                        y--;
                        mapa1[x][y+1] = ' ';
                    }
                    else if((mapa1[x][y] == mapa1[1][3]) || (mapa1[x][y] == mapa1[6][2]) ||(mapa1[x][y] == mapa1[9][1]) || (mapa1[x][y] == mapa1[3][7])){
                        y--;
                        mapa1[x][y+1] = '=';
                    }
                    else{
                        y--;
                        mapa1[x][y+1] = ' ';
                    }
                    if((((mapa1[x][y+1] == mapa1[1][8]) && chave1_obtida == 0) || ((mapa1[x][y+1] == mapa1[2][1]) && chave2_obtida == 0) || ((mapa1[x][y+1] == mapa1[8][2]) && chave3_obtida == 0)) ){
                        mapa1[x][y+1] = '@';
                    }
                }
            }  
            else if(mov == 'd'){
                if(mapa1[x][y+1] != '*'){
                    if (((mapa1[x][y+1] == porta1) && (chave1_obtida == 0)) || 
                        ((mapa1[x][y+1] == porta2) && (chave2_obtida == 0)) || 
                        ((mapa1[x][y+1] == porta3) && (chave3_obtida == 0))){
                        printf("A porta esta trancada, ache a chave respectiva para ela");
                    }
                    else if(((mapa1[x][y+1] == porta1) && (chave1_obtida == 1)) || 
                            ((mapa1[x][y+1] == porta2) && (chave2_obtida == 1)) || 
                            ((mapa1[x][y+1] == porta3) && (chave3_obtida == 1))){
                        y++;
                        mapa1[x][y-1] = ' ';
                    }
                    else if((mapa1[x][y] == mapa1[1][3]) || (mapa1[x][y] == mapa1[6][2]) ||(mapa1[x][y] == mapa1[9][1]) || (mapa1[x][y] == mapa1[3][7])){
                        y++;
                        mapa1[x][y-1] = '=';
                    }
                    else{
                        y++;
                        mapa1[x][y-1] = ' ';    
                    }
                    if((((mapa1[x][y-1] == mapa1[1][8]) && chave1_obtida == 0) || ((mapa1[x][y-1] == mapa1[2][1]) && chave2_obtida == 0) || ((mapa1[x][y-1] == mapa1[8][2]) && chave3_obtida == 0)) ){
                        mapa1[x][y-1] = '@';
                    }
                }
            }
            else if(mov == 'q'){
                printf("Deseja sair do jogo? (S/N): ");
                char resposta;
                scanf(" %c", &resposta);
                if(resposta == 'S' || resposta == 's') {
                    printf("Voce saiu do jogo.\n");
                    printf("Pressione qualquer tecla para voltar ao menu.\n");
                    getch();
                    system("cls");
                    return;
                }
                else{
                    system("cls");
                }
            }
            else if(mov == 't' && (x == 1 && y == 8)){
                mapa1[1][8] = ' ';
                mapa1[1][3] = '=';
                chave1_obtida = 1;
                system("cls");
            }
            else if(mov == 't' && (x == 2 && y == 1)){
                mapa1[2][1] = ' ';
                mapa1[6][2] = '=';
                chave2_obtida = 1;
                system("cls");
            }
            else if(mov == 't' && (x == 8 && y == 2)){
                mapa1[8][2] = ' ';
                mapa1[9][1] = '=';
                chave3_obtida = 1;
                system("cls");
            }
            if(mov == 's' && (mapa1[x][y] == mapa1[9][1])){
                system("cls");
                return fase2();
            }
            else{
                system("cls");
            }
            mapa1[x][y] = '&';
            system("cls");
        }
    }
//Fase 2
void fase2(){
    int i;
    int j;
    int chave1_obtida = 0;
    int chave2_obtida = 0;
    int chave3_obtida = 0;
    int botao_acionado = 0;
    char mapa2[20][20];
    system("cls");
    for(i = 0; i < 20; i++){
        for(j = 0; j < 20; j++){
            //Paredes externas
            if(i == 0 || i == 19){
                mapa2[i][j] = '*';
            }
            else if (j == 0 || j == 19){
                mapa2[i][j] = '*';
            }
            else if(i == 14 && (j > 11 && j < 19)){
                mapa2[i][j] = '*';
            } 
            else if(j == 12 && (i > 13 && i < 19)){
                mapa2[i][j] = '*';
            }
            else if(i == 4 && (j > 14 && j < 19)){
                mapa2[i][j] = '*';
            }
            else if(j == 15 && (i > 3 && i < 11)){
                mapa2[i][j] = '*';
            }
                else if(i == 11 && (j > 14 && j < 19)){
                mapa2[i][j] = '*';
            }
            else if (i > 0 && i < 19){
                mapa2[i][j] = ' ';
            }
        }
    }
    int x = 16, y = 2;
    int xm = 9, ym = 8;
    char chave2 = '@', chave3 = '@', porta1 = 'D', porta2 = 'D', porta3 = 'D', botao = 'O';

    mapa2[xm][ym] = 'X';
    mapa2[x][y] = '&';
    mapa2[9][17] = chave3;
    mapa2[16][16] = chave2;
    mapa2[7][15] = porta2;
    mapa2[7][19] = porta3;
    mapa2[16][12] = porta1;
    mapa2[2][2] = '#';
    mapa2[3][3] = '#';
    mapa2[3][4] = '#';
    mapa2[2][4] = '#';
    mapa2[2][5] = '#';
    mapa2[1][5] = '#';
    mapa2[8][18] = '#';
    mapa2[8][17] = '#';
    mapa2[7][17] = '#';
    mapa2[2][3] = botao;
    
    int movimento_contador = 0;
    int mov;
    while(1){
        for(i = 0; i < 20; i++){
            for(j = 0; j < 20; j++){
                printf("%c ",mapa2[i][j]);
            }
            printf("\n");
        }
        printf("\n Vidas: %d", vida);
        printf("\n\nPressione 'q' para sair.\n");
    // Monstro nivel 1
        srand(time(NULL));
        mapa2[xm][ym] = 'X';
        int o;
        o = rand()%4;
        if(o == 0){
            if(mapa2[xm - 1][ym] != '*' && mapa2[xm - 1][ym] != 'D' && mapa2[xm - 1][ym] != '=' && mapa2[xm - 1][ym] != '#' && mapa2[xm - 1][ym] != '@'){
                xm--;
                mapa2[xm + 1][ym] = ' ';
            }
        }
        else if(o == 1){
            if(mapa2[xm + 1][ym] != '*' && mapa2[xm + 1][ym] != 'D' && mapa2[xm + 1][ym] != '=' && mapa2[xm + 1][ym] != '#' && mapa2[xm + 1][ym] != '@'){
                xm++;
                mapa2[xm - 1][ym] = ' ';
            }
        }
        else if(o == 2){
            if(mapa2[xm][ym - 1] != '*' && mapa2[xm][ym - 1] != 'D' && mapa2[xm][ym - 1] != '=' && mapa2[xm][ym - 1] != '#' && mapa2[xm][ym - 1] != '@'){
                ym--;
                mapa2[xm][ym + 1] = ' ';
            }
        }
        else if(o == 3){
            if(mapa2[xm][ym + 1] != '*' && mapa2[xm][ym + 1] != 'D' && mapa2[xm][ym + 1] != '=' && mapa2[xm][ym + 1] != '#' && mapa2[xm][ym + 1] != '@'){
                ym++;
                mapa2[xm][ym - 1] = ' ';
            }
        }
        mov = getch();
        //Movimentacao do jogador
        if(mov == 'w'){
            if(mapa2[x-1][y] != '*' && mapa2[x-1][y] != 'D'){
                if(((mapa2[x-1][y] == porta1) && (chave1_obtida == 0)) ||
                   ((mapa2[x-1][y] == porta2) && (chave2_obtida == 0)) || 
                   ((mapa2[x-1][y] == porta3) && (chave3_obtida == 0))) {
                    printf("A porta esta trancada, ache a chave respectiva para ela");
                }
                else if (((mapa2[x-1][y] == porta1) && (chave1_obtida == 1)) ||
                         ((mapa2[x-1][y] == porta2) && (chave2_obtida == 1)) ||
                         ((mapa2[x-1][y] == porta3) && (chave3_obtida == 1))) {
                    x--;
                    mapa2[x+1][y] = ' ';
                }
                else if((mapa2[x][y] == mapa2[16][12]) || (mapa2[x][y] == mapa2[7][15]) ||(mapa2[x][y] == mapa2[7][19])){
                    x--;
                    mapa2[x+1][y] = '=';
                }
                else{
                    x--;
                    mapa2[x+1][y] = ' ';
                }
                if((((mapa2[x+1][y] == mapa2[8][5]) && chave1_obtida == 0) || ((mapa2[x+1][y] == mapa2[16][16]) && chave2_obtida == 0) || ((mapa2[x+1][y] == mapa2[9][17]) && chave3_obtida == 0)) && botao_acionado == 1){
                    mapa2[x+1][y] = '@';
                }
                if((mapa2[x+1][y] == mapa2[2][3]) && botao_acionado == 0){
                    mapa2[x+1][y] = 'O';
                }
                if((mapa2[x+1][y] == mapa2[8][5]) && botao_acionado == 0){
                    mapa2[x+1][y] = ' ';
                }
                movimento_contador ++;
            }
        }
        else if(mov == 's'){
            if(mapa2[x+1][y] != '*' && mapa2[x+1][y] != 'D'){
                if (((mapa2[x+1][y] == porta1) && (chave1_obtida == 0)) || 
                    ((mapa2[x+1][y] == porta2) && (chave2_obtida == 0)) || 
                    ((mapa2[x+1][y] == porta3) && (chave3_obtida == 0))){
                    printf("A porta esta trancada, ache a chave respectiva para ela");
                }
                else if(((mapa2[x+1][y] == porta1) && (chave1_obtida == 1)) ||
                        ((mapa2[x+1][y] == porta2) && (chave2_obtida == 1)) || 
                        ((mapa2[x+1][y] == porta3) && (chave3_obtida == 1))){
                    x++;
                    mapa2[x-1][y] = ' ';
                }
                else if((mapa2[x][y] == mapa2[16][12]) || (mapa2[x][y] == mapa2[7][15]) ||(mapa2[x][y] == mapa2[7][19])){
                    x++;
                    mapa2[x-1][y] = '=';
                }
                else{
                    x++;
                    mapa2[x-1][y] = ' ';
                }
                if((((mapa2[x-1][y] == mapa2[8][5]) && chave1_obtida == 0) || ((mapa2[x-1][y] == mapa2[16][16]) && chave2_obtida == 0) || ((mapa2[x-1][y] == mapa2[9][17]) && chave3_obtida == 0)) && botao_acionado == 1){
                    mapa2[x-1][y] = '@';
                }
                if((mapa2[x-1][y] == mapa2[2][3]) && botao_acionado == 0){
                    mapa2[x-1][y] = 'O';
                }
                if((mapa2[x-1][y] == mapa2[8][5]) && botao_acionado == 0){
                    mapa2[x-1][y] = ' ';
                }
                movimento_contador ++;
            }  
        }
        else if(mov == 'a'){
            if (mapa2[x][y-1] != '*' && mapa2[x][y-1] != 'D'){
                if (((mapa2[x][y-1] == porta1) && (chave1_obtida == 0)) || 
                    ((mapa2[x][y-1] == porta2) && (chave2_obtida == 0)) || 
                    ((mapa2[x][y-1] == porta3) && (chave3_obtida == 0))){
                    printf("A porta esta trancada, ache a chave respectiva para ela");
                }
                else if(((mapa2[x][y-1] == porta1) && (chave1_obtida == 1)) || 
                        ((mapa2[x][y-1] == porta2) && (chave2_obtida == 1)) || 
                        ((mapa2[x][y-1] == porta3) && (chave3_obtida == 1))){
                    y--;
                    mapa2[x][y+1] = ' ';
                }
                else if((mapa2[x][y] == mapa2[16][12]) || (mapa2[x][y] == mapa2[7][15]) ||(mapa2[x][y] == mapa2[7][19])){
                    y--;
                    mapa2[x][y+1] = '=';
                }
                else{
                    y--;
                    mapa2[x][y+1] = ' ';
                }
                if((((mapa2[x][y+1] == mapa2[8][5]) && chave1_obtida == 0) || ((mapa2[x][y+1] == mapa2[16][16]) && chave2_obtida == 0) || ((mapa2[x][y+1] == mapa2[9][17]) && chave3_obtida == 0)) && botao_acionado == 1){
                    mapa2[x][y+1] = '@';
                }
                if((mapa2[x][y+1] == mapa2[2][3]) && botao_acionado == 0){
                    mapa2[x][y+1] = 'O';
                }
                if((mapa2[x][y+1] == mapa2[8][5]) && botao_acionado == 0){
                    mapa2[x][y+1] = ' ';
                }
                movimento_contador ++;
            }
        }  
        else if(mov == 'd'){
            if(mapa2[x][y+1] != '*' && mapa2[x][y+1] != 'D'){
                if (((mapa2[x][y+1] == porta1) && (chave1_obtida == 0)) || 
                    ((mapa2[x][y+1] == porta2) && (chave2_obtida == 0)) || 
                    ((mapa2[x][y+1] == porta3) && (chave3_obtida == 0))){
                    printf("A porta esta trancada, ache a chave respectiva para ela");
                }
                else if(((mapa2[x][y+1] == porta1) && (chave1_obtida == 1)) || 
                        ((mapa2[x][y+1] == porta2) && (chave2_obtida == 1)) || 
                        ((mapa2[x][y+1] == porta3) && (chave3_obtida == 1))){
                    y++;
                    mapa2[x][y-1] = ' ';
                }
                else if((mapa2[x][y] == mapa2[16][12]) || (mapa2[x][y] == mapa2[7][15]) ||(mapa2[x][y] == mapa2[7][19])){
                    y++;
                    mapa2[x][y-1] = '=';
                }
                else{
                    y++;
                    mapa2[x][y-1] = ' ';    
                }
                if((((mapa2[x][y-1] == mapa2[8][5]) && chave1_obtida == 0) || ((mapa2[x][y-1] == mapa2[16][16]) && chave2_obtida == 0) || ((mapa2[x][y-1] == mapa2[9][17]) && chave3_obtida == 0)) && botao_acionado == 1){
                    mapa2[x][y-1] = '@';
                }
                if((mapa2[x][y-1] == mapa2[2][3]) && botao_acionado == 0){
                    mapa2[x][y-1] = 'O';
                }
                if((mapa2[x][y-1] == mapa2[8][5]) && botao_acionado == 0){
                    mapa2[x][y-1] = ' ';
                }
                movimento_contador ++;
            }
        }
        else if(mov == 'q'){
            printf("Deseja sair do jogo? (S/N): ");
            char resposta;
            scanf(" %c", &resposta);
            if(resposta == 'S' || resposta == 's') {
                printf("Voce saiu do jogo.\n");
                printf("Pressione qualquer tecla para voltar ao menu.\n");
                getch();
                system("cls");
                return;
            }
            else{
                system("cls");
            }
        }
        else if(mov == 't' && (x == 2 && y == 3)){
            mapa2[2][3] = ' ';
            mapa2[8][5] = '@';
            botao_acionado = 1;
        }
        else if(mov =='t' && (x == 8 && y == 5)){
            mapa2[8][5] = ' ';
            mapa2[16][12] = '=';
            chave1_obtida = 1;
        }
        else if(mov =='t' && (x == 16 && y == 16 )){
            mapa2[16][16] = ' ';
            mapa2[7][15] = '=';
            chave2_obtida = 1;
        }
        else if(mov =='t' && (x == 9 && y == 17)){
            mapa2[9][17] = ' ';
            mapa2[7][19] = '=';
            chave3_obtida = 1;
        }
        if (mapa2[x][y] == '#'){
            printf("\t\t\t\t\t\tVoce sofreu dano!\n");
            getch();
            vida --;
            x = 16;
            y = 2;
            botao_acionado = 0;
            mapa2[2][3] = 'O';
            chave1_obtida = 0;
            mapa2[16][12] = 'D';
            mapa2[8][5] = ' ';
            chave2_obtida = 0;
            mapa2[7][15] = 'D';
            mapa2[16][16] = '@';
            chave3_obtida = 0;
            mapa2[9][17] = '@';
            mapa2[7][19] = 'D';
            mapa2[xm][ym] = ' ';
            xm = 9;
            ym = 8;
            system("cls");
        }
        if (x == xm && y == ym){
            printf("\t\t\t\t\t\tVoce sofreu dano!\n");
            vida --;
            x = 16;
            y = 2;
            botao_acionado = 0;
            mapa2[2][3] = 'O';
            chave1_obtida = 0;
            mapa2[16][12] = 'D';
            mapa2[8][5] = ' ';
            chave2_obtida = 0;
            mapa2[7][15] = 'D';
            mapa2[16][16] = '@';
            chave3_obtida = 0;
            mapa2[9][17] = '@';
            mapa2[7][19] = 'D';
            mapa2[xm][ym] = ' ';
            xm = 9;
            ym = 8;
            getch();
            system("cls");
        }
        if(mov == 'd' && (mapa2[x][y] == mapa2[7][19])){
            system("cls");
            return fase3();
        }
        if (vida == 0){
            morte();
        }
        mapa2[x][y] = '&';
        mapa2[xm][ym] = 'X';
        system("cls");
    }
    for(i = 0; i < 20; i++){
        for(j = 0; j < 20; j++){
            printf("%c ",mapa2[i][j]);
        }
        printf("\n");
    }
    getch();
    system("cls");
}
void fase3(){
    int i, j;
    int chave1_obtida = 0;
    int chave2_obtida = 0;
    int botao_acionado = 0;
    char mapa3[40][40];
    
    system("cls");
    for(i = 0;i < 40;i++){
    	for(j = 0;j < 40;j++){
    		if(i == 0 || i == 39){
    			mapa3[i][j] ='*';
			}
			else if(j == 0 || j == 39){
				mapa3[i][j] = '*';	
			}
			else if(j == 13 && (i > 13 && i < 29)){
				mapa3[i][j] = '*'; 
			}
			else if(i == 1 && (j > 12 && j < 25)){
				mapa3[i][j] = '#';
			}
			else if(j == 12 &&(i > 0 && i < 6)){
				mapa3[i][j] = '#';
			}
			else if(i == 6 &&(j > 11 && j < 22)){
				mapa3[i][j] = '#';
			}
			else if(i == 4 &&(j > 14 && j < 24)){
				mapa3[i][j] = '#';
			}
			else if(i - j == -20 &&(j > 23 && j < 35)){
				mapa3[i][j] = '#';
			}
			else if(i == 13 &&(j > 32 && j < 39)){
				mapa3[i][j] = '#';
			}
			else if(i - j == -16 &&(j > 21 && j < 30)){
				mapa3[i][j] = '#';
			}
			else if(i - j == -24 &&(j > 24 && j < 31)){
				mapa3[i][j] = '#';
			}
			else if(i == 10 && (j > 34 && j <39)){
				mapa3[i][j] ='#';
			}
			else if (j == 29 &&(i > 13 && i < 17)){
				mapa3[i][j] ='#';
			}
			else if(i == 7 &&(j > 30 && j < 35)){
				mapa3[i][j] = '#';
			}
			else if(j == 35 &&(i > 6 && i < 11)){
				mapa3[i][j] = '#';
			}
			else if(i == 13 && (j > 5 && j < 14)){
				mapa3[i][j] = '*';
			}
			else if(j == 5 && (i > 12 && i < 19)){
				mapa3[i][j] = '*';
			}
			else if(i == 12 &&(j > 16 && j < 22)){
				mapa3[i][j] = '*';
			}
			else if(j == 16 && ( i > 11 && i < 15)){
				mapa3[i][j] = '*';	
			}
			else if(i == 37 && (j > 0 && j < 5)){
				mapa3[i][j] = '*';	
			}
			else if(j - i == 9 &&(i > 11 && i < 19)){
				mapa3[i][j] = '*';
			}
			else if(j == 22 &&(i > 20 && i < 25)){
				mapa3[i][j] = '*';
			}
			else if(i == 23 &&(j > 26 && j < 31)){
				mapa3[i][j] = '*';
			}
			else if(i == 25 &&(j > 21 && j < 31)){
				mapa3[i][j] = '*';	
			}
			else if(j == 27 &&(i > 17 && i < 23)){
				mapa3[i][j] = '*';
			}
			else if(i - j == -2 &&(j > 16 && j < 23)){
				mapa3[i][j] = '*';
			}
			else if(i + j == 41 && (i > 28 && i < 37)){
				mapa3[i][j] = '*';
			}
			else if(i + j == 36 && ( i > 24 && i < 36)){
				mapa3[i][j] = '*';
			}
			else if(i - j == 13 && (i > 18 && i < 25)){
				mapa3[i][j] = '*';
			}
			else if(i == 23 &&(j > 21 && j < 29)){
				mapa3[i][j] = '*';
			}
			else if (j > 0 && j < 39){
                mapa3[i][j] = ' ';
            }
        	else if(i > 0 && i < 39 ){
				mapa3[i][j] = ' '; 
			}
    		
    	}
    }
    botao_acionado = 0;
    chave1_obtida = 0;
    chave2_obtida = 0;
    int x = 36;
    int y = 2;
    int xm = 18;
    int ym = 11;
    int xm2 = 18;
    int ym2 = 38;
    char chave1 = '@', chave2 = '@', porta1 = 'D', porta2 = 'D';
    mapa3[23][25] = porta1;
    mapa3[12][39] = porta2;
    mapa3[x][y] = '&';
    mapa3[xm][ym] = 'X';
    mapa3[xm2][ym2] = 'V';
    mapa3[14][8] = '#';
    mapa3[15][8] = '#';
    mapa3[16][8] = '#';
    mapa3[16][7] = '#';
    mapa3[15][10] = 'O';
    mapa3[18][23] = chave1;
    mapa3[17][20] = '#';
    mapa3[17][21] = '#';
    mapa3[16][21] = '#';
    mapa3[15][20] = '#';
    mapa3[24][30] = '*';
    mapa3[15][33] = chave2;
    mapa3[15][34] = '#';
    mapa3[16][34] = '#';
    
    int movimento_contador = 0;
    int mov;
    while(1){
        for(i = 0; i < 40; i++){
            for(j = 0; j < 40; j++){
                printf("%c ",mapa3[i][j]);
            }
            printf("\n");
        }
        printf("\n Vidas: %d", vida);
        printf("\n\nPressione 'q' para sair.\n");
        // Monstro nivel 1
        srand(time(NULL));
        mapa3[xm][ym] = 'X';
        int o;
        o = rand()%4;
        if(o == 0){
            if(mapa3[xm - 1][ym] != '*' && mapa3[xm - 1][ym] != 'D' && mapa3[xm - 1][ym] != '=' && mapa3[xm - 1][ym] != '#' && mapa3[xm - 1][ym] != '@' && mapa3[xm - 1][ym] != 'O'){
                xm--;
                mapa3[xm + 1][ym] = ' ';
            }
        }
        else if(o == 1){
            if(mapa3[xm + 1][ym] != '*' && mapa3[xm + 1][ym] != 'D' && mapa3[xm + 1][ym] != '=' && mapa3[xm + 1][ym] != '#' && mapa3[xm + 1][ym] != '@' && mapa3[xm + 1][ym] != 'O'){
                xm++;
                mapa3[xm - 1][ym] = ' ';
            }
        }
        else if(o == 2){
            if(mapa3[xm][ym - 1] != '*' && mapa3[xm][ym - 1] != 'D' && mapa3[xm][ym - 1] != '=' && mapa3[xm][ym - 1] != '#' && mapa3[xm][ym - 1] != '@' && mapa3[xm][ym - 1] != 'O'){
                ym--;
                mapa3[xm][ym + 1] = ' ';
            }
        }
        else if(o == 3){
            if(mapa3[xm][ym + 1] != '*' && mapa3[xm][ym + 1] != 'D' && mapa3[xm][ym + 1] != '=' && mapa3[xm][ym + 1] != '#' && mapa3[xm][ym + 1] != '@' && mapa3[xm][ym + 1] != 'O'){
                ym++;
                mapa3[xm][ym - 1] = ' ';
            }
        }
        // Monstro nivel 2
        mapa3[xm2][ym2] = 'V';
        if (movimento_contador == 2){
            int dif_x = x - xm2;
            int dif_y = y - ym2;
            if (abs(dif_x) > abs(dif_y)){
                if (dif_x > 0){
                    if(mapa3[xm2 + 1][ym2] != '*'){
                        xm2 ++;
                        mapa3[xm2 - 1][ym2] = ' ';
                    }
                }
                else if (dif_x < 0){
                    if(mapa3[xm2 - 1][ym2] != '*'){
                        xm2 --;
                        mapa3[xm2 + 1][ym2] = ' ';
                    }
                }
            }
            else{
                if (dif_y > 0){
                    if(mapa3[xm2][ym2 + 1] != '*'){
                        ym2 ++;
                        mapa3[xm2][ym2 - 1] = ' ';
                    }
                }
                else if (dif_y < 0){
                    if(mapa3[xm2][ym2 - 1] != '*'){
                        ym2 --;
                        mapa3[xm2][ym2 + 1] = ' ';
                    }
                }
            }
            movimento_contador = 0;
        }
        mov = getch();
        //Movimentacao do jogador
        if(mov == 'w'){
            if(mapa3[x-1][y] != '*' && mapa3[x-1][y] != 'D'){
                if(((mapa3[x-1][y] == porta1) && (chave1_obtida == 0)) ||
                   ((mapa3[x-1][y] == porta2) && (chave2_obtida == 0))) {
                    printf("A porta esta trancada, ache a chave respectiva para ela");
                }
                else if (((mapa3[x-1][y] == porta1) && (chave1_obtida == 1)) ||
                         ((mapa3[x-1][y] == porta2) && (chave2_obtida == 1))) {
                    x--;
                    mapa3[x+1][y] = ' ';
                }
                else if((mapa3[x][y] == mapa3[23][25]) || (mapa3[x][y] == mapa3[12][39])){
                    x--;
                    mapa3[x+1][y] = '=';
                }
                else{
                    x--;
                    mapa3[x+1][y] = ' ';
                }
                if((mapa3[x+1][y] == mapa3[15][10]) && botao_acionado == 0){
                    mapa3[x+1][y] = 'O';
                }
                movimento_contador ++;
            }
        }
        else if(mov == 's'){
            if(mapa3[x+1][y] != '*' && mapa3[x+1][y] != 'D'){
                if (((mapa3[x+1][y] == porta1) && (chave1_obtida == 0)) || 
                    ((mapa3[x+1][y] == porta2) && (chave2_obtida == 0))){
                    printf("A porta esta trancada, ache a chave respectiva para ela");
                }
                else if(((mapa3[x+1][y] == porta1) && (chave1_obtida == 1)) ||
                        ((mapa3[x+1][y] == porta2) && (chave2_obtida == 1))){
                    x++;
                    mapa3[x-1][y] = ' ';
                }
                else if((mapa3[x][y] == mapa3[23][25]) || (mapa3[x][y] == mapa3[12][39])){
                    x++;
                    mapa3[x-1][y] = '=';
                }
                else{
                    x++;
                    mapa3[x-1][y] = ' ';
                }
                if((mapa3[x-1][y] == mapa3[15][10]) && botao_acionado == 0){
                    mapa3[x-1][y] = 'O';
                }
                movimento_contador ++;
            }  
        }
        else if(mov == 'a'){
            if (mapa3[x][y-1] != '*' && mapa3[x][y-1] != 'D'){
                if (((mapa3[x][y-1] == porta1) && (chave1_obtida == 0)) || 
                    ((mapa3[x][y-1] == porta2) && (chave2_obtida == 0))){
                    printf("A porta esta trancada, ache a chave respectiva para ela");
                }
                else if(((mapa3[x][y-1] == porta1) && (chave1_obtida == 1)) || 
                        ((mapa3[x][y-1] == porta2) && (chave2_obtida == 1))){
                    y--;
                    mapa3[x][y+1] = ' ';
                }
                else if((mapa3[x][y] == mapa3[23][25]) || (mapa3[x][y] == mapa3[12][39])){
                    y--;
                    mapa3[x][y+1] = '=';
                }
                else{
                    y--;
                    mapa3[x][y+1] = ' ';
                }
                if((mapa3[x][y+1] == mapa3[15][10]) && botao_acionado == 0){
                    mapa3[x][y+1] = 'O';
                }
                movimento_contador ++;
            }
        }  
        else if(mov == 'd'){
            if(mapa3[x][y+1] != '*' && mapa3[x][y+1] != 'D'){
                if (((mapa3[x][y+1] == porta1) && (chave1_obtida == 0)) || 
                    ((mapa3[x][y+1] == porta2) && (chave2_obtida == 0))){
                    printf("A porta esta trancada, ache a chave respectiva para ela");
                }
                else if(((mapa3[x][y+1] == porta1) && (chave1_obtida == 1)) || 
                        ((mapa3[x][y+1] == porta2) && (chave2_obtida == 1))){
                    y++;
                    mapa3[x][y-1] = ' ';
                }
                else if((mapa3[x][y] == mapa3[23][25]) || (mapa3[x][y] == mapa3[12][39])){
                    y++;
                    mapa3[x][y-1] = '=';
                }
                else{
                    y++;
                    mapa3[x][y-1] = ' ';    
                }
                if((mapa3[x][y-1] == mapa3[15][10]) && botao_acionado == 0){
                    mapa3[x][y-1] = 'O';
                }
                movimento_contador ++;
            }
        }
        else if(mov == 'q'){
            printf("Deseja sair do jogo? (S/N): ");
            char resposta;
            scanf(" %c", &resposta);
            if(resposta == 'S' || resposta == 's') {
                printf("Voce saiu do jogo.\n");
                printf("Pressione qualquer tecla para voltar ao menu.\n");
                getch();
                system("cls");
                return;
            }
            else{
                system("cls");
            }
        } 
        else if(mov == 't' && (x == 15 && y == 10)){
            mapa3[15][10] = ' ';
            mapa3[15][7] = '>';
            mapa3[16][20] = '<';
            mapa3[24][29] = '>';
            mapa3[16][30] = '<';
            botao_acionado = 1;
        }
        else if(mov =='t' && (x == 18 && y == 23)){
            mapa3[18][23] = ' ';
            mapa3[23][25] = '=';
            chave1_obtida = 1;
        }
        else if(mov == 't' && (x == 15 && y == 33)){
            mapa3[15][33] = ' ';
            mapa3[12][39] = '=';
            chave2_obtida = 1;
        }
        else if(mov == 't' && (x == 15 && y == 7)){
            mapa3[x][y] = ' ';
            x = 16;
            y = 20;
            mapa3[15][7] = '>';
        }
        else if(mov == 't' && (x == 16 && y == 20)){
            mapa3[x][y] = ' ';
            x = 15;
            y = 7;
            mapa3[16][20] = '<';
        }
        else if(mov == 't' && (x == 24 && y == 29)){
            mapa3[x][y] = ' ';
            x = 16;
            y = 30;
            mapa3[24][29] = '>';
        }
        else if(mov == 't' && (x == 16 && y == 30)){
            mapa3[x][y] = ' ';
            x = 24;
            y = 29;
            mapa3[16][30] = '<';
        }
        if (mapa3[x][y] == '#'){
            printf("\t\t\t\t\t\tVoce sofreu dano!\n");
            getch();
            vida --;
            x = 36;
            y = 2;
            botao_acionado = 0;
            mapa3[15][10] = 'O';
            chave1_obtida = 0;
            mapa3[23][25] = 'D';
            mapa3[18][23] = '@';
            chave2_obtida = 0;
            mapa3[12][39] = 'D';
            mapa3[15][33] = '@';
            mapa3[xm][ym] = ' ';
            mapa3[xm2][ym2] = ' ';
            mapa3[15][7] = ' ';
            mapa3[16][20] = ' ';
            mapa3[24][29] = ' ';
            mapa3[16][30] = ' ';
            xm = 18;
            ym = 11;
            xm2 = 18;
            ym2 = 38;
            system("cls");
        }
        if (x == xm && y == ym){
            printf("\t\t\t\t\t\tVoce sofreu dano!\n");
            getch();
            vida --;
            x = 36;
            y = 2;
            botao_acionado = 0;
            mapa3[15][10] = 'O';
            chave1_obtida = 0;
            mapa3[23][25] = 'D';
            mapa3[18][23] = '@';
            chave2_obtida = 0;
            mapa3[12][39] = 'D';
            mapa3[15][33] = '@';
            mapa3[xm][ym] = ' ';
            mapa3[xm2][ym2] = ' ';
            mapa3[15][7] = ' ';
            mapa3[16][20] = ' ';
            mapa3[24][29] = ' ';
            mapa3[16][30] = ' ';
            xm = 18;
            ym = 11;
            xm2 = 18;
            ym2 = 38;
            system("cls");
        }
        if (x == xm2 && y == ym2){
            printf("\t\t\t\t\t\tVoce sofreu dano!\n");
            getch();
            vida --;
            x = 36;
            y = 2;
            botao_acionado = 0;
            mapa3[15][10] = 'O';
            chave1_obtida = 0;
            mapa3[23][25] = 'D';
            mapa3[18][23] = '@';
            chave2_obtida = 0;
            mapa3[12][39] = 'D';
            mapa3[15][33] = '@';
            mapa3[xm][ym] = ' ';
            mapa3[xm2][ym2] = ' ';
            mapa3[15][7] = ' ';
            mapa3[16][20] = ' ';
            mapa3[24][29] = ' ';
            mapa3[16][30] = ' ';
            xm = 18;
            ym = 11;
            xm2 = 18;
            ym2 = 38;
            system("cls");
        }
        if(mov == 'd' && (mapa3[x][y] == mapa3[12][39])){
            system("cls");
            return vitoria();
        }
        if (vida == 0){
            morte();
        }
        mapa3[x][y] = '&';
        mapa3[xm][ym] = 'X';
        mapa3[xm2][ym2] = 'V';
        system("cls");
    }
    for(i = 0; i < 40; i++){
    	for(j = 0;j < 40;j++){
    		printf("%c ", mapa3[i][j]);
		}
		printf("\n");
	}
	getch();
	system("cls");
}
int main() {
    menu();
}