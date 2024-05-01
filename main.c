#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

//Voids
void tutorial();
void jogar();
void sair();

//Menu Inicial
void menu(){
	int menu1;
	do{
		printf("1) Jogar\n2) Tutorial\n3) Sair\n");
		scanf("%d", &menu1);
		if(menu1 == 1){
			jogar();
		}
		else if(menu1 == 2){
			tutorial();
		}
		else if(menu1 == 3){
			sair();
			return;
		}
		else{
			printf("Opcao invalida. Tente novamente!\n");
		}
	}while(menu1 != 3);
}
//Tutorial
void tutorial(){
	printf("Ola, Bravo Aventureiro, Hoje voce ira passar por um nova aventura, que consiste em 3 fases.\nO jogo consiste em pegar a chave '@', e passar pelas portas 'D' e '=', caso a porta seja um '=', quer dizer que a porta esta aberta. A movimentacao consiste em usar 'w' 'a' 's' 'd' e pressionar 'q' para sair.\n");
	printf("Pressione qualquer tecla para voltar ao menu.\n");
	getch();
	system("cls");
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
		//Colocar os elementos no mapa
		char chave1, chave2, chave3, porta1, porta2, porta3;
		mapa1[1][3] = 'D';
		mapa1[2][1] = '@';
		mapa1[6][2] = 'D';
		mapa1[1][8] = '@';
		mapa1[3][7] = '=';
		mapa1[y][x] = '&';
		mapa1[9][1] = 'D';
		mapa1[8][2] = '@';
		chave1 = mapa1[1][8];
		chave2 = mapa1[2][1];
		chave3 = mapa1[8][2];
		porta1 = mapa1[1][3];
		porta2 = mapa1[6][2];
		porta3 = mapa1[9][1];
		while(1){
			for(i = 0; i < 10; i ++){
				for(j = 0; j < 10; j ++){
					printf("%c ", mapa1[i][j]);
				}
				printf("\n");
			}
			printf("\n\nPressione 'q' para sair.\n");
			int ch = getch();
			//Movimentação do jogador
			if(ch == 'w'){
				if(mapa1[x-1][y] != '*'){
				 x--;
				mapa1[x+1][y] = ' ';	
				}
				system("cls");
			}
			else if(ch == 's'){
				if(mapa1[x+1][y] != '*'){
				x++;
				mapa1[x-1][y] = ' ';
				}
				system("cls");	
			}
			else if(ch == 'a'){
				if (mapa1[x][y-1] != '*'){
				y--;
				mapa1[x][y+1] = ' ';
				}
				system("cls");
			}
			else if(ch == 'd'){
				if(mapa1[x][y+1] != '*'){
				y++;
				mapa1[x][y-1] = ' ';
				}
				system("cls");
			}
			else if(ch == 'q'){
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
				mapa1[x][y] = '&';
		}
	}
void sair(){
	printf("Voce saiu. Por favor volte novamente outra hora.\n");
	exit(0);
}
int main() {
	menu();
	return 0;
}
