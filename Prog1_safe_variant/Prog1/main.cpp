#include "game.h"

void PressStart(string var2, Game play, string name1, string name2);

int main()
{
	setlocale(LC_ALL, "Russian");
	CleverGamer h1;
	RandomGamer h2;
	Game play;
	play.place[ARRAY_LENGTH][ARRAY_HEIGHT] = { ' ' };
	string name1 = "���� ";
	string name2 = "������ ";
	string var2;
	system("cls");
	cout << "�������� �������� ����: " << endl;
	cout << "1. ������ ������" << endl;
	cout << "2. ������ �������������(�� �������)" << endl;
	cin >> var2;
	PressStart(var2, play, name1, name2);
}
