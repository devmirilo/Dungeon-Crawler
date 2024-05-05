#include <stdio.h>
#include <stdlib.h>
#include <conio.h>


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
			//Movimentação do jogador
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
					else{
						x--;
						mapa1[x+1][y] = ' ';
					}
				}
				system("cls");
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
					else{
						x++;
						mapa1[x-1][y] = ' ';
					}
				}
				system("cls");	
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
					else{
						y--;
						mapa1[x][y+1] = ' ';
					}
				}
				system("cls");
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
					else{
						y++;
						mapa1[x][y-1] = ' ';	
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
			if (mapa1[x][y] == chave1){
    			chave1_obtida = 1;
    			mapa1[x][y] = ' '; // Remover a chave do mapa após o jogador pegá-la
			}
			else if (mapa1[x][y] == chave2){
   				chave2_obtida = 1;
    			mapa1[x][y] = ' '; // Remover a chave do mapa após o jogador pegá-la
			}
			else if (mapa1[x][y] == chave3){
    			chave3_obtida = 1;
    			mapa1[x][y] = ' '; // Remover a chave do mapa após o jogador pegá-la
			}
				mapa1[x][y] = '&';
		}
	}
int main() {
	menu();
	return 0;
}
