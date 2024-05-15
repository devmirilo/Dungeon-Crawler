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
//Voids
void tutorial();
void fase1();
void fase2();
void morte();
void sair();
//Menu Inicial
void menu() {
    char menu1;
    do {
        system("cls");
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
            system("color 4");
            fase2();
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
            if(mov == 't' && (mapa1[x][y] == mapa1[9][1])){
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
    
    int mov;
    int vida = 3;
    while(1){
        for(i = 0; i < 20; i++){
            for(j = 0; j < 20; j++){
                printf("%c ",mapa2[i][j]);
            }
            printf("\n");
        }
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
            xm = 9;
            ym = 8;
            getch();
            system("cls");
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
    exit(0);
}
int main() {
    menu();
}