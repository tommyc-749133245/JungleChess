#include <iostream>
#include <sstream>
#include <windows.h>
#include "Board.h"
using namespace std;

//constructor
Board::Board()
{
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 7; j++)
			g_iBoard[i][j] = 0;

	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

}
//accessor function for board
int Board::getBoard(int x, int y)
{
	return g_iBoard[x][y];
}
//mutator function for board
void Board::setBorad(int x, int y, int temp)
{
	g_iBoard[x][y] = temp;
}
//lines between columns
void Board::line()
{
	cout << "|";
	for (int i = 0; i < 78; i++)
		cout << "=";
	cout << "|";
}
//spaces between content
void Board::spaces(){
	cout << "||";
	for (int j = 0; j < 7; j++)
	{
		for (int i = 0; i < 9; i++)
			cout << " ";
		cout << "||";
	}
}
//display animal name and landscape
void Board::content(int i)
{
	cout << "||";
	for (int j = 0; j < 7; j++)
	{

		char* temp = displayName(i, j);
		if (temp != 0)
		{
			cout << " " << temp;
			SetConsoleTextAttribute(hConsole, 7);
			cout << "||";
		}
		else
		{
			for (int i = 0; i < 9; i++)
				cout << " ";
			cout << "||";
			continue;
		}
	}
}
//get animal name and landscape
char* Board::displayName(int x, int y)
{
	Animal a;
	Landscape l;
	switch (g_iBoard[x][y])
	{
	case 1:
		SetConsoleTextAttribute(hConsole, 9);
		return a.getanimalName(0);

	case 2:
		SetConsoleTextAttribute(hConsole, 9);
		return a.getanimalName(1);

	case 3:
		SetConsoleTextAttribute(hConsole, 9);
		return a.getanimalName(2);

	case 4:
		SetConsoleTextAttribute(hConsole, 9);
		return a.getanimalName(3);

	case 5:
		SetConsoleTextAttribute(hConsole, 9);
		return a.getanimalName(4);

	case 6:
		SetConsoleTextAttribute(hConsole, 9);
		return a.getanimalName(5);

	case 7:
		SetConsoleTextAttribute(hConsole, 9);
		return a.getanimalName(6);

	case 8:
		SetConsoleTextAttribute(hConsole, 9);
		return a.getanimalName(7);

	case 9:
		SetConsoleTextAttribute(hConsole, 12);
		return a.getanimalName(0);

	case 10:
		SetConsoleTextAttribute(hConsole, 12);
		return a.getanimalName(1);

	case 11:
		SetConsoleTextAttribute(hConsole, 12);
		return a.getanimalName(2);

	case 12:
		SetConsoleTextAttribute(hConsole, 12);
		return a.getanimalName(3);

	case 13:
		SetConsoleTextAttribute(hConsole, 12);
		return a.getanimalName(4);

	case 14:
		SetConsoleTextAttribute(hConsole, 12);
		return a.getanimalName(5);

	case 15:
		SetConsoleTextAttribute(hConsole, 12);
		return a.getanimalName(6);

	case 16:
		SetConsoleTextAttribute(hConsole, 12);
		return a.getanimalName(7);

	case 17: case 21:
		return l.getLandscapeName(0);

	case 18: case 22:
		return l.getLandscapeName(1);

	case 19:
		SetConsoleTextAttribute(hConsole, 11);
		return l.getLandscapeName(2);

	default:
		return a.getanimalName(8);

	}
}