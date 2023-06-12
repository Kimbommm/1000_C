#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include <time.h>

#define LENGTH_K 21

void Intro();
int randomAB(int, int);
void giatri(int, int);
void textcolor(int);
void CreateMap(char[]);
void PrintMap(char[], int, int);
void Game1(int, int, int, int);
void Game2(char[], int, int);

int check = 0;

void Intro() {
	char s[10][500] = { "====>>GAME<<===", "Player a will find a treasure containing a lot of gold.", "however, in the process of finding gold.","You have met the pirates and will fight them.",
		"Are you ready to join this challenge?","...","ready???","ok let's go!!!","Press the Enter key to continue..." };

	int i;
	for (i = 0; i < 9; i++)
	{
		printf("%s\n", s[i]);
		Sleep(1000);
	}
	_getch();
	system("cls");
}

void Game1(int hp_a, int pw_a, int hp_b, int pw_b) {
	int temp_pw_a, turn, choose, checkIncrease, checkTransfiguration;
	temp_pw_a = pw_a;
	turn = 0; //0: Player, 1: Computer
	choose;
	checkIncrease = 0;
	checkTransfiguration = 0;


	while (hp_a > 0 && hp_b > 0)
	{
		printf("\nPlayer   HP: %d, PW: %d (%d)\n", hp_a, pw_a, pw_a / temp_pw_a);
		printf("Computer   HP: %d, PW: %d\n", hp_b, pw_b);

		if (turn == 0) // Player
		{
			printf("\n=============A's turn=============\n");
			do {
				printf("1. Attack\n");
				printf("2. Increase Power\n");
				printf("===========================\n\n");

				printf("Your choice(1/2): ");
				scanf_s("%d", &choose);

				if (choose != 1 && choose != 2)
				{
					printf("\nPlease input 1 or 2. Try again");
				}
			} while (choose != 1 && choose != 2);
			printf("\nYour choose: ");
			if (choose == 1)
			{
				printf("Attack");
				int temp_hp_b = hp_b;
				if (checkTransfiguration == 1)
				{
					hp_b -= pw_a / 2;
					if (hp_b <= 0)
					{
						hp_b = 0;
						printf("PW =>> 1/2!!!");
						printf("\nHP_B = %d - %d = %d\n", temp_hp_b, pw_a / 2, hp_b);
					}
					else
					{
						printf("PW =>> 1/2!!!");
						printf("\nHP_B = %d - %d = %d\n", temp_hp_b, pw_a / 2, hp_b);
					}
					/*printf("PW =>> 1/2!!!");
					printf("\nhp_b = %d - %d = %d\n", temp_hp_b, pw_a / 2, hp_b);*/
					checkTransfiguration = 0;
				}
				else
				{

					hp_b -= pw_a;
					if (hp_b <= 0)
					{
						hp_b = 0;
						printf("\nHP_B = %d - %d = %d\n", temp_hp_b, pw_a, hp_b);

					}
					else
					{
						printf("\nHP_B = %d - %d = %d\n", temp_hp_b, pw_a, hp_b);

					}
				}

				if (checkIncrease == 1)
				{
					checkIncrease = 0;
					pw_a = temp_pw_a;
				}
			}
			else
			{
				printf("Increase Power\n");
				pw_a *= 2;
				checkIncrease = 1;
			}
			turn = 1;
		}
		else if (turn == 1)
		{
			printf("\n=============B's turn=============\n");
			srand(time(0));
			choose = randomAB(1, 3);
			/*printf("\nComputer input: ");
			scanf_s("%d", &choose);*/
			if (choose == 1)
			{
				printf("Computer: Attack");
				int temp_hp_a = hp_a;
				hp_a -= pw_b;
				if (hp_a <= 0)
				{
					hp_a = 0;
					printf("\nHP_A = %d - %d = %d\n", temp_hp_a, pw_b, hp_a);

				}
				else
				{
					printf("\nHP_A = %d - %d = %d\n", temp_hp_a, pw_b, hp_a);

				}
				//printf("\nhp_a = %d - %d = %d\n", temp_hp_a, pw_b, hp_a);

				if (checkIncrease == 1)
				{
					checkIncrease = 0;
					pw_a = temp_pw_a;
				}
			}
			else if (choose == 2)
			{
				printf("Computer: Transfiguration\n");
				checkTransfiguration = 1;
			}
			else
			{
				printf("No thing\n");
			}
			turn = 0;
		}
	}
	if (hp_a <= 0)
	{
		printf("\nComuter win");
		hp_a = 0;
	}
	else if (hp_b <= 0)
	{
		printf("\nPlayer win");
		hp_b = 0;
	}
	printf("\nPlayer    HP: %d, PW: %d", hp_a, pw_a);
	printf("\nComputer  HP: %d, PW: %d", hp_b, pw_b);
	printf("\n");

}

