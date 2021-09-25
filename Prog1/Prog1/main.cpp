#include "game.h"

void PressStart(string var2, Game play, string name1, string name2);

int main()
{
	setlocale(LC_ALL, "Russian");
	CleverGamer h1;
	RandomGamer h2;
	Game play;
	play.place[ARRAY_LENGTH][ARRAY_HEIGHT] = { ' ' };
	string name1 = "Рома ";
	string name2 = "Никита ";
	string var2;
	system("cls");
	cout << "Выберите варианты игры: " << endl;
	cout << "1. Играть самому" << endl;
	cout << "2. Играть автоматически(по заданию)" << endl;
	cin >> var2;
	PressStart(var2, play, name1, name2);
}
