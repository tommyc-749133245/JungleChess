#ifndef GAME_H
#define GAME_H
#include <iostream>
#include "display.h"
#include"Rule.h"
using namespace std;
class Game
{
private:
	Display d;
	Animal a;
	Rule r;
	Player *ptrPlayer;
public:
	Game();
	void Initialize();
	void display();
	int convert(int pieces);
	void displayPiecesSelectionA();
	void displayPiecesSelectionB();
	void displayPossibleMoveA();
	void displayPossibleMoveB();
	void MoveA();
	void MoveB();
	bool gameover();
	char* result();
};
#endif