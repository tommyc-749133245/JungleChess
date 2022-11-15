#include <iostream>
#include <windows.h>
#include"Game.h"
using namespace std;

int main()
{
	Game g;
	HANDLE hConsole;
	bool gameover;
	char* result;
	//game initialize
	g.Initialize();
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	do{
		//display game board
		g.display();
		//-------------------------------
		//Team A
		//-------------------------------
		cout << " Team: ";
		SetConsoleTextAttribute(hConsole, 9);
		cout << "A" << endl;
		SetConsoleTextAttribute(hConsole, 7);
		//Pieces selection of Player A
		g.displayPiecesSelectionA();
		//Possible move of piece
		g.displayPossibleMoveA();
		//pieces movement function
		g.MoveA();
		system("cls");
		//display game board
		g.display();
		//-------------------------------
		//Team B
		//-------------------------------
		cout << " Team: ";
		SetConsoleTextAttribute(hConsole, 12);
		cout << "B" << endl;
		SetConsoleTextAttribute(hConsole, 7);
		//Pieces selection of Player B
		g.displayPiecesSelectionB();
		//Possible move of piece
		g.displayPossibleMoveB();
		//pieces movement function
		g.MoveB();
		system("cls");
		//update the boolean gameover
		gameover = g.gameover();
	} while (gameover);
	g.display();
	result = g.result();
	cout << result << endl;
	system("pause");
}