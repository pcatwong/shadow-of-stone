#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<windows.h>
#include<unistd.h>

char check_password[100];
char introl[90][100];
char loginsystem[50][100];
char login_acc_arr[50][100];
char register_acc_arr[50][100];
char wrong_message_ac_arr[50][100];
char wrong_message_ac2_arr[50][100];
char wrong_message_ac3_arr[50][100];
char login_pw_arr[50][100];
char register_pw_arr[50][100];
char wrong_message_pw_arr[50][100];
char wrong_message_pw1_arr[50][100];
char login_success_arr[50][100];
char register_success_arr[50][100];
char game_menu_arr[50][100];
char reg_name[100];
char reg_password[100];
char login_name[100];
char login_password[100];
char file_name[100];
char input;
int i,j;
int check_pw();
void login();
void login_account();
void login_pw();
void login_success();
void start();
void reg_account();
void reg_pw();
void reg_success();
void wrong_message_ac();
void wrong_message_ac2();
void wrong_message_ac3();
void wrong_message_pw();
void wrong_message_pw1();
void game_menu();


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
void login_success(){
	system("cls");
	FILE*log_success=fopen("login_success.txt","r");
	for(i=0;i<20;i++){
		fgets(login_success_arr[i], 70 ,log_success);
	}
	fclose(log_success);
	for(i=0;i<20;i++){
		int l=strlen(login_success_arr[i]);
		for(j=0;j<l;j++){
			printf("%c",login_success_arr[i][j]);
		}
	}
	gotoxy(34,2);
	printf("%s!",login_name);
	while(1){
		input=getch();
		if(input=='s'){
			game_menu();
		}
	}
}

void wrong_message_pw1(){
	system("cls");
	FILE*wrong_message=fopen("wrong_message_pw1.txt","r");
	for(i=0;i<20;i++){
		fgets(wrong_message_pw1_arr[i], 70 ,wrong_message);
	}
	fclose(wrong_message);
	for(i=0;i<20;i++){
		int l=strlen(wrong_message_pw1_arr[i]);
		for(j=0;j<l;j++){
			printf("%c",wrong_message_pw1_arr[i][j]);
		}
	}
	gotoxy(0,7);
	while(1){
		input=getch();
		if(input=='\r'){
			login_pw();
		}
	}
}
int check_pw(){
	FILE*log_password=fopen(file_name,"r");
	int flag=1;
	fscanf(log_password,"%s",&check_password);
	fclose(log_password);
	int l=strlen(check_password);
	for(i=0;i<l;i++){
		if(check_password[i]!=login_password[i]){
			flag=0;
			break;
		}
	}
	return flag;
}

void login_pw(){
	system("cls");
	memset(login_password,'\0',16);
	FILE *log_password;
	log_password=fopen("login_password.txt","r");
	for(i=0;i<20;i++){
		fgets(login_pw_arr[i] , 70 , log_password);
	}
	fclose(log_password);
	for(i=0;i<20;i++){
		int l=strlen(login_pw_arr[i]);
		for(j=0;j<l;j++){
			printf("%c",login_pw_arr[i][j]);
		}
	}
	int x=28,y=4;
	int count=0;
	gotoxy(x,y);
	while(1){
		input=getch();
		if(input!=' '){
			if(input=='\b'&&count>0){
				count--;
				if(count>0){
					gotoxy(x+count-1,y);
					putchar(login_password[count-1]);
				}
				gotoxy(x+count,y);
				login_password[count]='\0';
				putchar(' ');
				gotoxy(x+count,y);
			}
			else if(input=='\r'){
				if(check_pw()){
					login_success();
				}
				else{
					wrong_message_pw1();
				}
			}
			else if(count<16&&input!='\b'){
				if(count>0){
					gotoxy(x+count-1,y);
					putchar('*');
				}
				gotoxy(x+count,y);
				putchar(input);
				login_password[count]=input;
				count++;
				gotoxy(x+count,y);
			}
		}
	}
}

void wrong_message_ac3(){
	system("cls");
	FILE*wrong_message=fopen("wrong_message_ac3.txt","r");
	for(i=0;i<20;i++){
		fgets(wrong_message_ac3_arr[i], 70 ,wrong_message);
	}
	fclose(wrong_message);
	for(i=0;i<20;i++){
		int l=strlen(wrong_message_ac3_arr[i]);
		for(j=0;j<l;j++){
			printf("%c",wrong_message_ac3_arr[i][j]);
		}
	}
	gotoxy(0,7);
	while(1){
		input=getch();
		if(input=='\r'){
			login_account();
		}
	}
	
}

