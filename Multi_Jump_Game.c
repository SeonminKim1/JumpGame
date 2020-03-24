#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <Windows.h>
#define size_y 25   // �� ũ�� (��)
#define size_x 25   // �� ũ�� (��)
#define my_x1 3     // ù��°���� x
#define my_y1 6*1-1 // ù��°���� y
#define my_x2 3     // �ι�°���� x
#define my_y2 6*2-1 // �ι�°���� y 
#define my_x3 3     // ����°���� x
#define my_y3 6*3-1 // ����°���� y
#define my_x4 3     // �׹�°���� x
#define my_y4 6*4-1 // �׹�°���� y
#define ESC 0x1b
int map[size_x][size_y];

enum COLOR
{
	BLACK, BLUE1, GREEN1, CYAN1, RED1, MAGENTA1, YELLOW1, GRAY1, GRAY2, BLUE2, GREEN2, CYAN2, RED2, MAGENTA2, YELLOW2, WHITE
}COLOR;
void gotoxy(int x, int y) { //���� ���ϴ� ��ġ�� Ŀ�� �̵�
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
void textcolor(int color, int bgcolor)
{
	color &= 0xf;
	bgcolor &= 0xf;
	bgcolor &= 0xf;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (bgcolor << 4) | color);
}
void delay() {
	Sleep(100);
}
void cls() {
	system("cls"); 
}
void cls2(int bg_color, int text_color)
{
	char cmd[100];
	system("cls");
	sprintf(cmd, "COLOR %x%x", bg_color, text_color);
	system(cmd);

}
void removecursor() { // Ŀ���� �Ⱥ��̰� �Ѵ�
	CONSOLE_CURSOR_INFO curInfo;
	GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
	curInfo.bVisible = 0;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
}
void scoreprint(int score) {
	gotoxy(54, 14);
	textcolor(YELLOW2, BLACK);
	printf("  Score = %d", score);
}
void Levelcount(int level) {
	gotoxy(54, 11);
	textcolor(RED2, BLACK);
	printf(" S T A G E  %d ", level);
}
// ����
void keyprint(int aa) {
	gotoxy(12, 27);
	if (aa == 1){textcolor(MAGENTA2, BLACK);printf(" 1���� : 'A' ");textcolor(YELLOW2,BLACK); printf(" 2���� : 'D' "); textcolor(CYAN2,BLACK); printf(" 3���� : 'J' "); textcolor(GREEN2,BLACK); printf(" 4���� : 'l' ");}
	if (aa == 2){textcolor(MAGENTA2, BLACK);printf(" 1���� : 'D' ");textcolor(YELLOW2,BLACK); printf(" 2���� : 'J' "); textcolor(CYAN2,BLACK); printf(" 3���� : 'L' "); textcolor(GREEN2,BLACK); printf(" 4���� : 'A' ");}
	if (aa == 3){textcolor(MAGENTA2, BLACK);printf(" 1���� : 'J' ");textcolor(YELLOW2,BLACK); printf(" 2���� : 'L' "); textcolor(CYAN2,BLACK); printf(" 3���� : 'A' "); textcolor(GREEN2,BLACK); printf(" 4���� : 'D' ");}
}
void firstscreen() {
	cls(); gotoxy(0, 0); textcolor(RED2, BLACK);
	printf("                                                                          \n");//1
	printf("                                                                          \n");//2
	printf("                                                                          \n");//3
	printf("                                                                          \n");//4
	printf("                                                                          \n");//5
	printf("                                                                          \n");//6
	printf("           ���  ���   ��      ��   ��       ������   ����         \n");//Sleep(1000);2
	printf("           �� ��� ��   ��      ��   ��           ��         ��           \n");//Sleep(1000);3
	printf("           ��  ��  ��   ��      ��   ��           ��         ��           \n");//Sleep(1000);4
	printf("           ��      ��   ��      ��   ��           ��         ��           \n");//Sleep(1000);5
	printf("           ��      ��    �����    �����     ��       ����         \n");//Sleep(1000);6
	printf("                                                                          \n");//Sleep(1000);7
	printf("                                                                          \n");//Sleep(1000);7
	textcolor(BLUE2, BLACK);
	printf("              �����   ��      ��    ���  ���    �����             \n");//Sleep(1000);8
	printf("                 ��      ��      ��    �� ��� ��    ��    ��             \n");//Sleep(1000);9
	printf("                 ��      ��      ��    ��  ��  ��    �����	          \n");//Sleep(1000);10
	printf("                 ��      ��      ��    ��      ��    ��                   \n");//Sleep(1000);11
	printf("               ���       �����     ��      ��    ��                   \n");//Sleep(1000);12
	printf("	    				                 				                  \n");//Sleep(1000);13
	textcolor(GREEN2, BLACK);
	printf("               ����       ���       ���  ���    �����             \n");//Sleep(1000);14
	printf("              ��           ��  ��      �� ��� ��    ��                   \n");//Sleep(1000);15
	printf("              ��  ���    �����     ��  ��  ��    �����             \n");//Sleep(1000);16
	printf("              ��    ��    ��    ��     ��      ��    ��                   \n");//Sleep(1000);17
	printf("               ��� ��    ��    ��     ��      ��    �����    	      \n");//Sleep(1000);18
	textcolor(MAGENTA2, BLACK);
	printf("                                                                          \n");//Sleep(1000);19
	printf("                                                                          \n");//Sleep(1000):20
	textcolor(WHITE, BLACK);
}
// ù��°ȭ�� �⺻
void firstscreen_1() {
	cls(); gotoxy(0, 0); textcolor(RED2, BLACK);
	printf("                                                                          \n");//1
	printf("                                                                          \n");//2
	printf("                                                                          \n");//3
	printf("                                                                          \n");//4
	printf("                                                                          \n");//5
	printf("                                                                          \n");//6
	printf("           ���  ���   ��      ��   ��       ������   ����         \n");//Sleep(1000);2
	printf("           �� ��� ��   ��      ��   ��           ��         ��           \n");//Sleep(1000);3
	printf("           ��  ��  ��   ��      ��   ��           ��         ��           \n");//Sleep(1000);4
	printf("           ��      ��   ��      ��   ��           ��         ��           \n");//Sleep(1000);5
	printf("           ��      ��    �����    �����     ��       ����         \n");//Sleep(1000);6
	printf("                                                                          \n");//Sleep(1000);7
	printf("                                                                          \n");//Sleep(1000);7
	textcolor(BLUE2, BLACK);
	printf("              �����   ��      ��    ���  ���    �����             \n");//Sleep(1000);8
	printf("                 ��      ��      ��    �� ��� ��    ��    ��             \n");//Sleep(1000);9
	printf("                 ��      ��      ��    ��  ��  ��    �����	          \n");//Sleep(1000);10
	printf("                 ��      ��      ��    ��      ��    ��                   \n");//Sleep(1000);11
	printf("               ���       �����     ��      ��    ��                   \n");//Sleep(1000);12
	printf("	    				                 				                  \n");//Sleep(1000);13
	textcolor(GREEN2, BLACK);
	printf("               ����       ���       ���  ���    �����             \n");//Sleep(1000);14
	printf("              ��           ��  ��      �� ��� ��    ��                   \n");//Sleep(1000);15
	printf("              ��  ���    �����     ��  ��  ��    �����             \n");//Sleep(1000);16
	printf("              ��    ��    ��    ��     ��      ��    ��                   \n");//Sleep(1000);17
	printf("               ��� ��    ��    ��     ��      ��    �����    	      \n");//Sleep(1000);18
	printf("                                                                          \n");//Sleep(1000);19
	textcolor(MAGENTA2, BLACK);
	printf("                               Press Any Key ....                         \n");//Sleep(1000):
	textcolor(WHITE, BLACK);
}
// ù��°ȭ�� -1
void firstscreen_2() {
	cls(); gotoxy(0, 0); textcolor(RED2, BLACK);
	printf("                                                                          \n");//1
	printf("                                                                          \n");//2
	printf("                                                                          \n");//3
	printf("                                                                          \n");//4
	printf("                                                                          \n");//5
	printf("                                                                          \n");//6
	printf("           ���  ���   ��      ��   ��       ������   ����         \n");//Sleep(1000);2
	printf("           �� ��� ��   ��      ��   ��           ��         ��           \n");//Sleep(1000);3
	printf("           ��  ��  ��   ��      ��   ��           ��         ��           \n");//Sleep(1000);4
	printf("           ��      ��   ��      ��   ��           ��         ��           \n");//Sleep(1000);5
	printf("           ��      ��    �����    �����     ��       ����         \n");//Sleep(1000);6
	printf("                                                                          \n");//Sleep(1000);7
	printf("                                                                          \n");//Sleep(1000);7
	textcolor(BLUE2, BLACK);
	printf("              �����   ��      ��    ���  ���    �����             \n");//Sleep(1000);8
	printf("                 ��      ��      ��    �� ��� ��    ��    ��             \n");//Sleep(1000);9
	printf("                 ��      ��      ��    ��  ��  ��    �����	          \n");//Sleep(1000);10
	printf("                 ��      ��      ��    ��      ��    ��                   \n");//Sleep(1000);11
	printf("               ���       �����     ��      ��    ��                   \n");//Sleep(1000);12
	printf("	    				                 				                  \n");//Sleep(1000);13
	textcolor(GREEN2, BLACK);
	printf("               ����       ���       ���  ���    �����             \n");//Sleep(1000);14
	printf("              ��           ��  ��      �� ��� ��    ��                   \n");//Sleep(1000);15
	printf("              ��  ���    �����     ��  ��  ��    �����             \n");//Sleep(1000);16
	printf("              ��    ��    ��    ��     ��      ��    ��                   \n");//Sleep(1000);17
	printf("               ��� ��    ��    ��     ��      ��    �����     	      \n");//Sleep(1000);18
	printf("                                                                          \n");//Sleep(1000);19
	textcolor(MAGENTA2, BLACK);
	printf("                               Press Any Key ....                         \n");//Sleep(1000):
	textcolor(WHITE, BLACK);
}
// ù��°ȭ��-2
void secondscreen() {
	gotoxy(0, 0);
	printf("                                                                          \n");//1
	printf("                                                                          \n");//6
	textcolor(RED2, BLACK);
	printf("                  "); textcolor(RED2, BLACK); printf("�� "); textcolor(WHITE, BLACK); printf("��  ��  ��  ��  ��  ��  ��  ��"); textcolor(RED2, BLACK); printf(" ��"); textcolor(WHITE, BLACK);printf("                     \n");//7
	textcolor(WHITE, BLACK);
	printf("                                                                          \n");
	printf("                                                                          \n");
	printf("       ");textcolor(YELLOW2,BLACK);printf("��");textcolor(WHITE,BLACK);printf(" �� 4���� �������� ���������� �������ؼ� ��ֹ��� �Ѵ°���       \n");
	printf("                                                            		      \n");
	printf("       ");textcolor(YELLOW2,BLACK);printf("��");textcolor(WHITE,BLACK);printf(" �������� ����Ű�� ���� ������, �� �� �Ǵ� �� ���� ��ֹ���      \n");
	printf("          ���ÿ� ������ ������ "); textcolor(RED2, BLACK); printf("Game Over"); textcolor(WHITE, BLACK); printf("							  	  \n");
	printf("                                                                          \n");
	printf("       ");textcolor(YELLOW2,BLACK);printf("��");textcolor(WHITE,BLACK);printf(" �� 3���� STAGE�� �����Ǿ������� 5�� ���� STAGE�� �ö�         \n");
	printf("                                                                          \n");
	printf("                                                                          \n");
	printf("       ");textcolor(YELLOW2,BLACK);printf("��");textcolor(WHITE,BLACK);printf(" STAGE�� �ö� ������ ���� Ű ��ư�� ��ֹ��� ����� �ٲ�          \n");
	printf("                                                                          \n");
	printf("                                                                          \n");
	printf("                   1���� Ű: "); textcolor(MAGENTA2, BLACK); printf("A"); textcolor(WHITE, BLACK); printf("          2���� Ű : "); textcolor(YELLOW2, BLACK); printf("D"); textcolor(WHITE, BLACK);printf("                       \n");
	printf("                   3���� Ű: "); textcolor(CYAN2, BLACK); printf("J"); textcolor(WHITE, BLACK); printf("          4���� Ű : "); textcolor(GREEN2, BLACK); printf("L"); textcolor(WHITE, BLACK); printf("                       \n");
	printf("                                                             		      \n");
	printf("                                  ���ӽ��� -> "); textcolor(BLUE2, BLACK); printf("Enter"); textcolor(WHITE, BLACK);printf("                       \n");
}
// 2��°ȭ��
void secondscreen_start() {
	clock_t now, before, alarm_time;// , remain_msec;
	clock_t sec;
	int mm = 6, msec, remain_msec;
	msec = mm  * CLOCKS_PER_SEC;
	now = before = clock();
	alarm_time = now + msec;
	printf("\n");
	while (alarm_time != now) {
		do {
			now = clock();
		} while (before == now);
		before = now;
		remain_msec = alarm_time - now;
		sec = remain_msec / CLOCKS_PER_SEC;
		sec = sec % 60;
		if (sec == -1)break;
		printf("                                  %02d\r", sec);
	}
	textcolor(RED2,BLACK);
	printf("                           G A M E  S T A R T  ! \n");Sleep(700);
	textcolor(WHITE,BLACK);
}
// 2��°ȭ�� -> ����ȭ��
void gameover_screen() {
	cls(); gotoxy(0, 0);cls2(BLACK,WHITE); 
	printf("                                                                        \n");//Sleep(600);
	printf("                                                                        \n");//Sleep(600);
	printf("                                                                        \n");//Sleep(600);
	printf("                                                                        \n");//Sleep(600);
	printf("                                                                        \n");//Sleep(800);
	printf("                                                                        \n");//Sleep(800);
	textcolor(RED2,BLACK);
	printf("                ����        ��        ���  ���    �����          \n");Sleep(300);
	printf("               ��           ��  ��      �� ��� ��    ��                \n");Sleep(300);
	printf("               ��  ���    �����     ��  ��  ��    �����          \n");Sleep(300);
	printf("               ��    ��    ��    ��     ��      ��    ��                \n");Sleep(300);
	printf("                ��� ��    ��    ��     ��      ��    �����    	    \n");Sleep(300);
	printf("                                                                        \n");Sleep(300);
	printf("                                                                        \n");Sleep(300);
	textcolor(BLUE2,BLACK);
	printf("                ����     ��    ��     ������    �����          \n");Sleep(300);
	printf("               ��    ��    ��    ��     ��            ��     ��         \n");Sleep(300);
	printf("               ��    ��    ��    ��     ������    �����          \n");Sleep(300);
	printf("               ��    ��     ��  ��      ��            ��     ��         \n");Sleep(300);
	printf("                ����       ���       ������    ��     ��         \n");Sleep(300);
	printf("                                                                        \n");Sleep(300);
	printf("                                                                        \n");Sleep(300);
	printf("                                                                        \n");Sleep(300);
	textcolor(YELLOW2,BLACK);
	printf("                           1. Regame    ");textcolor(GREEN2,BLACK); printf("2.Exit                          \n");Sleep(300);
	textcolor(WHITE,BLACK);
	printf("                                                                        \n");Sleep(300);
	printf("                                                                        \n");//Sleep(600);
	textcolor(WHITE,BLACK);
}
void stageclear_screen() {
	cls(); gotoxy(0, 0);
	printf("                                                                          \n");//Sleep(600);
	printf("                                                                          \n");//Sleep(600);
	printf("                                                                          \n");//Sleep(600);
	printf("                                                                          \n");//Sleep(600);
	printf("                                                                          \n");//Sleep(800);
	printf("                                                                          \n");//Sleep(800);
	printf("            �����   �����    ���       ����     �����         \n");//Sleep(800);
	printf("            ��            ��      ��  ��     ��          ��               \n");//Sleep(800);
	printf("            �����      ��     �����    ��   ���   �����         \n");//Sleep(800);
	printf("                  ��      ��     ��    ��    ��     ��   ��               \n");//Sleep(800);
	printf("            �����      ��     ��    ��     ���  ��   �����    	  \n");//Sleep(800);
	printf("                                                                          \n");//Sleep(600);
	printf("                                                                          \n");//Sleep(600);
	printf("             ����     ��       �����      ���      �����         \n");//Sleep(800);
	printf("            ��          ��       ��           ��  ��     ��     ��        \n");//Sleep(800);
	printf("            ��          ��       �����    �����    �����         \n");//Sleep(800);
	printf("            ��          ��       ��          ��    ��    ��     ��        \n");//Sleep(800);
	printf("             ����     ����   �����    ��    ��    ��     ��        \n");//Sleep(800);
	printf("                                                                          \n");//Sleep(600);
	printf("                                                                          \n");//Sleep(600);
	textcolor(GREEN2,BLACK);
	printf("                           1. Next Stage    2.Exit                        \n");//Sleep(800);
	printf("                                                                          \n");//Sleep(600);
	textcolor(WHITE,BLACK);
}
void allgameclear(){
cls(); textcolor(WHITE,BLACK);gotoxy(30,14);printf("- The_End -\n");
}
void mapbase() {
	int i, j;
	for (i = 0; i<size_y; i++) {
		for (j = 0; j<size_x; j++) {
			if (i % 6 == 0) { if (j % 2 == 0)map[i][j] = 1; else map[i][j] = 1; } //printf("��");}
			else if (j == 24) { map[i][j] = 1; } //printf("��");}
			else if (j == my_x1 && i == my_y1) { map[i][j] = 2; } //printf("��");}
			else if (j == my_x2 && i == my_y2) { map[i][j] = 2; } //printf("��");}
			else if (j == my_x3 && i == my_y3) { map[i][j] = 2; } //printf("��");}
			else if (j == my_x4 && i == my_y4) { map[i][j] = 2; } //printf("��");}
			else { map[i][j] = 0; } //printf("  ");}
		}
		//printf("\n");
	}
}
// �� Ʋ.
void mapping() {
	int i, j;
	textcolor(BLACK, WHITE);
	for (i = 0; i<size_y; i++) {
		for (j = 0; j<size_x; j++) { // 
			if (map[i][j] == 0)printf("  ");
			else if (map[i][j] == 1)printf("��");
			else if (map[i][j] == 2)printf("��");
			else if (map[i][j] == 6)printf("��");
		}
		printf("\n");
	}
}
// �� �׸���
void mapping2() {
	int i, j;
	gotoxy(0, 1); textcolor(WHITE, BLACK);
	for (i = 1; i<6; i++)
	{
		for (j = 0; j<24; j++)
		{
			if (map[i][j] == 0)printf("  ");
			else if (map[i][j] == 1) { textcolor(RED2,BLACK);printf("��");textcolor(WHITE,BLACK);}
			else if (map[i][j] == 2) { textcolor(MAGENTA2, BLACK); printf("��"); textcolor(WHITE, BLACK); }
		}
		printf("\n");
	}
	gotoxy(0, 7); textcolor(WHITE, BLACK);
	for (i = 7; i<12; i++)
	{
		for (j = 0; j < 24; j++)
		{
			if (map[i][j] == 0)printf("  ");
			else if (map[i][j] == 1) { textcolor(RED2,BLACK);printf("��");textcolor(WHITE,BLACK);}
			else if (map[i][j] == 2) { textcolor(YELLOW2, BLACK); printf("��"); textcolor(WHITE, BLACK); }
		}
		printf("\n");
	}
	gotoxy(0, 13); textcolor(WHITE, BLACK);
	for (i = 13; i<18; i++)
	{
		for (j = 0; j<24; j++)
		{
			if (map[i][j] == 0)printf("  ");
			else if (map[i][j] == 1) { textcolor(RED2,BLACK);printf("��");textcolor(WHITE,BLACK);}
			else if (map[i][j] == 2) { textcolor(CYAN2, BLACK); printf("��"); textcolor(WHITE, BLACK); }
		}
		printf("\n");
	}
	gotoxy(0, 19); textcolor(WHITE,BLACK);
	for (i = 19; i<24; i++)
	{
		for (j = 0; j<24; j++)
		{
			if (map[i][j] == 0)printf("  ");
			else if (map[i][j] == 1) { textcolor(RED2,BLACK);printf("��");textcolor(WHITE,BLACK);}
			else if (map[i][j] == 2) { textcolor(GREEN2, BLACK); printf("��"); textcolor(WHITE, BLACK); }
		}
		printf("\n");
	}
}
// �׵θ� �� �� �׸���
void jump0_1(int i, int h) { // �ٲ��ٷ��� ��ֹ��� ���� �ٲ������.
	static int step = 0;
	int j = 0;
	for (j = 0; j<7; j++) {
		switch (step) {
		case 0:
			map[5 + (h - 1) * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 1] = 1; mapping2();
			map[5 + (h - 1) * 6][3] = 0; map[5 + (h - 1) * 6][25 - i - 1] = 0; delay(); mapping2(); break;
		case 1:
			map[4 + (h - 1) * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 2] = 1; mapping2();
			map[4 + (h - 1) * 6][3] = 0; map[5 + (h - 1) * 6][25 - i - 2] = 0; delay(); mapping2(); break;
		case 2:
			map[3 + (h - 1) * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 3] = 1; mapping2();
			map[3 + (h - 1) * 6][3] = 0; map[5 + (h - 1) * 6][25 - i - 3] = 0; delay(); mapping2(); break;
		case 3:
			map[2 + (h - 1) * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 4] = 1; mapping2();
			map[2 + (h - 1) * 6][3] = 0; map[5 + (h - 1) * 6][25 - i - 4] = 0; delay(); mapping2(); break;
		case 4:
			map[3 + (h - 1) * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 5] = 1; mapping2();
			map[3 + (h - 1) * 6][3] = 0; map[5 + (h - 1) * 6][25 - i - 5] = 0; delay(); mapping2(); break;
		case 5:
			map[4 + (h - 1) * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 6] = 1; mapping2();
			map[4 + (h - 1) * 6][3] = 0; map[5 + (h - 1) * 6][25 - i - 6] = 0; delay(); mapping2(); break;
		case 6:
			map[5 + (h - 1) * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 7] = 1; mapping2();
			map[5 + (h - 1) * 6][25 - i - 7] = 0; delay(); mapping2(); break;
		}
		step++;
		step = step % 7;
	}
}//�Ʒ��� 1��¥��
void jump0_1_12(int i, int h) { // �ٲ��ٷ��� ��ֹ��� ���� �ٲ������.
	static int step = 0;
	int j = 0;
	for (j = 0; j<7; j++) {
		switch (step) {
		case 0:
			map[5 + (h - 1) * 6][3] = 2; map[5 + h * 6][3] = 2;   map[5 + (h - 1) * 6][25 - i - 1] = 1; map[5 + h * 6][25 - i - 1] = 1; mapping2();
			map[5 + (h - 1) * 6][3] = 0; map[5 + h * 6][3] = 0;   map[5 + (h - 1) * 6][25 - i - 1] = 0; map[5 + h * 6][25 - i - 1] = 0; delay(); mapping2(); break;
		case 1:
			map[4 + (h - 1) * 6][3] = 2; map[4 + h * 6][3] = 2;   map[5 + (h - 1) * 6][25 - i - 2] = 1; map[5 + h * 6][25 - i - 2] = 1; mapping2();
			map[4 + (h - 1) * 6][3] = 0; map[4 + h * 6][3] = 0;   map[5 + (h - 1) * 6][25 - i - 2] = 0; map[5 + h * 6][25 - i - 2] = 0; delay(); mapping2(); break;
		case 2:
			map[3 + (h - 1) * 6][3] = 2; map[3 + h * 6][3] = 2;   map[5 + (h - 1) * 6][25 - i - 3] = 1; map[5 + h * 6][25 - i - 3] = 1; mapping2();
			map[3 + (h - 1) * 6][3] = 0; map[3 + h * 6][3] = 0;   map[5 + (h - 1) * 6][25 - i - 3] = 0; map[5 + h * 6][25 - i - 3] = 0; delay(); mapping2(); break;
		case 3:
			map[2 + (h - 1) * 6][3] = 2; map[2 + h * 6][3] = 2;   map[5 + (h - 1) * 6][25 - i - 4] = 1; map[5 + h * 6][25 - i - 4] = 1; mapping2();
			map[2 + (h - 1) * 6][3] = 0; map[2 + h * 6][3] = 0;   map[5 + (h - 1) * 6][25 - i - 4] = 0; map[5 + h * 6][25 - i - 4] = 0; delay(); mapping2(); break;
		case 4:
			map[3 + (h - 1) * 6][3] = 2; map[3 + h * 6][3] = 2;   map[5 + (h - 1) * 6][25 - i - 5] = 1; map[5 + h * 6][25 - i - 5] = 1; mapping2();
			map[3 + (h - 1) * 6][3] = 0; map[3 + h * 6][3] = 0;   map[5 + (h - 1) * 6][25 - i - 5] = 0; map[5 + h * 6][25 - i - 5] = 0; delay(); mapping2(); break;
		case 5:
			map[4 + (h - 1) * 6][3] = 2; map[4 + h * 6][3] = 2;   map[5 + (h - 1) * 6][25 - i - 6] = 1; map[5 + h * 6][25 - i - 6] = 1; mapping2();
			map[4 + (h - 1) * 6][3] = 0; map[4 + h * 6][3] = 0;   map[5 + (h - 1) * 6][25 - i - 6] = 0; map[5 + h * 6][25 - i - 6] = 0; delay(); mapping2(); break;
		case 6:
			map[5 + (h - 1) * 6][3] = 2; map[5 + h * 6][3] = 2;   map[5 + (h - 1) * 6][25 - i - 7] = 1; map[5 + h * 6][25 - i - 7] = 1; mapping2();
			map[5 + (h - 1) * 6][25 - i - 7] = 0; map[5 + h * 6][25 - i - 7] = 0; delay(); mapping2(); break;
		}
		step++;
		step = step % 7;
	}
}//�Ʒ��� 1��¥��
void jump0_1_12_1(int i, int h) { // �ٲ��ٷ��� ��ֹ��� ���� �ٲ������.
	static int step = 0;
	int j = 0;
	for (j = 0; j<7; j++) {
		switch (step) {
		case 0:
			map[5 + (h - 1) * 6][3] = 2; map[5 + h * 6][3] = 2;   map[5 + (h - 1) * 6][25 - i - 1] = 1; map[5 + h * 6][25 - i - 1] = 1; mapping2();
			map[5 + (h - 1) * 6][3] = 0; map[5 + h * 6][3] = 0;   map[5 + (h - 1) * 6][25 - i - 1] = 0; map[5 + h * 6][25 - i - 1] = 0; delay(); mapping2(); break;
		case 1:
			map[4 + (h - 1) * 6][3] = 2; map[5 + h * 6][3] = 2;   map[5 + (h - 1) * 6][25 - i - 2] = 1; map[5 + h * 6][25 - i - 2] = 1; mapping2();
			map[4 + (h - 1) * 6][3] = 0; map[5 + h * 6][3] = 0;   map[5 + (h - 1) * 6][25 - i - 2] = 0; map[5 + h * 6][25 - i - 2] = 0; delay(); mapping2(); break;
		case 2:
			map[3 + (h - 1) * 6][3] = 2; map[5 + h * 6][3] = 2;   map[5 + (h - 1) * 6][25 - i - 3] = 1; map[5 + h * 6][25 - i - 3] = 1; mapping2();
			map[3 + (h - 1) * 6][3] = 0; map[5 + h * 6][3] = 0;   map[5 + (h - 1) * 6][25 - i - 3] = 0; map[5 + h * 6][25 - i - 3] = 0; delay(); mapping2(); break;
		case 3:
			map[2 + (h - 1) * 6][3] = 2; map[5 + h * 6][3] = 2;   map[5 + (h - 1) * 6][25 - i - 4] = 1; map[5 + h * 6][25 - i - 4] = 1; mapping2();
			map[2 + (h - 1) * 6][3] = 0; map[5 + h * 6][3] = 0;   map[5 + (h - 1) * 6][25 - i - 4] = 0; map[5 + h * 6][25 - i - 4] = 0; delay(); mapping2(); break;
		case 4:
			map[3 + (h - 1) * 6][3] = 2; map[5 + h * 6][3] = 2;   map[5 + (h - 1) * 6][25 - i - 5] = 1; map[5 + h * 6][25 - i - 5] = 1; mapping2();
			map[3 + (h - 1) * 6][3] = 0; map[5 + h * 6][3] = 0;   map[5 + (h - 1) * 6][25 - i - 5] = 0; map[5 + h * 6][25 - i - 5] = 0; delay(); mapping2(); break;
		case 5:
			map[4 + (h - 1) * 6][3] = 2; map[5 + h * 6][3] = 2;   map[5 + (h - 1) * 6][25 - i - 6] = 1; map[5 + h * 6][25 - i - 6] = 1; mapping2();
			map[4 + (h - 1) * 6][3] = 0; map[5 + h * 6][3] = 0;   map[5 + (h - 1) * 6][25 - i - 6] = 0; map[5 + h * 6][25 - i - 6] = 0; delay(); mapping2(); break;
		case 6:
			map[5 + (h - 1) * 6][3] = 2; map[5 + h * 6][3] = 2;   map[5 + (h - 1) * 6][25 - i - 7] = 1; map[5 + h * 6][25 - i - 7] = 1; mapping2();
			map[5 + (h - 1) * 6][25 - i - 7] = 0; map[5 + h * 6][25 - i - 7] = 0; delay(); mapping2(); break;
		}
		step++;
		step = step % 7;
	}
}//�Ʒ��� 1��¥��
void jump0_1_12_2(int i, int h) { // �ٲ��ٷ��� ��ֹ��� ���� �ٲ������.
	static int step = 0;
	int j = 0;
	for (j = 0; j<7; j++) {
		switch (step) {
		case 0:
			map[5 + (h - 1) * 6][3] = 2; map[5 + h * 6][3] = 2;   map[5 + (h - 1) * 6][25 - i - 1] = 1; map[5 + h * 6][25 - i - 1] = 1; mapping2();
			map[5 + (h - 1) * 6][3] = 0; map[5 + h * 6][3] = 0;   map[5 + (h - 1) * 6][25 - i - 1] = 0; map[5 + h * 6][25 - i - 1] = 0; delay(); mapping2(); break;
		case 1:
			map[5 + (h - 1) * 6][3] = 2; map[4 + h * 6][3] = 2;   map[5 + (h - 1) * 6][25 - i - 2] = 1; map[5 + h * 6][25 - i - 2] = 1; mapping2();
			map[5 + (h - 1) * 6][3] = 0; map[4 + h * 6][3] = 0;   map[5 + (h - 1) * 6][25 - i - 2] = 0; map[5 + h * 6][25 - i - 2] = 0; delay(); mapping2(); break;
		case 2:
			map[5 + (h - 1) * 6][3] = 2; map[3 + h * 6][3] = 2;   map[5 + (h - 1) * 6][25 - i - 3] = 1; map[5 + h * 6][25 - i - 3] = 1; mapping2();
			map[5 + (h - 1) * 6][3] = 0; map[3 + h * 6][3] = 0;   map[5 + (h - 1) * 6][25 - i - 3] = 0; map[5 + h * 6][25 - i - 3] = 0; delay(); mapping2(); break;
		case 3:
			map[5 + (h - 1) * 6][3] = 2; map[2 + h * 6][3] = 2;   map[5 + (h - 1) * 6][25 - i - 4] = 1; map[5 + h * 6][25 - i - 4] = 1; mapping2();
			map[5 + (h - 1) * 6][3] = 0; map[2 + h * 6][3] = 0;   map[5 + (h - 1) * 6][25 - i - 4] = 0; map[5 + h * 6][25 - i - 4] = 0; delay(); mapping2(); break;
		case 4:
			map[5 + (h - 1) * 6][3] = 2; map[3 + h * 6][3] = 2;   map[5 + (h - 1) * 6][25 - i - 5] = 1; map[5 + h * 6][25 - i - 5] = 1; mapping2();
			map[5 + (h - 1) * 6][3] = 0; map[3 + h * 6][3] = 0;   map[5 + (h - 1) * 6][25 - i - 5] = 0; map[5 + h * 6][25 - i - 5] = 0; delay(); mapping2(); break;
		case 5:
			map[5 + (h - 1) * 6][3] = 2; map[4 + h * 6][3] = 2;   map[5 + (h - 1) * 6][25 - i - 6] = 1; map[5 + h * 6][25 - i - 6] = 1; mapping2();
			map[5 + (h - 1) * 6][3] = 0; map[4 + h * 6][3] = 0;   map[5 + (h - 1) * 6][25 - i - 6] = 0; map[5 + h * 6][25 - i - 6] = 0; delay(); mapping2(); break;
		case 6:
			map[5 + (h - 1) * 6][3] = 2; map[5 + h * 6][3] = 2;   map[5 + (h - 1) * 6][25 - i - 7] = 1; map[5 + h * 6][25 - i - 7] = 1; mapping2();
			map[5 + (h - 1) * 6][25 - i - 7] = 0; map[5 + h * 6][25 - i - 7] = 0; delay(); mapping2(); break;
		}
		step++;
		step = step % 7;
	}
}//�Ʒ��� 1��¥��
void jump0_1_13(int i, int h) { // �ٲ��ٷ��� ��ֹ��� ���� �ٲ������.
	static int step = 0;
	int j = 0;
	for (j = 0; j<7; j++) {
		switch (step) {
		case 0:
			map[5 + (h - 1) * 6][3] = 2; map[5 + (h + 1) * 6][3] = 2;   map[5 + (h - 1) * 6][25 - i - 1] = 1; map[5 + (h + 1) * 6][25 - i - 1] = 1; mapping2();
			map[5 + (h - 1) * 6][3] = 0; map[5 + (h + 1) * 6][3] = 0;   map[5 + (h - 1) * 6][25 - i - 1] = 0; map[5 + (h + 1) * 6][25 - i - 1] = 0; delay(); mapping2(); break;
		case 1:
			map[4 + (h - 1) * 6][3] = 2; map[4 + (h + 1) * 6][3] = 2;   map[5 + (h - 1) * 6][25 - i - 2] = 1; map[5 + (h + 1) * 6][25 - i - 2] = 1; mapping2();
			map[4 + (h - 1) * 6][3] = 0; map[4 + (h + 1) * 6][3] = 0;   map[5 + (h - 1) * 6][25 - i - 2] = 0; map[5 + (h + 1) * 6][25 - i - 2] = 0; delay(); mapping2(); break;
		case 2:
			map[3 + (h - 1) * 6][3] = 2; map[3 + (h + 1) * 6][3] = 2;   map[5 + (h - 1) * 6][25 - i - 3] = 1; map[5 + (h + 1) * 6][25 - i - 3] = 1; mapping2();
			map[3 + (h - 1) * 6][3] = 0; map[3 + (h + 1) * 6][3] = 0;   map[5 + (h - 1) * 6][25 - i - 3] = 0; map[5 + (h + 1) * 6][25 - i - 3] = 0; delay(); mapping2(); break;
		case 3:
			map[2 + (h - 1) * 6][3] = 2; map[2 + (h + 1) * 6][3] = 2;   map[5 + (h - 1) * 6][25 - i - 4] = 1; map[5 + (h + 1) * 6][25 - i - 4] = 1; mapping2();
			map[2 + (h - 1) * 6][3] = 0; map[2 + (h + 1) * 6][3] = 0;   map[5 + (h - 1) * 6][25 - i - 4] = 0; map[5 + (h + 1) * 6][25 - i - 4] = 0; delay(); mapping2(); break;
		case 4:
			map[3 + (h - 1) * 6][3] = 2; map[3 + (h + 1) * 6][3] = 2;   map[5 + (h - 1) * 6][25 - i - 5] = 1; map[5 + (h + 1) * 6][25 - i - 5] = 1; mapping2();
			map[3 + (h - 1) * 6][3] = 0; map[3 + (h + 1) * 6][3] = 0;   map[5 + (h - 1) * 6][25 - i - 5] = 0; map[5 + (h + 1) * 6][25 - i - 5] = 0; delay(); mapping2(); break;
		case 5:
			map[4 + (h - 1) * 6][3] = 2; map[4 + (h + 1) * 6][3] = 2;   map[5 + (h - 1) * 6][25 - i - 6] = 1; map[5 + (h + 1) * 6][25 - i - 6] = 1; mapping2();
			map[4 + (h - 1) * 6][3] = 0; map[4 + (h + 1) * 6][3] = 0;   map[5 + (h - 1) * 6][25 - i - 6] = 0; map[5 + (h + 1) * 6][25 - i - 6] = 0; delay(); mapping2(); break;
		case 6:
			map[5 + (h - 1) * 6][3] = 2; map[5 + (h + 1) * 6][3] = 2;   map[5 + (h - 1) * 6][25 - i - 7] = 1; map[5 + (h + 1) * 6][25 - i - 7] = 1; mapping2();
			map[5 + (h - 1) * 6][25 - i - 7] = 0; map[5 + (h + 1) * 6][25 - i - 7] = 0; delay(); mapping2(); break;
		}
		step++;
		step = step % 7;
	}
}//�Ʒ��� 1��¥��
void jump0_1_13_1(int i, int h) { // �ٲ��ٷ��� ��ֹ��� ���� �ٲ������.
	static int step = 0;
	int j = 0;
	for (j = 0; j<7; j++) {
		switch (step) {
		case 0:
			map[5 + (h - 1) * 6][3] = 2; map[5 + (h + 1) * 6][3] = 2;   map[5 + (h - 1) * 6][25 - i - 1] = 1; map[5 + (h + 1) * 6][25 - i - 1] = 1; mapping2();
			map[5 + (h - 1) * 6][3] = 0; map[5 + (h + 1) * 6][3] = 0;   map[5 + (h - 1) * 6][25 - i - 1] = 0; map[5 + (h + 1) * 6][25 - i - 1] = 0; delay(); mapping2(); break;
		case 1:
			map[4 + (h - 1) * 6][3] = 2; map[5 + (h + 1) * 6][3] = 2;   map[5 + (h - 1) * 6][25 - i - 2] = 1; map[5 + (h + 1) * 6][25 - i - 2] = 1; mapping2();
			map[4 + (h - 1) * 6][3] = 0; map[5 + (h + 1) * 6][3] = 0;   map[5 + (h - 1) * 6][25 - i - 2] = 0; map[5 + (h + 1) * 6][25 - i - 2] = 0; delay(); mapping2(); break;
		case 2:
			map[3 + (h - 1) * 6][3] = 2; map[5 + (h + 1) * 6][3] = 2;   map[5 + (h - 1) * 6][25 - i - 3] = 1; map[5 + (h + 1) * 6][25 - i - 3] = 1; mapping2();
			map[3 + (h - 1) * 6][3] = 0; map[5 + (h + 1) * 6][3] = 0;   map[5 + (h - 1) * 6][25 - i - 3] = 0; map[5 + (h + 1) * 6][25 - i - 3] = 0; delay(); mapping2(); break;
		case 3:
			map[2 + (h - 1) * 6][3] = 2; map[5 + (h + 1) * 6][3] = 2;   map[5 + (h - 1) * 6][25 - i - 4] = 1; map[5 + (h + 1) * 6][25 - i - 4] = 1; mapping2();
			map[2 + (h - 1) * 6][3] = 0; map[5 + (h + 1) * 6][3] = 0;   map[5 + (h - 1) * 6][25 - i - 4] = 0; map[5 + (h + 1) * 6][25 - i - 4] = 0; delay(); mapping2(); break;
		case 4:
			map[3 + (h - 1) * 6][3] = 2; map[5 + (h + 1) * 6][3] = 2;   map[5 + (h - 1) * 6][25 - i - 5] = 1; map[5 + (h + 1) * 6][25 - i - 5] = 1; mapping2();
			map[3 + (h - 1) * 6][3] = 0; map[5 + (h + 1) * 6][3] = 0;   map[5 + (h - 1) * 6][25 - i - 5] = 0; map[5 + (h + 1) * 6][25 - i - 5] = 0; delay(); mapping2(); break;
		case 5:
			map[4 + (h - 1) * 6][3] = 2; map[5 + (h + 1) * 6][3] = 2;   map[5 + (h - 1) * 6][25 - i - 6] = 1; map[5 + (h + 1) * 6][25 - i - 6] = 1; mapping2();
			map[4 + (h - 1) * 6][3] = 0; map[5 + (h + 1) * 6][3] = 0;   map[5 + (h - 1) * 6][25 - i - 6] = 0; map[5 + (h + 1) * 6][25 - i - 6] = 0; delay(); mapping2(); break;
		case 6:
			map[5 + (h - 1) * 6][3] = 2; map[5 + (h + 1) * 6][3] = 2;   map[5 + (h - 1) * 6][25 - i - 7] = 1; map[5 + (h + 1) * 6][25 - i - 7] = 1; mapping2();
			map[5 + (h - 1) * 6][25 - i - 7] = 0; map[5 + (h + 1) * 6][25 - i - 7] = 0; delay(); mapping2(); break;
		}
		step++;
		step = step % 7;
	}
}//�Ʒ��� 1��¥��
void jump0_1_13_2(int i, int h) { // �ٲ��ٷ��� ��ֹ��� ���� �ٲ������.
	static int step = 0;
	int j = 0;
	for (j = 0; j<7; j++) {
		switch (step) {
		case 0:
			map[5 + (h - 1) * 6][3] = 2; map[5 + (h + 1) * 6][3] = 2;   map[5 + (h - 1) * 6][25 - i - 1] = 1; map[5 + (h + 1) * 6][25 - i - 1] = 1; mapping2();
			map[5 + (h - 1) * 6][3] = 0; map[5 + (h + 1) * 6][3] = 0;   map[5 + (h - 1) * 6][25 - i - 1] = 0; map[5 + (h + 1) * 6][25 - i - 1] = 0; delay(); mapping2(); break;
		case 1:
			map[5 + (h - 1) * 6][3] = 2; map[4 + (h + 1) * 6][3] = 2;   map[5 + (h - 1) * 6][25 - i - 2] = 1; map[5 + (h + 1) * 6][25 - i - 2] = 1; mapping2();
			map[5 + (h - 1) * 6][3] = 0; map[4 + (h + 1) * 6][3] = 0;   map[5 + (h - 1) * 6][25 - i - 2] = 0; map[5 + (h + 1) * 6][25 - i - 2] = 0; delay(); mapping2(); break;
		case 2:
			map[5 + (h - 1) * 6][3] = 2; map[3 + (h + 1) * 6][3] = 2;   map[5 + (h - 1) * 6][25 - i - 3] = 1; map[5 + (h + 1) * 6][25 - i - 3] = 1; mapping2();
			map[5 + (h - 1) * 6][3] = 0; map[3 + (h + 1) * 6][3] = 0;   map[5 + (h - 1) * 6][25 - i - 3] = 0; map[5 + (h + 1) * 6][25 - i - 3] = 0; delay(); mapping2(); break;
		case 3:
			map[5 + (h - 1) * 6][3] = 2; map[2 + (h + 1) * 6][3] = 2;   map[5 + (h - 1) * 6][25 - i - 4] = 1; map[5 + (h + 1) * 6][25 - i - 4] = 1; mapping2();
			map[5 + (h - 1) * 6][3] = 0; map[2 + (h + 1) * 6][3] = 0;   map[5 + (h - 1) * 6][25 - i - 4] = 0; map[5 + (h + 1) * 6][25 - i - 4] = 0; delay(); mapping2(); break;
		case 4:
			map[5 + (h - 1) * 6][3] = 2; map[3 + (h + 1) * 6][3] = 2;   map[5 + (h - 1) * 6][25 - i - 5] = 1; map[5 + (h + 1) * 6][25 - i - 5] = 1; mapping2();
			map[5 + (h - 1) * 6][3] = 0; map[3 + (h + 1) * 6][3] = 0;   map[5 + (h - 1) * 6][25 - i - 5] = 0; map[5 + (h + 1) * 6][25 - i - 5] = 0; delay(); mapping2(); break;
		case 5:
			map[5 + (h - 1) * 6][3] = 2; map[4 + (h + 1) * 6][3] = 2;   map[5 + (h - 1) * 6][25 - i - 6] = 1; map[5 + (h + 1) * 6][25 - i - 6] = 1; mapping2();
			map[5 + (h - 1) * 6][3] = 0; map[4 + (h + 1) * 6][3] = 0;   map[5 + (h - 1) * 6][25 - i - 6] = 0; map[5 + (h + 1) * 6][25 - i - 6] = 0; delay(); mapping2(); break;
		case 6:
			map[5 + (h - 1) * 6][3] = 2; map[5 + (h + 1) * 6][3] = 2;   map[5 + (h - 1) * 6][25 - i - 7] = 1; map[5 + (h + 1) * 6][25 - i - 7] = 1; mapping2();
			map[5 + (h - 1) * 6][25 - i - 7] = 0; map[5 + (h + 1) * 6][25 - i - 7] = 0; delay(); mapping2(); break;
		}
		step++;
		step = step % 7;
	}
}//�Ʒ��� 1��¥��

void jump0_2(int i, int h) { // �ٲ��ٷ��� ��ֹ��� ���� �ٲ������.
	static int step = 0;
	int j = 0;
	for (j = 0; j<7; j++) {
		switch (step) {
		case 0:
			map[5 + (h - 1) * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 1] = 1; map[4 + (h - 1) * 6][25 - i - 1] = 1; mapping2();
			map[5 + (h - 1) * 6][3] = 0; map[5 + (h - 1) * 6][25 - i - 1] = 0; map[4 + (h - 1) * 6][25 - i - 1] = 0; delay(); mapping2(); break;
		case 1:
			map[4 + (h - 1) * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 2] = 1; map[4 + (h - 1) * 6][25 - i - 2] = 1; mapping2();
			map[4 + (h - 1) * 6][3] = 0; map[5 + (h - 1) * 6][25 - i - 2] = 0; map[4 + (h - 1) * 6][25 - i - 2] = 0; delay(); mapping2(); break;
		case 2:
			map[3 + (h - 1) * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 3] = 1; map[4 + (h - 1) * 6][25 - i - 3] = 1; mapping2();
			map[3 + (h - 1) * 6][3] = 0; map[5 + (h - 1) * 6][25 - i - 3] = 0; map[4 + (h - 1) * 6][25 - i - 3] = 0; delay(); mapping2(); break;
		case 3:
			map[2 + (h - 1) * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 4] = 1; map[4 + (h - 1) * 6][25 - i - 4] = 1; mapping2();
			map[2 + (h - 1) * 6][3] = 0; map[5 + (h - 1) * 6][25 - i - 4] = 0; map[4 + (h - 1) * 6][25 - i - 4] = 0; delay(); mapping2(); break;
		case 4:
			map[3 + (h - 1) * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 5] = 1; map[4 + (h - 1) * 6][25 - i - 5] = 1; mapping2();
			map[3 + (h - 1) * 6][3] = 0; map[5 + (h - 1) * 6][25 - i - 5] = 0; map[4 + (h - 1) * 6][25 - i - 5] = 0; delay(); mapping2(); break;
		case 5:
			map[4 + (h - 1) * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 6] = 1; map[4 + (h - 1) * 6][25 - i - 6] = 1; mapping2();
			map[4 + (h - 1) * 6][3] = 0; map[5 + (h - 1) * 6][25 - i - 6] = 0; map[4 + (h - 1) * 6][25 - i - 6] = 0; delay(); mapping2(); break;
		case 6:
			map[5 + (h - 1) * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 7] = 1; map[4 + (h - 1) * 6][25 - i - 7] = 1; mapping2();
			map[5 + (h - 1) * 6][25 - i - 7] = 0; map[4 + (h - 1) * 6][25 - i - 7] = 0; delay(); mapping2(); break;
		}
		step++;
		step = step % 7;
	}
}//�Ʒ��� 2��¥��
void jump0_2_12(int i, int h) { // �ٲ��ٷ��� ��ֹ��� ���� �ٲ������.
	static int step = 0;
	int j = 0;
	for (j = 0; j<7; j++) {
		switch (step) {
		case 0:
			map[5 + (h - 1) * 6][3] = 2; map[5 + h * 6][3] = 2;  map[5 + (h - 1) * 6][25 - i - 1] = 1; map[4 + (h - 1) * 6][25 - i - 1] = 1; map[5 + h * 6][25 - i - 1] = 1; map[4 + h * 6][25 - i - 1] = 1; mapping2();
			map[5 + (h - 1) * 6][3] = 0; map[5 + h * 6][3] = 0;  map[5 + (h - 1) * 6][25 - i - 1] = 0; map[4 + (h - 1) * 6][25 - i - 1] = 0; map[5 + h * 6][25 - i - 1] = 0; map[4 + h * 6][25 - i - 1] = 0; delay(); mapping2(); break;
		case 1:
			map[4 + (h - 1) * 6][3] = 2; map[4 + h * 6][3] = 2;  map[5 + (h - 1) * 6][25 - i - 2] = 1; map[4 + (h - 1) * 6][25 - i - 2] = 1; map[5 + h * 6][25 - i - 2] = 1; map[4 + h * 6][25 - i - 2] = 1; mapping2();
			map[4 + (h - 1) * 6][3] = 0; map[4 + h * 6][3] = 0;  map[5 + (h - 1) * 6][25 - i - 2] = 0; map[4 + (h - 1) * 6][25 - i - 2] = 0; map[5 + h * 6][25 - i - 2] = 0; map[4 + h * 6][25 - i - 2] = 0; delay(); mapping2(); break;
		case 2:
			map[3 + (h - 1) * 6][3] = 2; map[3 + h * 6][3] = 2;  map[5 + (h - 1) * 6][25 - i - 3] = 1; map[4 + (h - 1) * 6][25 - i - 3] = 1; map[5 + h * 6][25 - i - 3] = 1; map[4 + h * 6][25 - i - 3] = 1; mapping2();
			map[3 + (h - 1) * 6][3] = 0; map[3 + h * 6][3] = 0;  map[5 + (h - 1) * 6][25 - i - 3] = 0; map[4 + (h - 1) * 6][25 - i - 3] = 0; map[5 + h * 6][25 - i - 3] = 0; map[4 + h * 6][25 - i - 3] = 0; delay(); mapping2(); break;
		case 3:
			map[2 + (h - 1) * 6][3] = 2; map[2 + h * 6][3] = 2;  map[5 + (h - 1) * 6][25 - i - 4] = 1; map[4 + (h - 1) * 6][25 - i - 4] = 1; map[5 + h * 6][25 - i - 4] = 1; map[4 + h * 6][25 - i - 4] = 1; mapping2();
			map[2 + (h - 1) * 6][3] = 0; map[2 + h * 6][3] = 0;  map[5 + (h - 1) * 6][25 - i - 4] = 0; map[4 + (h - 1) * 6][25 - i - 4] = 0; map[5 + h * 6][25 - i - 4] = 0; map[4 + h * 6][25 - i - 4] = 0; delay(); mapping2(); break;
		case 4:
			map[3 + (h - 1) * 6][3] = 2; map[3 + h * 6][3] = 2;  map[5 + (h - 1) * 6][25 - i - 5] = 1; map[4 + (h - 1) * 6][25 - i - 5] = 1; map[5 + h * 6][25 - i - 5] = 1; map[4 + h * 6][25 - i - 5] = 1; mapping2();
			map[3 + (h - 1) * 6][3] = 0; map[3 + h * 6][3] = 0;  map[5 + (h - 1) * 6][25 - i - 5] = 0; map[4 + (h - 1) * 6][25 - i - 5] = 0; map[5 + h * 6][25 - i - 5] = 0; map[4 + h * 6][25 - i - 5] = 0; delay(); mapping2(); break;
		case 5:
			map[4 + (h - 1) * 6][3] = 2; map[4 + h * 6][3] = 2;  map[5 + (h - 1) * 6][25 - i - 6] = 1; map[4 + (h - 1) * 6][25 - i - 6] = 1; map[5 + h * 6][25 - i - 6] = 1; map[4 + h * 6][25 - i - 6] = 1; mapping2();
			map[4 + (h - 1) * 6][3] = 0; map[4 + h * 6][3] = 0;  map[5 + (h - 1) * 6][25 - i - 6] = 0; map[4 + (h - 1) * 6][25 - i - 6] = 0; map[5 + h * 6][25 - i - 6] = 0; map[4 + h * 6][25 - i - 6] = 0; delay(); mapping2(); break;
		case 6:
			map[5 + (h - 1) * 6][3] = 2; map[5 + h * 6][3] = 2;  map[5 + (h - 1) * 6][25 - i - 7] = 1; map[4 + (h - 1) * 6][25 - i - 7] = 1; map[5 + h * 6][25 - i - 7] = 1; map[4 + h * 6][25 - i - 7] = 1; mapping2();
			map[5 + (h - 1) * 6][25 - i - 7] = 0; map[4 + (h - 1) * 6][25 - i - 7] = 0; map[5 + h * 6][25 - i - 7] = 0; map[4 + h * 6][25 - i - 7] = 0; delay(); mapping2(); break;
		}
		step++;
		step = step % 7;
	}
}//�Ʒ��� 2��¥��
void jump0_2_12_1(int i, int h) { // �ٲ��ٷ��� ��ֹ��� ���� �ٲ������.
	static int step = 0;
	int j = 0;
	for (j = 0; j<7; j++) {
		switch (step) {
		case 0:
			map[5 + (h - 1) * 6][3] = 2; map[5 + h * 6][3] = 2;  map[5 + (h - 1) * 6][25 - i - 1] = 1; map[4 + (h - 1) * 6][25 - i - 1] = 1; map[5 + h * 6][25 - i - 1] = 1; map[4 + h * 6][25 - i - 1] = 1; mapping2();
			map[5 + (h - 1) * 6][3] = 0; map[5 + h * 6][3] = 0;  map[5 + (h - 1) * 6][25 - i - 1] = 0; map[4 + (h - 1) * 6][25 - i - 1] = 0; map[5 + h * 6][25 - i - 1] = 0; map[4 + h * 6][25 - i - 1] = 0; delay(); mapping2(); break;
		case 1:
			map[4 + (h - 1) * 6][3] = 2; map[5 + h * 6][3] = 2;  map[5 + (h - 1) * 6][25 - i - 2] = 1; map[4 + (h - 1) * 6][25 - i - 2] = 1; map[5 + h * 6][25 - i - 2] = 1; map[4 + h * 6][25 - i - 2] = 1; mapping2();
			map[4 + (h - 1) * 6][3] = 0; map[5 + h * 6][3] = 0;  map[5 + (h - 1) * 6][25 - i - 2] = 0; map[4 + (h - 1) * 6][25 - i - 2] = 0; map[5 + h * 6][25 - i - 2] = 0; map[4 + h * 6][25 - i - 2] = 0; delay(); mapping2(); break;
		case 2:
			map[3 + (h - 1) * 6][3] = 2; map[5 + h * 6][3] = 2;  map[5 + (h - 1) * 6][25 - i - 3] = 1; map[4 + (h - 1) * 6][25 - i - 3] = 1; map[5 + h * 6][25 - i - 3] = 1; map[4 + h * 6][25 - i - 3] = 1; mapping2();
			map[3 + (h - 1) * 6][3] = 0; map[5 + h * 6][3] = 0;  map[5 + (h - 1) * 6][25 - i - 3] = 0; map[4 + (h - 1) * 6][25 - i - 3] = 0; map[5 + h * 6][25 - i - 3] = 0; map[4 + h * 6][25 - i - 3] = 0; delay(); mapping2(); break;
		case 3:
			map[2 + (h - 1) * 6][3] = 2; map[5 + h * 6][3] = 2;  map[5 + (h - 1) * 6][25 - i - 4] = 1; map[4 + (h - 1) * 6][25 - i - 4] = 1; map[5 + h * 6][25 - i - 4] = 1; map[4 + h * 6][25 - i - 4] = 1; mapping2();
			map[2 + (h - 1) * 6][3] = 0; map[5 + h * 6][3] = 0;  map[5 + (h - 1) * 6][25 - i - 4] = 0; map[4 + (h - 1) * 6][25 - i - 4] = 0; map[5 + h * 6][25 - i - 4] = 0; map[4 + h * 6][25 - i - 4] = 0; delay(); mapping2(); break;
		case 4:
			map[3 + (h - 1) * 6][3] = 2; map[5 + h * 6][3] = 2;  map[5 + (h - 1) * 6][25 - i - 5] = 1; map[4 + (h - 1) * 6][25 - i - 5] = 1; map[5 + h * 6][25 - i - 5] = 1; map[4 + h * 6][25 - i - 5] = 1; mapping2();
			map[3 + (h - 1) * 6][3] = 0; map[5 + h * 6][3] = 0;  map[5 + (h - 1) * 6][25 - i - 5] = 0; map[4 + (h - 1) * 6][25 - i - 5] = 0; map[5 + h * 6][25 - i - 5] = 0; map[4 + h * 6][25 - i - 5] = 0; delay(); mapping2(); break;
		case 5:
			map[4 + (h - 1) * 6][3] = 2; map[5 + h * 6][3] = 2;  map[5 + (h - 1) * 6][25 - i - 6] = 1; map[4 + (h - 1) * 6][25 - i - 6] = 1; map[5 + h * 6][25 - i - 6] = 1; map[4 + h * 6][25 - i - 6] = 1; mapping2();
			map[4 + (h - 1) * 6][3] = 0; map[5 + h * 6][3] = 0;  map[5 + (h - 1) * 6][25 - i - 6] = 0; map[4 + (h - 1) * 6][25 - i - 6] = 0; map[5 + h * 6][25 - i - 6] = 0; map[4 + h * 6][25 - i - 6] = 0; delay(); mapping2(); break;
		case 6:
			map[5 + (h - 1) * 6][3] = 2; map[5 + h * 6][3] = 2;  map[5 + (h - 1) * 6][25 - i - 7] = 1; map[4 + (h - 1) * 6][25 - i - 7] = 1; map[5 + h * 6][25 - i - 7] = 1; map[4 + h * 6][25 - i - 7] = 1; mapping2();
			map[5 + (h - 1) * 6][25 - i - 7] = 0; map[4 + (h - 1) * 6][25 - i - 7] = 0; map[5 + h * 6][25 - i - 7] = 0; map[4 + h * 6][25 - i - 7] = 0; delay(); mapping2(); break;
		}
		step++;
		step = step % 7;
	}
}//�Ʒ��� 2��¥��
void jump0_2_12_2(int i, int h) { // �ٲ��ٷ��� ��ֹ��� ���� �ٲ������.
	static int step = 0;
	int j = 0;
	for (j = 0; j<7; j++) {
		switch (step) {
		case 0:
			map[5 + (h - 1) * 6][3] = 2; map[5 + h * 6][3] = 2;  map[5 + (h - 1) * 6][25 - i - 1] = 1; map[4 + (h - 1) * 6][25 - i - 1] = 1; map[5 + h * 6][25 - i - 1] = 1; map[4 + h * 6][25 - i - 1] = 1; mapping2();
			map[5 + (h - 1) * 6][3] = 0; map[5 + h * 6][3] = 0;  map[5 + (h - 1) * 6][25 - i - 1] = 0; map[4 + (h - 1) * 6][25 - i - 1] = 0; map[5 + h * 6][25 - i - 1] = 0; map[4 + h * 6][25 - i - 1] = 0; delay(); mapping2(); break;
		case 1:
			map[5 + (h - 1) * 6][3] = 2; map[4 + h * 6][3] = 2;  map[5 + (h - 1) * 6][25 - i - 2] = 1; map[4 + (h - 1) * 6][25 - i - 2] = 1; map[5 + h * 6][25 - i - 2] = 1; map[4 + h * 6][25 - i - 2] = 1; mapping2();
			map[5 + (h - 1) * 6][3] = 0; map[4 + h * 6][3] = 0;  map[5 + (h - 1) * 6][25 - i - 2] = 0; map[4 + (h - 1) * 6][25 - i - 2] = 0; map[5 + h * 6][25 - i - 2] = 0; map[4 + h * 6][25 - i - 2] = 0; delay(); mapping2(); break;
		case 2:
			map[5 + (h - 1) * 6][3] = 2; map[3 + h * 6][3] = 2;  map[5 + (h - 1) * 6][25 - i - 3] = 1; map[4 + (h - 1) * 6][25 - i - 3] = 1; map[5 + h * 6][25 - i - 3] = 1; map[4 + h * 6][25 - i - 3] = 1; mapping2();
			map[5 + (h - 1) * 6][3] = 0; map[3 + h * 6][3] = 0;  map[5 + (h - 1) * 6][25 - i - 3] = 0; map[4 + (h - 1) * 6][25 - i - 3] = 0; map[5 + h * 6][25 - i - 3] = 0; map[4 + h * 6][25 - i - 3] = 0; delay(); mapping2(); break;
		case 3:
			map[5 + (h - 1) * 6][3] = 2; map[2 + h * 6][3] = 2;  map[5 + (h - 1) * 6][25 - i - 4] = 1; map[4 + (h - 1) * 6][25 - i - 4] = 1; map[5 + h * 6][25 - i - 4] = 1; map[4 + h * 6][25 - i - 4] = 1; mapping2();
			map[5 + (h - 1) * 6][3] = 0; map[2 + h * 6][3] = 0;  map[5 + (h - 1) * 6][25 - i - 4] = 0; map[4 + (h - 1) * 6][25 - i - 4] = 0; map[5 + h * 6][25 - i - 4] = 0; map[4 + h * 6][25 - i - 4] = 0; delay(); mapping2(); break;
		case 4:
			map[5 + (h - 1) * 6][3] = 2; map[3 + h * 6][3] = 2;  map[5 + (h - 1) * 6][25 - i - 5] = 1; map[4 + (h - 1) * 6][25 - i - 5] = 1; map[5 + h * 6][25 - i - 5] = 1; map[4 + h * 6][25 - i - 5] = 1; mapping2();
			map[5 + (h - 1) * 6][3] = 0; map[3 + h * 6][3] = 0;  map[5 + (h - 1) * 6][25 - i - 5] = 0; map[4 + (h - 1) * 6][25 - i - 5] = 0; map[5 + h * 6][25 - i - 5] = 0; map[4 + h * 6][25 - i - 5] = 0; delay(); mapping2(); break;
		case 5:
			map[5 + (h - 1) * 6][3] = 2; map[4 + h * 6][3] = 2;  map[5 + (h - 1) * 6][25 - i - 6] = 1; map[4 + (h - 1) * 6][25 - i - 6] = 1; map[5 + h * 6][25 - i - 6] = 1; map[4 + h * 6][25 - i - 6] = 1; mapping2();
			map[5 + (h - 1) * 6][3] = 0; map[4 + h * 6][3] = 0;  map[5 + (h - 1) * 6][25 - i - 6] = 0; map[4 + (h - 1) * 6][25 - i - 6] = 0; map[5 + h * 6][25 - i - 6] = 0; map[4 + h * 6][25 - i - 6] = 0; delay(); mapping2(); break;
		case 6:
			map[5 + (h - 1) * 6][3] = 2; map[5 + h * 6][3] = 2;  map[5 + (h - 1) * 6][25 - i - 7] = 1; map[4 + (h - 1) * 6][25 - i - 7] = 1; map[5 + h * 6][25 - i - 7] = 1; map[4 + h * 6][25 - i - 7] = 1; mapping2();
			map[5 + (h - 1) * 6][25 - i - 7] = 0; map[4 + (h - 1) * 6][25 - i - 7] = 0; map[5 + h * 6][25 - i - 7] = 0; map[4 + h * 6][25 - i - 7] = 0; delay(); mapping2(); break;
		}
		step++;
		step = step % 7;
	}
}//�Ʒ��� 2��¥��
void jump0_2_13(int i, int h) { // �ٲ��ٷ��� ��ֹ��� ���� �ٲ������.
	static int step = 0;
	int j = 0;
	for (j = 0; j<7; j++) {
		switch (step) {
		case 0:
			map[5 + (h - 1) * 6][3] = 2; map[5 + (h + 1) * 6][3] = 2;  map[5 + (h - 1) * 6][25 - i - 1] = 1; map[4 + (h - 1) * 6][25 - i - 1] = 1; map[5 + (h + 1) * 6][25 - i - 1] = 1; map[4 + (h + 1) * 6][25 - i - 1] = 1; mapping2();
			map[5 + (h - 1) * 6][3] = 0; map[5 + (h + 1) * 6][3] = 0;  map[5 + (h - 1) * 6][25 - i - 1] = 0; map[4 + (h - 1) * 6][25 - i - 1] = 0; map[5 + (h + 1) * 6][25 - i - 1] = 0; map[4 + (h + 1) * 6][25 - i - 1] = 0; delay(); mapping2(); break;
		case 1:
			map[4 + (h - 1) * 6][3] = 2; map[4 + (h + 1) * 6][3] = 2;  map[5 + (h - 1) * 6][25 - i - 2] = 1; map[4 + (h - 1) * 6][25 - i - 2] = 1; map[5 + (h + 1) * 6][25 - i - 2] = 1; map[4 + (h + 1) * 6][25 - i - 2] = 1; mapping2();
			map[4 + (h - 1) * 6][3] = 0; map[4 + (h + 1) * 6][3] = 0;  map[5 + (h - 1) * 6][25 - i - 2] = 0; map[4 + (h - 1) * 6][25 - i - 2] = 0; map[5 + (h + 1) * 6][25 - i - 2] = 0; map[4 + (h + 1) * 6][25 - i - 2] = 0; delay(); mapping2(); break;
		case 2:
			map[3 + (h - 1) * 6][3] = 2; map[3 + (h + 1) * 6][3] = 2;  map[5 + (h - 1) * 6][25 - i - 3] = 1; map[4 + (h - 1) * 6][25 - i - 3] = 1; map[5 + (h + 1) * 6][25 - i - 3] = 1; map[4 + (h + 1) * 6][25 - i - 3] = 1; mapping2();
			map[3 + (h - 1) * 6][3] = 0; map[3 + (h + 1) * 6][3] = 0;  map[5 + (h - 1) * 6][25 - i - 3] = 0; map[4 + (h - 1) * 6][25 - i - 3] = 0; map[5 + (h + 1) * 6][25 - i - 3] = 0; map[4 + (h + 1) * 6][25 - i - 3] = 0; delay(); mapping2(); break;
		case 3:
			map[2 + (h - 1) * 6][3] = 2; map[2 + (h + 1) * 6][3] = 2;  map[5 + (h - 1) * 6][25 - i - 4] = 1; map[4 + (h - 1) * 6][25 - i - 4] = 1; map[5 + (h + 1) * 6][25 - i - 4] = 1; map[4 + (h + 1) * 6][25 - i - 4] = 1; mapping2();
			map[2 + (h - 1) * 6][3] = 0; map[2 + (h + 1) * 6][3] = 0;  map[5 + (h - 1) * 6][25 - i - 4] = 0; map[4 + (h - 1) * 6][25 - i - 4] = 0; map[5 + (h + 1) * 6][25 - i - 4] = 0; map[4 + (h + 1) * 6][25 - i - 4] = 0; delay(); mapping2(); break;
		case 4:
			map[3 + (h - 1) * 6][3] = 2; map[3 + (h + 1) * 6][3] = 2;  map[5 + (h - 1) * 6][25 - i - 5] = 1; map[4 + (h - 1) * 6][25 - i - 5] = 1; map[5 + (h + 1) * 6][25 - i - 5] = 1; map[4 + (h + 1) * 6][25 - i - 5] = 1; mapping2();
			map[3 + (h - 1) * 6][3] = 0; map[3 + (h + 1) * 6][3] = 0;  map[5 + (h - 1) * 6][25 - i - 5] = 0; map[4 + (h - 1) * 6][25 - i - 5] = 0; map[5 + (h + 1) * 6][25 - i - 5] = 0; map[4 + (h + 1) * 6][25 - i - 5] = 0; delay(); mapping2(); break;
		case 5:
			map[4 + (h - 1) * 6][3] = 2; map[4 + (h + 1) * 6][3] = 2;  map[5 + (h - 1) * 6][25 - i - 6] = 1; map[4 + (h - 1) * 6][25 - i - 6] = 1; map[5 + (h + 1) * 6][25 - i - 6] = 1; map[4 + (h + 1) * 6][25 - i - 6] = 1; mapping2();
			map[4 + (h - 1) * 6][3] = 0; map[4 + (h + 1) * 6][3] = 0;  map[5 + (h - 1) * 6][25 - i - 6] = 0; map[4 + (h - 1) * 6][25 - i - 6] = 0; map[5 + (h + 1) * 6][25 - i - 6] = 0; map[4 + (h + 1) * 6][25 - i - 6] = 0; delay(); mapping2(); break;
		case 6:
			map[5 + (h - 1) * 6][3] = 2; map[5 + (h + 1) * 6][3] = 2;  map[5 + (h - 1) * 6][25 - i - 7] = 1; map[4 + (h - 1) * 6][25 - i - 7] = 1; map[5 + (h + 1) * 6][25 - i - 7] = 1; map[4 + (h + 1) * 6][25 - i - 7] = 1; mapping2();
			map[5 + (h - 1) * 6][25 - i - 7] = 0; map[4 + (h - 1) * 6][25 - i - 7] = 0; map[5 + (h + 1) * 6][25 - i - 7] = 0; map[4 + (h + 1) * 6][25 - i - 7] = 0; delay(); mapping2(); break;
		}
		step++;
		step = step % 7;
	}
}//�Ʒ��� 2��¥��
void jump0_2_13_1(int i, int h) { // �ٲ��ٷ��� ��ֹ��� ���� �ٲ������.
	static int step = 0;
	int j = 0;
	for (j = 0; j<7; j++) {
		switch (step) {
		case 0:
			map[5 + (h - 1) * 6][3] = 2; map[5 + (h + 1) * 6][3] = 2;  map[5 + (h - 1) * 6][25 - i - 1] = 1; map[4 + (h - 1) * 6][25 - i - 1] = 1; map[5 + (h + 1) * 6][25 - i - 1] = 1; map[4 + (h + 1) * 6][25 - i - 1] = 1; mapping2();
			map[5 + (h - 1) * 6][3] = 0; map[5 + (h + 1) * 6][3] = 0;  map[5 + (h - 1) * 6][25 - i - 1] = 0; map[4 + (h - 1) * 6][25 - i - 1] = 0; map[5 + (h + 1) * 6][25 - i - 1] = 0; map[4 + (h + 1) * 6][25 - i - 1] = 0; delay(); mapping2(); break;
		case 1:
			map[4 + (h - 1) * 6][3] = 2; map[5 + (h + 1) * 6][3] = 2;  map[5 + (h - 1) * 6][25 - i - 2] = 1; map[4 + (h - 1) * 6][25 - i - 2] = 1; map[5 + (h + 1) * 6][25 - i - 2] = 1; map[4 + (h + 1) * 6][25 - i - 2] = 1; mapping2();
			map[4 + (h - 1) * 6][3] = 0; map[5 + (h + 1) * 6][3] = 0;  map[5 + (h - 1) * 6][25 - i - 2] = 0; map[4 + (h - 1) * 6][25 - i - 2] = 0; map[5 + (h + 1) * 6][25 - i - 2] = 0; map[4 + (h + 1) * 6][25 - i - 2] = 0; delay(); mapping2(); break;
		case 2:
			map[3 + (h - 1) * 6][3] = 2; map[5 + (h + 1) * 6][3] = 2;  map[5 + (h - 1) * 6][25 - i - 3] = 1; map[4 + (h - 1) * 6][25 - i - 3] = 1; map[5 + (h + 1) * 6][25 - i - 3] = 1; map[4 + (h + 1) * 6][25 - i - 3] = 1; mapping2();
			map[3 + (h - 1) * 6][3] = 0; map[5 + (h + 1) * 6][3] = 0;  map[5 + (h - 1) * 6][25 - i - 3] = 0; map[4 + (h - 1) * 6][25 - i - 3] = 0; map[5 + (h + 1) * 6][25 - i - 3] = 0; map[4 + (h + 1) * 6][25 - i - 3] = 0; delay(); mapping2(); break;
		case 3:
			map[2 + (h - 1) * 6][3] = 2; map[5 + (h + 1) * 6][3] = 2;  map[5 + (h - 1) * 6][25 - i - 4] = 1; map[4 + (h - 1) * 6][25 - i - 4] = 1; map[5 + (h + 1) * 6][25 - i - 4] = 1; map[4 + (h + 1) * 6][25 - i - 4] = 1; mapping2();
			map[2 + (h - 1) * 6][3] = 0; map[5 + (h + 1) * 6][3] = 0;  map[5 + (h - 1) * 6][25 - i - 4] = 0; map[4 + (h - 1) * 6][25 - i - 4] = 0; map[5 + (h + 1) * 6][25 - i - 4] = 0; map[4 + (h + 1) * 6][25 - i - 4] = 0; delay(); mapping2(); break;
		case 4:
			map[3 + (h - 1) * 6][3] = 2; map[5 + (h + 1) * 6][3] = 2;  map[5 + (h - 1) * 6][25 - i - 5] = 1; map[4 + (h - 1) * 6][25 - i - 5] = 1; map[5 + (h + 1) * 6][25 - i - 5] = 1; map[4 + (h + 1) * 6][25 - i - 5] = 1; mapping2();
			map[3 + (h - 1) * 6][3] = 0; map[5 + (h + 1) * 6][3] = 0;  map[5 + (h - 1) * 6][25 - i - 5] = 0; map[4 + (h - 1) * 6][25 - i - 5] = 0; map[5 + (h + 1) * 6][25 - i - 5] = 0; map[4 + (h + 1) * 6][25 - i - 5] = 0; delay(); mapping2(); break;
		case 5:
			map[4 + (h - 1) * 6][3] = 2; map[5 + (h + 1) * 6][3] = 2;  map[5 + (h - 1) * 6][25 - i - 6] = 1; map[4 + (h - 1) * 6][25 - i - 6] = 1; map[5 + (h + 1) * 6][25 - i - 6] = 1; map[4 + (h + 1) * 6][25 - i - 6] = 1; mapping2();
			map[4 + (h - 1) * 6][3] = 0; map[5 + (h + 1) * 6][3] = 0;  map[5 + (h - 1) * 6][25 - i - 6] = 0; map[4 + (h - 1) * 6][25 - i - 6] = 0; map[5 + (h + 1) * 6][25 - i - 6] = 0; map[4 + (h + 1) * 6][25 - i - 6] = 0; delay(); mapping2(); break;
		case 6:
			map[5 + (h - 1) * 6][3] = 2; map[5 + (h + 1) * 6][3] = 2;  map[5 + (h - 1) * 6][25 - i - 7] = 1; map[4 + (h - 1) * 6][25 - i - 7] = 1; map[5 + (h + 1) * 6][25 - i - 7] = 1; map[4 + (h + 1) * 6][25 - i - 7] = 1; mapping2();
			map[5 + (h - 1) * 6][25 - i - 7] = 0; map[4 + (h - 1) * 6][25 - i - 7] = 0; map[5 + (h + 1) * 6][25 - i - 7] = 0; map[4 + (h + 1) * 6][25 - i - 7] = 0; delay(); mapping2(); break;
		}
		step++;
		step = step % 7;
	}
}//�Ʒ��� 2��¥��
void jump0_2_13_2(int i, int h) { // �ٲ��ٷ��� ��ֹ��� ���� �ٲ������.
	static int step = 0;
	int j = 0;
	for (j = 0; j<7; j++) {
		switch (step) {
		case 0:
			map[5 + (h - 1) * 6][3] = 2; map[5 + (h + 1) * 6][3] = 2;  map[5 + (h - 1) * 6][25 - i - 1] = 1; map[4 + (h - 1) * 6][25 - i - 1] = 1; map[5 + (h + 1) * 6][25 - i - 1] = 1; map[4 + (h + 1) * 6][25 - i - 1] = 1; mapping2();
			map[5 + (h - 1) * 6][3] = 0; map[5 + (h + 1) * 6][3] = 0;  map[5 + (h - 1) * 6][25 - i - 1] = 0; map[4 + (h - 1) * 6][25 - i - 1] = 0; map[5 + (h + 1) * 6][25 - i - 1] = 0; map[4 + (h + 1) * 6][25 - i - 1] = 0; delay(); mapping2(); break;
		case 1:
			map[5 + (h - 1) * 6][3] = 2; map[4 + (h + 1) * 6][3] = 2;  map[5 + (h - 1) * 6][25 - i - 2] = 1; map[4 + (h - 1) * 6][25 - i - 2] = 1; map[5 + (h + 1) * 6][25 - i - 2] = 1; map[4 + (h + 1) * 6][25 - i - 2] = 1; mapping2();
			map[5 + (h - 1) * 6][3] = 0; map[4 + (h + 1) * 6][3] = 0;  map[5 + (h - 1) * 6][25 - i - 2] = 0; map[4 + (h - 1) * 6][25 - i - 2] = 0; map[5 + (h + 1) * 6][25 - i - 2] = 0; map[4 + (h + 1) * 6][25 - i - 2] = 0; delay(); mapping2(); break;
		case 2:
			map[5 + (h - 1) * 6][3] = 2; map[3 + (h + 1) * 6][3] = 2;  map[5 + (h - 1) * 6][25 - i - 3] = 1; map[4 + (h - 1) * 6][25 - i - 3] = 1; map[5 + (h + 1) * 6][25 - i - 3] = 1; map[4 + (h + 1) * 6][25 - i - 3] = 1; mapping2();
			map[5 + (h - 1) * 6][3] = 0; map[3 + (h + 1) * 6][3] = 0;  map[5 + (h - 1) * 6][25 - i - 3] = 0; map[4 + (h - 1) * 6][25 - i - 3] = 0; map[5 + (h + 1) * 6][25 - i - 3] = 0; map[4 + (h + 1) * 6][25 - i - 3] = 0; mapping2(); delay(); mapping2(); break;
		case 3:
			map[5 + (h - 1) * 6][3] = 2; map[2 + (h + 1) * 6][3] = 2;  map[5 + (h - 1) * 6][25 - i - 4] = 1; map[4 + (h - 1) * 6][25 - i - 4] = 1; map[5 + (h + 1) * 6][25 - i - 4] = 1; map[4 + (h + 1) * 6][25 - i - 4] = 1; mapping2();
			map[5 + (h - 1) * 6][3] = 0; map[2 + (h + 1) * 6][3] = 0;  map[5 + (h - 1) * 6][25 - i - 4] = 0; map[4 + (h - 1) * 6][25 - i - 4] = 0; map[5 + (h + 1) * 6][25 - i - 4] = 0; map[4 + (h + 1) * 6][25 - i - 4] = 0; delay(); mapping2(); break;
		case 4:
			map[5 + (h - 1) * 6][3] = 2; map[3 + (h + 1) * 6][3] = 2;  map[5 + (h - 1) * 6][25 - i - 5] = 1; map[4 + (h - 1) * 6][25 - i - 5] = 1; map[5 + (h + 1) * 6][25 - i - 5] = 1; map[4 + (h + 1) * 6][25 - i - 5] = 1; mapping2();
			map[5 + (h - 1) * 6][3] = 0; map[3 + (h + 1) * 6][3] = 0;  map[5 + (h - 1) * 6][25 - i - 5] = 0; map[4 + (h - 1) * 6][25 - i - 5] = 0; map[5 + (h + 1) * 6][25 - i - 5] = 0; map[4 + (h + 1) * 6][25 - i - 5] = 0; delay(); mapping2(); break;
		case 5:
			map[5 + (h - 1) * 6][3] = 2; map[4 + (h + 1) * 6][3] = 2;  map[5 + (h - 1) * 6][25 - i - 6] = 1; map[4 + (h - 1) * 6][25 - i - 6] = 1; map[5 + (h + 1) * 6][25 - i - 6] = 1; map[4 + (h + 1) * 6][25 - i - 6] = 1; mapping2();
			map[5 + (h - 1) * 6][3] = 0; map[4 + (h + 1) * 6][3] = 0;  map[5 + (h - 1) * 6][25 - i - 6] = 0; map[4 + (h - 1) * 6][25 - i - 6] = 0; map[5 + (h + 1) * 6][25 - i - 6] = 0; map[4 + (h + 1) * 6][25 - i - 6] = 0; delay(); mapping2(); break;
		case 6:
			map[5 + (h - 1) * 6][3] = 2; map[5 + (h + 1) * 6][3] = 2;  map[5 + (h - 1) * 6][25 - i - 7] = 1; map[4 + (h - 1) * 6][25 - i - 7] = 1; map[5 + (h + 1) * 6][25 - i - 7] = 1; map[4 + (h + 1) * 6][25 - i - 7] = 1; mapping2();
			map[5 + (h - 1) * 6][25 - i - 7] = 0; map[4 + (h - 1) * 6][25 - i - 7] = 0; map[5 + (h + 1) * 6][25 - i - 7] = 0; map[4 + (h + 1) * 6][25 - i - 7] = 0; delay(); mapping2(); break;
		}
		step++;
		step = step % 7;
	}
}//�Ʒ��� 2��¥��

void jump3_0(int i, int h) {
	static int step = 0;
	int j = 0;
	for (j = 0; j<7; j++) {
		switch (step) {
		case 0:
			map[5 + (h - 1) * 6][3] = 2; map[3 + (h - 1) * 6][25 - i - 1] = 1; map[2 + (h - 1) * 6][25 - i - 1] = 1; map[1 + (h - 1) * 6][25 - i - 1] = 1; mapping2();
			map[5 + (h - 1) * 6][3] = 0; map[3 + (h - 1) * 6][25 - i - 1] = 0; map[2 + (h - 1) * 6][25 - i - 1] = 0; map[1 + (h - 1) * 6][25 - i - 1] = 0; delay(); mapping2(); break;
		case 1:
			map[4 + (h - 1) * 6][3] = 2; map[3 + (h - 1) * 6][25 - i - 2] = 1; map[2 + (h - 1) * 6][25 - i - 2] = 1; map[1 + (h - 1) * 6][25 - i - 2] = 1; mapping2();
			map[4 + (h - 1) * 6][3] = 0; map[3 + (h - 1) * 6][25 - i - 2] = 0; map[2 + (h - 1) * 6][25 - i - 2] = 0; map[1 + (h - 1) * 6][25 - i - 2] = 0; delay(); mapping2(); break;
		case 2:
			map[3 + (h - 1) * 6][3] = 2; map[3 + (h - 1) * 6][25 - i - 3] = 1; map[2 + (h - 1) * 6][25 - i - 3] = 1; map[1 + (h - 1) * 6][25 - i - 3] = 1; mapping2();
			map[3 + (h - 1) * 6][3] = 0; map[3 + (h - 1) * 6][25 - i - 3] = 0; map[2 + (h - 1) * 6][25 - i - 3] = 0; map[1 + (h - 1) * 6][25 - i - 3] = 0; delay(); mapping2(); break;
		case 3:
			map[2 + (h - 1) * 6][3] = 2; map[3 + (h - 1) * 6][25 - i - 4] = 1; map[2 + (h - 1) * 6][25 - i - 4] = 1; map[1 + (h - 1) * 6][25 - i - 4] = 1; mapping2();
			map[2 + (h - 1) * 6][3] = 0; map[3 + (h - 1) * 6][25 - i - 4] = 0; map[2 + (h - 1) * 6][25 - i - 4] = 0; map[1 + (h - 1) * 6][25 - i - 4] = 0; delay(); mapping2(); break;
		case 4:
			map[3 + (h - 1) * 6][3] = 2; map[3 + (h - 1) * 6][25 - i - 5] = 1; map[2 + (h - 1) * 6][25 - i - 5] = 1; map[1 + (h - 1) * 6][25 - i - 5] = 1; mapping2();
			map[3 + (h - 1) * 6][3] = 0; map[3 + (h - 1) * 6][25 - i - 5] = 0; map[2 + (h - 1) * 6][25 - i - 5] = 0; map[1 + (h - 1) * 6][25 - i - 5] = 0; delay(); mapping2(); break;
		case 5:
			map[4 + (h - 1) * 6][3] = 2; map[3 + (h - 1) * 6][25 - i - 6] = 1; map[2 + (h - 1) * 6][25 - i - 6] = 1; map[1 + (h - 1) * 6][25 - i - 6] = 1; mapping2();
			map[4 + (h - 1) * 6][3] = 0; map[3 + (h - 1) * 6][25 - i - 6] = 0; map[2 + (h - 1) * 6][25 - i - 6] = 0; map[1 + (h - 1) * 6][25 - i - 6] = 0; delay(); mapping2(); break;
		case 6:
			map[5 + (h - 1) * 6][3] = 2; map[3 + (h - 1) * 6][25 - i - 7] = 1; map[2 + (h - 1) * 6][25 - i - 7] = 1; map[1 + (h - 1) * 6][25 - i - 7] = 1; mapping2();
			map[3 + (h - 1) * 6][25 - i - 7] = 0; map[2 + (h - 1) * 6][25 - i - 7] = 0; map[1 + (h - 1) * 6][25 - i - 7] = 0; delay(); mapping2(); break;
		}
		step++;
		step = step % 7;
	}
}//������ 3��¥��
void jump3_0_12(int i, int h) {
	static int step = 0;
	int j = 0;
	for (j = 0; j<7; j++) {
		switch (step) {
		case 0:
			map[5 + (h - 1) * 6][3] = 2; map[5 + h * 6][3] = 2; map[3 + (h - 1) * 6][25 - i - 1] = 1; map[2 + (h - 1) * 6][25 - i - 1] = 1; map[1 + (h - 1) * 6][25 - i - 1] = 1; map[3 + h * 6][25 - i - 1] = 1; map[2 + h * 6][25 - i - 1] = 1; map[1 + h * 6][25 - i - 1] = 1; mapping2();
			map[5 + (h - 1) * 6][3] = 0; map[5 + h * 6][3] = 0; map[3 + (h - 1) * 6][25 - i - 1] = 0; map[2 + (h - 1) * 6][25 - i - 1] = 0; map[1 + (h - 1) * 6][25 - i - 1] = 0; map[3 + h * 6][25 - i - 1] = 0; map[2 + h * 6][25 - i - 1] = 0; map[1 + h * 6][25 - i - 1] = 0; delay(); mapping2(); break;
		case 1:
			map[4 + (h - 1) * 6][3] = 2; map[4 + h * 6][3] = 2; map[3 + (h - 1) * 6][25 - i - 2] = 1; map[2 + (h - 1) * 6][25 - i - 2] = 1; map[1 + (h - 1) * 6][25 - i - 2] = 1; map[3 + h * 6][25 - i - 2] = 1; map[2 + h * 6][25 - i - 2] = 1; map[1 + h * 6][25 - i - 2] = 1; mapping2();
			map[4 + (h - 1) * 6][3] = 0; map[4 + h * 6][3] = 0; map[3 + (h - 1) * 6][25 - i - 2] = 0; map[2 + (h - 1) * 6][25 - i - 2] = 0; map[1 + (h - 1) * 6][25 - i - 2] = 0; map[3 + h * 6][25 - i - 2] = 0; map[2 + h * 6][25 - i - 2] = 0; map[1 + h * 6][25 - i - 2] = 0; delay(); mapping2(); break;
		case 2:
			map[3 + (h - 1) * 6][3] = 2; map[3 + h * 6][3] = 2; map[3 + (h - 1) * 6][25 - i - 3] = 1; map[2 + (h - 1) * 6][25 - i - 3] = 1; map[1 + (h - 1) * 6][25 - i - 3] = 1; map[3 + h * 6][25 - i - 3] = 1; map[2 + h * 6][25 - i - 3] = 1; map[1 + h * 6][25 - i - 3] = 1; mapping2();
			map[3 + (h - 1) * 6][3] = 0; map[3 + h * 6][3] = 0; map[3 + (h - 1) * 6][25 - i - 3] = 0; map[2 + (h - 1) * 6][25 - i - 3] = 0; map[1 + (h - 1) * 6][25 - i - 3] = 0; map[3 + h * 6][25 - i - 3] = 0; map[2 + h * 6][25 - i - 3] = 0; map[1 + h * 6][25 - i - 3] = 0; delay(); mapping2(); break;
		case 3:
			map[2 + (h - 1) * 6][3] = 2; map[2 + h * 6][3] = 2; map[3 + (h - 1) * 6][25 - i - 4] = 1; map[2 + (h - 1) * 6][25 - i - 4] = 1; map[1 + (h - 1) * 6][25 - i - 4] = 1; map[3 + h * 6][25 - i - 4] = 1; map[2 + h * 6][25 - i - 4] = 1; map[1 + h * 6][25 - i - 4] = 1; mapping2();
			map[2 + (h - 1) * 6][3] = 0; map[2 + h * 6][3] = 0; map[3 + (h - 1) * 6][25 - i - 4] = 0; map[2 + (h - 1) * 6][25 - i - 4] = 0; map[1 + (h - 1) * 6][25 - i - 4] = 0; map[3 + h * 6][25 - i - 4] = 0; map[2 + h * 6][25 - i - 4] = 0; map[1 + h * 6][25 - i - 4] = 0; delay(); mapping2(); break;
		case 4:
			map[3 + (h - 1) * 6][3] = 2; map[3 + h * 6][3] = 2; map[3 + (h - 1) * 6][25 - i - 5] = 1; map[2 + (h - 1) * 6][25 - i - 5] = 1; map[1 + (h - 1) * 6][25 - i - 5] = 1; map[3 + h * 6][25 - i - 5] = 1; map[2 + h * 6][25 - i - 5] = 1; map[1 + h * 6][25 - i - 5] = 1; mapping2();
			map[3 + (h - 1) * 6][3] = 0; map[3 + h * 6][3] = 0; map[3 + (h - 1) * 6][25 - i - 5] = 0; map[2 + (h - 1) * 6][25 - i - 5] = 0; map[1 + (h - 1) * 6][25 - i - 5] = 0; map[3 + h * 6][25 - i - 5] = 0; map[2 + h * 6][25 - i - 5] = 0; map[1 + h * 6][25 - i - 5] = 0; delay(); mapping2(); break;
		case 5:
			map[4 + (h - 1) * 6][3] = 2; map[4 + h * 6][3] = 2; map[3 + (h - 1) * 6][25 - i - 6] = 1; map[2 + (h - 1) * 6][25 - i - 6] = 1; map[1 + (h - 1) * 6][25 - i - 6] = 1; map[3 + h * 6][25 - i - 6] = 1; map[2 + h * 6][25 - i - 6] = 1; map[1 + h * 6][25 - i - 6] = 1; mapping2();
			map[4 + (h - 1) * 6][3] = 0; map[4 + h * 6][3] = 0; map[3 + (h - 1) * 6][25 - i - 6] = 0; map[2 + (h - 1) * 6][25 - i - 6] = 0; map[1 + (h - 1) * 6][25 - i - 6] = 0; map[3 + h * 6][25 - i - 6] = 0; map[2 + h * 6][25 - i - 6] = 0; map[1 + h * 6][25 - i - 6] = 0; delay(); mapping2(); break;
		case 6:
			map[5 + (h - 1) * 6][3] = 2; map[5 + h * 6][3] = 2; map[3 + (h - 1) * 6][25 - i - 7] = 1; map[2 + (h - 1) * 6][25 - i - 7] = 1; map[1 + (h - 1) * 6][25 - i - 7] = 1; map[3 + h * 6][25 - i - 7] = 1; map[2 + h * 6][25 - i - 7] = 1; map[1 + h * 6][25 - i - 7] = 1; mapping2();
			map[3 + (h - 1) * 6][25 - i - 7] = 0; map[2 + (h - 1) * 6][25 - i - 7] = 0; map[1 + (h - 1) * 6][25 - i - 7] = 0; map[3 + h * 6][25 - i - 7] = 0; map[2 + h * 6][25 - i - 7] = 0; map[1 + h * 6][25 - i - 7] = 0; delay(); mapping2(); break;
		}
		step++;
		step = step % 7;
	}
}//������ 3��¥��
void jump3_0_12_1(int i, int h) {
	static int step = 0;
	int j = 0;
	for (j = 0; j<7; j++) {
		switch (step) {
		case 0:
			map[5 + (h - 1) * 6][3] = 2; map[5 + h * 6][3] = 2; map[3 + (h - 1) * 6][25 - i - 1] = 1; map[2 + (h - 1) * 6][25 - i - 1] = 1; map[1 + (h - 1) * 6][25 - i - 1] = 1; map[3 + h * 6][25 - i - 1] = 1; map[2 + h * 6][25 - i - 1] = 1; map[1 + h * 6][25 - i - 1] = 1; mapping2();
			map[5 + (h - 1) * 6][3] = 0; map[5 + h * 6][3] = 0; map[3 + (h - 1) * 6][25 - i - 1] = 0; map[2 + (h - 1) * 6][25 - i - 1] = 0; map[1 + (h - 1) * 6][25 - i - 1] = 0; map[3 + h * 6][25 - i - 1] = 0; map[2 + h * 6][25 - i - 1] = 0; map[1 + h * 6][25 - i - 1] = 0; delay(); mapping2(); break;
		case 1:
			map[4 + (h - 1) * 6][3] = 2; map[5 + h * 6][3] = 2; map[3 + (h - 1) * 6][25 - i - 2] = 1; map[2 + (h - 1) * 6][25 - i - 2] = 1; map[1 + (h - 1) * 6][25 - i - 2] = 1; map[3 + h * 6][25 - i - 2] = 1; map[2 + h * 6][25 - i - 2] = 1; map[1 + h * 6][25 - i - 2] = 1; mapping2();
			map[4 + (h - 1) * 6][3] = 0; map[5 + h * 6][3] = 0; map[3 + (h - 1) * 6][25 - i - 2] = 0; map[2 + (h - 1) * 6][25 - i - 2] = 0; map[1 + (h - 1) * 6][25 - i - 2] = 0; map[3 + h * 6][25 - i - 2] = 0; map[2 + h * 6][25 - i - 2] = 0; map[1 + h * 6][25 - i - 2] = 0; delay(); mapping2(); break;
		case 2:
			map[3 + (h - 1) * 6][3] = 2; map[5 + h * 6][3] = 2; map[3 + (h - 1) * 6][25 - i - 3] = 1; map[2 + (h - 1) * 6][25 - i - 3] = 1; map[1 + (h - 1) * 6][25 - i - 3] = 1; map[3 + h * 6][25 - i - 3] = 1; map[2 + h * 6][25 - i - 3] = 1; map[1 + h * 6][25 - i - 3] = 1; mapping2();
			map[3 + (h - 1) * 6][3] = 0; map[5 + h * 6][3] = 0; map[3 + (h - 1) * 6][25 - i - 3] = 0; map[2 + (h - 1) * 6][25 - i - 3] = 0; map[1 + (h - 1) * 6][25 - i - 3] = 0; map[3 + h * 6][25 - i - 3] = 0; map[2 + h * 6][25 - i - 3] = 0; map[1 + h * 6][25 - i - 3] = 0; delay(); mapping2(); break;
		case 3:
			map[2 + (h - 1) * 6][3] = 2; map[5 + h * 6][3] = 2; map[3 + (h - 1) * 6][25 - i - 4] = 1; map[2 + (h - 1) * 6][25 - i - 4] = 1; map[1 + (h - 1) * 6][25 - i - 4] = 1; map[3 + h * 6][25 - i - 4] = 1; map[2 + h * 6][25 - i - 4] = 1; map[1 + h * 6][25 - i - 4] = 1; mapping2();
			map[2 + (h - 1) * 6][3] = 0; map[5 + h * 6][3] = 0; map[3 + (h - 1) * 6][25 - i - 4] = 0; map[2 + (h - 1) * 6][25 - i - 4] = 0; map[1 + (h - 1) * 6][25 - i - 4] = 0; map[3 + h * 6][25 - i - 4] = 0; map[2 + h * 6][25 - i - 4] = 0; map[1 + h * 6][25 - i - 4] = 0; delay(); mapping2(); break;
		case 4:
			map[3 + (h - 1) * 6][3] = 2; map[5 + h * 6][3] = 2; map[3 + (h - 1) * 6][25 - i - 5] = 1; map[2 + (h - 1) * 6][25 - i - 5] = 1; map[1 + (h - 1) * 6][25 - i - 5] = 1; map[3 + h * 6][25 - i - 5] = 1; map[2 + h * 6][25 - i - 5] = 1; map[1 + h * 6][25 - i - 5] = 1; mapping2();
			map[3 + (h - 1) * 6][3] = 0; map[5 + h * 6][3] = 0; map[3 + (h - 1) * 6][25 - i - 5] = 0; map[2 + (h - 1) * 6][25 - i - 5] = 0; map[1 + (h - 1) * 6][25 - i - 5] = 0; map[3 + h * 6][25 - i - 5] = 0; map[2 + h * 6][25 - i - 5] = 0; map[1 + h * 6][25 - i - 5] = 0; delay(); mapping2(); break;
		case 5:
			map[4 + (h - 1) * 6][3] = 2; map[5 + h * 6][3] = 2; map[3 + (h - 1) * 6][25 - i - 6] = 1; map[2 + (h - 1) * 6][25 - i - 6] = 1; map[1 + (h - 1) * 6][25 - i - 6] = 1; map[3 + h * 6][25 - i - 6] = 1; map[2 + h * 6][25 - i - 6] = 1; map[1 + h * 6][25 - i - 6] = 1; mapping2();
			map[4 + (h - 1) * 6][3] = 0; map[5 + h * 6][3] = 0; map[3 + (h - 1) * 6][25 - i - 6] = 0; map[2 + (h - 1) * 6][25 - i - 6] = 0; map[1 + (h - 1) * 6][25 - i - 6] = 0; map[3 + h * 6][25 - i - 6] = 0; map[2 + h * 6][25 - i - 6] = 0; map[1 + h * 6][25 - i - 6] = 0; delay(); mapping2(); break;
		case 6:
			map[5 + (h - 1) * 6][3] = 2; map[5 + h * 6][3] = 2; map[3 + (h - 1) * 6][25 - i - 7] = 1; map[2 + (h - 1) * 6][25 - i - 7] = 1; map[1 + (h - 1) * 6][25 - i - 7] = 1; map[3 + h * 6][25 - i - 7] = 1; map[2 + h * 6][25 - i - 7] = 1; map[1 + h * 6][25 - i - 7] = 1; mapping2();
			map[3 + (h - 1) * 6][25 - i - 7] = 0; map[2 + (h - 1) * 6][25 - i - 7] = 0; map[1 + (h - 1) * 6][25 - i - 7] = 0; map[3 + h * 6][25 - i - 7] = 0; map[2 + h * 6][25 - i - 7] = 0; map[1 + h * 6][25 - i - 7] = 0; delay(); mapping2(); break;
		}
		step++;
		step = step % 7;
	}
}//������ 3��¥��
void jump3_0_12_2(int i, int h) {
	static int step = 0;
	int j = 0;
	for (j = 0; j<7; j++) {
		switch (step) {
		case 0:
			map[5 + (h - 1) * 6][3] = 2; map[5 + h * 6][3] = 2; map[3 + (h - 1) * 6][25 - i - 1] = 1; map[2 + (h - 1) * 6][25 - i - 1] = 1; map[1 + (h - 1) * 6][25 - i - 1] = 1; map[3 + h * 6][25 - i - 1] = 1; map[2 + h * 6][25 - i - 1] = 1; map[1 + h * 6][25 - i - 1] = 1; mapping2();
			map[5 + (h - 1) * 6][3] = 0; map[5 + h * 6][3] = 0; map[3 + (h - 1) * 6][25 - i - 1] = 0; map[2 + (h - 1) * 6][25 - i - 1] = 0; map[1 + (h - 1) * 6][25 - i - 1] = 0; map[3 + h * 6][25 - i - 1] = 0; map[2 + h * 6][25 - i - 1] = 0; map[1 + h * 6][25 - i - 1] = 0; delay(); mapping2(); break;
		case 1:
			map[5 + (h - 1) * 6][3] = 2; map[4 + h * 6][3] = 2; map[3 + (h - 1) * 6][25 - i - 2] = 1; map[2 + (h - 1) * 6][25 - i - 2] = 1; map[1 + (h - 1) * 6][25 - i - 2] = 1; map[3 + h * 6][25 - i - 2] = 1; map[2 + h * 6][25 - i - 2] = 1; map[1 + h * 6][25 - i - 2] = 1; mapping2();
			map[5 + (h - 1) * 6][3] = 0; map[4 + h * 6][3] = 0; map[3 + (h - 1) * 6][25 - i - 2] = 0; map[2 + (h - 1) * 6][25 - i - 2] = 0; map[1 + (h - 1) * 6][25 - i - 2] = 0; map[3 + h * 6][25 - i - 2] = 0; map[2 + h * 6][25 - i - 2] = 0; map[1 + h * 6][25 - i - 2] = 0; delay(); mapping2(); break;
		case 2:
			map[5 + (h - 1) * 6][3] = 2; map[3 + h * 6][3] = 2; map[3 + (h - 1) * 6][25 - i - 3] = 1; map[2 + (h - 1) * 6][25 - i - 3] = 1; map[1 + (h - 1) * 6][25 - i - 3] = 1; map[3 + h * 6][25 - i - 3] = 1; map[2 + h * 6][25 - i - 3] = 1; map[1 + h * 6][25 - i - 3] = 1; mapping2();
			map[5 + (h - 1) * 6][3] = 0; map[3 + h * 6][3] = 0; map[3 + (h - 1) * 6][25 - i - 3] = 0; map[2 + (h - 1) * 6][25 - i - 3] = 0; map[1 + (h - 1) * 6][25 - i - 3] = 0; map[3 + h * 6][25 - i - 3] = 0; map[2 + h * 6][25 - i - 3] = 0; map[1 + h * 6][25 - i - 3] = 0; delay(); mapping2(); break;
		case 3:
			map[5 + (h - 1) * 6][3] = 2; map[2 + h * 6][3] = 2; map[3 + (h - 1) * 6][25 - i - 4] = 1; map[2 + (h - 1) * 6][25 - i - 4] = 1; map[1 + (h - 1) * 6][25 - i - 4] = 1; map[3 + h * 6][25 - i - 4] = 1; map[2 + h * 6][25 - i - 4] = 1; map[1 + h * 6][25 - i - 4] = 1; mapping2();
			map[5 + (h - 1) * 6][3] = 0; map[2 + h * 6][3] = 0; map[3 + (h - 1) * 6][25 - i - 4] = 0; map[2 + (h - 1) * 6][25 - i - 4] = 0; map[1 + (h - 1) * 6][25 - i - 4] = 0; map[3 + h * 6][25 - i - 4] = 0; map[2 + h * 6][25 - i - 4] = 0; map[1 + h * 6][25 - i - 4] = 0; delay(); mapping2(); break;
		case 4:
			map[5 + (h - 1) * 6][3] = 2; map[3 + h * 6][3] = 2; map[3 + (h - 1) * 6][25 - i - 5] = 1; map[2 + (h - 1) * 6][25 - i - 5] = 1; map[1 + (h - 1) * 6][25 - i - 5] = 1; map[3 + h * 6][25 - i - 5] = 1; map[2 + h * 6][25 - i - 5] = 1; map[1 + h * 6][25 - i - 5] = 1; mapping2();
			map[5 + (h - 1) * 6][3] = 0; map[3 + h * 6][3] = 0; map[3 + (h - 1) * 6][25 - i - 5] = 0; map[2 + (h - 1) * 6][25 - i - 5] = 0; map[1 + (h - 1) * 6][25 - i - 5] = 0; map[3 + h * 6][25 - i - 5] = 0; map[2 + h * 6][25 - i - 5] = 0; map[1 + h * 6][25 - i - 5] = 0; delay(); mapping2(); break;
		case 5:
			map[5 + (h - 1) * 6][3] = 2; map[4 + h * 6][3] = 2; map[3 + (h - 1) * 6][25 - i - 6] = 1; map[2 + (h - 1) * 6][25 - i - 6] = 1; map[1 + (h - 1) * 6][25 - i - 6] = 1; map[3 + h * 6][25 - i - 6] = 1; map[2 + h * 6][25 - i - 6] = 1; map[1 + h * 6][25 - i - 6] = 1; mapping2();
			map[5 + (h - 1) * 6][3] = 0; map[4 + h * 6][3] = 0; map[3 + (h - 1) * 6][25 - i - 6] = 0; map[2 + (h - 1) * 6][25 - i - 6] = 0; map[1 + (h - 1) * 6][25 - i - 6] = 0; map[3 + h * 6][25 - i - 6] = 0; map[2 + h * 6][25 - i - 6] = 0; map[1 + h * 6][25 - i - 6] = 0; delay(); mapping2(); break;
		case 6:
			map[5 + (h - 1) * 6][3] = 2; map[5 + h * 6][3] = 2; map[3 + (h - 1) * 6][25 - i - 7] = 1; map[2 + (h - 1) * 6][25 - i - 7] = 1; map[1 + (h - 1) * 6][25 - i - 7] = 1; map[3 + h * 6][25 - i - 7] = 1; map[2 + h * 6][25 - i - 7] = 1; map[1 + h * 6][25 - i - 7] = 1; mapping2();
			map[3 + (h - 1) * 6][25 - i - 7] = 0; map[2 + (h - 1) * 6][25 - i - 7] = 0; map[1 + (h - 1) * 6][25 - i - 7] = 0; map[3 + h * 6][25 - i - 7] = 0; map[2 + h * 6][25 - i - 7] = 0; map[1 + h * 6][25 - i - 7] = 0; delay(); mapping2(); break;
		}
		step++;
		step = step % 7;
	}
}//������ 3��¥��
void jump3_0_13(int i, int h) {
	static int step = 0;
	int j = 0;
	for (j = 0; j<7; j++) {
		switch (step) {
		case 0:
			map[5 + (h - 1) * 6][3] = 2; map[5 + (h + 1) * 6][3] = 2; map[3 + (h - 1) * 6][25 - i - 1] = 1; map[2 + (h - 1) * 6][25 - i - 1] = 1; map[1 + (h - 1) * 6][25 - i - 1] = 1; map[3 + (h + 1) * 6][25 - i - 1] = 1; map[2 + (h + 1) * 6][25 - i - 1] = 1; map[1 + (h + 1) * 6][25 - i - 1] = 1; mapping2();
			map[5 + (h - 1) * 6][3] = 0; map[5 + (h + 1) * 6][3] = 0; map[3 + (h - 1) * 6][25 - i - 1] = 0; map[2 + (h - 1) * 6][25 - i - 1] = 0; map[1 + (h - 1) * 6][25 - i - 1] = 0; map[3 + (h + 1) * 6][25 - i - 1] = 0; map[2 + (h + 1) * 6][25 - i - 1] = 0; map[1 + (h + 1) * 6][25 - i - 1] = 0; delay(); mapping2(); break;
		case 1:
			map[4 + (h - 1) * 6][3] = 2; map[4 + (h + 1) * 6][3] = 2; map[3 + (h - 1) * 6][25 - i - 2] = 1; map[2 + (h - 1) * 6][25 - i - 2] = 1; map[1 + (h - 1) * 6][25 - i - 2] = 1; map[3 + (h + 1) * 6][25 - i - 2] = 1; map[2 + (h + 1) * 6][25 - i - 2] = 1; map[1 + (h + 1) * 6][25 - i - 2] = 1; mapping2();
			map[4 + (h - 1) * 6][3] = 0; map[4 + (h + 1) * 6][3] = 0; map[3 + (h - 1) * 6][25 - i - 2] = 0; map[2 + (h - 1) * 6][25 - i - 2] = 0; map[1 + (h - 1) * 6][25 - i - 2] = 0; map[3 + (h + 1) * 6][25 - i - 2] = 0; map[2 + (h + 1) * 6][25 - i - 2] = 0; map[1 + (h + 1) * 6][25 - i - 2] = 0; delay(); mapping2(); break;
		case 2:
			map[3 + (h - 1) * 6][3] = 2; map[3 + (h + 1) * 6][3] = 2; map[3 + (h - 1) * 6][25 - i - 3] = 1; map[2 + (h - 1) * 6][25 - i - 3] = 1; map[1 + (h - 1) * 6][25 - i - 3] = 1; map[3 + (h + 1) * 6][25 - i - 3] = 1; map[2 + (h + 1) * 6][25 - i - 3] = 1; map[1 + (h + 1) * 6][25 - i - 3] = 1; mapping2();
			map[3 + (h - 1) * 6][3] = 0; map[3 + (h + 1) * 6][3] = 0; map[3 + (h - 1) * 6][25 - i - 3] = 0; map[2 + (h - 1) * 6][25 - i - 3] = 0; map[1 + (h - 1) * 6][25 - i - 3] = 0; map[3 + (h + 1) * 6][25 - i - 3] = 0; map[2 + (h + 1) * 6][25 - i - 3] = 0; map[1 + (h + 1) * 6][25 - i - 3] = 0; delay(); mapping2(); break;
		case 3:
			map[2 + (h - 1) * 6][3] = 2; map[2 + (h + 1) * 6][3] = 2; map[3 + (h - 1) * 6][25 - i - 4] = 1; map[2 + (h - 1) * 6][25 - i - 4] = 1; map[1 + (h - 1) * 6][25 - i - 4] = 1; map[3 + (h + 1) * 6][25 - i - 4] = 1; map[2 + (h + 1) * 6][25 - i - 4] = 1; map[1 + (h + 1) * 6][25 - i - 4] = 1; mapping2();
			map[2 + (h - 1) * 6][3] = 0; map[2 + (h + 1) * 6][3] = 0; map[3 + (h - 1) * 6][25 - i - 4] = 0; map[2 + (h - 1) * 6][25 - i - 4] = 0; map[1 + (h - 1) * 6][25 - i - 4] = 0; map[3 + (h + 1) * 6][25 - i - 4] = 0; map[2 + (h + 1) * 6][25 - i - 4] = 0; map[1 + (h + 1) * 6][25 - i - 4] = 0; delay(); mapping2(); break;
		case 4:
			map[3 + (h - 1) * 6][3] = 2; map[3 + (h + 1) * 6][3] = 2; map[3 + (h - 1) * 6][25 - i - 5] = 1; map[2 + (h - 1) * 6][25 - i - 5] = 1; map[1 + (h - 1) * 6][25 - i - 5] = 1; map[3 + (h + 1) * 6][25 - i - 5] = 1; map[2 + (h + 1) * 6][25 - i - 5] = 1; map[1 + (h + 1) * 6][25 - i - 5] = 1; mapping2();
			map[3 + (h - 1) * 6][3] = 0; map[3 + (h + 1) * 6][3] = 0; map[3 + (h - 1) * 6][25 - i - 5] = 0; map[2 + (h - 1) * 6][25 - i - 5] = 0; map[1 + (h - 1) * 6][25 - i - 5] = 0; map[3 + (h + 1) * 6][25 - i - 5] = 0; map[2 + (h + 1) * 6][25 - i - 5] = 0; map[1 + (h + 1) * 6][25 - i - 5] = 0; delay(); mapping2(); break;
		case 5:
			map[4 + (h - 1) * 6][3] = 2; map[4 + (h + 1) * 6][3] = 2; map[3 + (h - 1) * 6][25 - i - 6] = 1; map[2 + (h - 1) * 6][25 - i - 6] = 1; map[1 + (h - 1) * 6][25 - i - 6] = 1; map[3 + (h + 1) * 6][25 - i - 6] = 1; map[2 + (h + 1) * 6][25 - i - 6] = 1; map[1 + (h + 1) * 6][25 - i - 6] = 1; mapping2();
			map[4 + (h - 1) * 6][3] = 0; map[4 + (h + 1) * 6][3] = 0; map[3 + (h - 1) * 6][25 - i - 6] = 0; map[2 + (h - 1) * 6][25 - i - 6] = 0; map[1 + (h - 1) * 6][25 - i - 6] = 0; map[3 + (h + 1) * 6][25 - i - 6] = 0; map[2 + (h + 1) * 6][25 - i - 6] = 0; map[1 + (h + 1) * 6][25 - i - 6] = 0; delay(); mapping2(); break;
		case 6:
			map[5 + (h - 1) * 6][3] = 2; map[5 + (h + 1) * 6][3] = 2; map[3 + (h - 1) * 6][25 - i - 7] = 1; map[2 + (h - 1) * 6][25 - i - 7] = 1; map[1 + (h - 1) * 6][25 - i - 7] = 1; map[3 + (h + 1) * 6][25 - i - 7] = 1; map[2 + (h + 1) * 6][25 - i - 7] = 1; map[1 + (h + 1) * 6][25 - i - 7] = 1; mapping2();
			map[3 + (h - 1) * 6][25 - i - 7] = 0; map[2 + (h - 1) * 6][25 - i - 7] = 0; map[1 + (h - 1) * 6][25 - i - 7] = 0; map[3 + (h + 1) * 6][25 - i - 7] = 0; map[2 + (h + 1) * 6][25 - i - 7] = 0; map[1 + (h + 1) * 6][25 - i - 7] = 0; delay(); mapping2(); break;
		}
		step++;
		step = step % 7;
	}
}//������ 3��¥��
void jump3_0_13_1(int i, int h) {
	static int step = 0;
	int j = 0;
	for (j = 0; j<7; j++) {
		switch (step) {
		case 0:
			map[5 + (h - 1) * 6][3] = 2; map[5 + (h + 1) * 6][3] = 2; map[3 + (h - 1) * 6][25 - i - 1] = 1; map[2 + (h - 1) * 6][25 - i - 1] = 1; map[1 + (h - 1) * 6][25 - i - 1] = 1; map[3 + (h + 1) * 6][25 - i - 1] = 1; map[2 + (h + 1) * 6][25 - i - 1] = 1; map[1 + (h + 1) * 6][25 - i - 1] = 1; mapping2();
			map[5 + (h - 1) * 6][3] = 0; map[5 + (h + 1) * 6][3] = 0; map[3 + (h - 1) * 6][25 - i - 1] = 0; map[2 + (h - 1) * 6][25 - i - 1] = 0; map[1 + (h - 1) * 6][25 - i - 1] = 0; map[3 + (h + 1) * 6][25 - i - 1] = 0; map[2 + (h + 1) * 6][25 - i - 1] = 0; map[1 + (h + 1) * 6][25 - i - 1] = 0; delay(); mapping2(); break;
		case 1:
			map[4 + (h - 1) * 6][3] = 2; map[5 + (h + 1) * 6][3] = 2; map[3 + (h - 1) * 6][25 - i - 2] = 1; map[2 + (h - 1) * 6][25 - i - 2] = 1; map[1 + (h - 1) * 6][25 - i - 2] = 1; map[3 + (h + 1) * 6][25 - i - 2] = 1; map[2 + (h + 1) * 6][25 - i - 2] = 1; map[1 + (h + 1) * 6][25 - i - 2] = 1; mapping2();
			map[4 + (h - 1) * 6][3] = 0; map[5 + (h + 1) * 6][3] = 0; map[3 + (h - 1) * 6][25 - i - 2] = 0; map[2 + (h - 1) * 6][25 - i - 2] = 0; map[1 + (h - 1) * 6][25 - i - 2] = 0; map[3 + (h + 1) * 6][25 - i - 2] = 0; map[2 + (h + 1) * 6][25 - i - 2] = 0; map[1 + (h + 1) * 6][25 - i - 2] = 0; delay(); mapping2(); break;
		case 2:
			map[3 + (h - 1) * 6][3] = 2; map[5 + (h + 1) * 6][3] = 2; map[3 + (h - 1) * 6][25 - i - 3] = 1; map[2 + (h - 1) * 6][25 - i - 3] = 1; map[1 + (h - 1) * 6][25 - i - 3] = 1; map[3 + (h + 1) * 6][25 - i - 3] = 1; map[2 + (h + 1) * 6][25 - i - 3] = 1; map[1 + (h + 1) * 6][25 - i - 3] = 1; mapping2();
			map[3 + (h - 1) * 6][3] = 0; map[5 + (h + 1) * 6][3] = 0; map[3 + (h - 1) * 6][25 - i - 3] = 0; map[2 + (h - 1) * 6][25 - i - 3] = 0; map[1 + (h - 1) * 6][25 - i - 3] = 0; map[3 + (h + 1) * 6][25 - i - 3] = 0; map[2 + (h + 1) * 6][25 - i - 3] = 0; map[1 + (h + 1) * 6][25 - i - 3] = 0; delay(); mapping2(); break;
		case 3:
			map[2 + (h - 1) * 6][3] = 2; map[5 + (h + 1) * 6][3] = 2; map[3 + (h - 1) * 6][25 - i - 4] = 1; map[2 + (h - 1) * 6][25 - i - 4] = 1; map[1 + (h - 1) * 6][25 - i - 4] = 1; map[3 + (h + 1) * 6][25 - i - 4] = 1; map[2 + (h + 1) * 6][25 - i - 4] = 1; map[1 + (h + 1) * 6][25 - i - 4] = 1; mapping2();
			map[2 + (h - 1) * 6][3] = 0; map[5 + (h + 1) * 6][3] = 0; map[3 + (h - 1) * 6][25 - i - 4] = 0; map[2 + (h - 1) * 6][25 - i - 4] = 0; map[1 + (h - 1) * 6][25 - i - 4] = 0; map[3 + (h + 1) * 6][25 - i - 4] = 0; map[2 + (h + 1) * 6][25 - i - 4] = 0; map[1 + (h + 1) * 6][25 - i - 4] = 0; delay(); mapping2(); break;
		case 4:
			map[3 + (h - 1) * 6][3] = 2; map[5 + (h + 1) * 6][3] = 2; map[3 + (h - 1) * 6][25 - i - 5] = 1; map[2 + (h - 1) * 6][25 - i - 5] = 1; map[1 + (h - 1) * 6][25 - i - 5] = 1; map[3 + (h + 1) * 6][25 - i - 5] = 1; map[2 + (h + 1) * 6][25 - i - 5] = 1; map[1 + (h + 1) * 6][25 - i - 5] = 1; mapping2();
			map[3 + (h - 1) * 6][3] = 0; map[5 + (h + 1) * 6][3] = 0; map[3 + (h - 1) * 6][25 - i - 5] = 0; map[2 + (h - 1) * 6][25 - i - 5] = 0; map[1 + (h - 1) * 6][25 - i - 5] = 0; map[3 + (h + 1) * 6][25 - i - 5] = 0; map[2 + (h + 1) * 6][25 - i - 5] = 0; map[1 + (h + 1) * 6][25 - i - 5] = 0; delay(); mapping2(); break;
		case 5:
			map[4 + (h - 1) * 6][3] = 2; map[5 + (h + 1) * 6][3] = 2; map[3 + (h - 1) * 6][25 - i - 6] = 1; map[2 + (h - 1) * 6][25 - i - 6] = 1; map[1 + (h - 1) * 6][25 - i - 6] = 1; map[3 + (h + 1) * 6][25 - i - 6] = 1; map[2 + (h + 1) * 6][25 - i - 6] = 1; map[1 + (h + 1) * 6][25 - i - 6] = 1; mapping2();
			map[4 + (h - 1) * 6][3] = 0; map[5 + (h + 1) * 6][3] = 0; map[3 + (h - 1) * 6][25 - i - 6] = 0; map[2 + (h - 1) * 6][25 - i - 6] = 0; map[1 + (h - 1) * 6][25 - i - 6] = 0; map[3 + (h + 1) * 6][25 - i - 6] = 0; map[2 + (h + 1) * 6][25 - i - 6] = 0; map[1 + (h + 1) * 6][25 - i - 6] = 0; delay(); mapping2(); break;
		case 6:
			map[5 + (h - 1) * 6][3] = 2; map[5 + (h + 1) * 6][3] = 2; map[3 + (h - 1) * 6][25 - i - 7] = 1; map[2 + (h - 1) * 6][25 - i - 7] = 1; map[1 + (h - 1) * 6][25 - i - 7] = 1; map[3 + (h + 1) * 6][25 - i - 7] = 1; map[2 + (h + 1) * 6][25 - i - 7] = 1; map[1 + (h + 1) * 6][25 - i - 7] = 1; mapping2();
			map[3 + (h - 1) * 6][25 - i - 7] = 0; map[2 + (h - 1) * 6][25 - i - 7] = 0; map[1 + (h - 1) * 6][25 - i - 7] = 0; map[3 + (h + 1) * 6][25 - i - 7] = 0; map[2 + (h + 1) * 6][25 - i - 7] = 0; map[1 + (h + 1) * 6][25 - i - 7] = 0; delay(); mapping2(); break;
		}
		step++;
		step = step % 7;
	}
}//������ 3��¥��
void jump3_0_13_2(int i, int h) {
	static int step = 0;
	int j = 0;
	for (j = 0; j<7; j++) {
		switch (step) {
		case 0:
			map[5 + (h - 1) * 6][3] = 2; map[5 + (h + 1) * 6][3] = 2; map[3 + (h - 1) * 6][25 - i - 1] = 1; map[2 + (h - 1) * 6][25 - i - 1] = 1; map[1 + (h - 1) * 6][25 - i - 1] = 1; map[3 + (h + 1) * 6][25 - i - 1] = 1; map[2 + (h + 1) * 6][25 - i - 1] = 1; map[1 + (h + 1) * 6][25 - i - 1] = 1; mapping2();
			map[5 + (h - 1) * 6][3] = 0; map[5 + (h + 1) * 6][3] = 0; map[3 + (h - 1) * 6][25 - i - 1] = 0; map[2 + (h - 1) * 6][25 - i - 1] = 0; map[1 + (h - 1) * 6][25 - i - 1] = 0; map[3 + (h + 1) * 6][25 - i - 1] = 0; map[2 + (h + 1) * 6][25 - i - 1] = 0; map[1 + (h + 1) * 6][25 - i - 1] = 0; delay(); mapping2(); break;
		case 1:
			map[5 + (h - 1) * 6][3] = 2; map[4 + (h + 1) * 6][3] = 2; map[3 + (h - 1) * 6][25 - i - 2] = 1; map[2 + (h - 1) * 6][25 - i - 2] = 1; map[1 + (h - 1) * 6][25 - i - 2] = 1; map[3 + (h + 1) * 6][25 - i - 2] = 1; map[2 + (h + 1) * 6][25 - i - 2] = 1; map[1 + (h + 1) * 6][25 - i - 2] = 1; mapping2();
			map[5 + (h - 1) * 6][3] = 0; map[4 + (h + 1) * 6][3] = 0; map[3 + (h - 1) * 6][25 - i - 2] = 0; map[2 + (h - 1) * 6][25 - i - 2] = 0; map[1 + (h - 1) * 6][25 - i - 2] = 0; map[3 + (h + 1) * 6][25 - i - 2] = 0; map[2 + (h + 1) * 6][25 - i - 2] = 0; map[1 + (h + 1) * 6][25 - i - 2] = 0; delay(); mapping2(); break;
		case 2:
			map[5 + (h - 1) * 6][3] = 2; map[3 + (h + 1) * 6][3] = 2; map[3 + (h - 1) * 6][25 - i - 3] = 1; map[2 + (h - 1) * 6][25 - i - 3] = 1; map[1 + (h - 1) * 6][25 - i - 3] = 1; map[3 + (h + 1) * 6][25 - i - 3] = 1; map[2 + (h + 1) * 6][25 - i - 3] = 1; map[1 + (h + 1) * 6][25 - i - 3] = 1; mapping2();
			map[5 + (h - 1) * 6][3] = 0; map[3 + (h + 1) * 6][3] = 0; map[3 + (h - 1) * 6][25 - i - 3] = 0; map[2 + (h - 1) * 6][25 - i - 3] = 0; map[1 + (h - 1) * 6][25 - i - 3] = 0; map[3 + (h + 1) * 6][25 - i - 3] = 0; map[2 + (h + 1) * 6][25 - i - 3] = 0; map[1 + (h + 1) * 6][25 - i - 3] = 0; delay(); mapping2(); break;
		case 3:
			map[5 + (h - 1) * 6][3] = 2; map[2 + (h + 1) * 6][3] = 2; map[3 + (h - 1) * 6][25 - i - 4] = 1; map[2 + (h - 1) * 6][25 - i - 4] = 1; map[1 + (h - 1) * 6][25 - i - 4] = 1; map[3 + (h + 1) * 6][25 - i - 4] = 1; map[2 + (h + 1) * 6][25 - i - 4] = 1; map[1 + (h + 1) * 6][25 - i - 4] = 1; mapping2();
			map[5 + (h - 1) * 6][3] = 0; map[2 + (h + 1) * 6][3] = 0; map[3 + (h - 1) * 6][25 - i - 4] = 0; map[2 + (h - 1) * 6][25 - i - 4] = 0; map[1 + (h - 1) * 6][25 - i - 4] = 0; map[3 + (h + 1) * 6][25 - i - 4] = 0; map[2 + (h + 1) * 6][25 - i - 4] = 0; map[1 + (h + 1) * 6][25 - i - 4] = 0; delay(); mapping2(); break;
		case 4:
			map[5 + (h - 1) * 6][3] = 2; map[3 + (h + 1) * 6][3] = 2; map[3 + (h - 1) * 6][25 - i - 5] = 1; map[2 + (h - 1) * 6][25 - i - 5] = 1; map[1 + (h - 1) * 6][25 - i - 5] = 1; map[3 + (h + 1) * 6][25 - i - 5] = 1; map[2 + (h + 1) * 6][25 - i - 5] = 1; map[1 + (h + 1) * 6][25 - i - 5] = 1; mapping2();
			map[5 + (h - 1) * 6][3] = 0; map[3 + (h + 1) * 6][3] = 0; map[3 + (h - 1) * 6][25 - i - 5] = 0; map[2 + (h - 1) * 6][25 - i - 5] = 0; map[1 + (h - 1) * 6][25 - i - 5] = 0; map[3 + (h + 1) * 6][25 - i - 5] = 0; map[2 + (h + 1) * 6][25 - i - 5] = 0; map[1 + (h + 1) * 6][25 - i - 5] = 0; delay(); mapping2(); break;
		case 5:
			map[5 + (h - 1) * 6][3] = 2; map[4 + (h + 1) * 6][3] = 2; map[3 + (h - 1) * 6][25 - i - 6] = 1; map[2 + (h - 1) * 6][25 - i - 6] = 1; map[1 + (h - 1) * 6][25 - i - 6] = 1; map[3 + (h + 1) * 6][25 - i - 6] = 1; map[2 + (h + 1) * 6][25 - i - 6] = 1; map[1 + (h + 1) * 6][25 - i - 6] = 1; mapping2();
			map[5 + (h - 1) * 6][3] = 0; map[4 + (h + 1) * 6][3] = 0; map[3 + (h - 1) * 6][25 - i - 6] = 0; map[2 + (h - 1) * 6][25 - i - 6] = 0; map[1 + (h - 1) * 6][25 - i - 6] = 0; map[3 + (h + 1) * 6][25 - i - 6] = 0; map[2 + (h + 1) * 6][25 - i - 6] = 0; map[1 + (h + 1) * 6][25 - i - 6] = 0; delay(); mapping2(); break;
		case 6:
			map[5 + (h - 1) * 6][3] = 2; map[5 + (h + 1) * 6][3] = 2; map[3 + (h - 1) * 6][25 - i - 7] = 1; map[2 + (h - 1) * 6][25 - i - 7] = 1; map[1 + (h - 1) * 6][25 - i - 7] = 1; map[3 + (h + 1) * 6][25 - i - 7] = 1; map[2 + (h + 1) * 6][25 - i - 7] = 1; map[1 + (h + 1) * 6][25 - i - 7] = 1; mapping2();
			map[3 + (h - 1) * 6][25 - i - 7] = 0; map[2 + (h - 1) * 6][25 - i - 7] = 0; map[1 + (h - 1) * 6][25 - i - 7] = 0; map[3 + (h + 1) * 6][25 - i - 7] = 0; map[2 + (h + 1) * 6][25 - i - 7] = 0; map[1 + (h + 1) * 6][25 - i - 7] = 0; delay(); mapping2(); break;
		}
		step++;
		step = step % 7;
	}
}//������ 3��¥��

void jump4_0(int i, int h) {
	static int step = 0;
	int j = 0;
	for (j = 0; j<7; j++) {
		switch (step) {
		case 0:
			map[5 + (h - 1) * 6][3] = 2; map[4 + (h - 1) * 6][25 - i - 1] = 1; map[3 + (h - 1) * 6][25 - i - 1] = 1; map[2 + (h - 1) * 6][25 - i - 1] = 1; map[1 + (h - 1) * 6][25 - i - 1] = 1; mapping2();
			map[5 + (h - 1) * 6][3] = 0; map[4 + (h - 1) * 6][25 - i - 1] = 0; map[3 + (h - 1) * 6][25 - i - 1] = 0; map[2 + (h - 1) * 6][25 - i - 1] = 0; map[1 + (h - 1) * 6][25 - i - 1] = 0; delay(); mapping2(); break;
		case 1:
			map[4 + (h - 1) * 6][3] = 2; map[4 + (h - 1) * 6][25 - i - 2] = 1; map[3 + (h - 1) * 6][25 - i - 2] = 1; map[2 + (h - 1) * 6][25 - i - 2] = 1; map[1 + (h - 1) * 6][25 - i - 2] = 1; mapping2();
			map[4 + (h - 1) * 6][3] = 0; map[4 + (h - 1) * 6][25 - i - 2] = 0; map[3 + (h - 1) * 6][25 - i - 2] = 0; map[2 + (h - 1) * 6][25 - i - 2] = 0; map[1 + (h - 1) * 6][25 - i - 2] = 0; delay(); mapping2(); break;
		case 2:
			map[3 + (h - 1) * 6][3] = 2; map[4 + (h - 1) * 6][25 - i - 3] = 1; map[3 + (h - 1) * 6][25 - i - 3] = 1; map[2 + (h - 1) * 6][25 - i - 3] = 1; map[1 + (h - 1) * 6][25 - i - 3] = 1; mapping2();
			map[3 + (h - 1) * 6][3] = 0; map[4 + (h - 1) * 6][25 - i - 3] = 0; map[3 + (h - 1) * 6][25 - i - 3] = 0; map[2 + (h - 1) * 6][25 - i - 3] = 0; map[1 + (h - 1) * 6][25 - i - 3] = 0; delay(); mapping2(); break;
		case 3:
			map[2 + (h - 1) * 6][3] = 2; map[4 + (h - 1) * 6][25 - i - 4] = 1; map[3 + (h - 1) * 6][25 - i - 4] = 1; map[2 + (h - 1) * 6][25 - i - 4] = 1; map[1 + (h - 1) * 6][25 - i - 4] = 1; mapping2();
			map[2 + (h - 1) * 6][3] = 0; map[4 + (h - 1) * 6][25 - i - 4] = 0; map[3 + (h - 1) * 6][25 - i - 4] = 0; map[2 + (h - 1) * 6][25 - i - 4] = 0; map[1 + (h - 1) * 6][25 - i - 4] = 0; delay(); mapping2(); break;
		case 4:
			map[3 + (h - 1) * 6][3] = 2; map[4 + (h - 1) * 6][25 - i - 5] = 1; map[3 + (h - 1) * 6][25 - i - 5] = 1; map[2 + (h - 1) * 6][25 - i - 5] = 1; map[1 + (h - 1) * 6][25 - i - 5] = 1; mapping2();
			map[3 + (h - 1) * 6][3] = 0; map[4 + (h - 1) * 6][25 - i - 5] = 0; map[3 + (h - 1) * 6][25 - i - 5] = 0; map[2 + (h - 1) * 6][25 - i - 5] = 0; map[1 + (h - 1) * 6][25 - i - 5] = 0; delay(); mapping2(); break;
		case 5:
			map[4 + (h - 1) * 6][3] = 2; map[4 + (h - 1) * 6][25 - i - 6] = 1; map[3 + (h - 1) * 6][25 - i - 6] = 1; map[2 + (h - 1) * 6][25 - i - 6] = 1; map[1 + (h - 1) * 6][25 - i - 6] = 1; mapping2();
			map[4 + (h - 1) * 6][3] = 0; map[4 + (h - 1) * 6][25 - i - 6] = 0; map[3 + (h - 1) * 6][25 - i - 6] = 0; map[2 + (h - 1) * 6][25 - i - 6] = 0; map[1 + (h - 1) * 6][25 - i - 6] = 0; delay(); mapping2(); break;
		case 6:
			map[5 + (h - 1) * 6][3] = 2; map[4 + (h - 1) * 6][25 - i - 7] = 1; map[3 + (h - 1) * 6][25 - i - 7] = 1; map[2 + (h - 1) * 6][25 - i - 7] = 1; map[1 + (h - 1) * 6][25 - i - 7] = 1; mapping2();
			map[4 + (h - 1) * 6][25 - i - 7] = 0; map[3 + (h - 1) * 6][25 - i - 7] = 0; map[2 + (h - 1) * 6][25 - i - 7] = 0; map[1 + (h - 1) * 6][25 - i - 7] = 0; delay(); mapping2(); break;
		}
		step++;
		step = step % 7;
	}
}
void jump4_0_12(int i, int h) {
	static int step = 0;
	int j = 0;
	for (j = 0; j<7; j++) {
		switch (step) {
		case 0:
			map[5 + (h - 1) * 6][3] = 2; map[5 + h * 6][3] = 2; map[4 + (h - 1) * 6][25 - i - 1] = 1; map[3 + (h - 1) * 6][25 - i - 1] = 1; map[2 + (h - 1) * 6][25 - i - 1] = 1; map[1 + (h - 1) * 6][25 - i - 1] = 1; map[4 + h * 6][25 - i - 1] = 1; map[3 + h * 6][25 - i - 1] = 1; map[2 + h * 6][25 - i - 1] = 1; map[1 + h * 6][25 - i - 1] = 1;  mapping2();
			map[5 + (h - 1) * 6][3] = 0; map[5 + h * 6][3] = 0; map[4 + (h - 1) * 6][25 - i - 1] = 0; map[3 + (h - 1) * 6][25 - i - 1] = 0; map[2 + (h - 1) * 6][25 - i - 1] = 0; map[1 + (h - 1) * 6][25 - i - 1] = 0; map[4 + h * 6][25 - i - 1] = 0; map[3 + h * 6][25 - i - 1] = 0; map[2 + h * 6][25 - i - 1] = 0; map[1 + h * 6][25 - i - 1] = 0;  delay(); mapping2(); break;
		case 1:
			map[4 + (h - 1) * 6][3] = 2; map[4 + h * 6][3] = 2; map[4 + (h - 1) * 6][25 - i - 2] = 1; map[3 + (h - 1) * 6][25 - i - 2] = 1; map[2 + (h - 1) * 6][25 - i - 2] = 1; map[1 + (h - 1) * 6][25 - i - 2] = 1; map[4 + h * 6][25 - i - 2] = 1; map[3 + h * 6][25 - i - 2] = 1; map[2 + h * 6][25 - i - 2] = 1; map[1 + h * 6][25 - i - 2] = 1;  mapping2();
			map[4 + (h - 1) * 6][3] = 0; map[4 + h * 6][3] = 0; map[4 + (h - 1) * 6][25 - i - 2] = 0; map[3 + (h - 1) * 6][25 - i - 2] = 0; map[2 + (h - 1) * 6][25 - i - 2] = 0; map[1 + (h - 1) * 6][25 - i - 2] = 0; map[4 + h * 6][25 - i - 2] = 0; map[3 + h * 6][25 - i - 2] = 0; map[2 + h * 6][25 - i - 2] = 0; map[1 + h * 6][25 - i - 2] = 0;  delay(); mapping2(); break;
		case 2:
			map[3 + (h - 1) * 6][3] = 2; map[3 + h * 6][3] = 2; map[4 + (h - 1) * 6][25 - i - 3] = 1; map[3 + (h - 1) * 6][25 - i - 3] = 1; map[2 + (h - 1) * 6][25 - i - 3] = 1; map[1 + (h - 1) * 6][25 - i - 3] = 1; map[4 + h * 6][25 - i - 3] = 1; map[3 + h * 6][25 - i - 3] = 1; map[2 + h * 6][25 - i - 3] = 1; map[1 + h * 6][25 - i - 3] = 1;  mapping2();
			map[3 + (h - 1) * 6][3] = 0; map[3 + h * 6][3] = 0; map[4 + (h - 1) * 6][25 - i - 3] = 0; map[3 + (h - 1) * 6][25 - i - 3] = 0; map[2 + (h - 1) * 6][25 - i - 3] = 0; map[1 + (h - 1) * 6][25 - i - 3] = 0; map[4 + h * 6][25 - i - 3] = 0; map[3 + h * 6][25 - i - 3] = 0; map[2 + h * 6][25 - i - 3] = 0; map[1 + h * 6][25 - i - 3] = 0;  delay(); mapping2(); break;
		case 3:
			map[2 + (h - 1) * 6][3] = 2; map[2 + h * 6][3] = 2; map[4 + (h - 1) * 6][25 - i - 4] = 1; map[3 + (h - 1) * 6][25 - i - 4] = 1; map[2 + (h - 1) * 6][25 - i - 4] = 1; map[1 + (h - 1) * 6][25 - i - 4] = 1; map[4 + h * 6][25 - i - 4] = 1; map[3 + h * 6][25 - i - 4] = 1; map[2 + h * 6][25 - i - 4] = 1; map[1 + h * 6][25 - i - 4] = 1;  mapping2();
			map[2 + (h - 1) * 6][3] = 0; map[2 + h * 6][3] = 0; map[4 + (h - 1) * 6][25 - i - 4] = 0; map[3 + (h - 1) * 6][25 - i - 4] = 0; map[2 + (h - 1) * 6][25 - i - 4] = 0; map[1 + (h - 1) * 6][25 - i - 4] = 0; map[4 + h * 6][25 - i - 4] = 0; map[3 + h * 6][25 - i - 4] = 0; map[2 + h * 6][25 - i - 4] = 0; map[1 + h * 6][25 - i - 4] = 0;  delay(); mapping2(); break;
		case 4:
			map[3 + (h - 1) * 6][3] = 2; map[3 + h * 6][3] = 2; map[4 + (h - 1) * 6][25 - i - 5] = 1; map[3 + (h - 1) * 6][25 - i - 5] = 1; map[2 + (h - 1) * 6][25 - i - 5] = 1; map[1 + (h - 1) * 6][25 - i - 5] = 1; map[4 + h * 6][25 - i - 5] = 1; map[3 + h * 6][25 - i - 5] = 1; map[2 + h * 6][25 - i - 5] = 1; map[1 + h * 6][25 - i - 5] = 1;  mapping2();
			map[3 + (h - 1) * 6][3] = 0; map[3 + h * 6][3] = 0; map[4 + (h - 1) * 6][25 - i - 5] = 0; map[3 + (h - 1) * 6][25 - i - 5] = 0; map[2 + (h - 1) * 6][25 - i - 5] = 0; map[1 + (h - 1) * 6][25 - i - 5] = 0; map[4 + h * 6][25 - i - 5] = 0; map[3 + h * 6][25 - i - 5] = 0; map[2 + h * 6][25 - i - 5] = 0; map[1 + h * 6][25 - i - 5] = 0;  delay(); mapping2(); break;
		case 5:
			map[4 + (h - 1) * 6][3] = 2; map[4 + h * 6][3] = 2; map[4 + (h - 1) * 6][25 - i - 6] = 1; map[3 + (h - 1) * 6][25 - i - 6] = 1; map[2 + (h - 1) * 6][25 - i - 6] = 1; map[1 + (h - 1) * 6][25 - i - 6] = 1; map[4 + h * 6][25 - i - 6] = 1; map[3 + h * 6][25 - i - 6] = 1; map[2 + h * 6][25 - i - 6] = 1; map[1 + h * 6][25 - i - 6] = 1;  mapping2();
			map[4 + (h - 1) * 6][3] = 0; map[4 + h * 6][3] = 0; map[4 + (h - 1) * 6][25 - i - 6] = 0; map[3 + (h - 1) * 6][25 - i - 6] = 0; map[2 + (h - 1) * 6][25 - i - 6] = 0; map[1 + (h - 1) * 6][25 - i - 6] = 0; map[4 + h * 6][25 - i - 6] = 0; map[3 + h * 6][25 - i - 6] = 0; map[2 + h * 6][25 - i - 6] = 0; map[1 + h * 6][25 - i - 6] = 0;  delay(); mapping2(); break;
		case 6:
			map[5 + (h - 1) * 6][3] = 2; map[5 + h * 6][3] = 2; map[4 + (h - 1) * 6][25 - i - 7] = 1; map[3 + (h - 1) * 6][25 - i - 7] = 1; map[2 + (h - 1) * 6][25 - i - 7] = 1; map[1 + (h - 1) * 6][25 - i - 7] = 1; map[4 + h * 6][25 - i - 7] = 1; map[3 + h * 6][25 - i - 7] = 1; map[2 + h * 6][25 - i - 7] = 1; map[1 + h * 6][25 - i - 7] = 1;  mapping2();
			map[4 + (h - 1) * 6][25 - i - 7] = 0; map[3 + (h - 1) * 6][25 - i - 7] = 0; map[2 + (h - 1) * 6][25 - i - 7] = 0; map[1 + (h - 1) * 6][25 - i - 7] = 0; map[4 + h * 6][25 - i - 7] = 0; map[3 + h * 6][25 - i - 7] = 0; map[2 + h * 6][25 - i - 7] = 0; map[1 + h * 6][25 - i - 7] = 0;  delay(); mapping2(); break;
		}
		step++;
		step = step % 7;
	}
}
void jump4_0_12_1(int i, int h) {
	static int step = 0;
	int j = 0;
	for (j = 0; j<7; j++) {
		switch (step) {
		case 0:
			map[5 + (h - 1) * 6][3] = 2; map[5 + h * 6][3] = 2; map[4 + (h - 1) * 6][25 - i - 1] = 1; map[3 + (h - 1) * 6][25 - i - 1] = 1; map[2 + (h - 1) * 6][25 - i - 1] = 1; map[1 + (h - 1) * 6][25 - i - 1] = 1; map[4 + h * 6][25 - i - 1] = 1; map[3 + h * 6][25 - i - 1] = 1; map[2 + h * 6][25 - i - 1] = 1; map[1 + h * 6][25 - i - 1] = 1;  mapping2();
			map[5 + (h - 1) * 6][3] = 0; map[5 + h * 6][3] = 0; map[4 + (h - 1) * 6][25 - i - 1] = 0; map[3 + (h - 1) * 6][25 - i - 1] = 0; map[2 + (h - 1) * 6][25 - i - 1] = 0; map[1 + (h - 1) * 6][25 - i - 1] = 0; map[4 + h * 6][25 - i - 1] = 0; map[3 + h * 6][25 - i - 1] = 0; map[2 + h * 6][25 - i - 1] = 0; map[1 + h * 6][25 - i - 1] = 0;  delay(); mapping2(); break;
		case 1:
			map[4 + (h - 1) * 6][3] = 2; map[5 + h * 6][3] = 2; map[4 + (h - 1) * 6][25 - i - 2] = 1; map[3 + (h - 1) * 6][25 - i - 2] = 1; map[2 + (h - 1) * 6][25 - i - 2] = 1; map[1 + (h - 1) * 6][25 - i - 2] = 1; map[4 + h * 6][25 - i - 2] = 1; map[3 + h * 6][25 - i - 2] = 1; map[2 + h * 6][25 - i - 2] = 1; map[1 + h * 6][25 - i - 2] = 1;  mapping2();
			map[4 + (h - 1) * 6][3] = 0; map[5 + h * 6][3] = 0; map[4 + (h - 1) * 6][25 - i - 2] = 0; map[3 + (h - 1) * 6][25 - i - 2] = 0; map[2 + (h - 1) * 6][25 - i - 2] = 0; map[1 + (h - 1) * 6][25 - i - 2] = 0; map[4 + h * 6][25 - i - 2] = 0; map[3 + h * 6][25 - i - 2] = 0; map[2 + h * 6][25 - i - 2] = 0; map[1 + h * 6][25 - i - 2] = 0;  delay(); mapping2(); break;
		case 2:
			map[3 + (h - 1) * 6][3] = 2; map[5 + h * 6][3] = 2; map[4 + (h - 1) * 6][25 - i - 3] = 1; map[3 + (h - 1) * 6][25 - i - 3] = 1; map[2 + (h - 1) * 6][25 - i - 3] = 1; map[1 + (h - 1) * 6][25 - i - 3] = 1; map[4 + h * 6][25 - i - 3] = 1; map[3 + h * 6][25 - i - 3] = 1; map[2 + h * 6][25 - i - 3] = 1; map[1 + h * 6][25 - i - 3] = 1;  mapping2();
			map[3 + (h - 1) * 6][3] = 0; map[5 + h * 6][3] = 0; map[4 + (h - 1) * 6][25 - i - 3] = 0; map[3 + (h - 1) * 6][25 - i - 3] = 0; map[2 + (h - 1) * 6][25 - i - 3] = 0; map[1 + (h - 1) * 6][25 - i - 3] = 0; map[4 + h * 6][25 - i - 3] = 0; map[3 + h * 6][25 - i - 3] = 0; map[2 + h * 6][25 - i - 3] = 0; map[1 + h * 6][25 - i - 3] = 0;  delay(); mapping2(); break;
		case 3:
			map[2 + (h - 1) * 6][3] = 2; map[5 + h * 6][3] = 2; map[4 + (h - 1) * 6][25 - i - 4] = 1; map[3 + (h - 1) * 6][25 - i - 4] = 1; map[2 + (h - 1) * 6][25 - i - 4] = 1; map[1 + (h - 1) * 6][25 - i - 4] = 1; map[4 + h * 6][25 - i - 4] = 1; map[3 + h * 6][25 - i - 4] = 1; map[2 + h * 6][25 - i - 4] = 1; map[1 + h * 6][25 - i - 4] = 1;  mapping2();
			map[2 + (h - 1) * 6][3] = 0; map[5 + h * 6][3] = 0; map[4 + (h - 1) * 6][25 - i - 4] = 0; map[3 + (h - 1) * 6][25 - i - 4] = 0; map[2 + (h - 1) * 6][25 - i - 4] = 0; map[1 + (h - 1) * 6][25 - i - 4] = 0; map[4 + h * 6][25 - i - 4] = 0; map[3 + h * 6][25 - i - 4] = 0; map[2 + h * 6][25 - i - 4] = 0; map[1 + h * 6][25 - i - 4] = 0;  delay(); mapping2(); break;
		case 4:
			map[3 + (h - 1) * 6][3] = 2; map[5 + h * 6][3] = 2; map[4 + (h - 1) * 6][25 - i - 5] = 1; map[3 + (h - 1) * 6][25 - i - 5] = 1; map[2 + (h - 1) * 6][25 - i - 5] = 1; map[1 + (h - 1) * 6][25 - i - 5] = 1; map[4 + h * 6][25 - i - 5] = 1; map[3 + h * 6][25 - i - 5] = 1; map[2 + h * 6][25 - i - 5] = 1; map[1 + h * 6][25 - i - 5] = 1;  mapping2();
			map[3 + (h - 1) * 6][3] = 0; map[5 + h * 6][3] = 0; map[4 + (h - 1) * 6][25 - i - 5] = 0; map[3 + (h - 1) * 6][25 - i - 5] = 0; map[2 + (h - 1) * 6][25 - i - 5] = 0; map[1 + (h - 1) * 6][25 - i - 5] = 0; map[4 + h * 6][25 - i - 5] = 0; map[3 + h * 6][25 - i - 5] = 0; map[2 + h * 6][25 - i - 5] = 0; map[1 + h * 6][25 - i - 5] = 0;  delay(); mapping2(); break;
		case 5:
			map[4 + (h - 1) * 6][3] = 2; map[5 + h * 6][3] = 2; map[4 + (h - 1) * 6][25 - i - 6] = 1; map[3 + (h - 1) * 6][25 - i - 6] = 1; map[2 + (h - 1) * 6][25 - i - 6] = 1; map[1 + (h - 1) * 6][25 - i - 6] = 1; map[4 + h * 6][25 - i - 6] = 1; map[3 + h * 6][25 - i - 6] = 1; map[2 + h * 6][25 - i - 6] = 1; map[1 + h * 6][25 - i - 6] = 1;  mapping2();
			map[4 + (h - 1) * 6][3] = 0; map[5 + h * 6][3] = 0; map[4 + (h - 1) * 6][25 - i - 6] = 0; map[3 + (h - 1) * 6][25 - i - 6] = 0; map[2 + (h - 1) * 6][25 - i - 6] = 0; map[1 + (h - 1) * 6][25 - i - 6] = 0; map[4 + h * 6][25 - i - 6] = 0; map[3 + h * 6][25 - i - 6] = 0; map[2 + h * 6][25 - i - 6] = 0; map[1 + h * 6][25 - i - 6] = 0;  delay(); mapping2(); break;
		case 6:
			map[5 + (h - 1) * 6][3] = 2; map[5 + h * 6][3] = 2; map[4 + (h - 1) * 6][25 - i - 7] = 1; map[3 + (h - 1) * 6][25 - i - 7] = 1; map[2 + (h - 1) * 6][25 - i - 7] = 1; map[1 + (h - 1) * 6][25 - i - 7] = 1; map[4 + h * 6][25 - i - 7] = 1; map[3 + h * 6][25 - i - 7] = 1; map[2 + h * 6][25 - i - 7] = 1; map[1 + h * 6][25 - i - 7] = 1;  mapping2();
			map[4 + (h - 1) * 6][25 - i - 7] = 0; map[3 + (h - 1) * 6][25 - i - 7] = 0; map[2 + (h - 1) * 6][25 - i - 7] = 0; map[1 + (h - 1) * 6][25 - i - 7] = 0; map[4 + h * 6][25 - i - 7] = 0; map[3 + h * 6][25 - i - 7] = 0; map[2 + h * 6][25 - i - 7] = 0; map[1 + h * 6][25 - i - 7] = 0;  delay(); mapping2(); break;
		}
		step++;
		step = step % 7;
	}
}
void jump4_0_12_2(int i, int h) {
	static int step = 0;
	int j = 0;
	for (j = 0; j<7; j++) {
		switch (step) {
		case 0:
			map[5 + (h - 1) * 6][3] = 2; map[5 + h * 6][3] = 2; map[4 + (h - 1) * 6][25 - i - 1] = 1; map[3 + (h - 1) * 6][25 - i - 1] = 1; map[2 + (h - 1) * 6][25 - i - 1] = 1; map[1 + (h - 1) * 6][25 - i - 1] = 1; map[4 + h * 6][25 - i - 1] = 1; map[3 + h * 6][25 - i - 1] = 1; map[2 + h * 6][25 - i - 1] = 1; map[1 + h * 6][25 - i - 1] = 1;  mapping2();
			map[5 + (h - 1) * 6][3] = 0; map[5 + h * 6][3] = 0; map[4 + (h - 1) * 6][25 - i - 1] = 0; map[3 + (h - 1) * 6][25 - i - 1] = 0; map[2 + (h - 1) * 6][25 - i - 1] = 0; map[1 + (h - 1) * 6][25 - i - 1] = 0; map[4 + h * 6][25 - i - 1] = 0; map[3 + h * 6][25 - i - 1] = 0; map[2 + h * 6][25 - i - 1] = 0; map[1 + h * 6][25 - i - 1] = 0;  delay(); mapping2(); break;
		case 1:
			map[5 + (h - 1) * 6][3] = 2; map[4 + h * 6][3] = 2; map[4 + (h - 1) * 6][25 - i - 2] = 1; map[3 + (h - 1) * 6][25 - i - 2] = 1; map[2 + (h - 1) * 6][25 - i - 2] = 1; map[1 + (h - 1) * 6][25 - i - 2] = 1; map[4 + h * 6][25 - i - 2] = 1; map[3 + h * 6][25 - i - 2] = 1; map[2 + h * 6][25 - i - 2] = 1; map[1 + h * 6][25 - i - 2] = 1;  mapping2();
			map[5 + (h - 1) * 6][3] = 0; map[4 + h * 6][3] = 0; map[4 + (h - 1) * 6][25 - i - 2] = 0; map[3 + (h - 1) * 6][25 - i - 2] = 0; map[2 + (h - 1) * 6][25 - i - 2] = 0; map[1 + (h - 1) * 6][25 - i - 2] = 0; map[4 + h * 6][25 - i - 2] = 0; map[3 + h * 6][25 - i - 2] = 0; map[2 + h * 6][25 - i - 2] = 0; map[1 + h * 6][25 - i - 2] = 0;  delay(); mapping2(); break;
		case 2:
			map[5 + (h - 1) * 6][3] = 2; map[3 + h * 6][3] = 2; map[4 + (h - 1) * 6][25 - i - 3] = 1; map[3 + (h - 1) * 6][25 - i - 3] = 1; map[2 + (h - 1) * 6][25 - i - 3] = 1; map[1 + (h - 1) * 6][25 - i - 3] = 1; map[4 + h * 6][25 - i - 3] = 1; map[3 + h * 6][25 - i - 3] = 1; map[2 + h * 6][25 - i - 3] = 1; map[1 + h * 6][25 - i - 3] = 1;  mapping2();
			map[5 + (h - 1) * 6][3] = 0; map[3 + h * 6][3] = 0; map[4 + (h - 1) * 6][25 - i - 3] = 0; map[3 + (h - 1) * 6][25 - i - 3] = 0; map[2 + (h - 1) * 6][25 - i - 3] = 0; map[1 + (h - 1) * 6][25 - i - 3] = 0; map[4 + h * 6][25 - i - 3] = 0; map[3 + h * 6][25 - i - 3] = 0; map[2 + h * 6][25 - i - 3] = 0; map[1 + h * 6][25 - i - 3] = 0;  delay(); mapping2(); break;
		case 3:
			map[5 + (h - 1) * 6][3] = 2; map[2 + h * 6][3] = 2; map[4 + (h - 1) * 6][25 - i - 4] = 1; map[3 + (h - 1) * 6][25 - i - 4] = 1; map[2 + (h - 1) * 6][25 - i - 4] = 1; map[1 + (h - 1) * 6][25 - i - 4] = 1; map[4 + h * 6][25 - i - 4] = 1; map[3 + h * 6][25 - i - 4] = 1; map[2 + h * 6][25 - i - 4] = 1; map[1 + h * 6][25 - i - 4] = 1;  mapping2();
			map[5 + (h - 1) * 6][3] = 0; map[2 + h * 6][3] = 0; map[4 + (h - 1) * 6][25 - i - 4] = 0; map[3 + (h - 1) * 6][25 - i - 4] = 0; map[2 + (h - 1) * 6][25 - i - 4] = 0; map[1 + (h - 1) * 6][25 - i - 4] = 0; map[4 + h * 6][25 - i - 4] = 0; map[3 + h * 6][25 - i - 4] = 0; map[2 + h * 6][25 - i - 4] = 0; map[1 + h * 6][25 - i - 4] = 0;  delay(); mapping2(); break;
		case 4:
			map[5 + (h - 1) * 6][3] = 2; map[3 + h * 6][3] = 2; map[4 + (h - 1) * 6][25 - i - 5] = 1; map[3 + (h - 1) * 6][25 - i - 5] = 1; map[2 + (h - 1) * 6][25 - i - 5] = 1; map[1 + (h - 1) * 6][25 - i - 5] = 1; map[4 + h * 6][25 - i - 5] = 1; map[3 + h * 6][25 - i - 5] = 1; map[2 + h * 6][25 - i - 5] = 1; map[1 + h * 6][25 - i - 5] = 1;  mapping2();
			map[5 + (h - 1) * 6][3] = 0; map[3 + h * 6][3] = 0; map[4 + (h - 1) * 6][25 - i - 5] = 0; map[3 + (h - 1) * 6][25 - i - 5] = 0; map[2 + (h - 1) * 6][25 - i - 5] = 0; map[1 + (h - 1) * 6][25 - i - 5] = 0; map[4 + h * 6][25 - i - 5] = 0; map[3 + h * 6][25 - i - 5] = 0; map[2 + h * 6][25 - i - 5] = 0; map[1 + h * 6][25 - i - 5] = 0;  delay(); mapping2(); break;
		case 5:
			map[5 + (h - 1) * 6][3] = 2; map[4 + h * 6][3] = 2; map[4 + (h - 1) * 6][25 - i - 6] = 1; map[3 + (h - 1) * 6][25 - i - 6] = 1; map[2 + (h - 1) * 6][25 - i - 6] = 1; map[1 + (h - 1) * 6][25 - i - 6] = 1; map[4 + h * 6][25 - i - 6] = 1; map[3 + h * 6][25 - i - 6] = 1; map[2 + h * 6][25 - i - 6] = 1; map[1 + h * 6][25 - i - 6] = 1;  mapping2();
			map[5 + (h - 1) * 6][3] = 0; map[4 + h * 6][3] = 0; map[4 + (h - 1) * 6][25 - i - 6] = 0; map[3 + (h - 1) * 6][25 - i - 6] = 0; map[2 + (h - 1) * 6][25 - i - 6] = 0; map[1 + (h - 1) * 6][25 - i - 6] = 0; map[4 + h * 6][25 - i - 6] = 0; map[3 + h * 6][25 - i - 6] = 0; map[2 + h * 6][25 - i - 6] = 0; map[1 + h * 6][25 - i - 6] = 0;  delay(); mapping2(); break;
		case 6:
			map[5 + (h - 1) * 6][3] = 2; map[5 + h * 6][3] = 2; map[4 + (h - 1) * 6][25 - i - 7] = 1; map[3 + (h - 1) * 6][25 - i - 7] = 1; map[2 + (h - 1) * 6][25 - i - 7] = 1; map[1 + (h - 1) * 6][25 - i - 7] = 1; map[4 + h * 6][25 - i - 7] = 1; map[3 + h * 6][25 - i - 7] = 1; map[2 + h * 6][25 - i - 7] = 1; map[1 + h * 6][25 - i - 7] = 1;  mapping2();
			map[4 + (h - 1) * 6][25 - i - 7] = 0; map[3 + (h - 1) * 6][25 - i - 7] = 0; map[2 + (h - 1) * 6][25 - i - 7] = 0; map[1 + (h - 1) * 6][25 - i - 7] = 0; map[4 + h * 6][25 - i - 7] = 0; map[3 + h * 6][25 - i - 7] = 0; map[2 + h * 6][25 - i - 7] = 0; map[1 + h * 6][25 - i - 7] = 0;  delay(); mapping2(); break;
		}
		step++;
		step = step % 7;
	}
}
void jump4_0_13(int i, int h) {
	static int step = 0;
	int j = 0;
	for (j = 0; j<7; j++) {
		switch (step) {
		case 0:
			map[5 + (h - 1) * 6][3] = 2; map[5 + (h + 1) * 6][3] = 2; map[4 + (h - 1) * 6][25 - i - 1] = 1; map[3 + (h - 1) * 6][25 - i - 1] = 1; map[2 + (h - 1) * 6][25 - i - 1] = 1; map[1 + (h - 1) * 6][25 - i - 1] = 1; map[4 + (h + 1) * 6][25 - i - 1] = 1; map[3 + (h + 1) * 6][25 - i - 1] = 1; map[2 + (h + 1) * 6][25 - i - 1] = 1; map[1 + (h + 1) * 6][25 - i - 1] = 1;  mapping2();
			map[5 + (h - 1) * 6][3] = 0; map[5 + (h + 1) * 6][3] = 0; map[4 + (h - 1) * 6][25 - i - 1] = 0; map[3 + (h - 1) * 6][25 - i - 1] = 0; map[2 + (h - 1) * 6][25 - i - 1] = 0; map[1 + (h - 1) * 6][25 - i - 1] = 0; map[4 + (h + 1) * 6][25 - i - 1] = 0; map[3 + (h + 1) * 6][25 - i - 1] = 0; map[2 + (h + 1) * 6][25 - i - 1] = 0; map[1 + (h + 1) * 6][25 - i - 1] = 0;  delay(); mapping2(); break;
		case 1:
			map[4 + (h - 1) * 6][3] = 2; map[4 + (h + 1) * 6][3] = 2; map[4 + (h - 1) * 6][25 - i - 2] = 1; map[3 + (h - 1) * 6][25 - i - 2] = 1; map[2 + (h - 1) * 6][25 - i - 2] = 1; map[1 + (h - 1) * 6][25 - i - 2] = 1; map[4 + (h + 1) * 6][25 - i - 2] = 1; map[3 + (h + 1) * 6][25 - i - 2] = 1; map[2 + (h + 1) * 6][25 - i - 2] = 1; map[1 + (h + 1) * 6][25 - i - 2] = 1;  mapping2();
			map[4 + (h - 1) * 6][3] = 0; map[4 + (h + 1) * 6][3] = 0; map[4 + (h - 1) * 6][25 - i - 2] = 0; map[3 + (h - 1) * 6][25 - i - 2] = 0; map[2 + (h - 1) * 6][25 - i - 2] = 0; map[1 + (h - 1) * 6][25 - i - 2] = 0; map[4 + (h + 1) * 6][25 - i - 2] = 0; map[3 + (h + 1) * 6][25 - i - 2] = 0; map[2 + (h + 1) * 6][25 - i - 2] = 0; map[1 + (h + 1) * 6][25 - i - 2] = 0;  delay(); mapping2(); break;
		case 2:
			map[3 + (h - 1) * 6][3] = 2; map[3 + (h + 1) * 6][3] = 2; map[4 + (h - 1) * 6][25 - i - 3] = 1; map[3 + (h - 1) * 6][25 - i - 3] = 1; map[2 + (h - 1) * 6][25 - i - 3] = 1; map[1 + (h - 1) * 6][25 - i - 3] = 1; map[4 + (h + 1) * 6][25 - i - 3] = 1; map[3 + (h + 1) * 6][25 - i - 3] = 1; map[2 + (h + 1) * 6][25 - i - 3] = 1; map[1 + (h + 1) * 6][25 - i - 3] = 1;  mapping2();
			map[3 + (h - 1) * 6][3] = 0; map[3 + (h + 1) * 6][3] = 0; map[4 + (h - 1) * 6][25 - i - 3] = 0; map[3 + (h - 1) * 6][25 - i - 3] = 0; map[2 + (h - 1) * 6][25 - i - 3] = 0; map[1 + (h - 1) * 6][25 - i - 3] = 0; map[4 + (h + 1) * 6][25 - i - 3] = 0; map[3 + (h + 1) * 6][25 - i - 3] = 0; map[2 + (h + 1) * 6][25 - i - 3] = 0; map[1 + (h + 1) * 6][25 - i - 3] = 0;  delay(); mapping2(); break;
		case 3:
			map[2 + (h - 1) * 6][3] = 2; map[2 + (h + 1) * 6][3] = 2; map[4 + (h - 1) * 6][25 - i - 4] = 1; map[3 + (h - 1) * 6][25 - i - 4] = 1; map[2 + (h - 1) * 6][25 - i - 4] = 1; map[1 + (h - 1) * 6][25 - i - 4] = 1; map[4 + (h + 1) * 6][25 - i - 4] = 1; map[3 + (h + 1) * 6][25 - i - 4] = 1; map[2 + (h + 1) * 6][25 - i - 4] = 1; map[1 + (h + 1) * 6][25 - i - 4] = 1;  mapping2();
			map[2 + (h - 1) * 6][3] = 0; map[2 + (h + 1) * 6][3] = 0; map[4 + (h - 1) * 6][25 - i - 4] = 0; map[3 + (h - 1) * 6][25 - i - 4] = 0; map[2 + (h - 1) * 6][25 - i - 4] = 0; map[1 + (h - 1) * 6][25 - i - 4] = 0; map[4 + (h + 1) * 6][25 - i - 4] = 0; map[3 + (h + 1) * 6][25 - i - 4] = 0; map[2 + (h + 1) * 6][25 - i - 4] = 0; map[1 + (h + 1) * 6][25 - i - 4] = 0;  delay(); mapping2(); break;
		case 4:
			map[3 + (h - 1) * 6][3] = 2; map[3 + (h + 1) * 6][3] = 2; map[4 + (h - 1) * 6][25 - i - 5] = 1; map[3 + (h - 1) * 6][25 - i - 5] = 1; map[2 + (h - 1) * 6][25 - i - 5] = 1; map[1 + (h - 1) * 6][25 - i - 5] = 1; map[4 + (h + 1) * 6][25 - i - 5] = 1; map[3 + (h + 1) * 6][25 - i - 5] = 1; map[2 + (h + 1) * 6][25 - i - 5] = 1; map[1 + (h + 1) * 6][25 - i - 5] = 1;  mapping2();
			map[3 + (h - 1) * 6][3] = 0; map[3 + (h + 1) * 6][3] = 0; map[4 + (h - 1) * 6][25 - i - 5] = 0; map[3 + (h - 1) * 6][25 - i - 5] = 0; map[2 + (h - 1) * 6][25 - i - 5] = 0; map[1 + (h - 1) * 6][25 - i - 5] = 0; map[4 + (h + 1) * 6][25 - i - 5] = 0; map[3 + (h + 1) * 6][25 - i - 5] = 0; map[2 + (h + 1) * 6][25 - i - 5] = 0; map[1 + (h + 1) * 6][25 - i - 5] = 0;  delay(); mapping2(); break;
		case 5:
			map[4 + (h - 1) * 6][3] = 2; map[4 + (h + 1) * 6][3] = 2; map[4 + (h - 1) * 6][25 - i - 6] = 1; map[3 + (h - 1) * 6][25 - i - 6] = 1; map[2 + (h - 1) * 6][25 - i - 6] = 1; map[1 + (h - 1) * 6][25 - i - 6] = 1; map[4 + (h + 1) * 6][25 - i - 6] = 1; map[3 + (h + 1) * 6][25 - i - 6] = 1; map[2 + (h + 1) * 6][25 - i - 6] = 1; map[1 + (h + 1) * 6][25 - i - 6] = 1;  mapping2();
			map[4 + (h - 1) * 6][3] = 0; map[4 + (h + 1) * 6][3] = 0; map[4 + (h - 1) * 6][25 - i - 6] = 0; map[3 + (h - 1) * 6][25 - i - 6] = 0; map[2 + (h - 1) * 6][25 - i - 6] = 0; map[1 + (h - 1) * 6][25 - i - 6] = 0; map[4 + (h + 1) * 6][25 - i - 6] = 0; map[3 + (h + 1) * 6][25 - i - 6] = 0; map[2 + (h + 1) * 6][25 - i - 6] = 0; map[1 + (h + 1) * 6][25 - i - 6] = 0;  delay(); mapping2(); break;
		case 6:
			map[5 + (h - 1) * 6][3] = 2; map[5 + (h + 1) * 6][3] = 2; map[4 + (h - 1) * 6][25 - i - 7] = 1; map[3 + (h - 1) * 6][25 - i - 7] = 1; map[2 + (h - 1) * 6][25 - i - 7] = 1; map[1 + (h - 1) * 6][25 - i - 7] = 1; map[4 + (h + 1) * 6][25 - i - 7] = 1; map[3 + (h + 1) * 6][25 - i - 7] = 1; map[2 + (h + 1) * 6][25 - i - 7] = 1; map[1 + (h + 1) * 6][25 - i - 7] = 1;  mapping2();
			map[4 + (h - 1) * 6][25 - i - 7] = 0; map[3 + (h - 1) * 6][25 - i - 7] = 0; map[2 + (h - 1) * 6][25 - i - 7] = 0; map[1 + (h - 1) * 6][25 - i - 7] = 0; map[4 + (h + 1) * 6][25 - i - 7] = 0; map[3 + (h + 1) * 6][25 - i - 7] = 0; map[2 + (h + 1) * 6][25 - i - 7] = 0; map[1 + (h + 1) * 6][25 - i - 7] = 0;  delay(); mapping2(); break;
		}
		step++;
		step = step % 7;
	}
}
void jump4_0_13_1(int i, int h) {
	static int step = 0;
	int j = 0;
	for (j = 0; j<7; j++) {
		switch (step) {
		case 0:
			map[5 + (h - 1) * 6][3] = 2; map[5 + (h + 1) * 6][3] = 2; map[4 + (h - 1) * 6][25 - i - 1] = 1; map[3 + (h - 1) * 6][25 - i - 1] = 1; map[2 + (h - 1) * 6][25 - i - 1] = 1; map[1 + (h - 1) * 6][25 - i - 1] = 1; map[4 + (h + 1) * 6][25 - i - 1] = 1; map[3 + (h + 1) * 6][25 - i - 1] = 1; map[2 + (h + 1) * 6][25 - i - 1] = 1; map[1 + (h + 1) * 6][25 - i - 1] = 1;  mapping2();
			map[5 + (h - 1) * 6][3] = 0; map[5 + (h + 1) * 6][3] = 0; map[4 + (h - 1) * 6][25 - i - 1] = 0; map[3 + (h - 1) * 6][25 - i - 1] = 0; map[2 + (h - 1) * 6][25 - i - 1] = 0; map[1 + (h - 1) * 6][25 - i - 1] = 0; map[4 + (h + 1) * 6][25 - i - 1] = 0; map[3 + (h + 1) * 6][25 - i - 1] = 0; map[2 + (h + 1) * 6][25 - i - 1] = 0; map[1 + (h + 1) * 6][25 - i - 1] = 0;  delay(); mapping2(); break;
		case 1:
			map[4 + (h - 1) * 6][3] = 2; map[5 + (h + 1) * 6][3] = 2; map[4 + (h - 1) * 6][25 - i - 2] = 1; map[3 + (h - 1) * 6][25 - i - 2] = 1; map[2 + (h - 1) * 6][25 - i - 2] = 1; map[1 + (h - 1) * 6][25 - i - 2] = 1; map[4 + (h + 1) * 6][25 - i - 2] = 1; map[3 + (h + 1) * 6][25 - i - 2] = 1; map[2 + (h + 1) * 6][25 - i - 2] = 1; map[1 + (h + 1) * 6][25 - i - 2] = 1;  mapping2();
			map[4 + (h - 1) * 6][3] = 0; map[5 + (h + 1) * 6][3] = 0; map[4 + (h - 1) * 6][25 - i - 2] = 0; map[3 + (h - 1) * 6][25 - i - 2] = 0; map[2 + (h - 1) * 6][25 - i - 2] = 0; map[1 + (h - 1) * 6][25 - i - 2] = 0; map[4 + (h + 1) * 6][25 - i - 2] = 0; map[3 + (h + 1) * 6][25 - i - 2] = 0; map[2 + (h + 1) * 6][25 - i - 2] = 0; map[1 + (h + 1) * 6][25 - i - 2] = 0;  delay(); mapping2(); break;
		case 2:
			map[3 + (h - 1) * 6][3] = 2; map[5 + (h + 1) * 6][3] = 2; map[4 + (h - 1) * 6][25 - i - 3] = 1; map[3 + (h - 1) * 6][25 - i - 3] = 1; map[2 + (h - 1) * 6][25 - i - 3] = 1; map[1 + (h - 1) * 6][25 - i - 3] = 1; map[4 + (h + 1) * 6][25 - i - 3] = 1; map[3 + (h + 1) * 6][25 - i - 3] = 1; map[2 + (h + 1) * 6][25 - i - 3] = 1; map[1 + (h + 1) * 6][25 - i - 3] = 1;  mapping2();
			map[3 + (h - 1) * 6][3] = 0; map[5 + (h + 1) * 6][3] = 0; map[4 + (h - 1) * 6][25 - i - 3] = 0; map[3 + (h - 1) * 6][25 - i - 3] = 0; map[2 + (h - 1) * 6][25 - i - 3] = 0; map[1 + (h - 1) * 6][25 - i - 3] = 0; map[4 + (h + 1) * 6][25 - i - 3] = 0; map[3 + (h + 1) * 6][25 - i - 3] = 0; map[2 + (h + 1) * 6][25 - i - 3] = 0; map[1 + (h + 1) * 6][25 - i - 3] = 0;  delay(); mapping2(); break;
		case 3:
			map[2 + (h - 1) * 6][3] = 2; map[5 + (h + 1) * 6][3] = 2; map[4 + (h - 1) * 6][25 - i - 4] = 1; map[3 + (h - 1) * 6][25 - i - 4] = 1; map[2 + (h - 1) * 6][25 - i - 4] = 1; map[1 + (h - 1) * 6][25 - i - 4] = 1; map[4 + (h + 1) * 6][25 - i - 4] = 1; map[3 + (h + 1) * 6][25 - i - 4] = 1; map[2 + (h + 1) * 6][25 - i - 4] = 1; map[1 + (h + 1) * 6][25 - i - 4] = 1;  mapping2();
			map[2 + (h - 1) * 6][3] = 0; map[5 + (h + 1) * 6][3] = 0; map[4 + (h - 1) * 6][25 - i - 4] = 0; map[3 + (h - 1) * 6][25 - i - 4] = 0; map[2 + (h - 1) * 6][25 - i - 4] = 0; map[1 + (h - 1) * 6][25 - i - 4] = 0; map[4 + (h + 1) * 6][25 - i - 4] = 0; map[3 + (h + 1) * 6][25 - i - 4] = 0; map[2 + (h + 1) * 6][25 - i - 4] = 0; map[1 + (h + 1) * 6][25 - i - 4] = 0;  delay(); mapping2(); break;
		case 4:
			map[3 + (h - 1) * 6][3] = 2; map[5 + (h + 1) * 6][3] = 2; map[4 + (h - 1) * 6][25 - i - 5] = 1; map[3 + (h - 1) * 6][25 - i - 5] = 1; map[2 + (h - 1) * 6][25 - i - 5] = 1; map[1 + (h - 1) * 6][25 - i - 5] = 1; map[4 + (h + 1) * 6][25 - i - 5] = 1; map[3 + (h + 1) * 6][25 - i - 5] = 1; map[2 + (h + 1) * 6][25 - i - 5] = 1; map[1 + (h + 1) * 6][25 - i - 5] = 1;  mapping2();
			map[3 + (h - 1) * 6][3] = 0; map[5 + (h + 1) * 6][3] = 0; map[4 + (h - 1) * 6][25 - i - 5] = 0; map[3 + (h - 1) * 6][25 - i - 5] = 0; map[2 + (h - 1) * 6][25 - i - 5] = 0; map[1 + (h - 1) * 6][25 - i - 5] = 0; map[4 + (h + 1) * 6][25 - i - 5] = 0; map[3 + (h + 1) * 6][25 - i - 5] = 0; map[2 + (h + 1) * 6][25 - i - 5] = 0; map[1 + (h + 1) * 6][25 - i - 5] = 0;  delay(); mapping2(); break;
		case 5:
			map[4 + (h - 1) * 6][3] = 2; map[5 + (h + 1) * 6][3] = 2; map[4 + (h - 1) * 6][25 - i - 6] = 1; map[3 + (h - 1) * 6][25 - i - 6] = 1; map[2 + (h - 1) * 6][25 - i - 6] = 1; map[1 + (h - 1) * 6][25 - i - 6] = 1; map[4 + (h + 1) * 6][25 - i - 6] = 1; map[3 + (h + 1) * 6][25 - i - 6] = 1; map[2 + (h + 1) * 6][25 - i - 6] = 1; map[1 + (h + 1) * 6][25 - i - 6] = 1;  mapping2();
			map[4 + (h - 1) * 6][3] = 0; map[5 + (h + 1) * 6][3] = 0; map[4 + (h - 1) * 6][25 - i - 6] = 0; map[3 + (h - 1) * 6][25 - i - 6] = 0; map[2 + (h - 1) * 6][25 - i - 6] = 0; map[1 + (h - 1) * 6][25 - i - 6] = 0; map[4 + (h + 1) * 6][25 - i - 6] = 0; map[3 + (h + 1) * 6][25 - i - 6] = 0; map[2 + (h + 1) * 6][25 - i - 6] = 0; map[1 + (h + 1) * 6][25 - i - 6] = 0;  delay(); mapping2(); break;
		case 6:
			map[5 + (h - 1) * 6][3] = 2; map[5 + (h + 1) * 6][3] = 2; map[4 + (h - 1) * 6][25 - i - 7] = 1; map[3 + (h - 1) * 6][25 - i - 7] = 1; map[2 + (h - 1) * 6][25 - i - 7] = 1; map[1 + (h - 1) * 6][25 - i - 7] = 1; map[4 + (h + 1) * 6][25 - i - 7] = 1; map[3 + (h + 1) * 6][25 - i - 7] = 1; map[2 + (h + 1) * 6][25 - i - 7] = 1; map[1 + (h + 1) * 6][25 - i - 7] = 1;  mapping2();
			map[4 + (h - 1) * 6][25 - i - 7] = 0; map[3 + (h - 1) * 6][25 - i - 7] = 0; map[2 + (h - 1) * 6][25 - i - 7] = 0; map[1 + (h - 1) * 6][25 - i - 7] = 0; map[4 + (h + 1) * 6][25 - i - 7] = 0; map[3 + (h + 1) * 6][25 - i - 7] = 0; map[2 + (h + 1) * 6][25 - i - 7] = 0; map[1 + (h + 1) * 6][25 - i - 7] = 0;  delay(); mapping2(); break;
		}
		step++;
		step = step % 7;
	}
}
void jump4_0_13_2(int i, int h) {
	static int step = 0;
	int j = 0;
	for (j = 0; j<7; j++) {
		switch (step) {
		case 0:
			map[5 + (h - 1) * 6][3] = 2; map[5 + (h + 1) * 6][3] = 2; map[4 + (h - 1) * 6][25 - i - 1] = 1; map[3 + (h - 1) * 6][25 - i - 1] = 1; map[2 + (h - 1) * 6][25 - i - 1] = 1; map[1 + (h - 1) * 6][25 - i - 1] = 1; map[4 + (h + 1) * 6][25 - i - 1] = 1; map[3 + (h + 1) * 6][25 - i - 1] = 1; map[2 + (h + 1) * 6][25 - i - 1] = 1; map[1 + (h + 1) * 6][25 - i - 1] = 1;  mapping2();
			map[5 + (h - 1) * 6][3] = 0; map[5 + (h + 1) * 6][3] = 0; map[4 + (h - 1) * 6][25 - i - 1] = 0; map[3 + (h - 1) * 6][25 - i - 1] = 0; map[2 + (h - 1) * 6][25 - i - 1] = 0; map[1 + (h - 1) * 6][25 - i - 1] = 0; map[4 + (h + 1) * 6][25 - i - 1] = 0; map[3 + (h + 1) * 6][25 - i - 1] = 0; map[2 + (h + 1) * 6][25 - i - 1] = 0; map[1 + (h + 1) * 6][25 - i - 1] = 0;  delay(); mapping2(); break;
		case 1:
			map[5 + (h - 1) * 6][3] = 2; map[4 + (h + 1) * 6][3] = 2; map[4 + (h - 1) * 6][25 - i - 2] = 1; map[3 + (h - 1) * 6][25 - i - 2] = 1; map[2 + (h - 1) * 6][25 - i - 2] = 1; map[1 + (h - 1) * 6][25 - i - 2] = 1; map[4 + (h + 1) * 6][25 - i - 2] = 1; map[3 + (h + 1) * 6][25 - i - 2] = 1; map[2 + (h + 1) * 6][25 - i - 2] = 1; map[1 + (h + 1) * 6][25 - i - 2] = 1;  mapping2();
			map[5 + (h - 1) * 6][3] = 0; map[4 + (h + 1) * 6][3] = 0; map[4 + (h - 1) * 6][25 - i - 2] = 0; map[3 + (h - 1) * 6][25 - i - 2] = 0; map[2 + (h - 1) * 6][25 - i - 2] = 0; map[1 + (h - 1) * 6][25 - i - 2] = 0; map[4 + (h + 1) * 6][25 - i - 2] = 0; map[3 + (h + 1) * 6][25 - i - 2] = 0; map[2 + (h + 1) * 6][25 - i - 2] = 0; map[1 + (h + 1) * 6][25 - i - 2] = 0;  delay(); mapping2(); break;
		case 2:
			map[5 + (h - 1) * 6][3] = 2; map[3 + (h + 1) * 6][3] = 2; map[4 + (h - 1) * 6][25 - i - 3] = 1; map[3 + (h - 1) * 6][25 - i - 3] = 1; map[2 + (h - 1) * 6][25 - i - 3] = 1; map[1 + (h - 1) * 6][25 - i - 3] = 1; map[4 + (h + 1) * 6][25 - i - 3] = 1; map[3 + (h + 1) * 6][25 - i - 3] = 1; map[2 + (h + 1) * 6][25 - i - 3] = 1; map[1 + (h + 1) * 6][25 - i - 3] = 1;  mapping2();
			map[5 + (h - 1) * 6][3] = 0; map[3 + (h + 1) * 6][3] = 0; map[4 + (h - 1) * 6][25 - i - 3] = 0; map[3 + (h - 1) * 6][25 - i - 3] = 0; map[2 + (h - 1) * 6][25 - i - 3] = 0; map[1 + (h - 1) * 6][25 - i - 3] = 0; map[4 + (h + 1) * 6][25 - i - 3] = 0; map[3 + (h + 1) * 6][25 - i - 3] = 0; map[2 + (h + 1) * 6][25 - i - 3] = 0; map[1 + (h + 1) * 6][25 - i - 3] = 0;  delay(); mapping2(); break;
		case 3:
			map[5 + (h - 1) * 6][3] = 2; map[2 + (h + 1) * 6][3] = 2; map[4 + (h - 1) * 6][25 - i - 4] = 1; map[3 + (h - 1) * 6][25 - i - 4] = 1; map[2 + (h - 1) * 6][25 - i - 4] = 1; map[1 + (h - 1) * 6][25 - i - 4] = 1; map[4 + (h + 1) * 6][25 - i - 4] = 1; map[3 + (h + 1) * 6][25 - i - 4] = 1; map[2 + (h + 1) * 6][25 - i - 4] = 1; map[1 + (h + 1) * 6][25 - i - 4] = 1;  mapping2();
			map[5 + (h - 1) * 6][3] = 0; map[2 + (h + 1) * 6][3] = 0; map[4 + (h - 1) * 6][25 - i - 4] = 0; map[3 + (h - 1) * 6][25 - i - 4] = 0; map[2 + (h - 1) * 6][25 - i - 4] = 0; map[1 + (h - 1) * 6][25 - i - 4] = 0; map[4 + (h + 1) * 6][25 - i - 4] = 0; map[3 + (h + 1) * 6][25 - i - 4] = 0; map[2 + (h + 1) * 6][25 - i - 4] = 0; map[1 + (h + 1) * 6][25 - i - 4] = 0;  delay(); mapping2(); break;
		case 4:
			map[5 + (h - 1) * 6][3] = 2; map[3 + (h + 1) * 6][3] = 2; map[4 + (h - 1) * 6][25 - i - 5] = 1; map[3 + (h - 1) * 6][25 - i - 5] = 1; map[2 + (h - 1) * 6][25 - i - 5] = 1; map[1 + (h - 1) * 6][25 - i - 5] = 1; map[4 + (h + 1) * 6][25 - i - 5] = 1; map[3 + (h + 1) * 6][25 - i - 5] = 1; map[2 + (h + 1) * 6][25 - i - 5] = 1; map[1 + (h + 1) * 6][25 - i - 5] = 1;  mapping2();
			map[5 + (h - 1) * 6][3] = 0; map[3 + (h + 1) * 6][3] = 0; map[4 + (h - 1) * 6][25 - i - 5] = 0; map[3 + (h - 1) * 6][25 - i - 5] = 0; map[2 + (h - 1) * 6][25 - i - 5] = 0; map[1 + (h - 1) * 6][25 - i - 5] = 0; map[4 + (h + 1) * 6][25 - i - 5] = 0; map[3 + (h + 1) * 6][25 - i - 5] = 0; map[2 + (h + 1) * 6][25 - i - 5] = 0; map[1 + (h + 1) * 6][25 - i - 5] = 0;  delay(); mapping2(); break;
		case 5:
			map[5 + (h - 1) * 6][3] = 2; map[4 + (h + 1) * 6][3] = 2; map[4 + (h - 1) * 6][25 - i - 6] = 1; map[3 + (h - 1) * 6][25 - i - 6] = 1; map[2 + (h - 1) * 6][25 - i - 6] = 1; map[1 + (h - 1) * 6][25 - i - 6] = 1; map[4 + (h + 1) * 6][25 - i - 6] = 1; map[3 + (h + 1) * 6][25 - i - 6] = 1; map[2 + (h + 1) * 6][25 - i - 6] = 1; map[1 + (h + 1) * 6][25 - i - 6] = 1;  mapping2();
			map[5 + (h - 1) * 6][3] = 0; map[4 + (h + 1) * 6][3] = 0; map[4 + (h - 1) * 6][25 - i - 6] = 0; map[3 + (h - 1) * 6][25 - i - 6] = 0; map[2 + (h - 1) * 6][25 - i - 6] = 0; map[1 + (h - 1) * 6][25 - i - 6] = 0; map[4 + (h + 1) * 6][25 - i - 6] = 0; map[3 + (h + 1) * 6][25 - i - 6] = 0; map[2 + (h + 1) * 6][25 - i - 6] = 0; map[1 + (h + 1) * 6][25 - i - 6] = 0;  delay(); mapping2(); break;
		case 6:
			map[5 + (h - 1) * 6][3] = 2; map[5 + (h + 1) * 6][3] = 2; map[4 + (h - 1) * 6][25 - i - 7] = 1; map[3 + (h - 1) * 6][25 - i - 7] = 1; map[2 + (h - 1) * 6][25 - i - 7] = 1; map[1 + (h - 1) * 6][25 - i - 7] = 1; map[4 + (h + 1) * 6][25 - i - 7] = 1; map[3 + (h + 1) * 6][25 - i - 7] = 1; map[2 + (h + 1) * 6][25 - i - 7] = 1; map[1 + (h + 1) * 6][25 - i - 7] = 1;  mapping2();
			map[4 + (h - 1) * 6][25 - i - 7] = 0; map[3 + (h - 1) * 6][25 - i - 7] = 0; map[2 + (h - 1) * 6][25 - i - 7] = 0; map[1 + (h - 1) * 6][25 - i - 7] = 0; map[4 + (h + 1) * 6][25 - i - 7] = 0; map[3 + (h + 1) * 6][25 - i - 7] = 0; map[2 + (h + 1) * 6][25 - i - 7] = 0; map[1 + (h + 1) * 6][25 - i - 7] = 0;  delay(); mapping2(); break;
		}
		step++;
		step = step % 7;
	}
}

void jump1_1(int i, int h) { // �ٲ��ٷ��� ��ֹ��� ���� �ٲ������.
	static int step = 0;
	int j = 0;
	for (j = 0; j<7; j++) {
		switch (step) {
		case 0:
			map[5 + (h - 1) * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 1] = 1; map[1 + (h - 1) * 6][25 - i - 1] = 1; mapping2();
			map[5 + (h - 1) * 6][3] = 0; map[5 + (h - 1) * 6][25 - i - 1] = 0; map[1 + (h - 1) * 6][25 - i - 1] = 0; delay(); mapping2(); break;
		case 1:
			map[4 + (h - 1) * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 2] = 1; map[1 + (h - 1) * 6][25 - i - 2] = 1; mapping2();
			map[4 + (h - 1) * 6][3] = 0; map[5 + (h - 1) * 6][25 - i - 2] = 0; map[1 + (h - 1) * 6][25 - i - 2] = 0; delay(); mapping2(); break;
		case 2:
			map[3 + (h - 1) * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 3] = 1; map[1 + (h - 1) * 6][25 - i - 3] = 1; mapping2();
			map[3 + (h - 1) * 6][3] = 0; map[5 + (h - 1) * 6][25 - i - 3] = 0; map[1 + (h - 1) * 6][25 - i - 3] = 0; delay(); mapping2(); break;
		case 3:
			map[2 + (h - 1) * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 4] = 1; map[1 + (h - 1) * 6][25 - i - 4] = 1; mapping2();
			map[2 + (h - 1) * 6][3] = 0; map[5 + (h - 1) * 6][25 - i - 4] = 0; map[1 + (h - 1) * 6][25 - i - 4] = 0; delay(); mapping2(); break;
		case 4:
			map[3 + (h - 1) * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 5] = 1; map[1 + (h - 1) * 6][25 - i - 5] = 1; mapping2();
			map[3 + (h - 1) * 6][3] = 0; map[5 + (h - 1) * 6][25 - i - 5] = 0; map[1 + (h - 1) * 6][25 - i - 5] = 0; delay(); mapping2(); break;
		case 5:
			map[4 + (h - 1) * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 6] = 1; map[1 + (h - 1) * 6][25 - i - 6] = 1; mapping2();
			map[4 + (h - 1) * 6][3] = 0; map[5 + (h - 1) * 6][25 - i - 6] = 0; map[1 + (h - 1) * 6][25 - i - 6] = 0; delay(); mapping2(); break;
		case 6:
			map[5 + (h - 1) * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 7] = 1; map[1 + (h - 1) * 6][25 - i - 7] = 1; mapping2();
			map[5 + (h - 1) * 6][25 - i - 7] = 0; map[5 + (h - 1) * 6][25 - i - 7] = 0; map[1 + (h - 1) * 6][25 - i - 7] = 0; delay(); mapping2(); break;
		}
		step++;
		step = step % 7;
	}
}
void jump1_1_12(int i, int h) { // �ٲ��ٷ��� ��ֹ��� ���� �ٲ������.
	static int step = 0;
	int j = 0;
	for (j = 0; j<7; j++) {
		switch (step) {
		case 0:
			map[5 + (h - 1) * 6][3] = 2; map[5 + h * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 1] = 1; map[1 + (h - 1) * 6][25 - i - 1] = 1; map[5 + h * 6][25 - i - 1] = 1; map[1 + h * 6][25 - i - 1] = 1; mapping2();
			map[5 + (h - 1) * 6][3] = 0; map[5 + h * 6][3] = 0; map[5 + (h - 1) * 6][25 - i - 1] = 0; map[1 + (h - 1) * 6][25 - i - 1] = 0; map[5 + h * 6][25 - i - 1] = 0; map[1 + h * 6][25 - i - 1] = 0; delay(); mapping2(); break;
		case 1:
			map[4 + (h - 1) * 6][3] = 2; map[4 + h * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 2] = 1; map[1 + (h - 1) * 6][25 - i - 2] = 1; map[5 + h * 6][25 - i - 2] = 1; map[1 + h * 6][25 - i - 2] = 1; mapping2();
			map[4 + (h - 1) * 6][3] = 0; map[4 + h * 6][3] = 0; map[5 + (h - 1) * 6][25 - i - 2] = 0; map[1 + (h - 1) * 6][25 - i - 2] = 0; map[5 + h * 6][25 - i - 2] = 0; map[1 + h * 6][25 - i - 2] = 0; delay(); mapping2(); break;
		case 2:
			map[3 + (h - 1) * 6][3] = 2; map[3 + h * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 3] = 1; map[1 + (h - 1) * 6][25 - i - 3] = 1; map[5 + h * 6][25 - i - 3] = 1; map[1 + h * 6][25 - i - 3] = 1; mapping2();
			map[3 + (h - 1) * 6][3] = 0; map[3 + h * 6][3] = 0; map[5 + (h - 1) * 6][25 - i - 3] = 0; map[1 + (h - 1) * 6][25 - i - 3] = 0; map[5 + h * 6][25 - i - 3] = 0; map[1 + h * 6][25 - i - 3] = 0; delay(); mapping2(); break;
		case 3:
			map[2 + (h - 1) * 6][3] = 2; map[2 + h * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 4] = 1; map[1 + (h - 1) * 6][25 - i - 4] = 1; map[5 + h * 6][25 - i - 4] = 1; map[1 + h * 6][25 - i - 4] = 1; mapping2();
			map[2 + (h - 1) * 6][3] = 0; map[2 + h * 6][3] = 0; map[5 + (h - 1) * 6][25 - i - 4] = 0; map[1 + (h - 1) * 6][25 - i - 4] = 0; map[5 + h * 6][25 - i - 4] = 0; map[1 + h * 6][25 - i - 4] = 0; delay(); mapping2(); break;
		case 4:
			map[3 + (h - 1) * 6][3] = 2; map[3 + h * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 5] = 1; map[1 + (h - 1) * 6][25 - i - 5] = 1; map[5 + h * 6][25 - i - 5] = 1; map[1 + h * 6][25 - i - 5] = 1; mapping2();
			map[3 + (h - 1) * 6][3] = 0; map[3 + h * 6][3] = 0; map[5 + (h - 1) * 6][25 - i - 5] = 0; map[1 + (h - 1) * 6][25 - i - 5] = 0; map[5 + h * 6][25 - i - 5] = 0; map[1 + h * 6][25 - i - 5] = 0; delay(); mapping2(); break;
		case 5:
			map[4 + (h - 1) * 6][3] = 2; map[4 + h * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 6] = 1; map[1 + (h - 1) * 6][25 - i - 6] = 1; map[5 + h * 6][25 - i - 6] = 1; map[1 + h * 6][25 - i - 6] = 1; mapping2();
			map[4 + (h - 1) * 6][3] = 0; map[4 + h * 6][3] = 0; map[5 + (h - 1) * 6][25 - i - 6] = 0; map[1 + (h - 1) * 6][25 - i - 6] = 0; map[5 + h * 6][25 - i - 6] = 0; map[1 + h * 6][25 - i - 6] = 0; delay(); mapping2(); break;
		case 6:
			map[5 + (h - 1) * 6][3] = 2; map[5 + h * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 7] = 1; map[1 + (h - 1) * 6][25 - i - 7] = 1; map[5 + h * 6][25 - i - 7] = 1; map[1 + h * 6][25 - i - 7] = 1; mapping2();
			map[5 + (h - 1) * 6][25 - i - 7] = 0; map[1 + (h - 1) * 6][25 - i - 7] = 0; map[5 + h * 6][25 - i - 7] = 0; map[1 + h * 6][25 - i - 7] = 0; delay(); mapping2(); break;
		}
		step++;
		step = step % 7;
	}
}
void jump1_1_12_1(int i, int h) { // �ٲ��ٷ��� ��ֹ��� ���� �ٲ������.
	static int step = 0;
	int j = 0;
	for (j = 0; j<7; j++) {
		switch (step) {
		case 0:
			map[5 + (h - 1) * 6][3] = 2; map[5 + h * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 1] = 1; map[1 + (h - 1) * 6][25 - i - 1] = 1; map[5 + h * 6][25 - i - 1] = 1; map[1 + h * 6][25 - i - 1] = 1; mapping2();
			map[5 + (h - 1) * 6][3] = 0; map[5 + h * 6][3] = 0; map[5 + (h - 1) * 6][25 - i - 1] = 0; map[1 + (h - 1) * 6][25 - i - 1] = 0; map[5 + h * 6][25 - i - 1] = 0; map[1 + h * 6][25 - i - 1] = 0; delay(); mapping2(); break;
		case 1:
			map[4 + (h - 1) * 6][3] = 2; map[5 + h * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 2] = 1; map[1 + (h - 1) * 6][25 - i - 2] = 1; map[5 + h * 6][25 - i - 2] = 1; map[1 + h * 6][25 - i - 2] = 1; mapping2();
			map[4 + (h - 1) * 6][3] = 0; map[5 + h * 6][3] = 0; map[5 + (h - 1) * 6][25 - i - 2] = 0; map[1 + (h - 1) * 6][25 - i - 2] = 0; map[5 + h * 6][25 - i - 2] = 0; map[1 + h * 6][25 - i - 2] = 0; delay(); mapping2(); break;
		case 2:
			map[3 + (h - 1) * 6][3] = 2; map[5 + h * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 3] = 1; map[1 + (h - 1) * 6][25 - i - 3] = 1; map[5 + h * 6][25 - i - 3] = 1; map[1 + h * 6][25 - i - 3] = 1; mapping2();
			map[3 + (h - 1) * 6][3] = 0; map[5 + h * 6][3] = 0; map[5 + (h - 1) * 6][25 - i - 3] = 0; map[1 + (h - 1) * 6][25 - i - 3] = 0; map[5 + h * 6][25 - i - 3] = 0; map[1 + h * 6][25 - i - 3] = 0; delay(); mapping2(); break;
		case 3:
			map[2 + (h - 1) * 6][3] = 2; map[5 + h * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 4] = 1; map[1 + (h - 1) * 6][25 - i - 4] = 1; map[5 + h * 6][25 - i - 4] = 1; map[1 + h * 6][25 - i - 4] = 1; mapping2();
			map[2 + (h - 1) * 6][3] = 0; map[5 + h * 6][3] = 0; map[5 + (h - 1) * 6][25 - i - 4] = 0; map[1 + (h - 1) * 6][25 - i - 4] = 0; map[5 + h * 6][25 - i - 4] = 0; map[1 + h * 6][25 - i - 4] = 0; delay(); mapping2(); break;
		case 4:
			map[3 + (h - 1) * 6][3] = 2; map[5 + h * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 5] = 1; map[1 + (h - 1) * 6][25 - i - 5] = 1; map[5 + h * 6][25 - i - 5] = 1; map[1 + h * 6][25 - i - 5] = 1; mapping2();
			map[3 + (h - 1) * 6][3] = 0; map[5 + h * 6][3] = 0; map[5 + (h - 1) * 6][25 - i - 5] = 0; map[1 + (h - 1) * 6][25 - i - 5] = 0; map[5 + h * 6][25 - i - 5] = 0; map[1 + h * 6][25 - i - 5] = 0; delay(); mapping2(); break;
		case 5:
			map[4 + (h - 1) * 6][3] = 2; map[5 + h * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 6] = 1; map[1 + (h - 1) * 6][25 - i - 6] = 1; map[5 + h * 6][25 - i - 6] = 1; map[1 + h * 6][25 - i - 6] = 1; mapping2();
			map[4 + (h - 1) * 6][3] = 0; map[5 + h * 6][3] = 0; map[5 + (h - 1) * 6][25 - i - 6] = 0; map[1 + (h - 1) * 6][25 - i - 6] = 0; map[5 + h * 6][25 - i - 6] = 0; map[1 + h * 6][25 - i - 6] = 0; delay(); mapping2(); break;
		case 6:
			map[5 + (h - 1) * 6][3] = 2; map[5 + h * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 7] = 1; map[1 + (h - 1) * 6][25 - i - 7] = 1; map[5 + h * 6][25 - i - 7] = 1; map[1 + h * 6][25 - i - 7] = 1; mapping2();
			map[5 + (h - 1) * 6][25 - i - 7] = 0; map[1 + (h - 1) * 6][25 - i - 7] = 0; map[5 + h * 6][25 - i - 7] = 0; map[1 + h * 6][25 - i - 7] = 0; delay(); mapping2(); break;
		}
		step++;
		step = step % 7;
	}
}
void jump1_1_12_2(int i, int h) { // �ٲ��ٷ��� ��ֹ��� ���� �ٲ������.
	static int step = 0;
	int j = 0;
	for (j = 0; j<7; j++) {
		switch (step) {
		case 0:
			map[5 + (h - 1) * 6][3] = 2; map[5 + h * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 1] = 1; map[1 + (h - 1) * 6][25 - i - 1] = 1; map[5 + h * 6][25 - i - 1] = 1; map[1 + h * 6][25 - i - 1] = 1; mapping2();
			map[5 + (h - 1) * 6][3] = 0; map[5 + h * 6][3] = 0; map[5 + (h - 1) * 6][25 - i - 1] = 0; map[1 + (h - 1) * 6][25 - i - 1] = 0; map[5 + h * 6][25 - i - 1] = 0; map[1 + h * 6][25 - i - 1] = 0; delay(); mapping2(); break;
		case 1:
			map[5 + (h - 1) * 6][3] = 2; map[4 + h * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 2] = 1; map[1 + (h - 1) * 6][25 - i - 2] = 1; map[5 + h * 6][25 - i - 2] = 1; map[1 + h * 6][25 - i - 2] = 1; mapping2();
			map[5 + (h - 1) * 6][3] = 0; map[4 + h * 6][3] = 0; map[5 + (h - 1) * 6][25 - i - 2] = 0; map[1 + (h - 1) * 6][25 - i - 2] = 0; map[5 + h * 6][25 - i - 2] = 0; map[1 + h * 6][25 - i - 2] = 0; delay(); mapping2(); break;
		case 2:
			map[5 + (h - 1) * 6][3] = 2; map[3 + h * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 3] = 1; map[1 + (h - 1) * 6][25 - i - 3] = 1; map[5 + h * 6][25 - i - 3] = 1; map[1 + h * 6][25 - i - 3] = 1; mapping2();
			map[5 + (h - 1) * 6][3] = 0; map[3 + h * 6][3] = 0; map[5 + (h - 1) * 6][25 - i - 3] = 0; map[1 + (h - 1) * 6][25 - i - 3] = 0; map[5 + h * 6][25 - i - 3] = 0; map[1 + h * 6][25 - i - 3] = 0; delay(); mapping2(); break;
		case 3:
			map[5 + (h - 1) * 6][3] = 2; map[2 + h * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 4] = 1; map[1 + (h - 1) * 6][25 - i - 4] = 1; map[5 + h * 6][25 - i - 4] = 1; map[1 + h * 6][25 - i - 4] = 1; mapping2();
			map[5 + (h - 1) * 6][3] = 0; map[2 + h * 6][3] = 0; map[5 + (h - 1) * 6][25 - i - 4] = 0; map[1 + (h - 1) * 6][25 - i - 4] = 0; map[5 + h * 6][25 - i - 4] = 0; map[1 + h * 6][25 - i - 4] = 0; delay(); mapping2(); break;
		case 4:
			map[5 + (h - 1) * 6][3] = 2; map[3 + h * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 5] = 1; map[1 + (h - 1) * 6][25 - i - 5] = 1; map[5 + h * 6][25 - i - 5] = 1; map[1 + h * 6][25 - i - 5] = 1; mapping2();
			map[5 + (h - 1) * 6][3] = 0; map[3 + h * 6][3] = 0; map[5 + (h - 1) * 6][25 - i - 5] = 0; map[1 + (h - 1) * 6][25 - i - 5] = 0; map[5 + h * 6][25 - i - 5] = 0; map[1 + h * 6][25 - i - 5] = 0; delay(); mapping2(); break;
		case 5:
			map[5 + (h - 1) * 6][3] = 2; map[4 + h * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 6] = 1; map[1 + (h - 1) * 6][25 - i - 6] = 1; map[5 + h * 6][25 - i - 6] = 1; map[1 + h * 6][25 - i - 6] = 1; mapping2();
			map[5 + (h - 1) * 6][3] = 0; map[4 + h * 6][3] = 0; map[5 + (h - 1) * 6][25 - i - 6] = 0; map[1 + (h - 1) * 6][25 - i - 6] = 0; map[5 + h * 6][25 - i - 6] = 0; map[1 + h * 6][25 - i - 6] = 0; delay(); mapping2(); break;
		case 6:
			map[5 + (h - 1) * 6][3] = 2; map[5 + h * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 7] = 1; map[1 + (h - 1) * 6][25 - i - 7] = 1; map[5 + h * 6][25 - i - 7] = 1; map[1 + h * 6][25 - i - 7] = 1; mapping2();
			map[5 + (h - 1) * 6][25 - i - 7] = 0; map[1 + (h - 1) * 6][25 - i - 7] = 0; map[5 + h * 6][25 - i - 7] = 0; map[1 + h * 6][25 - i - 7] = 0; delay(); mapping2(); break;
		}
		step++;
		step = step % 7;
	}
}
void jump1_1_13(int i, int h) { // �ٲ��ٷ��� ��ֹ��� ���� �ٲ������.
	static int step = 0;
	int j = 0;
	for (j = 0; j<7; j++) {
		switch (step) {
		case 0:
			map[5 + (h - 1) * 6][3] = 2; map[5 + (h + 1) * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 1] = 1; map[1 + (h - 1) * 6][25 - i - 1] = 1; map[5 + (h + 1) * 6][25 - i - 1] = 1; map[1 + (h + 1) * 6][25 - i - 1] = 1; mapping2();
			map[5 + (h - 1) * 6][3] = 0; map[5 + (h + 1) * 6][3] = 0; map[5 + (h - 1) * 6][25 - i - 1] = 0; map[1 + (h - 1) * 6][25 - i - 1] = 0; map[5 + (h + 1) * 6][25 - i - 1] = 0; map[1 + (h + 1) * 6][25 - i - 1] = 0; delay(); mapping2(); break;
		case 1:
			map[4 + (h - 1) * 6][3] = 2; map[4 + (h + 1) * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 2] = 1; map[1 + (h - 1) * 6][25 - i - 2] = 1; map[5 + (h + 1) * 6][25 - i - 2] = 1; map[1 + (h + 1) * 6][25 - i - 2] = 1; mapping2();
			map[4 + (h - 1) * 6][3] = 0; map[4 + (h + 1) * 6][3] = 0; map[5 + (h - 1) * 6][25 - i - 2] = 0; map[1 + (h - 1) * 6][25 - i - 2] = 0; map[5 + (h + 1) * 6][25 - i - 2] = 0; map[1 + (h + 1) * 6][25 - i - 2] = 0; delay(); mapping2(); break;
		case 2:
			map[3 + (h - 1) * 6][3] = 2; map[3 + (h + 1) * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 3] = 1; map[1 + (h - 1) * 6][25 - i - 3] = 1; map[5 + (h + 1) * 6][25 - i - 3] = 1; map[1 + (h + 1) * 6][25 - i - 3] = 1; mapping2();
			map[3 + (h - 1) * 6][3] = 0; map[3 + (h + 1) * 6][3] = 0; map[5 + (h - 1) * 6][25 - i - 3] = 0; map[1 + (h - 1) * 6][25 - i - 3] = 0; map[5 + (h + 1) * 6][25 - i - 3] = 0; map[1 + (h + 1) * 6][25 - i - 3] = 0; delay(); mapping2(); break;
		case 3:
			map[2 + (h - 1) * 6][3] = 2; map[2 + (h + 1) * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 4] = 1; map[1 + (h - 1) * 6][25 - i - 4] = 1; map[5 + (h + 1) * 6][25 - i - 4] = 1; map[1 + (h + 1) * 6][25 - i - 4] = 1; mapping2();
			map[2 + (h - 1) * 6][3] = 0; map[2 + (h + 1) * 6][3] = 0; map[5 + (h - 1) * 6][25 - i - 4] = 0; map[1 + (h - 1) * 6][25 - i - 4] = 0; map[5 + (h + 1) * 6][25 - i - 4] = 0; map[1 + (h + 1) * 6][25 - i - 4] = 0; delay(); mapping2(); break;
		case 4:
			map[3 + (h - 1) * 6][3] = 2; map[3 + (h + 1) * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 5] = 1; map[1 + (h - 1) * 6][25 - i - 5] = 1; map[5 + (h + 1) * 6][25 - i - 5] = 1; map[1 + (h + 1) * 6][25 - i - 5] = 1; mapping2();
			map[3 + (h - 1) * 6][3] = 0; map[3 + (h + 1) * 6][3] = 0; map[5 + (h - 1) * 6][25 - i - 5] = 0; map[1 + (h - 1) * 6][25 - i - 5] = 0; map[5 + (h + 1) * 6][25 - i - 5] = 0; map[1 + (h + 1) * 6][25 - i - 5] = 0; delay(); mapping2(); break;
		case 5:
			map[4 + (h - 1) * 6][3] = 2; map[4 + (h + 1) * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 6] = 1; map[1 + (h - 1) * 6][25 - i - 6] = 1; map[5 + (h + 1) * 6][25 - i - 6] = 1; map[1 + (h + 1) * 6][25 - i - 6] = 1; mapping2();
			map[4 + (h - 1) * 6][3] = 0; map[4 + (h + 1) * 6][3] = 0; map[5 + (h - 1) * 6][25 - i - 6] = 0; map[1 + (h - 1) * 6][25 - i - 6] = 0; map[5 + (h + 1) * 6][25 - i - 6] = 0; map[1 + (h + 1) * 6][25 - i - 6] = 0; delay(); mapping2(); break;
		case 6:
			map[5 + (h - 1) * 6][3] = 2; map[5 + (h + 1) * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 7] = 1; map[1 + (h - 1) * 6][25 - i - 7] = 1; map[5 + (h + 1) * 6][25 - i - 7] = 1; map[1 + (h + 1) * 6][25 - i - 7] = 1; mapping2();
			map[5 + (h - 1) * 6][25 - i - 7] = 0; map[1 + (h - 1) * 6][25 - i - 7] = 0; map[5 + (h + 1) * 6][25 - i - 7] = 0; map[1 + (h + 1) * 6][25 - i - 7] = 0; delay(); mapping2(); break;
		}
		step++;
		step = step % 7;
	}
}
void jump1_1_13_1(int i, int h) { // �ٲ��ٷ��� ��ֹ��� ���� �ٲ������.
	static int step = 0;
	int j = 0;
	for (j = 0; j<7; j++) {
		switch (step) {
		case 0:
			map[5 + (h - 1) * 6][3] = 2; map[5 + (h + 1) * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 1] = 1; map[1 + (h - 1) * 6][25 - i - 1] = 1; map[5 + (h + 1) * 6][25 - i - 1] = 1; map[1 + (h + 1) * 6][25 - i - 1] = 1; mapping2();
			map[5 + (h - 1) * 6][3] = 0; map[5 + (h + 1) * 6][3] = 0; map[5 + (h - 1) * 6][25 - i - 1] = 0; map[1 + (h - 1) * 6][25 - i - 1] = 0; map[5 + (h + 1) * 6][25 - i - 1] = 0; map[1 + (h + 1) * 6][25 - i - 1] = 0; delay(); mapping2(); break;
		case 1:
			map[4 + (h - 1) * 6][3] = 2; map[5 + (h + 1) * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 2] = 1; map[1 + (h - 1) * 6][25 - i - 2] = 1; map[5 + (h + 1) * 6][25 - i - 2] = 1; map[1 + (h + 1) * 6][25 - i - 2] = 1; mapping2();
			map[4 + (h - 1) * 6][3] = 0; map[5 + (h + 1) * 6][3] = 0; map[5 + (h - 1) * 6][25 - i - 2] = 0; map[1 + (h - 1) * 6][25 - i - 2] = 0; map[5 + (h + 1) * 6][25 - i - 2] = 0; map[1 + (h + 1) * 6][25 - i - 2] = 0; delay(); mapping2(); break;
		case 2:
			map[3 + (h - 1) * 6][3] = 2; map[5 + (h + 1) * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 3] = 1; map[1 + (h - 1) * 6][25 - i - 3] = 1; map[5 + (h + 1) * 6][25 - i - 3] = 1; map[1 + (h + 1) * 6][25 - i - 3] = 1; mapping2();
			map[3 + (h - 1) * 6][3] = 0; map[5 + (h + 1) * 6][3] = 0; map[5 + (h - 1) * 6][25 - i - 3] = 0; map[1 + (h - 1) * 6][25 - i - 3] = 0; map[5 + (h + 1) * 6][25 - i - 3] = 0; map[1 + (h + 1) * 6][25 - i - 3] = 0; delay(); mapping2(); break;
		case 3:
			map[2 + (h - 1) * 6][3] = 2; map[5 + (h + 1) * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 4] = 1; map[1 + (h - 1) * 6][25 - i - 4] = 1; map[5 + (h + 1) * 6][25 - i - 4] = 1; map[1 + (h + 1) * 6][25 - i - 4] = 1; mapping2();
			map[2 + (h - 1) * 6][3] = 0; map[5 + (h + 1) * 6][3] = 0; map[5 + (h - 1) * 6][25 - i - 4] = 0; map[1 + (h - 1) * 6][25 - i - 4] = 0; map[5 + (h + 1) * 6][25 - i - 4] = 0; map[1 + (h + 1) * 6][25 - i - 4] = 0; delay(); mapping2(); break;
		case 4:
			map[3 + (h - 1) * 6][3] = 2; map[5 + (h + 1) * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 5] = 1; map[1 + (h - 1) * 6][25 - i - 5] = 1; map[5 + (h + 1) * 6][25 - i - 5] = 1; map[1 + (h + 1) * 6][25 - i - 5] = 1; mapping2();
			map[3 + (h - 1) * 6][3] = 0; map[5 + (h + 1) * 6][3] = 0; map[5 + (h - 1) * 6][25 - i - 5] = 0; map[1 + (h - 1) * 6][25 - i - 5] = 0; map[5 + (h + 1) * 6][25 - i - 5] = 0; map[1 + (h + 1) * 6][25 - i - 5] = 0; delay(); mapping2(); break;
		case 5:
			map[4 + (h - 1) * 6][3] = 2; map[5 + (h + 1) * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 6] = 1; map[1 + (h - 1) * 6][25 - i - 6] = 1; map[5 + (h + 1) * 6][25 - i - 6] = 1; map[1 + (h + 1) * 6][25 - i - 6] = 1; mapping2();
			map[4 + (h - 1) * 6][3] = 0; map[5 + (h + 1) * 6][3] = 0; map[5 + (h - 1) * 6][25 - i - 6] = 0; map[1 + (h - 1) * 6][25 - i - 6] = 0; map[5 + (h + 1) * 6][25 - i - 6] = 0; map[1 + (h + 1) * 6][25 - i - 6] = 0; delay(); mapping2(); break;
		case 6:
			map[5 + (h - 1) * 6][3] = 2; map[5 + (h + 1) * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 7] = 1; map[1 + (h - 1) * 6][25 - i - 7] = 1; map[5 + (h + 1) * 6][25 - i - 7] = 1; map[1 + (h + 1) * 6][25 - i - 7] = 1; mapping2();
			map[5 + (h - 1) * 6][25 - i - 7] = 0; map[1 + (h - 1) * 6][25 - i - 7] = 0; map[5 + (h + 1) * 6][25 - i - 7] = 0; map[1 + (h + 1) * 6][25 - i - 7] = 0; delay(); mapping2(); break;
		}
		step++;
		step = step % 7;
	}
}
void jump1_1_13_2(int i, int h) { // �ٲ��ٷ��� ��ֹ��� ���� �ٲ������.
	static int step = 0;
	int j = 0;
	for (j = 0; j<7; j++) {
		switch (step) {
		case 0:
			map[5 + (h - 1) * 6][3] = 2; map[5 + (h + 1) * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 1] = 1; map[1 + (h - 1) * 6][25 - i - 1] = 1; map[5 + (h + 1) * 6][25 - i - 1] = 1; map[1 + (h + 1) * 6][25 - i - 1] = 1; mapping2();
			map[5 + (h - 1) * 6][3] = 0; map[5 + (h + 1) * 6][3] = 0; map[5 + (h - 1) * 6][25 - i - 1] = 0; map[1 + (h - 1) * 6][25 - i - 1] = 0; map[5 + (h + 1) * 6][25 - i - 1] = 0; map[1 + (h + 1) * 6][25 - i - 1] = 0; delay(); mapping2(); break;
		case 1:
			map[5 + (h - 1) * 6][3] = 2; map[4 + (h + 1) * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 2] = 1; map[1 + (h - 1) * 6][25 - i - 2] = 1; map[5 + (h + 1) * 6][25 - i - 2] = 1; map[1 + (h + 1) * 6][25 - i - 2] = 1; mapping2();
			map[5 + (h - 1) * 6][3] = 0; map[4 + (h + 1) * 6][3] = 0; map[5 + (h - 1) * 6][25 - i - 2] = 0; map[1 + (h - 1) * 6][25 - i - 2] = 0; map[5 + (h + 1) * 6][25 - i - 2] = 0; map[1 + (h + 1) * 6][25 - i - 2] = 0; delay(); mapping2(); break;
		case 2:
			map[5 + (h - 1) * 6][3] = 2; map[3 + (h + 1) * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 3] = 1; map[1 + (h - 1) * 6][25 - i - 3] = 1; map[5 + (h + 1) * 6][25 - i - 3] = 1; map[1 + (h + 1) * 6][25 - i - 3] = 1; mapping2();
			map[5 + (h - 1) * 6][3] = 0; map[3 + (h + 1) * 6][3] = 0; map[5 + (h - 1) * 6][25 - i - 3] = 0; map[1 + (h - 1) * 6][25 - i - 3] = 0; map[5 + (h + 1) * 6][25 - i - 3] = 0; map[1 + (h + 1) * 6][25 - i - 3] = 0; delay(); mapping2(); break;
		case 3:
			map[5 + (h - 1) * 6][3] = 2; map[2 + (h + 1) * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 4] = 1; map[1 + (h - 1) * 6][25 - i - 4] = 1; map[5 + (h + 1) * 6][25 - i - 4] = 1; map[1 + (h + 1) * 6][25 - i - 4] = 1; mapping2();
			map[5 + (h - 1) * 6][3] = 0; map[2 + (h + 1) * 6][3] = 0; map[5 + (h - 1) * 6][25 - i - 4] = 0; map[1 + (h - 1) * 6][25 - i - 4] = 0; map[5 + (h + 1) * 6][25 - i - 4] = 0; map[1 + (h + 1) * 6][25 - i - 4] = 0; delay(); mapping2(); break;
		case 4:
			map[5 + (h - 1) * 6][3] = 2; map[3 + (h + 1) * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 5] = 1; map[1 + (h - 1) * 6][25 - i - 5] = 1; map[5 + (h + 1) * 6][25 - i - 5] = 1; map[1 + (h + 1) * 6][25 - i - 5] = 1; mapping2();
			map[5 + (h - 1) * 6][3] = 0; map[3 + (h + 1) * 6][3] = 0; map[5 + (h - 1) * 6][25 - i - 5] = 0; map[1 + (h - 1) * 6][25 - i - 5] = 0; map[5 + (h + 1) * 6][25 - i - 5] = 0; map[1 + (h + 1) * 6][25 - i - 5] = 0; delay(); mapping2(); break;
		case 5:
			map[5 + (h - 1) * 6][3] = 2; map[4 + (h + 1) * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 6] = 1; map[1 + (h - 1) * 6][25 - i - 6] = 1; map[5 + (h + 1) * 6][25 - i - 6] = 1; map[1 + (h + 1) * 6][25 - i - 6] = 1; mapping2();
			map[5 + (h - 1) * 6][3] = 0; map[4 + (h + 1) * 6][3] = 0; map[5 + (h - 1) * 6][25 - i - 6] = 0; map[1 + (h - 1) * 6][25 - i - 6] = 0; map[5 + (h + 1) * 6][25 - i - 6] = 0; map[1 + (h + 1) * 6][25 - i - 6] = 0; delay(); mapping2(); break;
		case 6:
			map[5 + (h - 1) * 6][3] = 2; map[5 + (h + 1) * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 7] = 1; map[1 + (h - 1) * 6][25 - i - 7] = 1; map[5 + (h + 1) * 6][25 - i - 7] = 1; map[1 + (h + 1) * 6][25 - i - 7] = 1; mapping2();
			map[5 + (h - 1) * 6][25 - i - 7] = 0; map[1 + (h - 1) * 6][25 - i - 7] = 0; map[5 + (h + 1) * 6][25 - i - 7] = 0; map[1 + (h + 1) * 6][25 - i - 7] = 0; delay(); mapping2(); break;
		}
		step++;
		step = step % 7;
	}
}

void jump2_1(int i, int h) { // �ٲ��ٷ��� ��ֹ��� ���� �ٲ������.
	static int step = 0;
	int j = 0;
	for (j = 0; j<7; j++) {
		switch (step) {
		case 0:
			map[5 + (h - 1) * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 1] = 1; map[2 + (h - 1) * 6][25 - i - 1] = 1; map[1 + (h - 1) * 6][25 - i - 1] = 1; mapping2();
			map[5 + (h - 1) * 6][3] = 0; map[5 + (h - 1) * 6][25 - i - 1] = 0; map[2 + (h - 1) * 6][25 - i - 1] = 0; map[1 + (h - 1) * 6][25 - i - 1] = 0; delay(); mapping2(); break;
		case 1:
			map[4 + (h - 1) * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 2] = 1; map[2 + (h - 1) * 6][25 - i - 2] = 1; map[1 + (h - 1) * 6][25 - i - 2] = 1; mapping2();
			map[4 + (h - 1) * 6][3] = 0; map[5 + (h - 1) * 6][25 - i - 2] = 0; map[2 + (h - 1) * 6][25 - i - 2] = 0; map[1 + (h - 1) * 6][25 - i - 2] = 0; delay(); mapping2(); break;
		case 2:
			map[3 + (h - 1) * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 3] = 1; map[2 + (h - 1) * 6][25 - i - 3] = 1; map[1 + (h - 1) * 6][25 - i - 3] = 1; mapping2();
			map[3 + (h - 1) * 6][3] = 0; map[5 + (h - 1) * 6][25 - i - 3] = 0; map[2 + (h - 1) * 6][25 - i - 3] = 0; map[1 + (h - 1) * 6][25 - i - 3] = 0; delay(); mapping2(); break;
		case 3:
			map[2 + (h - 1) * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 4] = 1; map[2 + (h - 1) * 6][25 - i - 4] = 1; map[1 + (h - 1) * 6][25 - i - 4] = 1; mapping2();
			map[2 + (h - 1) * 6][3] = 0; map[5 + (h - 1) * 6][25 - i - 4] = 0; map[2 + (h - 1) * 6][25 - i - 4] = 0; map[1 + (h - 1) * 6][25 - i - 4] = 0; delay(); mapping2(); break;
		case 4:
			map[3 + (h - 1) * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 5] = 1; map[2 + (h - 1) * 6][25 - i - 5] = 1; map[1 + (h - 1) * 6][25 - i - 5] = 1; mapping2();
			map[3 + (h - 1) * 6][3] = 0; map[5 + (h - 1) * 6][25 - i - 5] = 0; map[2 + (h - 1) * 6][25 - i - 5] = 0; map[1 + (h - 1) * 6][25 - i - 5] = 0; delay(); mapping2(); break;
		case 5:
			map[4 + (h - 1) * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 6] = 1; map[2 + (h - 1) * 6][25 - i - 6] = 1; map[1 + (h - 1) * 6][25 - i - 6] = 1; mapping2();
			map[4 + (h - 1) * 6][3] = 0; map[5 + (h - 1) * 6][25 - i - 6] = 0; map[2 + (h - 1) * 6][25 - i - 6] = 0; map[1 + (h - 1) * 6][25 - i - 6] = 0; delay(); mapping2(); break;
		case 6:
			map[5 + (h - 1) * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 7] = 1; map[2 + (h - 1) * 6][25 - i - 7] = 1; map[1 + (h - 1) * 6][25 - i - 7] = 1; mapping2();
			map[5 + (h - 1) * 6][25 - i - 7] = 0; map[5 + (h - 1) * 6][25 - i - 7] = 0; map[2 + (h - 1) * 6][25 - i - 7] = 0; map[1 + (h - 1) * 6][25 - i - 7] = 0; delay(); mapping2(); break;
		}
		step++;
		step = step % 7;
	}
}
void jump2_1_12(int i, int h) { // �ٲ��ٷ��� ��ֹ��� ���� �ٲ������.
	static int step = 0;
	int j = 0;
	for (j = 0; j<7; j++) {
		switch (step) {
		case 0:
			map[5 + (h - 1) * 6][3] = 2; map[5 + h * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 1] = 1; map[2 + (h - 1) * 6][25 - i - 1] = 1; map[1 + (h - 1) * 6][25 - i - 1] = 1; map[5 + h * 6][25 - i - 1] = 1; map[2 + h * 6][25 - i - 1] = 1; map[1 + h * 6][25 - i - 1] = 1; mapping2();
			map[5 + (h - 1) * 6][3] = 0; map[5 + h * 6][3] = 0; map[5 + (h - 1) * 6][25 - i - 1] = 0; map[2 + (h - 1) * 6][25 - i - 1] = 0; map[1 + (h - 1) * 6][25 - i - 1] = 0; map[5 + h * 6][25 - i - 1] = 0; map[2 + h * 6][25 - i - 1] = 0; map[1 + h * 6][25 - i - 1] = 0; delay(); mapping2(); break;
		case 1:
			map[4 + (h - 1) * 6][3] = 2; map[4 + h * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 2] = 1; map[2 + (h - 1) * 6][25 - i - 2] = 1; map[1 + (h - 1) * 6][25 - i - 2] = 1; map[5 + h * 6][25 - i - 2] = 1; map[2 + h * 6][25 - i - 2] = 1; map[1 + h * 6][25 - i - 2] = 1; mapping2();
			map[4 + (h - 1) * 6][3] = 0; map[4 + h * 6][3] = 0; map[5 + (h - 1) * 6][25 - i - 2] = 0; map[2 + (h - 1) * 6][25 - i - 2] = 0; map[1 + (h - 1) * 6][25 - i - 2] = 0; map[5 + h * 6][25 - i - 2] = 0; map[2 + h * 6][25 - i - 2] = 0; map[1 + h * 6][25 - i - 2] = 0; delay(); mapping2(); break;
		case 2:
			map[3 + (h - 1) * 6][3] = 2; map[3 + h * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 3] = 1; map[2 + (h - 1) * 6][25 - i - 3] = 1; map[1 + (h - 1) * 6][25 - i - 3] = 1; map[5 + h * 6][25 - i - 3] = 1; map[2 + h * 6][25 - i - 3] = 1; map[1 + h * 6][25 - i - 3] = 1; mapping2();
			map[3 + (h - 1) * 6][3] = 0; map[3 + h * 6][3] = 0; map[5 + (h - 1) * 6][25 - i - 3] = 0; map[2 + (h - 1) * 6][25 - i - 3] = 0; map[1 + (h - 1) * 6][25 - i - 3] = 0; map[5 + h * 6][25 - i - 3] = 0; map[2 + h * 6][25 - i - 3] = 0; map[1 + h * 6][25 - i - 3] = 0; delay(); mapping2(); break;
		case 3:
			map[2 + (h - 1) * 6][3] = 2; map[2 + h * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 4] = 1; map[2 + (h - 1) * 6][25 - i - 4] = 1; map[1 + (h - 1) * 6][25 - i - 4] = 1; map[5 + h * 6][25 - i - 4] = 1; map[2 + h * 6][25 - i - 4] = 1; map[1 + h * 6][25 - i - 4] = 1; mapping2();
			map[2 + (h - 1) * 6][3] = 0; map[2 + h * 6][3] = 0; map[5 + (h - 1) * 6][25 - i - 4] = 0; map[2 + (h - 1) * 6][25 - i - 4] = 0; map[1 + (h - 1) * 6][25 - i - 4] = 0; map[5 + h * 6][25 - i - 4] = 0; map[2 + h * 6][25 - i - 4] = 0; map[1 + h * 6][25 - i - 4] = 0; delay(); mapping2(); break;
		case 4:
			map[3 + (h - 1) * 6][3] = 2; map[3 + h * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 5] = 1; map[2 + (h - 1) * 6][25 - i - 5] = 1; map[1 + (h - 1) * 6][25 - i - 5] = 1; map[5 + h * 6][25 - i - 5] = 1; map[2 + h * 6][25 - i - 5] = 1; map[1 + h * 6][25 - i - 5] = 1; mapping2();
			map[3 + (h - 1) * 6][3] = 0; map[3 + h * 6][3] = 0; map[5 + (h - 1) * 6][25 - i - 5] = 0; map[2 + (h - 1) * 6][25 - i - 5] = 0; map[1 + (h - 1) * 6][25 - i - 5] = 0; map[5 + h * 6][25 - i - 5] = 0; map[2 + h * 6][25 - i - 5] = 0; map[1 + h * 6][25 - i - 5] = 0; delay(); mapping2(); break;
		case 5:
			map[4 + (h - 1) * 6][3] = 2; map[4 + h * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 6] = 1; map[2 + (h - 1) * 6][25 - i - 6] = 1; map[1 + (h - 1) * 6][25 - i - 6] = 1; map[5 + h * 6][25 - i - 6] = 1; map[2 + h * 6][25 - i - 6] = 1; map[1 + h * 6][25 - i - 6] = 1; mapping2();
			map[4 + (h - 1) * 6][3] = 0; map[4 + h * 6][3] = 0; map[5 + (h - 1) * 6][25 - i - 6] = 0; map[2 + (h - 1) * 6][25 - i - 6] = 0; map[1 + (h - 1) * 6][25 - i - 6] = 0; map[5 + h * 6][25 - i - 6] = 0; map[2 + h * 6][25 - i - 6] = 0; map[1 + h * 6][25 - i - 6] = 0; delay(); mapping2(); break;
		case 6:
			map[5 + (h - 1) * 6][3] = 2; map[5 + h * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 7] = 1; map[2 + (h - 1) * 6][25 - i - 7] = 1; map[1 + (h - 1) * 6][25 - i - 7] = 1; map[5 + h * 6][25 - i - 7] = 1; map[2 + h * 6][25 - i - 7] = 1; map[1 + h * 6][25 - i - 7] = 1; mapping2();
			map[5 + (h - 1) * 6][25 - i - 7] = 0; map[2 + (h - 1) * 6][25 - i - 7] = 0; map[1 + (h - 1) * 6][25 - i - 7] = 0; map[5 + h * 6][25 - i - 7] = 0; map[2 + h * 6][25 - i - 7] = 0; map[1 + h * 6][25 - i - 7] = 0; delay(); mapping2(); break;
		}
		step++;
		step = step % 7;
	}
}
void jump2_1_12_1(int i, int h) { // �ٲ��ٷ��� ��ֹ��� ���� �ٲ������.
	static int step = 0;
	int j = 0;
	for (j = 0; j<7; j++) {
		switch (step) {
		case 0:
			map[5 + (h - 1) * 6][3] = 2; map[5 + h * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 1] = 1; map[2 + (h - 1) * 6][25 - i - 1] = 1; map[1 + (h - 1) * 6][25 - i - 1] = 1; map[5 + h * 6][25 - i - 1] = 1; map[2 + h * 6][25 - i - 1] = 1; map[1 + h * 6][25 - i - 1] = 1; mapping2();
			map[5 + (h - 1) * 6][3] = 0; map[5 + h * 6][3] = 0; map[5 + (h - 1) * 6][25 - i - 1] = 0; map[2 + (h - 1) * 6][25 - i - 1] = 0; map[1 + (h - 1) * 6][25 - i - 1] = 0; map[5 + h * 6][25 - i - 1] = 0; map[2 + h * 6][25 - i - 1] = 0; map[1 + h * 6][25 - i - 1] = 0; delay(); mapping2(); break;
		case 1:
			map[4 + (h - 1) * 6][3] = 2; map[5 + h * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 2] = 1; map[2 + (h - 1) * 6][25 - i - 2] = 1; map[1 + (h - 1) * 6][25 - i - 2] = 1; map[5 + h * 6][25 - i - 2] = 1; map[2 + h * 6][25 - i - 2] = 1; map[1 + h * 6][25 - i - 2] = 1; mapping2();
			map[4 + (h - 1) * 6][3] = 0; map[5 + h * 6][3] = 0; map[5 + (h - 1) * 6][25 - i - 2] = 0; map[2 + (h - 1) * 6][25 - i - 2] = 0; map[1 + (h - 1) * 6][25 - i - 2] = 0; map[5 + h * 6][25 - i - 2] = 0; map[2 + h * 6][25 - i - 2] = 0; map[1 + h * 6][25 - i - 2] = 0; delay(); mapping2(); break;
		case 2:
			map[3 + (h - 1) * 6][3] = 2; map[5 + h * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 3] = 1; map[2 + (h - 1) * 6][25 - i - 3] = 1; map[1 + (h - 1) * 6][25 - i - 3] = 1; map[5 + h * 6][25 - i - 3] = 1; map[2 + h * 6][25 - i - 3] = 1; map[1 + h * 6][25 - i - 3] = 1; mapping2();
			map[3 + (h - 1) * 6][3] = 0; map[5 + h * 6][3] = 0; map[5 + (h - 1) * 6][25 - i - 3] = 0; map[2 + (h - 1) * 6][25 - i - 3] = 0; map[1 + (h - 1) * 6][25 - i - 3] = 0; map[5 + h * 6][25 - i - 3] = 0; map[2 + h * 6][25 - i - 3] = 0; map[1 + h * 6][25 - i - 3] = 0; delay(); mapping2(); break;
		case 3:
			map[2 + (h - 1) * 6][3] = 2; map[5 + h * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 4] = 1; map[2 + (h - 1) * 6][25 - i - 4] = 1; map[1 + (h - 1) * 6][25 - i - 4] = 1; map[5 + h * 6][25 - i - 4] = 1; map[2 + h * 6][25 - i - 4] = 1; map[1 + h * 6][25 - i - 4] = 1; mapping2();
			map[2 + (h - 1) * 6][3] = 0; map[5 + h * 6][3] = 0; map[5 + (h - 1) * 6][25 - i - 4] = 0; map[2 + (h - 1) * 6][25 - i - 4] = 0; map[1 + (h - 1) * 6][25 - i - 4] = 0; map[5 + h * 6][25 - i - 4] = 0; map[2 + h * 6][25 - i - 4] = 0; map[1 + h * 6][25 - i - 4] = 0; delay(); mapping2(); break;
		case 4:
			map[3 + (h - 1) * 6][3] = 2; map[5 + h * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 5] = 1; map[2 + (h - 1) * 6][25 - i - 5] = 1; map[1 + (h - 1) * 6][25 - i - 5] = 1; map[5 + h * 6][25 - i - 5] = 1; map[2 + h * 6][25 - i - 5] = 1; map[1 + h * 6][25 - i - 5] = 1; mapping2();
			map[3 + (h - 1) * 6][3] = 0; map[5 + h * 6][3] = 0; map[5 + (h - 1) * 6][25 - i - 5] = 0; map[2 + (h - 1) * 6][25 - i - 5] = 0; map[1 + (h - 1) * 6][25 - i - 5] = 0; map[5 + h * 6][25 - i - 5] = 0; map[2 + h * 6][25 - i - 5] = 0; map[1 + h * 6][25 - i - 5] = 0; delay(); mapping2(); break;
		case 5:
			map[4 + (h - 1) * 6][3] = 2; map[5 + h * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 6] = 1; map[2 + (h - 1) * 6][25 - i - 6] = 1; map[1 + (h - 1) * 6][25 - i - 6] = 1; map[5 + h * 6][25 - i - 6] = 1; map[2 + h * 6][25 - i - 6] = 1; map[1 + h * 6][25 - i - 6] = 1; mapping2();
			map[4 + (h - 1) * 6][3] = 0; map[5 + h * 6][3] = 0; map[5 + (h - 1) * 6][25 - i - 6] = 0; map[2 + (h - 1) * 6][25 - i - 6] = 0; map[1 + (h - 1) * 6][25 - i - 6] = 0; map[5 + h * 6][25 - i - 6] = 0; map[2 + h * 6][25 - i - 6] = 0; map[1 + h * 6][25 - i - 6] = 0; delay(); mapping2(); break;
		case 6:
			map[5 + (h - 1) * 6][3] = 2; map[5 + h * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 7] = 1; map[2 + (h - 1) * 6][25 - i - 7] = 1; map[1 + (h - 1) * 6][25 - i - 7] = 1; map[5 + h * 6][25 - i - 7] = 1; map[2 + h * 6][25 - i - 7] = 1; map[1 + h * 6][25 - i - 7] = 1; mapping2();
			map[5 + (h - 1) * 6][25 - i - 7] = 0; map[2 + (h - 1) * 6][25 - i - 7] = 0; map[1 + (h - 1) * 6][25 - i - 7] = 0; map[5 + h * 6][25 - i - 7] = 0; map[2 + h * 6][25 - i - 7] = 0; map[1 + h * 6][25 - i - 7] = 0; delay(); mapping2(); break;
		}
		step++;
		step = step % 7;
	}
}
void jump2_1_12_2(int i, int h) { // �ٲ��ٷ��� ��ֹ��� ���� �ٲ������.
	static int step = 0;
	int j = 0;
	for (j = 0; j<7; j++) {
		switch (step) {
		case 0:
			map[5 + (h - 1) * 6][3] = 2; map[5 + h * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 1] = 1; map[2 + (h - 1) * 6][25 - i - 1] = 1; map[1 + (h - 1) * 6][25 - i - 1] = 1; map[5 + h * 6][25 - i - 1] = 1; map[2 + h * 6][25 - i - 1] = 1; map[1 + h * 6][25 - i - 1] = 1; mapping2();
			map[5 + (h - 1) * 6][3] = 0; map[5 + h * 6][3] = 0; map[5 + (h - 1) * 6][25 - i - 1] = 0; map[2 + (h - 1) * 6][25 - i - 1] = 0; map[1 + (h - 1) * 6][25 - i - 1] = 0; map[5 + h * 6][25 - i - 1] = 0; map[2 + h * 6][25 - i - 1] = 0; map[1 + h * 6][25 - i - 1] = 0; delay(); mapping2(); break;
		case 1:
			map[5 + (h - 1) * 6][3] = 2; map[4 + h * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 2] = 1; map[2 + (h - 1) * 6][25 - i - 2] = 1; map[1 + (h - 1) * 6][25 - i - 2] = 1; map[5 + h * 6][25 - i - 2] = 1; map[2 + h * 6][25 - i - 2] = 1; map[1 + h * 6][25 - i - 2] = 1; mapping2();
			map[5 + (h - 1) * 6][3] = 0; map[4 + h * 6][3] = 0; map[5 + (h - 1) * 6][25 - i - 2] = 0; map[2 + (h - 1) * 6][25 - i - 2] = 0; map[1 + (h - 1) * 6][25 - i - 2] = 0; map[5 + h * 6][25 - i - 2] = 0; map[2 + h * 6][25 - i - 2] = 0; map[1 + h * 6][25 - i - 2] = 0; delay(); mapping2(); break;
		case 2:
			map[5 + (h - 1) * 6][3] = 2; map[3 + h * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 3] = 1; map[2 + (h - 1) * 6][25 - i - 3] = 1; map[1 + (h - 1) * 6][25 - i - 3] = 1; map[5 + h * 6][25 - i - 3] = 1; map[2 + h * 6][25 - i - 3] = 1; map[1 + h * 6][25 - i - 3] = 1; mapping2();
			map[5 + (h - 1) * 6][3] = 0; map[3 + h * 6][3] = 0; map[5 + (h - 1) * 6][25 - i - 3] = 0; map[2 + (h - 1) * 6][25 - i - 3] = 0; map[1 + (h - 1) * 6][25 - i - 3] = 0; map[5 + h * 6][25 - i - 3] = 0; map[2 + h * 6][25 - i - 3] = 0; map[1 + h * 6][25 - i - 3] = 0; delay(); mapping2(); break;
		case 3:
			map[5 + (h - 1) * 6][3] = 2; map[2 + h * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 4] = 1; map[2 + (h - 1) * 6][25 - i - 4] = 1; map[1 + (h - 1) * 6][25 - i - 4] = 1; map[5 + h * 6][25 - i - 4] = 1; map[2 + h * 6][25 - i - 4] = 1; map[1 + h * 6][25 - i - 4] = 1; mapping2();
			map[5 + (h - 1) * 6][3] = 0; map[2 + h * 6][3] = 0; map[5 + (h - 1) * 6][25 - i - 4] = 0; map[2 + (h - 1) * 6][25 - i - 4] = 0; map[1 + (h - 1) * 6][25 - i - 4] = 0; map[5 + h * 6][25 - i - 4] = 0; map[2 + h * 6][25 - i - 4] = 0; map[1 + h * 6][25 - i - 4] = 0; delay(); mapping2(); break;
		case 4:
			map[5 + (h - 1) * 6][3] = 2; map[3 + h * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 5] = 1; map[2 + (h - 1) * 6][25 - i - 5] = 1; map[1 + (h - 1) * 6][25 - i - 5] = 1; map[5 + h * 6][25 - i - 5] = 1; map[2 + h * 6][25 - i - 5] = 1; map[1 + h * 6][25 - i - 5] = 1; mapping2();
			map[5 + (h - 1) * 6][3] = 0; map[3 + h * 6][3] = 0; map[5 + (h - 1) * 6][25 - i - 5] = 0; map[2 + (h - 1) * 6][25 - i - 5] = 0; map[1 + (h - 1) * 6][25 - i - 5] = 0; map[5 + h * 6][25 - i - 5] = 0; map[2 + h * 6][25 - i - 5] = 0; map[1 + h * 6][25 - i - 5] = 0; delay(); mapping2(); break;
		case 5:
			map[5 + (h - 1) * 6][3] = 2; map[4 + h * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 6] = 1; map[2 + (h - 1) * 6][25 - i - 6] = 1; map[1 + (h - 1) * 6][25 - i - 6] = 1; map[5 + h * 6][25 - i - 6] = 1; map[2 + h * 6][25 - i - 6] = 1; map[1 + h * 6][25 - i - 6] = 1; mapping2();
			map[5 + (h - 1) * 6][3] = 0; map[4 + h * 6][3] = 0; map[5 + (h - 1) * 6][25 - i - 6] = 0; map[2 + (h - 1) * 6][25 - i - 6] = 0; map[1 + (h - 1) * 6][25 - i - 6] = 0; map[5 + h * 6][25 - i - 6] = 0; map[2 + h * 6][25 - i - 6] = 0; map[1 + h * 6][25 - i - 6] = 0; delay(); mapping2(); break;
		case 6:
			map[5 + (h - 1) * 6][3] = 2; map[5 + h * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 7] = 1; map[2 + (h - 1) * 6][25 - i - 7] = 1; map[1 + (h - 1) * 6][25 - i - 7] = 1; map[5 + h * 6][25 - i - 7] = 1; map[2 + h * 6][25 - i - 7] = 1; map[1 + h * 6][25 - i - 7] = 1; mapping2();
			map[5 + (h - 1) * 6][25 - i - 7] = 0; map[2 + (h - 1) * 6][25 - i - 7] = 0; map[1 + (h - 1) * 6][25 - i - 7] = 0; map[5 + h * 6][25 - i - 7] = 0; map[2 + h * 6][25 - i - 7] = 0; map[1 + h * 6][25 - i - 7] = 0; delay(); mapping2(); break;
		}
		step++;
		step = step % 7;
	}
}
void jump2_1_13(int i, int h) { // �ٲ��ٷ��� ��ֹ��� ���� �ٲ������.
	static int step = 0;
	int j = 0;
	for (j = 0; j<7; j++) {
		switch (step) {
		case 0:
			map[5 + (h - 1) * 6][3] = 2; map[5 + (h + 1) * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 1] = 1; map[2 + (h - 1) * 6][25 - i - 1] = 1; map[1 + (h - 1) * 6][25 - i - 1] = 1; map[5 + (h + 1) * 6][25 - i - 1] = 1; map[2 + (h + 1) * 6][25 - i - 1] = 1; map[1 + (h + 1) * 6][25 - i - 1] = 1; mapping2();
			map[5 + (h - 1) * 6][3] = 0; map[5 + (h + 1) * 6][3] = 0; map[5 + (h - 1) * 6][25 - i - 1] = 0; map[2 + (h - 1) * 6][25 - i - 1] = 0; map[1 + (h - 1) * 6][25 - i - 1] = 0; map[5 + (h + 1) * 6][25 - i - 1] = 0; map[2 + (h + 1) * 6][25 - i - 1] = 0; map[1 + (h + 1) * 6][25 - i - 1] = 0; delay(); mapping2(); break;
		case 1:
			map[4 + (h - 1) * 6][3] = 2; map[4 + (h + 1) * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 2] = 1; map[2 + (h - 1) * 6][25 - i - 2] = 1; map[1 + (h - 1) * 6][25 - i - 2] = 1; map[5 + (h + 1) * 6][25 - i - 2] = 1; map[2 + (h + 1) * 6][25 - i - 2] = 1; map[1 + (h + 1) * 6][25 - i - 2] = 1; mapping2();
			map[4 + (h - 1) * 6][3] = 0; map[4 + (h + 1) * 6][3] = 0; map[5 + (h - 1) * 6][25 - i - 2] = 0; map[2 + (h - 1) * 6][25 - i - 2] = 0; map[1 + (h - 1) * 6][25 - i - 2] = 0; map[5 + (h + 1) * 6][25 - i - 2] = 0; map[2 + (h + 1) * 6][25 - i - 2] = 0; map[1 + (h + 1) * 6][25 - i - 2] = 0; delay(); mapping2(); break;
		case 2:
			map[3 + (h - 1) * 6][3] = 2; map[3 + (h + 1) * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 3] = 1; map[2 + (h - 1) * 6][25 - i - 3] = 1; map[1 + (h - 1) * 6][25 - i - 3] = 1; map[5 + (h + 1) * 6][25 - i - 3] = 1; map[2 + (h + 1) * 6][25 - i - 3] = 1; map[1 + (h + 1) * 6][25 - i - 3] = 1; mapping2();
			map[3 + (h - 1) * 6][3] = 0; map[3 + (h + 1) * 6][3] = 0; map[5 + (h - 1) * 6][25 - i - 3] = 0; map[2 + (h - 1) * 6][25 - i - 3] = 0; map[1 + (h - 1) * 6][25 - i - 3] = 0; map[5 + (h + 1) * 6][25 - i - 3] = 0; map[2 + (h + 1) * 6][25 - i - 3] = 0; map[1 + (h + 1) * 6][25 - i - 3] = 0; delay(); mapping2(); break;
		case 3:
			map[2 + (h - 1) * 6][3] = 2; map[2 + (h + 1) * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 4] = 1; map[2 + (h - 1) * 6][25 - i - 4] = 1; map[1 + (h - 1) * 6][25 - i - 4] = 1; map[5 + (h + 1) * 6][25 - i - 4] = 1; map[2 + (h + 1) * 6][25 - i - 4] = 1; map[1 + (h + 1) * 6][25 - i - 4] = 1; mapping2();
			map[2 + (h - 1) * 6][3] = 0; map[2 + (h + 1) * 6][3] = 0; map[5 + (h - 1) * 6][25 - i - 4] = 0; map[2 + (h - 1) * 6][25 - i - 4] = 0; map[1 + (h - 1) * 6][25 - i - 4] = 0; map[5 + (h + 1) * 6][25 - i - 4] = 0; map[2 + (h + 1) * 6][25 - i - 4] = 0; map[1 + (h + 1) * 6][25 - i - 4] = 0; delay(); mapping2(); break;
		case 4:
			map[3 + (h - 1) * 6][3] = 2; map[3 + (h + 1) * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 5] = 1; map[2 + (h - 1) * 6][25 - i - 5] = 1; map[1 + (h - 1) * 6][25 - i - 5] = 1; map[5 + (h + 1) * 6][25 - i - 5] = 1; map[2 + (h + 1) * 6][25 - i - 5] = 1; map[1 + (h + 1) * 6][25 - i - 5] = 1; mapping2();
			map[3 + (h - 1) * 6][3] = 0; map[3 + (h + 1) * 6][3] = 0; map[5 + (h - 1) * 6][25 - i - 5] = 0; map[2 + (h - 1) * 6][25 - i - 5] = 0; map[1 + (h - 1) * 6][25 - i - 5] = 0; map[5 + (h + 1) * 6][25 - i - 5] = 0; map[2 + (h + 1) * 6][25 - i - 5] = 0; map[1 + (h + 1) * 6][25 - i - 5] = 0; delay(); mapping2(); break;
		case 5:
			map[4 + (h - 1) * 6][3] = 2; map[4 + (h + 1) * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 6] = 1; map[2 + (h - 1) * 6][25 - i - 6] = 1; map[1 + (h - 1) * 6][25 - i - 6] = 1; map[5 + (h + 1) * 6][25 - i - 6] = 1; map[2 + (h + 1) * 6][25 - i - 6] = 1; map[1 + (h + 1) * 6][25 - i - 6] = 1; mapping2();
			map[4 + (h - 1) * 6][3] = 0; map[4 + (h + 1) * 6][3] = 0; map[5 + (h - 1) * 6][25 - i - 6] = 0; map[2 + (h - 1) * 6][25 - i - 6] = 0; map[1 + (h - 1) * 6][25 - i - 6] = 0; map[5 + (h + 1) * 6][25 - i - 6] = 0; map[2 + (h + 1) * 6][25 - i - 6] = 0; map[1 + (h + 1) * 6][25 - i - 6] = 0; delay(); mapping2(); break;
		case 6:
			map[5 + (h - 1) * 6][3] = 2; map[5 + (h + 1) * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 7] = 1; map[2 + (h - 1) * 6][25 - i - 7] = 1; map[1 + (h - 1) * 6][25 - i - 7] = 1; map[5 + (h + 1) * 6][25 - i - 7] = 1; map[2 + (h + 1) * 6][25 - i - 7] = 1; map[1 + (h + 1) * 6][25 - i - 7] = 1; mapping2();
			map[5 + (h - 1) * 6][25 - i - 7] = 0; map[2 + (h - 1) * 6][25 - i - 7] = 0; map[1 + (h - 1) * 6][25 - i - 7] = 0; map[5 + (h + 1) * 6][25 - i - 7] = 0; map[2 + (h + 1) * 6][25 - i - 7] = 0; map[1 + (h + 1) * 6][25 - i - 7] = 0; delay(); mapping2(); break;
		}
		step++;
		step = step % 7;
	}
}
void jump2_1_13_1(int i, int h) { // �ٲ��ٷ��� ��ֹ��� ���� �ٲ������.
	static int step = 0;
	int j = 0;
	for (j = 0; j<7; j++) {
		switch (step) {
		case 0:
			map[5 + (h - 1) * 6][3] = 2; map[5 + (h + 1) * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 1] = 1; map[2 + (h - 1) * 6][25 - i - 1] = 1; map[1 + (h - 1) * 6][25 - i - 1] = 1; map[5 + (h + 1) * 6][25 - i - 1] = 1; map[2 + (h + 1) * 6][25 - i - 1] = 1; map[1 + (h + 1) * 6][25 - i - 1] = 1; mapping2();
			map[5 + (h - 1) * 6][3] = 0; map[5 + (h + 1) * 6][3] = 0; map[5 + (h - 1) * 6][25 - i - 1] = 0; map[2 + (h - 1) * 6][25 - i - 1] = 0; map[1 + (h - 1) * 6][25 - i - 1] = 0; map[5 + (h + 1) * 6][25 - i - 1] = 0; map[2 + (h + 1) * 6][25 - i - 1] = 0; map[1 + (h + 1) * 6][25 - i - 1] = 0; delay(); mapping2(); break;
		case 1:
			map[4 + (h - 1) * 6][3] = 2; map[5 + (h + 1) * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 2] = 1; map[2 + (h - 1) * 6][25 - i - 2] = 1; map[1 + (h - 1) * 6][25 - i - 2] = 1; map[5 + (h + 1) * 6][25 - i - 2] = 1; map[2 + (h + 1) * 6][25 - i - 2] = 1; map[1 + (h + 1) * 6][25 - i - 2] = 1; mapping2();
			map[4 + (h - 1) * 6][3] = 0; map[5 + (h + 1) * 6][3] = 0; map[5 + (h - 1) * 6][25 - i - 2] = 0; map[2 + (h - 1) * 6][25 - i - 2] = 0; map[1 + (h - 1) * 6][25 - i - 2] = 0; map[5 + (h + 1) * 6][25 - i - 2] = 0; map[2 + (h + 1) * 6][25 - i - 2] = 0; map[1 + (h + 1) * 6][25 - i - 2] = 0; delay(); mapping2(); break;
		case 2:
			map[3 + (h - 1) * 6][3] = 2; map[5 + (h + 1) * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 3] = 1; map[2 + (h - 1) * 6][25 - i - 3] = 1; map[1 + (h - 1) * 6][25 - i - 3] = 1; map[5 + (h + 1) * 6][25 - i - 3] = 1; map[2 + (h + 1) * 6][25 - i - 3] = 1; map[1 + (h + 1) * 6][25 - i - 3] = 1; mapping2();
			map[3 + (h - 1) * 6][3] = 0; map[5 + (h + 1) * 6][3] = 0; map[5 + (h - 1) * 6][25 - i - 3] = 0; map[2 + (h - 1) * 6][25 - i - 3] = 0; map[1 + (h - 1) * 6][25 - i - 3] = 0; map[5 + (h + 1) * 6][25 - i - 3] = 0; map[2 + (h + 1) * 6][25 - i - 3] = 0; map[1 + (h + 1) * 6][25 - i - 3] = 0; delay(); mapping2(); break;
		case 3:
			map[2 + (h - 1) * 6][3] = 2; map[5 + (h + 1) * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 4] = 1; map[2 + (h - 1) * 6][25 - i - 4] = 1; map[1 + (h - 1) * 6][25 - i - 4] = 1; map[5 + (h + 1) * 6][25 - i - 4] = 1; map[2 + (h + 1) * 6][25 - i - 4] = 1; map[1 + (h + 1) * 6][25 - i - 4] = 1; mapping2();
			map[2 + (h - 1) * 6][3] = 0; map[5 + (h + 1) * 6][3] = 0; map[5 + (h - 1) * 6][25 - i - 4] = 0; map[2 + (h - 1) * 6][25 - i - 4] = 0; map[1 + (h - 1) * 6][25 - i - 4] = 0; map[5 + (h + 1) * 6][25 - i - 4] = 0; map[2 + (h + 1) * 6][25 - i - 4] = 0; map[1 + (h + 1) * 6][25 - i - 4] = 0; delay(); mapping2(); break;
		case 4:
			map[3 + (h - 1) * 6][3] = 2; map[5 + (h + 1) * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 5] = 1; map[2 + (h - 1) * 6][25 - i - 5] = 1; map[1 + (h - 1) * 6][25 - i - 5] = 1; map[5 + (h + 1) * 6][25 - i - 5] = 1; map[2 + (h + 1) * 6][25 - i - 5] = 1; map[1 + (h + 1) * 6][25 - i - 5] = 1; mapping2();
			map[3 + (h - 1) * 6][3] = 0; map[5 + (h + 1) * 6][3] = 0; map[5 + (h - 1) * 6][25 - i - 5] = 0; map[2 + (h - 1) * 6][25 - i - 5] = 0; map[1 + (h - 1) * 6][25 - i - 5] = 0; map[5 + (h + 1) * 6][25 - i - 5] = 0; map[2 + (h + 1) * 6][25 - i - 5] = 0; map[1 + (h + 1) * 6][25 - i - 5] = 0; delay(); mapping2(); break;
		case 5:
			map[4 + (h - 1) * 6][3] = 2; map[5 + (h + 1) * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 6] = 1; map[2 + (h - 1) * 6][25 - i - 6] = 1; map[1 + (h - 1) * 6][25 - i - 6] = 1; map[5 + (h + 1) * 6][25 - i - 6] = 1; map[2 + (h + 1) * 6][25 - i - 6] = 1; map[1 + (h + 1) * 6][25 - i - 6] = 1; mapping2();
			map[4 + (h - 1) * 6][3] = 0; map[5 + (h + 1) * 6][3] = 0; map[5 + (h - 1) * 6][25 - i - 6] = 0; map[2 + (h - 1) * 6][25 - i - 6] = 0; map[1 + (h - 1) * 6][25 - i - 6] = 0; map[5 + (h + 1) * 6][25 - i - 6] = 0; map[2 + (h + 1) * 6][25 - i - 6] = 0; map[1 + (h + 1) * 6][25 - i - 6] = 0; delay(); mapping2(); break;
		case 6:
			map[5 + (h - 1) * 6][3] = 2; map[5 + (h + 1) * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 7] = 1; map[2 + (h - 1) * 6][25 - i - 7] = 1; map[1 + (h - 1) * 6][25 - i - 7] = 1; map[5 + (h + 1) * 6][25 - i - 7] = 1; map[2 + (h + 1) * 6][25 - i - 7] = 1; map[1 + (h + 1) * 6][25 - i - 7] = 1; mapping2();
			map[5 + (h - 1) * 6][25 - i - 7] = 0; map[2 + (h - 1) * 6][25 - i - 7] = 0; map[1 + (h - 1) * 6][25 - i - 7] = 0; map[5 + (h + 1) * 6][25 - i - 7] = 0; map[2 + (h + 1) * 6][25 - i - 7] = 0; map[1 + (h + 1) * 6][25 - i - 7] = 0; delay(); mapping2(); break;
		}
		step++;
		step = step % 7;
	}
}
void jump2_1_13_2(int i, int h) { // �ٲ��ٷ��� ��ֹ��� ���� �ٲ������.
	static int step = 0;
	int j = 0;
	for (j = 0; j<7; j++) {
		switch (step) {
		case 0:
			map[5 + (h - 1) * 6][3] = 2; map[5 + (h + 1) * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 1] = 1; map[2 + (h - 1) * 6][25 - i - 1] = 1; map[1 + (h - 1) * 6][25 - i - 1] = 1; map[5 + (h + 1) * 6][25 - i - 1] = 1; map[2 + (h + 1) * 6][25 - i - 1] = 1; map[1 + (h + 1) * 6][25 - i - 1] = 1; mapping2();
			map[5 + (h - 1) * 6][3] = 0; map[5 + (h + 1) * 6][3] = 0; map[5 + (h - 1) * 6][25 - i - 1] = 0; map[2 + (h - 1) * 6][25 - i - 1] = 0; map[1 + (h - 1) * 6][25 - i - 1] = 0; map[5 + (h + 1) * 6][25 - i - 1] = 0; map[2 + (h + 1) * 6][25 - i - 1] = 0; map[1 + (h + 1) * 6][25 - i - 1] = 0; delay(); mapping2(); break;
		case 1:
			map[5 + (h - 1) * 6][3] = 2; map[4 + (h + 1) * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 2] = 1; map[2 + (h - 1) * 6][25 - i - 2] = 1; map[1 + (h - 1) * 6][25 - i - 2] = 1; map[5 + (h + 1) * 6][25 - i - 2] = 1; map[2 + (h + 1) * 6][25 - i - 2] = 1; map[1 + (h + 1) * 6][25 - i - 2] = 1; mapping2();
			map[5 + (h - 1) * 6][3] = 0; map[4 + (h + 1) * 6][3] = 0; map[5 + (h - 1) * 6][25 - i - 2] = 0; map[2 + (h - 1) * 6][25 - i - 2] = 0; map[1 + (h - 1) * 6][25 - i - 2] = 0; map[5 + (h + 1) * 6][25 - i - 2] = 0; map[2 + (h + 1) * 6][25 - i - 2] = 0; map[1 + (h + 1) * 6][25 - i - 2] = 0; delay(); mapping2(); break;
		case 2:
			map[5 + (h - 1) * 6][3] = 2; map[3 + (h + 1) * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 3] = 1; map[2 + (h - 1) * 6][25 - i - 3] = 1; map[1 + (h - 1) * 6][25 - i - 3] = 1; map[5 + (h + 1) * 6][25 - i - 3] = 1; map[2 + (h + 1) * 6][25 - i - 3] = 1; map[1 + (h + 1) * 6][25 - i - 3] = 1; mapping2();
			map[5 + (h - 1) * 6][3] = 0; map[3 + (h + 1) * 6][3] = 0; map[5 + (h - 1) * 6][25 - i - 3] = 0; map[2 + (h - 1) * 6][25 - i - 3] = 0; map[1 + (h - 1) * 6][25 - i - 3] = 0; map[5 + (h + 1) * 6][25 - i - 3] = 0; map[2 + (h + 1) * 6][25 - i - 3] = 0; map[1 + (h + 1) * 6][25 - i - 3] = 0; delay(); mapping2(); break;
		case 3:
			map[5 + (h - 1) * 6][3] = 2; map[2 + (h + 1) * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 4] = 1; map[2 + (h - 1) * 6][25 - i - 4] = 1; map[1 + (h - 1) * 6][25 - i - 4] = 1; map[5 + (h + 1) * 6][25 - i - 4] = 1; map[2 + (h + 1) * 6][25 - i - 4] = 1; map[1 + (h + 1) * 6][25 - i - 4] = 1; mapping2();
			map[5 + (h - 1) * 6][3] = 0; map[2 + (h + 1) * 6][3] = 0; map[5 + (h - 1) * 6][25 - i - 4] = 0; map[2 + (h - 1) * 6][25 - i - 4] = 0; map[1 + (h - 1) * 6][25 - i - 4] = 0; map[5 + (h + 1) * 6][25 - i - 4] = 0; map[2 + (h + 1) * 6][25 - i - 4] = 0; map[1 + (h + 1) * 6][25 - i - 4] = 0; delay(); mapping2(); break;
		case 4:
			map[5 + (h - 1) * 6][3] = 2; map[3 + (h + 1) * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 5] = 1; map[2 + (h - 1) * 6][25 - i - 5] = 1; map[1 + (h - 1) * 6][25 - i - 5] = 1; map[5 + (h + 1) * 6][25 - i - 5] = 1; map[2 + (h + 1) * 6][25 - i - 5] = 1; map[1 + (h + 1) * 6][25 - i - 5] = 1; mapping2();
			map[5 + (h - 1) * 6][3] = 0; map[3 + (h + 1) * 6][3] = 0; map[5 + (h - 1) * 6][25 - i - 5] = 0; map[2 + (h - 1) * 6][25 - i - 5] = 0; map[1 + (h - 1) * 6][25 - i - 5] = 0; map[5 + (h + 1) * 6][25 - i - 5] = 0; map[2 + (h + 1) * 6][25 - i - 5] = 0; map[1 + (h + 1) * 6][25 - i - 5] = 0; delay(); mapping2(); break;
		case 5:
			map[5 + (h - 1) * 6][3] = 2; map[4 + (h + 1) * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 6] = 1; map[2 + (h - 1) * 6][25 - i - 6] = 1; map[1 + (h - 1) * 6][25 - i - 6] = 1; map[5 + (h + 1) * 6][25 - i - 6] = 1; map[2 + (h + 1) * 6][25 - i - 6] = 1; map[1 + (h + 1) * 6][25 - i - 6] = 1; mapping2();
			map[5 + (h - 1) * 6][3] = 0; map[4 + (h + 1) * 6][3] = 0; map[5 + (h - 1) * 6][25 - i - 6] = 0; map[2 + (h - 1) * 6][25 - i - 6] = 0; map[1 + (h - 1) * 6][25 - i - 6] = 0; map[5 + (h + 1) * 6][25 - i - 6] = 0; map[2 + (h + 1) * 6][25 - i - 6] = 0; map[1 + (h + 1) * 6][25 - i - 6] = 0; delay(); mapping2(); break;
		case 6:
			map[5 + (h - 1) * 6][3] = 2; map[5 + (h + 1) * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 7] = 1; map[2 + (h - 1) * 6][25 - i - 7] = 1; map[1 + (h - 1) * 6][25 - i - 7] = 1; map[5 + (h + 1) * 6][25 - i - 7] = 1; map[2 + (h + 1) * 6][25 - i - 7] = 1; map[1 + (h + 1) * 6][25 - i - 7] = 1; mapping2();
			map[5 + (h - 1) * 6][25 - i - 7] = 0; map[2 + (h - 1) * 6][25 - i - 7] = 0; map[1 + (h - 1) * 6][25 - i - 7] = 0; map[5 + (h + 1) * 6][25 - i - 7] = 0; map[2 + (h + 1) * 6][25 - i - 7] = 0; map[1 + (h + 1) * 6][25 - i - 7] = 0; delay(); mapping2(); break;
		}
		step++;
		step = step % 7;
	}
}

void jump1_2(int i, int h) { // �ٲ��ٷ��� ��ֹ��� ���� �ٲ������.
	static int step = 0;
	int j = 0;
	for (j = 0; j<7; j++) {
		switch (step) {
		case 0:
			map[5 + (h - 1) * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 1] = 1; map[4 + (h - 1) * 6][25 - i - 1] = 1; map[1 + (h - 1) * 6][25 - i - 1] = 1; mapping2();
			map[5 + (h - 1) * 6][3] = 0; map[5 + (h - 1) * 6][25 - i - 1] = 0; map[4 + (h - 1) * 6][25 - i - 1] = 0; map[1 + (h - 1) * 6][25 - i - 1] = 0; delay(); mapping2(); break;
		case 1:
			map[4 + (h - 1) * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 2] = 1; map[4 + (h - 1) * 6][25 - i - 2] = 1; map[1 + (h - 1) * 6][25 - i - 2] = 1; mapping2();
			map[4 + (h - 1) * 6][3] = 0; map[5 + (h - 1) * 6][25 - i - 2] = 0; map[4 + (h - 1) * 6][25 - i - 2] = 0; map[1 + (h - 1) * 6][25 - i - 2] = 0; delay(); mapping2(); break;
		case 2:
			map[3 + (h - 1) * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 3] = 1; map[4 + (h - 1) * 6][25 - i - 3] = 1; map[1 + (h - 1) * 6][25 - i - 3] = 1; mapping2();
			map[3 + (h - 1) * 6][3] = 0; map[5 + (h - 1) * 6][25 - i - 3] = 0; map[4 + (h - 1) * 6][25 - i - 3] = 0; map[1 + (h - 1) * 6][25 - i - 3] = 0; delay(); mapping2(); break;
		case 3:
			map[2 + (h - 1) * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 4] = 1; map[4 + (h - 1) * 6][25 - i - 4] = 1; map[1 + (h - 1) * 6][25 - i - 4] = 1; mapping2();
			map[2 + (h - 1) * 6][3] = 0; map[5 + (h - 1) * 6][25 - i - 4] = 0; map[4 + (h - 1) * 6][25 - i - 4] = 0; map[1 + (h - 1) * 6][25 - i - 4] = 0; delay(); mapping2(); break;
		case 4:
			map[3 + (h - 1) * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 5] = 1; map[4 + (h - 1) * 6][25 - i - 5] = 1; map[1 + (h - 1) * 6][25 - i - 5] = 1; mapping2();
			map[3 + (h - 1) * 6][3] = 0; map[5 + (h - 1) * 6][25 - i - 5] = 0; map[4 + (h - 1) * 6][25 - i - 5] = 0; map[1 + (h - 1) * 6][25 - i - 5] = 0; delay(); mapping2(); break;
		case 5:
			map[4 + (h - 1) * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 6] = 1; map[4 + (h - 1) * 6][25 - i - 6] = 1; map[1 + (h - 1) * 6][25 - i - 6] = 1; mapping2();
			map[4 + (h - 1) * 6][3] = 0; map[5 + (h - 1) * 6][25 - i - 6] = 0; map[4 + (h - 1) * 6][25 - i - 6] = 0; map[1 + (h - 1) * 6][25 - i - 6] = 0; delay(); mapping2(); break;
		case 6:
			map[5 + (h - 1) * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 7] = 1; map[4 + (h - 1) * 6][25 - i - 7] = 1; map[1 + (h - 1) * 6][25 - i - 7] = 1; mapping2();
			map[5 + (h - 1) * 6][25 - i - 7] = 0; map[5 + (h - 1) * 6][25 - i - 7] = 0; map[4 + (h - 1) * 6][25 - i - 7] = 0; map[1 + (h - 1) * 6][25 - i - 7] = 0; delay(); mapping2(); break;
		}
		step++;
		step = step % 7;
	}
}
void jump1_2_12(int i, int h) { // �ٲ��ٷ��� ��ֹ��� ���� �ٲ������.
	static int step = 0;
	int j = 0;
	for (j = 0; j<7; j++) {
		switch (step) {
		case 0:
			map[5 + (h - 1) * 6][3] = 2; map[5 + h * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 1] = 1; map[4 + (h - 1) * 6][25 - i - 1] = 1; map[1 + (h - 1) * 6][25 - i - 1] = 1; map[5 + h * 6][25 - i - 1] = 1; map[4 + h * 6][25 - i - 1] = 1; map[1 + h * 6][25 - i - 1] = 1; mapping2();
			map[5 + (h - 1) * 6][3] = 0; map[5 + h * 6][3] = 0; map[5 + (h - 1) * 6][25 - i - 1] = 0; map[4 + (h - 1) * 6][25 - i - 1] = 0; map[1 + (h - 1) * 6][25 - i - 1] = 0; map[5 + h * 6][25 - i - 1] = 0; map[4 + h * 6][25 - i - 1] = 0; map[1 + h * 6][25 - i - 1] = 0; delay(); mapping2(); break;
		case 1:
			map[4 + (h - 1) * 6][3] = 2; map[4 + h * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 2] = 1; map[4 + (h - 1) * 6][25 - i - 2] = 1; map[1 + (h - 1) * 6][25 - i - 2] = 1; map[5 + h * 6][25 - i - 2] = 1; map[4 + h * 6][25 - i - 2] = 1; map[1 + h * 6][25 - i - 2] = 1; mapping2();
			map[4 + (h - 1) * 6][3] = 0; map[4 + h * 6][3] = 0; map[5 + (h - 1) * 6][25 - i - 2] = 0; map[4 + (h - 1) * 6][25 - i - 2] = 0; map[1 + (h - 1) * 6][25 - i - 2] = 0; map[5 + h * 6][25 - i - 2] = 0; map[4 + h * 6][25 - i - 2] = 0; map[1 + h * 6][25 - i - 2] = 0; delay(); mapping2(); break;
		case 2:
			map[3 + (h - 1) * 6][3] = 2; map[3 + h * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 3] = 1; map[4 + (h - 1) * 6][25 - i - 3] = 1; map[1 + (h - 1) * 6][25 - i - 3] = 1; map[5 + h * 6][25 - i - 3] = 1; map[4 + h * 6][25 - i - 3] = 1; map[1 + h * 6][25 - i - 3] = 1; mapping2();
			map[3 + (h - 1) * 6][3] = 0; map[3 + h * 6][3] = 0; map[5 + (h - 1) * 6][25 - i - 3] = 0; map[4 + (h - 1) * 6][25 - i - 3] = 0; map[1 + (h - 1) * 6][25 - i - 3] = 0; map[5 + h * 6][25 - i - 3] = 0; map[4 + h * 6][25 - i - 3] = 0; map[1 + h * 6][25 - i - 3] = 0; delay(); mapping2(); break;
		case 3:
			map[2 + (h - 1) * 6][3] = 2; map[2 + h * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 4] = 1; map[4 + (h - 1) * 6][25 - i - 4] = 1; map[1 + (h - 1) * 6][25 - i - 4] = 1; map[5 + h * 6][25 - i - 4] = 1; map[4 + h * 6][25 - i - 4] = 1; map[1 + h * 6][25 - i - 4] = 1; mapping2();
			map[2 + (h - 1) * 6][3] = 0; map[2 + h * 6][3] = 0; map[5 + (h - 1) * 6][25 - i - 4] = 0; map[4 + (h - 1) * 6][25 - i - 4] = 0; map[1 + (h - 1) * 6][25 - i - 4] = 0; map[5 + h * 6][25 - i - 4] = 0; map[4 + h * 6][25 - i - 4] = 0; map[1 + h * 6][25 - i - 4] = 0; delay(); mapping2(); break;
		case 4:
			map[3 + (h - 1) * 6][3] = 2; map[3 + h * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 5] = 1; map[4 + (h - 1) * 6][25 - i - 5] = 1; map[1 + (h - 1) * 6][25 - i - 5] = 1; map[5 + h * 6][25 - i - 5] = 1; map[4 + h * 6][25 - i - 5] = 1; map[1 + h * 6][25 - i - 5] = 1; mapping2();
			map[3 + (h - 1) * 6][3] = 0; map[3 + h * 6][3] = 0; map[5 + (h - 1) * 6][25 - i - 5] = 0; map[4 + (h - 1) * 6][25 - i - 5] = 0; map[1 + (h - 1) * 6][25 - i - 5] = 0; map[5 + h * 6][25 - i - 5] = 0; map[4 + h * 6][25 - i - 5] = 0; map[1 + h * 6][25 - i - 5] = 0; delay(); mapping2(); break;
		case 5:
			map[4 + (h - 1) * 6][3] = 2; map[4 + h * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 6] = 1; map[4 + (h - 1) * 6][25 - i - 6] = 1; map[1 + (h - 1) * 6][25 - i - 6] = 1; map[5 + h * 6][25 - i - 6] = 1; map[4 + h * 6][25 - i - 6] = 1; map[1 + h * 6][25 - i - 6] = 1; mapping2();
			map[4 + (h - 1) * 6][3] = 0; map[4 + h * 6][3] = 0; map[5 + (h - 1) * 6][25 - i - 6] = 0; map[4 + (h - 1) * 6][25 - i - 6] = 0; map[1 + (h - 1) * 6][25 - i - 6] = 0; map[5 + h * 6][25 - i - 6] = 0; map[4 + h * 6][25 - i - 6] = 0; map[1 + h * 6][25 - i - 6] = 0; delay(); mapping2(); break;
		case 6:
			map[5 + (h - 1) * 6][3] = 2; map[5 + h * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 7] = 1; map[4 + (h - 1) * 6][25 - i - 7] = 1; map[1 + (h - 1) * 6][25 - i - 7] = 1; map[5 + h * 6][25 - i - 7] = 1; map[4 + h * 6][25 - i - 7] = 1; map[1 + h * 6][25 - i - 7] = 1; mapping2();
			map[5 + (h - 1) * 6][25 - i - 7] = 0; map[4 + (h - 1) * 6][25 - i - 7] = 0; map[1 + (h - 1) * 6][25 - i - 7] = 0; map[5 + h * 6][25 - i - 7] = 0; map[4 + h * 6][25 - i - 7] = 0; map[1 + h * 6][25 - i - 7] = 0; delay(); mapping2(); break;
		}
		step++;
		step = step % 7;
	}
}
void jump1_2_12_1(int i, int h) { // �ٲ��ٷ��� ��ֹ��� ���� �ٲ������.
	static int step = 0;
	int j = 0;
	for (j = 0; j<7; j++) {
		switch (step) {
		case 0:
			map[5 + (h - 1) * 6][3] = 2; map[5 + h * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 1] = 1; map[4 + (h - 1) * 6][25 - i - 1] = 1; map[1 + (h - 1) * 6][25 - i - 1] = 1; map[5 + h * 6][25 - i - 1] = 1; map[4 + h * 6][25 - i - 1] = 1; map[1 + h * 6][25 - i - 1] = 1; mapping2();
			map[5 + (h - 1) * 6][3] = 0; map[5 + h * 6][3] = 0; map[5 + (h - 1) * 6][25 - i - 1] = 0; map[4 + (h - 1) * 6][25 - i - 1] = 0; map[1 + (h - 1) * 6][25 - i - 1] = 0; map[5 + h * 6][25 - i - 1] = 0; map[4 + h * 6][25 - i - 1] = 0; map[1 + h * 6][25 - i - 1] = 0; delay(); mapping2(); break;
		case 1:
			map[4 + (h - 1) * 6][3] = 2; map[5 + h * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 2] = 1; map[4 + (h - 1) * 6][25 - i - 2] = 1; map[1 + (h - 1) * 6][25 - i - 2] = 1; map[5 + h * 6][25 - i - 2] = 1; map[4 + h * 6][25 - i - 2] = 1; map[1 + h * 6][25 - i - 2] = 1; mapping2();
			map[4 + (h - 1) * 6][3] = 0; map[5 + h * 6][3] = 0; map[5 + (h - 1) * 6][25 - i - 2] = 0; map[4 + (h - 1) * 6][25 - i - 2] = 0; map[1 + (h - 1) * 6][25 - i - 2] = 0; map[5 + h * 6][25 - i - 2] = 0; map[4 + h * 6][25 - i - 2] = 0; map[1 + h * 6][25 - i - 2] = 0; delay(); mapping2(); break;
		case 2:
			map[3 + (h - 1) * 6][3] = 2; map[5 + h * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 3] = 1; map[4 + (h - 1) * 6][25 - i - 3] = 1; map[1 + (h - 1) * 6][25 - i - 3] = 1; map[5 + h * 6][25 - i - 3] = 1; map[4 + h * 6][25 - i - 3] = 1; map[1 + h * 6][25 - i - 3] = 1; mapping2();
			map[3 + (h - 1) * 6][3] = 0; map[5 + h * 6][3] = 0; map[5 + (h - 1) * 6][25 - i - 3] = 0; map[4 + (h - 1) * 6][25 - i - 3] = 0; map[1 + (h - 1) * 6][25 - i - 3] = 0; map[5 + h * 6][25 - i - 3] = 0; map[4 + h * 6][25 - i - 3] = 0; map[1 + h * 6][25 - i - 3] = 0; delay(); mapping2(); break;
		case 3:
			map[2 + (h - 1) * 6][3] = 2; map[5 + h * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 4] = 1; map[4 + (h - 1) * 6][25 - i - 4] = 1; map[1 + (h - 1) * 6][25 - i - 4] = 1; map[5 + h * 6][25 - i - 4] = 1; map[4 + h * 6][25 - i - 4] = 1; map[1 + h * 6][25 - i - 4] = 1; mapping2();
			map[2 + (h - 1) * 6][3] = 0; map[5 + h * 6][3] = 0; map[5 + (h - 1) * 6][25 - i - 4] = 0; map[4 + (h - 1) * 6][25 - i - 4] = 0; map[1 + (h - 1) * 6][25 - i - 4] = 0; map[5 + h * 6][25 - i - 4] = 0; map[4 + h * 6][25 - i - 4] = 0; map[1 + h * 6][25 - i - 4] = 0; delay(); mapping2(); break;
		case 4:
			map[3 + (h - 1) * 6][3] = 2; map[5 + h * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 5] = 1; map[4 + (h - 1) * 6][25 - i - 5] = 1; map[1 + (h - 1) * 6][25 - i - 5] = 1; map[5 + h * 6][25 - i - 5] = 1; map[4 + h * 6][25 - i - 5] = 1; map[1 + h * 6][25 - i - 5] = 1; mapping2();
			map[3 + (h - 1) * 6][3] = 0; map[5 + h * 6][3] = 0; map[5 + (h - 1) * 6][25 - i - 5] = 0; map[4 + (h - 1) * 6][25 - i - 5] = 0; map[1 + (h - 1) * 6][25 - i - 5] = 0; map[5 + h * 6][25 - i - 5] = 0; map[4 + h * 6][25 - i - 5] = 0; map[1 + h * 6][25 - i - 5] = 0; delay(); mapping2(); break;
		case 5:
			map[4 + (h - 1) * 6][3] = 2; map[5 + h * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 6] = 1; map[4 + (h - 1) * 6][25 - i - 6] = 1; map[1 + (h - 1) * 6][25 - i - 6] = 1; map[5 + h * 6][25 - i - 6] = 1; map[4 + h * 6][25 - i - 6] = 1; map[1 + h * 6][25 - i - 6] = 1; mapping2();
			map[4 + (h - 1) * 6][3] = 0; map[5 + h * 6][3] = 0; map[5 + (h - 1) * 6][25 - i - 6] = 0; map[4 + (h - 1) * 6][25 - i - 6] = 0; map[1 + (h - 1) * 6][25 - i - 6] = 0; map[5 + h * 6][25 - i - 6] = 0; map[4 + h * 6][25 - i - 6] = 0; map[1 + h * 6][25 - i - 6] = 0; delay(); mapping2(); break;
		case 6:
			map[5 + (h - 1) * 6][3] = 2; map[5 + h * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 7] = 1; map[4 + (h - 1) * 6][25 - i - 7] = 1; map[1 + (h - 1) * 6][25 - i - 7] = 1; map[5 + h * 6][25 - i - 7] = 1; map[4 + h * 6][25 - i - 7] = 1; map[1 + h * 6][25 - i - 7] = 1; mapping2();
			map[5 + (h - 1) * 6][25 - i - 7] = 0; map[4 + (h - 1) * 6][25 - i - 7] = 0; map[1 + (h - 1) * 6][25 - i - 7] = 0; map[5 + h * 6][25 - i - 7] = 0; map[4 + h * 6][25 - i - 7] = 0; map[1 + h * 6][25 - i - 7] = 0; delay(); mapping2(); break;
		}
		step++;
		step = step % 7;
	}
}
void jump1_2_12_2(int i, int h) { // �ٲ��ٷ��� ��ֹ��� ���� �ٲ������.
	static int step = 0;
	int j = 0;
	for (j = 0; j<7; j++) {
		switch (step) {
		case 0:
			map[5 + (h - 1) * 6][3] = 2; map[5 + h * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 1] = 1; map[4 + (h - 1) * 6][25 - i - 1] = 1; map[1 + (h - 1) * 6][25 - i - 1] = 1; map[5 + h * 6][25 - i - 1] = 1; map[4 + h * 6][25 - i - 1] = 1; map[1 + h * 6][25 - i - 1] = 1; mapping2();
			map[5 + (h - 1) * 6][3] = 0; map[5 + h * 6][3] = 0; map[5 + (h - 1) * 6][25 - i - 1] = 0; map[4 + (h - 1) * 6][25 - i - 1] = 0; map[1 + (h - 1) * 6][25 - i - 1] = 0; map[5 + h * 6][25 - i - 1] = 0; map[4 + h * 6][25 - i - 1] = 0; map[1 + h * 6][25 - i - 1] = 0; delay(); mapping2(); break;
		case 1:
			map[5 + (h - 1) * 6][3] = 2; map[4 + h * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 2] = 1; map[4 + (h - 1) * 6][25 - i - 2] = 1; map[1 + (h - 1) * 6][25 - i - 2] = 1; map[5 + h * 6][25 - i - 2] = 1; map[4 + h * 6][25 - i - 2] = 1; map[1 + h * 6][25 - i - 2] = 1; mapping2();
			map[5 + (h - 1) * 6][3] = 0; map[4 + h * 6][3] = 0; map[5 + (h - 1) * 6][25 - i - 2] = 0; map[4 + (h - 1) * 6][25 - i - 2] = 0; map[1 + (h - 1) * 6][25 - i - 2] = 0; map[5 + h * 6][25 - i - 2] = 0; map[4 + h * 6][25 - i - 2] = 0; map[1 + h * 6][25 - i - 2] = 0; delay(); mapping2(); break;
		case 2:
			map[5 + (h - 1) * 6][3] = 2; map[3 + h * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 3] = 1; map[4 + (h - 1) * 6][25 - i - 3] = 1; map[1 + (h - 1) * 6][25 - i - 3] = 1; map[5 + h * 6][25 - i - 3] = 1; map[4 + h * 6][25 - i - 3] = 1; map[1 + h * 6][25 - i - 3] = 1; mapping2();
			map[5 + (h - 1) * 6][3] = 0; map[3 + h * 6][3] = 0; map[5 + (h - 1) * 6][25 - i - 3] = 0; map[4 + (h - 1) * 6][25 - i - 3] = 0; map[1 + (h - 1) * 6][25 - i - 3] = 0; map[5 + h * 6][25 - i - 3] = 0; map[4 + h * 6][25 - i - 3] = 0; map[1 + h * 6][25 - i - 3] = 0; delay(); mapping2(); break;
		case 3:
			map[5 + (h - 1) * 6][3] = 2; map[2 + h * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 4] = 1; map[4 + (h - 1) * 6][25 - i - 4] = 1; map[1 + (h - 1) * 6][25 - i - 4] = 1; map[5 + h * 6][25 - i - 4] = 1; map[4 + h * 6][25 - i - 4] = 1; map[1 + h * 6][25 - i - 4] = 1; mapping2();
			map[5 + (h - 1) * 6][3] = 0; map[2 + h * 6][3] = 0; map[5 + (h - 1) * 6][25 - i - 4] = 0; map[4 + (h - 1) * 6][25 - i - 4] = 0; map[1 + (h - 1) * 6][25 - i - 4] = 0; map[5 + h * 6][25 - i - 4] = 0; map[4 + h * 6][25 - i - 4] = 0; map[1 + h * 6][25 - i - 4] = 0; delay(); mapping2(); break;
		case 4:
			map[5 + (h - 1) * 6][3] = 2; map[3 + h * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 5] = 1; map[4 + (h - 1) * 6][25 - i - 5] = 1; map[1 + (h - 1) * 6][25 - i - 5] = 1; map[5 + h * 6][25 - i - 5] = 1; map[4 + h * 6][25 - i - 5] = 1; map[1 + h * 6][25 - i - 5] = 1; mapping2();
			map[5 + (h - 1) * 6][3] = 0; map[3 + h * 6][3] = 0; map[5 + (h - 1) * 6][25 - i - 5] = 0; map[4 + (h - 1) * 6][25 - i - 5] = 0; map[1 + (h - 1) * 6][25 - i - 5] = 0; map[5 + h * 6][25 - i - 5] = 0; map[4 + h * 6][25 - i - 5] = 0; map[1 + h * 6][25 - i - 5] = 0; delay(); mapping2(); break;
		case 5:
			map[5 + (h - 1) * 6][3] = 2; map[4 + h * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 6] = 1; map[4 + (h - 1) * 6][25 - i - 6] = 1; map[1 + (h - 1) * 6][25 - i - 6] = 1; map[5 + h * 6][25 - i - 6] = 1; map[4 + h * 6][25 - i - 6] = 1; map[1 + h * 6][25 - i - 6] = 1; mapping2();
			map[5 + (h - 1) * 6][3] = 0; map[4 + h * 6][3] = 0; map[5 + (h - 1) * 6][25 - i - 6] = 0; map[4 + (h - 1) * 6][25 - i - 6] = 0; map[1 + (h - 1) * 6][25 - i - 6] = 0; map[5 + h * 6][25 - i - 6] = 0; map[4 + h * 6][25 - i - 6] = 0; map[1 + h * 6][25 - i - 6] = 0; delay(); mapping2(); break;
		case 6:
			map[5 + (h - 1) * 6][3] = 2; map[5 + h * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 7] = 1; map[4 + (h - 1) * 6][25 - i - 7] = 1; map[1 + (h - 1) * 6][25 - i - 7] = 1; map[5 + h * 6][25 - i - 7] = 1; map[4 + h * 6][25 - i - 7] = 1; map[1 + h * 6][25 - i - 7] = 1; mapping2();
			map[5 + (h - 1) * 6][25 - i - 7] = 0; map[4 + (h - 1) * 6][25 - i - 7] = 0; map[1 + (h - 1) * 6][25 - i - 7] = 0; map[5 + h * 6][25 - i - 7] = 0; map[4 + h * 6][25 - i - 7] = 0; map[1 + h * 6][25 - i - 7] = 0; delay(); mapping2(); break;
		}
		step++;
		step = step % 7;
	}
}
void jump1_2_13(int i, int h) { // �ٲ��ٷ��� ��ֹ��� ���� �ٲ������.
	static int step = 0;
	int j = 0;
	for (j = 0; j<7; j++) {
		switch (step) {
		case 0:
			map[5 + (h - 1) * 6][3] = 2; map[5 + (h + 1) * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 1] = 1; map[4 + (h - 1) * 6][25 - i - 1] = 1; map[1 + (h - 1) * 6][25 - i - 1] = 1; map[5 + (h + 1) * 6][25 - i - 1] = 1; map[4 + (h + 1) * 6][25 - i - 1] = 1; map[1 + (h + 1) * 6][25 - i - 1] = 1; mapping2();
			map[5 + (h - 1) * 6][3] = 0; map[5 + (h + 1) * 6][3] = 0; map[5 + (h - 1) * 6][25 - i - 1] = 0; map[4 + (h - 1) * 6][25 - i - 1] = 0; map[1 + (h - 1) * 6][25 - i - 1] = 0; map[5 + (h + 1) * 6][25 - i - 1] = 0; map[4 + (h + 1) * 6][25 - i - 1] = 0; map[1 + (h + 1) * 6][25 - i - 1] = 0; delay(); mapping2(); break;
		case 1:
			map[4 + (h - 1) * 6][3] = 2; map[4 + (h + 1) * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 2] = 1; map[4 + (h - 1) * 6][25 - i - 2] = 1; map[1 + (h - 1) * 6][25 - i - 2] = 1; map[5 + (h + 1) * 6][25 - i - 2] = 1; map[4 + (h + 1) * 6][25 - i - 2] = 1; map[1 + (h + 1) * 6][25 - i - 2] = 1; mapping2();
			map[4 + (h - 1) * 6][3] = 0; map[4 + (h + 1) * 6][3] = 0; map[5 + (h - 1) * 6][25 - i - 2] = 0; map[4 + (h - 1) * 6][25 - i - 2] = 0; map[1 + (h - 1) * 6][25 - i - 2] = 0; map[5 + (h + 1) * 6][25 - i - 2] = 0; map[4 + (h + 1) * 6][25 - i - 2] = 0; map[1 + (h + 1) * 6][25 - i - 2] = 0; delay(); mapping2(); break;
		case 2:
			map[3 + (h - 1) * 6][3] = 2; map[3 + (h + 1) * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 3] = 1; map[4 + (h - 1) * 6][25 - i - 3] = 1; map[1 + (h - 1) * 6][25 - i - 3] = 1; map[5 + (h + 1) * 6][25 - i - 3] = 1; map[4 + (h + 1) * 6][25 - i - 3] = 1; map[1 + (h + 1) * 6][25 - i - 3] = 1; mapping2();
			map[3 + (h - 1) * 6][3] = 0; map[3 + (h + 1) * 6][3] = 0; map[5 + (h - 1) * 6][25 - i - 3] = 0; map[4 + (h - 1) * 6][25 - i - 3] = 0; map[1 + (h - 1) * 6][25 - i - 3] = 0; map[5 + (h + 1) * 6][25 - i - 3] = 0; map[4 + (h + 1) * 6][25 - i - 3] = 0; map[1 + (h + 1) * 6][25 - i - 3] = 0; delay(); mapping2(); break;
		case 3:
			map[2 + (h - 1) * 6][3] = 2; map[2 + (h + 1) * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 4] = 1; map[4 + (h - 1) * 6][25 - i - 4] = 1; map[1 + (h - 1) * 6][25 - i - 4] = 1; map[5 + (h + 1) * 6][25 - i - 4] = 1; map[4 + (h + 1) * 6][25 - i - 4] = 1; map[1 + (h + 1) * 6][25 - i - 4] = 1; mapping2();
			map[2 + (h - 1) * 6][3] = 0; map[2 + (h + 1) * 6][3] = 0; map[5 + (h - 1) * 6][25 - i - 4] = 0; map[4 + (h - 1) * 6][25 - i - 4] = 0; map[1 + (h - 1) * 6][25 - i - 4] = 0; map[5 + (h + 1) * 6][25 - i - 4] = 0; map[4 + (h + 1) * 6][25 - i - 4] = 0; map[1 + (h + 1) * 6][25 - i - 4] = 0; delay(); mapping2(); break;
		case 4:
			map[3 + (h - 1) * 6][3] = 2; map[3 + (h + 1) * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 5] = 1; map[4 + (h - 1) * 6][25 - i - 5] = 1; map[1 + (h - 1) * 6][25 - i - 5] = 1; map[5 + (h + 1) * 6][25 - i - 5] = 1; map[4 + (h + 1) * 6][25 - i - 5] = 1; map[1 + (h + 1) * 6][25 - i - 5] = 1; mapping2();
			map[3 + (h - 1) * 6][3] = 0; map[3 + (h + 1) * 6][3] = 0; map[5 + (h - 1) * 6][25 - i - 5] = 0; map[4 + (h - 1) * 6][25 - i - 5] = 0; map[1 + (h - 1) * 6][25 - i - 5] = 0; map[5 + (h + 1) * 6][25 - i - 5] = 0; map[4 + (h + 1) * 6][25 - i - 5] = 0; map[1 + (h + 1) * 6][25 - i - 5] = 0; delay(); mapping2(); break;
		case 5:
			map[4 + (h - 1) * 6][3] = 2; map[4 + (h + 1) * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 6] = 1; map[4 + (h - 1) * 6][25 - i - 6] = 1; map[1 + (h - 1) * 6][25 - i - 6] = 1; map[5 + (h + 1) * 6][25 - i - 6] = 1; map[4 + (h + 1) * 6][25 - i - 6] = 1; map[1 + (h + 1) * 6][25 - i - 6] = 1; mapping2();
			map[4 + (h - 1) * 6][3] = 0; map[4 + (h + 1) * 6][3] = 0; map[5 + (h - 1) * 6][25 - i - 6] = 0; map[4 + (h - 1) * 6][25 - i - 6] = 0; map[1 + (h - 1) * 6][25 - i - 6] = 0; map[5 + (h + 1) * 6][25 - i - 6] = 0; map[4 + (h + 1) * 6][25 - i - 6] = 0; map[1 + (h + 1) * 6][25 - i - 6] = 0; delay(); mapping2(); break;
		case 6:
			map[5 + (h - 1) * 6][3] = 2; map[5 + (h + 1) * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 7] = 1; map[4 + (h - 1) * 6][25 - i - 7] = 1; map[1 + (h - 1) * 6][25 - i - 7] = 1; map[5 + (h + 1) * 6][25 - i - 7] = 1; map[4 + (h + 1) * 6][25 - i - 7] = 1; map[1 + (h + 1) * 6][25 - i - 7] = 1; mapping2();
			map[5 + (h - 1) * 6][25 - i - 7] = 0; map[4 + (h - 1) * 6][25 - i - 7] = 0; map[1 + (h - 1) * 6][25 - i - 7] = 0; map[5 + (h + 1) * 6][25 - i - 7] = 0; map[4 + (h + 1) * 6][25 - i - 7] = 0; map[1 + (h + 1) * 6][25 - i - 7] = 0; delay(); mapping2(); break;
		}
		step++;
		step = step % 7;
	}
}
void jump1_2_13_1(int i, int h) { // �ٲ��ٷ��� ��ֹ��� ���� �ٲ������.
	static int step = 0;
	int j = 0;
	for (j = 0; j<7; j++) {
		switch (step) {
		case 0:
			map[5 + (h - 1) * 6][3] = 2; map[5 + (h + 1) * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 1] = 1; map[4 + (h - 1) * 6][25 - i - 1] = 1; map[1 + (h - 1) * 6][25 - i - 1] = 1; map[5 + (h + 1) * 6][25 - i - 1] = 1; map[4 + (h + 1) * 6][25 - i - 1] = 1; map[1 + (h + 1) * 6][25 - i - 1] = 1; mapping2();
			map[5 + (h - 1) * 6][3] = 0; map[5 + (h + 1) * 6][3] = 0; map[5 + (h - 1) * 6][25 - i - 1] = 0; map[4 + (h - 1) * 6][25 - i - 1] = 0; map[1 + (h - 1) * 6][25 - i - 1] = 0; map[5 + (h + 1) * 6][25 - i - 1] = 0; map[4 + (h + 1) * 6][25 - i - 1] = 0; map[1 + (h + 1) * 6][25 - i - 1] = 0; delay(); mapping2(); break;
		case 1:
			map[4 + (h - 1) * 6][3] = 2; map[5 + (h + 1) * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 2] = 1; map[4 + (h - 1) * 6][25 - i - 2] = 1; map[1 + (h - 1) * 6][25 - i - 2] = 1; map[5 + (h + 1) * 6][25 - i - 2] = 1; map[4 + (h + 1) * 6][25 - i - 2] = 1; map[1 + (h + 1) * 6][25 - i - 2] = 1; mapping2();
			map[4 + (h - 1) * 6][3] = 0; map[5 + (h + 1) * 6][3] = 0; map[5 + (h - 1) * 6][25 - i - 2] = 0; map[4 + (h - 1) * 6][25 - i - 2] = 0; map[1 + (h - 1) * 6][25 - i - 2] = 0; map[5 + (h + 1) * 6][25 - i - 2] = 0; map[4 + (h + 1) * 6][25 - i - 2] = 0; map[1 + (h + 1) * 6][25 - i - 2] = 0; delay(); mapping2(); break;
		case 2:
			map[3 + (h - 1) * 6][3] = 2; map[5 + (h + 1) * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 3] = 1; map[4 + (h - 1) * 6][25 - i - 3] = 1; map[1 + (h - 1) * 6][25 - i - 3] = 1; map[5 + (h + 1) * 6][25 - i - 3] = 1; map[4 + (h + 1) * 6][25 - i - 3] = 1; map[1 + (h + 1) * 6][25 - i - 3] = 1; mapping2();
			map[3 + (h - 1) * 6][3] = 0; map[5 + (h + 1) * 6][3] = 0; map[5 + (h - 1) * 6][25 - i - 3] = 0; map[4 + (h - 1) * 6][25 - i - 3] = 0; map[1 + (h - 1) * 6][25 - i - 3] = 0; map[5 + (h + 1) * 6][25 - i - 3] = 0; map[4 + (h + 1) * 6][25 - i - 3] = 0; map[1 + (h + 1) * 6][25 - i - 3] = 0; delay(); mapping2(); break;
		case 3:
			map[2 + (h - 1) * 6][3] = 2; map[5 + (h + 1) * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 4] = 1; map[4 + (h - 1) * 6][25 - i - 4] = 1; map[1 + (h - 1) * 6][25 - i - 4] = 1; map[5 + (h + 1) * 6][25 - i - 4] = 1; map[4 + (h + 1) * 6][25 - i - 4] = 1; map[1 + (h + 1) * 6][25 - i - 4] = 1; mapping2();
			map[2 + (h - 1) * 6][3] = 0; map[5 + (h + 1) * 6][3] = 0; map[5 + (h - 1) * 6][25 - i - 4] = 0; map[4 + (h - 1) * 6][25 - i - 4] = 0; map[1 + (h - 1) * 6][25 - i - 4] = 0; map[5 + (h + 1) * 6][25 - i - 4] = 0; map[4 + (h + 1) * 6][25 - i - 4] = 0; map[1 + (h + 1) * 6][25 - i - 4] = 0; delay(); mapping2(); break;
		case 4:
			map[3 + (h - 1) * 6][3] = 2; map[5 + (h + 1) * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 5] = 1; map[4 + (h - 1) * 6][25 - i - 5] = 1; map[1 + (h - 1) * 6][25 - i - 5] = 1; map[5 + (h + 1) * 6][25 - i - 5] = 1; map[4 + (h + 1) * 6][25 - i - 5] = 1; map[1 + (h + 1) * 6][25 - i - 5] = 1; mapping2();
			map[3 + (h - 1) * 6][3] = 0; map[5 + (h + 1) * 6][3] = 0; map[5 + (h - 1) * 6][25 - i - 5] = 0; map[4 + (h - 1) * 6][25 - i - 5] = 0; map[1 + (h - 1) * 6][25 - i - 5] = 0; map[5 + (h + 1) * 6][25 - i - 5] = 0; map[4 + (h + 1) * 6][25 - i - 5] = 0; map[1 + (h + 1) * 6][25 - i - 5] = 0; delay(); mapping2(); break;
		case 5:
			map[4 + (h - 1) * 6][3] = 2; map[5 + (h + 1) * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 6] = 1; map[4 + (h - 1) * 6][25 - i - 6] = 1; map[1 + (h - 1) * 6][25 - i - 6] = 1; map[5 + (h + 1) * 6][25 - i - 6] = 1; map[4 + (h + 1) * 6][25 - i - 6] = 1; map[1 + (h + 1) * 6][25 - i - 6] = 1; mapping2();
			map[4 + (h - 1) * 6][3] = 0; map[5 + (h + 1) * 6][3] = 0; map[5 + (h - 1) * 6][25 - i - 6] = 0; map[4 + (h - 1) * 6][25 - i - 6] = 0; map[1 + (h - 1) * 6][25 - i - 6] = 0; map[5 + (h + 1) * 6][25 - i - 6] = 0; map[4 + (h + 1) * 6][25 - i - 6] = 0; map[1 + (h + 1) * 6][25 - i - 6] = 0; delay(); mapping2(); break;
		case 6:
			map[5 + (h - 1) * 6][3] = 2; map[5 + (h + 1) * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 7] = 1; map[4 + (h - 1) * 6][25 - i - 7] = 1; map[1 + (h - 1) * 6][25 - i - 7] = 1; map[5 + (h + 1) * 6][25 - i - 7] = 1; map[4 + (h + 1) * 6][25 - i - 7] = 1; map[1 + (h + 1) * 6][25 - i - 7] = 1; mapping2();
			map[5 + (h - 1) * 6][25 - i - 7] = 0; map[4 + (h - 1) * 6][25 - i - 7] = 0; map[1 + (h - 1) * 6][25 - i - 7] = 0; map[5 + (h + 1) * 6][25 - i - 7] = 0; map[4 + (h + 1) * 6][25 - i - 7] = 0; map[1 + (h + 1) * 6][25 - i - 7] = 0; delay(); mapping2(); break;
		}
		step++;
		step = step % 7;
	}
}
void jump1_2_13_2(int i, int h) { // �ٲ��ٷ��� ��ֹ��� ���� �ٲ������.
	static int step = 0;
	int j = 0;
	for (j = 0; j<7; j++) {
		switch (step) {
		case 0:
			map[5 + (h - 1) * 6][3] = 2; map[5 + (h + 1) * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 1] = 1; map[4 + (h - 1) * 6][25 - i - 1] = 1; map[1 + (h - 1) * 6][25 - i - 1] = 1; map[5 + (h + 1) * 6][25 - i - 1] = 1; map[4 + (h + 1) * 6][25 - i - 1] = 1; map[1 + (h + 1) * 6][25 - i - 1] = 1; mapping2();
			map[5 + (h - 1) * 6][3] = 0; map[5 + (h + 1) * 6][3] = 0; map[5 + (h - 1) * 6][25 - i - 1] = 0; map[4 + (h - 1) * 6][25 - i - 1] = 0; map[1 + (h - 1) * 6][25 - i - 1] = 0; map[5 + (h + 1) * 6][25 - i - 1] = 0; map[4 + (h + 1) * 6][25 - i - 1] = 0; map[1 + (h + 1) * 6][25 - i - 1] = 0; delay(); mapping2(); break;
		case 1:
			map[5 + (h - 1) * 6][3] = 2; map[4 + (h + 1) * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 2] = 1; map[4 + (h - 1) * 6][25 - i - 2] = 1; map[1 + (h - 1) * 6][25 - i - 2] = 1; map[5 + (h + 1) * 6][25 - i - 2] = 1; map[4 + (h + 1) * 6][25 - i - 2] = 1; map[1 + (h + 1) * 6][25 - i - 2] = 1; mapping2();
			map[5 + (h - 1) * 6][3] = 0; map[4 + (h + 1) * 6][3] = 0; map[5 + (h - 1) * 6][25 - i - 2] = 0; map[4 + (h - 1) * 6][25 - i - 2] = 0; map[1 + (h - 1) * 6][25 - i - 2] = 0; map[5 + (h + 1) * 6][25 - i - 2] = 0; map[4 + (h + 1) * 6][25 - i - 2] = 0; map[1 + (h + 1) * 6][25 - i - 2] = 0; delay(); mapping2(); break;
		case 2:
			map[5 + (h - 1) * 6][3] = 2; map[3 + (h + 1) * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 3] = 1; map[4 + (h - 1) * 6][25 - i - 3] = 1; map[1 + (h - 1) * 6][25 - i - 3] = 1; map[5 + (h + 1) * 6][25 - i - 3] = 1; map[4 + (h + 1) * 6][25 - i - 3] = 1; map[1 + (h + 1) * 6][25 - i - 3] = 1; mapping2();
			map[5 + (h - 1) * 6][3] = 0; map[3 + (h + 1) * 6][3] = 0; map[5 + (h - 1) * 6][25 - i - 3] = 0; map[4 + (h - 1) * 6][25 - i - 3] = 0; map[1 + (h - 1) * 6][25 - i - 3] = 0; map[5 + (h + 1) * 6][25 - i - 3] = 0; map[4 + (h + 1) * 6][25 - i - 3] = 0; map[1 + (h + 1) * 6][25 - i - 3] = 0; delay(); mapping2(); break;
		case 3:
			map[5 + (h - 1) * 6][3] = 2; map[2 + (h + 1) * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 4] = 1; map[4 + (h - 1) * 6][25 - i - 4] = 1; map[1 + (h - 1) * 6][25 - i - 4] = 1; map[5 + (h + 1) * 6][25 - i - 4] = 1; map[4 + (h + 1) * 6][25 - i - 4] = 1; map[1 + (h + 1) * 6][25 - i - 4] = 1; mapping2();
			map[5 + (h - 1) * 6][3] = 0; map[2 + (h + 1) * 6][3] = 0; map[5 + (h - 1) * 6][25 - i - 4] = 0; map[4 + (h - 1) * 6][25 - i - 4] = 0; map[1 + (h - 1) * 6][25 - i - 4] = 0; map[5 + (h + 1) * 6][25 - i - 4] = 0; map[4 + (h + 1) * 6][25 - i - 4] = 0; map[1 + (h + 1) * 6][25 - i - 4] = 0; delay(); mapping2(); break;
		case 4:
			map[5 + (h - 1) * 6][3] = 2; map[3 + (h + 1) * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 5] = 1; map[4 + (h - 1) * 6][25 - i - 5] = 1; map[1 + (h - 1) * 6][25 - i - 5] = 1; map[5 + (h + 1) * 6][25 - i - 5] = 1; map[4 + (h + 1) * 6][25 - i - 5] = 1; map[1 + (h + 1) * 6][25 - i - 5] = 1; mapping2();
			map[5 + (h - 1) * 6][3] = 0; map[3 + (h + 1) * 6][3] = 0; map[5 + (h - 1) * 6][25 - i - 5] = 0; map[4 + (h - 1) * 6][25 - i - 5] = 0; map[1 + (h - 1) * 6][25 - i - 5] = 0; map[5 + (h + 1) * 6][25 - i - 5] = 0; map[4 + (h + 1) * 6][25 - i - 5] = 0; map[1 + (h + 1) * 6][25 - i - 5] = 0; delay(); mapping2(); break;
		case 5:
			map[5 + (h - 1) * 6][3] = 2; map[4 + (h + 1) * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 6] = 1; map[4 + (h - 1) * 6][25 - i - 6] = 1; map[1 + (h - 1) * 6][25 - i - 6] = 1; map[5 + (h + 1) * 6][25 - i - 6] = 1; map[4 + (h + 1) * 6][25 - i - 6] = 1; map[1 + (h + 1) * 6][25 - i - 6] = 1; mapping2();
			map[5 + (h - 1) * 6][3] = 0; map[4 + (h + 1) * 6][3] = 0; map[5 + (h - 1) * 6][25 - i - 6] = 0; map[4 + (h - 1) * 6][25 - i - 6] = 0; map[1 + (h - 1) * 6][25 - i - 6] = 0; map[5 + (h + 1) * 6][25 - i - 6] = 0; map[4 + (h + 1) * 6][25 - i - 6] = 0; map[1 + (h + 1) * 6][25 - i - 6] = 0; delay(); mapping2(); break;
		case 6:
			map[5 + (h - 1) * 6][3] = 2; map[5 + (h + 1) * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 7] = 1; map[4 + (h - 1) * 6][25 - i - 7] = 1; map[1 + (h - 1) * 6][25 - i - 7] = 1; map[5 + (h + 1) * 6][25 - i - 7] = 1; map[4 + (h + 1) * 6][25 - i - 7] = 1; map[1 + (h + 1) * 6][25 - i - 7] = 1; mapping2();
			map[5 + (h - 1) * 6][25 - i - 7] = 0; map[4 + (h - 1) * 6][25 - i - 7] = 0; map[1 + (h - 1) * 6][25 - i - 7] = 0; map[5 + (h + 1) * 6][25 - i - 7] = 0; map[4 + (h + 1) * 6][25 - i - 7] = 0; map[1 + (h + 1) * 6][25 - i - 7] = 0; delay(); mapping2(); break;
		}
		step++;
		step = step % 7;
	}
}

void jump1_3(int i, int h) { // �ٲ��ٷ��� ��ֹ��� ���� �ٲ������.
	static int step = 0;
	int j = 0;
	for (j = 0; j<7; j++) {
		switch (step) {
		case 0:
			map[5 + (h - 1) * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 1] = 1; map[4 + (h - 1) * 6][25 - i - 1] = 1; map[3 + (h - 1) * 6][25 - i - 1] = 1; map[1 + (h - 1) * 6][25 - i - 1] = 1; mapping2();
			map[5 + (h - 1) * 6][3] = 0; map[5 + (h - 1) * 6][25 - i - 1] = 0; map[4 + (h - 1) * 6][25 - i - 1] = 0; map[3 + (h - 1) * 6][25 - i - 1] = 0; map[1 + (h - 1) * 6][25 - i - 1] = 0; delay(); mapping2(); break;
		case 1:
			map[4 + (h - 1) * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 2] = 1; map[4 + (h - 1) * 6][25 - i - 2] = 1; map[3 + (h - 1) * 6][25 - i - 2] = 1; map[1 + (h - 1) * 6][25 - i - 2] = 1; mapping2();
			map[4 + (h - 1) * 6][3] = 0; map[5 + (h - 1) * 6][25 - i - 2] = 0; map[4 + (h - 1) * 6][25 - i - 2] = 0; map[3 + (h - 1) * 6][25 - i - 2] = 0; map[1 + (h - 1) * 6][25 - i - 2] = 0; delay(); mapping2(); break;
		case 2:
			map[3 + (h - 1) * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 3] = 1; map[4 + (h - 1) * 6][25 - i - 3] = 1; map[3 + (h - 1) * 6][25 - i - 3] = 1; map[1 + (h - 1) * 6][25 - i - 3] = 1; mapping2();
			map[3 + (h - 1) * 6][3] = 0; map[5 + (h - 1) * 6][25 - i - 3] = 0; map[4 + (h - 1) * 6][25 - i - 3] = 0; map[3 + (h - 1) * 6][25 - i - 3] = 0; map[1 + (h - 1) * 6][25 - i - 3] = 0; delay(); mapping2(); break;
		case 3:
			map[2 + (h - 1) * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 4] = 1; map[4 + (h - 1) * 6][25 - i - 4] = 1; map[3 + (h - 1) * 6][25 - i - 4] = 1; map[1 + (h - 1) * 6][25 - i - 4] = 1; mapping2();
			map[2 + (h - 1) * 6][3] = 0; map[5 + (h - 1) * 6][25 - i - 4] = 0; map[4 + (h - 1) * 6][25 - i - 4] = 0; map[3 + (h - 1) * 6][25 - i - 4] = 0; map[1 + (h - 1) * 6][25 - i - 4] = 0; delay(); mapping2(); break;
		case 4:
			map[3 + (h - 1) * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 5] = 1; map[4 + (h - 1) * 6][25 - i - 5] = 1; map[3 + (h - 1) * 6][25 - i - 5] = 1; map[1 + (h - 1) * 6][25 - i - 5] = 1; mapping2();
			map[3 + (h - 1) * 6][3] = 0; map[5 + (h - 1) * 6][25 - i - 5] = 0; map[4 + (h - 1) * 6][25 - i - 5] = 0; map[3 + (h - 1) * 6][25 - i - 5] = 0; map[1 + (h - 1) * 6][25 - i - 5] = 0; delay(); mapping2(); break;
		case 5:
			map[4 + (h - 1) * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 6] = 1; map[4 + (h - 1) * 6][25 - i - 6] = 1; map[3 + (h - 1) * 6][25 - i - 6] = 1; map[1 + (h - 1) * 6][25 - i - 6] = 1; mapping2();
			map[4 + (h - 1) * 6][3] = 0; map[5 + (h - 1) * 6][25 - i - 6] = 0; map[4 + (h - 1) * 6][25 - i - 6] = 0; map[3 + (h - 1) * 6][25 - i - 6] = 0; map[1 + (h - 1) * 6][25 - i - 6] = 0; delay(); mapping2(); break;
		case 6:
			map[5 + (h - 1) * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 7] = 1; map[4 + (h - 1) * 6][25 - i - 7] = 1; map[3 + (h - 1) * 6][25 - i - 7] = 1; map[1 + (h - 1) * 6][25 - i - 7] = 1; mapping2();
			map[5 + (h - 1) * 6][25 - i - 7] = 0; map[4 + (h - 1) * 6][25 - i - 7] = 0; map[3 + (h - 1) * 6][25 - i - 7] = 0; map[1 + (h - 1) * 6][25 - i - 7] = 0; delay(); mapping2(); break;
		}
		step++;
		step = step % 7;
	}
}
void jump1_3_12(int i, int h) { // �ٲ��ٷ��� ��ֹ��� ���� �ٲ������.
	static int step = 0;
	int j = 0;
	for (j = 0; j<7; j++) {
		switch (step) {
		case 0:
			map[5 + (h - 1) * 6][3] = 2; map[5 + h * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 1] = 1; map[4 + (h - 1) * 6][25 - i - 1] = 1; map[3 + (h - 1) * 6][25 - i - 1] = 1; map[1 + (h - 1) * 6][25 - i - 1] = 1; map[5 + h * 6][25 - i - 1] = 1; map[4 + h * 6][25 - i - 1] = 1; map[3 + h * 6][25 - i - 1] = 1; map[1 + h * 6][25 - i - 1] = 1; mapping2();
			map[5 + (h - 1) * 6][3] = 0; map[5 + h * 6][3] = 0; map[5 + (h - 1) * 6][25 - i - 1] = 0; map[4 + (h - 1) * 6][25 - i - 1] = 0; map[3 + (h - 1) * 6][25 - i - 1] = 0; map[1 + (h - 1) * 6][25 - i - 1] = 0; map[5 + h * 6][25 - i - 1] = 0; map[4 + h * 6][25 - i - 1] = 0; map[3 + h * 6][25 - i - 1] = 0; map[1 + h * 6][25 - i - 1] = 0; delay(); mapping2(); break;
		case 1:
			map[4 + (h - 1) * 6][3] = 2; map[4 + h * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 2] = 1; map[4 + (h - 1) * 6][25 - i - 2] = 1; map[3 + (h - 1) * 6][25 - i - 2] = 1; map[1 + (h - 1) * 6][25 - i - 2] = 1; map[5 + h * 6][25 - i - 2] = 1; map[4 + h * 6][25 - i - 2] = 1; map[3 + h * 6][25 - i - 2] = 1; map[1 + h * 6][25 - i - 2] = 1; mapping2();
			map[4 + (h - 1) * 6][3] = 0; map[4 + h * 6][3] = 0; map[5 + (h - 1) * 6][25 - i - 2] = 0; map[4 + (h - 1) * 6][25 - i - 2] = 0; map[3 + (h - 1) * 6][25 - i - 2] = 0; map[1 + (h - 1) * 6][25 - i - 2] = 0; map[5 + h * 6][25 - i - 2] = 0; map[4 + h * 6][25 - i - 2] = 0; map[3 + h * 6][25 - i - 2] = 0; map[1 + h * 6][25 - i - 2] = 0; delay(); mapping2(); break;
		case 2:
			map[3 + (h - 1) * 6][3] = 2; map[3 + h * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 3] = 1; map[4 + (h - 1) * 6][25 - i - 3] = 1; map[3 + (h - 1) * 6][25 - i - 3] = 1; map[1 + (h - 1) * 6][25 - i - 3] = 1; map[5 + h * 6][25 - i - 3] = 1; map[4 + h * 6][25 - i - 3] = 1; map[3 + h * 6][25 - i - 3] = 1; map[1 + h * 6][25 - i - 3] = 1; mapping2();
			map[3 + (h - 1) * 6][3] = 0; map[3 + h * 6][3] = 0; map[5 + (h - 1) * 6][25 - i - 3] = 0; map[4 + (h - 1) * 6][25 - i - 3] = 0; map[3 + (h - 1) * 6][25 - i - 3] = 0; map[1 + (h - 1) * 6][25 - i - 3] = 0; map[5 + h * 6][25 - i - 3] = 0; map[4 + h * 6][25 - i - 3] = 0; map[3 + h * 6][25 - i - 3] = 0; map[1 + h * 6][25 - i - 3] = 0; delay(); mapping2(); break;
		case 3:
			map[2 + (h - 1) * 6][3] = 2; map[2 + h * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 4] = 1; map[4 + (h - 1) * 6][25 - i - 4] = 1; map[3 + (h - 1) * 6][25 - i - 4] = 1; map[1 + (h - 1) * 6][25 - i - 4] = 1; map[5 + h * 6][25 - i - 4] = 1; map[4 + h * 6][25 - i - 4] = 1; map[3 + h * 6][25 - i - 4] = 1; map[1 + h * 6][25 - i - 4] = 1; mapping2();
			map[2 + (h - 1) * 6][3] = 0; map[2 + h * 6][3] = 0; map[5 + (h - 1) * 6][25 - i - 4] = 0; map[4 + (h - 1) * 6][25 - i - 4] = 0; map[3 + (h - 1) * 6][25 - i - 4] = 0; map[1 + (h - 1) * 6][25 - i - 4] = 0; map[5 + h * 6][25 - i - 4] = 0; map[4 + h * 6][25 - i - 4] = 0; map[3 + h * 6][25 - i - 4] = 0; map[1 + h * 6][25 - i - 4] = 0; delay(); mapping2(); break;
		case 4:
			map[3 + (h - 1) * 6][3] = 2; map[3 + h * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 5] = 1; map[4 + (h - 1) * 6][25 - i - 5] = 1; map[3 + (h - 1) * 6][25 - i - 5] = 1; map[1 + (h - 1) * 6][25 - i - 5] = 1; map[5 + h * 6][25 - i - 5] = 1; map[4 + h * 6][25 - i - 5] = 1; map[3 + h * 6][25 - i - 5] = 1; map[1 + h * 6][25 - i - 5] = 1; mapping2();
			map[3 + (h - 1) * 6][3] = 0; map[3 + h * 6][3] = 0; map[5 + (h - 1) * 6][25 - i - 5] = 0; map[4 + (h - 1) * 6][25 - i - 5] = 0; map[3 + (h - 1) * 6][25 - i - 5] = 0; map[1 + (h - 1) * 6][25 - i - 5] = 0; map[5 + h * 6][25 - i - 5] = 0; map[4 + h * 6][25 - i - 5] = 0; map[3 + h * 6][25 - i - 5] = 0; map[1 + h * 6][25 - i - 5] = 0; delay(); mapping2(); break;
		case 5:
			map[4 + (h - 1) * 6][3] = 2; map[4 + h * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 6] = 1; map[4 + (h - 1) * 6][25 - i - 6] = 1; map[3 + (h - 1) * 6][25 - i - 6] = 1; map[1 + (h - 1) * 6][25 - i - 6] = 1; map[5 + h * 6][25 - i - 6] = 1; map[4 + h * 6][25 - i - 6] = 1; map[3 + h * 6][25 - i - 6] = 1; map[1 + h * 6][25 - i - 6] = 1; mapping2();
			map[4 + (h - 1) * 6][3] = 0; map[4 + h * 6][3] = 0; map[5 + (h - 1) * 6][25 - i - 6] = 0; map[4 + (h - 1) * 6][25 - i - 6] = 0; map[3 + (h - 1) * 6][25 - i - 6] = 0; map[1 + (h - 1) * 6][25 - i - 6] = 0; map[5 + h * 6][25 - i - 6] = 0; map[4 + h * 6][25 - i - 6] = 0; map[3 + h * 6][25 - i - 6] = 0; map[1 + h * 6][25 - i - 6] = 0; delay(); mapping2(); break;
		case 6:
			map[5 + (h - 1) * 6][3] = 2; map[5 + h * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 7] = 1; map[4 + (h - 1) * 6][25 - i - 7] = 1; map[3 + (h - 1) * 6][25 - i - 7] = 1; map[1 + (h - 1) * 6][25 - i - 7] = 1; map[5 + h * 6][25 - i - 7] = 1; map[4 + h * 6][25 - i - 7] = 1; map[3 + h * 6][25 - i - 7] = 1; map[1 + h * 6][25 - i - 7] = 1; mapping2();
			map[5 + (h - 1) * 6][25 - i - 7] = 0; map[4 + (h - 1) * 6][25 - i - 7] = 0; map[3 + (h - 1) * 6][25 - i - 7] = 0; map[1 + (h - 1) * 6][25 - i - 7] = 0; map[5 + h * 6][25 - i - 7] = 0; map[4 + h * 6][25 - i - 7] = 0; map[3 + h * 6][25 - i - 7] = 0; map[1 + h * 6][25 - i - 7] = 0; delay(); mapping2(); break;
		}
		step++;
		step = step % 7;
	}
}
void jump1_3_12_1(int i, int h) { // �ٲ��ٷ��� ��ֹ��� ���� �ٲ������.
	static int step = 0;
	int j = 0;
	for (j = 0; j<7; j++) {
		switch (step) {
		case 0:
			map[5 + (h - 1) * 6][3] = 2; map[5 + h * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 1] = 1; map[4 + (h - 1) * 6][25 - i - 1] = 1; map[3 + (h - 1) * 6][25 - i - 1] = 1; map[1 + (h - 1) * 6][25 - i - 1] = 1; map[5 + h * 6][25 - i - 1] = 1; map[4 + h * 6][25 - i - 1] = 1; map[3 + h * 6][25 - i - 1] = 1; map[1 + h * 6][25 - i - 1] = 1; mapping2();
			map[5 + (h - 1) * 6][3] = 0; map[5 + h * 6][3] = 0; map[5 + (h - 1) * 6][25 - i - 1] = 0; map[4 + (h - 1) * 6][25 - i - 1] = 0; map[3 + (h - 1) * 6][25 - i - 1] = 0; map[1 + (h - 1) * 6][25 - i - 1] = 0; map[5 + h * 6][25 - i - 1] = 0; map[4 + h * 6][25 - i - 1] = 0; map[3 + h * 6][25 - i - 1] = 0; map[1 + h * 6][25 - i - 1] = 0; delay(); mapping2(); break;
		case 1:
			map[4 + (h - 1) * 6][3] = 2; map[5 + h * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 2] = 1; map[4 + (h - 1) * 6][25 - i - 2] = 1; map[3 + (h - 1) * 6][25 - i - 2] = 1; map[1 + (h - 1) * 6][25 - i - 2] = 1; map[5 + h * 6][25 - i - 2] = 1; map[4 + h * 6][25 - i - 2] = 1; map[3 + h * 6][25 - i - 2] = 1; map[1 + h * 6][25 - i - 2] = 1; mapping2();
			map[4 + (h - 1) * 6][3] = 0; map[5 + h * 6][3] = 0; map[5 + (h - 1) * 6][25 - i - 2] = 0; map[4 + (h - 1) * 6][25 - i - 2] = 0; map[3 + (h - 1) * 6][25 - i - 2] = 0; map[1 + (h - 1) * 6][25 - i - 2] = 0; map[5 + h * 6][25 - i - 2] = 0; map[4 + h * 6][25 - i - 2] = 0; map[3 + h * 6][25 - i - 2] = 0; map[1 + h * 6][25 - i - 2] = 0; delay(); mapping2(); break;
		case 2:
			map[3 + (h - 1) * 6][3] = 2; map[5 + h * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 3] = 1; map[4 + (h - 1) * 6][25 - i - 3] = 1; map[3 + (h - 1) * 6][25 - i - 3] = 1; map[1 + (h - 1) * 6][25 - i - 3] = 1; map[5 + h * 6][25 - i - 3] = 1; map[4 + h * 6][25 - i - 3] = 1; map[3 + h * 6][25 - i - 3] = 1; map[1 + h * 6][25 - i - 3] = 1; mapping2();
			map[3 + (h - 1) * 6][3] = 0; map[5 + h * 6][3] = 0; map[5 + (h - 1) * 6][25 - i - 3] = 0; map[4 + (h - 1) * 6][25 - i - 3] = 0; map[3 + (h - 1) * 6][25 - i - 3] = 0; map[1 + (h - 1) * 6][25 - i - 3] = 0; map[5 + h * 6][25 - i - 3] = 0; map[4 + h * 6][25 - i - 3] = 0; map[3 + h * 6][25 - i - 3] = 0; map[1 + h * 6][25 - i - 3] = 0; delay(); mapping2(); break;
		case 3:
			map[2 + (h - 1) * 6][3] = 2; map[5 + h * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 4] = 1; map[4 + (h - 1) * 6][25 - i - 4] = 1; map[3 + (h - 1) * 6][25 - i - 4] = 1; map[1 + (h - 1) * 6][25 - i - 4] = 1; map[5 + h * 6][25 - i - 4] = 1; map[4 + h * 6][25 - i - 4] = 1; map[3 + h * 6][25 - i - 4] = 1; map[1 + h * 6][25 - i - 4] = 1; mapping2();
			map[2 + (h - 1) * 6][3] = 0; map[5 + h * 6][3] = 0; map[5 + (h - 1) * 6][25 - i - 4] = 0; map[4 + (h - 1) * 6][25 - i - 4] = 0; map[3 + (h - 1) * 6][25 - i - 4] = 0; map[1 + (h - 1) * 6][25 - i - 4] = 0; map[5 + h * 6][25 - i - 4] = 0; map[4 + h * 6][25 - i - 4] = 0; map[3 + h * 6][25 - i - 4] = 0; map[1 + h * 6][25 - i - 4] = 0; delay(); mapping2(); break;
		case 4:
			map[3 + (h - 1) * 6][3] = 2; map[5 + h * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 5] = 1; map[4 + (h - 1) * 6][25 - i - 5] = 1; map[3 + (h - 1) * 6][25 - i - 5] = 1; map[1 + (h - 1) * 6][25 - i - 5] = 1; map[5 + h * 6][25 - i - 5] = 1; map[4 + h * 6][25 - i - 5] = 1; map[3 + h * 6][25 - i - 5] = 1; map[1 + h * 6][25 - i - 5] = 1; mapping2();
			map[3 + (h - 1) * 6][3] = 0; map[5 + h * 6][3] = 0; map[5 + (h - 1) * 6][25 - i - 5] = 0; map[4 + (h - 1) * 6][25 - i - 5] = 0; map[3 + (h - 1) * 6][25 - i - 5] = 0; map[1 + (h - 1) * 6][25 - i - 5] = 0; map[5 + h * 6][25 - i - 5] = 0; map[4 + h * 6][25 - i - 5] = 0; map[3 + h * 6][25 - i - 5] = 0; map[1 + h * 6][25 - i - 5] = 0; delay(); mapping2(); break;
		case 5:
			map[4 + (h - 1) * 6][3] = 2; map[5 + h * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 6] = 1; map[4 + (h - 1) * 6][25 - i - 6] = 1; map[3 + (h - 1) * 6][25 - i - 6] = 1; map[1 + (h - 1) * 6][25 - i - 6] = 1; map[5 + h * 6][25 - i - 6] = 1; map[4 + h * 6][25 - i - 6] = 1; map[3 + h * 6][25 - i - 6] = 1; map[1 + h * 6][25 - i - 6] = 1; mapping2();
			map[4 + (h - 1) * 6][3] = 0; map[5 + h * 6][3] = 0; map[5 + (h - 1) * 6][25 - i - 6] = 0; map[4 + (h - 1) * 6][25 - i - 6] = 0; map[3 + (h - 1) * 6][25 - i - 6] = 0; map[1 + (h - 1) * 6][25 - i - 6] = 0; map[5 + h * 6][25 - i - 6] = 0; map[4 + h * 6][25 - i - 6] = 0; map[3 + h * 6][25 - i - 6] = 0; map[1 + h * 6][25 - i - 6] = 0; delay(); mapping2(); break;
		case 6:
			map[5 + (h - 1) * 6][3] = 2; map[5 + h * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 7] = 1; map[4 + (h - 1) * 6][25 - i - 7] = 1; map[3 + (h - 1) * 6][25 - i - 7] = 1; map[1 + (h - 1) * 6][25 - i - 7] = 1; map[5 + h * 6][25 - i - 7] = 1; map[4 + h * 6][25 - i - 7] = 1; map[3 + h * 6][25 - i - 7] = 1; map[1 + h * 6][25 - i - 7] = 1; mapping2();
			map[5 + (h - 1) * 6][25 - i - 7] = 0; map[4 + (h - 1) * 6][25 - i - 7] = 0; map[3 + (h - 1) * 6][25 - i - 7] = 0; map[1 + (h - 1) * 6][25 - i - 7] = 0; map[5 + h * 6][25 - i - 7] = 0; map[4 + h * 6][25 - i - 7] = 0; map[3 + h * 6][25 - i - 7] = 0; map[1 + h * 6][25 - i - 7] = 0; delay(); mapping2(); break;
		}
		step++;
		step = step % 7;
	}
}
void jump1_3_12_2(int i, int h) { // �ٲ��ٷ��� ��ֹ��� ���� �ٲ������.
	static int step = 0;
	int j = 0;
	for (j = 0; j<7; j++) {
		switch (step) {
		case 0:
			map[5 + (h - 1) * 6][3] = 2; map[5 + h * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 1] = 1; map[4 + (h - 1) * 6][25 - i - 1] = 1; map[3 + (h - 1) * 6][25 - i - 1] = 1; map[1 + (h - 1) * 6][25 - i - 1] = 1; map[5 + h * 6][25 - i - 1] = 1; map[4 + h * 6][25 - i - 1] = 1; map[3 + h * 6][25 - i - 1] = 1; map[1 + h * 6][25 - i - 1] = 1; mapping2();
			map[5 + (h - 1) * 6][3] = 0; map[5 + h * 6][3] = 0; map[5 + (h - 1) * 6][25 - i - 1] = 0; map[4 + (h - 1) * 6][25 - i - 1] = 0; map[3 + (h - 1) * 6][25 - i - 1] = 0; map[1 + (h - 1) * 6][25 - i - 1] = 0; map[5 + h * 6][25 - i - 1] = 0; map[4 + h * 6][25 - i - 1] = 0; map[3 + h * 6][25 - i - 1] = 0; map[1 + h * 6][25 - i - 1] = 0; delay(); mapping2(); break;
		case 1:
			map[5 + (h - 1) * 6][3] = 2; map[4 + h * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 2] = 1; map[4 + (h - 1) * 6][25 - i - 2] = 1; map[3 + (h - 1) * 6][25 - i - 2] = 1; map[1 + (h - 1) * 6][25 - i - 2] = 1; map[5 + h * 6][25 - i - 2] = 1; map[4 + h * 6][25 - i - 2] = 1; map[3 + h * 6][25 - i - 2] = 1; map[1 + h * 6][25 - i - 2] = 1; mapping2();
			map[5 + (h - 1) * 6][3] = 0; map[4 + h * 6][3] = 0; map[5 + (h - 1) * 6][25 - i - 2] = 0; map[4 + (h - 1) * 6][25 - i - 2] = 0; map[3 + (h - 1) * 6][25 - i - 2] = 0; map[1 + (h - 1) * 6][25 - i - 2] = 0; map[5 + h * 6][25 - i - 2] = 0; map[4 + h * 6][25 - i - 2] = 0; map[3 + h * 6][25 - i - 2] = 0; map[1 + h * 6][25 - i - 2] = 0; delay(); mapping2(); break;
		case 2:
			map[5 + (h - 1) * 6][3] = 2; map[3 + h * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 3] = 1; map[4 + (h - 1) * 6][25 - i - 3] = 1; map[3 + (h - 1) * 6][25 - i - 3] = 1; map[1 + (h - 1) * 6][25 - i - 3] = 1; map[5 + h * 6][25 - i - 3] = 1; map[4 + h * 6][25 - i - 3] = 1; map[3 + h * 6][25 - i - 3] = 1; map[1 + h * 6][25 - i - 3] = 1; mapping2();
			map[5 + (h - 1) * 6][3] = 0; map[3 + h * 6][3] = 0; map[5 + (h - 1) * 6][25 - i - 3] = 0; map[4 + (h - 1) * 6][25 - i - 3] = 0; map[3 + (h - 1) * 6][25 - i - 3] = 0; map[1 + (h - 1) * 6][25 - i - 3] = 0; map[5 + h * 6][25 - i - 3] = 0; map[4 + h * 6][25 - i - 3] = 0; map[3 + h * 6][25 - i - 3] = 0; map[1 + h * 6][25 - i - 3] = 0; delay(); mapping2(); break;
		case 3:
			map[5 + (h - 1) * 6][3] = 2; map[2 + h * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 4] = 1; map[4 + (h - 1) * 6][25 - i - 4] = 1; map[3 + (h - 1) * 6][25 - i - 4] = 1; map[1 + (h - 1) * 6][25 - i - 4] = 1; map[5 + h * 6][25 - i - 4] = 1; map[4 + h * 6][25 - i - 4] = 1; map[3 + h * 6][25 - i - 4] = 1; map[1 + h * 6][25 - i - 4] = 1; mapping2();
			map[5 + (h - 1) * 6][3] = 0; map[2 + h * 6][3] = 0; map[5 + (h - 1) * 6][25 - i - 4] = 0; map[4 + (h - 1) * 6][25 - i - 4] = 0; map[3 + (h - 1) * 6][25 - i - 4] = 0; map[1 + (h - 1) * 6][25 - i - 4] = 0; map[5 + h * 6][25 - i - 4] = 0; map[4 + h * 6][25 - i - 4] = 0; map[3 + h * 6][25 - i - 4] = 0; map[1 + h * 6][25 - i - 4] = 0; delay(); mapping2(); break;
		case 4:
			map[5 + (h - 1) * 6][3] = 2; map[3 + h * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 5] = 1; map[4 + (h - 1) * 6][25 - i - 5] = 1; map[3 + (h - 1) * 6][25 - i - 5] = 1; map[1 + (h - 1) * 6][25 - i - 5] = 1; map[5 + h * 6][25 - i - 5] = 1; map[4 + h * 6][25 - i - 5] = 1; map[3 + h * 6][25 - i - 5] = 1; map[1 + h * 6][25 - i - 5] = 1; mapping2();
			map[5 + (h - 1) * 6][3] = 0; map[3 + h * 6][3] = 0; map[5 + (h - 1) * 6][25 - i - 5] = 0; map[4 + (h - 1) * 6][25 - i - 5] = 0; map[3 + (h - 1) * 6][25 - i - 5] = 0; map[1 + (h - 1) * 6][25 - i - 5] = 0; map[5 + h * 6][25 - i - 5] = 0; map[4 + h * 6][25 - i - 5] = 0; map[3 + h * 6][25 - i - 5] = 0; map[1 + h * 6][25 - i - 5] = 0; delay(); mapping2(); break;
		case 5:
			map[5 + (h - 1) * 6][3] = 2; map[4 + h * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 6] = 1; map[4 + (h - 1) * 6][25 - i - 6] = 1; map[3 + (h - 1) * 6][25 - i - 6] = 1; map[1 + (h - 1) * 6][25 - i - 6] = 1; map[5 + h * 6][25 - i - 6] = 1; map[4 + h * 6][25 - i - 6] = 1; map[3 + h * 6][25 - i - 6] = 1; map[1 + h * 6][25 - i - 6] = 1; mapping2();
			map[5 + (h - 1) * 6][3] = 0; map[4 + h * 6][3] = 0; map[5 + (h - 1) * 6][25 - i - 6] = 0; map[4 + (h - 1) * 6][25 - i - 6] = 0; map[3 + (h - 1) * 6][25 - i - 6] = 0; map[1 + (h - 1) * 6][25 - i - 6] = 0; map[5 + h * 6][25 - i - 6] = 0; map[4 + h * 6][25 - i - 6] = 0; map[3 + h * 6][25 - i - 6] = 0; map[1 + h * 6][25 - i - 6] = 0; delay(); mapping2(); break;
		case 6:
			map[5 + (h - 1) * 6][3] = 2; map[5 + h * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 7] = 1; map[4 + (h - 1) * 6][25 - i - 7] = 1; map[3 + (h - 1) * 6][25 - i - 7] = 1; map[1 + (h - 1) * 6][25 - i - 7] = 1; map[5 + h * 6][25 - i - 7] = 1; map[4 + h * 6][25 - i - 7] = 1; map[3 + h * 6][25 - i - 7] = 1; map[1 + h * 6][25 - i - 7] = 1; mapping2();
			map[5 + (h - 1) * 6][25 - i - 7] = 0; map[4 + (h - 1) * 6][25 - i - 7] = 0; map[3 + (h - 1) * 6][25 - i - 7] = 0; map[1 + (h - 1) * 6][25 - i - 7] = 0; map[5 + h * 6][25 - i - 7] = 0; map[4 + h * 6][25 - i - 7] = 0; map[3 + h * 6][25 - i - 7] = 0; map[1 + h * 6][25 - i - 7] = 0; delay(); mapping2(); break;
		}
		step++;
		step = step % 7;
	}
}
void jump1_3_13(int i, int h) { // �ٲ��ٷ��� ��ֹ��� ���� �ٲ������.
	static int step = 0;
	int j = 0;
	for (j = 0; j<7; j++) {
		switch (step) {
		case 0:
			map[5 + (h - 1) * 6][3] = 2; map[5 + (h + 1) * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 1] = 1; map[4 + (h - 1) * 6][25 - i - 1] = 1; map[3 + (h - 1) * 6][25 - i - 1] = 1; map[1 + (h - 1) * 6][25 - i - 1] = 1; map[5 + (h + 1) * 6][25 - i - 1] = 1; map[4 + (h + 1) * 6][25 - i - 1] = 1; map[3 + (h + 1) * 6][25 - i - 1] = 1; map[1 + (h + 1) * 6][25 - i - 1] = 1; mapping2();
			map[5 + (h - 1) * 6][3] = 0; map[5 + (h + 1) * 6][3] = 0; map[5 + (h - 1) * 6][25 - i - 1] = 0; map[4 + (h - 1) * 6][25 - i - 1] = 0; map[3 + (h - 1) * 6][25 - i - 1] = 0; map[1 + (h - 1) * 6][25 - i - 1] = 0; map[5 + (h + 1) * 6][25 - i - 1] = 0; map[4 + (h + 1) * 6][25 - i - 1] = 0; map[3 + (h + 1) * 6][25 - i - 1] = 0; map[1 + (h + 1) * 6][25 - i - 1] = 0; delay(); mapping2(); break;
		case 1:
			map[4 + (h - 1) * 6][3] = 2; map[4 + (h + 1) * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 2] = 1; map[4 + (h - 1) * 6][25 - i - 2] = 1; map[3 + (h - 1) * 6][25 - i - 2] = 1; map[1 + (h - 1) * 6][25 - i - 2] = 1; map[5 + (h + 1) * 6][25 - i - 2] = 1; map[4 + (h + 1) * 6][25 - i - 2] = 1; map[3 + (h + 1) * 6][25 - i - 2] = 1; map[1 + (h + 1) * 6][25 - i - 2] = 1; mapping2();
			map[4 + (h - 1) * 6][3] = 0; map[4 + (h + 1) * 6][3] = 0; map[5 + (h - 1) * 6][25 - i - 2] = 0; map[4 + (h - 1) * 6][25 - i - 2] = 0; map[3 + (h - 1) * 6][25 - i - 2] = 0; map[1 + (h - 1) * 6][25 - i - 2] = 0; map[5 + (h + 1) * 6][25 - i - 2] = 0; map[4 + (h + 1) * 6][25 - i - 2] = 0; map[3 + (h + 1) * 6][25 - i - 2] = 0; map[1 + (h + 1) * 6][25 - i - 2] = 0; delay(); mapping2(); break;
		case 2:
			map[3 + (h - 1) * 6][3] = 2; map[3 + (h + 1) * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 3] = 1; map[4 + (h - 1) * 6][25 - i - 3] = 1; map[3 + (h - 1) * 6][25 - i - 3] = 1; map[1 + (h - 1) * 6][25 - i - 3] = 1; map[5 + (h + 1) * 6][25 - i - 3] = 1; map[4 + (h + 1) * 6][25 - i - 3] = 1; map[3 + (h + 1) * 6][25 - i - 3] = 1; map[1 + (h + 1) * 6][25 - i - 3] = 1; mapping2();
			map[3 + (h - 1) * 6][3] = 0; map[3 + (h + 1) * 6][3] = 0; map[5 + (h - 1) * 6][25 - i - 3] = 0; map[4 + (h - 1) * 6][25 - i - 3] = 0; map[3 + (h - 1) * 6][25 - i - 3] = 0; map[1 + (h - 1) * 6][25 - i - 3] = 0; map[5 + (h + 1) * 6][25 - i - 3] = 0; map[4 + (h + 1) * 6][25 - i - 3] = 0; map[3 + (h + 1) * 6][25 - i - 3] = 0; map[1 + (h + 1) * 6][25 - i - 3] = 0; delay(); mapping2(); break;
		case 3:
			map[2 + (h - 1) * 6][3] = 2; map[2 + (h + 1) * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 4] = 1; map[4 + (h - 1) * 6][25 - i - 4] = 1; map[3 + (h - 1) * 6][25 - i - 4] = 1; map[1 + (h - 1) * 6][25 - i - 4] = 1; map[5 + (h + 1) * 6][25 - i - 4] = 1; map[4 + (h + 1) * 6][25 - i - 4] = 1; map[3 + (h + 1) * 6][25 - i - 4] = 1; map[1 + (h + 1) * 6][25 - i - 4] = 1; mapping2();
			map[2 + (h - 1) * 6][3] = 0; map[2 + (h + 1) * 6][3] = 0; map[5 + (h - 1) * 6][25 - i - 4] = 0; map[4 + (h - 1) * 6][25 - i - 4] = 0; map[3 + (h - 1) * 6][25 - i - 4] = 0; map[1 + (h - 1) * 6][25 - i - 4] = 0; map[5 + (h + 1) * 6][25 - i - 4] = 0; map[4 + (h + 1) * 6][25 - i - 4] = 0; map[3 + (h + 1) * 6][25 - i - 4] = 0; map[1 + (h + 1) * 6][25 - i - 4] = 0; delay(); mapping2(); break;
		case 4:
			map[3 + (h - 1) * 6][3] = 2; map[3 + (h + 1) * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 5] = 1; map[4 + (h - 1) * 6][25 - i - 5] = 1; map[3 + (h - 1) * 6][25 - i - 5] = 1; map[1 + (h - 1) * 6][25 - i - 5] = 1; map[5 + (h + 1) * 6][25 - i - 5] = 1; map[4 + (h + 1) * 6][25 - i - 5] = 1; map[3 + (h + 1) * 6][25 - i - 5] = 1; map[1 + (h + 1) * 6][25 - i - 5] = 1; mapping2();
			map[3 + (h - 1) * 6][3] = 0; map[3 + (h + 1) * 6][3] = 0; map[5 + (h - 1) * 6][25 - i - 5] = 0; map[4 + (h - 1) * 6][25 - i - 5] = 0; map[3 + (h - 1) * 6][25 - i - 5] = 0; map[1 + (h - 1) * 6][25 - i - 5] = 0; map[5 + (h + 1) * 6][25 - i - 5] = 0; map[4 + (h + 1) * 6][25 - i - 5] = 0; map[3 + (h + 1) * 6][25 - i - 5] = 0; map[1 + (h + 1) * 6][25 - i - 5] = 0; delay(); mapping2(); break;
		case 5:
			map[4 + (h - 1) * 6][3] = 2; map[4 + (h + 1) * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 6] = 1; map[4 + (h - 1) * 6][25 - i - 6] = 1; map[3 + (h - 1) * 6][25 - i - 6] = 1; map[1 + (h - 1) * 6][25 - i - 6] = 1; map[5 + (h + 1) * 6][25 - i - 6] = 1; map[4 + (h + 1) * 6][25 - i - 6] = 1; map[3 + (h + 1) * 6][25 - i - 6] = 1; map[1 + (h + 1) * 6][25 - i - 6] = 1; mapping2();
			map[4 + (h - 1) * 6][3] = 0; map[4 + (h + 1) * 6][3] = 0; map[5 + (h - 1) * 6][25 - i - 6] = 0; map[4 + (h - 1) * 6][25 - i - 6] = 0; map[3 + (h - 1) * 6][25 - i - 6] = 0; map[1 + (h - 1) * 6][25 - i - 6] = 0; map[5 + (h + 1) * 6][25 - i - 6] = 0; map[4 + (h + 1) * 6][25 - i - 6] = 0; map[3 + (h + 1) * 6][25 - i - 6] = 0; map[1 + (h + 1) * 6][25 - i - 6] = 0; delay(); mapping2(); break;
		case 6:
			map[5 + (h - 1) * 6][3] = 2; map[5 + (h + 1) * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 7] = 1; map[4 + (h - 1) * 6][25 - i - 7] = 1; map[3 + (h - 1) * 6][25 - i - 7] = 1; map[1 + (h - 1) * 6][25 - i - 7] = 1; map[5 + (h + 1) * 6][25 - i - 7] = 1; map[4 + (h + 1) * 6][25 - i - 7] = 1; map[3 + (h + 1) * 6][25 - i - 7] = 1; map[1 + (h + 1) * 6][25 - i - 7] = 1; mapping2();
			map[5 + (h - 1) * 6][25 - i - 7] = 0; map[4 + (h - 1) * 6][25 - i - 7] = 0; map[3 + (h - 1) * 6][25 - i - 7] = 0; map[1 + (h - 1) * 6][25 - i - 7] = 0; map[5 + (h + 1) * 6][25 - i - 7] = 0; map[4 + (h + 1) * 6][25 - i - 7] = 0; map[3 + (h + 1) * 6][25 - i - 7] = 0; map[1 + (h + 1) * 6][25 - i - 7] = 0; delay(); mapping2(); break;
		}
		step++;
		step = step % 7;
	}
}
void jump1_3_13_1(int i, int h) { // �ٲ��ٷ��� ��ֹ��� ���� �ٲ������.
	static int step = 0;
	int j = 0;
	for (j = 0; j<7; j++) {
		switch (step) {
		case 0:
			map[5 + (h - 1) * 6][3] = 2; map[5 + (h + 1) * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 1] = 1; map[4 + (h - 1) * 6][25 - i - 1] = 1; map[3 + (h - 1) * 6][25 - i - 1] = 1; map[1 + (h - 1) * 6][25 - i - 1] = 1; map[5 + (h + 1) * 6][25 - i - 1] = 1; map[4 + (h + 1) * 6][25 - i - 1] = 1; map[3 + (h + 1) * 6][25 - i - 1] = 1; map[1 + (h + 1) * 6][25 - i - 1] = 1; mapping2();
			map[5 + (h - 1) * 6][3] = 0; map[5 + (h + 1) * 6][3] = 0; map[5 + (h - 1) * 6][25 - i - 1] = 0; map[4 + (h - 1) * 6][25 - i - 1] = 0; map[3 + (h - 1) * 6][25 - i - 1] = 0; map[1 + (h - 1) * 6][25 - i - 1] = 0; map[5 + (h + 1) * 6][25 - i - 1] = 0; map[4 + (h + 1) * 6][25 - i - 1] = 0; map[3 + (h + 1) * 6][25 - i - 1] = 0; map[1 + (h + 1) * 6][25 - i - 1] = 0; delay(); mapping2(); break;
		case 1:
			map[4 + (h - 1) * 6][3] = 2; map[5 + (h + 1) * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 2] = 1; map[4 + (h - 1) * 6][25 - i - 2] = 1; map[3 + (h - 1) * 6][25 - i - 2] = 1; map[1 + (h - 1) * 6][25 - i - 2] = 1; map[5 + (h + 1) * 6][25 - i - 2] = 1; map[4 + (h + 1) * 6][25 - i - 2] = 1; map[3 + (h + 1) * 6][25 - i - 2] = 1; map[1 + (h + 1) * 6][25 - i - 2] = 1; mapping2();
			map[4 + (h - 1) * 6][3] = 0; map[5 + (h + 1) * 6][3] = 0; map[5 + (h - 1) * 6][25 - i - 2] = 0; map[4 + (h - 1) * 6][25 - i - 2] = 0; map[3 + (h - 1) * 6][25 - i - 2] = 0; map[1 + (h - 1) * 6][25 - i - 2] = 0; map[5 + (h + 1) * 6][25 - i - 2] = 0; map[4 + (h + 1) * 6][25 - i - 2] = 0; map[3 + (h + 1) * 6][25 - i - 2] = 0; map[1 + (h + 1) * 6][25 - i - 2] = 0; delay(); mapping2(); break;
		case 2:
			map[3 + (h - 1) * 6][3] = 2; map[5 + (h + 1) * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 3] = 1; map[4 + (h - 1) * 6][25 - i - 3] = 1; map[3 + (h - 1) * 6][25 - i - 3] = 1; map[1 + (h - 1) * 6][25 - i - 3] = 1; map[5 + (h + 1) * 6][25 - i - 3] = 1; map[4 + (h + 1) * 6][25 - i - 3] = 1; map[3 + (h + 1) * 6][25 - i - 3] = 1; map[1 + (h + 1) * 6][25 - i - 3] = 1; mapping2();
			map[3 + (h - 1) * 6][3] = 0; map[5 + (h + 1) * 6][3] = 0; map[5 + (h - 1) * 6][25 - i - 3] = 0; map[4 + (h - 1) * 6][25 - i - 3] = 0; map[3 + (h - 1) * 6][25 - i - 3] = 0; map[1 + (h - 1) * 6][25 - i - 3] = 0; map[5 + (h + 1) * 6][25 - i - 3] = 0; map[4 + (h + 1) * 6][25 - i - 3] = 0; map[3 + (h + 1) * 6][25 - i - 3] = 0; map[1 + (h + 1) * 6][25 - i - 3] = 0; delay(); mapping2(); break;
		case 3:
			map[2 + (h - 1) * 6][3] = 2; map[5 + (h + 1) * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 4] = 1; map[4 + (h - 1) * 6][25 - i - 4] = 1; map[3 + (h - 1) * 6][25 - i - 4] = 1; map[1 + (h - 1) * 6][25 - i - 4] = 1; map[5 + (h + 1) * 6][25 - i - 4] = 1; map[4 + (h + 1) * 6][25 - i - 4] = 1; map[3 + (h + 1) * 6][25 - i - 4] = 1; map[1 + (h + 1) * 6][25 - i - 4] = 1; mapping2();
			map[2 + (h - 1) * 6][3] = 0; map[5 + (h + 1) * 6][3] = 0; map[5 + (h - 1) * 6][25 - i - 4] = 0; map[4 + (h - 1) * 6][25 - i - 4] = 0; map[3 + (h - 1) * 6][25 - i - 4] = 0; map[1 + (h - 1) * 6][25 - i - 4] = 0; map[5 + (h + 1) * 6][25 - i - 4] = 0; map[4 + (h + 1) * 6][25 - i - 4] = 0; map[3 + (h + 1) * 6][25 - i - 4] = 0; map[1 + (h + 1) * 6][25 - i - 4] = 0; delay(); mapping2(); break;
		case 4:
			map[3 + (h - 1) * 6][3] = 2; map[5 + (h + 1) * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 5] = 1; map[4 + (h - 1) * 6][25 - i - 5] = 1; map[3 + (h - 1) * 6][25 - i - 5] = 1; map[1 + (h - 1) * 6][25 - i - 5] = 1; map[5 + (h + 1) * 6][25 - i - 5] = 1; map[4 + (h + 1) * 6][25 - i - 5] = 1; map[3 + (h + 1) * 6][25 - i - 5] = 1; map[1 + (h + 1) * 6][25 - i - 5] = 1; mapping2();
			map[3 + (h - 1) * 6][3] = 0; map[5 + (h + 1) * 6][3] = 0; map[5 + (h - 1) * 6][25 - i - 5] = 0; map[4 + (h - 1) * 6][25 - i - 5] = 0; map[3 + (h - 1) * 6][25 - i - 5] = 0; map[1 + (h - 1) * 6][25 - i - 5] = 0; map[5 + (h + 1) * 6][25 - i - 5] = 0; map[4 + (h + 1) * 6][25 - i - 5] = 0; map[3 + (h + 1) * 6][25 - i - 5] = 0; map[1 + (h + 1) * 6][25 - i - 5] = 0; delay(); mapping2(); break;
		case 5:
			map[4 + (h - 1) * 6][3] = 2; map[5 + (h + 1) * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 6] = 1; map[4 + (h - 1) * 6][25 - i - 6] = 1; map[3 + (h - 1) * 6][25 - i - 6] = 1; map[1 + (h - 1) * 6][25 - i - 6] = 1; map[5 + (h + 1) * 6][25 - i - 6] = 1; map[4 + (h + 1) * 6][25 - i - 6] = 1; map[3 + (h + 1) * 6][25 - i - 6] = 1; map[1 + (h + 1) * 6][25 - i - 6] = 1; mapping2();
			map[4 + (h - 1) * 6][3] = 0; map[5 + (h + 1) * 6][3] = 0; map[5 + (h - 1) * 6][25 - i - 6] = 0; map[4 + (h - 1) * 6][25 - i - 6] = 0; map[3 + (h - 1) * 6][25 - i - 6] = 0; map[1 + (h - 1) * 6][25 - i - 6] = 0; map[5 + (h + 1) * 6][25 - i - 6] = 0; map[4 + (h + 1) * 6][25 - i - 6] = 0; map[3 + (h + 1) * 6][25 - i - 6] = 0; map[1 + (h + 1) * 6][25 - i - 6] = 0; delay(); mapping2(); break;
		case 6:
			map[5 + (h - 1) * 6][3] = 2; map[5 + (h + 1) * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 7] = 1; map[4 + (h - 1) * 6][25 - i - 7] = 1; map[3 + (h - 1) * 6][25 - i - 7] = 1; map[1 + (h - 1) * 6][25 - i - 7] = 1; map[5 + (h + 1) * 6][25 - i - 7] = 1; map[4 + (h + 1) * 6][25 - i - 7] = 1; map[3 + (h + 1) * 6][25 - i - 7] = 1; map[1 + (h + 1) * 6][25 - i - 7] = 1; mapping2();
			map[5 + (h - 1) * 6][25 - i - 7] = 0; map[4 + (h - 1) * 6][25 - i - 7] = 0; map[3 + (h - 1) * 6][25 - i - 7] = 0; map[1 + (h - 1) * 6][25 - i - 7] = 0; map[5 + (h + 1) * 6][25 - i - 7] = 0; map[4 + (h + 1) * 6][25 - i - 7] = 0; map[3 + (h + 1) * 6][25 - i - 7] = 0; map[1 + (h + 1) * 6][25 - i - 7] = 0; delay(); mapping2(); break;
		}
		step++;
		step = step % 7;
	}
}
void jump1_3_13_2(int i, int h) { // �ٲ��ٷ��� ��ֹ��� ���� �ٲ������.
	static int step = 0;
	int j = 0;
	for (j = 0; j<7; j++) {
		switch (step) {
		case 0:
			map[5 + (h - 1) * 6][3] = 2; map[5 + (h + 1) * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 1] = 1; map[4 + (h - 1) * 6][25 - i - 1] = 1; map[3 + (h - 1) * 6][25 - i - 1] = 1; map[1 + (h - 1) * 6][25 - i - 1] = 1; map[5 + (h + 1) * 6][25 - i - 1] = 1; map[4 + (h + 1) * 6][25 - i - 1] = 1; map[3 + (h + 1) * 6][25 - i - 1] = 1; map[1 + (h + 1) * 6][25 - i - 1] = 1; mapping2();
			map[5 + (h - 1) * 6][3] = 0; map[5 + (h + 1) * 6][3] = 0; map[5 + (h - 1) * 6][25 - i - 1] = 0; map[4 + (h - 1) * 6][25 - i - 1] = 0; map[3 + (h - 1) * 6][25 - i - 1] = 0; map[1 + (h - 1) * 6][25 - i - 1] = 0; map[5 + (h + 1) * 6][25 - i - 1] = 0; map[4 + (h + 1) * 6][25 - i - 1] = 0; map[3 + (h + 1) * 6][25 - i - 1] = 0; map[1 + (h + 1) * 6][25 - i - 1] = 0; delay(); mapping2(); break;
		case 1:
			map[5 + (h - 1) * 6][3] = 2; map[4 + (h + 1) * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 2] = 1; map[4 + (h - 1) * 6][25 - i - 2] = 1; map[3 + (h - 1) * 6][25 - i - 2] = 1; map[1 + (h - 1) * 6][25 - i - 2] = 1; map[5 + (h + 1) * 6][25 - i - 2] = 1; map[4 + (h + 1) * 6][25 - i - 2] = 1; map[3 + (h + 1) * 6][25 - i - 2] = 1; map[1 + (h + 1) * 6][25 - i - 2] = 1; mapping2();
			map[5 + (h - 1) * 6][3] = 0; map[4 + (h + 1) * 6][3] = 0; map[5 + (h - 1) * 6][25 - i - 2] = 0; map[4 + (h - 1) * 6][25 - i - 2] = 0; map[3 + (h - 1) * 6][25 - i - 2] = 0; map[1 + (h - 1) * 6][25 - i - 2] = 0; map[5 + (h + 1) * 6][25 - i - 2] = 0; map[4 + (h + 1) * 6][25 - i - 2] = 0; map[3 + (h + 1) * 6][25 - i - 2] = 0; map[1 + (h + 1) * 6][25 - i - 2] = 0; delay(); mapping2(); break;
		case 2:
			map[5 + (h - 1) * 6][3] = 2; map[3 + (h + 1) * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 3] = 1; map[4 + (h - 1) * 6][25 - i - 3] = 1; map[3 + (h - 1) * 6][25 - i - 3] = 1; map[1 + (h - 1) * 6][25 - i - 3] = 1; map[5 + (h + 1) * 6][25 - i - 3] = 1; map[4 + (h + 1) * 6][25 - i - 3] = 1; map[3 + (h + 1) * 6][25 - i - 3] = 1; map[1 + (h + 1) * 6][25 - i - 3] = 1; mapping2();
			map[5 + (h - 1) * 6][3] = 0; map[3 + (h + 1) * 6][3] = 0; map[5 + (h - 1) * 6][25 - i - 3] = 0; map[4 + (h - 1) * 6][25 - i - 3] = 0; map[3 + (h - 1) * 6][25 - i - 3] = 0; map[1 + (h - 1) * 6][25 - i - 3] = 0; map[5 + (h + 1) * 6][25 - i - 3] = 0; map[4 + (h + 1) * 6][25 - i - 3] = 0; map[3 + (h + 1) * 6][25 - i - 3] = 0; map[1 + (h + 1) * 6][25 - i - 3] = 0; delay(); mapping2(); break;
		case 3:
			map[5 + (h - 1) * 6][3] = 2; map[2 + (h + 1) * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 4] = 1; map[4 + (h - 1) * 6][25 - i - 4] = 1; map[3 + (h - 1) * 6][25 - i - 4] = 1; map[1 + (h - 1) * 6][25 - i - 4] = 1; map[5 + (h + 1) * 6][25 - i - 4] = 1; map[4 + (h + 1) * 6][25 - i - 4] = 1; map[3 + (h + 1) * 6][25 - i - 4] = 1; map[1 + (h + 1) * 6][25 - i - 4] = 1; mapping2();
			map[5 + (h - 1) * 6][3] = 0; map[2 + (h + 1) * 6][3] = 0; map[5 + (h - 1) * 6][25 - i - 4] = 0; map[4 + (h - 1) * 6][25 - i - 4] = 0; map[3 + (h - 1) * 6][25 - i - 4] = 0; map[1 + (h - 1) * 6][25 - i - 4] = 0; map[5 + (h + 1) * 6][25 - i - 4] = 0; map[4 + (h + 1) * 6][25 - i - 4] = 0; map[3 + (h + 1) * 6][25 - i - 4] = 0; map[1 + (h + 1) * 6][25 - i - 4] = 0; delay(); mapping2(); break;
		case 4:
			map[5 + (h - 1) * 6][3] = 2; map[3 + (h + 1) * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 5] = 1; map[4 + (h - 1) * 6][25 - i - 5] = 1; map[3 + (h - 1) * 6][25 - i - 5] = 1; map[1 + (h - 1) * 6][25 - i - 5] = 1; map[5 + (h + 1) * 6][25 - i - 5] = 1; map[4 + (h + 1) * 6][25 - i - 5] = 1; map[3 + (h + 1) * 6][25 - i - 5] = 1; map[1 + (h + 1) * 6][25 - i - 5] = 1; mapping2();
			map[5 + (h - 1) * 6][3] = 0; map[3 + (h + 1) * 6][3] = 0; map[5 + (h - 1) * 6][25 - i - 5] = 0; map[4 + (h - 1) * 6][25 - i - 5] = 0; map[3 + (h - 1) * 6][25 - i - 5] = 0; map[1 + (h - 1) * 6][25 - i - 5] = 0; map[5 + (h + 1) * 6][25 - i - 5] = 0; map[4 + (h + 1) * 6][25 - i - 5] = 0; map[3 + (h + 1) * 6][25 - i - 5] = 0; map[1 + (h + 1) * 6][25 - i - 5] = 0; delay(); mapping2(); break;
		case 5:
			map[5 + (h - 1) * 6][3] = 2; map[4 + (h + 1) * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 6] = 1; map[4 + (h - 1) * 6][25 - i - 6] = 1; map[3 + (h - 1) * 6][25 - i - 6] = 1; map[1 + (h - 1) * 6][25 - i - 6] = 1; map[5 + (h + 1) * 6][25 - i - 6] = 1; map[4 + (h + 1) * 6][25 - i - 6] = 1; map[3 + (h + 1) * 6][25 - i - 6] = 1; map[1 + (h + 1) * 6][25 - i - 6] = 1; mapping2();
			map[5 + (h - 1) * 6][3] = 0; map[4 + (h + 1) * 6][3] = 0; map[5 + (h - 1) * 6][25 - i - 6] = 0; map[4 + (h - 1) * 6][25 - i - 6] = 0; map[3 + (h - 1) * 6][25 - i - 6] = 0; map[1 + (h - 1) * 6][25 - i - 6] = 0; map[5 + (h + 1) * 6][25 - i - 6] = 0; map[4 + (h + 1) * 6][25 - i - 6] = 0; map[3 + (h + 1) * 6][25 - i - 6] = 0; map[1 + (h + 1) * 6][25 - i - 6] = 0; delay(); mapping2(); break;
		case 6:
			map[5 + (h - 1) * 6][3] = 2; map[5 + (h + 1) * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 7] = 1; map[4 + (h - 1) * 6][25 - i - 7] = 1; map[3 + (h - 1) * 6][25 - i - 7] = 1; map[1 + (h - 1) * 6][25 - i - 7] = 1; map[5 + (h + 1) * 6][25 - i - 7] = 1; map[4 + (h + 1) * 6][25 - i - 7] = 1; map[3 + (h + 1) * 6][25 - i - 7] = 1; map[1 + (h + 1) * 6][25 - i - 7] = 1; mapping2();
			map[5 + (h - 1) * 6][25 - i - 7] = 0; map[4 + (h - 1) * 6][25 - i - 7] = 0; map[3 + (h - 1) * 6][25 - i - 7] = 0; map[1 + (h - 1) * 6][25 - i - 7] = 0; map[5 + (h + 1) * 6][25 - i - 7] = 0; map[4 + (h + 1) * 6][25 - i - 7] = 0; map[3 + (h + 1) * 6][25 - i - 7] = 0; map[1 + (h + 1) * 6][25 - i - 7] = 0; delay(); mapping2(); break;
		}
		step++;
		step = step % 7;
	}
}

void jump3_1(int i, int h) { // �ٲ��ٷ��� ��ֹ��� ���� �ٲ������.
	static int step = 0;
	int j = 0;
	for (j = 0; j<7; j++) {
		switch (step) {
		case 0:
			map[5 + (h - 1) * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 1] = 1; map[3 + (h - 1) * 6][25 - i - 1] = 1; map[2 + (h - 1) * 6][25 - i - 1] = 1; map[1 + (h - 1) * 6][25 - i - 1] = 1; mapping2();
			map[5 + (h - 1) * 6][3] = 0; map[5 + (h - 1) * 6][25 - i - 1] = 0; map[3 + (h - 1) * 6][25 - i - 1] = 0; map[2 + (h - 1) * 6][25 - i - 1] = 0; map[1 + (h - 1) * 6][25 - i - 1] = 0; delay(); mapping2(); break;
		case 1:
			map[4 + (h - 1) * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 2] = 1; map[3 + (h - 1) * 6][25 - i - 2] = 1; map[2 + (h - 1) * 6][25 - i - 2] = 1; map[1 + (h - 1) * 6][25 - i - 2] = 1; mapping2();
			map[4 + (h - 1) * 6][3] = 0; map[5 + (h - 1) * 6][25 - i - 2] = 0; map[3 + (h - 1) * 6][25 - i - 2] = 0; map[2 + (h - 1) * 6][25 - i - 2] = 0; map[1 + (h - 1) * 6][25 - i - 2] = 0; delay(); mapping2(); break;
		case 2:
			map[3 + (h - 1) * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 3] = 1; map[3 + (h - 1) * 6][25 - i - 3] = 1; map[2 + (h - 1) * 6][25 - i - 3] = 1; map[1 + (h - 1) * 6][25 - i - 3] = 1; mapping2();
			map[3 + (h - 1) * 6][3] = 0; map[5 + (h - 1) * 6][25 - i - 3] = 0; map[3 + (h - 1) * 6][25 - i - 3] = 0; map[2 + (h - 1) * 6][25 - i - 3] = 0; map[1 + (h - 1) * 6][25 - i - 3] = 0; delay(); mapping2(); break;
		case 3:
			map[2 + (h - 1) * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 4] = 1; map[3 + (h - 1) * 6][25 - i - 4] = 1; map[2 + (h - 1) * 6][25 - i - 4] = 1; map[1 + (h - 1) * 6][25 - i - 4] = 1; mapping2();
			map[2 + (h - 1) * 6][3] = 0; map[5 + (h - 1) * 6][25 - i - 4] = 0; map[3 + (h - 1) * 6][25 - i - 4] = 0; map[2 + (h - 1) * 6][25 - i - 4] = 0; map[1 + (h - 1) * 6][25 - i - 4] = 0; delay(); mapping2(); break;
		case 4:
			map[3 + (h - 1) * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 5] = 1; map[3 + (h - 1) * 6][25 - i - 5] = 1; map[2 + (h - 1) * 6][25 - i - 5] = 1; map[1 + (h - 1) * 6][25 - i - 5] = 1; mapping2();
			map[3 + (h - 1) * 6][3] = 0; map[5 + (h - 1) * 6][25 - i - 5] = 0; map[3 + (h - 1) * 6][25 - i - 5] = 0; map[2 + (h - 1) * 6][25 - i - 5] = 0; map[1 + (h - 1) * 6][25 - i - 5] = 0; delay(); mapping2(); break;
		case 5:
			map[4 + (h - 1) * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 6] = 1; map[3 + (h - 1) * 6][25 - i - 6] = 1; map[2 + (h - 1) * 6][25 - i - 6] = 1; map[1 + (h - 1) * 6][25 - i - 6] = 1; mapping2();
			map[4 + (h - 1) * 6][3] = 0; map[5 + (h - 1) * 6][25 - i - 6] = 0; map[3 + (h - 1) * 6][25 - i - 6] = 0; map[2 + (h - 1) * 6][25 - i - 6] = 0; map[1 + (h - 1) * 6][25 - i - 6] = 0; delay(); mapping2(); break;
		case 6:
			map[5 + (h - 1) * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 7] = 1; map[3 + (h - 1) * 6][25 - i - 7] = 1; map[2 + (h - 1) * 6][25 - i - 7] = 1; map[1 + (h - 1) * 6][25 - i - 7] = 1; mapping2();
			map[5 + (h - 1) * 6][25 - i - 7] = 0; map[5 + (h - 1) * 6][25 - i - 7] = 0; map[3 + (h - 1) * 6][25 - i - 7] = 0; map[2 + (h - 1) * 6][25 - i - 7] = 0; map[1 + (h - 1) * 6][25 - i - 7] = 0; delay(); mapping2(); break;
		}
		step++;
		step = step % 7;
	}
}
void jump3_1_12(int i, int h) { // �ٲ��ٷ��� ��ֹ��� ���� �ٲ������.
	static int step = 0;
	int j = 0;
	for (j = 0; j<7; j++) {
		switch (step) {
		case 0:
			map[5 + (h - 1) * 6][3] = 2; map[5 + h * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 1] = 1; map[3 + (h - 1) * 6][25 - i - 1] = 1; map[2 + (h - 1) * 6][25 - i - 1] = 1; map[1 + (h - 1) * 6][25 - i - 1] = 1;  map[5 + h * 6][25 - i - 1] = 1; map[3 + h * 6][25 - i - 1] = 1; map[2 + h * 6][25 - i - 1] = 1; map[1 + h * 6][25 - i - 1] = 1; mapping2();
			map[5 + (h - 1) * 6][3] = 0; map[5 + h * 6][3] = 0; map[5 + (h - 1) * 6][25 - i - 1] = 0; map[3 + (h - 1) * 6][25 - i - 1] = 0; map[2 + (h - 1) * 6][25 - i - 1] = 0; map[1 + (h - 1) * 6][25 - i - 1] = 0;  map[5 + h * 6][25 - i - 1] = 0; map[3 + h * 6][25 - i - 1] = 0; map[2 + h * 6][25 - i - 1] = 0; map[1 + h * 6][25 - i - 1] = 0; delay(); mapping2(); break;
		case 1:
			map[4 + (h - 1) * 6][3] = 2; map[4 + h * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 2] = 1; map[3 + (h - 1) * 6][25 - i - 2] = 1; map[2 + (h - 1) * 6][25 - i - 2] = 1; map[1 + (h - 1) * 6][25 - i - 2] = 1;  map[5 + h * 6][25 - i - 2] = 1; map[3 + h * 6][25 - i - 2] = 1; map[2 + h * 6][25 - i - 2] = 1; map[1 + h * 6][25 - i - 2] = 1; mapping2();
			map[4 + (h - 1) * 6][3] = 0; map[4 + h * 6][3] = 0; map[5 + (h - 1) * 6][25 - i - 2] = 0; map[3 + (h - 1) * 6][25 - i - 2] = 0; map[2 + (h - 1) * 6][25 - i - 2] = 0; map[1 + (h - 1) * 6][25 - i - 2] = 0;  map[5 + h * 6][25 - i - 2] = 0; map[3 + h * 6][25 - i - 2] = 0; map[2 + h * 6][25 - i - 2] = 0; map[1 + h * 6][25 - i - 2] = 0; delay(); mapping2(); break;
		case 2:
			map[3 + (h - 1) * 6][3] = 2; map[3 + h * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 3] = 1; map[3 + (h - 1) * 6][25 - i - 3] = 1; map[2 + (h - 1) * 6][25 - i - 3] = 1; map[1 + (h - 1) * 6][25 - i - 3] = 1;  map[5 + h * 6][25 - i - 3] = 1; map[3 + h * 6][25 - i - 3] = 1; map[2 + h * 6][25 - i - 3] = 1; map[1 + h * 6][25 - i - 3] = 1; mapping2();
			map[3 + (h - 1) * 6][3] = 0; map[3 + h * 6][3] = 0; map[5 + (h - 1) * 6][25 - i - 3] = 0; map[3 + (h - 1) * 6][25 - i - 3] = 0; map[2 + (h - 1) * 6][25 - i - 3] = 0; map[1 + (h - 1) * 6][25 - i - 3] = 0;  map[5 + h * 6][25 - i - 3] = 0; map[3 + h * 6][25 - i - 3] = 0; map[2 + h * 6][25 - i - 3] = 0; map[1 + h * 6][25 - i - 3] = 0; delay(); mapping2(); break;
		case 3:
			map[2 + (h - 1) * 6][3] = 2; map[2 + h * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 4] = 1; map[3 + (h - 1) * 6][25 - i - 4] = 1; map[2 + (h - 1) * 6][25 - i - 4] = 1; map[1 + (h - 1) * 6][25 - i - 4] = 1;  map[5 + h * 6][25 - i - 4] = 1; map[3 + h * 6][25 - i - 4] = 1; map[2 + h * 6][25 - i - 4] = 1; map[1 + h * 6][25 - i - 4] = 1; mapping2();
			map[2 + (h - 1) * 6][3] = 0; map[2 + h * 6][3] = 0; map[5 + (h - 1) * 6][25 - i - 4] = 0; map[3 + (h - 1) * 6][25 - i - 4] = 0; map[2 + (h - 1) * 6][25 - i - 4] = 0; map[1 + (h - 1) * 6][25 - i - 4] = 0;  map[5 + h * 6][25 - i - 4] = 0; map[3 + h * 6][25 - i - 4] = 0; map[2 + h * 6][25 - i - 4] = 0; map[1 + h * 6][25 - i - 4] = 0; delay(); mapping2(); break;
		case 4:
			map[3 + (h - 1) * 6][3] = 2; map[3 + h * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 5] = 1; map[3 + (h - 1) * 6][25 - i - 5] = 1; map[2 + (h - 1) * 6][25 - i - 5] = 1; map[1 + (h - 1) * 6][25 - i - 5] = 1;  map[5 + h * 6][25 - i - 5] = 1; map[3 + h * 6][25 - i - 5] = 1; map[2 + h * 6][25 - i - 5] = 1; map[1 + h * 6][25 - i - 5] = 1; mapping2();
			map[3 + (h - 1) * 6][3] = 0; map[3 + h * 6][3] = 0; map[5 + (h - 1) * 6][25 - i - 5] = 0; map[3 + (h - 1) * 6][25 - i - 5] = 0; map[2 + (h - 1) * 6][25 - i - 5] = 0; map[1 + (h - 1) * 6][25 - i - 5] = 0;  map[5 + h * 6][25 - i - 5] = 0; map[3 + h * 6][25 - i - 5] = 0; map[2 + h * 6][25 - i - 5] = 0; map[1 + h * 6][25 - i - 5] = 0; delay(); mapping2(); break;
		case 5:
			map[4 + (h - 1) * 6][3] = 2; map[4 + h * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 6] = 1; map[3 + (h - 1) * 6][25 - i - 6] = 1; map[2 + (h - 1) * 6][25 - i - 6] = 1; map[1 + (h - 1) * 6][25 - i - 6] = 1;  map[5 + h * 6][25 - i - 6] = 1; map[3 + h * 6][25 - i - 6] = 1; map[2 + h * 6][25 - i - 6] = 1; map[1 + h * 6][25 - i - 6] = 1; mapping2();
			map[4 + (h - 1) * 6][3] = 0; map[4 + h * 6][3] = 0; map[5 + (h - 1) * 6][25 - i - 6] = 0; map[3 + (h - 1) * 6][25 - i - 6] = 0; map[2 + (h - 1) * 6][25 - i - 6] = 0; map[1 + (h - 1) * 6][25 - i - 6] = 0;  map[5 + h * 6][25 - i - 6] = 0; map[3 + h * 6][25 - i - 6] = 0; map[2 + h * 6][25 - i - 6] = 0; map[1 + h * 6][25 - i - 6] = 0; delay(); mapping2(); break;
		case 6:
			map[5 + (h - 1) * 6][3] = 2; map[5 + h * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 7] = 1; map[3 + (h - 1) * 6][25 - i - 7] = 1; map[2 + (h - 1) * 6][25 - i - 7] = 1; map[1 + (h - 1) * 6][25 - i - 7] = 1;  map[5 + h * 6][25 - i - 7] = 1; map[3 + h * 6][25 - i - 7] = 1; map[2 + h * 6][25 - i - 7] = 1; map[1 + h * 6][25 - i - 7] = 1; mapping2();
			map[5 + (h - 1) * 6][25 - i - 7] = 0; map[3 + (h - 1) * 6][25 - i - 7] = 0; map[2 + (h - 1) * 6][25 - i - 7] = 0; map[1 + (h - 1) * 6][25 - i - 7] = 0;  map[5 + h * 6][25 - i - 7] = 0; map[3 + h * 6][25 - i - 7] = 0; map[2 + h * 6][25 - i - 7] = 0; map[1 + h * 6][25 - i - 7] = 0; delay(); mapping2(); break;
		}
		step++;
		step = step % 7;
	}
}
void jump3_1_12_1(int i, int h) { // �ٲ��ٷ��� ��ֹ��� ���� �ٲ������.
	static int step = 0;
	int j = 0;
	for (j = 0; j<7; j++) {
		switch (step) {
		case 0:
			map[5 + (h - 1) * 6][3] = 2; map[5 + h * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 1] = 1; map[3 + (h - 1) * 6][25 - i - 1] = 1; map[2 + (h - 1) * 6][25 - i - 1] = 1; map[1 + (h - 1) * 6][25 - i - 1] = 1;  map[5 + h * 6][25 - i - 1] = 1; map[3 + h * 6][25 - i - 1] = 1; map[2 + h * 6][25 - i - 1] = 1; map[1 + h * 6][25 - i - 1] = 1; mapping2();
			map[5 + (h - 1) * 6][3] = 0; map[5 + h * 6][3] = 0; map[5 + (h - 1) * 6][25 - i - 1] = 0; map[3 + (h - 1) * 6][25 - i - 1] = 0; map[2 + (h - 1) * 6][25 - i - 1] = 0; map[1 + (h - 1) * 6][25 - i - 1] = 0;  map[5 + h * 6][25 - i - 1] = 0; map[3 + h * 6][25 - i - 1] = 0; map[2 + h * 6][25 - i - 1] = 0; map[1 + h * 6][25 - i - 1] = 0; delay(); mapping2(); break;
		case 1:
			map[4 + (h - 1) * 6][3] = 2; map[5 + h * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 2] = 1; map[3 + (h - 1) * 6][25 - i - 2] = 1; map[2 + (h - 1) * 6][25 - i - 2] = 1; map[1 + (h - 1) * 6][25 - i - 2] = 1;  map[5 + h * 6][25 - i - 2] = 1; map[3 + h * 6][25 - i - 2] = 1; map[2 + h * 6][25 - i - 2] = 1; map[1 + h * 6][25 - i - 2] = 1; mapping2();
			map[4 + (h - 1) * 6][3] = 0; map[5 + h * 6][3] = 0; map[5 + (h - 1) * 6][25 - i - 2] = 0; map[3 + (h - 1) * 6][25 - i - 2] = 0; map[2 + (h - 1) * 6][25 - i - 2] = 0; map[1 + (h - 1) * 6][25 - i - 2] = 0;  map[5 + h * 6][25 - i - 2] = 0; map[3 + h * 6][25 - i - 2] = 0; map[2 + h * 6][25 - i - 2] = 0; map[1 + h * 6][25 - i - 2] = 0; delay(); mapping2(); break;
		case 2:
			map[3 + (h - 1) * 6][3] = 2; map[5 + h * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 3] = 1; map[3 + (h - 1) * 6][25 - i - 3] = 1; map[2 + (h - 1) * 6][25 - i - 3] = 1; map[1 + (h - 1) * 6][25 - i - 3] = 1;  map[5 + h * 6][25 - i - 3] = 1; map[3 + h * 6][25 - i - 3] = 1; map[2 + h * 6][25 - i - 3] = 1; map[1 + h * 6][25 - i - 3] = 1; mapping2();
			map[3 + (h - 1) * 6][3] = 0; map[5 + h * 6][3] = 0; map[5 + (h - 1) * 6][25 - i - 3] = 0; map[3 + (h - 1) * 6][25 - i - 3] = 0; map[2 + (h - 1) * 6][25 - i - 3] = 0; map[1 + (h - 1) * 6][25 - i - 3] = 0;  map[5 + h * 6][25 - i - 3] = 0; map[3 + h * 6][25 - i - 3] = 0; map[2 + h * 6][25 - i - 3] = 0; map[1 + h * 6][25 - i - 3] = 0; delay(); mapping2(); break;
		case 3:
			map[2 + (h - 1) * 6][3] = 2; map[5 + h * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 4] = 1; map[3 + (h - 1) * 6][25 - i - 4] = 1; map[2 + (h - 1) * 6][25 - i - 4] = 1; map[1 + (h - 1) * 6][25 - i - 4] = 1;  map[5 + h * 6][25 - i - 4] = 1; map[3 + h * 6][25 - i - 4] = 1; map[2 + h * 6][25 - i - 4] = 1; map[1 + h * 6][25 - i - 4] = 1; mapping2();
			map[2 + (h - 1) * 6][3] = 0; map[5 + h * 6][3] = 0; map[5 + (h - 1) * 6][25 - i - 4] = 0; map[3 + (h - 1) * 6][25 - i - 4] = 0; map[2 + (h - 1) * 6][25 - i - 4] = 0; map[1 + (h - 1) * 6][25 - i - 4] = 0;  map[5 + h * 6][25 - i - 4] = 0; map[3 + h * 6][25 - i - 4] = 0; map[2 + h * 6][25 - i - 4] = 0; map[1 + h * 6][25 - i - 4] = 0; delay(); mapping2(); break;
		case 4:
			map[3 + (h - 1) * 6][3] = 2; map[5 + h * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 5] = 1; map[3 + (h - 1) * 6][25 - i - 5] = 1; map[2 + (h - 1) * 6][25 - i - 5] = 1; map[1 + (h - 1) * 6][25 - i - 5] = 1;  map[5 + h * 6][25 - i - 5] = 1; map[3 + h * 6][25 - i - 5] = 1; map[2 + h * 6][25 - i - 5] = 1; map[1 + h * 6][25 - i - 5] = 1; mapping2();
			map[3 + (h - 1) * 6][3] = 0; map[5 + h * 6][3] = 0; map[5 + (h - 1) * 6][25 - i - 5] = 0; map[3 + (h - 1) * 6][25 - i - 5] = 0; map[2 + (h - 1) * 6][25 - i - 5] = 0; map[1 + (h - 1) * 6][25 - i - 5] = 0;  map[5 + h * 6][25 - i - 5] = 0; map[3 + h * 6][25 - i - 5] = 0; map[2 + h * 6][25 - i - 5] = 0; map[1 + h * 6][25 - i - 5] = 0; delay(); mapping2(); break;
		case 5:
			map[4 + (h - 1) * 6][3] = 2; map[5 + h * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 6] = 1; map[3 + (h - 1) * 6][25 - i - 6] = 1; map[2 + (h - 1) * 6][25 - i - 6] = 1; map[1 + (h - 1) * 6][25 - i - 6] = 1;  map[5 + h * 6][25 - i - 6] = 1; map[3 + h * 6][25 - i - 6] = 1; map[2 + h * 6][25 - i - 6] = 1; map[1 + h * 6][25 - i - 6] = 1; mapping2();
			map[4 + (h - 1) * 6][3] = 0; map[5 + h * 6][3] = 0; map[5 + (h - 1) * 6][25 - i - 6] = 0; map[3 + (h - 1) * 6][25 - i - 6] = 0; map[2 + (h - 1) * 6][25 - i - 6] = 0; map[1 + (h - 1) * 6][25 - i - 6] = 0;  map[5 + h * 6][25 - i - 6] = 0; map[3 + h * 6][25 - i - 6] = 0; map[2 + h * 6][25 - i - 6] = 0; map[1 + h * 6][25 - i - 6] = 0; delay(); mapping2(); break;
		case 6:
			map[5 + (h - 1) * 6][3] = 2; map[5 + h * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 7] = 1; map[3 + (h - 1) * 6][25 - i - 7] = 1; map[2 + (h - 1) * 6][25 - i - 7] = 1; map[1 + (h - 1) * 6][25 - i - 7] = 1;  map[5 + h * 6][25 - i - 7] = 1; map[3 + h * 6][25 - i - 7] = 1; map[2 + h * 6][25 - i - 7] = 1; map[1 + h * 6][25 - i - 7] = 1; mapping2();
			map[5 + (h - 1) * 6][25 - i - 7] = 0; map[3 + (h - 1) * 6][25 - i - 7] = 0; map[2 + (h - 1) * 6][25 - i - 7] = 0; map[1 + (h - 1) * 6][25 - i - 7] = 0;  map[5 + h * 6][25 - i - 7] = 0; map[3 + h * 6][25 - i - 7] = 0; map[2 + h * 6][25 - i - 7] = 0; map[1 + h * 6][25 - i - 7] = 0; delay(); mapping2(); break;
		}
		step++;
		step = step % 7;
	}
}
void jump3_1_12_2(int i, int h) { // �ٲ��ٷ��� ��ֹ��� ���� �ٲ������.
	static int step = 0;
	int j = 0;
	for (j = 0; j<7; j++) {
		switch (step) {
		case 0:
			map[5 + (h - 1) * 6][3] = 2; map[5 + h * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 1] = 1; map[3 + (h - 1) * 6][25 - i - 1] = 1; map[2 + (h - 1) * 6][25 - i - 1] = 1; map[1 + (h - 1) * 6][25 - i - 1] = 1;  map[5 + h * 6][25 - i - 1] = 1; map[3 + h * 6][25 - i - 1] = 1; map[2 + h * 6][25 - i - 1] = 1; map[1 + h * 6][25 - i - 1] = 1; mapping2();
			map[5 + (h - 1) * 6][3] = 0; map[5 + h * 6][3] = 0; map[5 + (h - 1) * 6][25 - i - 1] = 0; map[3 + (h - 1) * 6][25 - i - 1] = 0; map[2 + (h - 1) * 6][25 - i - 1] = 0; map[1 + (h - 1) * 6][25 - i - 1] = 0;  map[5 + h * 6][25 - i - 1] = 0; map[3 + h * 6][25 - i - 1] = 0; map[2 + h * 6][25 - i - 1] = 0; map[1 + h * 6][25 - i - 1] = 0; delay(); mapping2(); break;
		case 1:
			map[5 + (h - 1) * 6][3] = 2; map[4 + h * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 2] = 1; map[3 + (h - 1) * 6][25 - i - 2] = 1; map[2 + (h - 1) * 6][25 - i - 2] = 1; map[1 + (h - 1) * 6][25 - i - 2] = 1;  map[5 + h * 6][25 - i - 2] = 1; map[3 + h * 6][25 - i - 2] = 1; map[2 + h * 6][25 - i - 2] = 1; map[1 + h * 6][25 - i - 2] = 1; mapping2();
			map[5 + (h - 1) * 6][3] = 0; map[4 + h * 6][3] = 0; map[5 + (h - 1) * 6][25 - i - 2] = 0; map[3 + (h - 1) * 6][25 - i - 2] = 0; map[2 + (h - 1) * 6][25 - i - 2] = 0; map[1 + (h - 1) * 6][25 - i - 2] = 0;  map[5 + h * 6][25 - i - 2] = 0; map[3 + h * 6][25 - i - 2] = 0; map[2 + h * 6][25 - i - 2] = 0; map[1 + h * 6][25 - i - 2] = 0; delay(); mapping2(); break;
		case 2:
			map[5 + (h - 1) * 6][3] = 2; map[3 + h * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 3] = 1; map[3 + (h - 1) * 6][25 - i - 3] = 1; map[2 + (h - 1) * 6][25 - i - 3] = 1; map[1 + (h - 1) * 6][25 - i - 3] = 1;  map[5 + h * 6][25 - i - 3] = 1; map[3 + h * 6][25 - i - 3] = 1; map[2 + h * 6][25 - i - 3] = 1; map[1 + h * 6][25 - i - 3] = 1; mapping2();
			map[5 + (h - 1) * 6][3] = 0; map[3 + h * 6][3] = 0; map[5 + (h - 1) * 6][25 - i - 3] = 0; map[3 + (h - 1) * 6][25 - i - 3] = 0; map[2 + (h - 1) * 6][25 - i - 3] = 0; map[1 + (h - 1) * 6][25 - i - 3] = 0;  map[5 + h * 6][25 - i - 3] = 0; map[3 + h * 6][25 - i - 3] = 0; map[2 + h * 6][25 - i - 3] = 0; map[1 + h * 6][25 - i - 3] = 0; delay(); mapping2(); break;
		case 3:
			map[5 + (h - 1) * 6][3] = 2; map[2 + h * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 4] = 1; map[3 + (h - 1) * 6][25 - i - 4] = 1; map[2 + (h - 1) * 6][25 - i - 4] = 1; map[1 + (h - 1) * 6][25 - i - 4] = 1;  map[5 + h * 6][25 - i - 4] = 1; map[3 + h * 6][25 - i - 4] = 1; map[2 + h * 6][25 - i - 4] = 1; map[1 + h * 6][25 - i - 4] = 1; mapping2();
			map[5 + (h - 1) * 6][3] = 0; map[2 + h * 6][3] = 0; map[5 + (h - 1) * 6][25 - i - 4] = 0; map[3 + (h - 1) * 6][25 - i - 4] = 0; map[2 + (h - 1) * 6][25 - i - 4] = 0; map[1 + (h - 1) * 6][25 - i - 4] = 0;  map[5 + h * 6][25 - i - 4] = 0; map[3 + h * 6][25 - i - 4] = 0; map[2 + h * 6][25 - i - 4] = 0; map[1 + h * 6][25 - i - 4] = 0; delay(); mapping2(); break;
		case 4:
			map[5 + (h - 1) * 6][3] = 2; map[3 + h * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 5] = 1; map[3 + (h - 1) * 6][25 - i - 5] = 1; map[2 + (h - 1) * 6][25 - i - 5] = 1; map[1 + (h - 1) * 6][25 - i - 5] = 1;  map[5 + h * 6][25 - i - 5] = 1; map[3 + h * 6][25 - i - 5] = 1; map[2 + h * 6][25 - i - 5] = 1; map[1 + h * 6][25 - i - 5] = 1; mapping2();
			map[5 + (h - 1) * 6][3] = 0; map[3 + h * 6][3] = 0; map[5 + (h - 1) * 6][25 - i - 5] = 0; map[3 + (h - 1) * 6][25 - i - 5] = 0; map[2 + (h - 1) * 6][25 - i - 5] = 0; map[1 + (h - 1) * 6][25 - i - 5] = 0;  map[5 + h * 6][25 - i - 5] = 0; map[3 + h * 6][25 - i - 5] = 0; map[2 + h * 6][25 - i - 5] = 0; map[1 + h * 6][25 - i - 5] = 0; delay(); mapping2(); break;
		case 5:
			map[5 + (h - 1) * 6][3] = 2; map[4 + h * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 6] = 1; map[3 + (h - 1) * 6][25 - i - 6] = 1; map[2 + (h - 1) * 6][25 - i - 6] = 1; map[1 + (h - 1) * 6][25 - i - 6] = 1;  map[5 + h * 6][25 - i - 6] = 1; map[3 + h * 6][25 - i - 6] = 1; map[2 + h * 6][25 - i - 6] = 1; map[1 + h * 6][25 - i - 6] = 1; mapping2();
			map[5 + (h - 1) * 6][3] = 0; map[4 + h * 6][3] = 0; map[5 + (h - 1) * 6][25 - i - 6] = 0; map[3 + (h - 1) * 6][25 - i - 6] = 0; map[2 + (h - 1) * 6][25 - i - 6] = 0; map[1 + (h - 1) * 6][25 - i - 6] = 0;  map[5 + h * 6][25 - i - 6] = 0; map[3 + h * 6][25 - i - 6] = 0; map[2 + h * 6][25 - i - 6] = 0; map[1 + h * 6][25 - i - 6] = 0; delay(); mapping2(); break;
		case 6:
			map[5 + (h - 1) * 6][3] = 2; map[5 + h * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 7] = 1; map[3 + (h - 1) * 6][25 - i - 7] = 1; map[2 + (h - 1) * 6][25 - i - 7] = 1; map[1 + (h - 1) * 6][25 - i - 7] = 1;  map[5 + h * 6][25 - i - 7] = 1; map[3 + h * 6][25 - i - 7] = 1; map[2 + h * 6][25 - i - 7] = 1; map[1 + h * 6][25 - i - 7] = 1; mapping2();
			map[5 + (h - 1) * 6][25 - i - 7] = 0; map[3 + (h - 1) * 6][25 - i - 7] = 0; map[2 + (h - 1) * 6][25 - i - 7] = 0; map[1 + (h - 1) * 6][25 - i - 7] = 0;  map[5 + h * 6][25 - i - 7] = 0; map[3 + h * 6][25 - i - 7] = 0; map[2 + h * 6][25 - i - 7] = 0; map[1 + h * 6][25 - i - 7] = 0; delay(); mapping2(); break;
		}
		step++;
		step = step % 7;
	}
}
void jump3_1_13(int i, int h) { // �ٲ��ٷ��� ��ֹ��� ���� �ٲ������.
	static int step = 0;
	int j = 0;
	for (j = 0; j<7; j++) {
		switch (step) {
		case 0:
			map[5 + (h - 1) * 6][3] = 2; map[5 + (h + 1) * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 1] = 1; map[3 + (h - 1) * 6][25 - i - 1] = 1; map[2 + (h - 1) * 6][25 - i - 1] = 1; map[1 + (h - 1) * 6][25 - i - 1] = 1;  map[5 + (h + 1) * 6][25 - i - 1] = 1; map[3 + (h + 1) * 6][25 - i - 1] = 1; map[2 + (h + 1) * 6][25 - i - 1] = 1; map[1 + (h + 1) * 6][25 - i - 1] = 1; mapping2();
			map[5 + (h - 1) * 6][3] = 0; map[5 + (h + 1) * 6][3] = 0; map[5 + (h - 1) * 6][25 - i - 1] = 0; map[3 + (h - 1) * 6][25 - i - 1] = 0; map[2 + (h - 1) * 6][25 - i - 1] = 0; map[1 + (h - 1) * 6][25 - i - 1] = 0;  map[5 + (h + 1) * 6][25 - i - 1] = 0; map[3 + (h + 1) * 6][25 - i - 1] = 0; map[2 + (h + 1) * 6][25 - i - 1] = 0; map[1 + (h + 1) * 6][25 - i - 1] = 0; delay(); mapping2(); break;
		case 1:
			map[4 + (h - 1) * 6][3] = 2; map[4 + (h + 1) * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 2] = 1; map[3 + (h - 1) * 6][25 - i - 2] = 1; map[2 + (h - 1) * 6][25 - i - 2] = 1; map[1 + (h - 1) * 6][25 - i - 2] = 1;  map[5 + (h + 1) * 6][25 - i - 2] = 1; map[3 + (h + 1) * 6][25 - i - 2] = 1; map[2 + (h + 1) * 6][25 - i - 2] = 1; map[1 + (h + 1) * 6][25 - i - 2] = 1; mapping2();
			map[4 + (h - 1) * 6][3] = 0; map[4 + (h + 1) * 6][3] = 0; map[5 + (h - 1) * 6][25 - i - 2] = 0; map[3 + (h - 1) * 6][25 - i - 2] = 0; map[2 + (h - 1) * 6][25 - i - 2] = 0; map[1 + (h - 1) * 6][25 - i - 2] = 0;  map[5 + (h + 1) * 6][25 - i - 2] = 0; map[3 + (h + 1) * 6][25 - i - 2] = 0; map[2 + (h + 1) * 6][25 - i - 2] = 0; map[1 + (h + 1) * 6][25 - i - 2] = 0; delay(); mapping2(); break;
		case 2:
			map[3 + (h - 1) * 6][3] = 2; map[3 + (h + 1) * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 3] = 1; map[3 + (h - 1) * 6][25 - i - 3] = 1; map[2 + (h - 1) * 6][25 - i - 3] = 1; map[1 + (h - 1) * 6][25 - i - 3] = 1;  map[5 + (h + 1) * 6][25 - i - 3] = 1; map[3 + (h + 1) * 6][25 - i - 3] = 1; map[2 + (h + 1) * 6][25 - i - 3] = 1; map[1 + (h + 1) * 6][25 - i - 3] = 1; mapping2();
			map[3 + (h - 1) * 6][3] = 0; map[3 + (h + 1) * 6][3] = 0; map[5 + (h - 1) * 6][25 - i - 3] = 0; map[3 + (h - 1) * 6][25 - i - 3] = 0; map[2 + (h - 1) * 6][25 - i - 3] = 0; map[1 + (h - 1) * 6][25 - i - 3] = 0;  map[5 + (h + 1) * 6][25 - i - 3] = 0; map[3 + (h + 1) * 6][25 - i - 3] = 0; map[2 + (h + 1) * 6][25 - i - 3] = 0; map[1 + (h + 1) * 6][25 - i - 3] = 0; delay(); mapping2(); break;
		case 3:
			map[2 + (h - 1) * 6][3] = 2; map[2 + (h + 1) * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 4] = 1; map[3 + (h - 1) * 6][25 - i - 4] = 1; map[2 + (h - 1) * 6][25 - i - 4] = 1; map[1 + (h - 1) * 6][25 - i - 4] = 1;  map[5 + (h + 1) * 6][25 - i - 4] = 1; map[3 + (h + 1) * 6][25 - i - 4] = 1; map[2 + (h + 1) * 6][25 - i - 4] = 1; map[1 + (h + 1) * 6][25 - i - 4] = 1; mapping2();
			map[2 + (h - 1) * 6][3] = 0; map[2 + (h + 1) * 6][3] = 0; map[5 + (h - 1) * 6][25 - i - 4] = 0; map[3 + (h - 1) * 6][25 - i - 4] = 0; map[2 + (h - 1) * 6][25 - i - 4] = 0; map[1 + (h - 1) * 6][25 - i - 4] = 0;  map[5 + (h + 1) * 6][25 - i - 4] = 0; map[3 + (h + 1) * 6][25 - i - 4] = 0; map[2 + (h + 1) * 6][25 - i - 4] = 0; map[1 + (h + 1) * 6][25 - i - 4] = 0; delay(); mapping2(); break;
		case 4:
			map[3 + (h - 1) * 6][3] = 2; map[3 + (h + 1) * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 5] = 1; map[3 + (h - 1) * 6][25 - i - 5] = 1; map[2 + (h - 1) * 6][25 - i - 5] = 1; map[1 + (h - 1) * 6][25 - i - 5] = 1;  map[5 + (h + 1) * 6][25 - i - 5] = 1; map[3 + (h + 1) * 6][25 - i - 5] = 1; map[2 + (h + 1) * 6][25 - i - 5] = 1; map[1 + (h + 1) * 6][25 - i - 5] = 1; mapping2();
			map[3 + (h - 1) * 6][3] = 0; map[3 + (h + 1) * 6][3] = 0; map[5 + (h - 1) * 6][25 - i - 5] = 0; map[3 + (h - 1) * 6][25 - i - 5] = 0; map[2 + (h - 1) * 6][25 - i - 5] = 0; map[1 + (h - 1) * 6][25 - i - 5] = 0;  map[5 + (h + 1) * 6][25 - i - 5] = 0; map[3 + (h + 1) * 6][25 - i - 5] = 0; map[2 + (h + 1) * 6][25 - i - 5] = 0; map[1 + (h + 1) * 6][25 - i - 5] = 0; delay(); mapping2(); break;
		case 5:
			map[4 + (h - 1) * 6][3] = 2; map[4 + (h + 1) * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 6] = 1; map[3 + (h - 1) * 6][25 - i - 6] = 1; map[2 + (h - 1) * 6][25 - i - 6] = 1; map[1 + (h - 1) * 6][25 - i - 6] = 1;  map[5 + (h + 1) * 6][25 - i - 6] = 1; map[3 + (h + 1) * 6][25 - i - 6] = 1; map[2 + (h + 1) * 6][25 - i - 6] = 1; map[1 + (h + 1) * 6][25 - i - 6] = 1; mapping2();
			map[4 + (h - 1) * 6][3] = 0; map[4 + (h + 1) * 6][3] = 0; map[5 + (h - 1) * 6][25 - i - 6] = 0; map[3 + (h - 1) * 6][25 - i - 6] = 0; map[2 + (h - 1) * 6][25 - i - 6] = 0; map[1 + (h - 1) * 6][25 - i - 6] = 0;  map[5 + (h + 1) * 6][25 - i - 6] = 0; map[3 + (h + 1) * 6][25 - i - 6] = 0; map[2 + (h + 1) * 6][25 - i - 6] = 0; map[1 + (h + 1) * 6][25 - i - 6] = 0; delay(); mapping2(); break;
		case 6:
			map[5 + (h - 1) * 6][3] = 2; map[5 + (h + 1) * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 7] = 1; map[3 + (h - 1) * 6][25 - i - 7] = 1; map[2 + (h - 1) * 6][25 - i - 7] = 1; map[1 + (h - 1) * 6][25 - i - 7] = 1;  map[5 + (h + 1) * 6][25 - i - 7] = 1; map[3 + (h + 1) * 6][25 - i - 7] = 1; map[2 + (h + 1) * 6][25 - i - 7] = 1; map[1 + (h + 1) * 6][25 - i - 7] = 1; mapping2();
			map[5 + (h - 1) * 6][25 - i - 7] = 0; map[3 + (h - 1) * 6][25 - i - 7] = 0; map[2 + (h - 1) * 6][25 - i - 7] = 0; map[1 + (h - 1) * 6][25 - i - 7] = 0;  map[5 + (h + 1) * 6][25 - i - 7] = 0; map[3 + (h + 1) * 6][25 - i - 7] = 0; map[2 + (h + 1) * 6][25 - i - 7] = 0; map[1 + (h + 1) * 6][25 - i - 7] = 0; delay(); mapping2(); break;
		}
		step++;
		step = step % 7;
	}
}
void jump3_1_13_1(int i, int h) { // �ٲ��ٷ��� ��ֹ��� ���� �ٲ������.
	static int step = 0;
	int j = 0;
	for (j = 0; j<7; j++) {
		switch (step) {
		case 0:
			map[5 + (h - 1) * 6][3] = 2; map[5 + (h + 1) * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 1] = 1; map[3 + (h - 1) * 6][25 - i - 1] = 1; map[2 + (h - 1) * 6][25 - i - 1] = 1; map[1 + (h - 1) * 6][25 - i - 1] = 1;  map[5 + (h + 1) * 6][25 - i - 1] = 1; map[3 + (h + 1) * 6][25 - i - 1] = 1; map[2 + (h + 1) * 6][25 - i - 1] = 1; map[1 + (h + 1) * 6][25 - i - 1] = 1; mapping2();
			map[5 + (h - 1) * 6][3] = 0; map[5 + (h + 1) * 6][3] = 0; map[5 + (h - 1) * 6][25 - i - 1] = 0; map[3 + (h - 1) * 6][25 - i - 1] = 0; map[2 + (h - 1) * 6][25 - i - 1] = 0; map[1 + (h - 1) * 6][25 - i - 1] = 0;  map[5 + (h + 1) * 6][25 - i - 1] = 0; map[3 + (h + 1) * 6][25 - i - 1] = 0; map[2 + (h + 1) * 6][25 - i - 1] = 0; map[1 + (h + 1) * 6][25 - i - 1] = 0; delay(); mapping2(); break;
		case 1:
			map[4 + (h - 1) * 6][3] = 2; map[5 + (h + 1) * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 2] = 1; map[3 + (h - 1) * 6][25 - i - 2] = 1; map[2 + (h - 1) * 6][25 - i - 2] = 1; map[1 + (h - 1) * 6][25 - i - 2] = 1;  map[5 + (h + 1) * 6][25 - i - 2] = 1; map[3 + (h + 1) * 6][25 - i - 2] = 1; map[2 + (h + 1) * 6][25 - i - 2] = 1; map[1 + (h + 1) * 6][25 - i - 2] = 1; mapping2();
			map[4 + (h - 1) * 6][3] = 0; map[5 + (h + 1) * 6][3] = 0; map[5 + (h - 1) * 6][25 - i - 2] = 0; map[3 + (h - 1) * 6][25 - i - 2] = 0; map[2 + (h - 1) * 6][25 - i - 2] = 0; map[1 + (h - 1) * 6][25 - i - 2] = 0;  map[5 + (h + 1) * 6][25 - i - 2] = 0; map[3 + (h + 1) * 6][25 - i - 2] = 0; map[2 + (h + 1) * 6][25 - i - 2] = 0; map[1 + (h + 1) * 6][25 - i - 2] = 0; delay(); mapping2(); break;
		case 2:
			map[3 + (h - 1) * 6][3] = 2; map[5 + (h + 1) * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 3] = 1; map[3 + (h - 1) * 6][25 - i - 3] = 1; map[2 + (h - 1) * 6][25 - i - 3] = 1; map[1 + (h - 1) * 6][25 - i - 3] = 1;  map[5 + (h + 1) * 6][25 - i - 3] = 1; map[3 + (h + 1) * 6][25 - i - 3] = 1; map[2 + (h + 1) * 6][25 - i - 3] = 1; map[1 + (h + 1) * 6][25 - i - 3] = 1; mapping2();
			map[3 + (h - 1) * 6][3] = 0; map[5 + (h + 1) * 6][3] = 0; map[5 + (h - 1) * 6][25 - i - 3] = 0; map[3 + (h - 1) * 6][25 - i - 3] = 0; map[2 + (h - 1) * 6][25 - i - 3] = 0; map[1 + (h - 1) * 6][25 - i - 3] = 0;  map[5 + (h + 1) * 6][25 - i - 3] = 0; map[3 + (h + 1) * 6][25 - i - 3] = 0; map[2 + (h + 1) * 6][25 - i - 3] = 0; map[1 + (h + 1) * 6][25 - i - 3] = 0; delay(); mapping2(); break;
		case 3:
			map[2 + (h - 1) * 6][3] = 2; map[5 + (h + 1) * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 4] = 1; map[3 + (h - 1) * 6][25 - i - 4] = 1; map[2 + (h - 1) * 6][25 - i - 4] = 1; map[1 + (h - 1) * 6][25 - i - 4] = 1;  map[5 + (h + 1) * 6][25 - i - 4] = 1; map[3 + (h + 1) * 6][25 - i - 4] = 1; map[2 + (h + 1) * 6][25 - i - 4] = 1; map[1 + (h + 1) * 6][25 - i - 4] = 1; mapping2();
			map[2 + (h - 1) * 6][3] = 0; map[5 + (h + 1) * 6][3] = 0; map[5 + (h - 1) * 6][25 - i - 4] = 0; map[3 + (h - 1) * 6][25 - i - 4] = 0; map[2 + (h - 1) * 6][25 - i - 4] = 0; map[1 + (h - 1) * 6][25 - i - 4] = 0;  map[5 + (h + 1) * 6][25 - i - 4] = 0; map[3 + (h + 1) * 6][25 - i - 4] = 0; map[2 + (h + 1) * 6][25 - i - 4] = 0; map[1 + (h + 1) * 6][25 - i - 4] = 0; delay(); mapping2(); break;
		case 4:
			map[3 + (h - 1) * 6][3] = 2; map[5 + (h + 1) * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 5] = 1; map[3 + (h - 1) * 6][25 - i - 5] = 1; map[2 + (h - 1) * 6][25 - i - 5] = 1; map[1 + (h - 1) * 6][25 - i - 5] = 1;  map[5 + (h + 1) * 6][25 - i - 5] = 1; map[3 + (h + 1) * 6][25 - i - 5] = 1; map[2 + (h + 1) * 6][25 - i - 5] = 1; map[1 + (h + 1) * 6][25 - i - 5] = 1; mapping2();
			map[3 + (h - 1) * 6][3] = 0; map[5 + (h + 1) * 6][3] = 0; map[5 + (h - 1) * 6][25 - i - 5] = 0; map[3 + (h - 1) * 6][25 - i - 5] = 0; map[2 + (h - 1) * 6][25 - i - 5] = 0; map[1 + (h - 1) * 6][25 - i - 5] = 0;  map[5 + (h + 1) * 6][25 - i - 5] = 0; map[3 + (h + 1) * 6][25 - i - 5] = 0; map[2 + (h + 1) * 6][25 - i - 5] = 0; map[1 + (h + 1) * 6][25 - i - 5] = 0; delay(); mapping2(); break;
		case 5:
			map[4 + (h - 1) * 6][3] = 2; map[5 + (h + 1) * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 6] = 1; map[3 + (h - 1) * 6][25 - i - 6] = 1; map[2 + (h - 1) * 6][25 - i - 6] = 1; map[1 + (h - 1) * 6][25 - i - 6] = 1;  map[5 + (h + 1) * 6][25 - i - 6] = 1; map[3 + (h + 1) * 6][25 - i - 6] = 1; map[2 + (h + 1) * 6][25 - i - 6] = 1; map[1 + (h + 1) * 6][25 - i - 6] = 1; mapping2();
			map[4 + (h - 1) * 6][3] = 0; map[5 + (h + 1) * 6][3] = 0; map[5 + (h - 1) * 6][25 - i - 6] = 0; map[3 + (h - 1) * 6][25 - i - 6] = 0; map[2 + (h - 1) * 6][25 - i - 6] = 0; map[1 + (h - 1) * 6][25 - i - 6] = 0;  map[5 + (h + 1) * 6][25 - i - 6] = 0; map[3 + (h + 1) * 6][25 - i - 6] = 0; map[2 + (h + 1) * 6][25 - i - 6] = 0; map[1 + (h + 1) * 6][25 - i - 6] = 0; delay(); mapping2(); break;
		case 6:
			map[5 + (h - 1) * 6][3] = 2; map[5 + (h + 1) * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 7] = 1; map[3 + (h - 1) * 6][25 - i - 7] = 1; map[2 + (h - 1) * 6][25 - i - 7] = 1; map[1 + (h - 1) * 6][25 - i - 7] = 1;  map[5 + (h + 1) * 6][25 - i - 7] = 1; map[3 + (h + 1) * 6][25 - i - 7] = 1; map[2 + (h + 1) * 6][25 - i - 7] = 1; map[1 + (h + 1) * 6][25 - i - 7] = 1; mapping2();
			map[5 + (h - 1) * 6][25 - i - 7] = 0; map[3 + (h - 1) * 6][25 - i - 7] = 0; map[2 + (h - 1) * 6][25 - i - 7] = 0; map[1 + (h - 1) * 6][25 - i - 7] = 0;  map[5 + (h + 1) * 6][25 - i - 7] = 0; map[3 + (h + 1) * 6][25 - i - 7] = 0; map[2 + (h + 1) * 6][25 - i - 7] = 0; map[1 + (h + 1) * 6][25 - i - 7] = 0; delay(); mapping2(); break;
		}
		step++;
		step = step % 7;
	}
}
void jump3_1_13_2(int i, int h) { // �ٲ��ٷ��� ��ֹ��� ���� �ٲ������.
	static int step = 0;
	int j = 0;
	for (j = 0; j<7; j++) {
		switch (step) {
		case 0:
			map[5 + (h - 1) * 6][3] = 2; map[5 + (h + 1) * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 1] = 1; map[3 + (h - 1) * 6][25 - i - 1] = 1; map[2 + (h - 1) * 6][25 - i - 1] = 1; map[1 + (h - 1) * 6][25 - i - 1] = 1;  map[5 + (h + 1) * 6][25 - i - 1] = 1; map[3 + (h + 1) * 6][25 - i - 1] = 1; map[2 + (h + 1) * 6][25 - i - 1] = 1; map[1 + (h + 1) * 6][25 - i - 1] = 1; mapping2();
			map[5 + (h - 1) * 6][3] = 0; map[5 + (h + 1) * 6][3] = 0; map[5 + (h - 1) * 6][25 - i - 1] = 0; map[3 + (h - 1) * 6][25 - i - 1] = 0; map[2 + (h - 1) * 6][25 - i - 1] = 0; map[1 + (h - 1) * 6][25 - i - 1] = 0;  map[5 + (h + 1) * 6][25 - i - 1] = 0; map[3 + (h + 1) * 6][25 - i - 1] = 0; map[2 + (h + 1) * 6][25 - i - 1] = 0; map[1 + (h + 1) * 6][25 - i - 1] = 0; delay(); mapping2(); break;
		case 1:
			map[5 + (h - 1) * 6][3] = 2; map[4 + (h + 1) * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 2] = 1; map[3 + (h - 1) * 6][25 - i - 2] = 1; map[2 + (h - 1) * 6][25 - i - 2] = 1; map[1 + (h - 1) * 6][25 - i - 2] = 1;  map[5 + (h + 1) * 6][25 - i - 2] = 1; map[3 + (h + 1) * 6][25 - i - 2] = 1; map[2 + (h + 1) * 6][25 - i - 2] = 1; map[1 + (h + 1) * 6][25 - i - 2] = 1; mapping2();
			map[5 + (h - 1) * 6][3] = 0; map[4 + (h + 1) * 6][3] = 0; map[5 + (h - 1) * 6][25 - i - 2] = 0; map[3 + (h - 1) * 6][25 - i - 2] = 0; map[2 + (h - 1) * 6][25 - i - 2] = 0; map[1 + (h - 1) * 6][25 - i - 2] = 0;  map[5 + (h + 1) * 6][25 - i - 2] = 0; map[3 + (h + 1) * 6][25 - i - 2] = 0; map[2 + (h + 1) * 6][25 - i - 2] = 0; map[1 + (h + 1) * 6][25 - i - 2] = 0; delay(); mapping2(); break;
		case 2:
			map[5 + (h - 1) * 6][3] = 2; map[3 + (h + 1) * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 3] = 1; map[3 + (h - 1) * 6][25 - i - 3] = 1; map[2 + (h - 1) * 6][25 - i - 3] = 1; map[1 + (h - 1) * 6][25 - i - 3] = 1;  map[5 + (h + 1) * 6][25 - i - 3] = 1; map[3 + (h + 1) * 6][25 - i - 3] = 1; map[2 + (h + 1) * 6][25 - i - 3] = 1; map[1 + (h + 1) * 6][25 - i - 3] = 1; mapping2();
			map[5 + (h - 1) * 6][3] = 0; map[3 + (h + 1) * 6][3] = 0; map[5 + (h - 1) * 6][25 - i - 3] = 0; map[3 + (h - 1) * 6][25 - i - 3] = 0; map[2 + (h - 1) * 6][25 - i - 3] = 0; map[1 + (h - 1) * 6][25 - i - 3] = 0;  map[5 + (h + 1) * 6][25 - i - 3] = 0; map[3 + (h + 1) * 6][25 - i - 3] = 0; map[2 + (h + 1) * 6][25 - i - 3] = 0; map[1 + (h + 1) * 6][25 - i - 3] = 0; delay(); mapping2(); break;
		case 3:
			map[5 + (h - 1) * 6][3] = 2; map[2 + (h + 1) * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 4] = 1; map[3 + (h - 1) * 6][25 - i - 4] = 1; map[2 + (h - 1) * 6][25 - i - 4] = 1; map[1 + (h - 1) * 6][25 - i - 4] = 1;  map[5 + (h + 1) * 6][25 - i - 4] = 1; map[3 + (h + 1) * 6][25 - i - 4] = 1; map[2 + (h + 1) * 6][25 - i - 4] = 1; map[1 + (h + 1) * 6][25 - i - 4] = 1; mapping2();
			map[5 + (h - 1) * 6][3] = 0; map[2 + (h + 1) * 6][3] = 0; map[5 + (h - 1) * 6][25 - i - 4] = 0; map[3 + (h - 1) * 6][25 - i - 4] = 0; map[2 + (h - 1) * 6][25 - i - 4] = 0; map[1 + (h - 1) * 6][25 - i - 4] = 0;  map[5 + (h + 1) * 6][25 - i - 4] = 0; map[3 + (h + 1) * 6][25 - i - 4] = 0; map[2 + (h + 1) * 6][25 - i - 4] = 0; map[1 + (h + 1) * 6][25 - i - 4] = 0; delay(); mapping2(); break;
		case 4:
			map[5 + (h - 1) * 6][3] = 2; map[3 + (h + 1) * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 5] = 1; map[3 + (h - 1) * 6][25 - i - 5] = 1; map[2 + (h - 1) * 6][25 - i - 5] = 1; map[1 + (h - 1) * 6][25 - i - 5] = 1;  map[5 + (h + 1) * 6][25 - i - 5] = 1; map[3 + (h + 1) * 6][25 - i - 5] = 1; map[2 + (h + 1) * 6][25 - i - 5] = 1; map[1 + (h + 1) * 6][25 - i - 5] = 1; mapping2();
			map[5 + (h - 1) * 6][3] = 0; map[3 + (h + 1) * 6][3] = 0; map[5 + (h - 1) * 6][25 - i - 5] = 0; map[3 + (h - 1) * 6][25 - i - 5] = 0; map[2 + (h - 1) * 6][25 - i - 5] = 0; map[1 + (h - 1) * 6][25 - i - 5] = 0;  map[5 + (h + 1) * 6][25 - i - 5] = 0; map[3 + (h + 1) * 6][25 - i - 5] = 0; map[2 + (h + 1) * 6][25 - i - 5] = 0; map[1 + (h + 1) * 6][25 - i - 5] = 0; delay(); mapping2(); break;
		case 5:
			map[5 + (h - 1) * 6][3] = 2; map[4 + (h + 1) * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 6] = 1; map[3 + (h - 1) * 6][25 - i - 6] = 1; map[2 + (h - 1) * 6][25 - i - 6] = 1; map[1 + (h - 1) * 6][25 - i - 6] = 1;  map[5 + (h + 1) * 6][25 - i - 6] = 1; map[3 + (h + 1) * 6][25 - i - 6] = 1; map[2 + (h + 1) * 6][25 - i - 6] = 1; map[1 + (h + 1) * 6][25 - i - 6] = 1; mapping2();
			map[5 + (h - 1) * 6][3] = 0; map[4 + (h + 1) * 6][3] = 0; map[5 + (h - 1) * 6][25 - i - 6] = 0; map[3 + (h - 1) * 6][25 - i - 6] = 0; map[2 + (h - 1) * 6][25 - i - 6] = 0; map[1 + (h - 1) * 6][25 - i - 6] = 0;  map[5 + (h + 1) * 6][25 - i - 6] = 0; map[3 + (h + 1) * 6][25 - i - 6] = 0; map[2 + (h + 1) * 6][25 - i - 6] = 0; map[1 + (h + 1) * 6][25 - i - 6] = 0; delay(); mapping2(); break;
		case 6:
			map[5 + (h - 1) * 6][3] = 2; map[5 + (h + 1) * 6][3] = 2; map[5 + (h - 1) * 6][25 - i - 7] = 1; map[3 + (h - 1) * 6][25 - i - 7] = 1; map[2 + (h - 1) * 6][25 - i - 7] = 1; map[1 + (h - 1) * 6][25 - i - 7] = 1;  map[5 + (h + 1) * 6][25 - i - 7] = 1; map[3 + (h + 1) * 6][25 - i - 7] = 1; map[2 + (h + 1) * 6][25 - i - 7] = 1; map[1 + (h + 1) * 6][25 - i - 7] = 1; mapping2();
			map[5 + (h - 1) * 6][25 - i - 7] = 0; map[3 + (h - 1) * 6][25 - i - 7] = 0; map[2 + (h - 1) * 6][25 - i - 7] = 0; map[1 + (h - 1) * 6][25 - i - 7] = 0;  map[5 + (h + 1) * 6][25 - i - 7] = 0; map[3 + (h + 1) * 6][25 - i - 7] = 0; map[2 + (h + 1) * 6][25 - i - 7] = 0; map[1 + (h + 1) * 6][25 - i - 7] = 0; delay(); mapping2(); break;
		}
		step++;
		step = step % 7;
	}
}

void obstacle0_1(int i, int h) { // i �� ���� ��ġ.
	if (i>0) {
		map[5 + (h - 1) * 6][25 - i] = 1; mapping2();
		map[5 + (h - 1) * 6][25 - i] = 0; delay(); mapping2();
	}
}
void obstacle0_1_12(int i, int h) { // i �� ���� ��ġ.
	if (i>0) {
		map[5 + (h - 1) * 6][25 - i] = 1; map[5 + h * 6][25 - i] = 1; mapping2();
		map[5 + (h - 1) * 6][25 - i] = 0; map[5 + h * 6][25 - i] = 0; delay(); mapping2();
	}
}
void obstacle0_1_13(int i, int h) { // i �� ���� ��ġ.
	if (i>0) {
		map[5 + (h - 1) * 6][25 - i] = 1; map[5 + (h + 1) * 6][25 - i] = 1; mapping2();
		map[5 + (h - 1) * 6][25 - i] = 0; map[5 + (h + 1) * 6][25 - i] = 0; delay(); mapping2();
	}
}

void obstacle0_2(int i, int h) {
	if (i>0) {
		map[5 + (h - 1) * 6][25 - i] = 1; map[4 + (h - 1) * 6][25 - i] = 1; mapping2();
		map[5 + (h - 1) * 6][25 - i] = 0; map[4 + (h - 1) * 6][25 - i] = 0; delay(); mapping2();
	}
}
void obstacle0_2_12(int i, int h) {
	if (i>0) {
		map[5 + (h - 1) * 6][25 - i] = 1; map[4 + (h - 1) * 6][25 - i] = 1; map[5 + h * 6][25 - i] = 1; map[4 + h * 6][25 - i] = 1; mapping2();
		map[5 + (h - 1) * 6][25 - i] = 0; map[4 + (h - 1) * 6][25 - i] = 0; map[5 + h * 6][25 - i] = 0; map[4 + h * 6][25 - i] = 0; delay(); mapping2();
	}
}
void obstacle0_2_13(int i, int h) {
	if (i>0) {
		map[5 + (h - 1) * 6][25 - i] = 1; map[4 + (h - 1) * 6][25 - i] = 1; map[5 + (h + 1) * 6][25 - i] = 1; map[4 + (h + 1) * 6][25 - i] = 1; mapping2();
		map[5 + (h - 1) * 6][25 - i] = 0; map[4 + (h - 1) * 6][25 - i] = 0; map[5 + (h + 1) * 6][25 - i] = 0; map[4 + (h + 1) * 6][25 - i] = 0; delay(); mapping2();
	}
}

void obstacle3_0(int i, int h) {
	if (i>0) {
		map[3 + (h - 1) * 6][25 - i] = 1; map[2 + (h - 1) * 6][25 - i] = 1; map[1 + (h - 1) * 6][25 - i] = 1; mapping2();
		map[3 + (h - 1) * 6][25 - i] = 0; map[2 + (h - 1) * 6][25 - i] = 0; map[1 + (h - 1) * 6][25 - i] = 0; delay(); mapping2();
	}
}
void obstacle3_0_12(int i, int h) {
	if (i>0) {
		map[3 + (h - 1) * 6][25 - i] = 1; map[2 + (h - 1) * 6][25 - i] = 1; map[1 + (h - 1) * 6][25 - i] = 1; map[3 + h * 6][25 - i] = 1; map[2 + h * 6][25 - i] = 1; map[1 + h * 6][25 - i] = 1; mapping2();
		map[3 + (h - 1) * 6][25 - i] = 0; map[2 + (h - 1) * 6][25 - i] = 0; map[1 + (h - 1) * 6][25 - i] = 0; map[3 + h * 6][25 - i] = 0; map[2 + h * 6][25 - i] = 0; map[1 + h * 6][25 - i] = 0; delay(); mapping2();
	}
}
void obstacle3_0_13(int i, int h) {
	if (i>0) {
		map[3 + (h - 1) * 6][25 - i] = 1; map[2 + (h - 1) * 6][25 - i] = 1; map[1 + (h - 1) * 6][25 - i] = 1; map[3 + (h + 1) * 6][25 - i] = 1; map[2 + (h + 1) * 6][25 - i] = 1; map[1 + (h + 1) * 6][25 - i] = 1; mapping2();
		map[3 + (h - 1) * 6][25 - i] = 0; map[2 + (h - 1) * 6][25 - i] = 0; map[1 + (h - 1) * 6][25 - i] = 0; map[3 + (h + 1) * 6][25 - i] = 0; map[2 + (h + 1) * 6][25 - i] = 0; map[1 + (h + 1) * 6][25 - i] = 0; delay(); mapping2();
	}
}

void obstacle4_0(int i, int h) {
	if (i>0) {
		map[4 + (h - 1) * 6][25 - i] = 1; map[3 + (h - 1) * 6][25 - i] = 1; map[2 + (h - 1) * 6][25 - i] = 1; map[1 + (h - 1) * 6][25 - i] = 1; mapping2();
		map[4 + (h - 1) * 6][25 - i] = 0; map[3 + (h - 1) * 6][25 - i] = 0; map[2 + (h - 1) * 6][25 - i] = 0; map[1 + (h - 1) * 6][25 - i] = 0; delay(); mapping2();
	}
}
void obstacle4_0_12(int i, int h) {
	if (i>0) {
		map[4 + (h - 1) * 6][25 - i] = 1; map[3 + (h - 1) * 6][25 - i] = 1; map[2 + (h - 1) * 6][25 - i] = 1; map[1 + (h - 1) * 6][25 - i] = 1; map[4 + h * 6][25 - i] = 1; map[3 + h * 6][25 - i] = 1; map[2 + h * 6][25 - i] = 1; map[1 + h * 6][25 - i] = 1; mapping2();
		map[4 + (h - 1) * 6][25 - i] = 0; map[3 + (h - 1) * 6][25 - i] = 0; map[2 + (h - 1) * 6][25 - i] = 0; map[1 + (h - 1) * 6][25 - i] = 0; map[4 + h * 6][25 - i] = 0; map[3 + h * 6][25 - i] = 0; map[2 + h * 6][25 - i] = 0; map[1 + h * 6][25 - i] = 0; delay(); mapping2();
	}
}
void obstacle4_0_13(int i, int h) {
	if (i>0) {
		map[4 + (h - 1) * 6][25 - i] = 1; map[3 + (h - 1) * 6][25 - i] = 1; map[2 + (h - 1) * 6][25 - i] = 1; map[1 + (h - 1) * 6][25 - i] = 1; map[4 + (h + 1) * 6][25 - i] = 1; map[3 + (h + 1) * 6][25 - i] = 1; map[2 + (h + 1) * 6][25 - i] = 1; map[1 + (h + 1) * 6][25 - i] = 1; mapping2();
		map[4 + (h - 1) * 6][25 - i] = 0; map[3 + (h - 1) * 6][25 - i] = 0; map[2 + (h - 1) * 6][25 - i] = 0; map[1 + (h - 1) * 6][25 - i] = 0; map[4 + (h + 1) * 6][25 - i] = 0; map[3 + (h + 1) * 6][25 - i] = 0; map[2 + (h + 1) * 6][25 - i] = 0; map[1 + (h + 1) * 6][25 - i] = 0; delay(); mapping2();
	}
}

void obstacle1_1(int i, int h) {
	if (i>0) {
		map[5 + (h - 1) * 6][25 - i] = 1; map[1 + (h - 1) * 6][25 - i] = 1; mapping2();
		map[5 + (h - 1) * 6][25 - i] = 0; map[1 + (h - 1) * 6][25 - i] = 0; delay(); mapping2();
	}
}
void obstacle1_1_12(int i, int h) {
	if (i>0) {
		map[5 + (h - 1) * 6][25 - i] = 1; map[1 + (h - 1) * 6][25 - i] = 1; map[5 + h * 6][25 - i] = 1; map[1 + h * 6][25 - i] = 1; mapping2();
		map[5 + (h - 1) * 6][25 - i] = 0; map[1 + (h - 1) * 6][25 - i] = 0; map[5 + h * 6][25 - i] = 0; map[1 + h * 6][25 - i] = 0; delay(); mapping2();
	}
}
void obstacle1_1_13(int i, int h) {
	if (i>0) {
		map[5 + (h - 1) * 6][25 - i] = 1; map[1 + (h - 1) * 6][25 - i] = 1; map[5 + (h + 1) * 6][25 - i] = 1; map[1 + (h + 1) * 6][25 - i] = 1; mapping2();
		map[5 + (h - 1) * 6][25 - i] = 0; map[1 + (h - 1) * 6][25 - i] = 0; map[5 + (h + 1) * 6][25 - i] = 0; map[1 + (h + 1) * 6][25 - i] = 0; delay(); mapping2();
	}
}

void obstacle2_1(int i, int h) {
	if (i>0) {
		map[5 + (h - 1) * 6][25 - i] = 1; map[2 + (h - 1) * 6][25 - i] = 1; map[1 + (h - 1) * 6][25 - i] = 1; mapping2();
		map[5 + (h - 1) * 6][25 - i] = 0; map[2 + (h - 1) * 6][25 - i] = 0; map[1 + (h - 1) * 6][25 - i] = 0; delay(); mapping2();
	}
}
void obstacle2_1_12(int i, int h) {
	if (i>0) {
		map[5 + (h - 1) * 6][25 - i] = 1; map[2 + (h - 1) * 6][25 - i] = 1; map[1 + (h - 1) * 6][25 - i] = 1; map[5 + h * 6][25 - i] = 1; map[2 + h * 6][25 - i] = 1; map[1 + h * 6][25 - i] = 1; mapping2();
		map[5 + (h - 1) * 6][25 - i] = 0; map[2 + (h - 1) * 6][25 - i] = 0; map[1 + (h - 1) * 6][25 - i] = 0; map[5 + h * 6][25 - i] = 0; map[2 + h * 6][25 - i] = 0; map[1 + h * 6][25 - i] = 0; delay(); mapping2();
	}
}
void obstacle2_1_13(int i, int h) {
	if (i>0) {
		map[5 + (h - 1) * 6][25 - i] = 1; map[2 + (h - 1) * 6][25 - i] = 1; map[1 + (h - 1) * 6][25 - i] = 1; map[5 + (h + 1) * 6][25 - i] = 1; map[2 + (h + 1) * 6][25 - i] = 1; map[1 + (h + 1) * 6][25 - i] = 1; mapping2();
		map[5 + (h - 1) * 6][25 - i] = 0; map[2 + (h - 1) * 6][25 - i] = 0; map[1 + (h - 1) * 6][25 - i] = 0; map[5 + (h + 1) * 6][25 - i] = 0; map[2 + (h + 1) * 6][25 - i] = 0; map[1 + (h + 1) * 6][25 - i] = 0; delay(); mapping2();
	}
}

void obstacle1_2(int i, int h) {
	if (i>0) {
		map[5 + (h - 1) * 6][25 - i] = 1; map[4 + (h - 1) * 6][25 - i] = 1; map[1 + (h - 1) * 6][25 - i] = 1; mapping2();
		map[5 + (h - 1) * 6][25 - i] = 0; map[4 + (h - 1) * 6][25 - i] = 0; map[1 + (h - 1) * 6][25 - i] = 0; delay(); mapping2();
	}
}
void obstacle1_2_12(int i, int h) {
	if (i>0) {
		map[5 + (h - 1) * 6][25 - i] = 1; map[4 + (h - 1) * 6][25 - i] = 1; map[1 + (h - 1) * 6][25 - i] = 1; map[5 + h * 6][25 - i] = 1; map[4 + h * 6][25 - i] = 1; map[1 + h * 6][25 - i] = 1; mapping2();
		map[5 + (h - 1) * 6][25 - i] = 0; map[4 + (h - 1) * 6][25 - i] = 0; map[1 + (h - 1) * 6][25 - i] = 0; map[5 + h * 6][25 - i] = 0; map[4 + h * 6][25 - i] = 0; map[1 + h * 6][25 - i] = 0; delay(); mapping2();
	}
}
void obstacle1_2_13(int i, int h) {
	if (i>0) {
		map[5 + (h - 1) * 6][25 - i] = 1; map[4 + (h - 1) * 6][25 - i] = 1; map[1 + (h - 1) * 6][25 - i] = 1; map[5 + (h + 1) * 6][25 - i] = 1; map[4 + (h + 1) * 6][25 - i] = 1; map[1 + (h + 1) * 6][25 - i] = 1; mapping2();
		map[5 + (h - 1) * 6][25 - i] = 0; map[4 + (h - 1) * 6][25 - i] = 0; map[1 + (h - 1) * 6][25 - i] = 0; map[5 + (h + 1) * 6][25 - i] = 0; map[4 + (h + 1) * 6][25 - i] = 0; map[1 + (h + 1) * 6][25 - i] = 0; delay(); mapping2();
	}
}

void obstacle1_3(int i, int h) {
	if (i>0) {
		map[5 + (h - 1) * 6][25 - i] = 1; map[4 + (h - 1) * 6][25 - i] = 1; map[3 + (h - 1) * 6][25 - i] = 1; map[1 + (h - 1) * 6][25 - i] = 1; mapping2();
		map[5 + (h - 1) * 6][25 - i] = 0; map[4 + (h - 1) * 6][25 - i] = 0; map[3 + (h - 1) * 6][25 - i] = 0; map[1 + (h - 1) * 6][25 - i] = 0; delay(); mapping2();
	}
}
void obstacle1_3_12(int i, int h) {
	if (i>0) {
		map[5 + (h - 1) * 6][25 - i] = 1; map[4 + (h - 1) * 6][25 - i] = 1; map[3 + (h - 1) * 6][25 - i] = 1; map[1 + (h - 1) * 6][25 - i] = 1; map[5 + h * 6][25 - i] = 1; map[4 + h * 6][25 - i] = 1; map[3 + h * 6][25 - i] = 1; map[1 + h * 6][25 - i] = 1; mapping2();
		map[5 + (h - 1) * 6][25 - i] = 0; map[4 + (h - 1) * 6][25 - i] = 0; map[3 + (h - 1) * 6][25 - i] = 0; map[1 + (h - 1) * 6][25 - i] = 0; map[5 + h * 6][25 - i] = 0; map[4 + h * 6][25 - i] = 0; map[3 + h * 6][25 - i] = 0; map[1 + h * 6][25 - i] = 0; delay(); mapping2();
	}
}
void obstacle1_3_13(int i, int h) {
	if (i>0) {
		map[5 + (h - 1) * 6][25 - i] = 1; map[4 + (h - 1) * 6][25 - i] = 1; map[3 + (h - 1) * 6][25 - i] = 1; map[1 + (h - 1) * 6][25 - i] = 1; map[5 + (h + 1) * 6][25 - i] = 1; map[4 + (h + 1) * 6][25 - i] = 1; map[3 + (h + 1) * 6][25 - i] = 1; map[1 + (h + 1) * 6][25 - i] = 1; mapping2();
		map[5 + (h - 1) * 6][25 - i] = 0; map[4 + (h - 1) * 6][25 - i] = 0; map[3 + (h - 1) * 6][25 - i] = 0; map[1 + (h - 1) * 6][25 - i] = 0; map[5 + (h + 1) * 6][25 - i] = 0; map[4 + (h + 1) * 6][25 - i] = 0; map[3 + (h + 1) * 6][25 - i] = 0; map[1 + (h + 1) * 6][25 - i] = 0; delay(); mapping2();
	}
}

void obstacle3_1(int i, int h) {
	if (i>0) {
		map[5 + (h - 1) * 6][25 - i] = 1; map[3 + (h - 1) * 6][25 - i] = 1; map[2 + (h - 1) * 6][25 - i] = 1; map[1 + (h - 1) * 6][25 - i] = 1; mapping2();
		map[5 + (h - 1) * 6][25 - i] = 0; map[3 + (h - 1) * 6][25 - i] = 0; map[2 + (h - 1) * 6][25 - i] = 0; map[1 + (h - 1) * 6][25 - i] = 0; delay(); mapping2();
	}
}
void obstacle3_1_12(int i, int h) {
	if (i>0) {
		map[5 + (h - 1) * 6][25 - i] = 1; map[3 + (h - 1) * 6][25 - i] = 1; map[2 + (h - 1) * 6][25 - i] = 1; map[1 + (h - 1) * 6][25 - i] = 1; map[5 + h * 6][25 - i] = 1; map[3 + h * 6][25 - i] = 1; map[2 + h * 6][25 - i] = 1; map[1 + h * 6][25 - i] = 1; mapping2();
		map[5 + (h - 1) * 6][25 - i] = 0; map[3 + (h - 1) * 6][25 - i] = 0; map[2 + (h - 1) * 6][25 - i] = 0; map[1 + (h - 1) * 6][25 - i] = 0; map[5 + h * 6][25 - i] = 0; map[3 + h * 6][25 - i] = 0; map[2 + h * 6][25 - i] = 0; map[1 + h * 6][25 - i] = 0; delay(); mapping2();
	}
}
void obstacle3_1_13(int i, int h) {
	if (i>0) {
		map[5 + (h - 1) * 6][25 - i] = 1; map[3 + (h - 1) * 6][25 - i] = 1; map[2 + (h - 1) * 6][25 - i] = 1; map[1 + (h - 1) * 6][25 - i] = 1; map[5 + (h + 1) * 6][25 - i] = 1; map[3 + (h + 1) * 6][25 - i] = 1; map[2 + (h + 1) * 6][25 - i] = 1; map[1 + (h + 1) * 6][25 - i] = 1; mapping2();
		map[5 + (h - 1) * 6][25 - i] = 0; map[3 + (h - 1) * 6][25 - i] = 0; map[2 + (h - 1) * 6][25 - i] = 0; map[1 + (h - 1) * 6][25 - i] = 0; map[5 + (h + 1) * 6][25 - i] = 0; map[3 + (h + 1) * 6][25 - i] = 0; map[2 + (h + 1) * 6][25 - i] = 0; map[1 + (h + 1) * 6][25 - i] = 0; delay(); mapping2();
	}
}

int main() {
	unsigned char key, key2, exitkey, Levelupkey;
	int a, b, op, score; // a�� ù��°ȭ�� ����Ű, b�� �ι�°ȭ�� ����Ű.
	int i = 0, j = 0, r, h, qr = 0;
	char cmd[100];
	sprintf(cmd, "mode con cols=%d lines=%d", 75, 34); system(cmd);
	srand(time(NULL));
	textcolor(WHITE, BLACK);removecursor();
	firstscreen(); Sleep(2000);
	while (1) { // ù��°ȭ�� -> �ι�°ȭ��
	firstscreen_1(); Sleep(500); 
	firstscreen_2(); Sleep(500);
	if (_kbhit()) {
		a = getch();
		if (a != NULL) { 
			cls(); 
			secondscreen();break; 
			} // ���ӹ��ȭ�麸���� �ƹ�Ű�� �Է�.
		}
	}
	while (1){ // �ι�°ȭ�� -> ����ȭ��.
	if (_kbhit()) {
		b = getch();
		if (b == 13) { 
			secondscreen_start(); break; 
			} // ���ӽ����Ϸ��� EnterŰ�� �Է��ϼ���.
		}
	}
	while (1) {
		i = 0, op = 0, score = 0;
		cls(); mapbase(); mapping(); scoreprint(score); keyprint(1);
		while (1) {
			if (score<5) {
				Levelcount(1);
				// r�� ��ֹ� ���� h�� ����(1����,2����,3����,4����, 1 2���� , 1 3���� ,1 4���� ,2 3���� ,2 4���� ,3 4���� ,1 3���� ,2 4���� ��)
				r = rand() % 3 + 1; h = rand() % 9 + 1;
				while (1){
					if (r == 1) {  // �Ʒ��� 1ĭ¥������ֹ�
						if (h == 1) { //1����
							key = 0; i = i % 25; 
							obstacle0_1(i, h); i++; 
							if (i == 23) { // Ű�ȴ������� ����. 
								if (key == 0){ op = 1; break; } }
							if (_kbhit()) {
								key = _getch();
								if (key == 'a') {
									if (i == 16 || i == 22) {
										jump0_1(i - 1, h); op = 1; i = i + 7; break; }
									else { 
										if (i >= 17 && i<22) { 
											jump0_1(i - 1, h); score++; scoreprint(score); i = i + 7; } 
										else {
											jump0_1(i - 1, h); i = i + 7; } 
									} 
								} 
							}
							if (i >= 25)break;
						}
						if (h == 2) { //2����
							key = 0; i = i % 25; 
							obstacle0_1(i, h); i++; 
							if (i == 23) {
								if (key == 0) { op = 1; break; } }
							if (_kbhit()) {
								key = _getch(); 
								if (key == 'd') {
									if (i == 16 || i == 22) {
										jump0_1(i - 1, h); op = 1; i = i + 7; break; } 
									else { 
										if (i >= 17 && i<22) {
											jump0_1(i - 1, h); score++; scoreprint(score); i = i + 7; } 
										else { 
											jump0_1(i - 1, h); i = i + 7; } 
									} 
								} 
							}
							if (i >= 25)break;
						}
						if (h == 3) { //3����
							key = 0; i = i % 25; 
							obstacle0_1(i, h); i++; 
							if (i == 23) {
								if (key == 0) { op = 1; break; } }
							if (_kbhit()) {
								key = _getch();
								if (key == 'j') {
									if (i == 16 || i == 22) {
										jump0_1(i - 1, h); op = 1; i = i + 7; break; } 
									else {
										if (i >= 17 && i<22) { 
											jump0_1(i - 1, h); score++; scoreprint(score); i = i + 7; } 
										else { 
											jump0_1(i - 1, h); i = i + 7; } 
									} 
								} 
							}
							if (i >= 25)break;
						}
						if (h == 4) { //4����
							key = 0; i = i % 25; 
							obstacle0_1(i, h); i++; 
							if (i == 23) {
								if (key == 0) { op = 1; break; } }
							if (_kbhit()) {
								key = _getch();
								if (key == 'l') {
									if (i == 16 || i == 22) {
										jump0_1(i - 1, h); op = 1; i = i + 7; break; }
									else { 
										if (i >= 17 && i<22) {
											jump0_1(i - 1, h); score++; scoreprint(score); i = i + 7; } 
										else {
											jump0_1(i - 1, h); i = i + 7; } 
									} 
								} 
							}
							if (i >= 25)break;
						}
						if (h == 5) { //1,2����
							key = 0; i = i % 25;
							obstacle0_1_12(i, h - 4); i++;
							if (i == 23) {
								if (key == 0) { op = 1; break; } }
							if (_kbhit()) {
								key = _getch(); key2 = _getch();
								if ((key == 'a' || key == 'd') && (key2 == 'd' || key2 == 'a')) { //1,2���� �Ѵ�����
									if (i == 16 || i == 22) {
										jump0_1_12(i - 1, h - 4); op = 1; i = i + 7; break; } 
									else {
											if (i >= 17 && i<22) {
												jump0_1_12(i - 1, h - 4); score++; scoreprint(score); i = i + 7; } 
											else {
												jump0_1_12(i - 1, h - 4); i = i + 7; } 
									} key = 0; key2 = 0; 
								}
								if (key == 'a' || key2 == 'a') { // 1,2���� �� 1����������
									if (i == 16 || i == 22) {
										jump0_1_12_1(i - 1, h - 4); op = 1; i = i + 7; break; } 
									else {
										if (i >= 17 && i<22) { // 1,2���� �� 2������ ����
											jump0_1_12_1(i - 1, h - 4); op = 1; i = i + 7; } 
										else {
											jump0_1_12_1(i - 1, h - 4); i = i + 7; } 
									} 
								}
								if (key == 'd' || key2 == 'd') {
									if (i == 16 || i == 22) {
										jump0_1_12_2(i - 1, h - 4); op = 1; i = i + 7; break; } 
									else {
										if (i >= 17 && i<22) {
											jump0_1_12_2(i - 1, h - 4); op = 1; i = i + 7; } 
										else {
											jump0_1_12_2(i - 1, h - 4); i = i + 7; } 
									} 
								}
							}if (i >= 25)break;
						} //h==5
						if (h == 6) { // 2,3����
							key = 0; i = i % 25; 
							obstacle0_1_12(i, h - 4); i++;
							if (i == 23) { if (key == 0) { op = 1; break; } }
							if (_kbhit()) {
								key = _getch(); key2 = _getch();
								if ((key == 'd' || key == 'j') && (key2 == 'j' || key2 == 'd')) {//2,3������ �Ѵ�����
									if (i == 16 || i == 22) {
										jump0_1_12(i - 1, h - 4); op = 1; i = i + 7; break; }
									else { 
										if (i >= 17 && i<22) {
										jump0_1_12(i - 1, h - 4); score++; scoreprint(score); i = i + 7; } 
									else { 
										jump0_1_12(i - 1, h - 4); i = i + 7; } 
									} key = 0; key2 = 0; 
								}
								if (key == 'd' || key2 == 'd') { // 2,3������ 2������ ����
									if (i == 16 || i == 22) {
										jump0_1_12_1(i - 1, h - 4); op = 1; i = i + 7; break; } 
									else {
										if (i >= 17 && i<22) {
											jump0_1_12_1(i - 1, h - 4); op = 1; i = i + 7; }
										else {
												jump0_1_12_1(i - 1, h - 4); i = i + 7; } 
									} 
								}
								if (key == 'j' || key2 == 'j') { //2,3���� �� 3����������
									if (i == 16 || i == 22) {
										jump0_1_12_2(i - 1, h - 4); op = 1; i = i + 7; break; } 
									else {
										if (i >= 17 && i<22) {
											jump0_1_12_2(i - 1, h - 4); op = 1; i = i + 7; } 
										else {
											jump0_1_12_2(i - 1, h - 4); i = i + 7; } 
									} 
								}
							}if (i >= 25)break;
						} //h==6
						if (h == 7) { // 3,4����
							key = 0; i = i % 25; 
							obstacle0_1_12(i, h - 4); i++; 
							if (i == 23) {
								if (key == 0) { op = 1; break; } }
							if (_kbhit()) {
								key = _getch(); key2 = _getch();
								if ((key == 'j' || key == 'l') && (key2 == 'l' || key2 == 'j')) {// 3,4���� �� 3,4���� ����
									if (i == 16 || i == 22) {
										jump0_1_12(i - 1, h - 4); op = 1; i = i + 7; break; }
									else {
										if (i >= 17 && i<22) {
											jump0_1_12(i - 1, h - 4); score++; scoreprint(score); i = i + 7; }
										else {
											jump0_1_12(i - 1, h - 4); i = i + 7; } 
									} key = 0; key2 = 0; 
								}
								if (key == 'j' || key2 == 'j') { // 3,4������ 3������ ����
									if (i == 16 || i == 22) {
										jump0_1_12_1(i - 1, h - 4); op = 1; i = i + 7; break; } 
									else {
										if (i >= 17 && i<22) {
											jump0_1_12_1(i - 1, h - 4); op = 1; i = i + 7; } 
										else {
											jump0_1_12_1(i - 1, h - 4); i = i + 7; } 
									} 
								}
								if (key == 'l' || key2 == 'l') { // 3,4 ������ 4������ ����
									if (i == 16 || i == 22) {
										jump0_1_12_2(i - 1, h - 4); op = 1; i = i + 7; break; }
									else {
										if (i >= 17 && i<22) {
											jump0_1_12_2(i - 1, h - 4); op = 1; i = i + 7; }
										else {
											jump0_1_12_2(i - 1, h - 4); i = i + 7; } 
									} 
								}
							}if (i >= 25)break;
						}//h==7
						if (h == 8) { // 1,3����
							key = 0; i = i % 25; 
							obstacle0_1_13(i, h - 7); i++; 
							if (i == 23) { 
								if (key == 0) { op = 1; break; } }
							if (_kbhit()) {
								key = _getch(); key2 = _getch();
								if ((key == 'a' || key == 'j') && (key2 == 'j' || key2 == 'a')) { // 1,3������ 1,3���� �Ѵ�����
									if (i == 16 || i == 22) {
										jump0_1_13(i - 1, h - 7); op = 1; i = i + 7; break; } 
									else { 
										if (i >= 17 && i<22) { 
											jump0_1_13(i - 1, h - 7); score++; scoreprint(score); i = i + 7; } 
										else {
											jump0_1_13(i - 1, h - 7); i = i + 7; } 
									} key = 0; key2 = 0; 
								}
								if (key == 'a' || key2 == 'a') {  // 1,3������ 1����������
									if (i == 16 || i == 22) { 
										jump0_1_13_1(i - 1, h - 7); op = 1; i = i + 7; break; } 
									else { 
										if (i >= 17 && i<22) { 
											jump0_1_13_1(i - 1, h - 7); op = 1; i = i + 7; } 
										else { 
											jump0_1_13_1(i - 1, h - 7); i = i + 7; } 
									} 
								}
								if (key == 'j' || key2 == 'j') { // 1,3������ 3������ ����
									if (i == 16 || i == 22) {
										jump0_1_13_2(i - 1, h - 7); op = 1; i = i + 7; break; } 
									else { 
										if (i >= 17 && i<22) { 
											jump0_1_13_2(i - 1, h - 7); op = 1; i = i + 7; }
										else { 
											jump0_1_13_2(i - 1, h - 7); i = i + 7; } 
									} 
								}
							}if (i >= 25)break;
						} // h==8
						if (h == 9) {//2,4����
							key = 0; i = i % 25; 
							obstacle0_1_13(i, h - 7); i++; 
							if (i == 23) { 
								if (key == 0) { op = 1; break; } }
							if (_kbhit()) {
								key = _getch(); key2 = _getch();
								if ((key == 'd' || key == 'l') && (key2 == 'l' || key2 == 'd')) { // 2,4������ 2,4���� ����
									if (i == 16 || i == 22) {
										jump0_1_13(i - 1, h - 7); op = 1; i = i + 7; break; }
									else { 
										if (i >= 17 && i<22) { 
											jump0_1_12(i - 1, h - 7); score++; scoreprint(score); i = i + 7; } 
										else { 
											jump0_1_13(i - 1, h - 7); i = i + 7; } 
									} key = 0; key2 = 0; 
								}
								if (key == 'd' || key2 == 'd') { if (i == 16 || i == 22) { // 2,4������ 2������ ����
									jump0_1_13_1(i - 1, h - 7); op = 1; i = i + 7; break; }
								else { 
									if (i >= 17 && i<22) {
										jump0_1_13_1(i - 1, h - 7); op = 1; i = i + 7; } 
									else { 
										jump0_1_13_1(i - 1, h - 7); i = i + 7; } 
									} 
								}
								if (key == 'l' || key2 == 'l') { // 2,4������ 4������ ����
									if (i == 16 || i == 22) {
										jump0_1_13_2(i - 1, h - 7); op = 1; i = i + 7; break; }
									else {
										if (i >= 17 && i<22) {
											jump0_1_13_2(i - 1, h - 7); op = 1; i = i + 7; }
										else {
											jump0_1_13_2(i - 1, h - 7); i = i + 7; } 
									} 
								}
							}if (i >= 25)break;
						} //h==9;
					}//r==1
					if (r == 2) {  // �Ʒ��� 2ĭ¥�� ��ֹ�
						if (h == 1) {
							key = 0; i = i % 25; obstacle0_2(i, h); i++; if (i == 23) { if (key == 0) { op = 1; break; } }
							if (_kbhit()) { key = _getch(); if (key == 'a') { if (i == 17 || i == 16 || i == 15 || i == 22) { jump0_2(i - 1, h); op = 1; i = i + 7; break; } else { if (i >= 18 && i<22) { jump0_2(i - 1, h); score++; scoreprint(score); i = i + 7; } else { jump0_2(i - 1, h); i = i + 7; } } } }
							if (i >= 25)break;
						}
						if (h == 2) {
							key = 0; i = i % 25; obstacle0_2(i, h); i++; if (i == 23) { if (key == 0) { op = 1; break; } }
							if (_kbhit()) { key = _getch(); if (key == 'd') { if (i == 17 || i == 16 || i == 15 || i == 22) { jump0_2(i - 1, h); op = 1; i = i + 7; break; } else { if (i >= 18 && i<22) { jump0_2(i - 1, h); score++; scoreprint(score); i = i + 7; } else { jump0_2(i - 1, h); i = i + 7; } } } }
							if (i >= 25)break;
						}
						if (h == 3) {
							key = 0; i = i % 25; obstacle0_2(i, h); i++; if (i == 23) { if (key == 0) { op = 1; break; } }
							if (_kbhit()) { key = _getch(); if (key == 'j') { if (i == 17 || i == 16 || i == 15 || i == 22) { jump0_2(i - 1, h); op = 1; i = i + 7; break; } else { if (i >= 18 && i<22) { jump0_2(i - 1, h); score++; scoreprint(score); i = i + 7; } else { jump0_2(i - 1, h); i = i + 7; } } } }
							if (i >= 25)break;
						}
						if (h == 4) {
							key = 0; i = i % 25; obstacle0_2(i, h); i++; if (i == 23) { if (key == 0) { op = 1; break; } }
							if (_kbhit()) { key = _getch(); if (key == 'l') { if (i == 17 || i == 16 || i == 15 || i == 22) { jump0_2(i - 1, h); op = 1; i = i + 7; break; } else { if (i >= 18 && i<22) { jump0_2(i - 1, h); score++; scoreprint(score); i = i + 7; } else { jump0_2(i - 1, h); i = i + 7; } } } }
							if (i >= 25)break;
						}
						if (h == 5) {
							key = 0; i = i % 25; obstacle0_2_12(i, h - 4); i++; if (i == 23) { if (key == 0) { op = 1; break; } }
							if (_kbhit()) {
								key = _getch(); key2 = _getch();
								if ((key == 'a' || key == 'd') && (key2 == 'd' || key2 == 'a')) { if (i == 17 || i == 16 || i == 15 || i == 22) { jump0_2_12(i - 1, h - 4); op = 1; i = i + 7; break; } else { if (i >= 18 && i<22) { jump0_2_12(i - 1, h - 4); score++; scoreprint(score); i = i + 7; } else { jump0_2_12(i - 1, h - 4); i = i + 7; } } key = 0; key2 = 0; }
								if (key == 'a' || key2 == 'a') { if (i == 17 || i == 16 || i == 15 || i == 22) { jump0_2_12_1(i - 1, h - 4); op = 1; i = i + 7; break; } else { if (i >= 18 && i<22) { jump0_2_12_1(i - 1, h - 4); op = 1; i = i + 7; break; } else { jump0_2_12_1(i - 1, h - 4); i = i + 7; } } }
								if (key == 'd' || key2 == 'd') { if (i == 17 || i == 16 || i == 15 || i == 22) { jump0_2_12_2(i - 1, h - 4); op = 1; i = i + 7; break; } else { if (i >= 18 && i<22) { jump0_2_12_2(i - 1, h - 4); op = 1; i = i + 7; break; } else { jump0_2_12_2(i - 1, h - 4); i = i + 7; } } }
							}if (i >= 25)break;
						}
						if (h == 6) {
							key = 0; i = i % 25; obstacle0_2_12(i, h - 4); i++; if (i == 23) { if (key == 0) { op = 1; break; } }
							if (_kbhit()) {
								key = _getch(); key2 = _getch();
								if ((key == 'd' || key == 'j') && (key2 == 'j' || key2 == 'd')) { if (i == 17 || i == 16 || i == 15 || i == 22) { jump0_2_12(i - 1, h - 4); op = 1; i = i + 7; break; } else { if (i >= 18 && i<22) { jump0_2_12(i - 1, h - 4); score++; scoreprint(score); i = i + 7; } else { jump0_2_12(i - 1, h - 4); i = i + 7; } } key = 0; key2 = 0; }
								if (key == 'd' || key2 == 'd') { if (i == 17 || i == 16 || i == 15 || i == 22) { jump0_2_12_1(i - 1, h - 4); op = 1; i = i + 7; break; } else { if (i >= 18 && i<22) { jump0_2_12_1(i - 1, h - 4); op = 1; i = i + 7; break; } else { jump0_2_12_1(i - 1, h - 4); i = i + 7; } } }
								if (key == 'j' || key2 == 'j') { if (i == 17 || i == 16 || i == 15 || i == 22) { jump0_2_12_2(i - 1, h - 4); op = 1; i = i + 7; break; } else { if (i >= 18 && i<22) { jump0_2_12_2(i - 1, h - 4); op = 1; i = i + 7; break; } else { jump0_2_12_2(i - 1, h - 4); i = i + 7; } } }
							}if (i >= 25)break;
						}
						if (h == 7) {
							key = 0; i = i % 25; obstacle0_2_12(i, h - 4); i++; if (i == 23) { if (key == 0) { op = 1; break; } }
							if (_kbhit()) {
								key = _getch(); key2 = _getch();
								if ((key == 'j' || key == 'l') && (key2 == 'l' || key2 == 'j')) { if (i == 17 || i == 16 || i == 15 || i == 22) { jump0_2_12(i - 1, h - 4); op = 1; i = i + 7; break; } else { if (i >= 18 && i<22) { jump0_2_12(i - 1, h - 4); score++; scoreprint(score); i = i + 7; } else { jump0_2_12(i - 1, h - 4); i = i + 7; } } key = 0; key2 = 0; }
								if (key == 'j' || key2 == 'j') { if (i == 17 || i == 16 || i == 15 || i == 22) { jump0_2_12_1(i - 1, h - 4); op = 1; i = i + 7; break; } else { if (i >= 18 && i<22) { jump0_2_12_1(i - 1, h - 4); op = 1; i = i + 7; break; } else { jump0_2_12_1(i - 1, h - 4); i = i + 7; } } }
								if (key == 'l' || key2 == 'l') { if (i == 17 || i == 16 || i == 15 || i == 22) { jump0_2_12_2(i - 1, h - 4); op = 1; i = i + 7; break; } else { if (i >= 18 && i<22) { jump0_2_12_2(i - 1, h - 4); op = 1; i = i + 7; break; } else { jump0_2_12_2(i - 1, h - 4); i = i + 7; } } }
							}if (i >= 25)break;
						}
						if (h == 8) {
							key = 0; i = i % 25; obstacle0_2_13(i, h - 7); i++; if (i == 23) { if (key == 0) { op = 1; break; } }
							if (_kbhit()) {
								key = _getch(); key2 = _getch();
								if ((key == 'a' || key == 'j') && (key2 == 'j' || key2 == 'a')) { if (i == 17 || i == 16 || i == 15 || i == 22) { jump0_2_13(i - 1, h - 7); op = 1; i = i + 7; break; } else { if (i >= 18 && i<22) { jump0_2_13(i - 1, h - 7); score++; scoreprint(score); i = i + 7; } else { jump0_2_13(i - 1, h - 7); i = i + 7; } } key = 0; key2 = 0; }
								if (key == 'a' || key2 == 'a') { if (i == 17 || i == 16 || i == 15 || i == 22) { jump0_2_13_1(i - 1, h - 7); op = 1; i = i + 7; break; } else { if (i >= 18 && i<22) { jump0_2_13_1(i - 1, h - 7); op = 1; i = i + 7; break; } else { jump0_2_13_1(i - 1, h - 7); i = i + 7; } } }
								if (key == 'j' || key2 == 'j') { if (i == 17 || i == 16 || i == 15 || i == 22) { jump0_2_13_2(i - 1, h - 7); op = 1; i = i + 7; break; } else { if (i >= 18 && i<22) { jump0_2_13_2(i - 1, h - 7); op = 1; i = i + 7; break; } else { jump0_2_13_2(i - 1, h - 7); i = i + 7; } } }
							}if (i >= 25)break;
						}
						if (h == 9) {
							key = 0; i = i % 25; obstacle0_2_13(i, h - 7); i++; if (i == 23) { if (key == 0) { op = 1; break; } }
							if (_kbhit()) {
								key = _getch(); key2 = _getch();
								if ((key == 'd' || key == 'l') && (key2 == 'l' || key2 == 'd')) { if (i == 17 || i == 16 || i == 15 || i == 22) { jump0_2_13(i - 1, h - 7); op = 1; i = i + 7; break; } else { if (i >= 18 && i<22) { jump0_2_13(i - 1, h - 7); score++; scoreprint(score); i = i + 7; } else { jump0_2_13(i - 1, h - 7); i = i + 7; } } key = 0; key2 = 0; }
								if (key == 'd' || key2 == 'd') { if (i == 17 || i == 16 || i == 15 || i == 22) { jump0_2_13_1(i - 1, h - 7); op = 1; i = i + 7; break; } else { if (i >= 18 && i<22) { jump0_2_13_1(i - 1, h - 7); op = 1; i = i + 7; break; } else { jump0_2_13_1(i - 1, h - 7); i = i + 7; } } }
								if (key == 'l' || key2 == 'l') { if (i == 17 || i == 16 || i == 15 || i == 22) { jump0_2_13_2(i - 1, h - 7); op = 1; i = i + 7; break; } else { if (i >= 18 && i<22) { jump0_2_13_2(i - 1, h - 7); op = 1; i = i + 7; break; } else { jump0_2_13_2(i - 1, h - 7); i = i + 7; } } }
							}if (i >= 25)break;
						}
					}//r==2
					if (r == 3) {  // ������ 3ĭ¥������ֹ� 
						if (h == 1) {
							key = 0; i = i % 25; obstacle3_0(i, h); i++; if (i == 25) { if (key == 0) { score++; scoreprint(score); break; } }
							if (_kbhit()) { key = _getch(); if (key == 'a') { if (i == 20 || i == 19 || i == 18) { jump3_0(i - 1, h); op = 1; i = i + 7; break; } else { jump3_0(i - 1, h); i = i + 7; } } }
							if (i >= 25)break;
						}
						if (h == 2) {
							key = 0; i = i % 25; obstacle3_0(i, h); i++; if (i == 25) { if (key == 0) { score++; scoreprint(score); break; } }
							if (_kbhit()) { key = _getch(); if (key == 'd') { if (i == 20 || i == 19 || i == 18) { jump3_0(i - 1, h); op = 1; i = i + 7; break; } else { jump3_0(i - 1, h);  i = i + 7; } } }
							if (i >= 25)break;
						}
						if (h == 3) {
							key = 0; i = i % 25; obstacle3_0(i, h); i++; if (i == 25) { if (key == 0) { score++; scoreprint(score); break; } }
							if (_kbhit()) { key = _getch(); if (key == 'j') { if (i == 20 || i == 19 || i == 18) { jump3_0(i - 1, h); op = 1; i = i + 7; break; } else { jump3_0(i - 1, h); i = i + 7; } } }
							if (i >= 25)break;
						}
						if (h == 4) {
							key = 0; i = i % 25; obstacle3_0(i, h); i++; if (i == 25) { if (key == 0) { score++; scoreprint(score); break; } }
							if (_kbhit()) { key = _getch(); if (key == 'l') { if (i == 20 || i == 19 || i == 18) { jump3_0(i - 1, h); op = 1; i = i + 7; break; } else { jump3_0(i - 1, h); i = i + 7; } } }
							if (i >= 25)break;
						}
						if (h == 5) {
							key = 0; i = i % 25; obstacle3_0_12(i, h - 4); i++; if (i == 25) { if (key == 0) { score++; scoreprint(score); break; } }
							if (_kbhit()) {
								key = _getch(); key2 = _getch();
								if ((key == 'a' || key == 'd') && (key2 == 'd' || key2 == 'a')) { if (i == 20 || i == 19 || i == 18) { jump3_0_12(i - 1, h - 4); op = 1; i = i + 7; break; } else { jump3_0_12(i - 1, h - 4); i = i + 7; } key = 0; key2 = 0; }
								if (key == 'a' || key2 == 'a') { if (i == 20 || i == 19 || i == 18) { jump3_0_12_1(i - 1, h - 4); op = 1; i = i + 7; break; } else { jump3_0_12_1(i - 1, h - 4); i = i + 7; } }
								if (key == 'd' || key2 == 'd') { if (i == 20 || i == 19 || i == 18) { jump3_0_12_2(i - 1, h - 4); op = 1; i = i + 7; break; } else { jump3_0_12_2(i - 1, h - 4); i = i + 7; } }
							}if (i >= 25)break;
						}
						if (h == 6) {
							key = 0; i = i % 25; obstacle3_0_12(i, h - 4); i++; if (i == 25) { if (key == 0) { score++; scoreprint(score); break; } }
							if (_kbhit()) {
								key = _getch(); key2 = _getch();
								if ((key == 'd' || key == 'j') && (key2 == 'j' || key2 == 'd')) { if (i == 20 || i == 19 || i == 18) { jump3_0_12(i - 1, h - 4); op = 1; i = i + 7; break; } else { jump3_0_12(i - 1, h - 4); i = i + 7; } key = 0; key2 = 0; }
								if (key == 'd' || key2 == 'd') { if (i == 20 || i == 19 || i == 18) { jump3_0_12_1(i - 1, h - 4); op = 1; i = i + 7; break; } else { jump3_0_12_1(i - 1, h - 4); i = i + 7; } }
								if (key == 'j' || key2 == 'j') { if (i == 20 || i == 19 || i == 18) { jump3_0_12_2(i - 1, h - 4); op = 1; i = i + 7; break; } else { jump3_0_12_2(i - 1, h - 4); i = i + 7; } }
							}if (i >= 25)break;
						}
						if (h == 7) {
							key = 0; i = i % 25; obstacle3_0_12(i, h - 4); i++; if (i == 25) { if (key == 0) { score++; scoreprint(score); break; } }
							if (_kbhit()) {
								key = _getch(); key2 = _getch();
								if ((key == 'j' || key == 'l') && (key2 == 'l' || key2 == 'j')) { if (i == 20 || i == 19 || i == 18) { jump3_0_12(i - 1, h - 4); op = 1; i = i + 7; break; } else { jump3_0_12(i - 1, h - 4); i = i + 7; } key = 0; key2 = 0; }
								if (key == 'j' || key2 == 'j') { if (i == 20 || i == 19 || i == 18) { jump3_0_12_1(i - 1, h - 4); op = 1; i = i + 7; break; } else { jump3_0_12_1(i - 1, h - 4); i = i + 7; } }
								if (key == 'l' || key2 == 'l') { if (i == 20 || i == 19 || i == 18) { jump3_0_12_2(i - 1, h - 4); op = 1; i = i + 7; break; } else { jump3_0_12_2(i - 1, h - 4); i = i + 7; } }
							}if (i >= 25)break;
						}
						if (h == 8) {
							key = 0; i = i % 25; obstacle3_0_13(i, h - 7); i++; if (i == 25) { if (key == 0) { score++; scoreprint(score); break; } }
							if (_kbhit()) {
								key = _getch(); key2 = _getch();
								if ((key == 'a' || key == 'j') && (key2 == 'j' || key2 == 'a')) { if (i == 20 || i == 19 || i == 18) { jump3_0_13(i - 1, h - 7); op = 1; i = i + 7; break; } else { jump3_0_13(i - 1, h - 7); i = i + 7; } key = 0; key2 = 0; }
								if (key == 'a' || key2 == 'a') { if (i == 20 || i == 19 || i == 18) { jump3_0_13_1(i - 1, h - 7); op = 1; i = i + 7; break; } else { jump3_0_13_1(i - 1, h - 7); i = i + 7; } }
								if (key == 'j' || key2 == 'j') { if (i == 20 || i == 19 || i == 18) { jump3_0_13_2(i - 1, h - 7); op = 1; i = i + 7; break; } else { jump3_0_13_2(i - 1, h - 7); i = i + 7; } }
							}if (i >= 25)break;
						}
						if (h == 9) {
							key = 0; i = i % 25; obstacle3_0_13(i, h - 7); i++; if (i == 25) { if (key == 0) { score++; scoreprint(score); break; } }
							if (_kbhit()) {
								key = _getch(); key2 = _getch();
								if ((key == 'd' || key == 'l') && (key2 == 'l' || key2 == 'd')) { if (i == 20 || i == 19 || i == 18) { jump3_0_13(i - 1, h - 7); op = 1; i = i + 7; break; } else { jump3_0_13(i - 1, h - 7); i = i + 7; } key = 0; key2 = 0; }
								if (key == 'd' || key2 == 'd') { if (i == 20 || i == 19 || i == 18) { jump3_0_13_1(i - 1, h - 7); op = 1; i = i + 7; break; } else { jump3_0_13_1(i - 1, h - 7); i = i + 7; } }
								if (key == 'l' || key2 == 'l') { if (i == 20 || i == 19 || i == 18) { jump3_0_13_2(i - 1, h - 7); op = 1; i = i + 7; break; } else { jump3_0_13_2(i - 1, h - 7); i = i + 7; } }
							}if (i >= 25)break;
						}
					}//r==3
				}//while ��ֹ��ݺ�
				if (op == 1) break;
			}//score<=3
			if (score >= 5 && score<10) {
				if (score == 5) {
					cls(); stageclear_screen(); Levelupkey = _getch(); if (_kbhit()) { fflush(stdin); Levelupkey = _getch(); if (Levelupkey == '1')cls(); }
					cls(); mapbase(); mapping();  scoreprint(score); Levelcount(2); keyprint(2);
				}
				r = rand() % 3 + 4; h = rand() % 9 + 1;
				while (1) {
					if (r == 4) {  // �Ʒ���ĭ ������ĭ
						if (h == 1) {
							key = 0; i = i % 25; obstacle1_1(i, h); i++; if (i == 23) { if (key == 0) { op = 1; break; } }
							if (_kbhit()) { key = _getch(); if (key == 'd') { if (i == 16 || i == 22) { jump1_1(i - 1, h); op = 1; i = i + 7; break; } else { if (i >= 17 && i<22) { jump1_1(i - 1, h); score++; scoreprint(score); i = i + 7; } else { jump1_1(i - 1, h); i = i + 7; } } } }
							if (i >= 25)break;
						}
						if (h == 2) {
							key = 0; i = i % 25; obstacle1_1(i, h); i++; if (i == 23) { if (key == 0) { op = 1; break; } }
							if (_kbhit()) { key = _getch(); if (key == 'j') { if (i == 16 || i == 22) { jump1_1(i - 1, h); op = 1; i = i + 7; break; } else { if (i >= 17 && i<22) { jump1_1(i - 1, h); score++; scoreprint(score); i = i + 7; } else { jump1_1(i - 1, h); i = i + 7; } } } }
							if (i >= 25)break;
						}
						if (h == 3) {
							key = 0; i = i % 25; obstacle1_1(i, h); i++; if (i == 23) { if (key == 0) { op = 1; break; } }
							if (_kbhit()) { key = _getch(); if (key == 'l') { if (i == 16 || i == 22) { jump1_1(i - 1, h); op = 1; i = i + 7; break; } else { if (i >= 17 && i<22) { jump1_1(i - 1, h); score++; scoreprint(score); i = i + 7; } else { jump1_1(i - 1, h); i = i + 7; } } } }
							if (i >= 25)break;
						}
						if (h == 4) {
							key = 0; i = i % 25; obstacle1_1(i, h); i++; if (i == 23) { if (key == 0) { op = 1; break; } }
							if (_kbhit()) { key = _getch(); if (key == 'a') { if (i == 16 || i == 22) { jump1_1(i - 1, h); op = 1; i = i + 7; break; } else { if (i >= 17 && i<22) { jump1_1(i - 1, h); score++; scoreprint(score); i = i + 7; } else { jump1_1(i - 1, h); i = i + 7; } } } }
							if (i >= 25)break;
						}
						if (h == 5) {
							key = 0; i = i % 25; obstacle1_1_12(i, h - 4); i++; if (i == 23) { if (key == 0) { op = 1; break; } }
							if (_kbhit()) {
								key = _getch(); key2 = _getch();
								if ((key == 'd' || key == 'j') && (key2 == 'j' || key2 == 'd')) { if (i == 16 || i == 22) { jump1_1_12(i - 1, h - 4); op = 1; i = i + 7; break; } else { if (i >= 17 && i<22) { jump1_1_12(i - 1, h - 4); score++; scoreprint(score); i = i + 7; } else { jump1_1_12(i - 1, h - 4); i = i + 7; } } key = 0; key2 = 0; }
								if (key == 'd' || key2 == 'd') { if (i == 16 || i == 22) { jump1_1_12_1(i - 1, h - 4); op = 1; i = i + 7; break; } else { if (i >= 17 && i<22) { jump1_1_12_1(i - 1, h - 4); op = 1; i = i + 7; break; } else { jump1_1_12_1(i - 1, h - 4); i = i + 7; } } }
								if (key == 'j' || key2 == 'j') { if (i == 16 || i == 22) { jump1_1_12_2(i - 1, h - 4); op = 1; i = i + 7; break; } else { if (i >= 17 && i<22) { jump1_1_12_2(i - 1, h - 4); op = 1; i = i + 7; break; } else { jump1_1_12_2(i - 1, h - 4); i = i + 7; } } }
							}if (i >= 25)break;
						}
						if (h == 6) {
							key = 0; i = i % 25; obstacle1_1_12(i, h - 4); i++; if (i == 23) { if (key == 0) { op = 1; break; } }
							if (_kbhit()) {
								key = _getch(); key2 = _getch();
								if ((key == 'j' || key == 'l') && (key2 == 'l' || key2 == 'j')) { if (i == 16 || i == 22) { jump1_1_12(i - 1, h - 4); op = 1; i = i + 7; break; } else { if (i >= 17 && i<22) { jump1_1_12(i - 1, h - 4); score++; scoreprint(score); i = i + 7; } else { jump1_1_12(i - 1, h - 4); i = i + 7; } } key = 0; key2 = 0; }
								if (key == 'j' || key2 == 'j') { if (i == 16 || i == 22) { jump1_1_12_1(i - 1, h - 4); op = 1; i = i + 7; break; } else { if (i >= 17 && i<22) { jump1_1_12_1(i - 1, h - 4); op = 1; i = i + 7; break; } else { jump1_1_12_1(i - 1, h - 4); i = i + 7; } } }
								if (key == 'l' || key2 == 'l') { if (i == 16 || i == 22) { jump1_1_12_2(i - 1, h - 4); op = 1; i = i + 7; break; } else { if (i >= 17 && i<22) { jump1_1_12_2(i - 1, h - 4); op = 1; i = i + 7; break; } else { jump1_1_12_2(i - 1, h - 4); i = i + 7; } } }
							}if (i >= 25)break;
						}
						if (h == 7) {
							key = 0; i = i % 25; obstacle1_1_12(i, h - 4); i++; if (i == 23) { if (key == 0) { op = 1; break; } }
							if (_kbhit()) {
								key = _getch(); key2 = _getch();
								if ((key == 'l' || key == 'a') && (key2 == 'a' || key2 == 'l')) { if (i == 16 || i == 22) { jump1_1_12(i - 1, h - 4); op = 1; i = i + 7; break; } else { if (i >= 17 && i<22) { jump1_1_12(i - 1, h - 4); score++; scoreprint(score); i = i + 7; } else { jump1_1_12(i - 1, h - 4); i = i + 7; } } key = 0; key2 = 0; }
								if (key == 'l' || key2 == 'l') { if (i == 16 || i == 22) { jump1_1_12_1(i - 1, h - 4); op = 1; i = i + 7; break; } else { if (i >= 17 && i<22) { jump1_1_12_1(i - 1, h - 4); op = 1; i = i + 7; break; } else { jump1_1_12_1(i - 1, h - 4); i = i + 7; } } }
								if (key == 'a' || key2 == 'a') { if (i == 16 || i == 22) { jump1_1_12_2(i - 1, h - 4); op = 1; i = i + 7; break; } else { if (i >= 17 && i<22) { jump1_1_12_2(i - 1, h - 4); op = 1; i = i + 7; break; } else { jump1_1_12_2(i - 1, h - 4); i = i + 7; } } }
							}if (i >= 25)break;
						}
						if (h == 8) {
							key = 0; i = i % 25; obstacle1_1_13(i, h - 7); i++; if (i == 23) { if (key == 0) { op = 1; break; } }
							if (_kbhit()) {
								key = _getch(); key2 = _getch();
								if ((key == 'd' || key == 'l') && (key2 == 'l' || key2 == 'd')) { if (i == 16 || i == 22) { jump1_1_13(i - 1, h - 7); op = 1; i = i + 7; break; } else { if (i >= 17 && i<22) { jump1_1_13(i - 1, h - 7); score++; scoreprint(score); i = i + 7; } else { jump1_1_13(i - 1, h - 7); i = i + 7; } } key = 0; key2 = 0; }
								if (key == 'd' || key2 == 'd') { if (i == 16 || i == 22) { jump1_1_13_1(i - 1, h - 7); op = 1; i = i + 7; break; } else { if (i >= 17 && i<22) { jump1_1_13_1(i - 1, h - 7); op = 1; i = i + 7; break; } else { jump1_1_13_1(i - 1, h - 7); i = i + 7; } } }
								if (key == 'l' || key2 == 'l') { if (i == 16 || i == 22) { jump1_1_13_2(i - 1, h - 7); op = 1; i = i + 7; break; } else { if (i >= 17 && i<22) { jump1_1_13_2(i - 1, h - 7); op = 1; i = i + 7; break; } else { jump1_1_13_2(i - 1, h - 7); i = i + 7; } } }
							}if (i >= 25)break;
						}
						if (h == 9) {
							key = 0; i = i % 25; obstacle1_1_13(i, h - 7); i++; if (i == 23) { if (key == 0) { op = 1; break; } }
							if (_kbhit()) {
								key = _getch(); key2 = _getch();
								if ((key == 'j' || key == 'a') && (key2 == 'a' || key2 == 'j')) { if (i == 16 || i == 22) { jump1_1_13(i - 1, h - 7); op = 1; i = i + 7; break; } else { if (i >= 17 && i<22) { jump1_1_13(i - 1, h - 7); score++; scoreprint(score); i = i + 7; } else { jump1_1_13(i - 1, h - 7); i = i + 7; } } key = 0; key2 = 0; }
								if (key == 'j' || key2 == 'j') { if (i == 16 || i == 22) { jump1_1_13_1(i - 1, h - 7); op = 1; i = i + 7; break; } else { if (i >= 17 && i<22) { jump1_1_13_1(i - 1, h - 7); op = 1; i = i + 7; break; } else { jump1_1_13_1(i - 1, h - 7); i = i + 7; } } }
								if (key == 'a' || key2 == 'a') { if (i == 16 || i == 22) { jump1_1_13_2(i - 1, h - 7); op = 1; i = i + 7; break; } else { if (i >= 17 && i<22) { jump1_1_13_2(i - 1, h - 7); op = 1; i = i + 7; break; } else { jump1_1_13_2(i - 1, h - 7); i = i + 7; } } }
							}if (i >= 25)break;
						}
					} //r==4
					if (r == 5) {  // �Ʒ��� 2ĭ ������ 1ĭ
						if (h == 1) {
							key = 0; i = i % 25; obstacle1_2(i, h); i++; if (i == 23) { if (key == 0) { op = 1; break; } }
							if (_kbhit()) { key = _getch(); if (key == 'd') { if (i == 17 || i == 16 || i == 15 || i == 22) { jump1_2(i - 1, h); op = 1; i = i + 7; break; } else { if (i >= 18 && i<22) { jump1_2(i - 1, h); score++; scoreprint(score); i = i + 7; } else { jump1_2(i - 1, h); i = i + 7; } } } }
							if (i >= 25)break;
						}
						if (h == 2) {
							key = 0; i = i % 25; obstacle1_2(i, h); i++; if (i == 23) { if (key == 0) { op = 1; break; } }
							if (_kbhit()) { key = _getch(); if (key == 'j') { if (i == 17 || i == 16 || i == 15 || i == 22) { jump1_2(i - 1, h); op = 1; i = i + 7; break; } else { if (i >= 18 && i<22) { jump1_2(i - 1, h); score++; scoreprint(score); i = i + 7; } else { jump1_2(i - 1, h); i = i + 7; } } } }
							if (i >= 25)break;
						}
						if (h == 3) {
							key = 0; i = i % 25; obstacle1_2(i, h); i++; if (i == 23) { if (key == 0) { op = 1; break; } }
							if (_kbhit()) { key = _getch(); if (key == 'l') { if (i == 17 || i == 16 || i == 15 || i == 22) { jump1_2(i - 1, h); op = 1; i = i + 7; break; } else { if (i >= 18 && i<22) { jump1_2(i - 1, h); score++; scoreprint(score); i = i + 7; } else { jump1_2(i - 1, h); i = i + 7; } } } }
							if (i >= 25)break;
						}
						if (h == 4) {
							key = 0; i = i % 25; obstacle1_2(i, h); i++; if (i == 23) { if (key == 0) { op = 1; break; } }
							if (_kbhit()) { key = _getch(); if (key == 'a') { if (i == 17 || i == 16 || i == 15 || i == 22) { jump1_2(i - 1, h); op = 1; i = i + 7; break; } else { if (i >= 18 && i<22) { jump1_2(i - 1, h); score++; scoreprint(score); i = i + 7; } else { jump1_2(i - 1, h); i = i + 7; } } } }
							if (i >= 25)break;
						}
						if (h == 5) {
							key = 0; i = i % 25; obstacle1_2_12(i, h - 4); i++; if (i == 23) { if (key == 0) { op = 1; break; } }
							if (_kbhit()) {
								key = _getch(); key2 = _getch();
								if ((key == 'd' || key == 'j') && (key2 == 'j' || key2 == 'd')) { if (i == 17 || i == 16 || i == 15 || i == 22) { jump1_2_12(i - 1, h - 4); op = 1; i = i + 7; break; } else { if (i >= 18 && i<22) { jump1_2_12(i - 1, h - 4); score++; scoreprint(score); i = i + 7; } else { jump1_2_12(i - 1, h - 4); i = i + 7; } } key = 0; key2 = 0; }
								if (key == 'd' || key2 == 'd') { if (i == 17 || i == 16 || i == 15 || i == 22) { jump1_2_12_1(i - 1, h - 4); op = 1; i = i + 7; break; } else { if (i >= 18 && i<22) { jump1_2_12_1(i - 1, h - 4); op = 1; i = i + 7; break; } else { jump1_2_12_1(i - 1, h - 4); i = i + 7; } } }
								if (key == 'j' || key2 == 'j') { if (i == 17 || i == 16 || i == 15 || i == 22) { jump1_2_12_2(i - 1, h - 4); op = 1; i = i + 7; break; } else { if (i >= 18 && i<22) { jump1_2_12_2(i - 1, h - 4); op = 1; i = i + 7; break; } else { jump1_2_12_2(i - 1, h - 4); i = i + 7; } } }
							}if (i >= 25)break;
						}
						if (h == 6) {
							key = 0; i = i % 25; obstacle1_2_12(i, h - 4); i++; if (i == 23) { if (key == 0) { op = 1; break; } }
							if (_kbhit()) {
								key = _getch(); key2 = _getch();
								if ((key == 'j' || key == 'l') && (key2 == 'l' || key2 == 'j')) { if (i == 17 || i == 16 || i == 15 || i == 22) { jump1_2_12(i - 1, h - 4); op = 1; i = i + 7; break; } else { if (i >= 18 && i<22) { jump1_2_12(i - 1, h - 4); score++; scoreprint(score); i = i + 7; } else { jump1_2_12(i - 1, h - 4); i = i + 7; } } key = 0; key2 = 0; }
								if (key == 'j' || key2 == 'j') { if (i == 17 || i == 16 || i == 15 || i == 22) { jump1_2_12_1(i - 1, h - 4); op = 1; i = i + 7; break; } else { if (i >= 18 && i<22) { jump1_2_12_1(i - 1, h - 4); op = 1; i = i + 7; break; } else { jump1_2_12_1(i - 1, h - 4); i = i + 7; } } }
								if (key == 'l' || key2 == 'l') { if (i == 17 || i == 16 || i == 15 || i == 22) { jump1_2_12_2(i - 1, h - 4); op = 1; i = i + 7; break; } else { if (i >= 18 && i<22) { jump1_2_12_2(i - 1, h - 4); op = 1; i = i + 7; break; } else { jump1_2_12_2(i - 1, h - 4); i = i + 7; } } }
							}if (i >= 25)break;
						}
						if (h == 7) {
							key = 0; i = i % 25; obstacle1_2_12(i, h - 4); i++; if (i == 23) { if (key == 0) { op = 1; break; } }
							if (_kbhit()) {
								key = _getch(); key2 = _getch();
								if ((key == 'l' || key == 'a') && (key2 == 'a' || key2 == 'l')) { if (i == 17 || i == 16 || i == 15 || i == 22) { jump1_2_12(i - 1, h - 4); op = 1; i = i + 7; break; } else { if (i >= 18 && i<22) { jump1_2_12(i - 1, h - 4); score++; scoreprint(score); i = i + 7; } else { jump1_2_12(i - 1, h - 4); i = i + 7; } } key = 0; key2 = 0; }
								if (key == 'l' || key2 == 'l') { if (i == 17 || i == 16 || i == 15 || i == 22) { jump1_2_12_1(i - 1, h - 4); op = 1; i = i + 7; break; } else { if (i >= 18 && i<22) { jump1_2_12_1(i - 1, h - 4); op = 1; i = i + 7; break; } else { jump1_2_12_1(i - 1, h - 4); i = i + 7; } } }
								if (key == 'a' || key2 == 'a') { if (i == 17 || i == 16 || i == 15 || i == 22) { jump1_2_12_2(i - 1, h - 4); op = 1; i = i + 7; break; } else { if (i >= 18 && i<22) { jump1_2_12_2(i - 1, h - 4); op = 1; i = i + 7; break; } else { jump1_2_12_2(i - 1, h - 4); i = i + 7; } } }
							}if (i >= 25)break;
						}
						if (h == 8) {
							key = 0; i = i % 25; obstacle1_2_13(i, h - 7); i++; if (i == 23) { if (key == 0) { op = 1; break; } }
							if (_kbhit()) {
								key = _getch(); key2 = _getch();
								if ((key == 'd' || key == 'l') && (key2 == 'l' || key2 == 'd')) { if (i == 17 || i == 16 || i == 15 || i == 22) { jump1_2_13(i - 1, h - 7); op = 1; i = i + 7; break; } else { if (i >= 18 && i<22) { jump1_2_13(i - 1, h - 7); score++; scoreprint(score); i = i + 7; } else { jump1_2_13(i - 1, h - 7); i = i + 7; } } key = 0; key2 = 0; }
								if (key == 'd' || key2 == 'd') { if (i == 17 || i == 16 || i == 15 || i == 22) { jump1_2_13_1(i - 1, h - 7); op = 1; i = i + 7; break; } else { if (i >= 18 && i<22) { jump1_2_13_1(i - 1, h - 7); op = 1; i = i + 7; break; } else { jump1_2_13_1(i - 1, h - 7); i = i + 7; } } }
								if (key == 'l' || key2 == 'l') { if (i == 17 || i == 16 || i == 15 || i == 22) { jump1_2_13_2(i - 1, h - 7); op = 1; i = i + 7; break; } else { if (i >= 18 && i<22) { jump1_2_13_2(i - 1, h - 7); op = 1; i = i + 7; break; } else { jump1_2_13_2(i - 1, h - 7); i = i + 7; } } }
							}if (i >= 25)break;
						}
						if (h == 9) {
							key = 0; i = i % 25; obstacle1_2_13(i, h - 7); i++; if (i == 23) { if (key == 0) { op = 1; break; } }
							if (_kbhit()) {
								key = _getch(); key2 = _getch();
								if ((key == 'j' || key == 'a') && (key2 == 'a' || key2 == 'j')) { if (i == 17 || i == 16 || i == 15 || i == 22) { jump1_2_13(i - 1, h - 7); op = 1; i = i + 7; break; } else { if (i >= 18 && i<22) { jump1_2_13(i - 1, h - 7); score++; scoreprint(score); i = i + 7; } else { jump1_2_13(i - 1, h - 7); i = i + 7; } } key = 0; key2 = 0; }
								if (key == 'j' || key2 == 'j') { if (i == 17 || i == 16 || i == 15 || i == 22) { jump1_2_13_1(i - 1, h - 7); op = 1; i = i + 7; break; } else { if (i >= 18 && i<22) { jump1_2_13_1(i - 1, h - 7); op = 1; i = i + 7; break; } else { jump1_2_13_1(i - 1, h - 7); i = i + 7; } } }
								if (key == 'a' || key2 == 'a') { if (i == 17 || i == 16 || i == 15 || i == 22) { jump1_2_13_2(i - 1, h - 7); op = 1; i = i + 7; break; } else { if (i >= 18 && i<22) { jump1_2_13_2(i - 1, h - 7); op = 1; i = i + 7; break; } else { jump1_2_13_2(i - 1, h - 7); i = i + 7; } } }
							}if (i >= 25)break;
						}
					}//r=5
					if (r == 6) {  // ������ 2ĭ �Ʒ��� 1ĭ
						if (h == 1) {
							key = 0; i = i % 25; obstacle2_1(i, h); i++; if (i == 23) { if (key == 0) { op = 1; break; } }
							if (_kbhit()) { key = _getch(); if (key == 'd') { if (i == 16 || i == 19 || i == 22) { jump2_1(i - 1, h); op = 1; i = i + 7; break; } else { if (i == 17 || i == 18 || i == 20 || i == 21) { jump2_1(i - 1, h); score++; scoreprint(score); i = i + 7; } else { jump2_1(i - 1, h); i = i + 7; } } } }
							if (i >= 25)break;
						}
						if (h == 2) {
							key = 0; i = i % 25; obstacle2_1(i, h); i++; if (i == 23) { if (key == 0) { op = 1; break; } }
							if (_kbhit()) { key = _getch(); if (key == 'j') { if (i == 16 || i == 19 || i == 22) { jump2_1(i - 1, h); op = 1; i = i + 7; break; } else { if (i == 17 || i == 18 || i == 20 || i == 21) { jump2_1(i - 1, h); score++; scoreprint(score); i = i + 7; } else { jump2_1(i - 1, h); i = i + 7; } } } }
							if (i >= 25)break;
						}
						if (h == 3) {
							key = 0; i = i % 25; obstacle2_1(i, h); i++; if (i == 23) { if (key == 0) { op = 1; break; } }
							if (_kbhit()) { key = _getch(); if (key == 'l') { if (i == 16 || i == 19 || i == 22) { jump2_1(i - 1, h); op = 1; i = i + 7; break; } else { if (i == 17 || i == 18 || i == 20 || i == 21) { jump2_1(i - 1, h); score++; scoreprint(score); i = i + 7; } else { jump2_1(i - 1, h); i = i + 7; } } } }
							if (i >= 25)break;
						}
						if (h == 4) {
							key = 0; i = i % 25; obstacle2_1(i, h); i++; if (i == 23) { if (key == 0) { op = 1; break; } }
							if (_kbhit()) { key = _getch(); if (key == 'a') { if (i == 16 || i == 19 || i == 22) { jump2_1(i - 1, h); op = 1; i = i + 7; break; } else { if (i == 17 || i == 18 || i == 20 || i == 21) { jump2_1(i - 1, h); score++; scoreprint(score); i = i + 7; } else { jump2_1(i - 1, h); i = i + 7; } } } }
							if (i >= 25)break;
						}
						if (h == 5) {
							key = 0; i = i % 25; obstacle2_1_12(i, h - 4); i++; if (i == 23) { if (key == 0) { op = 1; break; } }
							if (_kbhit()) {
								key = _getch(); key2 = _getch();
								if ((key == 'd' || key == 'j') && (key2 == 'j' || key2 == 'd')) { if (i == 16 || i == 19 || i == 22) { jump2_1_12(i - 1, h - 4); op = 1; i = i + 7; break; } else { if (i == 17 || i == 18 || i == 20 || i == 21) { jump2_1_12(i - 1, h - 4); score++; scoreprint(score); i = i + 7; } else { jump2_1_12(i - 1, h - 4); i = i + 7; } } key = 0; key2 = 0; }
								if (key == 'd' || key2 == 'd') { if (i == 16 || i == 19 || i == 22) { jump2_1_12_1(i - 1, h - 4); op = 1; i = i + 7; break; } else { if (i == 17 || i == 18 || i == 20 || i == 21) { jump2_1_12_1(i - 1, h - 4); op = 1; i = i + 7; break; } else { jump2_1_12_1(i - 1, h - 4); i = i + 7; } } }
								if (key == 'j' || key2 == 'j') { if (i == 16 || i == 19 || i == 22) { jump2_1_12_2(i - 1, h - 4); op = 1; i = i + 7; break; } else { if (i == 17 || i == 18 || i == 20 || i == 21) { jump2_1_12_2(i - 1, h - 4); op = 1; i = i + 7; break; } else { jump2_1_12_2(i - 1, h - 4); i = i + 7; } } }
							}if (i >= 25)break;
						}
						if (h == 6) {
							key = 0; i = i % 25; obstacle2_1_12(i, h - 4); i++; if (i == 23) { if (key == 0) { op = 1; break; } }
							if (_kbhit()) {
								key = _getch(); key2 = _getch();
								if ((key == 'j' || key == 'l') && (key2 == 'l' || key2 == 'j')) { if (i == 16 || i == 19 || i == 22) { jump2_1_12(i - 1, h - 4); op = 1; i = i + 7; break; } else { if (i == 17 || i == 18 || i == 20 || i == 21) { jump2_1_12(i - 1, h - 4); score++; scoreprint(score); i = i + 7; } else { jump2_1_12(i - 1, h - 4); i = i + 7; } } key = 0; key2 = 0; }
								if (key == 'j' || key2 == 'j') { if (i == 16 || i == 19 || i == 22) { jump2_1_12_1(i - 1, h - 4); op = 1; i = i + 7; break; } else { if (i == 17 || i == 18 || i == 20 || i == 21) { jump2_1_12_1(i - 1, h - 4); op = 1; i = i + 7; break; } else { jump2_1_12_1(i - 1, h - 4); i = i + 7; } } }
								if (key == 'l' || key2 == 'l') { if (i == 16 || i == 19 || i == 22) { jump2_1_12_2(i - 1, h - 4); op = 1; i = i + 7; break; } else { if (i == 17 || i == 18 || i == 20 || i == 21) { jump2_1_12_2(i - 1, h - 4); op = 1; i = i + 7; break; } else { jump2_1_12_2(i - 1, h - 4); i = i + 7; } } }
							}if (i >= 25)break;
						}
						if (h == 7) {
							key = 0; i = i % 25; obstacle2_1_12(i, h - 4); i++; if (i == 23) { if (key == 0) { op = 1; break; } }
							if (_kbhit()) {
								key = _getch(); key2 = _getch();
								if ((key == 'l' || key == 'a') && (key2 == 'a' || key2 == 'l')) { if (i == 16 || i == 19 || i == 22) { jump2_1_12(i - 1, h - 4); op = 1; i = i + 7; break; } else { if (i == 17 || i == 18 || i == 20 || i == 21) { jump2_1_12(i - 1, h - 4); score++; scoreprint(score); i = i + 7; } else { jump2_1_12(i - 1, h - 4); i = i + 7; } } key = 0; key2 = 0; }
								if (key == 'l' || key2 == 'l') { if (i == 16 || i == 19 || i == 22) { jump2_1_12_1(i - 1, h - 4); op = 1; i = i + 7; break; } else { if (i == 17 || i == 18 || i == 20 || i == 21) { jump2_1_12_1(i - 1, h - 4); op = 1; i = i + 7; break; } else { jump2_1_12_1(i - 1, h - 4); i = i + 7; } } }
								if (key == 'a' || key2 == 'a') { if (i == 16 || i == 19 || i == 22) { jump2_1_12_2(i - 1, h - 4); op = 1; i = i + 7; break; } else { if (i == 17 || i == 18 || i == 20 || i == 21) { jump2_1_12_2(i - 1, h - 4); op = 1; i = i + 7; break; } else { jump2_1_12_2(i - 1, h - 4); i = i + 7; } } }
							}if (i >= 25)break;
						}
						if (h == 8) {
							key = 0; i = i % 25; obstacle2_1_13(i, h - 7); i++; if (i == 23) { if (key == 0) { op = 1; break; } }
							if (_kbhit()) {
								key = _getch(); key2 = _getch();
								if ((key == 'd' || key == 'l') && (key2 == 'l' || key2 == 'd')) { if (i == 16 || i == 19 || i == 22) { jump2_1_13(i - 1, h - 7); op = 1; i = i + 7; break; } else { if (i == 17 || i == 18 || i == 20 || i == 21) { jump2_1_13(i - 1, h - 7); score++; scoreprint(score); i = i + 7; } else { jump2_1_13(i - 1, h - 7); i = i + 7; } } key = 0; key2 = 0; }
								if (key == 'd' || key2 == 'd') { if (i == 16 || i == 19 || i == 22) { jump2_1_13_1(i - 1, h - 7); op = 1; i = i + 7; break; } else { if (i == 17 || i == 18 || i == 20 || i == 21) { jump2_1_13_1(i - 1, h - 7); op = 1; i = i + 7; break; } else { jump2_1_13_1(i - 1, h - 7); i = i + 7; } } }
								if (key == 'l' || key2 == 'l') { if (i == 16 || i == 19 || i == 22) { jump2_1_13_2(i - 1, h - 7); op = 1; i = i + 7; break; } else { if (i == 17 || i == 18 || i == 20 || i == 21) { jump2_1_13_2(i - 1, h - 7); op = 1; i = i + 7; break; } else { jump2_1_13_2(i - 1, h - 7); i = i + 7; } } }
							}if (i >= 25)break;
						}
						if (h == 9) {
							key = 0; i = i % 25; obstacle2_1_13(i, h - 7); i++; if (i == 23) { if (key == 0) { op = 1; break; } }
							if (_kbhit()) {
								key = _getch(); key2 = _getch();
								if ((key == 'j' || key == 'a') && (key2 == 'a' || key2 == 'j')) { if (i == 16 || i == 19 || i == 22) { jump2_1_13(i - 1, h - 7); op = 1; i = i + 7; break; } else { if (i == 17 || i == 18 || i == 20 || i == 21) { jump2_1_13(i - 1, h - 7); score++; scoreprint(score); i = i + 7; } else { jump2_1_13(i - 1, h - 7); i = i + 7; } } key = 0; key2 = 0; }
								if (key == 'j' || key2 == 'j') { if (i == 16 || i == 19 || i == 22) { jump2_1_13_1(i - 1, h - 7); op = 1; i = i + 7; break; } else { if (i == 17 || i == 18 || i == 20 || i == 21) { jump2_1_13_1(i - 1, h - 7); op = 1; i = i + 7; break; } else { jump2_1_13_1(i - 1, h - 7); i = i + 7; } } }
								if (key == 'a' || key2 == 'a') { if (i == 16 || i == 19 || i == 22) { jump2_1_13_2(i - 1, h - 7); op = 1; i = i + 7; break; } else { if (i == 17 || i == 18 || i == 20 || i == 21) { jump2_1_13_2(i - 1, h - 7); op = 1; i = i + 7; break; } else { jump2_1_13_2(i - 1, h - 7); i = i + 7; } } }
							}if (i >= 25)break;
						}
					}//r=6
				}//while ��ֹ� �ݺ�
				if (op == 1) break;
			}//score>3 && score<=6
			if (score >= 10 && score<15) {
				if (score == 10) {
					cls(); stageclear_screen(); Levelupkey = _getch(); if (_kbhit()) { fflush(stdin); Levelupkey = _getch(); if (Levelupkey == '1')cls(); }
					cls(); mapbase(); mapping();  scoreprint(score); Levelcount(3); keyprint(3);
				}
				// r�� ��ֹ� ���� h�� ����(1����,2����,3����,4����) // ������ ������ i=1
				r = rand() % 3 + 7, h = rand() % 9 + 1;
				while (1)
				{
					if (r == 7) {  // ������ 4ĭ¥������ֹ� 
						if (h == 1) {
							key = 0; i = i % 25; obstacle4_0(i, h); i++; if (i == 25) { if (key == 0) { score++; scoreprint(score); break; } }
							if (_kbhit()) { key = _getch(); if (key == 'j') { if (i <= 21 && i >= 17) { jump4_0(i - 1, h); op = 1; i = i + 7; break; } else { jump4_0(i - 1, h); i = i + 7; } } }
						}
						if (h == 2) {
							key = 0; i = i % 25; obstacle4_0(i, h); i++; if (i == 25) { if (key == 0) { score++; scoreprint(score); break; } }
							if (_kbhit()) { key = _getch(); if (key == 'l') { if (i <= 21 && i >= 17) { jump4_0(i - 1, h); op = 1; i = i + 7; break; } else { jump4_0(i - 1, h); i = i + 7; } } }
						}
						if (h == 3) {
							key = 0; i = i % 25; obstacle4_0(i, h); i++; if (i == 25) { if (key == 0) { score++; scoreprint(score); break; } }
							if (_kbhit()) { key = _getch(); if (key == 'a') { if (i <= 21 && i >= 17) { jump4_0(i - 1, h); op = 1; i = i + 7; break; } else { jump4_0(i - 1, h); i = i + 7; } } }
							if (i >= 25)break;
						}
						if (h == 4) {
							key = 0; i = i % 25; obstacle4_0(i, h); i++; if (i == 25) { if (key == 0) { score++; scoreprint(score); break; } }
							if (_kbhit()) { key = _getch(); if (key == 'd') { if (i <= 21 && i >= 17) { jump4_0(i - 1, h); op = 1; i = i + 7; break; } else { jump4_0(i - 1, h); i = i + 7; } } }
						}
						if (h == 5) {
							key = 0; i = i % 25; obstacle4_0_12(i, h - 4); i++; if (i == 25) { if (key == 0) { score++; scoreprint(score); break; } }
							if (_kbhit()) {
								key = _getch(); key2 = _getch();
								if ((key == 'j' || key == 'l') && (key2 == 'l' || key2 == 'j')) { if (i <= 21 && i >= 17) { jump4_0_12(i - 1, h - 4); op = 1; i = i + 7; break; } else { jump4_0_12(i - 1, h - 4); i = i + 7; } key = 0; key2 = 0; }
								if (key == 'j' || key2 == 'j') { if (i <= 21 && i >= 17) { jump4_0_12_1(i - 1, h - 4); op = 1; i = i + 7; break; } else { jump4_0_12_1(i - 1, h - 4); i = i + 7; } }
								if (key == 'l' || key2 == 'l') { if (i <= 21 && i >= 17) { jump4_0_12_2(i - 1, h - 4); op = 1; i = i + 7; break; } else { jump4_0_12_2(i - 1, h - 4); i = i + 7; } }
							}if (i >= 25)break;
						}
						if (h == 6) {
							key = 0; i = i % 25; obstacle4_0_12(i, h - 4); i++; if (i == 25) { if (key == 0) { score++; scoreprint(score); break; } }
							if (_kbhit()) {
								key = _getch(); key2 = _getch();
								if ((key == 'l' || key == 'a') && (key2 == 'a' || key2 == 'l')) { if (i <= 21 && i >= 17) { jump4_0_12(i - 1, h - 4); op = 1; i = i + 7; break; } else { jump4_0_12(i - 1, h - 4); i = i + 7; } key = 0; key2 = 0; }
								if (key == 'l' || key2 == 'l') { if (i <= 21 && i >= 17) { jump4_0_12_1(i - 1, h - 4); op = 1; i = i + 7; break; } else { jump4_0_12_1(i - 1, h - 4); i = i + 7; } }
								if (key == 'a' || key2 == 'a') { if (i <= 21 && i >= 17) { jump4_0_12_2(i - 1, h - 4); op = 1; i = i + 7; break; } else { jump4_0_12_2(i - 1, h - 4); i = i + 7; } }
							}if (i >= 25)break;
						}
						if (h == 7) {
							key = 0; i = i % 25; obstacle4_0_12(i, h - 4); i++; if (i == 25) { if (key == 0) { score++; scoreprint(score); break; } }
							if (_kbhit()) {
								key = _getch(); key2 = _getch();
								if ((key == 'a' || key == 'd') && (key2 == 'd' || key2 == 'a')) { if (i <= 21 && i >= 17) { jump4_0_12(i - 1, h - 4); op = 1; i = i + 7; break; } else { jump4_0_12(i - 1, h - 4); i = i + 7; } key = 0; key2 = 0; }
								if (key == 'a' || key2 == 'a') { if (i <= 21 && i >= 17) { jump4_0_12_1(i - 1, h - 4); op = 1; i = i + 7; break; } else { jump4_0_12_1(i - 1, h - 4); i = i + 7; } }
								if (key == 'd' || key2 == 'd') { if (i <= 21 && i >= 17) { jump4_0_12_2(i - 1, h - 4); op = 1; i = i + 7; break; } else { jump4_0_12_2(i - 1, h - 4); i = i + 7; } }
							}if (i >= 25)break;
						}
						if (h == 8) {
							key = 0; i = i % 25; obstacle4_0_13(i, h - 7); i++; if (i == 25) { if (key == 0) { score++; scoreprint(score); break; } }
							if (_kbhit()) {
								key = _getch(); key2 = _getch();
								if ((key == 'j' || key == 'a') && (key2 == 'a' || key2 == 'j')) { if (i <= 21 && i >= 17) { jump4_0_13(i - 1, h - 7); op = 1; i = i + 7; break; } else { jump4_0_13(i - 1, h - 7); i = i + 7; } key = 0; key2 = 0; }
								if (key == 'j' || key2 == 'j') { if (i <= 21 && i >= 17) { jump4_0_13_1(i - 1, h - 7); op = 1; i = i + 7; break; } else { jump4_0_13_1(i - 1, h - 7); i = i + 7; } }
								if (key == 'a' || key2 == 'a') { if (i <= 21 && i >= 17) { jump4_0_13_2(i - 1, h - 7); op = 1; i = i + 7; break; } else { jump4_0_13_2(i - 1, h - 7); i = i + 7; } }
							}if (i >= 25)break;
						}
						if (h == 9) {
							key = 0; i = i % 25; obstacle4_0_13(i, h - 7); i++; if (i == 25) { if (key == 0) { score++; scoreprint(score); break; } }
							if (_kbhit()) {
								key = _getch(); key2 = _getch();
								if ((key == 'l' || key == 'd') && (key2 == 'd' || key2 == 'l')) { if (i <= 21 && i >= 17) { jump4_0_13(i - 1, h - 7); op = 1; i = i + 7; break; } else { jump4_0_13(i - 1, h - 7); i = i + 7; } key = 0; key2 = 0; }
								if (key == 'l' || key2 == 'l') { if (i <= 21 && i >= 17) { jump4_0_13_1(i - 1, h - 7); op = 1; i = i + 7; break; } else { jump4_0_13_1(i - 1, h - 7); i = i + 7; } }
								if (key == 'd' || key2 == 'd') { if (i <= 21 && i >= 17) { jump4_0_13_2(i - 1, h - 7); op = 1; i = i + 7; break; } else { jump4_0_13_2(i - 1, h - 7); i = i + 7; } }
							}if (i >= 25)break;
						}
					}//r==7
					if (r == 8) {  // �Ʒ���ĭ ������ĭ
						if (h == 1) {
							key = 0; i = i % 25; obstacle1_3(i, h); i++; if (i == 23) { if (key == 0) { op = 1; break; } }
							if (_kbhit()) { key = _getch(); if (key == 'j') { if (i >= 16 && i <= 18 || i == 20 || i == 21 || i == 22) { jump1_3(i - 1, h); op = 1; i = i + 7; break; } else { if (i == 19) { jump1_3(i - 1, h); score++; scoreprint(score); i = i + 7; } else { jump1_3(i - 1, h); i = i + 7; } } } }
							if (i >= 25)break;
						}
						if (h == 2) {
							key = 0; i = i % 25; obstacle1_3(i, h); i++; if (i == 23) { if (key == 0) { op = 1; break; } }
							if (_kbhit()) { key = _getch(); if (key == 'l') { if (i >= 16 && i <= 18 || i == 20 || i == 21 || i == 22) { jump1_3(i - 1, h); op = 1; i = i + 7; break; } else { if (i == 19) { jump1_3(i - 1, h); score++; scoreprint(score); i = i + 7; } else { jump1_3(i - 1, h); i = i + 7; } } } }
							if (i >= 25)break;
						}
						if (h == 3) {
							key = 0; i = i % 25; obstacle1_3(i, h); i++; if (i == 23) { if (key == 0) { op = 1; break; } }
							if (_kbhit()) { key = _getch(); if (key == 'a') { if (i >= 16 && i <= 18 || i == 20 || i == 21 || i == 22) { jump1_3(i - 1, h); op = 1; i = i + 7; break; } else { if (i == 19) { jump1_3(i - 1, h); score++; scoreprint(score); i = i + 7; } else { jump1_3(i - 1, h); i = i + 7; } } } }
							if (i >= 25)break;
						}
						if (h == 4) {
							key = 0; i = i % 25; obstacle1_3(i, h); i++; if (i == 23) { if (key == 0) { op = 1; break; } }
							if (_kbhit()) { key = _getch(); if (key == 'd') { if (i >= 16 && i <= 18 || i == 20 || i == 21 || i == 22) { jump1_3(i - 1, h); op = 1; i = i + 7; break; } else { if (i == 19) { jump1_3(i - 1, h); score++; scoreprint(score); i = i + 7; } else { jump1_3(i - 1, h); i = i + 7; } } } }
							if (i >= 25)break;
						}
						if (h == 5) {
							key = 0; i = i % 25; obstacle1_3_12(i, h - 4); i++; if (i == 23) { if (key == 0) { op = 1; break; } }
							if (_kbhit()) {
								key = _getch(); key2 = _getch();
								if ((key == 'j' || key == 'l') && (key2 == 'l' || key2 == 'j')) { if (i >= 16 && i <= 18 || i == 20 || i == 21 || i == 22) { jump1_3_12(i - 1, h - 4); op = 1; i = i + 7; break; } else { if (i == 19) { jump1_3_12(i - 1, h - 4); score++; scoreprint(score); i = i + 7; } else { jump1_3_12(i - 1, h - 4); i = i + 7; } } key = 0; key2 = 0; }
								if (key == 'j' || key2 == 'j') { if (i >= 16 && i <= 18 || i == 20 || i == 21 || i == 22) { jump1_3_12_1(i - 1, h - 4); op = 1; i = i + 7; break; } else { if (i == 19) { jump1_3_12_1(i - 1, h - 4); op = 1; i = i + 7; break; } else { jump1_3_12_1(i - 1, h - 4); i = i + 7; } } }
								if (key == 'l' || key2 == 'l') { if (i >= 16 && i <= 18 || i == 20 || i == 21 || i == 22) { jump1_3_12_2(i - 1, h - 4); op = 1; i = i + 7; break; } else { if (i == 19) { jump1_3_12_2(i - 1, h - 4); op = 1; i = i + 7; break; } else { jump1_3_12_2(i - 1, h - 4); i = i + 7; } } }
							}if (i >= 25)break;
						}
						if (h == 6) {
							key = 0; i = i % 25; obstacle1_3_12(i, h - 4); i++; if (i == 23) { if (key == 0) { op = 1; break; } }
							if (_kbhit()) {
								key = _getch(); key2 = _getch();
								if ((key == 'l' || key == 'a') && (key2 == 'a' || key2 == 'l')) { if (i >= 16 && i <= 18 || i == 20 || i == 21 || i == 22) { jump1_3_12(i - 1, h - 4); op = 1; i = i + 7; break; } else { if (i == 19) { jump1_3_12(i - 1, h - 4); score++; scoreprint(score); i = i + 7; } else { jump1_3_12(i - 1, h - 4); i = i + 7; } } key = 0; key2 = 0; }
								if (key == 'l' || key2 == 'l') { if (i >= 16 && i <= 18 || i == 20 || i == 21 || i == 22) { jump1_3_12_1(i - 1, h - 4); op = 1; i = i + 7; break; } else { if (i == 19) { jump1_3_12_1(i - 1, h - 4); op = 1; i = i + 7; break; } else { jump1_3_12_1(i - 1, h - 4); i = i + 7; } } }
								if (key == 'a' || key2 == 'a') { if (i >= 16 && i <= 18 || i == 20 || i == 21 || i == 22) { jump1_3_12_2(i - 1, h - 4); op = 1; i = i + 7; break; } else { if (i == 19) { jump1_3_12_2(i - 1, h - 4); op = 1; i = i + 7; break; } else { jump1_3_12_2(i - 1, h - 4); i = i + 7; } } }
							}if (i >= 25)break;
						}
						if (h == 7) {
							key = 0; i = i % 25; obstacle1_3_12(i, h - 4); i++; if (i == 23) { if (key == 0) { op = 1; break; } }
							if (_kbhit()) {
								key = _getch(); key2 = _getch();
								if ((key == 'a' || key == 'd') && (key2 == 'd' || key2 == 'a')) { if (i >= 16 && i <= 18 || i == 20 || i == 21 || i == 22) { jump1_3_12(i - 1, h - 4); op = 1; i = i + 7; break; } else { if (i == 19) { jump1_3_12(i - 1, h - 4); score++; scoreprint(score); i = i + 7; } else { jump1_3_12(i - 1, h - 4); i = i + 7; } } key = 0; key2 = 0; }
								if (key == 'a' || key2 == 'a') { if (i >= 16 && i <= 18 || i == 20 || i == 21 || i == 22) { jump1_3_12_1(i - 1, h - 4); op = 1; i = i + 7; break; } else { if (i == 19) { jump1_3_12_1(i - 1, h - 4); op = 1; i = i + 7; break; } else { jump1_3_12_1(i - 1, h - 4); i = i + 7; } } }
								if (key == 'd' || key2 == 'd') { if (i >= 16 && i <= 18 || i == 20 || i == 21 || i == 22) { jump1_3_12_2(i - 1, h - 4); op = 1; i = i + 7; break; } else { if (i == 19) { jump1_3_12_2(i - 1, h - 4); op = 1; i = i + 7; break; } else { jump1_3_12_2(i - 1, h - 4); i = i + 7; } } }
							}if (i >= 25)break;
						}
						if (h == 8) {
							key = 0; i = i % 25; obstacle1_3_13(i, h - 7); i++; if (i == 23) { if (key == 0) { op = 1; break; } }
							if (_kbhit()) {
								key = _getch(); key2 = _getch();
								if ((key == 'j' || key == 'a') && (key2 == 'a' || key2 == 'j')) { if (i >= 16 && i <= 18 || i == 20 || i == 21 || i == 22) { jump1_3_13(i - 1, h - 7); op = 1; i = i + 7; break; } else { if (i == 19) { jump1_3_13(i - 1, h - 7); score++; scoreprint(score); i = i + 7; } else { jump1_3_13(i - 1, h - 7); i = i + 7; } } key = 0; key2 = 0; }
								if (key == 'j' || key2 == 'j') { if (i >= 16 && i <= 18 || i == 20 || i == 21 || i == 22) { jump1_3_13_1(i - 1, h - 7); op = 1; i = i + 7; break; } else { if (i == 19) { jump1_3_13_1(i - 1, h - 7); op = 1; i = i + 7; break; } else { jump1_3_13_1(i - 1, h - 7); i = i + 7; } } }
								if (key == 'a' || key2 == 'a') { if (i >= 16 && i <= 18 || i == 20 || i == 21 || i == 22) { jump1_3_13_2(i - 1, h - 7); op = 1; i = i + 7; break; } else { if (i == 19) { jump1_3_13_2(i - 1, h - 7); op = 1; i = i + 7; break; } else { jump1_3_13_2(i - 1, h - 7); i = i + 7; } } }
							}if (i >= 25)break;
						}
						if (h == 9) {
							key = 0; i = i % 25; obstacle1_3_13(i, h - 7); i++; if (i == 23) { if (key == 0) { op = 1; break; } }
							if (_kbhit()) {
								key = _getch(); key2 = _getch();
								if ((key == 'l' || key == 'd') && (key2 == 'd' || key2 == 'l')) { if (i >= 16 && i <= 18 || i == 20 || i == 21 || i == 22) { jump1_3_13(i - 1, h - 7); op = 1; i = i + 7; break; } else { if (i == 19) { jump1_3_13(i - 1, h - 7); score++; scoreprint(score); i = i + 7; } else { jump1_3_13(i - 1, h - 7); i = i + 7; } } key = 0; key2 = 0; }
								if (key == 'l' || key2 == 'l') { if (i >= 16 && i <= 18 || i == 20 || i == 21 || i == 22) { jump1_3_13_1(i - 1, h - 7); op = 1; i = i + 7; break; } else { if (i == 19) { jump1_3_13_1(i - 1, h - 7); op = 1; i = i + 7; break; } else { jump1_3_13_1(i - 1, h - 7); i = i + 7; } } }
								if (key == 'd' || key2 == 'd') { if (i >= 16 && i <= 18 || i == 20 || i == 21 || i == 22) { jump1_3_13_2(i - 1, h - 7); op = 1; i = i + 7; break; } else { if (i == 19) { jump1_3_13_2(i - 1, h - 7); op = 1; i = i + 7; break; } else { jump1_3_13_2(i - 1, h - 7); i = i + 7; } } }
							}if (i >= 25)break;
						}
					}//r==8;
					if (r == 9) {  // �Ʒ���ĭ ������ĭ
						if (h == 1) {
							key = 0; i = i % 25; obstacle3_1(i, h); i++; if (i == 23) { if (key == 0) { op = 1; break; } }
							if (_kbhit()) { key = _getch(); if (key == 'j') { if (i >= 18 && i <= 20 || i == 16 || i == 22) { jump3_1(i - 1, h); op = 1; i = i + 7; break; } else { if (i == 17 || i == 21) { jump3_1(i - 1, h); score++; scoreprint(score); i = i + 7; } else { jump3_1(i - 1, h); i = i + 7; } } } }
							if (i >= 25)break;
						}
						if (h == 2) {
							key = 0; i = i % 25; obstacle3_1(i, h); i++; if (i == 23) { if (key == 0) { op = 1; break; } }
							if (_kbhit()) { key = _getch(); if (key == 'l') { if (i >= 18 && i <= 20 || i == 16 || i == 22) { jump3_1(i - 1, h); op = 1; i = i + 7; break; } else { if (i == 17 || i == 21) { jump3_1(i - 1, h); score++; scoreprint(score); i = i + 7; } else { jump3_1(i - 1, h); i = i + 7; } } } }
							if (i >= 25)break;
						}
						if (h == 3) {
							key = 0; i = i % 25; obstacle3_1(i, h); i++; if (i == 23) { if (key == 0) { op = 1; break; } }
							if (_kbhit()) { key = _getch(); if (key == 'a') { if (i >= 18 && i <= 20 || i == 16 || i == 22) { jump3_1(i - 1, h); op = 1; i = i + 7; break; } else { if (i == 17 || i == 21) { jump3_1(i - 1, h); score++; scoreprint(score); i = i + 7; } else { jump3_1(i - 1, h); i = i + 7; } } } }
							if (i >= 25)break;
						}
						if (h == 4) {
							key = 0; i = i % 25; obstacle3_1(i, h); i++; if (i == 23) { if (key == 0) { op = 1; break; } }
							if (_kbhit()) { key = _getch(); if (key == 'd') { if (i >= 18 && i <= 20 || i == 16 || i == 22) { jump3_1(i - 1, h); op = 1; i = i + 7; break; } else { if (i == 17 || i == 21) { jump3_1(i - 1, h); score++; scoreprint(score); i = i + 7; } else { jump3_1(i - 1, h); i = i + 7; } } } }
							if (i >= 25)break;
						}
						if (h == 5) {
							key = 0; i = i % 25; obstacle3_1_12(i, h - 4); i++; if (i == 23) { if (key == 0) { op = 1; break; } }
							if (_kbhit()) {
								key = _getch(); key2 = _getch();
								if ((key == 'j' || key == 'l') && (key2 == 'l' || key2 == 'j')) { if (i >= 18 && i <= 20 || i == 16 || i == 22) { jump3_1_12(i - 1, h - 4); op = 1; i = i + 7; break; } else { if (i == 17 || i == 21) { jump3_1_12(i - 1, h - 4); score++; scoreprint(score); i = i + 7; } else { jump3_1_12(i - 1, h - 4); i = i + 7; } } key = 0; key2 = 0; }
								if (key == 'j' || key2 == 'j') { if (i >= 18 && i <= 20 || i == 16 || i == 22) { jump3_1_12_1(i - 1, h - 4); op = 1; i = i + 7; break; } else { if (i == 17 || i == 21) { jump3_1_12_1(i - 1, h - 4); op = 1; i = i + 7; break; } else { jump3_1_12_1(i - 1, h - 4); i = i + 7; } } }
								if (key == 'l' || key2 == 'l') { if (i >= 18 && i <= 20 || i == 16 || i == 22) { jump3_1_12_2(i - 1, h - 4); op = 1; i = i + 7; break; } else { if (i == 17 || i == 21) { jump3_1_12_2(i - 1, h - 4); op = 1; i = i + 7; break; } else { jump3_1_12_2(i - 1, h - 4); i = i + 7; } } }
							}if (i >= 25)break;
						}
						if (h == 6) {
							key = 0; i = i % 25; obstacle3_1_12(i, h - 4); i++; if (i == 23) { if (key == 0) { op = 1; break; } }
							if (_kbhit()) {
								key = _getch(); key2 = _getch();
								if ((key == 'l' || key == 'a') && (key2 == 'a' || key2 == 'l')) { if (i >= 18 && i <= 20 || i == 16 || i == 22) { jump3_1_12(i - 1, h - 4); op = 1; i = i + 7; break; } else { if (i == 17 || i == 21) { jump3_1_12(i - 1, h - 4); score++; scoreprint(score); i = i + 7; } else { jump3_1_12(i - 1, h - 4); i = i + 7; } } key = 0; key2 = 0; }
								if (key == 'l' || key2 == 'l') { if (i >= 18 && i <= 20 || i == 16 || i == 22) { jump3_1_12_1(i - 1, h - 4); op = 1; i = i + 7; break; } else { if (i == 17 || i == 21) { jump3_1_12_1(i - 1, h - 4); op = 1; i = i + 7; break; } else { jump3_1_12_1(i - 1, h - 4); i = i + 7; } } }
								if (key == 'a' || key2 == 'a') { if (i >= 18 && i <= 20 || i == 16 || i == 22) { jump3_1_12_2(i - 1, h - 4); op = 1; i = i + 7; break; } else { if (i == 17 || i == 21) { jump3_1_12_2(i - 1, h - 4); op = 1; i = i + 7; break; } else { jump3_1_12_2(i - 1, h - 4); i = i + 7; } } }
							}if (i >= 25)break;
						}
						if (h == 7) {
							key = 0; i = i % 25; obstacle3_1_12(i, h - 4); i++; if (i == 23) { if (key == 0) { op = 1; break; } }
							if (_kbhit()) {
								key = _getch(); key2 = _getch();
								if ((key == 'a' || key == 'd') && (key2 == 'd' || key2 == 'a')) { if (i >= 18 && i <= 20 || i == 16 || i == 22) { jump3_1_12(i - 1, h - 4); op = 1; i = i + 7; break; } else { if (i == 17 || i == 21) { jump3_1_12(i - 1, h - 4); score++; scoreprint(score); i = i + 7; } else { jump3_1_12(i - 1, h - 4); i = i + 7; } } key = 0; key2 = 0; }
								if (key == 'a' || key2 == 'a') { if (i >= 18 && i <= 20 || i == 16 || i == 22) { jump3_1_12_1(i - 1, h - 4); op = 1; i = i + 7; break; } else { if (i == 17 || i == 21) { jump3_1_12_1(i - 1, h - 4); op = 1; i = i + 7; break; } else { jump3_1_12_1(i - 1, h - 4); i = i + 7; } } }
								if (key == 'd' || key2 == 'd') { if (i >= 18 && i <= 20 || i == 16 || i == 22) { jump3_1_12_2(i - 1, h - 4); op = 1; i = i + 7; break; } else { if (i == 17 || i == 21) { jump3_1_12_2(i - 1, h - 4); op = 1; i = i + 7; break; } else { jump3_1_12_2(i - 1, h - 4); i = i + 7; } } }
							}if (i >= 25)break;
						}
						if (h == 8) {
							key = 0; i = i % 25; obstacle3_1_13(i, h - 7); i++; if (i == 23) { if (key == 0) { op = 1; break; } }
							if (_kbhit()) {
								key = _getch(); key2 = _getch();
								if ((key == 'j' || key == 'a') && (key2 == 'a' || key2 == 'j')) { if (i >= 18 && i <= 20 || i == 16 || i == 22) { jump3_1_13(i - 1, h - 7); op = 1; i = i + 7; break; } else { if (i == 17 || i == 21) { jump3_1_13(i - 1, h - 7); score++; scoreprint(score); i = i + 7; } else { jump3_1_13(i - 1, h - 7); i = i + 7; } } key = 0; key2 = 0; }
								if (key == 'j' || key2 == 'j') { if (i >= 18 && i <= 20 || i == 16 || i == 22) { jump3_1_13_1(i - 1, h - 7); op = 1; i = i + 7; break; } else { if (i == 17 || i == 21) { jump3_1_13_1(i - 1, h - 7); op = 1; i = i + 7; break; } else { jump3_1_13_1(i - 1, h - 7); i = i + 7; } } }
								if (key == 'a' || key2 == 'a') { if (i >= 18 && i <= 20 || i == 16 || i == 22) { jump3_1_13_2(i - 1, h - 7); op = 1; i = i + 7; break; } else { if (i == 17 || i == 21) { jump3_1_13_2(i - 1, h - 7); op = 1; i = i + 7; break; } else { jump3_1_13_2(i - 1, h - 7); i = i + 7; } } }
							}if (i >= 25)break;
						}
						if (h == 9) {
							key = 0; i = i % 25; obstacle3_1_13(i, h - 7); i++; if (i == 23) { if (key == 0) { op = 1; break; } }
							if (_kbhit()) {
								key = _getch(); key2 = _getch();
								if ((key == 'l' || key == 'd') && (key2 == 'd' || key2 == 'l')) { if (i >= 18 && i <= 20 || i == 16 || i == 22) { jump3_1_13(i - 1, h - 7); op = 1; i = i + 7; break; } else { if (i == 17 || i == 21) { jump3_1_13(i - 1, h - 7); score++; scoreprint(score); i = i + 7; } else { jump3_1_13(i - 1, h - 7); i = i + 7; } } key = 0; key2 = 0; }
								if (key == 'l' || key2 == 'l') { if (i >= 18 && i <= 20 || i == 16 || i == 22) { jump3_1_13_1(i - 1, h - 7); op = 1; i = i + 7; break; } else { if (i == 17 || i == 21) { jump3_1_13_1(i - 1, h - 7); op = 1; i = i + 7; break; } else { jump3_1_13_1(i - 1, h - 7); i = i + 7; } } }
								if (key == 'd' || key2 == 'd') { if (i >= 18 && i <= 20 || i == 16 || i == 22) { jump3_1_13_2(i - 1, h - 7); op = 1; i = i + 7; break; } else { if (i == 17 || i == 21) { jump3_1_13_2(i - 1, h - 7); op = 1; i = i + 7; break; } else { jump3_1_13_2(i - 1, h - 7); i = i + 7; } } }
							}if (i >= 25)break;
						}
					}//r==9;
				}//while ��ֹ� �ݺ�
				if (op == 1) break;
				if (score==15){qr=1;break;}
			}//score >10  <=15
		}//while rand()
		if (op == 1) { gameover_screen(); exitkey = _getch(); if (_kbhit()) { exitkey = _getch(); if (exitkey == '2')break;} } // ���� Ű������ݺ���.
		if (qr == 1) { allgameclear();break;}
	}
}