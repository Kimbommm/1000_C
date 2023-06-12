/*
게임 1의 결과는 게임 파트 2에서 처리됩니다.
보너스의 총 가치가 2000포인트에 도달하지 않으면 게임이 계속됩니다.
9문제: 색상 효과 자동으로 프로그램이 완전히 게임의 끝에 생성됩니다.

모든 요구 사항을 이해하고 완벽하게 완성하고 싶었기 때문에 늦게 제출했습니다.이해해주시면 감사하겠습니다.
*/
#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include <time.h>

#define LENGTH_K 21

void Intro();
int randomAB(int, int);
void giatri(int, int);
void textcolor(int);
void CreateMap(char[][LENGTH_K + 1]);
void PrintMap(char[][LENGTH_K + 1], int*, int*);
void Game1(int, int, int, int, int*);
void Game2(char[][LENGTH_K + 1], int*, int*);

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

void Game1(int hp_a, int pw_a, int hp_b, int pw_b, int y, int *sotien) {
	int temp_pw_a, turn, choose, checkIncrease, checkTransfiguration;
	
	turn = 0;
	choose;
	checkIncrease = 0;
	checkTransfiguration = 0;

	int demo = 0;
	pw_a += y;
	temp_pw_a = pw_a;
	while (hp_a > 0 && hp_b > 0)
	{
		printf("\nPlayer   HP: %d, PW: %d (%d), PW++: %d =>>PW_sum: %d\n", hp_a, pw_a - y, pw_a / temp_pw_a, y, pw_a);
		//printf("\nPlayer   HP: %d, PW: %d (%d)\n", hp_a, pw_a, pw_a / temp_pw_a);
		//printf("\nPlayer   HP: %d, PW: %d (%d), PW++: %d =>>PW_sum: %d\n", hp_a, pw_a, pw_a / temp_pw_a, y, kkk);
		//pw_a = kkk;

		printf("Computer   HP: %d, PW: %d\n", hp_b, pw_b);
		if (turn == 0)
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
					//..
					//pw_a = y + pw_a;
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

					checkTransfiguration = 0;
				}
				else
				{
					//..
					//pw_a = y + pw_a;

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
				//pw_a = (pw_a * 2) + y;
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
		printf("\nPlayer    HP: %d, PW: %d", hp_a, pw_a);
		printf("\nComputer  HP: %d, PW: %d", hp_b, pw_b);
		printf("\n");
		printf("\nPlayer a has lost all his accumulated money: %d, the money left is = 0", *sotien);
		*sotien = 0;
		Sleep(5000);
		for (int i = 1; i <= 50; ++i) {
			textcolor(rand() % 20);
			printf("\n\n\t\tCongratulations");
			Sleep(50);
			system("cls");
		}
		exit(0);
	}
	else if (hp_b <= 0)
	{

		printf("\nPlayer win");
		hp_b = 0;
		printf("\nPlayer    HP: %d, PW: %d", hp_a, pw_a);
		printf("\nComputer  HP: %d, PW: %d", hp_b, pw_b);
		printf("\n");
		int sotien_ngaunhien = randomAB(500, 1000);
		printf("The amount awarded after the game is: %d", sotien_ngaunhien);
		*sotien += sotien_ngaunhien;
		if (*sotien >= 2000) {
			printf("\nAccumulated money: %d Bonus after the game %d = %d", *sotien - sotien_ngaunhien, sotien_ngaunhien, *sotien);
			printf("\nThe accumulated amount is over 2000.You have won the game.");
			Sleep(5000);
			for (int i = 1; i <= 50; ++i) {
				textcolor(rand() % 20);
				printf("\n\n\t\tCongratulations");
				Sleep(50);
				system("cls");
			}
			exit(0);
		}
	}

}

int randomAB(int a, int b)
{
	return a + rand() % (b - a + 1);
}


void giatri(int x, int y) {
	printf("Total money is: %d\n", x);
	printf("Power bonus random: %d\n", y);
}

void textcolor(int x)
{
	HANDLE mau;
	mau = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau, x);
}


void CreateMap(char a[3][LENGTH_K + 1]) {
	int i, j;
	for (i = 0; i < 3; ++i) {
		for (j = 0; j < LENGTH_K; ++j) {
			if (i == 0 || i == 2) {
				a[i][j] = '*';
			}
			else {
				a[i][j] = ' ';
			}
		}
		a[i][LENGTH_K] = '\0';
	}
}

void PrintMap(char a[3][LENGTH_K + 1], int* sotien, int* y) {
	int i;
	int thunghiem = 0;
	giatri(*sotien, *y);

	for (i = 0; i < 3; ++i) {
		printf("%s\n", a[i]);
	}

	if (check == 1) {

		int randomsukien;
		srand(time(0));
		randomsukien = randomAB(1, 3);
		if (randomsukien == 1)
		{
			int sotien_ngaunhien;
			sotien_ngaunhien = randomAB(0, 500);
			printf("The random amount received is: %d", sotien_ngaunhien);
			*sotien += sotien_ngaunhien;
			if (*sotien >= 2000) {
				printf("\nAccumulated money: %d Bonus after the game %d = %d", *sotien - sotien_ngaunhien, sotien_ngaunhien, *sotien);
				printf("\nThe accumulated amount is over 2000.You have won the game.");
				Sleep(3000);
				exit(0);
			}
			Sleep(3000);
		}
		else if (randomsukien == 2)
		{
			int congkich_ngaunhien;
			congkich_ngaunhien = randomAB(5, 10);
			printf("Power random bonus: %d", congkich_ngaunhien);
			*y = congkich_ngaunhien;
			Sleep(3000);
		}
		else if (randomsukien == 3)
		{
			//Game1(randomAB(20, 40), randomAB(5, 15), randomAB(30, 50), randomAB(10, 20));
			int hp_A = randomAB(20, 40);
			int pw_A = randomAB(5, 15);
			int hp_B = randomAB(30, 50);
			int pw_B = randomAB(10, 20);

			/*int hp_A = 100;
			int pw_A = 10;
			int hp_B = 100;
			int pw_B = 10;*/
			Game1(hp_A, pw_A, hp_B, pw_B, *y, sotien);
			Sleep(3000);

		}

	}

}

void Game2(char a[3][LENGTH_K + 1], int* x, int* y) {
	while (1)
	{

		int idx;
		CreateMap(a);

		a[1][LENGTH_K / 2] = 'M';


		idx = LENGTH_K - 1;
		while (1) {
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
			Sleep(20);
			system("cls");
			if (idx != LENGTH_K / 2) {
				a[1][idx] = ' ';
			}
			else {
				a[1][idx] = 'M';
				textcolor(7);
			}
			idx--;
			if (idx < 0) {
				idx = LENGTH_K - 1;
			}
		}
	}


}

int main() {
	Intro();
	srand(time(0));
	char a[3][LENGTH_K + 1];
	int nangluong = 1000;
	int congkich = 0;
	Game2(a, &nangluong, &congkich);
	return 0;
}