void login_account(){
	system("cls");
	memset(login_name,'\0',16);
	FILE*login_ac=fopen("login_account.txt","r");
	for(i=0;i<20;i++){
		fgets(login_acc_arr[i], 70 ,login_ac);
	}
	fclose(login_ac);
	for(i=0;i<20;i++){
		int l=strlen(login_acc_arr[i]);
		for(j=0;j<l;j++){
			printf("%c",login_acc_arr[i][j]);
		}
	}
	int x=28,y=4;
	int count=0;
	gotoxy(x,y);
	while(1){
		input=getch();
		input=tolower(input);
		if(input!=' '){
			if(input=='\b'&&count>0){
				count--;
				login_name[count]='\0';
				gotoxy(x+count,y);
				putchar(' ');
				gotoxy(x+count,y);
			}
			else if(input=='\r'){
				sprintf(file_name,"%s.txt",login_name);
				if(access(file_name,F_OK)==-1){
					wrong_message_ac3();	
				}
				else{
					login_pw();
				}
			}
			else if(count<16&&input!='\b'){
				putchar(input);
				login_name[count]=input;
				count++;
				gotoxy(x+count,y);
			}
		}
	}
}

void wrong_message_pw(){
	system("cls");
	FILE*wrong_message=fopen("wrong_message_pw.txt","r");
	for(i=0;i<20;i++){
		fgets(wrong_message_pw_arr[i], 70 ,wrong_message);
	}
	fclose(wrong_message);
	for(i=0;i<20;i++){
		int l=strlen(wrong_message_pw_arr[i]);
		for(j=0;j<l;j++){
			printf("%c",wrong_message_pw_arr[i][j]);
		}
	}
	gotoxy(0,6);
	while(1){
		input=getch();
		if(input=='\r'){
			reg_pw();
		}
	}
}

void wrong_message_ac2(){
	system("cls");
	FILE*wrong_message=fopen("wrong_message_ac2.txt","r");
	for(i=0;i<20;i++){
		fgets(wrong_message_ac2_arr[i], 70 ,wrong_message);
	}
	fclose(wrong_message);
	for(i=0;i<20;i++){
		int l=strlen(wrong_message_ac2_arr[i]);
		for(j=0;j<l;j++){
			printf("%c",wrong_message_ac2_arr[i][j]);
		}
	}
	gotoxy(0,6);
	while(1){
		input=getch();
		if(input=='\r'){
			reg_account();
		}
	}
}

void wrong_message_ac(){
	system("cls");
	FILE*wrong_message=fopen("wrong_message_ac.txt","r");
	for(i=0;i<20;i++){
		fgets(wrong_message_ac_arr[i], 70 ,wrong_message);
	}
	fclose(wrong_message);
	for(i=0;i<20;i++){
		int l=strlen(wrong_message_ac_arr[i]);
		for(j=0;j<l;j++){
			printf("%c",wrong_message_ac_arr[i][j]);
		}
	}
	gotoxy(0,6);
	while(1){
		input=getch();
		if(input=='\r'){
			reg_account();
		}
	}
}

void game_menu(){
	system("cls");
	FILE*menu=fopen("game_menu.txt","r");
	for(i=0;i<20;i++){
		fgets(game_menu_arr[i], 70 ,menu);
	}
	fclose(menu);
	for(i=0;i<20;i++){
		int l=strlen(game_menu_arr[i]);
		for(j=0;j<l;j++){
			printf("%c",game_menu_arr[i][j]);
		}
	}
}

void reg_success(){
	system("cls");
	FILE*register_success;
	register_success=fopen("register_success.txt","r");
	for(i=0;i<20;i++){
		fgets(register_success_arr[i], 70 ,register_success);
	}
	fclose(register_success);
	for(i=0;i<20;i++){
		int l=strlen(register_success_arr[i]);
		for(j=0;j<l;j++){
			printf("%c",register_success_arr[i][j]);
		}
	}
	FILE*fp=fopen(file_name,"w");
	fprintf(fp,"%s",reg_password);
	fclose(fp);
	gotoxy(0,6);
	while(1){
		input=getch();
		input=tolower(input);
		if(input=='s'){
			game_menu();
		}
	}
}