int randomAB(int a, int b)
{
	return a + rand() % (b - a + 1);
}

int ngaunhien(int randomAB) {

}

void giatri(int x, int y) {
	printf("Nang luong: %d diem\n", x);
	printf("Cong kich: %d\n", y);
}

void textcolor(int x)
{
	HANDLE mau;
	mau = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau, x);
}



//gán từng phần tử theo giá trị tương ứng
//void CreateMap(char a[3][length]) { 
void CreateMap(char a[3][LENGTH_K + 1]) {
	//Nhập vào với độ dài là 22
	int i, j;
	for (i = 0; i < 3; ++i) {
		for (j = 0; j < LENGTH_K; ++j) { // j chạy 21 lần và in ra các kí tự
			if (i == 0 || i == 2) {
				a[i][j] = '*';
			}
			else {
				a[i][j] = ' ';
			}
		}
		// 0    1    2    3    4   5   6   7   8   9   10  == 11 lần
		// 11   12   13   14   15  16  17  18  19  20      == 10 lần

		//mảng bắt đầu từ 0 nên con số đưa vào là 21 là vị trí cuối cùng
		a[i][LENGTH_K] = '\0';
		//a[i][length -1] = '\0';
	}
}

//xuất các giá trị trong mảng
void PrintMap(char a[3][LENGTH_K + 1], int *x, int *y) {
	//void PrintMap(char a[3][length]) {
	int i;

	giatri(*x, *y);

	for (i = 0; i < 3; ++i) {
		printf("%s\n", a[i]);
	}

	if (check == 1) {
		// tao random sự kiện
		int randomsukien;
		srand(time(0));
		randomsukien = randomAB(1, 3);
		if (randomsukien == 1)
		{
			int hp_ngaunhien;
			hp_ngaunhien = randomAB(0, 500);
			printf("Nang luong ngau nhien: %d", hp_ngaunhien);
			*x += hp_ngaunhien;
			Sleep(3000);
		}
		else if (randomsukien == 2)
		{
			int congkich_ngaunhien;
			congkich_ngaunhien = randomAB(5, 10);
			printf("Cong kich ngau nhien: %d", congkich_ngaunhien);
			*y += congkich_ngaunhien;
			Sleep(3000);
		}
		else
		{
			printf("Dang lam!");
		}
		
	}
	
}

void Game2(char a[3][LENGTH_K + 1], int *x, int *y) {
	//void Game(char a[3][length]) {
	while (1)
	{
		//system("cls");

		//printf("%d\n", length);
		int idx;
		CreateMap(a);
		//PrintMap(a); //in đường ray

		//gán giá trị chính giữa(cách tính: (tổng - 1) / 2) => 21 - 1 / 2 = 10 là số chính giữa
		a[1][LENGTH_K / 2] = 'M';
		//PrintMap(a); //in chữ M nằm giữa

		//khởi tạo vòng lặp

		idx = LENGTH_K - 1; //cho nó chạy từ vị trí số 20 về 0
		while (1) {
			//gán giá trị: chừng nào chưa ở vị trí chính giữa nó sẽ in giấu chấm hỏi và ngược lại là dấu chấm !
			if (idx != LENGTH_K / 2) {
				a[1][idx] = '?';
				check = 0;
			}
			else {
				a[1][idx] = '!';
				textcolor(12);
				check = 1;
			}
			PrintMap(a, x, y);
			Sleep(200);
			system("cls");
			//XoaManHinh();
			if (idx !=	LENGTH_K / 2) {
				a[1][idx] = ' ';
			}
			else {
				a[1][idx] = 'M';
				textcolor(7);
			}
			idx--;
			//khi nào chỉ số giảm xuống về âm thì reset nó lại giá trị ban đầu
			if (idx < 0) {
				idx = LENGTH_K - 1;
			}
		}
	}


}

int main() {
	Intro();
	srand(time(0));
	Game1(randomAB(20, 40), randomAB(5, 15), randomAB(30, 50), randomAB(15, 25));

	//khai báo 
	// khai báo 22 vì nếu để in ra giá trị 21 dấu * + vị trí cuối là \0
	char a[3][LENGTH_K + 1];

	int nangluong = 1000;
	int congkich = 0;
	int congkichnhanduoc = 0;
	Game2(a, &nangluong, &congkich);
	return 0;
}