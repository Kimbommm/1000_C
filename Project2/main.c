#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <conio.h>

int randomAB(int a, int b)
{
	return a + rand() % (b - a + 1);
}

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

/*void PrintStatus(int hp_a, int pw_a, int hp_b, int pw_b) {
	printf("\nPlayer   HP: %d, PW: %d\n", hp_a, pw_a, pw_a /);
	printf("Computer   HP: %d, PW: %d\n", hp_b, pw_b);
}*/

void Game(int hp_a, int pw_a, int hp_b, int pw_b) {
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

int main(void)
{
	Intro();

	/*int hp_a, pw_a, temp_pw_a, hp_b, pw_b, turn, choose, checkIncrease, checkTransfiguration;
	srand(time(0));
	hp_a = randomAB(20, 40);
	pw_a = randomAB(5, 15);
	hp_b = randomAB(30, 50);
	pw_b = randomAB(15, 25);*/

	srand(time(0));
	Game(randomAB(20, 40), randomAB(5, 15), randomAB(30, 50), randomAB(15, 25));
	return 0;
}