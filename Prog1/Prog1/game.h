#include <iostream>
#include <clocale>
#include <string>
#include <Windows.h>
#include <stdlib.h>
#include <limits>
#undef max

const unsigned int HEIGHT_PLAYFIELD = 24;
const unsigned int ARRAY_LENGTH = 73;
const unsigned int ARRAY_HEIGHT = 25;
const unsigned int NUMBER_OF_FIELDS = 9;
const unsigned int TEST_INPUT = 160;
using namespace std;

class Game
{
public:
	char place[ARRAY_LENGTH][ARRAY_HEIGHT] = { ' ' };
	int amount_moves = 0;
	string name;
	int NumberVariations[NUMBER_OF_FIELDS] = { 0 };
	int number;
	int checkermoves = 0;
	
	int WinCheck(int NumberVariations[NUMBER_OF_FIELDS])
	{
		if (((NumberVariations[0] == 1) && (NumberVariations[1] == 1) && (NumberVariations[2] == 1))\
			|| (NumberVariations[3] == 1) && (NumberVariations[4] == 1) && (NumberVariations[5] == 1)\
			|| (NumberVariations[6] == 1) && (NumberVariations[7] == 1) && (NumberVariations[8] == 1)\
			|| (NumberVariations[0] == 1) && (NumberVariations[3] == 1) && (NumberVariations[6] == 1)\
			|| (NumberVariations[1] == 1) && (NumberVariations[4] == 1) && (NumberVariations[7] == 1)\
			|| (NumberVariations[2] == 1) && (NumberVariations[5] == 1) && (NumberVariations[8] == 1)\
			|| (NumberVariations[0] == 1) && (NumberVariations[4] == 1) && (NumberVariations[8] == 1)\
			|| (NumberVariations[2] == 1) && (NumberVariations[4] == 1) && (NumberVariations[6] == 1))
		{
			return(1);
		}
		if (((NumberVariations[0] == 2) && (NumberVariations[1] == 2) && (NumberVariations[2] == 2))\
			|| (NumberVariations[3] == 2) && (NumberVariations[4] == 2) && (NumberVariations[5] == 2)\
			|| (NumberVariations[6] == 2) && (NumberVariations[7] == 2) && (NumberVariations[8] == 2)\
			|| (NumberVariations[0] == 2) && (NumberVariations[3] == 2) && (NumberVariations[6] == 2)\
			|| (NumberVariations[1] == 2) && (NumberVariations[4] == 2) && (NumberVariations[7] == 2)\
			|| (NumberVariations[2] == 2) && (NumberVariations[5] == 2) && (NumberVariations[8] == 2)\
			|| (NumberVariations[0] == 2) && (NumberVariations[4] == 2) && (NumberVariations[8] == 2)\
			|| (NumberVariations[2] == 2) && (NumberVariations[4] == 2) && (NumberVariations[6] == 2))
		{
			return(2);
		}
		else
		{
			return(0);
		}
	}

	void DrawCross(char place[ARRAY_LENGTH][ARRAY_HEIGHT],  int x, int y)
	{
		place[x - 3][y - 3] = '0';
		place[x + 3][y - 3] = '0';
		place[x - 2][y - 2] = '0';
		place[x + 2][y - 2] = '0';
		place[x - 1][y - 1] = '0';
		place[x + 1][y - 1] = '0';
		place[x][y] = '0';
		place[x - 1][y + 1] = '0';
		place[x + 1][y + 1] = '0';
		place[x - 2][y + 2] = '0';
		place[x + 2][y + 2] = '0';
		place[x - 3][y + 3] = '0';
		place[x + 3][y + 3] = '0';
	}

