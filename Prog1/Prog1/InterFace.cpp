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

int FindAndMakePossibleMoves(int amount_moves, int NumberVariations[NUMBER_OF_FIELDS], Game play, char place[ARRAY_LENGTH][ARRAY_HEIGHT])
{
	int reload = 0;
	int number = 0;
	int check = 0;

	if (amount_moves == 0)
	{
		cout << "Выберите куда нарисовать крестик:" << endl;
		cout << "0.Программа сама сделает ход" << endl;
		cout << "1.Левый верхний угол " << endl;
		cout << "2.Центральный верхний квадрат " << endl;
		cout << "3.Правый верхний угол " << endl;
		cout << "4.Левый центральный квадрат " << endl;
		cout << "5.Центральный квадрат " << endl;
		cout << "6.Правый центральный квадрат " << endl;
		cout << "7.Левый нижний угол " << endl;
		cout << "8.Центральный нижний квадрат " << endl;
		cout << "9.Правый нижний угол " << endl;
		cin >> number;
		if (number == 0)
		{
			check = play.MakeMoveCleverGamer(amount_moves, NumberVariations, place);
			return(1);
		}
		else
		{
			NumberVariations[number - 1] = 1;
			switch (number)
			{
			case 1:
				play.DrawCross(place, 12, 4);
				return(1);
			case 2:
				play.DrawCross(place, 35, 4);
				return(1);
			case 3:
				play.DrawCross(place, 58, 4);
				return(1);
			case 4:
				play.DrawCross(place, 12, 12);
				return(1);
			case 5:
				play.DrawCross(place, 35, 12);
				return(1);
			case 6:
				play.DrawCross(place, 58, 12);
				return(1);
			case 7:
				play.DrawCross(place, 12, 20);
				return(1);
			case 8:
				play.DrawCross(place, 35, 20);
				return(1);
			case 9:
				play.DrawCross(place, 58, 20);
				return(1);

			default:
				return(0);
			}
		}
	}
	if ((amount_moves != 0) && (amount_moves % 2 == 1))
	{
		cout << "Куда поставить нолик: " << endl;
		cout << "0.Программа сама сделает ход" << endl;
		if (NumberVariations[0] == 0)
		{
			cout << "1.Левый верхний угол " << endl;
		}
		if (NumberVariations[1] == 0)
		{
			cout << "2.Центральный верхний квадрат " << endl;
		}
		if (NumberVariations[2] == 0)
		{
			cout << "3.Правый верхний угол " << endl;
		}
		if (NumberVariations[3] == 0)
		{
			cout << "4.Левый центральный квадрат " << endl;
		}
		if (NumberVariations[4] == 0)
		{
			cout << "5.Центральный квадрат " << endl;
		}
		if (NumberVariations[5] == 0)
		{
			cout << "6.Правый центральный квадрат " << endl;
		}
		if (NumberVariations[6] == 0)
		{
			cout << "7.Левый нижний угол " << endl;
		}
		if (NumberVariations[7] == 0)
		{
			cout << "8.Центральный нижний квадрат " << endl;
		}
		if (NumberVariations[8] == 0)
		{
			cout << "9.Правый нижний угол " << endl;
		}
		cin >> number;

		if (number == 0)
		{
			check = play.MakeMoveCleverGamer(amount_moves, NumberVariations, place);
			return(1);
		}
		else
		{

			if (NumberVariations[number - 1] != 0)
			{
				reload = FindAndMakePossibleMoves(amount_moves, NumberVariations, play, place);
			}
			else
			{
				NumberVariations[number - 1] = 2;
				switch (number)
				{
				case 1:
					play.DrawCircle(place, 12, 4);
					return(1);
				case 2:
					play.DrawCircle(place, 35, 4);
					return(1);
				case 3:
					play.DrawCircle(place, 58, 4);
					return(1);
				case 4:
					play.DrawCircle(place, 12, 12);
					return(1);
				case 5:
					play.DrawCircle(place, 35, 12);
					return(1);
				case 6:
					play.DrawCircle(place, 58, 12);
					return(1);
				case 7:
					play.DrawCircle(place, 12, 20);
					return(1);
				case 8:
					play.DrawCircle(place, 35, 20);
					return(1);
				case 9:
					play.DrawCircle(place, 58, 20);
					return(1);

				default:
					return(0);
				}
			}
		}
	}
	if ((amount_moves != 0) && (amount_moves % 2 == 0))
	{
		cout << "Куда поставить крест: " << endl;
		cout << "0.Программа сама сделает ход" << endl;
		if (NumberVariations[0] == 0)
		{
			cout << "1.Левый верхний угол " << endl;
		}
		if (NumberVariations[1] == 0)
		{
			cout << "2.Центральный верхний квадрат " << endl;
		}
		if (NumberVariations[2] == 0)
		{
			cout << "3.Правый верхний угол " << endl;
		}
		if (NumberVariations[3] == 0)
		{
			cout << "4.Левый центральный квадрат " << endl;
		}
		if (NumberVariations[4] == 0)
		{
			cout << "5.Центральный квадрат " << endl;
		}
		if (NumberVariations[5] == 0)
		{
			cout << "6.Правый центральный квадрат " << endl;
		}
		if (NumberVariations[6] == 0)
		{
			cout << "7.Левый нижний угол " << endl;
		}
		if (NumberVariations[7] == 0)
		{
			cout << "8.Центральный нижний квадрат " << endl;
		}
		if (NumberVariations[8] == 0)
		{
			cout << "9.Правый нижний угол " << endl;
		}
		cin >> number;

		if (number == 0)
		{
			check = play.MakeMoveCleverGamer(amount_moves, NumberVariations, place);
			return(1);
		}
		else
		{
			if (NumberVariations[number - 1] != 0)
			{
				reload = FindAndMakePossibleMoves(amount_moves, NumberVariations, play, place);
			}
			else
			{
				NumberVariations[number - 1] = 1;
				switch (number)
				{
				case 1:
					play.DrawCross(place, 12, 4);
					return(1);
				case 2:
					play.DrawCross(place, 35, 4);
					return(1);
				case 3:
					play.DrawCross(place, 58, 4);
					return(1);
				case 4:
					play.DrawCross(place, 12, 12);
					return(1);
				case 5:
					play.DrawCross(place, 35, 12);
					return(1);
				case 6:
					play.DrawCross(place, 58, 12);
					return(1);
				case 7:
					play.DrawCross(place, 12, 20);
					return(1);
				case 8:
					play.DrawCross(place, 35, 20);
					return(1);
				case 9:
					play.DrawCross(place, 58, 20);
					return(1);

				default:
					return(0);
				}
			}
		}
	}
}

