#ifndef DISPLAY_H
#define DISPLAY_H
#include <iostream>
#include"Board.h"
#include"Player.h"
using namespace std;

class Display :public Board
{
private:
	Animal a;
	int choice;
	int MoveChoice;
public:
	Display();
	int getChoice();
	void setChoice(int temp);
	int getMove();
	void setMove(int temp);
	void displayboard();
};
#endif