#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<windows.h>

char introl[90][100];
char check;

void gotoxy(int x, int y){
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

/*void color(int ForgC){
     WORD wColor;
     HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
     CONSOLE_SCREEN_BUFFER_INFO csbi;
     if(GetConsoleScreenBufferInfo(hStdOut, &csbi)){
          wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
          SetConsoleTextAttribute(hStdOut, wColor);
     }
     return;
}*/

void start(){
	check=getch();
	if(check=='s'){
		system("cls");
	}
	else{
		start();
	}
}

int main(){
	int i,j;
	FILE *test;
	test=fopen("introl.txt","r");
	for(i=0;i<40;i++){
		fgets(introl[i] , 70 , test);
	}
	fclose(test);
	for(i=0;i<40;i++){
		int l=strlen(introl[i]);
		for(j=0;j<l;j++){
			printf("%c",introl[i][j]);
		}
	}
	gotoxy(0,23);
	start();
}
