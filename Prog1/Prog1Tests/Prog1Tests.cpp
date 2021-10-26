#include "pch.h"
#include "CppUnitTest.h"
#include "../Prog1/game.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Prog1Tests
{
	TEST_CLASS(GameClass)
	{
	public:
		int NumberVariations[NUMBER_OF_FIELDS] = { 0 };
		char place[ARRAY_LENGTH][ARRAY_HEIGHT] = { ' ' };
		TEST_METHOD(Checker_of_win)
		{
			Game play;
			NumberVariations[0] = 1;
			NumberVariations[1] = 1;
			NumberVariations[2] = 1;
			Assert::AreEqual(1, play.WinCheck(NumberVariations));
			NumberVariations[0] = 2;
			NumberVariations[1] = 2;
			NumberVariations[2] = 2;
			Assert::AreEqual(2, play.WinCheck(NumberVariations));
			NumberVariations[0] = 1;
			NumberVariations[1] = 2;
			NumberVariations[2] = 2;
			Assert::AreEqual(0, play.WinCheck(NumberVariations));
		}
		
		TEST_METHOD(Find_possible_rand_moves)//оптимизация
		{
			Game play;			
			NumberVariations[0] = 1;
			NumberVariations[1] = 1;
			NumberVariations[2] = 2;
			NumberVariations[3] = 1;
			NumberVariations[4] = 2;
			NumberVariations[5] = 1;
			NumberVariations[6] = 2;
			NumberVariations[7] = 1;
			Assert::AreEqual(8, play.FindPossibleRandMoves(NumberVariations));
			NumberVariations[0] = 1;
			NumberVariations[1] = 1;
			NumberVariations[2] = 2;
			NumberVariations[3] = 1;
			NumberVariations[4] = 2;
			NumberVariations[5] = 1;
			NumberVariations[6] = 2;
			NumberVariations[7] = 0;
			NumberVariations[8] = 1;
			Assert::AreEqual(7, play.FindPossibleRandMoves(NumberVariations));


		}
		TEST_METHOD(Find_move_clever_gamer)
		{
			Game play;
			int amount_moves = 3;
			NumberVariations[4] = 1;
			NumberVariations[5] = 1;
			Assert::AreEqual(2, play.MakeMoveCleverGamer(amount_moves, NumberVariations, place));
			amount_moves = 4;
			NumberVariations[0] = 1;
			NumberVariations[1] = 1;
			Assert::AreEqual(1, play.MakeMoveCleverGamer(amount_moves, NumberVariations, place));
		}

	};
}