	void DrawCircle(char place[ARRAY_LENGTH][ARRAY_HEIGHT], int x, int y)
	{
		place[x - 1][y - 3] = '0';
		place[x][y - 3] = '0';
		place[x + 1][y - 3] = '0';
		place[x - 2][y - 2] = '0';
		place[x + 2][y - 2] = '0';
		place[x - 3][y - 2] = '0';
		place[x + 3][y - 2] = '0';
		place[x - 4][y - 1] = '0';
		place[x + 4][y - 1] = '0';
		place[x - 4][y] = '0';
		place[x + 4][y] = '0';
		place[x - 4][y + 1] = '0';
		place[x + 4][y + 1] = '0';
		place[x - 2][y + 2] = '0';
		place[x + 2][y + 2] = '0';
		place[x - 3][y + 2] = '0';
		place[x + 3][y + 2] = '0';
		place[x - 1][y + 3] = '0';
		place[x][y + 3] = '0';
		place[x + 1][y + 3] = '0';
	}

	int FindPossibleRandMoves(int NumberVariations[NUMBER_OF_FIELDS])
	{
		int move = 0;
		for (;;)
		{
			srand(time(0));
			move = rand() % 9;
			if (NumberVariations[move] == 0)
			{
				return(move);
			}
		}
	}

	void MakePossibleRandMoves(int amount_moves, int NumberVariations[NUMBER_OF_FIELDS], int move)
	{
		if (amount_moves % 2 == 0)
		{
			if (NumberVariations[move] == 0)
			{
				NumberVariations[move] = 1;
				switch (move + 1)
				{
				case 1:
					DrawCross(place, 12, 4);
					break;
				case 2:
					DrawCross(place, 35, 4);
					break;
				case 3:
					DrawCross(place, 58, 4);
					break;
				case 4:
					DrawCross(place, 12, 12);
					break;
				case 5:
					DrawCross(place, 35, 12);
					break;
				case 6:
					DrawCross(place, 58, 12);
					break;
				case 7:
					DrawCross(place, 12, 20);
					break;
				case 8:
					DrawCross(place, 35, 20);
					break;
				case 9:
					DrawCross(place, 58, 20);
					break;

				default:
					break;
				}
			}
		}
		else
		{
			if (NumberVariations[move] == 0)
			{
				NumberVariations[move] = 2;
				switch (move + 1)
				{
				case 1:
					DrawCircle(place, 12, 4);
					break;
				case 2:
					DrawCircle(place, 35, 4);
					break;
				case 3:
					DrawCircle(place, 58, 4);
					break;
				case 4:
					DrawCircle(place, 12, 12);
					break;
				case 5:
					DrawCircle(place, 35, 12);
					break;
				case 6:
					DrawCircle(place, 58, 12);
					break;
				case 7:
					DrawCircle(place, 12, 20);
					break;
				case 8:
					DrawCircle(place, 35, 20);
					break;
				case 9:
					DrawCircle(place, 58, 20);
					break;

				default:
					break;
				}
			}
		}
	}

