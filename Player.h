#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include"Board.h"
using namespace std;

class Player
{
private:
	Board b;
	bool blue_pieces[8];
	bool red_pieces[8];
public:
	Player();
	bool GetRedPieces(int x);
	void SetRedPieces(int x, bool temp);
	bool GetBluePieces(int x);
	void SetBluePieces(int x, bool temp);
};
#endif