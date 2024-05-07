#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

// Variáveis para controlar se o jogador possui as chaves
int chave1_obtida = 0; // Inicialmente o jogador não possui a chave 1
int chave2_obtida = 0; // Inicialmente o jogador não possui a chave 2
int chave3_obtida = 0; // Inicialmente o jogador não possui a chave 3
// Variáveis para controlar se as portas estão trancadas
int porta1_trancada = 1; // Porta 1 inicialmente trancada
int porta2_trancada = 1; // Porta 2 inicialmente trancada
int porta3_trancada = 1; // Porta 3 inicialmente trancada
//Voids
void tutorial();
void jogar();

//Menu Inicial
void menu(){
	int menu1;
	do{
		system("color c");
		printf("1) Jogar\n2) Tutorial\n3) Sair\n");
		scanf("%d", &menu1);
		if(menu1 == 1){
			jogar();
		}
		else if(menu1 == 2){
			tutorial();
		}
		else if(menu1 == 3){
			printf("Voce saiu. Por favor volte novamente outra hora.\n");
			exit(0);
		}
		else{
			printf("Opcao invalida. Tente novamente!\n");
		}
	}while(menu1 != 3);
}
//Tutorial
void tutorial(){
	system("color a");
	system("cls");
	printf("\n\t\t   ---------------------------------------------------####----------------------------------------------------------\n"
                   "\t\t   |   O jogo eh do estilo aventura/puzzle onde o objetivo eh o passar de tres fases. Em cada fase o jogador deve  |\n"
                   "\t\t   |   se passar de tres fases. Em cada fase o jogador deve se movimentar para pegar uma chave para abrir a porta  |\n"
                   "\t\t   |    fechada.                                                                                                   |\n"
                   "\t\t   ---------------------------------------------------####----------------------------------------------------------\n"
                   "\t\t   |   O jogador possui os seguintes comandos:                                                                     |\n"
                   "\t\t   |   O: Simbolo que representa o botao(abre passagens secretas)                                                  |\n"
                   "\t\t   |   W: O jogador movimenta uma unidade para cima.                                                               |\n"
                   "\t\t   |   A: O jogador movimenta uma unidade para a esquerda.                                                         |\n"
                   "\t\t   |   S: O jogador movimenta uma unidade para baixo.                                                              |\n"
                   "\t\t   |   D: O jogador movimenta uma unidade para direita.                                                            |\n"
                   "\t\t   |   I: O jogador interage com o objeto que ele estiver em cima.                                                 |\n"
                   "\t\t   ---------------------------------------------------####----------------------------------------------------------\n"
                   "\t\t   |   @: Simbolo que representa o jogador.                                                                        |\n"
                   "\t\t   |   #: Simbolo que representa uma parede, o jogador nao pode passar pela parede.                                |\n"
                   "\t\t   |   &: Simbolo que representa a chave para abrir a porta para finalizar a fase,                                 |\n"
                   "\t\t   |   a porta abre no momento em que o jogador interage com a chave.                                              |\n"
                   "\t\t   |   D: Simbolo que representa uma porta fechada.                                                                |\n"
                   "\t\t   |   =: Simbolo que representa uma porta que foi aberta quando o jogador interagiu com a chave.                  |\n"
                   "\t\t   |   *: Simbolo que representa um espinho(tira uma vida).                                                        |\n"
                   "\t\t   |   >: simbolo que representa um teletransporte.O teletransporte sempre deve                                    |\n"
                   "\t\t   |   vir em par, quando o jogador toca em um ele e transportado para outro e vice-versa.                         |\n"
                   "\t\t   |   O guardiao do portal, jogue uma rodada e derrote o oponente para passar pelo portal vencer o jogo.          |\n"
                   "\t\t   ---------------------------------------------------####----------------------------------------------------------\n"
                   "\t\t   |     O JOGADOR POSSUI UM TOTAL DE 3 VIDAS, SE PERDER TODAS AS VIDAS O JOGO VOLTA PARA O MENU INICIAL.          |\n"
                   "\t\t   --------------------------------------------------####----------------------------------------------------------\n");
	getch();
	system("cls");
	system("color c");
}
//Jogo
void jogar(){
	int i, j;
	system("cls");
		//Criar o Mapa
		char mapa1[10][10];
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
		
		
		//Posição inicial do jogador
		int x = 8, y = 8;
		//Posição inicial do monstro
		int xm = 5, ym = 4;
		//Colocar os elementos no mapa
		char chave1 = '@', chave2 = '@', chave3 = '@', porta1 = 'D', porta2 = 'D', porta3 = 'D';
		char monstro = 'X';
		mapa1[xm][ym] = monstro;
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
			// Monstro nivel 1
			srand(time(NULL));
			mapa1[xm][ym] = monstro;
			int o;
			o = rand()%4;
			if(o == 0){
				if(mapa1[xm - 1][ym] != '*' && mapa1[xm - 1][ym] != 'D' && mapa1[xm - 1][ym] != '=' & mapa1[xm - 1][ym] != 'h'){
					xm--;
					mapa1[xm + 1][ym] = ' ';
				}
			}
			if(o == 1){
				if(mapa1[xm + 1][ym] != '*' && mapa1[xm + 1][ym] != 'D' && mapa1[xm + 1][ym] != '=' && mapa1[xm + 1][ym] != 'h'){
					xm++;
					mapa1[xm - 1][ym] = ' ';
				}
			}
			if(o == 2){
				if(mapa1[xm][ym - 1] != '*' && mapa1[xm][ym - 1] != 'D' && mapa1[xm][ym - 1] != '=' && mapa1[xm][ym - 1] != 'h'){
					ym--;
					mapa1[xm][ym + 1] = ' ';
				}
			}
			if(o == 3){
				if(mapa1[xm][ym + 1] != '*' && mapa1[xm][ym + 1] != 'D' && mapa1[xm][ym + 1] != '=' && mapa1[xm][ym + 1] != 'h'){
					ym++;
					mapa1[xm][ym - 1] = ' ';
				}
			}
			printf("\n\nPressione 'q' para sair.\n");
			int vida = 3;
			int mov = getch();
			//Movimentação do jogador
			if(mov == 'w'){
				if(mapa1[x-1][y] != '*'){
					if(mapa1[x][y] == mapa1[xm][ym]){
						vida--;
					}
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
					else{
						x--;
						mapa1[x+1][y] = ' ';
					}
					if((((mapa1[x+1][y] == mapa1[1][8]) && chave1_obtida == 0) || ((mapa1[x+1][y] == mapa1[2][1]) && chave2_obtida == 0) || ((mapa1[x+1][y] == mapa1[8][2]) && chave3_obtida == 0)) ){
						mapa1[x+1][y] = '@';
					}
				}
				system("cls");
			}
			else if(mov == 's'){
				if(mapa1[x+1][y] != '*'){
					if(mapa1[x][y] == mapa1[xm][ym]){
						vida--;
					}
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
					else{
						x++;
						mapa1[x-1][y] = ' ';
					}
					if((((mapa1[x-1][y] == mapa1[1][8]) && chave1_obtida == 0) || ((mapa1[x-1][y] == mapa1[2][1]) && chave2_obtida == 0) || ((mapa1[x-1][y] == mapa1[8][2]) && chave3_obtida == 0)) ){
						mapa1[x-1][y] = '@';
					}
				}
				system("cls");	
			}
			else if(mov == 'a'){
				if(mapa1[x][y] == mapa1[xm][ym]){
						vida--;
					}
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
					else{
						y--;
						mapa1[x][y+1] = ' ';
					}
					if((((mapa1[x][y+1] == mapa1[1][8]) && chave1_obtida == 0) || ((mapa1[x][y+1] == mapa1[2][1]) && chave2_obtida == 0) || ((mapa1[x][y+1] == mapa1[8][2]) && chave3_obtida == 0)) ){
						mapa1[x][y+1] = '@';
					}
				}
				system("cls");
			}  
			else if(mov == 'd'){
				if(mapa1[x][y] == mapa1[xm][ym]){
						vida--;
					}
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
					else{
						y++;
						mapa1[x][y-1] = ' ';	
					}
					if((((mapa1[x][y-1] == mapa1[1][8]) && chave1_obtida == 0) || ((mapa1[x][y-1] == mapa1[2][1]) && chave2_obtida == 0) || ((mapa1[x][y-1] == mapa1[8][2]) && chave3_obtida == 0)) ){
						mapa1[x][y-1] = '@';
					}
				}
				system("cls");
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
			}
			else if(mov == 't' && (x == 1 && y == 8)){
				mapa1[1][8] = " ";
				mapa1[1][3] = "=";
				chave1_obtida = 1;
				system("cls");
			}
			else if(mov == 't' && (x == 2 && y == 1)){
				mapa1[2][1] = " ";
				mapa1[6][2] = "=";
				chave2_obtida = 1;
				system("cls");
			}
			else if(mov == 't' && (x == 8 && y == 2)){
				mapa1[8][2] = " ";
				mapa1[9][1] = "=";
				chave3_obtida = 1;
				system("cls");
			}
			else if (vida == 0){
				printf("Voce morreu.");
				return;
			}
				mapa1[x][y] = '&';
				mapa1[xm][ym] = monstro;
		}
	}
int main() {
	menu();
	return 0;
}