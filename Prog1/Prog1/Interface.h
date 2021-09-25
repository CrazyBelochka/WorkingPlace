#include "game.h"
void DrawPlayField(char place[ARRAY_LENGTH][ARRAY_HEIGHT])
{
	for (size_t y = 0; y < 1; y++)
	{
		for (size_t x = 0; x < ARRAY_LENGTH; x++)
		{
			place[x][y] = '_';
		}
	}


	for (size_t y = 1; y < ARRAY_HEIGHT - 16; y++)
	{
		place[1][y] = '|';
		place[23][y] = '|';
		place[47][y] = '|';
		place[72][y] = '|';
	}
	for (size_t y = 8; y < 9; y++)
	{
		for (size_t x = 0; x < ARRAY_LENGTH; x++)
		{
			place[x][y] = '_';
		}
	}


	for (size_t y = 9; y < ARRAY_HEIGHT - 8; y++)
	{
		place[1][y] = '|';
		place[23][y] = '|';
		place[47][y] = '|';
		place[72][y] = '|';
	}
	for (size_t y = 16; y < 17; y++)
	{
		for (size_t x = 0; x < ARRAY_LENGTH; x++)
		{
			place[x][y] = '_';
		}
	}


	for (size_t y = 16; y < ARRAY_HEIGHT; y++)
	{
		place[1][y] = '|';
		place[23][y] = '|';
		place[47][y] = '|';
		place[72][y] = '|';
	}
	for (size_t y = 24; y < 25; y++)
	{
		for (size_t x = 0; x < ARRAY_LENGTH; x++)
		{
			place[x][y] = '_';
		}
	}



	for (size_t y = 0; y < ARRAY_HEIGHT; y++)
	{
		for (size_t x = 0; x < ARRAY_LENGTH; x++)
		{
			if (place[x][y] == false)
			{
				cout << " ";
			}
			cout << place[x][y];
		}
		cout << endl;
	}
}

void StartGame(string name1, string name2)
{
	cout << "			   Игра началась!" << endl;
	cout << name1 << "								" << name2 << endl;
}

void PressStart(string var2, Game play, string name1, string name2)
{
	if (var2[0] == '1')
	{
		StartGame(name1, name2);
		DrawPlayField(play.place);
		for (play.amount_moves = 0; play.amount_moves < NUMBER_OF_FIELDS; play.amount_moves++)
		{
			play.amount_moves = play.FindAndMakePossibleMoves(play.amount_moves);
			DrawPlayField(play.place);
			play.WinCheck();
		}
		if (play.amount_moves == 9)
		{
			cout << "Draw";
		}
	}
	if (var2[0] == '2')
	{
		cout << endl << "Укажите, кто ходит первым: " << endl;
		cout << "Игрок 1 - его цель - не проиграть" << endl;
		cout << "Игрок 2 - его ходы случайны" << endl;
		int choose = 0;
		int check = 0;
		cin >> choose;
		if (choose == 1)
		{
			StartGame(name1, name2);
			while (play.amount_moves != 9)
			{
				play.amount_moves = play.MakeMoveCleverGamer(play.amount_moves);
				DrawPlayField(play.place);
				play.WinCheck();
				Sleep(500);
				play.amount_moves++;
				if (play.amount_moves == 9)
				{
					break;
				}
				play.amount_moves = play.FindAndMakePossibleRandMoves(play.amount_moves);
				DrawPlayField(play.place);
				play.WinCheck();
				Sleep(500);
				play.amount_moves++;
			}
			cout << "Draw";
		}
		if (choose == 2)
		{
			StartGame(name1, name2);
			while (play.amount_moves != 9)
			{
				play.amount_moves = play.FindAndMakePossibleRandMoves(play.amount_moves);
				DrawPlayField(play.place);
				play.WinCheck();
				Sleep(500);
				play.amount_moves++;
				if (play.amount_moves == 9)
				{
					break;
				}
				play.amount_moves = play.MakeMoveCleverGamer(play.amount_moves);
				DrawPlayField(play.place);
				play.WinCheck();
				Sleep(500);
				play.amount_moves++;
			}
			cout << "Draw";
		}
	}
}

string Test(string var2)
{
	for (;;)
	{
		if (((var2[0] == '1') || (var2[0] == '2')) && (!var2[1]))
		{
			return(var2);
		}
		else
		{
			cout << "Ошибка ввода, проверьте правильность вашего ввода и попробуйте еще раз: " << endl;
			cout << "Выберите варианты игры: " << endl;
			cout << "1. Играть самому" << endl;
			cout << "2. Играть автоматически(по заданию)" << endl;
			cin >> var2;
			var2 = Test(var2);
		}
	}
}
