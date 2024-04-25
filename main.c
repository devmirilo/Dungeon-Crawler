#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int menu1;
	int i, j, k;
	int vida = 3;
	printf("1) Jogar\n2) Tutorial\n3) Sair\n");
	scanf("%d", &menu1);
	if(menu1 == 1){
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
		mapa1[6][2] = '=';
		mapa1[1][8] = '@';
		mapa1[3][7] = '=';
		mapa1[y][x] = '&';
		while(1){
			for(i = 0; i < 10; i ++){
				for(j = 0; j < 10; j ++){
					printf("%c ", mapa1[i][j]);
				}
				printf("\n");
			}
			int ch = getch();
			
			if(ch == 'w'){
				if(x > 1) x--;
				mapa1[x+1][y] = ' ';
				system("cls");
			}
			else if(ch == 's'){
				if(x < 8) x++;
				mapa1[x-1][y] = ' ';
				system("cls");	
			}
			else if(ch == 'a'){
				if (y > 1) y--;
				mapa1[x][y+1] = ' ';
				system("cls");
			}
			else if(ch == 'd'){
				if(y < 8) y++;
				mapa1[x][y-1] = ' ';
				system("cls");
			}
			else if(ch == 'q'){
				break;
			}
			mapa1[x][y] = '&';
		}
	}
	else if(menu1 == 2){
		printf("oi");
	}
	else if(menu1 == 3){
		system("cls");
		printf("Voce saiu, Volte depois.");
		return 0;
	}
	return 0;
}