	int MakeMoveCleverGamer(int amount_moves, int NumberVariations[NUMBER_OF_FIELDS])
	{
		if (amount_moves % 2 == 0)
		{
			if ((NumberVariations[0] == 1) && (NumberVariations[1] == 1) && (NumberVariations[2] == 0))
			{
				NumberVariations[2] = 1;
				DrawCross(place, 58, 4);
				return(1);
			}
			if ((NumberVariations[1] == 1) && (NumberVariations[2] == 1) && (NumberVariations[0] == 0))
			{
				NumberVariations[0] = 1;
				DrawCross(place, 12, 4);
				return(1);
			}
			if ((NumberVariations[0] == 1) && (NumberVariations[2] == 1) && (NumberVariations[1] == 0))
			{
				NumberVariations[1] = 1;
				DrawCross(place, 35, 4);
				return(1);
			}
			if ((NumberVariations[3] == 1) && (NumberVariations[4] == 1) && (NumberVariations[5] == 0))
			{
				NumberVariations[5] = 1;
				DrawCross(place, 58, 12);
				return(1);
			}
			if ((NumberVariations[4] == 1) && (NumberVariations[5] == 1) && (NumberVariations[3] == 0))
			{
				NumberVariations[3] = 1;
				DrawCross(place, 12, 12);
				return(1);
			}
			if ((NumberVariations[3] == 1) && (NumberVariations[5] == 1) && (NumberVariations[4] == 0))
			{
				NumberVariations[4] = 1;
				DrawCross(place, 35, 12);
				return(1);
			}
			if ((NumberVariations[6] == 1) && (NumberVariations[7] == 1) && (NumberVariations[8] == 0))
			{
				NumberVariations[8] = 1;
				DrawCross(place, 58, 20);
				return(1);
			}
			if ((NumberVariations[7] == 1) && (NumberVariations[8] == 1) && (NumberVariations[6] == 0))
			{
				NumberVariations[6] = 1;
				DrawCross(place, 12, 20);
				return(1);
			}
			if ((NumberVariations[6] == 1) && (NumberVariations[8] == 1) && (NumberVariations[7] == 0))
			{
				NumberVariations[7] = 1;
				DrawCross(place, 35, 20);
				return(1);
			}
			if ((NumberVariations[0] == 1) && (NumberVariations[3] == 1) && (NumberVariations[6] == 0))
			{
				NumberVariations[6] = 1;
				DrawCross(place, 12, 20);
				return(1);
			}
			if ((NumberVariations[3] == 1) && (NumberVariations[6] == 1) && (NumberVariations[0] == 0))
			{
				NumberVariations[0] = 1;
				DrawCross(place, 12, 4);
				return(1);
			}
			if ((NumberVariations[0] == 1) && (NumberVariations[6] == 1) && (NumberVariations[3] == 0))
			{
				NumberVariations[3] = 1;
				DrawCross(place, 12, 12);
				return(1);
			}
			if ((NumberVariations[1] == 1) && (NumberVariations[4] == 1) && (NumberVariations[7] == 0))
			{
				NumberVariations[7] = 1;
				DrawCross(place, 35, 20);
				return(1);
			}
			if ((NumberVariations[4] == 1) && (NumberVariations[7] == 1) && (NumberVariations[1] == 0))
			{
				NumberVariations[1] = 1;
				DrawCross(place, 35, 4);
				return(1);
			}
			if ((NumberVariations[1] == 1) && (NumberVariations[7] == 1) && (NumberVariations[4] == 0))
			{
				NumberVariations[4] = 1;
				DrawCross(place, 35, 12);
				return(1);
			}
			if ((NumberVariations[2] == 1) && (NumberVariations[5] == 1) && (NumberVariations[8] == 0))
			{
				NumberVariations[8] = 1;
				DrawCross(place, 58, 20);
				return(1);
			}
			if ((NumberVariations[5] == 1) && (NumberVariations[8] == 1) && (NumberVariations[2] == 0))
			{
				NumberVariations[2] = 1;
				DrawCross(place, 58, 4);
				return(1);
			}
			if ((NumberVariations[2] == 1) && (NumberVariations[8] == 1) && (NumberVariations[5] == 0))
			{
				NumberVariations[5] = 1;
				DrawCross(place, 58, 12);
				return(1);
			}
			if ((NumberVariations[0] == 1) && (NumberVariations[4] == 1) && (NumberVariations[8] == 0))
			{
				NumberVariations[8] = 1;
				DrawCross(place, 58, 20);
				return(1);
			}
			if ((NumberVariations[4] == 1) && (NumberVariations[8] == 1) && (NumberVariations[0] == 0))
			{
				NumberVariations[0] = 1;
				DrawCross(place, 12, 4);
				return(1);
			}
			if ((NumberVariations[0] == 1) && (NumberVariations[8] == 1) && (NumberVariations[4] == 0))
			{
				NumberVariations[4] = 1;
				DrawCross(place, 35, 12);
				return(1);
			}
			if ((NumberVariations[2] == 1) && (NumberVariations[4] == 1) && (NumberVariations[6] == 0))
			{
				NumberVariations[6] = 1;
				DrawCross(place, 12, 20);
				return(1);
			}
			if ((NumberVariations[4] == 1) && (NumberVariations[6] == 1) && (NumberVariations[2] == 0))
			{
				NumberVariations[2] = 1;
				DrawCross(place, 58, 4);
				return(1);
			}
			if ((NumberVariations[2] == 1) && (NumberVariations[6] == 1) && (NumberVariations[4] == 0))
			{
				NumberVariations[4] = 1;
				DrawCross(place, 35, 12);
				return(1);
			}
			if ((NumberVariations[0] == 2) && (NumberVariations[1] == 2) && (NumberVariations[2] == 0))
			{
				NumberVariations[2] = 1;
				DrawCross(place, 58, 4);
				return(1);
			}
			if ((NumberVariations[1] == 2) && (NumberVariations[2] == 2) && (NumberVariations[0] == 0))
			{
				NumberVariations[0] = 1;
				DrawCross(place, 12, 4);
				return(1);
			}
			if ((NumberVariations[0] == 2) && (NumberVariations[2] == 2) && (NumberVariations[1] == 0))
			{
				NumberVariations[1] = 1;
				DrawCross(place, 35, 4);
				return(1);
			}
			if ((NumberVariations[3] == 2) && (NumberVariations[4] == 2) && (NumberVariations[5] == 0))
			{
				NumberVariations[5] = 1;
				DrawCross(place, 58, 12);
				return(1);
			}
			if ((NumberVariations[4] == 2) && (NumberVariations[5] == 2) && (NumberVariations[3] == 0))
			{
				NumberVariations[3] = 1;
				DrawCross(place, 12, 12);
				return(1);
			}
			if ((NumberVariations[3] == 2) && (NumberVariations[5] == 2) && (NumberVariations[4] == 0))
			{
				NumberVariations[4] = 1;
				DrawCross(place, 35, 12);
				return(1);
			}
			if ((NumberVariations[6] == 2) && (NumberVariations[7] == 2) && (NumberVariations[8] == 0))
			{
				NumberVariations[8] = 1;
				DrawCross(place, 58, 20);
				return(1);
			}
			if ((NumberVariations[7] == 2) && (NumberVariations[8] == 2) && (NumberVariations[6] == 0))
			{
				NumberVariations[6] = 1;
				DrawCross(place, 12, 20);
				return(1);
			}
			if ((NumberVariations[6] == 2) && (NumberVariations[8] == 2) && (NumberVariations[7] == 0))
			{
				NumberVariations[7] = 1;
				DrawCross(place, 35, 20);
				return(1);
			}
			if ((NumberVariations[0] == 2) && (NumberVariations[3] == 2) && (NumberVariations[6] == 0))
			{
				NumberVariations[6] = 1;
				DrawCross(place, 12, 20);
				return(1);
			}
			if ((NumberVariations[3] == 2) && (NumberVariations[6] == 2) && (NumberVariations[0] == 0))
			{
				NumberVariations[0] = 1;
				DrawCross(place, 12, 4);
				return(1);
			}
			if ((NumberVariations[0] == 2) && (NumberVariations[6] == 2) && (NumberVariations[3] == 0))
			{
				NumberVariations[3] = 1;
				DrawCross(place, 12, 12);
				return(1);
			}
			if ((NumberVariations[1] == 2) && (NumberVariations[4] == 2) && (NumberVariations[7] == 0))
			{
				NumberVariations[7] = 1;
				DrawCross(place, 35, 20);
				return(1);
			}
			if ((NumberVariations[4] == 2) && (NumberVariations[7] == 2) && (NumberVariations[1] == 0))
			{
				NumberVariations[1] = 1;
				DrawCross(place, 35, 4);
				return(1);
			}
			if ((NumberVariations[1] == 2) && (NumberVariations[7] == 2) && (NumberVariations[4] == 0))
			{
				NumberVariations[4] = 1;
				DrawCross(place, 35, 12);
				return(1);
			}
			if ((NumberVariations[2] == 2) && (NumberVariations[5] == 2) && (NumberVariations[8] == 0))
			{
				NumberVariations[8] = 1;
				DrawCross(place, 58, 20);
				return(1);
			}
			if ((NumberVariations[5] == 2) && (NumberVariations[8] == 2) && (NumberVariations[2] == 0))
			{
				NumberVariations[2] = 1;
				DrawCross(place, 58, 4);
				return(1);
			}
			if ((NumberVariations[2] == 2) && (NumberVariations[8] == 2) && (NumberVariations[5] == 0))
			{
				NumberVariations[5] = 1;
				DrawCross(place, 58, 12);
				return(1);
			}
			if ((NumberVariations[0] == 2) && (NumberVariations[4] == 2) && (NumberVariations[8] == 0))
			{
				NumberVariations[8] = 1;
				DrawCross(place, 58, 20);
				return(1);
			}
			if ((NumberVariations[4] == 2) && (NumberVariations[8] == 2) && (NumberVariations[0] == 0))
			{
				NumberVariations[0] = 1;
				DrawCross(place, 12, 4);
				return(1);
			}
			if ((NumberVariations[0] == 2) && (NumberVariations[8] == 2) && (NumberVariations[4] == 0))
			{
				NumberVariations[4] = 1;
				DrawCross(place, 35, 12);
				return(1);
			}
			if ((NumberVariations[2] == 2) && (NumberVariations[4] == 2) && (NumberVariations[6] == 0))
			{
				NumberVariations[6] = 1;
				DrawCross(place, 12, 20);
				return(1);
			}
			if ((NumberVariations[4] == 2) && (NumberVariations[6] == 2) && (NumberVariations[2] == 0))
			{
				NumberVariations[2] = 1;
				DrawCross(place, 58, 4);
				return(1);
			}
			if ((NumberVariations[2] == 2) && (NumberVariations[6] == 2) && (NumberVariations[4] == 0))
			{
				NumberVariations[4] = 1;
				DrawCross(place, 35, 12);
				return(1);
			}
			int move = 0;
			for (;;)
			{
				srand(time(0));
				move = rand() % 9;
				if (NumberVariations[move] == 0)
				{
					break;
				}
			}
			if (NumberVariations[move] == 0)
			{
				NumberVariations[move] = 1;
				switch (move + 1)
				{
				case 1:
					DrawCross(place, 12, 4);
					break;
				case 2:
					DrawCross(place, 35, 4);
					break;
				case 3:
					DrawCross(place, 58, 4);
					break;
				case 4:
					DrawCross(place, 12, 12);
					break;
				case 5:
					DrawCross(place, 35, 12);
					break;
				case 6:
					DrawCross(place, 58, 12);
					break;
				case 7:
					DrawCross(place, 12, 20);
					break;
				case 8:
					DrawCross(place, 35, 20);
					break;
				case 9:
					DrawCross(place, 58, 20);
					break;

				default:
					break;
				}
			}
			return(amount_moves);
		}

		if(amount_moves %2 == 1)
		{
			if ((NumberVariations[0] == 2) && (NumberVariations[1] == 2) && (NumberVariations[2] == 0))
			{
				NumberVariations[2] = 2;
				DrawCircle(place, 58, 4);
				return(2);
			}
				if ((NumberVariations[1] == 2) && (NumberVariations[2] == 2) && (NumberVariations[0] == 0))
				{
					NumberVariations[0] = 2;
					DrawCircle(place, 12, 4);
					return(2);
				}
				if ((NumberVariations[0] == 2) && (NumberVariations[2] == 2) && (NumberVariations[1] == 0))
				{
					NumberVariations[1] = 2;
					DrawCircle(place, 35, 4);
					return(2);
				}
				if ((NumberVariations[3] == 2) && (NumberVariations[4] == 2) && (NumberVariations[5] == 0))
				{
					NumberVariations[5] = 2;
					DrawCircle(place, 58, 12);
					return(2);
				}
				if ((NumberVariations[4] == 2) && (NumberVariations[5] == 2) && (NumberVariations[3] == 0))
				{
					NumberVariations[3] = 2;
					DrawCircle(place, 12, 12);
					return(2);
				}
				if ((NumberVariations[3] == 2) && (NumberVariations[5] == 2) && (NumberVariations[4] == 0))
				{
					NumberVariations[4] = 2;
					DrawCircle(place, 35, 12);
					return(2);
				}
				if ((NumberVariations[6] == 2) && (NumberVariations[7] == 2) && (NumberVariations[8] == 0))
				{
					NumberVariations[8] = 2;
					DrawCircle(place, 58, 20);
					return(2);
				}
				if ((NumberVariations[7] == 2) && (NumberVariations[8] == 2) && (NumberVariations[6] == 0))
				{
					NumberVariations[6] = 2;
					DrawCircle(place, 12, 20);
					return(2);
				}
				if ((NumberVariations[6] == 2) && (NumberVariations[8] == 2) && (NumberVariations[7] == 0))
				{
					NumberVariations[7] = 2;
					DrawCircle(place, 35, 20);
					return(2);
				}
				if ((NumberVariations[0] == 2) && (NumberVariations[3] == 2) && (NumberVariations[6] == 0))
				{
					NumberVariations[6] = 2;
					DrawCircle(place, 12, 20);
					return(2);
				}
				if ((NumberVariations[3] == 2) && (NumberVariations[6] == 2) && (NumberVariations[0] == 0))
				{
					NumberVariations[0] = 2;
					DrawCircle(place, 12, 4);
					return(2);
				}
				if ((NumberVariations[0] == 2) && (NumberVariations[6] == 2) && (NumberVariations[3] == 0))
				{
					NumberVariations[3] = 2;
					DrawCircle(place, 12, 12);
					return(2);
				}
				if ((NumberVariations[1] == 2) && (NumberVariations[4] == 2) && (NumberVariations[7] == 0))
				{
					NumberVariations[7] = 2;
					DrawCircle(place, 35, 20);
					return(2);
				}
				if ((NumberVariations[4] == 2) && (NumberVariations[7] == 2) && (NumberVariations[1] == 0))
				{
					NumberVariations[1] = 2;
					DrawCircle(place, 35, 4);
					return(2);
				}
				if ((NumberVariations[1] == 2) && (NumberVariations[7] == 2) && (NumberVariations[4] == 0))
				{
					NumberVariations[4] = 2;
					DrawCircle(place, 35, 12);
					return(2);
				}
				if ((NumberVariations[2] == 2) && (NumberVariations[5] == 2) && (NumberVariations[8] == 0))
				{
					NumberVariations[8] = 2;
					DrawCircle(place, 58, 20);
					return(2);
				}
				if ((NumberVariations[5] == 2) && (NumberVariations[8] == 2) && (NumberVariations[2] == 0))
				{
					NumberVariations[2] = 2;
					DrawCircle(place, 58, 4);
					return(2);
				}
				if ((NumberVariations[2] == 2) && (NumberVariations[8] == 2) && (NumberVariations[5] == 0))
				{
					NumberVariations[5] = 2;
					DrawCircle(place, 58, 12);
					return(2);
				}
				if ((NumberVariations[0] == 2) && (NumberVariations[4] == 2) && (NumberVariations[8] == 0))
				{
					NumberVariations[8] = 2;
					DrawCircle(place, 58, 20);
					return(2);
				}
				if ((NumberVariations[4] == 2) && (NumberVariations[8] == 2) && (NumberVariations[0] == 0))
				{
					NumberVariations[0] = 2;
					DrawCircle(place, 12, 4);
					return(2);
				}
				if ((NumberVariations[0] == 2) && (NumberVariations[8] == 2) && (NumberVariations[4] == 0))
				{
					NumberVariations[4] = 2;
					DrawCircle(place, 35, 12);
					return(2);
				}
				if ((NumberVariations[2] == 2) && (NumberVariations[4] == 2) && (NumberVariations[6] == 0))
				{
					NumberVariations[6] = 2;
					DrawCircle(place, 12, 20);
					return(2);
				}
				if ((NumberVariations[4] == 2) && (NumberVariations[6] == 2) && (NumberVariations[2] == 0))
				{
					NumberVariations[2] = 2;
					DrawCircle(place, 58, 4);
					return(2);
				}
				if ((NumberVariations[2] == 2) && (NumberVariations[6] == 2) && (NumberVariations[4] == 0))
				{
					NumberVariations[4] = 2;
					DrawCircle(place, 35, 12);
					return(2);
				}
				if ((NumberVariations[0] == 1) && (NumberVariations[1] == 1) && (NumberVariations[2] == 0))
				{
					NumberVariations[2] = 2;
					DrawCircle(place, 58, 4);
					return(2);
				}
				if ((NumberVariations[1] == 1) && (NumberVariations[2] == 1) && (NumberVariations[0] == 0))
				{
					NumberVariations[0] = 2;
					DrawCircle(place, 12, 4);
					return(2);
				}
				if ((NumberVariations[0] == 1) && (NumberVariations[2] == 1) && (NumberVariations[1] == 0))
				{
					NumberVariations[1] = 2;
					DrawCircle(place, 35, 4);
					return(2);
				}
				if ((NumberVariations[3] == 1) && (NumberVariations[4] == 1) && (NumberVariations[5] == 0))
				{
					NumberVariations[5] = 2;
					DrawCircle(place, 58, 12);
					return(2);
				}
				if ((NumberVariations[4] == 1) && (NumberVariations[5] == 1) && (NumberVariations[3] == 0))
				{
					NumberVariations[3] = 2;
					DrawCircle(place, 12, 12);
					return(2);
				}
				if ((NumberVariations[3] == 1) && (NumberVariations[5] == 1) && (NumberVariations[4] == 0))
				{
					NumberVariations[4] = 2;
					DrawCircle(place, 35, 12);
					return(2);
				}
				if ((NumberVariations[6] == 1) && (NumberVariations[7] == 1) && (NumberVariations[8] == 0))
				{
					NumberVariations[8] = 2;
					DrawCircle(place, 58, 20);
					return(2);
				}
				if ((NumberVariations[7] == 1) && (NumberVariations[8] == 1) && (NumberVariations[6] == 0))
				{
					NumberVariations[6] = 2;
					DrawCircle(place, 12, 20);
					return(2);
				}
				if ((NumberVariations[6] == 1) && (NumberVariations[8] == 1) && (NumberVariations[7] == 0))
				{
					NumberVariations[7] = 2;
					DrawCircle(place, 35, 20);
					return(2);
				}
				if ((NumberVariations[0] == 1) && (NumberVariations[3] == 1) && (NumberVariations[6] == 0))
				{
					NumberVariations[6] = 2;
					DrawCircle(place, 12, 20);
					return(2);
				}
				if ((NumberVariations[3] == 1) && (NumberVariations[6] == 1) && (NumberVariations[0] == 0))
				{
					NumberVariations[0] = 2;
					DrawCircle(place, 12, 4);
					return(2);
				}
				if ((NumberVariations[0] == 1) && (NumberVariations[6] == 1) && (NumberVariations[3] == 0))
				{
					NumberVariations[3] = 2;
					DrawCircle(place, 12, 12);
					return(2);
				}
				if ((NumberVariations[1] == 1) && (NumberVariations[4] == 1) && (NumberVariations[7] == 0))
				{
					NumberVariations[7] = 2;
					DrawCircle(place, 35, 20);
					return(2);
				}
				if ((NumberVariations[4] == 1) && (NumberVariations[7] == 1) && (NumberVariations[1] == 0))
				{
					NumberVariations[1] = 2;
					DrawCircle(place, 35, 4);
					return(2);
				}
				if ((NumberVariations[1] == 1) && (NumberVariations[7] == 1) && (NumberVariations[4] == 0))
				{
					NumberVariations[4] = 2;
					DrawCircle(place, 35, 12);
					return(2);
				}
				if ((NumberVariations[2] == 1) && (NumberVariations[5] == 1) && (NumberVariations[8] == 0))
				{
					NumberVariations[8] = 2;
					DrawCircle(place, 58, 20);
					return(2);
				}
				if ((NumberVariations[5] == 1) && (NumberVariations[8] == 1) && (NumberVariations[2] == 0))
				{
					NumberVariations[2] = 2;
					DrawCircle(place, 58, 4);
					return(2);
				}
				if ((NumberVariations[2] == 1) && (NumberVariations[8] == 1) && (NumberVariations[5] == 0))
				{
					NumberVariations[5] = 2;
					DrawCircle(place, 58, 12);
					return(2);
				}
				if ((NumberVariations[0] == 1) && (NumberVariations[4] == 1) && (NumberVariations[8] == 0))
				{
					NumberVariations[8] = 2;
					DrawCircle(place, 58, 20);
					return(2);
				}
				if ((NumberVariations[4] == 1) && (NumberVariations[8] == 1) && (NumberVariations[0] == 0))
				{
					NumberVariations[0] = 2;
					DrawCircle(place, 12, 4);
					return(2);
				}
				if ((NumberVariations[0] == 1) && (NumberVariations[8] == 1) && (NumberVariations[4] == 0))
				{
					NumberVariations[4] = 2;
					DrawCircle(place, 35, 12);
					return(2);
				}
				if ((NumberVariations[2] == 1) && (NumberVariations[4] == 1) && (NumberVariations[6] == 0))
				{
					NumberVariations[6] = 2;
					DrawCircle(place, 12, 20);
					return(2);
				}
				if ((NumberVariations[4] == 1) && (NumberVariations[6] == 1) && (NumberVariations[2] == 0))
				{
					NumberVariations[2] = 2;
					DrawCircle(place, 58, 4);
					return(2);
				}
				if ((NumberVariations[2] == 1) && (NumberVariations[6] == 1) && (NumberVariations[4] == 0))
				{
					NumberVariations[4] = 2;
					DrawCircle(place, 35, 12);
					return(2);
				}	
				int move = 0;
				for (;;)
				{
					srand(time(0));
					move = rand() % 9;
					if (NumberVariations[move] == 0)
					{
						break;
					}
				}
				if (NumberVariations[move] == 0)
				{
					NumberVariations[move] = 2;
					switch (move + 1)
					{
					case 1:
						DrawCircle(place, 12, 4);
						break;
					case 2:
						DrawCircle(place, 35, 4);
						break;
					case 3:
						DrawCircle(place, 58, 4);
						break;
					case 4:
						DrawCircle(place, 12, 12);
						break;
					case 5:
						DrawCircle(place, 35, 12);
						break;
					case 6:
						DrawCircle(place, 58, 12);
						break;
					case 7:
						DrawCircle(place, 12, 20);
						break;
					case 8:
						DrawCircle(place, 35, 20);
						break;
					case 9:
						DrawCircle(place, 58, 20);
						break;

					default:
						break;
					}
				}
		}

		return(0);
	}

private:
};

class CleverGamer : public Game
{
public:
	string name;
};

class RandomGamer : public Game
{
public:
	string name;
};