void PressStart(string var2, Game play, string name1, string name2)
{
	if (var2[0] == '1')
	{
		size_t checker = 0;
		play.checkermoves = 0;
		int check = 0;
		StartGame(name1, name2);
		DrawPlayField(play.place);
		for (play.amount_moves = 0; play.amount_moves < NUMBER_OF_FIELDS; play.amount_moves++)
		{
			//play.checkermoves = FindAndMakePossibleMoves(play.amount_moves, play.NumberVariations, play, play.place);
			check = FindAndMakePossibleMoves(play.amount_moves, play.NumberVariations, play, play.place);

			DrawPlayField(play.place);
			checker = play.WinCheck(play.NumberVariations);
			if (checker == 1)
			{
				cout << "First player won";
				break;
			}
			if (checker == 2)
			{
				cout << "Second player won";
				break;
			}
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
		int checker = 0;
		int checker2 = 0;
		int move = 0;
		cin >> choose;
		if (choose == 1)
		{
			StartGame(name1, name2);
			while (play.amount_moves != 9)
			{
				checker2 = play.MakeMoveCleverGamer(play.amount_moves, play.NumberVariations, play.place);
				DrawPlayField(play.place);
				checker = play.WinCheck(play.NumberVariations);
				if (checker == 1)
				{
					cout << "First player won";
					break;
				}
				if (checker == 2)
				{
					cout << "Second player won";
					break;
				}
				Sleep(500);
				play.amount_moves++;
				if (play.amount_moves == 9)
				{
					break;
				}

				move = play.FindPossibleRandMoves(play.NumberVariations);
				play.MakePossibleRandMoves(play.amount_moves, play.NumberVariations, move);
				DrawPlayField(play.place);
				checker = play.WinCheck(play.NumberVariations);
				if (checker == 1)
				{
					cout << "First player won";
					break;
				}
				if (checker == 2)
				{
					cout << "Second player won";
					break;
				}
				Sleep(500);
				play.amount_moves++;
			}
			if (play.amount_moves == 9)
			{
				cout << "Draw";
			}
		}
		if (choose == 2)
		{
			StartGame(name1, name2);
			while (play.amount_moves != 9)
			{
				move = play.FindPossibleRandMoves(play.NumberVariations);
				play.MakePossibleRandMoves(play.amount_moves, play.NumberVariations, move);
				DrawPlayField(play.place);
				checker = play.WinCheck(play.NumberVariations);
				if (checker == 1)
				{
					cout << "First player won";
					break;
				}
				if (checker == 2)
				{
					cout << "Second player won";
					break;
				}
				Sleep(500);
				play.amount_moves++;
				if (play.amount_moves == 9)
				{
					break;
				}
				checker2 = play.MakeMoveCleverGamer(play.amount_moves, play.NumberVariations, play.place);
				DrawPlayField(play.place);
				checker = play.WinCheck(play.NumberVariations);
				if (checker == 1)
				{
					cout << "First player won";
					break;
				}
				if (checker == 2)
				{
					cout << "Second player won";
					break;
				}
				Sleep(500);
				play.amount_moves++;
			}
			if (play.amount_moves == 9)
			{
				cout << "Draw";
			}
		}
	}
}
