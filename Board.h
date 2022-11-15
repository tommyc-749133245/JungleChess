#ifndef BOARD_H
#define BOARD_H
#include <iostream>
#include <windows.h>
#include"Animal.h"
#include"Landscape.h"
using namespace std;


class Board
{
protected:
HANDLE hConsole;
int	g_iBoard[9][7];
public:
	Board();
	int getBoard(int x, int y);
	void setBorad(int x, int y, int temp);
	void line();
	void spaces();
	void content(int i);
	char* displayName(int x, int y);
};
#endif