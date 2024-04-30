#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void tutorial(){
	printf("Ola, Bravo Aventureiro, Hoje voce ira passar por um nova aventura. O jogo consiste em pegar a chave '@', e passar pelas portas 'D', caso a porta seja um '=', quer dizer que a porta esta aberta, podendo passar sem a chave!, a movimentacao consiste em usar 'w' 'a' 's' 'd', e pressione 'q' para sair ");
	getch();
	system("cls");
}
void jogar(){
	int i, j;
	system("cls");
		int x = 8, y = 8;
		char mapa1[10][10];
		for(i = 0; i < 10; i++){
			for(j = 0; j < 10; j++){
				if(i == 0 || i == 9){
					mapa1[i][j] = '*';
				}
				else if (j == 0 || j == 9){
					mapa1[i][j] = '*';
				}
				else if (i == 3 && (j > 0 && j < 4) || i == 3 && (j > 5 && i < 10)){
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
				else if (i > 0 && i < 9){
					mapa1[i][j] = ' ';
				}
			}
		}
		mapa1[1][3] = 'D';
		mapa1[2][1] = '@';
		mapa1[6][2] = 'D';
		mapa1[1][8] = '@';
		mapa1[3][7] = '=';
		mapa1[y][x] = '&';
		mapa1[9][1] = 'D';
		mapa1[8][2] = '@';
		while(1){
			for(i = 0; i < 10; i ++){
				for(j = 0; j < 10; j ++){
					printf("%c ", mapa1[i][j]);
				}
				printf("\n");
			}
			int ch = getch();
			
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
				system("cls");
				printf("Voce saiu.");
				getch();
				menu();
			}
			mapa1[x][y] = '&';
		}
	}
void sair(){
	printf("Voce saiu. Por favor volte novamente.");
	getch();
	return 0;
}
void menu(){
	int menu1;
	printf("1) Jogar\n2) Tutorial\n3) Sair\n");
	scanf("%d", &menu1);
	if(menu1 == 1){
		jogar();
	}
	else if(menu1 == 2){
		tutorial();
		menu();
	}
	else{
		return 0;
	}
}
int main(int argc, char *argv[]) {
	menu();
}
