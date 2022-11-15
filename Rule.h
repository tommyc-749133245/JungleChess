#ifndef RULE_H
#define RULE_H
#include <iostream>
#include"display.h"
using namespace std;
class Rule
{
private:
	int x;
	int y;
	Display d;
	Player p;
	Player *ptrPlayer;
public:
	Rule();
	int getx();
	void setx(int temp);
	int gety();
	void sety(int temp);
	void copy(Display& obj);
	Player* getPlayer();
	void checkposition(int pieces);
	bool gameover();
	char* result();
	//Player A, Blue team
	bool checkPossibleMoveUpA(int pieces);
	bool checkPossibleMoveDownA(int pieces);
	bool checkPossibleMoveLeftA(int pieces);
	bool checkPossibleMoveRightA(int pieces);
	void captureUpA(int pieces);
	void captureDownA(int pieces);
	void captureLeftA(int pieces);
	void captureRightA(int pieces);
	//Player B, Red team
	bool checkPossibleMoveUpB(int pieces);
	bool checkPossibleMoveDownB(int pieces);
	bool checkPossibleMoveLeftB(int pieces);
	bool checkPossibleMoveRightB(int pieces);
	void captureUpB(int pieces);
	void captureDownB(int pieces);
	void captureLeftB(int pieces);
	void captureRightB(int pieces);

};
#endif