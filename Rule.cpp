#include <iostream>
#include <sstream>
#include "Rule.h"
using namespace std;

//constructor
Rule::Rule()
{
	x = 0;
	y = 0;
}
//accessor function for x
int Rule::getx()
{
	return x;
}
//mutator function for x
void Rule::setx(int temp)
{
	x = temp;
}
//accessor function for y
int Rule::gety()
{
	return y;
}
//mutator function for y
void Rule::sety(int temp)
{
	y = temp;
}
//copy function for copying object from game.cpp
void Rule::copy(Display& obj)
{
	d = obj;
}
//return pointer to object to other class
Player* Rule::getPlayer()
{
	 return ptrPlayer = &p;
}
//member function for checking piece's position
void Rule::checkposition(int pieces)
{
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 7; j++)
			if (d.getBoard(i, j) == pieces)
			{
				setx(i);
				sety(j);
			}
}
//member function for gameover
bool Rule::gameover()
{
	if ((d.getBoard(0, 3) == 9)
		|| (d.getBoard(0, 3) == 10)
		|| (d.getBoard(0, 3) == 11)
		|| (d.getBoard(0, 3) == 12)
		|| (d.getBoard(0, 3) == 13)
		|| (d.getBoard(0, 3) == 14)
		|| (d.getBoard(0, 3) == 15)
		|| (d.getBoard(0, 3) == 16))
		return false;
	else if ((d.getBoard(8, 3) == 1)
		|| (d.getBoard(8, 3) == 2)
		|| (d.getBoard(8, 3) == 3)
		|| (d.getBoard(8, 3) == 4)
		|| (d.getBoard(8, 3) == 5)
		|| (d.getBoard(8, 3) == 6)
		|| (d.getBoard(8, 3) == 7)
		|| (d.getBoard(8, 3) == 8))
		return false;
	else if ((p.GetRedPieces(0) == false)
		&& (p.GetRedPieces(1) == false)
		&& (p.GetRedPieces(2) == false)
		&& (p.GetRedPieces(3) == false)
		&& (p.GetRedPieces(4) == false)
		&& (p.GetRedPieces(5) == false)
		&& (p.GetRedPieces(6) == false)
		&& (p.GetRedPieces(7) == false))
		return false;
	else if ((p.GetBluePieces(0) == false)
		&& (p.GetBluePieces(1) == false)
		&& (p.GetBluePieces(2) == false)
		&& (p.GetBluePieces(3) == false)
		&& (p.GetBluePieces(4) == false)
		&& (p.GetBluePieces(5) == false)
		&& (p.GetBluePieces(6) == false)
		&& (p.GetBluePieces(7) == false))
		return false;
	else
		return true;
}
char* Rule::result()
{
	if (((d.getBoard(8, 3) == 1)
		|| (d.getBoard(8, 3) == 2)
		|| (d.getBoard(8, 3) == 3)
		|| (d.getBoard(8, 3) == 4)
		|| (d.getBoard(8, 3) == 5)
		|| (d.getBoard(8, 3) == 6)
		|| (d.getBoard(8, 3) == 7)
		|| (d.getBoard(8, 3) == 8))
		|| ((p.GetRedPieces(0) == false)
		&& (p.GetRedPieces(1) == false)
		&& (p.GetRedPieces(2) == false)
		&& (p.GetRedPieces(3) == false)
		&& (p.GetRedPieces(4) == false)
		&& (p.GetRedPieces(5) == false)
		&& (p.GetRedPieces(6) == false)
		&& (p.GetRedPieces(7) == false)))
		return "Player A wins the game !";
	else if (((d.getBoard(0, 3) == 9)
		|| (d.getBoard(0, 3) == 10)
		|| (d.getBoard(0, 3) == 11)
		|| (d.getBoard(0, 3) == 12)
		|| (d.getBoard(0, 3) == 13)
		|| (d.getBoard(0, 3) == 14)
		|| (d.getBoard(0, 3) == 15)
		|| (d.getBoard(0, 3) == 16))
		|| ((p.GetBluePieces(0) == false)
		&& (p.GetBluePieces(1) == false)
		&& (p.GetBluePieces(2) == false)
		&& (p.GetBluePieces(3) == false)
		&& (p.GetBluePieces(4) == false)
		&& (p.GetBluePieces(5) == false)
		&& (p.GetBluePieces(6) == false)
		&& (p.GetBluePieces(7) == false)))
		return "Player B wins the game !";
}