void start(){
	input=getch();
	if(input=='s'){
		system("cls");
		login();
	}
	else{
		start();
	}
}

void reg_account(){
	system("cls");
	memset(reg_name,'\0',16);
	FILE*register_acc;                                  // 16
	register_acc=fopen("register_account.txt","r");
	for(i=0;i<20;i++){
		fgets(register_acc_arr[i] , 70 , register_acc);
	}
	fclose(register_acc);
	for(i=0;i<20;i++){
		int l=strlen(register_acc_arr[i]);
		for(j=0;j<l;j++){
			printf("%c",register_acc_arr[i][j]);
		}
	}
	int x=28,y=4;
	int count=0;
	gotoxy(x,y);
	while(1){
		input=getch();
		input=tolower(input);
		if(input!=' '){
			if(input=='\b'&&count>0){
				count--;
				reg_name[count]='\0';
				gotoxy(x+count,y);
				putchar(' ');
				gotoxy(x+count,y);
			}
			else if(input=='\r'){
				sprintf(file_name,"%s.txt",reg_name);
				if(count<8){
					wrong_message_ac();
				}
				else if(access(file_name,F_OK)!=-1){
					wrong_message_ac2();
				}
				else{
					reg_pw();
				}
			}
			else if(count<16&&input!='\b'){
				putchar(input);
				reg_name[count]=input;
				count++;
				gotoxy(x+count,y);
			}
		}
	}  
}

void reg_pw(){
	system("cls");
	memset(reg_password,'\0',16);
	FILE *register_password;
	register_password=fopen("register_pw.txt","r");
	for(i=0;i<20;i++){
		fgets(register_pw_arr[i] , 70 , register_password);
	}
	fclose(register_password);
	for(i=0;i<20;i++){
		int l=strlen(register_pw_arr[i]);
		for(j=0;j<l;j++){
			printf("%c",register_pw_arr[i][j]);
		}
	}
	int x=28,y=4;
	int count=0;
	gotoxy(x,y);
	while(1){
		input=getch();
		if(input!=' '){
			if(input=='\b'&&count>0){
				count--;
				if(count>0){
					gotoxy(x+count-1,y);
					putchar(reg_password[count-1]);
				}
				gotoxy(x+count,y);
				reg_password[count]='\0';
				putchar(' ');
				gotoxy(x+count,y);
			}
			else if(input=='\r'){
				if(count<8){
					wrong_message_pw();
				}
				else{
					reg_success();
				}
			}
			else if(count<16&&input!='\b'){
				if(count>0){
					gotoxy(x+count-1,y);
					putchar('*');
				}
				gotoxy(x+count,y);
				putchar(input);
				reg_password[count]=input;
				count++;
				gotoxy(x+count,y);
			}
		}
	}
}

void login(){
	FILE *logins;
	logins=fopen("login.txt","r");
	for(i=0;i<20;i++){
		fgets(loginsystem[i] , 70 ,logins);
	}
	fclose(logins);
	for(i=0;i<20;i++){
		int l=strlen(loginsystem[i]);
		for(j=0;j<l;j++){
			printf("%c",loginsystem[i][j]);
		}
	}                                               
	int x=36;
	int y=3;
	gotoxy(x,y);
	putchar('<');
	while(1){
		gotoxy(x,y);
		putchar('<');
		input=getch();
		input=tolower(input);
		if(input=='s'&&y<5){
			gotoxy(x,y);
			putchar(' ');
			y++;
		}
		else if(input=='w'&&y>3){
			gotoxy(x,y);
			putchar(' ');
			y--;
		}
		else if(input=='\r'){
			gotoxy(0,10);
			break;
		}
	}
	if(y==5){
		exit(0);
	}
	else if(y==4){
		system("cls");
		reg_account();	
	}
	else if(y==3){
		system("cls");
		login_account();
	}
}

int main(){
	FILE *intro;
	intro=fopen("introl.txt","r");
	for(i=0;i<40;i++){
		fgets(introl[i] , 70 , intro);
	}
	fclose(intro);
	for(i=0;i<40;i++){
		int l=strlen(introl[i]);
		for(j=0;j<l;j++){
			printf("%c",introl[i][j]);
		}
	}
	gotoxy(0,23);
	start();
}