//----------------------------------
//Player A, Blue team
//----------------------------------
bool Rule::checkPossibleMoveUpA(int pieces)
{
	int temp1 = x - 1;
	int temp2 = y;
	switch (pieces)
	{
		/*---------------------------------------
		Blue team
		------------------------------------------*/
	case 1:															//blue mouse
		if ((d.getBoard(temp1, temp2) == 2)							//same team
			|| (d.getBoard(temp1, temp2) == 3)
			|| (d.getBoard(temp1, temp2) == 4)
			|| (d.getBoard(temp1, temp2) == 5)
			|| (d.getBoard(temp1, temp2) == 6)
			|| (d.getBoard(temp1, temp2) == 7)
			|| (d.getBoard(temp1, temp2) == 8))
			return false;
		else if (d.getBoard(temp1 + 1, temp2) == 19)
		{
			if ((d.getBoard(temp1, temp2) == 9)
				|| (d.getBoard(temp1, temp2) == 10)
				|| (d.getBoard(temp1, temp2) == 11)
				|| (d.getBoard(temp1, temp2) == 12)
				|| (d.getBoard(temp1, temp2) == 13)
				|| (d.getBoard(temp1, temp2) == 14)
				|| (d.getBoard(temp1, temp2) == 15)
				|| (d.getBoard(temp1, temp2) == 16))
				return false;
			else
				return true;
		}
		else if ((temp1 >= 0)&&(d.getBoard(temp1,temp2)!=17))		//out of board and not den
			return true;
		else
			return false;

	case 2: case 3: case 4: case 5: case 8:							//blue
		if ((d.getBoard(temp1, temp2) == 1)							//same team
			|| (d.getBoard(temp1, temp2) == 2)
			|| (d.getBoard(temp1, temp2) == 3)
			|| (d.getBoard(temp1, temp2) == 4)
			|| (d.getBoard(temp1, temp2) == 5)
			|| (d.getBoard(temp1, temp2) == 6)
			|| (d.getBoard(temp1, temp2) == 7)
			|| (d.getBoard(temp1, temp2) == 8))
			return false;
		else if (!((temp1 == 5 && temp2 == 1)						//river
			|| (temp1 == 5 && temp2 == 2)
			|| (temp1 == 5 && temp2 == 4)
			|| (temp1 == 5 && temp2 == 5)))
		{
			if ((temp1 > -1) && (d.getBoard(temp1, temp2) != 17))	//out of board and not den
				return true;
			else
				return false;
		}
		else
			return false;
		case 6: case 7:												//lion and tiger
			if ((d.getBoard(temp1, temp2) == 1)						//same team
				|| (d.getBoard(temp1, temp2) == 2)
				|| (d.getBoard(temp1, temp2) == 3)
				|| (d.getBoard(temp1, temp2) == 4)
				|| (d.getBoard(temp1, temp2) == 5)
				|| (d.getBoard(temp1, temp2) == 6)
				|| (d.getBoard(temp1, temp2) == 7)
				|| (d.getBoard(temp1, temp2) == 8))
				return false;
			else if (d.getBoard(temp1, temp2) == 19)
			{
				if ((d.getBoard(temp1, temp2) == 1)
					|| (d.getBoard(temp1 - 1, temp2) == 1)
					|| (d.getBoard(temp1 - 2, temp2) == 1)
					|| (d.getBoard(temp1, temp2) == 9)
					|| (d.getBoard(temp1 - 1, temp2) == 9)
					|| (d.getBoard(temp1 - 2, temp2) == 9))
					return false;
			}
			else if ((temp1 >= 0) && (d.getBoard(temp1, temp2) != 17))		//out of board and not den
				return true;
			else
				return false;
	}
}
bool Rule::checkPossibleMoveDownA(int pieces)
{
	int temp1 = x + 1;
	int temp2 = gety();
	switch (pieces)
	{
		//--------------------------------------
		//Blue team
		//------------------------------------------
	case 1:											//blue mouse, lion and tiger
		if ((d.getBoard(temp1, temp2) == 1)
			||(d.getBoard(temp1, temp2) == 2)						//same team
			|| (d.getBoard(temp1, temp2) == 3)
			|| (d.getBoard(temp1, temp2) == 4)
			|| (d.getBoard(temp1, temp2) == 5)
			|| (d.getBoard(temp1, temp2) == 6)
			|| (d.getBoard(temp1, temp2) == 7)
			|| (d.getBoard(temp1, temp2) == 8))
			return false;
		else if (d.getBoard(temp1 - 1, temp2) == 19)
		{
			if ((d.getBoard(temp1, temp2) == 9)
				|| (d.getBoard(temp1, temp2) == 10)
				|| (d.getBoard(temp1, temp2) == 11)
				|| (d.getBoard(temp1, temp2) == 12)
				|| (d.getBoard(temp1, temp2) == 13)
				|| (d.getBoard(temp1, temp2) == 14)
				|| (d.getBoard(temp1, temp2) == 15)
				|| (d.getBoard(temp1, temp2) == 16))
				return false;
			else
				return true;
		}
		else if (temp1 < 9)											//out of board
			return true;
		else
			return false;

	case 2: case 3: case 4: case 5: case 8:							//blue
		if ((d.getBoard(temp1, temp2) == 1)							//same team
			|| (d.getBoard(temp1, temp2) == 2)
			|| (d.getBoard(temp1, temp2) == 3)
			|| (d.getBoard(temp1, temp2) == 4)
			|| (d.getBoard(temp1, temp2) == 5)
			|| (d.getBoard(temp1, temp2) == 6)
			|| (d.getBoard(temp1, temp2) == 7)
			|| (d.getBoard(temp1, temp2) == 8))
			return false;
		else if (!((temp1 == 3 && temp2 == 1)						//river
			|| (temp1 == 3 && temp2 == 2)
			|| (temp1 == 3 && temp2 == 4)
			|| (temp1 == 3 && temp2 == 5)))
		{
			if (temp1 < 9)											//out of board
				return true;
			else
				return false;
		}
		else
			return false;
	case 6: case 7:
		if ((d.getBoard(temp1, temp2) == 1)
			|| (d.getBoard(temp1, temp2) == 2)						//same team
			|| (d.getBoard(temp1, temp2) == 3)
			|| (d.getBoard(temp1, temp2) == 4)
			|| (d.getBoard(temp1, temp2) == 5)
			|| (d.getBoard(temp1, temp2) == 6)
			|| (d.getBoard(temp1, temp2) == 7)
			|| (d.getBoard(temp1, temp2) == 8))
			return false;
		else if (d.getBoard(temp1, temp2) == 19)
		{
			if ((d.getBoard(temp1, temp2) == 1)
				|| (d.getBoard(temp1 + 1, temp2) == 1)
				|| (d.getBoard(temp1 + 2, temp2) == 1)
				|| (d.getBoard(temp1, temp2) == 9)
				|| (d.getBoard(temp1 + 1, temp2) == 9)
				|| (d.getBoard(temp1 + 2, temp2) == 9))
				return false;
		}
		else if (temp1 < 9)											//out of board
			return true;
		else
			return false;
	}
}
bool Rule::checkPossibleMoveLeftA(int pieces)
{
	int temp1 = x;
	int temp2 = y - 1;
	switch (pieces)
	{
		//---------------------------------------
		//Blue team
		//------------------------------------------
	case 1:										//blue mouse, lion and tiger
		if ((d.getBoard(temp1, temp2) == 1)							//same team
			|| (d.getBoard(temp1, temp2) == 2)
			|| (d.getBoard(temp1, temp2) == 3)			
			|| (d.getBoard(temp1, temp2) == 4)
			|| (d.getBoard(temp1, temp2) == 5)
			|| (d.getBoard(temp1, temp2) == 6)
			|| (d.getBoard(temp1, temp2) == 7)
			|| (d.getBoard(temp1, temp2) == 8))
			return false;
		else if (d.getBoard(temp1, temp2 + 1) == 19)
		{
			if ((d.getBoard(temp1, temp2) == 9)
				|| (d.getBoard(temp1, temp2) == 10)
				|| (d.getBoard(temp1, temp2) == 11)
				|| (d.getBoard(temp1, temp2) == 12)
				|| (d.getBoard(temp1, temp2) == 13)
				|| (d.getBoard(temp1, temp2) == 14)
				|| (d.getBoard(temp1, temp2) == 15)
				|| (d.getBoard(temp1, temp2) == 16))
				return false;
			else
				return true;
		}
		else if ((temp2 > -1) && (d.getBoard(temp1, temp2) != 17)) //out of board
			return true;
		else
			return false;

	case 2: case 3: case 4: case 5: case 8:							//blue
		if ((d.getBoard(temp1, temp2) == 1)							//same team
			|| (d.getBoard(temp1, temp2) == 2)
			|| (d.getBoard(temp1, temp2) == 3)
			|| (d.getBoard(temp1, temp2) == 4)
			|| (d.getBoard(temp1, temp2) == 5)
			|| (d.getBoard(temp1, temp2) == 6)
			|| (d.getBoard(temp1, temp2) == 7)
			|| (d.getBoard(temp1, temp2) == 8))
			return false;
		else if (!((temp1 == 3 && temp2 == 2)						//river
			|| (temp1 == 4 && temp2 == 2)
			|| (temp1 == 5 && temp2 == 2)
			|| (temp1 == 3 && temp2 == 5)
			|| (temp1 == 4 && temp2 == 5)
			|| (temp1 == 5 && temp2 == 5)))
		{
			if ((temp2 > -1) && (d.getBoard(temp1, temp2) != 17))	//out of board
				return true;
			else
				return false;
		}
		else
			return false;

	case 6: case 7:
		if ((d.getBoard(temp1, temp2) == 1)
			|| (d.getBoard(temp1, temp2) == 2)						//same team
			|| (d.getBoard(temp1, temp2) == 3)
			|| (d.getBoard(temp1, temp2) == 4)
			|| (d.getBoard(temp1, temp2) == 5)
			|| (d.getBoard(temp1, temp2) == 6)
			|| (d.getBoard(temp1, temp2) == 7)
			|| (d.getBoard(temp1, temp2) == 8))
			return false;
		else if (d.getBoard(temp1, temp2) == 19)
		{
			if ((d.getBoard(temp1, temp2) == 1)
				|| (d.getBoard(temp1, temp2 - 1) == 1)
				|| (d.getBoard(temp1, temp2) == 9)
				|| (d.getBoard(temp1 + 1, temp2 - 1) == 9))
				return false;
		}
		else if ((temp2 > -1) && (d.getBoard(temp1, temp2) != 17))	//out of board
			return true;
		else
			return false;
	}
}
bool Rule::checkPossibleMoveRightA(int pieces)
{
	int temp1 = x;
	int temp2 = y + 1;
	switch (pieces)
	{
		//---------------------------------------
		//Blue team
		//------------------------------------------
	case 1:															//blue mouse, lion and tiger
		if ((d.getBoard(temp1, temp2) == 1)							//same team
			|| (d.getBoard(temp1, temp2) == 2)
			|| (d.getBoard(temp1, temp2) == 3)
			|| (d.getBoard(temp1, temp2) == 4)
			|| (d.getBoard(temp1, temp2) == 5)
			|| (d.getBoard(temp1, temp2) == 6)
			|| (d.getBoard(temp1, temp2) == 7)
			|| (d.getBoard(temp1, temp2) == 8))
			return false;
		else if (d.getBoard(temp1, temp2 - 1) == 19)
		{
			if ((d.getBoard(temp1, temp2) == 9)
				|| (d.getBoard(temp1, temp2) == 10)
				|| (d.getBoard(temp1, temp2) == 11)
				|| (d.getBoard(temp1, temp2) == 12)
				|| (d.getBoard(temp1, temp2) == 13)
				|| (d.getBoard(temp1, temp2) == 14)
				|| (d.getBoard(temp1, temp2) == 15)
				|| (d.getBoard(temp1, temp2) == 16))
				return false;
			else
				return true;
		}
		else if ((temp2 < 7) && (d.getBoard(temp1, temp2) != 17))	//out of board
			return true;
		else
			return false;

	case 2: case 3: case 4: case 5: case 8:							//blue
		if ((d.getBoard(temp1, temp2) == 1)							//same team
			|| (d.getBoard(temp1, temp2) == 2)
			|| (d.getBoard(temp1, temp2) == 3)
			|| (d.getBoard(temp1, temp2) == 4)
			|| (d.getBoard(temp1, temp2) == 5)
			|| (d.getBoard(temp1, temp2) == 6)
			|| (d.getBoard(temp1, temp2) == 7)
			|| (d.getBoard(temp1, temp2) == 8))
			return false;
		else if (!((temp1 == 3 && temp2 == 1)						//river
			|| (temp1 == 4 && temp2 == 1)
			|| (temp1 == 5 && temp2 == 1)
			|| (temp1 == 3 && temp2 == 4)
			|| (temp1 == 4 && temp2 == 4)
			|| (temp1 == 5 && temp2 == 4)))
		{
			if ((temp2 < 7) && (d.getBoard(temp1, temp2) != 17))	//out of board
				return true;
			else
				return false;
		}
		else
			return false;
	case 6: case 7:
		if ((d.getBoard(temp1, temp2) == 1)
			|| (d.getBoard(temp1, temp2) == 2)						//same team
			|| (d.getBoard(temp1, temp2) == 3)
			|| (d.getBoard(temp1, temp2) == 4)
			|| (d.getBoard(temp1, temp2) == 5)
			|| (d.getBoard(temp1, temp2) == 6)
			|| (d.getBoard(temp1, temp2) == 7)
			|| (d.getBoard(temp1, temp2) == 8))
			return false;
		else if (d.getBoard(temp1, temp2) == 19)
		{
			if ((d.getBoard(temp1, temp2) == 1)
				|| (d.getBoard(temp1, temp2 + 1) == 1)
				|| (d.getBoard(temp1, temp2) == 9)
				|| (d.getBoard(temp1 + 1, temp2 + 1) == 9))
				return false;
		}
		else if ((temp2 < 7) && (d.getBoard(temp1, temp2) != 17))//out of board
			return true;
		else
			return false;
	}
}
void Rule::captureUpA(int pieces)
{
	switch (pieces)
	{
	case 1:
		if ((d.getBoard(getx() - 1, gety()) == 16)
			|| (d.getBoard(getx() - 1, gety()) == 9))
		{
			if (d.getBoard(getx() - 1, gety()) == 16)
				p.SetRedPieces(7, false);
			else if (d.getBoard(getx() - 1, gety()) == 9)
				p.SetRedPieces(0, false);
			x = x - 1;
			break;
		}
		else if ((d.getBoard(getx() - 1, gety()) == 0)
			|| (d.getBoard(getx() - 1, gety()) == 19)
			|| (d.getBoard(getx() - 1, gety()) == 22)
			|| (d.getBoard(getx() - 1, gety()) == 21)
			|| (d.getBoard(getx() - 1, gety()) == 18))
		{
			x = x - 1;
			break;
		}
		else
		{
			x = x;
			break;
		}
	case 2:
		if ((d.getBoard(getx() - 1, gety()) == 10)
			|| (d.getBoard(getx() - 1, gety()) == 9))
		{
			if (d.getBoard(getx() - 1, gety()) == 10)
				p.SetRedPieces(1, false);
			else if (d.getBoard(getx() - 1, gety()) == 9)
				p.SetRedPieces(0, false);
			x = x - 1;
			break;
		}
		else if ((d.getBoard(getx() - 1, gety()) == 0)
			|| (d.getBoard(getx() - 1, gety()) == 22)
			|| (d.getBoard(getx() - 1, gety()) == 21)
			|| (d.getBoard(getx() - 1, gety()) == 18))
		{
			x = x - 1;
			break;
		}
		else
		{
			x = x;
			break;
		}
	case 3:
		if ((d.getBoard(getx() - 1, gety()) == 9)
			|| (d.getBoard(getx() - 1, gety()) == 10)
			|| (d.getBoard(getx() - 1, gety()) == 11))
		{
			if (d.getBoard(getx() - 1, gety()) == 9)
				p.SetRedPieces(0, false);
			else if (d.getBoard(getx() - 1, gety()) == 10)
				p.SetRedPieces(1, false);
			else if (d.getBoard(getx() - 1, gety()) == 11)
				p.SetRedPieces(2, false);
			x = x - 1;
			break;
		}

		else if ((d.getBoard(getx() - 1, gety()) == 0)
			|| (d.getBoard(getx() - 1, gety()) == 22)
			|| (d.getBoard(getx() - 1, gety()) == 21)
			|| (d.getBoard(getx() - 1, gety()) == 18))
		{
			x = x - 1;
			break;
		}
		else
		{
			x = x;
			break;
		}
	case 4:
		if ((d.getBoard(getx() - 1, gety()) == 9)
			|| (d.getBoard(getx() - 1, gety()) == 10)
			|| (d.getBoard(getx() - 1, gety()) == 11)
			|| (d.getBoard(getx() - 1, gety()) == 12))
		{
			
			if (d.getBoard(getx() - 1, gety()) == 9)
				p.SetRedPieces(0, false);
			else if (d.getBoard(getx() - 1, gety()) == 10)
				p.SetRedPieces(1, false);
			else if (d.getBoard(getx() - 1, gety()) == 11)
				p.SetRedPieces(2, false);
			else if (d.getBoard(getx() - 1, gety()) == 12)
				p.SetRedPieces(3, false);
			x = x - 1;
			break;
		}
		else if ((d.getBoard(getx() - 1, gety()) == 0)
			|| (d.getBoard(getx() - 1, gety()) == 22)
			|| (d.getBoard(getx() - 1, gety()) == 21)
			|| (d.getBoard(getx() - 1, gety()) == 18))
		{
			x = x - 1;
			break;
		}
		else
		{
			x = x;
			break;
		}
	case 5:
		if ((d.getBoard(getx() - 1, gety()) == 9)
			|| (d.getBoard(getx() - 1, gety()) == 10)
			|| (d.getBoard(getx() - 1, gety()) == 11)
			|| (d.getBoard(getx() - 1, gety()) == 12)
			|| (d.getBoard(getx() - 1, gety()) == 13))
		{
			if (d.getBoard(getx() - 1, gety()) == 9)
				p.SetRedPieces(0, false);
			else if (d.getBoard(getx() - 1, gety()) == 10)
				p.SetRedPieces(1, false);
			else if (d.getBoard(getx() - 1, gety()) == 11)
				p.SetRedPieces(2, false);
			else if (d.getBoard(getx() - 1, gety()) == 12)
				p.SetRedPieces(3, false);
			else if (d.getBoard(getx() - 1, gety()) == 13)
				p.SetRedPieces(4, false);
			x = x - 1;
			break;
		}
		else if ((d.getBoard(getx() - 1, gety()) == 0)
			|| (d.getBoard(getx() - 1, gety()) == 22)
			|| (d.getBoard(getx() - 1, gety()) == 21)
			|| (d.getBoard(getx() - 1, gety()) == 18))
		{
			x = x - 1;
			break;
		}
		else
		{
			x = x;
			break;
		}
	case 6:
		if ((x == 6) && (y == 1)
			|| (x == 6) && (y == 2)
			|| (x == 6) && (y == 4)
			|| (x == 6) && (y == 5))
		{
			if ((d.getBoard(getx() - 1, gety()) != 9)
				|| (d.getBoard(getx() - 2, gety()) != 9)
				|| (d.getBoard(getx() - 3, gety()) != 9))
				x = x - 4;
			break;
		}
		else if ((d.getBoard(getx() - 1, gety()) == 9)
			|| (d.getBoard(getx() - 1, gety()) == 10)
			|| (d.getBoard(getx() - 1, gety()) == 11)
			|| (d.getBoard(getx() - 1, gety()) == 12)
			|| (d.getBoard(getx() - 1, gety()) == 13)
			|| (d.getBoard(getx() - 1, gety()) == 14))
		{

			if (d.getBoard(getx() - 1, gety()) == 9)
				p.SetRedPieces(0, false);
			else if (d.getBoard(getx() - 1, gety()) == 10)
				p.SetRedPieces(1, false);
			else if (d.getBoard(getx() - 1, gety()) == 11)
				p.SetRedPieces(2, false);
			else if (d.getBoard(getx() - 1, gety()) == 12)
				p.SetRedPieces(3, false);
			else if (d.getBoard(getx() - 1, gety()) == 13)
				p.SetRedPieces(4, false);
			else if (d.getBoard(getx() - 1, gety()) == 14)
				p.SetRedPieces(5, false);
			x = x - 1;
			break;
		}

		else if ((d.getBoard(getx() - 1, gety()) == 0)
			|| (d.getBoard(getx() - 1, gety()) == 22)
			|| (d.getBoard(getx() - 1, gety()) == 21)
			|| (d.getBoard(getx() - 1, gety()) == 18))
		{
			x = x - 1;
			break;
		}
		else
		{
			x = x;
			break;
		}
	case 7:
		if ((x == 6) && (y == 1)
			|| (x == 6) && (y == 2)
			|| (x == 6) && (y == 4)
			|| (x == 6) && (y == 5))
		{
			if ((d.getBoard(getx() - 1, gety()) != 9)
				|| (d.getBoard(getx() - 2, gety()) != 9)
				|| (d.getBoard(getx() - 3, gety()) != 9))
				x = x - 4;
			break;
		}
		else if ((d.getBoard(getx() - 1, gety()) == 9)
			|| (d.getBoard(getx() - 1, gety()) == 10)
			|| (d.getBoard(getx() - 1, gety()) == 11)
			|| (d.getBoard(getx() - 1, gety()) == 12)
			|| (d.getBoard(getx() - 1, gety()) == 13)
			|| (d.getBoard(getx() - 1, gety()) == 14)
			|| (d.getBoard(getx() - 1, gety()) == 15))
		{
			if (d.getBoard(getx() - 1, gety()) == 9)
				p.SetRedPieces(0, false);
			else if (d.getBoard(getx() - 1, gety()) == 10)
				p.SetRedPieces(1, false);
			else if (d.getBoard(getx() - 1, gety()) == 11)
				p.SetRedPieces(2, false);
			else if (d.getBoard(getx() - 1, gety()) == 12)
				p.SetRedPieces(3, false);
			else if (d.getBoard(getx() - 1, gety()) == 13)
				p.SetRedPieces(4, false);
			else if (d.getBoard(getx() - 1, gety()) == 14)
				p.SetRedPieces(5, false);
			else if (d.getBoard(getx() - 1, gety()) == 15)
				p.SetRedPieces(6, false);
			x = x - 1;
			break;
		}

		else if ((d.getBoard(getx() - 1, gety()) == 0)
			|| (d.getBoard(getx() - 1, gety()) == 22)
			|| (d.getBoard(getx() - 1, gety()) == 21)
			|| (d.getBoard(getx() - 1, gety()) == 18))
		{
			x = x - 1;
			break;
		}
		else
		{
			x = x;
			break;
		}
	case 8:
		if ((d.getBoard(getx() - 1, gety()) == 10)
			|| (d.getBoard(getx() - 1, gety()) == 11)
			|| (d.getBoard(getx() - 1, gety()) == 12)
			|| (d.getBoard(getx() - 1, gety()) == 13)
			|| (d.getBoard(getx() - 1, gety()) == 14)
			|| (d.getBoard(getx() - 1, gety()) == 15)
			|| (d.getBoard(getx() - 1, gety()) == 16))
		{
			 if (d.getBoard(getx() - 1, gety()) == 10)
				 p.SetRedPieces(1, false);
			else if (d.getBoard(getx() - 1, gety()) == 11)
				p.SetRedPieces(2, false);
			else if (d.getBoard(getx() - 1, gety()) == 12)
				p.SetRedPieces(3, false);
			else if (d.getBoard(getx() - 1, gety()) == 13)
				p.SetRedPieces(4, false);
			else if (d.getBoard(getx() - 1, gety()) == 14)
				p.SetRedPieces(5, false);
			else if (d.getBoard(getx() - 1, gety()) == 15)
				p.SetRedPieces(6, false);
			else if (d.getBoard(getx() - 1, gety()) == 16)
				p.SetRedPieces(7, false);
			x = x - 1;
			break;
		}
		else if ((d.getBoard(getx() - 1, gety()) == 0)
			|| (d.getBoard(getx() - 1, gety()) == 22)
			|| (d.getBoard(getx() - 1, gety()) == 21)
			|| (d.getBoard(getx() - 1, gety()) == 18))
		{
			x = x - 1;
			break;
		}
		else
		{
			x = x;
			break;
		}
	}
}
void Rule::captureDownA(int pieces)
{
	switch (pieces)
	{
	case 1:
		if ((d.getBoard(getx() + 1, gety()) == 16)
			|| (d.getBoard(getx() + 1, gety()) == 9))
		{

			if (d.getBoard(getx() + 1, gety()) == 16)
				p.SetRedPieces(7, false);
			else if (d.getBoard(getx() + 1, gety()) == 9)
				p.SetRedPieces(0, false);
			x = x + 1;
			break;
		}
		else if ((d.getBoard(getx() + 1, gety()) == 0)
			|| (d.getBoard(getx() + 1, gety()) == 19)
			|| (d.getBoard(getx() + 1, gety()) == 22)
			|| (d.getBoard(getx() + 1, gety()) == 21))
		{
			x = x + 1;
			break;
		}
		else
		{
			x = x;
			break;
		}
	case 2:
		if ((d.getBoard(getx() + 1, gety()) == 10)
			|| (d.getBoard(getx() + 1, gety()) == 9))
		{
			
			if (d.getBoard(getx() + 1, gety()) == 10)
				p.SetRedPieces(1, false);
			else if (d.getBoard(getx() + 1, gety()) == 9)
				p.SetRedPieces(0, false);
			x = x + 1;
			break;
		}
		else if ((d.getBoard(getx() + 1, gety()) == 0)
			|| (d.getBoard(getx() + 1, gety()) == 22)
			|| (d.getBoard(getx() + 1, gety()) == 21))
		{
			x = x + 1;
			break;
		}
		else
		{
			x = x;
			break;
		}
	case 3:
		if ((d.getBoard(getx() + 1, gety()) == 9)
			|| (d.getBoard(getx() + 1, gety()) == 10)
			|| (d.getBoard(getx() + 1, gety()) == 11))
		{
			if (d.getBoard(getx() + 1, gety()) == 9)
				p.SetRedPieces(0, false);
			else if (d.getBoard(getx() + 1, gety()) == 10)
				p.SetRedPieces(1, false);
			else if (d.getBoard(getx() + 1, gety()) == 11)
				p.SetRedPieces(2, false);
			x = x + 1;
			break;
		}

		else if ((d.getBoard(getx() + 1, gety()) == 0)
			|| (d.getBoard(getx() + 1, gety()) == 22)
			|| (d.getBoard(getx() + 1, gety()) == 21))
		{
			x = x + 1;
			break;
		}
		else
		{
			x = x;
			break;
		}
	case 4:
		if ((d.getBoard(getx() + 1, gety()) == 9)
			|| (d.getBoard(getx() + 1, gety()) == 10)
			|| (d.getBoard(getx() + 1, gety()) == 11)
			|| (d.getBoard(getx() + 1, gety()) == 12))
		{
			
			if (d.getBoard(getx() + 1, gety()) == 9)
				p.SetRedPieces(0, false);
			else if (d.getBoard(getx() + 1, gety()) == 10)
				p.SetRedPieces(1, false);
			else if (d.getBoard(getx() + 1, gety()) == 11)
				p.SetRedPieces(2, false);
			else if (d.getBoard(getx() + 1, gety()) == 12)
				p.SetRedPieces(3, false);
			x = x + 1;
			break;
		}
		else if ((d.getBoard(getx() + 1, gety()) == 0)
			|| (d.getBoard(getx() + 1, gety()) == 22)
			|| (d.getBoard(getx() + 1, gety()) == 21))
		{
			x = x + 1;
			break;
		}
		else
		{
			x = x;
			break;
		}
	case 5:
		if ((d.getBoard(getx() + 1, gety()) == 9)
			|| (d.getBoard(getx() + 1, gety()) == 10)
			|| (d.getBoard(getx() + 1, gety()) == 11)
			|| (d.getBoard(getx() + 1, gety()) == 12)
			|| (d.getBoard(getx() + 1, gety()) == 13))
		{
			
			if (d.getBoard(getx() + 1, gety()) == 9)
				p.SetRedPieces(0, false);
			else if (d.getBoard(getx() + 1, gety()) == 10)
				p.SetRedPieces(1, false);
			else if (d.getBoard(getx() + 1, gety()) == 11)
				p.SetRedPieces(2, false);
			else if (d.getBoard(getx() + 1, gety()) == 12)
				p.SetRedPieces(3, false);
			else if (d.getBoard(getx() + 1, gety()) == 13)
				p.SetRedPieces(4, false);
			x = x + 1;
			break;
		}
		else if ((d.getBoard(getx() + 1, gety()) == 0)
			|| (d.getBoard(getx() + 1, gety()) == 22)
			|| (d.getBoard(getx() + 1, gety()) == 21))
		{
			x = x + 1;
			break;
		}
		else
		{
			x = x;
			break;
		}
	case 6:
		if ((x == 2) && (y == 1)
			|| (x == 2) && (y == 2)
			|| (x == 2) && (y == 4)
			|| (x == 2) && (y == 5))
		{
			if ((d.getBoard(getx() + 1, gety()) != 9)
				|| (d.getBoard(getx() + 2, gety()) != 9)
				|| (d.getBoard(getx() + 3, gety()) != 9))
				x = x + 4;
			break;
		}
		else if ((d.getBoard(getx() + 1, gety()) == 9)
			|| (d.getBoard(getx() + 1, gety()) == 10)
			|| (d.getBoard(getx() + 1, gety()) == 11)
			|| (d.getBoard(getx() + 1, gety()) == 12)
			|| (d.getBoard(getx() + 1, gety()) == 13)
			|| (d.getBoard(getx() + 1, gety()) == 14))
		{

			if (d.getBoard(getx() + 1, gety()) == 9)
				p.SetRedPieces(0, false);
			else if (d.getBoard(getx() + 1, gety()) == 10)
				p.SetRedPieces(1, false);
			else if (d.getBoard(getx() + 1, gety()) == 11)
				p.SetRedPieces(2, false);
			else if (d.getBoard(getx() + 1, gety()) == 12)
				p.SetRedPieces(3, false);
			else if (d.getBoard(getx() + 1, gety()) == 13)
				p.SetRedPieces(4, false);
			else if (d.getBoard(getx() + 1, gety()) == 14)
				p.SetRedPieces(5, false);
			x = x + 1;
			break;
		}

		else if ((d.getBoard(getx() + 1, gety()) == 0)
			|| (d.getBoard(getx() + 1, gety()) == 22)
			|| (d.getBoard(getx() + 1, gety()) == 21))
		{
			x = x + 1;
			break;
		}
		else
		{
			x = x;
			break;
		}
	case 7:
		if ((x == 2) && (y == 1)
			|| (x == 2) && (y == 2)
			|| (x == 2) && (y == 4)
			|| (x == 2) && (y == 5))
		{
			if ((d.getBoard(getx() + 1, gety()) != 9)
				|| (d.getBoard(getx() + 2, gety()) != 9)
				|| (d.getBoard(getx() + 3, gety()) != 9))
				x = x + 4;
			break;
		}
		else if ((d.getBoard(getx() + 1, gety()) == 9)
			|| (d.getBoard(getx() + 1, gety()) == 10)
			|| (d.getBoard(getx() + 1, gety()) == 11)
			|| (d.getBoard(getx() + 1, gety()) == 12)
			|| (d.getBoard(getx() + 1, gety()) == 13)
			|| (d.getBoard(getx() + 1, gety()) == 14)
			|| (d.getBoard(getx() + 1, gety()) == 15))
		{
			if (d.getBoard(getx() + 1, gety()) == 9)
				p.SetRedPieces(0, false);
			else if (d.getBoard(getx() + 1, gety()) == 10)
				p.SetRedPieces(1, false);
			else if (d.getBoard(getx() + 1, gety()) == 11)
				p.SetRedPieces(2, false);
			else if (d.getBoard(getx() + 1, gety()) == 12)
				p.SetRedPieces(3, false);
			else if (d.getBoard(getx() + 1, gety()) == 13)
				p.SetRedPieces(4, false);
			else if (d.getBoard(getx() + 1, gety()) == 14)
				p.SetRedPieces(5, false);
			else if (d.getBoard(getx() + 1, gety()) == 15)
				p.SetRedPieces(6, false);
			x = x + 1;
			break;
		}

		else if ((d.getBoard(getx() + 1, gety()) == 0)
			|| (d.getBoard(getx() + 1, gety()) == 22)
			|| (d.getBoard(getx() + 1, gety()) == 21))
		{
			x = x + 1;
			break;
		}
		else
		{
			x = x;
			break;
		}
	case 8:
		if ((d.getBoard(getx() + 1, gety()) == 10)
			|| (d.getBoard(getx() + 1, gety()) == 11)
			|| (d.getBoard(getx() + 1, gety()) == 12)
			|| (d.getBoard(getx() + 1, gety()) == 13)
			|| (d.getBoard(getx() + 1, gety()) == 14)
			|| (d.getBoard(getx() + 1, gety()) == 15)
			|| (d.getBoard(getx() + 1, gety()) == 16))
		{
			if (d.getBoard(getx() + 1, gety()) == 10)
				p.SetRedPieces(1, false);
			else if (d.getBoard(getx() + 1, gety()) == 11)
				p.SetRedPieces(2, false);
			else if (d.getBoard(getx() + 1, gety()) == 12)
				p.SetRedPieces(3, false);
			else if (d.getBoard(getx() + 1, gety()) == 13)
				p.SetRedPieces(4, false);
			else if (d.getBoard(getx() + 1, gety()) == 14)
				p.SetRedPieces(5, false);
			else if (d.getBoard(getx() + 1, gety()) == 15)
				p.SetRedPieces(6, false);
			else if (d.getBoard(getx() + 1, gety()) == 16)
				p.SetRedPieces(7, false);
			x = x + 1;
			break;
		}
		else if ((d.getBoard(getx() + 1, gety()) == 0)
			|| (d.getBoard(getx() + 1, gety()) == 22)
			|| (d.getBoard(getx() + 1, gety()) == 21))
		{
			x = x + 1;
			break;
		}
		else
		{
			x = x;
			break;
		}
	}
}
void Rule::captureLeftA(int pieces)
{
	switch (pieces)
	{
	case 1:
		if ((d.getBoard(getx(), gety() - 1) == 16)
			|| (d.getBoard(getx(), gety() - 1) == 9))
		{
			if (d.getBoard(getx(), gety() - 1) == 16)
				p.SetRedPieces(7, false);
			else if (d.getBoard(getx(), gety() - 1) == 9)
				p.SetRedPieces(0, false);
			y = y - 1;
			break;
		}
		else if ((d.getBoard(getx(), gety() - 1) == 0)
			|| (d.getBoard(getx(), gety() - 1) == 19)
			|| (d.getBoard(getx(), gety() - 1) == 22)
			|| (d.getBoard(getx(), gety() - 1) == 21)
			|| (d.getBoard(getx(), gety() - 1) == 18))
		{
			y = y - 1;
			break;
		}
		else
		{
			y = y;
			break;
		}
	case 2:
		if ((d.getBoard(getx(), gety() - 1) == 10)
			|| (d.getBoard(getx(), gety() - 1) == 9))
		{
			if (d.getBoard(getx(), gety() - 1) == 10)
				p.SetRedPieces(1, false);
			else if (d.getBoard(getx(), gety() - 1) == 9)
				p.SetRedPieces(0, false);
			y = y - 1;
			break;
		}
		else if ((d.getBoard(getx(), gety() - 1) == 0)
			|| (d.getBoard(getx(), gety() - 1) == 22)
			|| (d.getBoard(getx(), gety() - 1) == 21)
			|| (d.getBoard(getx(), gety() - 1) == 18))
		{
			y = y - 1;
			break;
		}
		else
		{
			y = y;
			break;
		}
	case 3:
		if ((d.getBoard(getx(), gety() - 1) == 9)
			|| (d.getBoard(getx(), gety() - 1) == 10)
			|| (d.getBoard(getx(), gety() - 1) == 11))
		{
			if (d.getBoard(getx(), gety() - 1) == 9)
				p.SetRedPieces(0, false);
			else if (d.getBoard(getx(), gety() - 1) == 10)
				p.SetRedPieces(1, false);
			else if (d.getBoard(getx(), gety() - 1) == 11)
				p.SetRedPieces(2, false);
			y = y - 1;
			break;
		}

		else if ((d.getBoard(getx(), gety() - 1) == 0)
			|| (d.getBoard(getx(), gety() - 1) == 22)
			|| (d.getBoard(getx(), gety() - 1) == 21)
			|| (d.getBoard(getx(), gety() - 1) == 18))
		{
			y = y - 1;
			break;
		}
		else
		{
			y = y;
			break;
		}
	case 4:
		if ((d.getBoard(getx(), gety() - 1) == 9)
			|| (d.getBoard(getx(), gety() - 1) == 10)
			|| (d.getBoard(getx(), gety() - 1) == 11)
			|| (d.getBoard(getx(), gety() - 1) == 12))
		{
			if (d.getBoard(getx(), gety() - 1) == 9)
				p.SetRedPieces(0, false);
			else if (d.getBoard(getx(), gety() - 1) == 10)
				p.SetRedPieces(1, false);
			else if (d.getBoard(getx(), gety() - 1) == 11)
				p.SetRedPieces(2, false);
			else if (d.getBoard(getx(), gety() - 1) == 12)
				p.SetRedPieces(3, false);
			y = y - 1;
			break;
		}
		else if ((d.getBoard(getx(), gety() - 1) == 0)
			|| (d.getBoard(getx(), gety() - 1) == 22)
			|| (d.getBoard(getx(), gety() - 1) == 21)
			|| (d.getBoard(getx(), gety() - 1) == 18))
		{
			y = y - 1;
			break;
		}
		else
		{
			y = y;
			break;
		}
	case 5:
		if ((d.getBoard(getx(), gety() - 1) == 9)
			|| (d.getBoard(getx(), gety() - 1) == 10)
			|| (d.getBoard(getx(), gety() - 1) == 11)
			|| (d.getBoard(getx(), gety() - 1) == 12)
			|| (d.getBoard(getx(), gety() - 1) == 13))
		{
			if (d.getBoard(getx(), gety() - 1) == 9)
				p.SetRedPieces(0, false);
			else if (d.getBoard(getx(), gety() - 1) == 10)
				p.SetRedPieces(1, false);
			else if (d.getBoard(getx(), gety() - 1) == 11)
				p.SetRedPieces(2, false);
			else if (d.getBoard(getx(), gety() - 1) == 12)
				p.SetRedPieces(3, false);
			else if (d.getBoard(getx(), gety() - 1) == 13)
				p.SetRedPieces(4, false);
			y = y - 1;
			break;
		}
		else if ((d.getBoard(getx(), gety() - 1) == 0)
			|| (d.getBoard(getx(), gety() - 1) == 22)
			|| (d.getBoard(getx(), gety() - 1) == 21)
			|| (d.getBoard(getx(), gety() - 1) == 18))
		{
			y = y - 1;
			break;
		}
		else
		{
			y = y;
			break;
		}
	case 6:
		if ((x == 3) && (y == 3)
			|| (x == 3) && (y == 6)
			|| (x == 4) && (y == 3)
			|| (x == 4) && (y == 6)
			|| (x == 5) && (y == 3)
			|| (x == 5) && (y == 6))
		{
			if ((d.getBoard(getx(), gety() - 1) != 9)
				|| (d.getBoard(getx(), gety() - 2) != 9))
				y = y - 3;
			break;
		}
		else if ((d.getBoard(getx(), gety() - 1) == 9)
			|| (d.getBoard(getx(), gety() - 1) == 10)
			|| (d.getBoard(getx(), gety() - 1) == 11)
			|| (d.getBoard(getx(), gety() - 1) == 12)
			|| (d.getBoard(getx(), gety() - 1) == 13)
			|| (d.getBoard(getx(), gety() - 1) == 14))
		{

			if (d.getBoard(getx(), gety() - 1) == 9)
				p.SetRedPieces(0, false);
			else if (d.getBoard(getx(), gety() - 1) == 10)
				p.SetRedPieces(1, false);
			else if (d.getBoard(getx(), gety() - 1) == 11)
				p.SetRedPieces(2, false);
			else if (d.getBoard(getx(), gety() - 1) == 12)
				p.SetRedPieces(3, false);
			else if (d.getBoard(getx(), gety() - 1) == 13)
				p.SetRedPieces(4, false);
			else if (d.getBoard(getx(), gety() - 1) == 14)
				p.SetRedPieces(5, false);
			y = y - 1;
			break;
		}

		else if ((d.getBoard(getx(), gety() - 1) == 0)
			|| (d.getBoard(getx(), gety() - 1) == 22)
			|| (d.getBoard(getx(), gety() - 1) == 21)
			|| (d.getBoard(getx(), gety() - 1) == 18))
		{
			y = y - 1;
			break;
		}
		else
		{
			y = y;
			break;
		}
	case 7:
		if ((x == 3) && (y == 3)
			|| (x == 3) && (y == 6)
			|| (x == 4) && (y == 3)
			|| (x == 4) && (y == 6)
			|| (x == 5) && (y == 3)
			|| (x == 5) && (y == 6))
		{
			if ((d.getBoard(getx(), gety() - 1) != 9)
				|| (d.getBoard(getx(), gety() - 2) != 9))
				y = y - 3;
			break;
		}
		else if ((d.getBoard(getx(), gety() - 1) == 9)
			|| (d.getBoard(getx(), gety() - 1) == 10)
			|| (d.getBoard(getx(), gety() - 1) == 11)
			|| (d.getBoard(getx(), gety() - 1) == 12)
			|| (d.getBoard(getx(), gety() - 1) == 13)
			|| (d.getBoard(getx(), gety() - 1) == 14)
			|| (d.getBoard(getx(), gety() - 1) == 15))
		{
			if (d.getBoard(getx(), gety() - 1) == 9)
				p.SetRedPieces(0, false);
			else if (d.getBoard(getx(), gety() - 1) == 10)
				p.SetRedPieces(1, false);
			else if (d.getBoard(getx(), gety() - 1) == 11)
				p.SetRedPieces(2, false);
			else if (d.getBoard(getx(), gety() - 1) == 12)
				p.SetRedPieces(3, false);
			else if (d.getBoard(getx(), gety() - 1) == 13)
				p.SetRedPieces(4, false);
			else if (d.getBoard(getx(), gety() - 1) == 14)
				p.SetRedPieces(5, false);
			else if (d.getBoard(getx(), gety() - 1) == 15)
				p.SetRedPieces(6, false);
			y = y - 1;
			break;
		}

		else if ((d.getBoard(getx(), gety() - 1) == 0)
			|| (d.getBoard(getx(), gety() - 1) == 22)
			|| (d.getBoard(getx(), gety() - 1) == 21)
			|| (d.getBoard(getx(), gety() - 1) == 18))
		{
			y = y - 1;
			break;
		}
		else
		{
			y = y;
			break;
		}
	case 8:
		if ((d.getBoard(getx(), gety() - 1) == 10)
			|| (d.getBoard(getx(), gety() - 1) == 11)
			|| (d.getBoard(getx(), gety() - 1) == 12)
			|| (d.getBoard(getx(), gety() - 1) == 13)
			|| (d.getBoard(getx(), gety() - 1) == 14)
			|| (d.getBoard(getx(), gety() - 1) == 15)
			|| (d.getBoard(getx(), gety() - 1) == 16))
		{
			if (d.getBoard(getx(), gety() - 1) == 10)
				p.SetRedPieces(1, false);
			else if (d.getBoard(getx(), gety() - 1) == 11)
				p.SetRedPieces(2, false);
			else if (d.getBoard(getx(), gety() - 1) == 12)
				p.SetRedPieces(3, false);
			else if (d.getBoard(getx(), gety() - 1) == 13)
				p.SetRedPieces(4, false);
			else if (d.getBoard(getx(), gety() - 1) == 14)
				p.SetRedPieces(5, false);
			else if (d.getBoard(getx(), gety() - 1) == 15)
				p.SetRedPieces(6, false);
			else if (d.getBoard(getx(), gety() - 1) == 16)
				p.SetRedPieces(7, false);
			y = y - 1;
			break;
		}
		else if ((d.getBoard(getx(), gety() - 1) == 0)
			|| (d.getBoard(getx(), gety() - 1) == 22)
			|| (d.getBoard(getx(), gety() - 1) == 21)
			|| (d.getBoard(getx(), gety() - 1) == 18))
		{
			y = y - 1;
			break;
		}
		else
		{
			y = y;
			break;
		}
	}
}
void Rule::captureRightA(int pieces)
{
	switch (pieces)
	{
	case 1:
		if ((d.getBoard(getx(), gety() + 1) == 16)
			|| (d.getBoard(getx(), gety() + 1) == 9))
		{
			if (d.getBoard(getx(), gety() + 1) == 16)
				p.SetRedPieces(7, false);
			else if (d.getBoard(getx(), gety() + 1) == 9)
				p.SetRedPieces(0, false);
			y = y + 1;
			break;
		}
		else if ((d.getBoard(getx(), gety() + 1) == 0)
			|| (d.getBoard(getx(), gety() + 1) == 19)
			|| (d.getBoard(getx(), gety() + 1) == 22)
			|| (d.getBoard(getx(), gety() + 1) == 21)
			|| (d.getBoard(getx(), gety() + 1) == 18))
		{
			y = y + 1;
			break;
		}
		else
		{
			y = y;
			break;
		}
	case 2:
		if ((d.getBoard(getx(), gety() + 1) == 10)
			|| (d.getBoard(getx(), gety() + 1) == 9))
		{
			if (d.getBoard(getx(), gety() + 1) == 10)
				p.SetRedPieces(1, false);
			else if (d.getBoard(getx(), gety() + 1) == 9)
				p.SetRedPieces(0, false);
			y = y + 1;
			break;
		}
		else if ((d.getBoard(getx(), gety() + 1) == 0)
			|| (d.getBoard(getx(), gety() + 1) == 22)
			|| (d.getBoard(getx(), gety() + 1) == 21)
			|| (d.getBoard(getx(), gety() + 1) == 18))
		{
			y = y + 1;
			break;
		}
		else
		{
			y = y;
			break;
		}
	case 3:
		if ((d.getBoard(getx(), gety() + 1) == 9)
			|| (d.getBoard(getx(), gety() + 1) == 10)
			|| (d.getBoard(getx(), gety() + 1) == 11))
		{
			if (d.getBoard(getx(), gety() + 1) == 9)
				p.SetRedPieces(0, false);
			else if (d.getBoard(getx(), gety() + 1) == 10)
				p.SetRedPieces(1, false);
			else if (d.getBoard(getx(), gety() + 1) == 11)
				p.SetRedPieces(2, false);
			y = y + 1;
			break;
		}

		else if ((d.getBoard(getx(), gety() + 1) == 0)
			|| (d.getBoard(getx(), gety() + 1) == 22)
			|| (d.getBoard(getx(), gety() + 1) == 21)
			|| (d.getBoard(getx(), gety() + 1) == 18))
		{
			y = y + 1;
			break;
		}
		else
		{
			y = y;
			break;
		}
	case 4:
		if ((d.getBoard(getx(), gety() + 1) == 9)
			|| (d.getBoard(getx(), gety() + 1) == 10)
			|| (d.getBoard(getx(), gety() + 1) == 11)
			|| (d.getBoard(getx(), gety() + 1) == 12))
		{
			if (d.getBoard(getx(), gety() + 1) == 9)
				p.SetRedPieces(0, false);
			else if (d.getBoard(getx(), gety() + 1) == 10)
				p.SetRedPieces(1, false);
			else if (d.getBoard(getx(), gety() + 1) == 11)
				p.SetRedPieces(2, false);
			else if (d.getBoard(getx(), gety() + 1) == 12)
				p.SetRedPieces(3, false);
			y = y + 1;
			break;
		}
		else if ((d.getBoard(getx(), gety() + 1) == 0)
			|| (d.getBoard(getx(), gety() + 1) == 22)
			|| (d.getBoard(getx(), gety() + 1) == 21)
			|| (d.getBoard(getx(), gety() + 1) == 18))
		{
			y = y + 1;
			break;
		}
		else
		{
			y = y;
			break;
		}
	case 5:
		if ((d.getBoard(getx(), gety() + 1) == 9)
			|| (d.getBoard(getx(), gety() + 1) == 10)
			|| (d.getBoard(getx(), gety() + 1) == 11)
			|| (d.getBoard(getx(), gety() + 1) == 12)
			|| (d.getBoard(getx(), gety() + 1) == 13))
		{
			if (d.getBoard(getx(), gety() + 1) == 9)
				p.SetRedPieces(0, false);
			else if (d.getBoard(getx(), gety() + 1) == 10)
				p.SetRedPieces(1, false);
			else if (d.getBoard(getx(), gety() + 1) == 11)
				p.SetRedPieces(2, false);
			else if (d.getBoard(getx(), gety() + 1) == 12)
				p.SetRedPieces(3, false);
			else if (d.getBoard(getx(), gety() + 1) == 13)
				p.SetRedPieces(4, false);
			y = y + 1;
			break;
		}
		else if ((d.getBoard(getx(), gety() + 1) == 0)
			|| (d.getBoard(getx(), gety() + 1) == 22)
			|| (d.getBoard(getx(), gety() + 1) == 21)
			|| (d.getBoard(getx(), gety() + 1) == 18))
		{
			y = y + 1;
			break;
		}
		else
		{
			y = y;
			break;
		}
	case 6:
		if ((x == 3) && (y == 0)
			|| (x == 3) && (y == 3)
			|| (x == 4) && (y == 0)
			|| (x == 4) && (y == 3)
			|| (x == 5) && (y == 0)
			|| (x == 5) && (y == 3))
		{
			if ((d.getBoard(getx(), gety() + 1) != 9)
				|| (d.getBoard(getx(), gety() + 2) != 9))
				y = y + 3;
			break;
		}
		else if ((d.getBoard(getx(), gety() + 1) == 9)
			|| (d.getBoard(getx(), gety() + 1) == 10)
			|| (d.getBoard(getx(), gety() + 1) == 11)
			|| (d.getBoard(getx(), gety() + 1) == 12)
			|| (d.getBoard(getx(), gety() + 1) == 13)
			|| (d.getBoard(getx(), gety() + 1) == 14))
		{

			if (d.getBoard(getx(), gety() + 1) == 9)
				p.SetRedPieces(0, false);
			else if (d.getBoard(getx(), gety() + 1) == 10)
				p.SetRedPieces(1, false);
			else if (d.getBoard(getx(), gety() + 1) == 11)
				p.SetRedPieces(2, false);
			else if (d.getBoard(getx(), gety() + 1) == 12)
				p.SetRedPieces(3, false);
			else if (d.getBoard(getx(), gety() + 1) == 13)
				p.SetRedPieces(4, false);
			else if (d.getBoard(getx(), gety() + 1) == 14)
				p.SetRedPieces(5, false);
			y = y + 1;
			break;
		}

		else if ((d.getBoard(getx(), gety() + 1) == 0)
			|| (d.getBoard(getx(), gety() + 1) == 22)
			|| (d.getBoard(getx(), gety() + 1) == 21)
			|| (d.getBoard(getx(), gety() + 1) == 18))
		{
			y = y + 1;
			break;
		}
		else
		{
			y = y;
			break;
		}
	case 7:
		if ((x == 3) && (y == 0)
			|| (x == 3) && (y == 3)
			|| (x == 4) && (y == 0)
			|| (x == 4) && (y == 3)
			|| (x == 5) && (y == 0)
			|| (x == 5) && (y == 3))
		{
			if ((d.getBoard(getx(), gety() + 1) != 9)
				|| (d.getBoard(getx(), gety() + 2) != 9))
				y = y + 3;
			break;
		}
		else if ((d.getBoard(getx(), gety() + 1) == 9)
			|| (d.getBoard(getx(), gety() + 1) == 10)
			|| (d.getBoard(getx(), gety() + 1) == 11)
			|| (d.getBoard(getx(), gety() + 1) == 12)
			|| (d.getBoard(getx(), gety() + 1) == 13)
			|| (d.getBoard(getx(), gety() + 1) == 14)
			|| (d.getBoard(getx(), gety() + 1) == 15))
		{
			if (d.getBoard(getx(), gety() + 1) == 9)
				p.SetRedPieces(0, false);
			else if (d.getBoard(getx(), gety() + 1) == 10)
				p.SetRedPieces(1, false);
			else if (d.getBoard(getx(), gety() + 1) == 11)
				p.SetRedPieces(2, false);
			else if (d.getBoard(getx(), gety() + 1) == 12)
				p.SetRedPieces(3, false);
			else if (d.getBoard(getx(), gety() + 1) == 13)
				p.SetRedPieces(4, false);
			else if (d.getBoard(getx(), gety() + 1) == 14)
				p.SetRedPieces(5, false);
			else if (d.getBoard(getx(), gety() + 1) == 15)
				p.SetRedPieces(6, false);
			y = y + 1;
			break;
		}

		else if ((d.getBoard(getx(), gety() + 1) == 0)
			|| (d.getBoard(getx(), gety() + 1) == 22)
			|| (d.getBoard(getx(), gety() + 1) == 21)
			|| (d.getBoard(getx(), gety() + 1) == 18))
		{
			y = y + 1;
			break;
		}
		else
		{
			y = y;
			break;
		}
	case 8:
		if ((d.getBoard(getx(), gety() + 1) == 10)
			|| (d.getBoard(getx(), gety() + 1) == 11)
			|| (d.getBoard(getx(), gety() + 1) == 12)
			|| (d.getBoard(getx(), gety() + 1) == 13)
			|| (d.getBoard(getx(), gety() + 1) == 14)
			|| (d.getBoard(getx(), gety() + 1) == 15)
			|| (d.getBoard(getx(), gety() + 1) == 16))
		{
			 if (d.getBoard(getx(), gety() + 1) == 10)
				 p.SetRedPieces(1, false);
			else if (d.getBoard(getx(), gety() + 1) == 11)
				p.SetRedPieces(2, false);
			else if (d.getBoard(getx(), gety() + 1) == 12)
				p.SetRedPieces(3, false);
			else if (d.getBoard(getx(), gety() + 1) == 13)
				p.SetRedPieces(4, false);
			else if (d.getBoard(getx(), gety() + 1) == 14)
				p.SetRedPieces(5, false);
			else if (d.getBoard(getx(), gety() + 1) == 15)
				p.SetRedPieces(6, false);
			else if (d.getBoard(getx(), gety() + 1) == 16)
				p.SetRedPieces(7, false);
			y = y + 1;
			break;
		}
		else if ((d.getBoard(getx(), gety() + 1) == 0)
			|| (d.getBoard(getx(), gety() + 1) == 22)
			|| (d.getBoard(getx(), gety() + 1) == 21)
			|| (d.getBoard(getx(), gety() + 1) == 18))
		{
			y = y + 1;
			break;
		}
		else
		{
			y = y;
			break;
		}
	}
}
//----------------------------------
//Player B, Red team
//-----------------------------------
bool Rule::checkPossibleMoveUpB(int pieces)
{
	int temp1 = x - 1;
	int temp2 = y;
	switch (pieces)
	{
		/*---------------------------------------
		Red team
		------------------------------------------*/
	case 9:															//mouse
		if ((d.getBoard(temp1, temp2) == 10)						//same team
			|| (d.getBoard(temp1, temp2) == 11)
			|| (d.getBoard(temp1, temp2) == 12)
			|| (d.getBoard(temp1, temp2) == 13)
			|| (d.getBoard(temp1, temp2) == 14)
			|| (d.getBoard(temp1, temp2) == 15)
			|| (d.getBoard(temp1, temp2) == 16))
			return false;
		else if (d.getBoard(temp1 + 1, temp2) == 19)
		{
			if ((d.getBoard(temp1, temp2) == 1)
				|| (d.getBoard(temp1, temp2) == 2)
				|| (d.getBoard(temp1, temp2) == 3)
				|| (d.getBoard(temp1, temp2) == 4)
				|| (d.getBoard(temp1, temp2) == 5)
				|| (d.getBoard(temp1, temp2) == 6)
				|| (d.getBoard(temp1, temp2) == 7)
				|| (d.getBoard(temp1, temp2) == 8))
				return false;
			else
				return true;
		}
		else if ((temp1) > -1)										//out of board
			return true;
		else
			return false;

	case 10: case 11: case 12: case 13: case 16:
		if ((d.getBoard(temp1, temp2) == 10)						//same team
			|| (d.getBoard(temp1, temp2) == 11)
			|| (d.getBoard(temp1, temp2) == 12)
			|| (d.getBoard(temp1, temp2) == 13)
			|| (d.getBoard(temp1, temp2) == 14)
			|| (d.getBoard(temp1, temp2) == 15)
			|| (d.getBoard(temp1, temp2) == 16)
			|| (d.getBoard(temp1, temp2) == 9))
			return false;
		else if (!((temp1 == 5 && temp2 == 1)						//river
			|| (temp1 == 5 && temp2 == 2)
			|| (temp1 == 5 && temp2 == 4)
			|| (temp1 == 5 && temp2 == 5)))
		{
			if (temp1 > -1)											//out of board
				return true;
			else
				return false;
		}
		else
			return false;
	case 14: case 15:												//lion and tiger
		if ((d.getBoard(temp1, temp2) == 9)
			|| (d.getBoard(temp1, temp2) == 10)						//same team
			|| (d.getBoard(temp1, temp2) == 11)
			|| (d.getBoard(temp1, temp2) == 12)
			|| (d.getBoard(temp1, temp2) == 13)
			|| (d.getBoard(temp1, temp2) == 14)
			|| (d.getBoard(temp1, temp2) == 15)
			|| (d.getBoard(temp1, temp2) == 16))
			return false;
		else if (d.getBoard(temp1, temp2) == 19)
		{
			if ((d.getBoard(temp1, temp2) == 1)
				|| (d.getBoard(temp1 - 1, temp2) == 1)
				|| (d.getBoard(temp1 - 2, temp2) == 1)
				|| (d.getBoard(temp1, temp2) == 9)
				|| (d.getBoard(temp1 - 1, temp2) == 9)
				|| (d.getBoard(temp1 - 2, temp2) == 9))
				return false;
		}
		else if (temp1 > -1)										//out of board
			return true;
		else
			return false;
	}

}
bool Rule::checkPossibleMoveDownB(int pieces)
{
	int temp1 = x + 1;
	int temp2 = gety();
	switch (pieces)
	{
		//---------------------------------------
		//Red team
		//------------------------------------------
	case 9:									//mouse
		if ((d.getBoard(temp1, temp2) == 10)						//same team
			|| (d.getBoard(temp1, temp2) == 11)
			|| (d.getBoard(temp1, temp2) == 12)
			|| (d.getBoard(temp1, temp2) == 13)
			|| (d.getBoard(temp1, temp2) == 14)
			|| (d.getBoard(temp1, temp2) == 15)
			|| (d.getBoard(temp1, temp2) == 16))
			return false;
		else if (d.getBoard(temp1 - 1, temp2) == 19)
		{
			if ((d.getBoard(temp1, temp2) == 1)
				|| (d.getBoard(temp1, temp2) == 2)
				|| (d.getBoard(temp1, temp2) == 3)
				|| (d.getBoard(temp1, temp2) == 4)
				|| (d.getBoard(temp1, temp2) == 5)
				|| (d.getBoard(temp1, temp2) == 6)
				|| (d.getBoard(temp1, temp2) == 7)
				|| (d.getBoard(temp1, temp2) == 8))
				return false;
			else
				return true;
		}
		else if ((temp1 < 9) && (d.getBoard(temp1, temp2) != 21))	//out of board
			return true;
		else
			return false;

	case 10: case 11: case 12: case 13: case 16:
		if ((d.getBoard(temp1, temp2) == 10)						//same team
			|| (d.getBoard(temp1, temp2) == 11)
			|| (d.getBoard(temp1, temp2) == 12)
			|| (d.getBoard(temp1, temp2) == 13)
			|| (d.getBoard(temp1, temp2) == 14)
			|| (d.getBoard(temp1, temp2) == 15)
			|| (d.getBoard(temp1, temp2) == 16)
			|| (d.getBoard(temp1, temp2) == 9))
			return false;
		else if (!((temp1 == 3 && temp2 == 1)						//river
			|| (temp1 == 3 && temp2 == 2)
			|| (temp1 == 3 && temp2 == 4)
			|| (temp1 == 3 && temp2 == 5)))
		{
			if ((temp1 < 9) && (d.getBoard(temp1, temp2) != 21))	//out of board
				return true;
			else
				return false;
		}
		else
			return false;
	case 14: case 15:
		if ((d.getBoard(temp1, temp2) == 10)
			|| (d.getBoard(temp1, temp2) == 11)						//same team
			|| (d.getBoard(temp1, temp2) == 12)
			|| (d.getBoard(temp1, temp2) == 13)
			|| (d.getBoard(temp1, temp2) == 14)
			|| (d.getBoard(temp1, temp2) == 15)
			|| (d.getBoard(temp1, temp2) == 16)
			|| (d.getBoard(temp1, temp2) == 17))
			return false;
		else if (d.getBoard(temp1, temp2) == 19)
		{
			if ((d.getBoard(temp1, temp2) == 1)
				|| (d.getBoard(temp1 + 1, temp2) == 1)
				|| (d.getBoard(temp1 + 2, temp2) == 1)
				|| (d.getBoard(temp1, temp2) == 9)
				|| (d.getBoard(temp1 + 1, temp2) == 9)
				|| (d.getBoard(temp1 + 2, temp2) == 9))
				return false;
		}
		else if ((temp1 < 9) && (d.getBoard(temp1, temp2) != 21))	//out of board
			return true;
		else
			return false;
	}
}
bool Rule::checkPossibleMoveLeftB(int pieces)
{
	int temp1 = x;
	int temp2 = y - 1;
	switch (pieces)
	{
		//---------------------------------------
		//Red team
		//------------------------------------------
	case 9:															//mouse
		if ((d.getBoard(temp1, temp2) == 10)						//same team
			|| (d.getBoard(temp1, temp2) == 11)
			|| (d.getBoard(temp1, temp2) == 12)
			|| (d.getBoard(temp1, temp2) == 13)
			|| (d.getBoard(temp1, temp2) == 14)
			|| (d.getBoard(temp1, temp2) == 15)
			|| (d.getBoard(temp1, temp2) == 16))
			return false;
		else if (d.getBoard(temp1, temp2 + 1) == 19)
		{
			if ((d.getBoard(temp1, temp2) == 1)
				|| (d.getBoard(temp1, temp2) == 2)
				|| (d.getBoard(temp1, temp2) == 3)
				|| (d.getBoard(temp1, temp2) == 4)
				|| (d.getBoard(temp1, temp2) == 5)
				|| (d.getBoard(temp1, temp2) == 6)
				|| (d.getBoard(temp1, temp2) == 7)
				|| (d.getBoard(temp1, temp2) == 8))
				return false;
			else
				return true;
		}
		else if ((temp2 > -1) && (d.getBoard(temp1, temp2) != 21))	//out of board
			return true;
		else
			return false;

	case 10: case 11: case 12: case 13: case 16:
		if ((d.getBoard(temp1, temp2) == 10)						//same team
			|| (d.getBoard(temp1, temp2) == 11)
			|| (d.getBoard(temp1, temp2) == 12)
			|| (d.getBoard(temp1, temp2) == 13)
			|| (d.getBoard(temp1, temp2) == 14)
			|| (d.getBoard(temp1, temp2) == 15)
			|| (d.getBoard(temp1, temp2) == 16)
			|| (d.getBoard(temp1, temp2) == 9))
			return false;
		else if (!((temp1 == 3 && temp2 == 2)						//river
			|| (temp1 == 4 && temp2 == 2)
			|| (temp1 == 5 && temp2 == 2)
			|| (temp1 == 3 && temp2 == 5)
			|| (temp1 == 4 && temp2 == 5)
			|| (temp1 == 5 && temp2 == 5)))
		{
			if ((temp2 > -1) && (d.getBoard(temp1, temp2) != 21))	//out of board
				return true;
			else
				return false;
		}
		else
			return false;
	case 14: case 15:
		if ((d.getBoard(temp1, temp2) == 10)
			|| (d.getBoard(temp1, temp2) == 11)						//same team
			|| (d.getBoard(temp1, temp2) == 12)
			|| (d.getBoard(temp1, temp2) == 13)
			|| (d.getBoard(temp1, temp2) == 14)
			|| (d.getBoard(temp1, temp2) == 15)
			|| (d.getBoard(temp1, temp2) == 16)
			|| (d.getBoard(temp1, temp2) == 17))
			return false;
		else if (d.getBoard(temp1, temp2) == 19)
		{
			if ((d.getBoard(temp1, temp2) == 1)
				|| (d.getBoard(temp1, temp2 - 1) == 1)
				|| (d.getBoard(temp1, temp2) == 9)
				|| (d.getBoard(temp1 + 1, temp2 - 1) == 9))
				return false;
		}
		else if ((temp2 > -1) && (d.getBoard(temp1, temp2) != 21))	//out of board
			return true;
		else
			return false;
	}
}
bool Rule::checkPossibleMoveRightB(int pieces)
{
	int temp1 = x;
	int temp2 = y + 1;
	switch (pieces)
	{
		//---------------------------------------
		//Red team
		//------------------------------------------
	case 9:															//mouse
		if ((d.getBoard(temp1, temp2) == 10)						//same team
			|| (d.getBoard(temp1, temp2) == 11)
			|| (d.getBoard(temp1, temp2) == 12)
			|| (d.getBoard(temp1, temp2) == 13)
			|| (d.getBoard(temp1, temp2) == 14)
			|| (d.getBoard(temp1, temp2) == 15)
			|| (d.getBoard(temp1, temp2) == 16))
			return false;
		else if (d.getBoard(temp1, temp2 - 1) == 19)
		{
			if ((d.getBoard(temp1, temp2) == 1)
				|| (d.getBoard(temp1, temp2) == 2)
				|| (d.getBoard(temp1, temp2) == 3)
				|| (d.getBoard(temp1, temp2) == 4)
				|| (d.getBoard(temp1, temp2) == 5)
				|| (d.getBoard(temp1, temp2) == 6)
				|| (d.getBoard(temp1, temp2) == 7)
				|| (d.getBoard(temp1, temp2) == 8))
				return false;
			else
				return true;
		}
		else if ((temp2 < 7) && (d.getBoard(temp1, temp2) != 21))	//out of board
			return true;
		else
			return false;

	case 10: case 11: case 12: case 13: case 16:
		if ((d.getBoard(temp1, temp2) == 10)						//same team
			|| (d.getBoard(temp1, temp2) == 11)
			|| (d.getBoard(temp1, temp2) == 12)
			|| (d.getBoard(temp1, temp2) == 13)
			|| (d.getBoard(temp1, temp2) == 14)
			|| (d.getBoard(temp1, temp2) == 15)
			|| (d.getBoard(temp1, temp2) == 16)
			|| (d.getBoard(temp1, temp2) == 9))
			return false;
		else if (!((temp1 == 3 && temp2 == 1)						//river
			|| (temp1 == 4 && temp2 == 1)
			|| (temp1 == 5 && temp2 == 1)
			|| (temp1 == 3 && temp2 == 4)
			|| (temp1 == 4 && temp2 == 4)
			|| (temp1 == 5 && temp2 == 4)))
		{
			if ((temp2 < 7) && (d.getBoard(temp1, temp2) != 21))	//out of board
				return true;
			else
				return false;
		}
		else
			return false;
	case 14: case 15:
		if ((d.getBoard(temp1, temp2) == 9)
			|| (d.getBoard(temp1, temp2) == 10)						//same team
			|| (d.getBoard(temp1, temp2) == 11)
			|| (d.getBoard(temp1, temp2) == 12)
			|| (d.getBoard(temp1, temp2) == 13)
			|| (d.getBoard(temp1, temp2) == 14)
			|| (d.getBoard(temp1, temp2) == 15)
			|| (d.getBoard(temp1, temp2) == 16))
			return false;
		else if (d.getBoard(temp1, temp2) == 19)
		{
			if ((d.getBoard(temp1, temp2) == 1)
				|| (d.getBoard(temp1, temp2 + 1) == 1)
				|| (d.getBoard(temp1, temp2) == 9)
				|| (d.getBoard(temp1 + 1, temp2 + 1) == 9))
				return false;
		}
		else if ((temp2 < 7) && (d.getBoard(temp1, temp2) != 21))	//out of board
			return true;
		else
			return false;
	}
}
void Rule::captureUpB(int pieces)
{
	switch (pieces)
	{
	case 9:
		if ((d.getBoard(getx() - 1, gety()) == 8)
			|| (d.getBoard(getx() - 1, gety()) == 1))
		{
			if (d.getBoard(getx() - 1, gety()) == 8)
				p.SetBluePieces(7, false);
			else if (d.getBoard(getx() - 1, gety()) == 1)
				p.SetBluePieces(0, false);
			x = x - 1;
			break;
		}
		else if ((d.getBoard(getx() - 1, gety()) == 0)
			|| (d.getBoard(getx() - 1, gety()) == 19)
			|| (d.getBoard(getx() - 1, gety()) == 17)
			|| (d.getBoard(getx() - 1, gety()) == 18))
		{
			x = x - 1;
			break;
		}
		else
		{
			x = x;
			break;
		}
	case 10:
		if ((d.getBoard(getx() - 1, gety()) == 2)
			|| (d.getBoard(getx() - 1, gety()) == 1))
		{
			if (d.getBoard(getx() - 1, gety()) == 2)
				p.SetBluePieces(1, false);
			else if (d.getBoard(getx() - 1, gety()) == 1)
				p.SetBluePieces(0, false);
			x = x - 1;
			break;
		}
		else if ((d.getBoard(getx() - 1, gety()) == 0)
			|| (d.getBoard(getx() - 1, gety()) == 17)
			|| (d.getBoard(getx() - 1, gety()) == 18))
		{
			x = x - 1;
			break;
		}
		else
		{
			x = x;
			break;
		}
	case 11:
		if ((d.getBoard(getx() - 1, gety()) == 1)
			|| (d.getBoard(getx() - 1, gety()) == 2)
			|| (d.getBoard(getx() - 1, gety()) == 3))
		{
			if (d.getBoard(getx() - 1, gety()) == 1)
				p.SetBluePieces(0, false);
			else if (d.getBoard(getx() - 1, gety()) == 2)
				p.SetBluePieces(1, false);
			else if (d.getBoard(getx() - 1, gety()) == 3)
				p.SetBluePieces(2, false);
			x = x - 1;
			break;
		}

		else if ((d.getBoard(getx() - 1, gety()) == 0)
			|| (d.getBoard(getx() - 1, gety()) == 17)
			|| (d.getBoard(getx() - 1, gety()) == 18))
		{
			x = x - 1;
			break;
		}
		else
		{
			x = x;
			break;
		}
	case 12:
		if ((d.getBoard(getx() - 1, gety()) == 1)
			|| (d.getBoard(getx() - 1, gety()) == 2)
			|| (d.getBoard(getx() - 1, gety()) == 3)
			|| (d.getBoard(getx() - 1, gety()) == 4))
		{
			if (d.getBoard(getx() - 1, gety()) == 1)
				p.SetBluePieces(0, false);
			else if (d.getBoard(getx() - 1, gety()) == 2)
				p.SetBluePieces(1, false);
			else if (d.getBoard(getx() - 1, gety()) == 3)
				p.SetBluePieces(2, false);
			else if (d.getBoard(getx() - 1, gety()) == 4)
				p.SetBluePieces(3, false);
			x = x - 1;
			break;
		}
		else if ((d.getBoard(getx() - 1, gety()) == 0)
			|| (d.getBoard(getx() - 1, gety()) == 17)
			|| (d.getBoard(getx() - 1, gety()) == 18))
		{
			x = x - 1;
			break;
		}
		else
		{
			x = x;
			break;
		}
	case 13:
		if ((d.getBoard(getx() - 1, gety()) == 1)
			|| (d.getBoard(getx() - 1, gety()) == 2)
			|| (d.getBoard(getx() - 1, gety()) == 3)
			|| (d.getBoard(getx() - 1, gety()) == 4)
			|| (d.getBoard(getx() - 1, gety()) == 5))
		{
			if (d.getBoard(getx() - 1, gety()) == 1)
				p.SetBluePieces(0, false);
			else if (d.getBoard(getx() - 1, gety()) == 2)
				p.SetBluePieces(1, false);
			else if (d.getBoard(getx() - 1, gety()) == 3)
				p.SetBluePieces(2, false);
			else if (d.getBoard(getx() - 1, gety()) == 4)
				p.SetBluePieces(3, false);
			else if (d.getBoard(getx() - 1, gety()) == 5)
				p.SetBluePieces(4, false);
			x = x - 1;
			break;
		}
		else if ((d.getBoard(getx() - 1, gety()) == 0)
			|| (d.getBoard(getx() - 1, gety()) == 17)
			|| (d.getBoard(getx() - 1, gety()) == 18))
		{
			x = x - 1;
			break;
		}
		else
		{
			x = x;
			break;
		}
	case 14:
		if ((x == 6) && (y == 1)
			|| (x == 6) && (y == 2)
			|| (x == 6) && (y == 4)
			|| (x == 6) && (y == 5))
		{
			if ((d.getBoard(getx() - 1, gety()) != 1)
				|| (d.getBoard(getx() - 2, gety()) != 1)
				|| (d.getBoard(getx() - 3, gety()) != 1))
				x = x - 4;
			break;
		}
		else if ((d.getBoard(getx() - 1, gety()) == 1)
			|| (d.getBoard(getx() - 1, gety()) == 2)
			|| (d.getBoard(getx() - 1, gety()) == 3)
			|| (d.getBoard(getx() - 1, gety()) == 4)
			|| (d.getBoard(getx() - 1, gety()) == 5)
			|| (d.getBoard(getx() - 1, gety()) == 6))
		{

			if (d.getBoard(getx() - 1, gety()) == 1)
				p.SetBluePieces(0, false);
			else if (d.getBoard(getx() - 1, gety()) == 2)
				p.SetBluePieces(1, false);
			else if (d.getBoard(getx() - 1, gety()) == 3)
				p.SetBluePieces(2, false);
			else if (d.getBoard(getx() - 1, gety()) == 4)
				p.SetBluePieces(3, false);
			else if (d.getBoard(getx() - 1, gety()) == 5)
				p.SetBluePieces(4, false);
			else if (d.getBoard(getx() - 1, gety()) == 6)
				p.SetBluePieces(5, false);
			x = x - 1;
			break;
		}

		else if ((d.getBoard(getx() - 1, gety()) == 0)
			|| (d.getBoard(getx() - 1, gety()) == 17)
			|| (d.getBoard(getx() - 1, gety()) == 18))
		{
			x = x - 1;
			break;
		}
		else
		{
			x = x;
			break;
		}
	case 15:
		if ((x == 6) && (y == 1)
			|| (x == 6) && (y == 2)
			|| (x == 6) && (y == 4)
			|| (x == 6) && (y == 5))
		{
			if ((d.getBoard(getx() - 1, gety()) != 1)
				|| (d.getBoard(getx() - 2, gety()) != 1)
				|| (d.getBoard(getx() - 3, gety()) != 1))
				x = x - 4;
			break;
		}
		else if ((d.getBoard(getx() - 1, gety()) == 1)
			|| (d.getBoard(getx() - 1, gety()) == 2)
			|| (d.getBoard(getx() - 1, gety()) == 3)
			|| (d.getBoard(getx() - 1, gety()) == 4)
			|| (d.getBoard(getx() - 1, gety()) == 5)
			|| (d.getBoard(getx() - 1, gety()) == 6)
			|| (d.getBoard(getx() - 1, gety()) == 7))
		{
			if (d.getBoard(getx() - 1, gety()) == 1)
				p.SetBluePieces(0, false);
			else if (d.getBoard(getx() - 1, gety()) == 2)
				p.SetBluePieces(1, false);
			else if (d.getBoard(getx() - 1, gety()) == 3)
				p.SetBluePieces(2, false);
			else if (d.getBoard(getx() - 1, gety()) == 4)
				p.SetBluePieces(3, false);
			else if (d.getBoard(getx() - 1, gety()) == 5)
				p.SetBluePieces(4, false);
			else if (d.getBoard(getx() - 1, gety()) == 6)
				p.SetBluePieces(5, false);
			else if (d.getBoard(getx() - 1, gety()) == 7)
				p.SetBluePieces(6, false);
			x = x - 1;
			break;
		}

		else if ((d.getBoard(getx() - 1, gety()) == 0)
			|| (d.getBoard(getx() - 1, gety()) == 17)
			|| (d.getBoard(getx() - 1, gety()) == 18))
		{
			x = x - 1;
			break;
		}
		else
		{
			x = x;
			break;
		}
	case 16:
		if ((d.getBoard(getx() - 1, gety()) == 2)
			|| (d.getBoard(getx() - 1, gety()) == 3)
			|| (d.getBoard(getx() - 1, gety()) == 4)
			|| (d.getBoard(getx() - 1, gety()) == 5)
			|| (d.getBoard(getx() - 1, gety()) == 6)
			|| (d.getBoard(getx() - 1, gety()) == 7)
			|| (d.getBoard(getx() - 1, gety()) == 8))
		{
			 if (d.getBoard(getx() - 1, gety()) == 2)
				 p.SetBluePieces(1, false);
			else if (d.getBoard(getx() - 1, gety()) == 3)
				p.SetBluePieces(2, false);
			else if (d.getBoard(getx() - 1, gety()) == 4)
				p.SetBluePieces(3, false);
			else if (d.getBoard(getx() - 1, gety()) == 5)
				p.SetBluePieces(4, false);
			else if (d.getBoard(getx() - 1, gety()) == 6)
				p.SetBluePieces(5, false);
			else if (d.getBoard(getx() - 1, gety()) == 7)
				p.SetBluePieces(6, false);
			else if (d.getBoard(getx() - 1, gety()) == 8)
				p.SetRedPieces(7, false);
			x = x - 1;
			break;
		}
		else if ((d.getBoard(getx() - 1, gety()) == 0)
			|| (d.getBoard(getx() - 1, gety()) == 17)
			|| (d.getBoard(getx() - 1, gety()) == 18))
		{
			x = x - 1;
			break;
		}
		else
		{
			x = x;
			break;
		}
	}
}
void Rule::captureDownB(int pieces)
{
	switch (pieces)
	{
	case 9:
		if ((d.getBoard(getx() + 1, gety()) == 8)
			|| (d.getBoard(getx() + 1, gety()) == 1))
		{
			if (d.getBoard(getx() + 1, gety()) == 8)
				p.SetBluePieces(7, false);
			else if (d.getBoard(getx() + 1, gety()) == 1)
				p.SetBluePieces(0, false);
			x = x + 1;
			break;
		}
		else if ((d.getBoard(getx() + 1, gety()) == 0)
			|| (d.getBoard(getx() + 1, gety()) == 19)
			|| (d.getBoard(getx() + 1, gety()) == 22))
		{
			x = x + 1;
			break;
		}
		else
		{
			x = x;
			break;
		}
	case 10:
		if ((d.getBoard(getx() + 1, gety()) == 2)
			|| (d.getBoard(getx() + 1, gety()) == 1))
		{
			if (d.getBoard(getx() + 1, gety()) == 2)
				p.SetBluePieces(1, false);
			else if (d.getBoard(getx() + 1, gety()) == 1)
				p.SetBluePieces(0, false);
			x = x + 1;
			break;
		}
		else if ((d.getBoard(getx() + 1, gety()) == 0)
			|| (d.getBoard(getx() + 1, gety()) == 22))
		{
			x = x + 1;
			break;
		}
		else
		{
			x = x;
			break;
		}
	case 11:
		if ((d.getBoard(getx() + 1, gety()) == 1)
			|| (d.getBoard(getx() + 1, gety()) == 2)
			|| (d.getBoard(getx() + 1, gety()) == 3))
		{
			if (d.getBoard(getx() + 1, gety()) == 1)
				p.SetBluePieces(0, false);
			else if (d.getBoard(getx() + 1, gety()) == 2)
				p.SetBluePieces(1, false);
			else if (d.getBoard(getx() + 1, gety()) == 3)
				p.SetBluePieces(2, false);
			x = x + 1;
			break;
		}

		else if ((d.getBoard(getx() + 1, gety()) == 0)
			|| (d.getBoard(getx() + 1, gety()) == 22))
		{
			x = x + 1;
			break;
		}
		else
		{
			x = x;
			break;
		}
	case 12:
		if ((d.getBoard(getx() + 1, gety()) == 1)
			|| (d.getBoard(getx() + 1, gety()) == 2)
			|| (d.getBoard(getx() + 1, gety()) == 3)
			|| (d.getBoard(getx() + 1, gety()) == 4))
		{
			if (d.getBoard(getx() + 1, gety()) == 1)
				p.SetBluePieces(0, false);
			else if (d.getBoard(getx() + 1, gety()) == 2)
				p.SetBluePieces(1, false);
			else if (d.getBoard(getx() + 1, gety()) == 3)
				p.SetBluePieces(2, false);
			else if (d.getBoard(getx() + 1, gety()) == 4)
				p.SetBluePieces(3, false);
			x = x + 1;
			break;
		}
		else if ((d.getBoard(getx() + 1, gety()) == 0)
			|| (d.getBoard(getx() + 1, gety()) == 22))
		{
			x = x + 1;
			break;
		}
		else
		{
			x = x;
			break;
		}
	case 13:
		if ((d.getBoard(getx() + 1, gety()) == 1)
			|| (d.getBoard(getx() + 1, gety()) == 2)
			|| (d.getBoard(getx() + 1, gety()) == 3)
			|| (d.getBoard(getx() + 1, gety()) == 4)
			|| (d.getBoard(getx() + 1, gety()) == 5))
		{
			if (d.getBoard(getx() + 1, gety()) == 1)
				p.SetBluePieces(0, false);
			else if (d.getBoard(getx() + 1, gety()) == 2)
				p.SetBluePieces(1, false);
			else if (d.getBoard(getx() + 1, gety()) == 3)
				p.SetBluePieces(2, false);
			else if (d.getBoard(getx() + 1, gety()) == 4)
				p.SetBluePieces(3, false);
			else if (d.getBoard(getx() + 1, gety()) == 5)
				p.SetBluePieces(4, false);
			x = x + 1;
			break;
		}
		else if ((d.getBoard(getx() + 1, gety()) == 0)
			|| (d.getBoard(getx() + 1, gety()) == 22))
		{
			x = x + 1;
			break;
		}
		else
		{
			x = x;
			break;
		}
	case 14:
		if ((x == 2) && (y == 1)
			|| (x == 2) && (y == 2)
			|| (x == 2) && (y == 4)
			|| (x == 2) && (y == 5))
		{
			if ((d.getBoard(getx() + 1, gety()) != 1)
				|| (d.getBoard(getx() + 2, gety()) != 1)
				|| (d.getBoard(getx() + 3, gety()) != 1))
				x = x + 4;
			break;
		}
		else if ((d.getBoard(getx() + 1, gety()) == 1)
			|| (d.getBoard(getx() + 1, gety()) == 2)
			|| (d.getBoard(getx() + 1, gety()) == 3)
			|| (d.getBoard(getx() + 1, gety()) == 4)
			|| (d.getBoard(getx() + 1, gety()) == 5)
			|| (d.getBoard(getx() + 1, gety()) == 6))
		{

			if (d.getBoard(getx() + 1, gety()) == 1)
				p.SetBluePieces(0, false);
			else if (d.getBoard(getx() + 1, gety()) == 2)
				p.SetBluePieces(1, false);
			else if (d.getBoard(getx() + 1, gety()) == 3)
				p.SetBluePieces(2, false);
			else if (d.getBoard(getx() + 1, gety()) == 4)
				p.SetBluePieces(3, false);
			else if (d.getBoard(getx() + 1, gety()) == 5)
				p.SetBluePieces(4, false);
			else if (d.getBoard(getx() + 1, gety()) == 6)
				p.SetBluePieces(5, false);
			x = x + 1;
			break;
		}

		else if ((d.getBoard(getx() + 1, gety()) == 0)
			|| (d.getBoard(getx() + 1, gety()) == 22))
		{
			x = x + 1;
			break;
		}
		else
		{
			x = x;
			break;
		}
	case 15:
		if ((x == 2) && (y == 1)
			|| (x == 2) && (y == 2)
			|| (x == 2) && (y == 4)
			|| (x == 2) && (y == 5))
		{
			if ((d.getBoard(getx() + 1, gety()) != 1)
				|| (d.getBoard(getx() + 2, gety()) != 1)
				|| (d.getBoard(getx() + 3, gety()) != 1))
				x = x + 4;
			break;
		}
		else if ((d.getBoard(getx() + 1, gety()) == 1)
			|| (d.getBoard(getx() + 1, gety()) == 2)
			|| (d.getBoard(getx() + 1, gety()) == 3)
			|| (d.getBoard(getx() + 1, gety()) == 4)
			|| (d.getBoard(getx() + 1, gety()) == 5)
			|| (d.getBoard(getx() + 1, gety()) == 6)
			|| (d.getBoard(getx() + 1, gety()) == 7))
		{
			if (d.getBoard(getx() + 1, gety()) == 1)
				p.SetBluePieces(0, false);
			else if (d.getBoard(getx() + 1, gety()) == 2)
				p.SetBluePieces(1, false);
			else if (d.getBoard(getx() + 1, gety()) == 3)
				p.SetBluePieces(2, false);
			else if (d.getBoard(getx() + 1, gety()) == 4)
				p.SetBluePieces(3, false);
			else if (d.getBoard(getx() + 1, gety()) == 5)
				p.SetBluePieces(4, false);
			else if (d.getBoard(getx() + 1, gety()) == 6)
				p.SetBluePieces(5, false);
			else if (d.getBoard(getx() + 1, gety()) == 7)
				p.SetBluePieces(6, false);
			x = x + 1;
			break;
		}

		else if ((d.getBoard(getx() + 1, gety()) == 0)
			|| (d.getBoard(getx() + 1, gety()) == 22))
		{
			x = x + 1;
			break;
		}
		else
		{
			x = x;
			break;
		}
	case 16:
		if ((d.getBoard(getx() + 1, gety()) == 2)
			|| (d.getBoard(getx() + 1, gety()) == 3)
			|| (d.getBoard(getx() + 1, gety()) == 4)
			|| (d.getBoard(getx() + 1, gety()) == 5)
			|| (d.getBoard(getx() + 1, gety()) == 6)
			|| (d.getBoard(getx() + 1, gety()) == 7)
			|| (d.getBoard(getx() + 1, gety()) == 8))
		{
			if (d.getBoard(getx() + 1, gety()) == 2)
				p.SetBluePieces(1, false);
			else if (d.getBoard(getx() + 1, gety()) == 3)
				p.SetBluePieces(2, false);
			else if (d.getBoard(getx() + 1, gety()) == 4)
				p.SetBluePieces(3, false);
			else if (d.getBoard(getx() + 1, gety()) == 5)
				p.SetBluePieces(4, false);
			else if (d.getBoard(getx() + 1, gety()) == 6)
				p.SetBluePieces(5, false);
			else if (d.getBoard(getx() + 1, gety()) == 7)
				p.SetBluePieces(6, false);
			else if (d.getBoard(getx() + 1, gety()) == 8)
				p.SetBluePieces(7, false);
			x = x + 1;
			break;
		}
		else if ((d.getBoard(getx() + 1, gety()) == 0)
			|| (d.getBoard(getx() + 1, gety()) == 22))
		{
			x = x + 1;
			break;
		}
		else
		{
			x = x;
			break;
		}
	}
}
void Rule::captureLeftB(int pieces)
{
	switch (pieces)
	{
	case 9:
		if ((d.getBoard(getx(), gety() - 1) == 8)
			|| (d.getBoard(getx(), gety() - 1) == 1))
		{
			if (d.getBoard(getx(), gety() - 1) == 8)
				p.SetBluePieces(7, false);
			else if (d.getBoard(getx(), gety() - 1) == 1)
				p.SetBluePieces(0, false);
			y = y - 1;
			break;
		}
		else if ((d.getBoard(getx(), gety() - 1) == 0)
			|| (d.getBoard(getx(), gety() - 1) == 19)
			|| (d.getBoard(getx(), gety() - 1) == 17)
			|| (d.getBoard(getx(), gety() - 1) == 18)
			|| (d.getBoard(getx(), gety() - 1) == 22))
		{
			y = y - 1;
			break;
		}
		else
		{
			y = y;
			break;
		}
	case 10:
		if ((d.getBoard(getx(), gety() - 1) == 2)
			|| (d.getBoard(getx(), gety() - 1) == 1))
		{
			if (d.getBoard(getx(), gety() - 1) == 2)
				p.SetBluePieces(1, false);
			else if (d.getBoard(getx(), gety() - 1) == 1)
				p.SetBluePieces(0, false);
			y = y - 1;
			break;
		}
		else if ((d.getBoard(getx(), gety() - 1) == 0)
			|| (d.getBoard(getx(), gety() - 1) == 17)
			|| (d.getBoard(getx(), gety() - 1) == 18)
			|| (d.getBoard(getx(), gety() - 1) == 22))
		{
			y = y - 1;
			break;
		}
		else
		{
			y = y;
			break;
		}
	case 11:
		if ((d.getBoard(getx(), gety() - 1) == 1)
			|| (d.getBoard(getx(), gety() - 1) == 2)
			|| (d.getBoard(getx(), gety() - 1) == 3))
		{
			if (d.getBoard(getx(), gety() - 1) == 1)
				p.SetBluePieces(0, false);
			else if (d.getBoard(getx(), gety() - 1) == 2)
				p.SetBluePieces(1, false);
			else if (d.getBoard(getx(), gety() - 1) == 3)
				p.SetBluePieces(2, false);
			y = y - 1;
			break;
		}

		else if ((d.getBoard(getx(), gety() - 1) == 0)
			|| (d.getBoard(getx(), gety() - 1) == 17)
			|| (d.getBoard(getx(), gety() - 1) == 18)
			|| (d.getBoard(getx(), gety() - 1) == 22))
		{
			y = y - 1;
			break;
		}
		else
		{
			y = y;
			break;
		}
	case 12:
		if ((d.getBoard(getx(), gety() - 1) == 1)
			|| (d.getBoard(getx(), gety() - 1) == 2)
			|| (d.getBoard(getx(), gety() - 1) == 3)
			|| (d.getBoard(getx(), gety() - 1) == 4))
		{
			if (d.getBoard(getx(), gety() - 1) == 1)
				p.SetBluePieces(0, false);
			else if (d.getBoard(getx(), gety() - 1) == 2)
				p.SetBluePieces(1, false);
			else if (d.getBoard(getx(), gety() - 1) == 3)
				p.SetBluePieces(2, false);
			else if (d.getBoard(getx(), gety() - 1) == 4)
				p.SetBluePieces(3, false);
			y = y - 1;
			break;
		}
		else if ((d.getBoard(getx(), gety() - 1) == 0)
			|| (d.getBoard(getx(), gety() - 1) == 17)
			|| (d.getBoard(getx(), gety() - 1) == 18)
			|| (d.getBoard(getx(), gety() - 1) == 22))
		{
			y = y - 1;
			break;
		}
		else
		{
			y = y;
			break;
		}
	case 13:
		if ((d.getBoard(getx(), gety() - 1) == 1)
			|| (d.getBoard(getx(), gety() - 1) == 2)
			|| (d.getBoard(getx(), gety() - 1) == 3)
			|| (d.getBoard(getx(), gety() - 1) == 4)
			|| (d.getBoard(getx(), gety() - 1) == 5))
		{
			if (d.getBoard(getx(), gety() - 1) == 1)
				p.SetBluePieces(0, false);
			else if (d.getBoard(getx(), gety() - 1) == 2)
				p.SetBluePieces(1, false);
			else if (d.getBoard(getx(), gety() - 1) == 3)
				p.SetBluePieces(2, false);
			else if (d.getBoard(getx(), gety() - 1) == 4)
				p.SetBluePieces(3, false);
			else if (d.getBoard(getx(), gety() - 1) == 5)
				p.SetBluePieces(4, false);
			y = y - 1;
			break;
		}
		else if ((d.getBoard(getx(), gety() - 1) == 0)
			|| (d.getBoard(getx(), gety() - 1) == 17)
			|| (d.getBoard(getx(), gety() - 1) == 18)
			|| (d.getBoard(getx(), gety() - 1) == 22))
		{
			y = y - 1;
			break;
		}
		else
		{
			y = y;
			break;
		}
	case 14:
		if ((x == 3) && (y == 3)
			|| (x == 3) && (y == 6)
			|| (x == 4) && (y == 3)
			|| (x == 4) && (y == 6)
			|| (x == 5) && (y == 3)
			|| (x == 5) && (y == 6))
		{
			if ((d.getBoard(getx(), gety() - 1) != 1)
				|| (d.getBoard(getx(), gety() - 2) != 1))
				y = y - 3;
			break;
		}
		else if ((d.getBoard(getx(), gety() - 1) == 1)
			|| (d.getBoard(getx(), gety() - 1) == 2)
			|| (d.getBoard(getx(), gety() - 1) == 3)
			|| (d.getBoard(getx(), gety() - 1) == 4)
			|| (d.getBoard(getx(), gety() - 1) == 5)
			|| (d.getBoard(getx(), gety() - 1) == 6))
		{

			if (d.getBoard(getx(), gety() - 1) == 1)
				p.SetBluePieces(0, false);
			else if (d.getBoard(getx(), gety() - 1) == 2)
				p.SetBluePieces(1, false);
			else if (d.getBoard(getx(), gety() - 1) == 3)
				p.SetBluePieces(2, false);
			else if (d.getBoard(getx(), gety() - 1) == 4)
				p.SetBluePieces(3, false);
			else if (d.getBoard(getx(), gety() - 1) == 5)
				p.SetBluePieces(4, false);
			else if (d.getBoard(getx(), gety() - 1) == 6)
				p.SetBluePieces(5, false);
			y = y - 1;
			break;
		}

		else if ((d.getBoard(getx(), gety() - 1) == 0)
			|| (d.getBoard(getx(), gety() - 1) == 18)
			|| (d.getBoard(getx(), gety() - 1) == 17)
			|| (d.getBoard(getx(), gety() - 1) == 22))
		{
			y = y - 1;
			break;
		}
		else
		{
			y = y;
			break;
		}
	case 15:
		if ((x == 3) && (y == 3)
			|| (x == 3) && (y == 6)
			|| (x == 4) && (y == 3)
			|| (x == 4) && (y == 6)
			|| (x == 5) && (y == 3)
			|| (x == 5) && (y == 6))
		{
			if ((d.getBoard(getx(), gety() - 1) != 1)
				|| (d.getBoard(getx(), gety() - 2) != 1))
				y = y - 3;
			break;
		}
		else if ((d.getBoard(getx(), gety() - 1) == 1)
			|| (d.getBoard(getx(), gety() - 1) == 2)
			|| (d.getBoard(getx(), gety() - 1) == 3)
			|| (d.getBoard(getx(), gety() - 1) == 4)
			|| (d.getBoard(getx(), gety() - 1) == 5)
			|| (d.getBoard(getx(), gety() - 1) == 6)
			|| (d.getBoard(getx(), gety() - 1) == 7))
		{
			if (d.getBoard(getx(), gety() - 1) == 1)
				p.SetBluePieces(0, false);
			else if (d.getBoard(getx(), gety() - 1) == 2)
				p.SetBluePieces(1, false);
			else if (d.getBoard(getx(), gety() - 1) == 3)
				p.SetBluePieces(2, false);
			else if (d.getBoard(getx(), gety() - 1) == 4)
				p.SetBluePieces(3, false);
			else if (d.getBoard(getx(), gety() - 1) == 5)
				p.SetBluePieces(4, false);
			else if (d.getBoard(getx(), gety() - 1) == 6)
				p.SetBluePieces(5, false);
			else if (d.getBoard(getx(), gety() - 1) == 7)
				p.SetBluePieces(6, false);
			y = y - 1;
			break;
		}

		else if ((d.getBoard(getx(), gety() - 1) == 0)
			|| (d.getBoard(getx(), gety() - 1) == 17)
			|| (d.getBoard(getx(), gety() - 1) == 18)
			|| (d.getBoard(getx(), gety() - 1) == 22))
		{
			y = y - 1;
			break;
		}
		else
		{
			y = y;
			break;
		}
	case 16:
		if ((d.getBoard(getx(), gety() - 1) == 2)
			|| (d.getBoard(getx(), gety() - 1) == 3)
			|| (d.getBoard(getx(), gety() - 1) == 4)
			|| (d.getBoard(getx(), gety() - 1) == 5)
			|| (d.getBoard(getx(), gety() - 1) == 6)
			|| (d.getBoard(getx(), gety() - 1) == 7)
			|| (d.getBoard(getx(), gety() - 1) == 8))
		{
			if (d.getBoard(getx(), gety() - 1) == 2)
				p.SetBluePieces(1, false);
			else if (d.getBoard(getx(), gety() - 1) == 3)
				p.SetBluePieces(2, false);
			else if (d.getBoard(getx(), gety() - 1) == 4)
				p.SetBluePieces(3, false);
			else if (d.getBoard(getx(), gety() - 1) == 5)
				p.SetBluePieces(4, false);
			else if (d.getBoard(getx(), gety() - 1) == 6)
				p.SetBluePieces(5, false);
			else if (d.getBoard(getx(), gety() - 1) == 7)
				p.SetBluePieces(6, false);
			else if (d.getBoard(getx(), gety() - 1) == 8)
				p.SetBluePieces(7, false);
			y = y - 1;
			break;
		}
		else if ((d.getBoard(getx(), gety() - 1) == 0)
			|| (d.getBoard(getx(), gety() - 1) == 17)
			|| (d.getBoard(getx(), gety() - 1) == 18)
			|| (d.getBoard(getx(), gety() - 1) == 22))
		{
			y = y - 1;
			break;
		}
		else
		{
			y = y;
			break;
		}
	}
}
void Rule::captureRightB(int pieces)
{
	switch (pieces)
	{
	case 9:
		if ((d.getBoard(getx(), gety() + 1) == 8)
			|| (d.getBoard(getx(), gety() + 1) == 1))
		{
			if (d.getBoard(getx(), gety() + 1) == 8)
				p.SetBluePieces(7, false);
			else if (d.getBoard(getx(), gety() + 1) == 1)
				p.SetBluePieces(0, false);
			y = y + 1;
			break;
		}
		else if ((d.getBoard(getx(), gety() + 1) == 0)
			|| (d.getBoard(getx(), gety() + 1) == 19)
			|| (d.getBoard(getx(), gety() + 1) == 17)
			|| (d.getBoard(getx(), gety() + 1) == 18)
			|| (d.getBoard(getx(), gety() + 1) == 22))
		{
			y = y + 1;
			break;
		}
		else
		{
			y = y;
			break;
		}
	case 10:
		if ((d.getBoard(getx(), gety() + 1) == 2)
			|| (d.getBoard(getx(), gety() + 1) == 1))
		{
			if (d.getBoard(getx(), gety() + 1) == 2)
				p.SetBluePieces(1, false);
			else if (d.getBoard(getx(), gety() + 1) == 1)
				p.SetBluePieces(0, false);
			y = y + 1;
			break;
		}
		else if ((d.getBoard(getx(), gety() + 1) == 0)
			|| (d.getBoard(getx(), gety() + 1) == 17)
			|| (d.getBoard(getx(), gety() + 1) == 18)
			|| (d.getBoard(getx(), gety() + 1) == 22))
		{
			y = y + 1;
			break;
		}
		else
		{
			y = y;
			break;
		}
	case 11:
		if ((d.getBoard(getx(), gety() + 1) == 1)
			|| (d.getBoard(getx(), gety() + 1) == 2)
			|| (d.getBoard(getx(), gety() + 1) == 3))
		{
			if (d.getBoard(getx(), gety() + 1) == 1)
				p.SetBluePieces(0, false);
			else if (d.getBoard(getx(), gety() + 1) == 2)
				p.SetBluePieces(1, false);
			else if (d.getBoard(getx(), gety() + 1) == 3)
				p.SetBluePieces(2, false);
			y = y + 1;
			break;
		}

		else if ((d.getBoard(getx(), gety() + 1) == 0)
			|| (d.getBoard(getx(), gety() + 1) == 17)
			|| (d.getBoard(getx(), gety() + 1) == 18)
			|| (d.getBoard(getx(), gety() + 1) == 22))
		{
			y = y + 1;
			break;
		}
		else
		{
			y = y;
			break;
		}
	case 12:
		if ((d.getBoard(getx(), gety() + 1) == 1)
			|| (d.getBoard(getx(), gety() + 1) == 2)
			|| (d.getBoard(getx(), gety() + 1) == 3)
			|| (d.getBoard(getx(), gety() + 1) == 4))
		{
			if (d.getBoard(getx(), gety() + 1) == 1)
				p.SetBluePieces(0, false);
			else if (d.getBoard(getx(), gety() + 1) == 2)
				p.SetBluePieces(1, false);
			else if (d.getBoard(getx(), gety() + 1) == 3)
				p.SetBluePieces(2, false);
			else if (d.getBoard(getx(), gety() + 1) == 4)
				p.SetBluePieces(3, false);
			y = y + 1;
			break;
		}
		else if ((d.getBoard(getx(), gety() + 1) == 0)
			|| (d.getBoard(getx(), gety() + 1) == 17)
			|| (d.getBoard(getx(), gety() + 1) == 18)
			|| (d.getBoard(getx(), gety() + 1) == 22))
		{
			y = y + 1;
			break;
		}
		else
		{
			y = y;
			break;
		}
	case 13:
		if ((d.getBoard(getx(), gety() + 1) == 1)
			|| (d.getBoard(getx(), gety() + 1) == 2)
			|| (d.getBoard(getx(), gety() + 1) == 3)
			|| (d.getBoard(getx(), gety() + 1) == 4)
			|| (d.getBoard(getx(), gety() + 1) == 5))
		{
			if (d.getBoard(getx(), gety() + 1) == 1)
				p.SetBluePieces(0, false);
			else if (d.getBoard(getx(), gety() + 1) == 2)
				p.SetBluePieces(1, false);
			else if (d.getBoard(getx(), gety() + 1) == 3)
				p.SetBluePieces(2, false);
			else if (d.getBoard(getx(), gety() + 1) == 4)
				p.SetBluePieces(3, false);
			else if (d.getBoard(getx(), gety() + 1) == 5)
				p.SetBluePieces(4, false);
			y = y + 1;
			break;
		}
		else if ((d.getBoard(getx(), gety() + 1) == 0)
			|| (d.getBoard(getx(), gety() + 1) == 17)
			|| (d.getBoard(getx(), gety() + 1) == 18)
			|| (d.getBoard(getx(), gety() + 1) == 22))
		{
			y = y + 1;
			break;
		}
		else
		{
			y = y;
			break;
		}
	case 14:
		if ((x == 3) && (y == 0)
			|| (x == 3) && (y == 3)
			|| (x == 4) && (y == 0)
			|| (x == 4) && (y == 3)
			|| (x == 5) && (y == 0)
			|| (x == 5) && (y == 3))
		{
			if ((d.getBoard(getx(), gety() + 1) != 1)
				|| (d.getBoard(getx(), gety() + 2) != 1))
				y = y + 3;
			break;
		}
		else if ((d.getBoard(getx(), gety() + 1) == 1)
			|| (d.getBoard(getx(), gety() + 1) == 2)
			|| (d.getBoard(getx(), gety() + 1) == 3)
			|| (d.getBoard(getx(), gety() + 1) == 4)
			|| (d.getBoard(getx(), gety() + 1) == 5)
			|| (d.getBoard(getx(), gety() + 1) == 6))
		{

			if (d.getBoard(getx(), gety() + 1) == 1)
				p.SetBluePieces(0, false);
			else if (d.getBoard(getx(), gety() + 1) == 2)
				p.SetBluePieces(1, false);
			else if (d.getBoard(getx(), gety() + 1) == 3)
				p.SetBluePieces(2, false);
			else if (d.getBoard(getx(), gety() + 1) == 4)
				p.SetBluePieces(3, false);
			else if (d.getBoard(getx(), gety() + 1) == 5)
				p.SetBluePieces(4, false);
			else if (d.getBoard(getx(), gety() + 1) == 6)
				p.SetBluePieces(5, false);
			y = y + 1;
			break;
		}

		else if ((d.getBoard(getx(), gety() + 1) == 0)
			|| (d.getBoard(getx(), gety() + 1) == 17)
			|| (d.getBoard(getx(), gety() + 1) == 18)
			|| (d.getBoard(getx(), gety() + 1) == 22))
		{
			y = y + 1;
			break;
		}
		else
		{
			y = y;
			break;
		}
	case 15:
		if ((x == 3) && (y == 0)
			|| (x == 3) && (y == 3)
			|| (x == 4) && (y == 0)
			|| (x == 4) && (y == 3)
			|| (x == 5) && (y == 0)
			|| (x == 5) && (y == 3))
		{
			if ((d.getBoard(getx(), gety() + 1) != 1)
				|| (d.getBoard(getx(), gety() + 2) != 1))
				y = y + 3;
			break;
		}
		else if ((d.getBoard(getx(), gety() + 1) == 1)
			|| (d.getBoard(getx(), gety() + 1) == 2)
			|| (d.getBoard(getx(), gety() + 1) == 3)
			|| (d.getBoard(getx(), gety() + 1) == 4)
			|| (d.getBoard(getx(), gety() + 1) == 5)
			|| (d.getBoard(getx(), gety() + 1) == 6)
			|| (d.getBoard(getx(), gety() + 1) == 7))
		{
			if (d.getBoard(getx(), gety() + 1) == 1)
				p.SetBluePieces(0, false);
			else if (d.getBoard(getx(), gety() + 1) == 2)
				p.SetBluePieces(1, false);
			else if (d.getBoard(getx(), gety() + 1) == 3)
				p.SetBluePieces(2, false);
			else if (d.getBoard(getx(), gety() + 1) == 4)
				p.SetBluePieces(3, false);
			else if (d.getBoard(getx(), gety() + 1) == 5)
				p.SetBluePieces(4, false);
			else if (d.getBoard(getx(), gety() + 1) == 6)
				p.SetBluePieces(5, false);
			else if (d.getBoard(getx(), gety() + 1) == 7)
				p.SetBluePieces(6, false);
			y = y + 1;
			break;
		}

		else if ((d.getBoard(getx(), gety() + 1) == 0)
			|| (d.getBoard(getx(), gety() + 1) == 18)
			|| (d.getBoard(getx(), gety() + 1) == 17)
			|| (d.getBoard(getx(), gety() + 1) == 22))
		{
			y = y + 1;
			break;
		}
		else
		{
			y = y;
			break;
		}
	case 16:
		if ((d.getBoard(getx(), gety() + 1) == 2)
			|| (d.getBoard(getx(), gety() + 1) == 3)
			|| (d.getBoard(getx(), gety() + 1) == 4)
			|| (d.getBoard(getx(), gety() + 1) == 5)
			|| (d.getBoard(getx(), gety() + 1) == 6)
			|| (d.getBoard(getx(), gety() + 1) == 7)
			|| (d.getBoard(getx(), gety() + 1) == 8))
		{
			 if (d.getBoard(getx(), gety() + 1) == 2)
				 p.SetBluePieces(1, false);
			else if (d.getBoard(getx(), gety() + 1) == 3)
				p.SetBluePieces(2, false);
			else if (d.getBoard(getx(), gety() + 1) == 4)
				p.SetBluePieces(3, false);
			else if (d.getBoard(getx(), gety() + 1) == 5)
				p.SetBluePieces(4, false);
			else if (d.getBoard(getx(), gety() + 1) == 6)
				p.SetBluePieces(5, false);
			else if (d.getBoard(getx(), gety() + 1) == 7)
				p.SetBluePieces(6, false);
			else if (d.getBoard(getx(), gety() + 1) == 8)
				p.SetBluePieces(7, false);
			y = y + 1;
			break;
		}
		else if ((d.getBoard(getx(), gety() + 1) == 0)
			|| (d.getBoard(getx(), gety() + 1) == 17)
			|| (d.getBoard(getx(), gety() + 1) == 18)
			|| (d.getBoard(getx(), gety() + 1) == 22))
		{
			y = y + 1;
			break;
		}
		else
		{
			y = y;
			break;
		}
	}
}
