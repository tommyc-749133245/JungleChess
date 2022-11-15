#include <iostream>
#include <sstream>
#include"Game.h"
using namespace std;

Game::Game()
{
}
//games start
void Game::Initialize()
{
	
	//blue Team
	d.setBorad(2, 0, 1);//b_rat
	d.setBorad(1, 5, 2); //b_cat
	d.setBorad(2, 4, 3); //b_wolf
	d.setBorad(1, 1, 4); //b_Dog
	d.setBorad(2, 2, 5); //b_Leopard
	d.setBorad(0, 6, 6); //b_Tiger
	d.setBorad(0, 0, 7); //b_Lion
	d.setBorad(2, 6, 8); //b_Elephant

	d.setBorad(0, 2, 18); //b_Trap
	d.setBorad(0, 3, 17); //b_Den
	d.setBorad(0, 4, 18); //b_Trap
	d.setBorad(1, 3, 18); //b_Trap

	//red team
	d.setBorad(6, 6, 9); //r_rat
	d.setBorad(7, 1, 10); //r_cat
	d.setBorad(6, 2, 11); //r_wolf
	d.setBorad(7, 5, 12); //r_Dog
	d.setBorad(6, 4, 13); //r_Leopard
	d.setBorad(8, 0, 14); //r_Tiger
	d.setBorad(8, 6, 15); //r_Lion
	d.setBorad(6, 0, 16); //r_Elephant

	d.setBorad(8, 2, 22); //r_Trap
	d.setBorad(8, 3, 21); //r_Den
	d.setBorad(8, 4, 22); //r_Trap
	d.setBorad(7, 3, 22); //r_Trap
	
	/*--------------------------
	River
	---------------------------*/
	d.setBorad(3, 1, 19);
	d.setBorad(3, 2, 19);
	d.setBorad(4, 1, 19);
	d.setBorad(4, 2, 19);
	d.setBorad(5, 1, 19);
	d.setBorad(5, 2, 19);
	d.setBorad(3, 5, 19);
	d.setBorad(3, 4, 19);
	d.setBorad(4, 4, 19);
	d.setBorad(4, 5, 19);
	d.setBorad(5, 4, 19);
	d.setBorad(5, 5, 19);
}
//display gameboard
void Game::display()
{
	d.displayboard();

}
//convert input for calculate
int Game::convert(int pieces)
{
	switch (pieces)
	{
	case 1:
		return 9;
		break;
	case 2:
		return 10;
		break;
	case 3:
		return 11;
		break;
	case 4:
		return 12;
		break;
	case 5:
		return 13;
		break;
	case 6:
		return 14;
		break;
	case 7:
		return 15;
		break;
	case 8:
		return 16;
		break;
	}
}
//display the pieces for player A
void Game::displayPiecesSelectionA()
{
	ptrPlayer = r.getPlayer();
	int piece;
	cout << "PICK 1 PIECE:" << endl;
	if (ptrPlayer->GetBluePieces(0))
		cout <<"1. " << a.getanimalName(0) << endl;
	if (ptrPlayer->GetBluePieces(1))
		cout <<"2. " << a.getanimalName(1) << endl;
	if (ptrPlayer->GetBluePieces(2))
		cout <<"3. " << a.getanimalName(2) << endl;
	if (ptrPlayer->GetBluePieces(3))
		cout <<"4. " << a.getanimalName(3) << endl;
	if (ptrPlayer->GetBluePieces(4))
		cout <<"5. " << a.getanimalName(4) << endl;
	if (ptrPlayer->GetBluePieces(5))
		cout <<"6. " << a.getanimalName(5) << endl;
	if (ptrPlayer->GetBluePieces(6))
		cout <<"7. " << a.getanimalName(6) << endl;
	if (ptrPlayer->GetBluePieces(7))
		cout <<"8. " << a.getanimalName(7) << endl;
	std::cin >> piece;
	d.setChoice(piece);
}
//display the pieces for player B
void Game::displayPiecesSelectionB()
{
	ptrPlayer = r.getPlayer();
	int piece;
	cout << "PICK 1 PIECE:" << endl;
	if (ptrPlayer->GetRedPieces(0))
		cout << "1. " << a.getanimalName(0) << endl;
	if (ptrPlayer->GetRedPieces(1))
		cout << "2. " << a.getanimalName(1) << endl;
	if (ptrPlayer->GetRedPieces(2))
		cout << "3. " << a.getanimalName(2) << endl;
	if (ptrPlayer->GetRedPieces(3))
		cout << "4. " << a.getanimalName(3) << endl;
	if (ptrPlayer->GetRedPieces(4))
		cout << "5. " << a.getanimalName(4) << endl;
	if (ptrPlayer->GetRedPieces(5))
		cout << "6. " << a.getanimalName(5) << endl;
	if (ptrPlayer->GetRedPieces(6))
		cout << "7. " << a.getanimalName(6) << endl;
	if (ptrPlayer->GetRedPieces(7))
		cout << "8. " << a.getanimalName(7) << endl;

	std::cin >> piece;
	piece = convert(piece);
	d.setChoice(piece);
}
//display the possible move for player A
void Game::displayPossibleMoveA()
{
	bool up;
	bool down;
	bool left;
	bool right;
	int move = 0;
	r.copy(d);
	r.checkposition(d.getChoice());
	cout << "PICK 1 DIRECTION FOR SELECTED PIECES:" << endl;
	up = r.checkPossibleMoveUpA(d.getChoice());
	down = r.checkPossibleMoveDownA(d.getChoice());
	left = r.checkPossibleMoveLeftA(d.getChoice());
	right = r.checkPossibleMoveRightA(d.getChoice());
	while(up)
	{
		cout << "1. Up" << endl;
		break;
	}
	while(down)
	{
		cout << "2. Down" << endl;
		break;
	}
	while(left)
	{
		cout << "3. Left" << endl;
		break;
	}
	while(right)
	{
		cout << "4. Right" << endl;
		break;
	}
	cin >> move;
	d.setMove(move);
}
//display the possible move for player B
void Game::displayPossibleMoveB()
{
	bool up;
	bool down;
	bool left;
	bool right;
	int move = 0;
	r.copy(d);
	r.checkposition(d.getChoice());
	cout << "PICK 1 DIRECTION FOR SELECTED PIECES:" << endl;
	up = r.checkPossibleMoveUpB(d.getChoice());
	down = r.checkPossibleMoveDownB(d.getChoice());
	left = r.checkPossibleMoveLeftB(d.getChoice());
	right = r.checkPossibleMoveRightB(d.getChoice());
	while (up)
	{
		cout << "1. Up" << endl;
		break;
	}
	while (down)
	{
		cout  << "2. Down" << endl;
		break;
	}
	while (left)
	{
		cout << "3. Left" << endl;
		break;
	}
	while (right)
	{
		cout << "4. Right" << endl;
		break;
	}
	cin >> move;
	d.setMove(move);
}
//call movement function when Player A is selected 
void Game::MoveA()
{
	int temp = d.getChoice();
	switch (d.getMove())
	{
		//-----------------
		//Up
		//-----------------
	case 1:
		r.checkposition(temp);
		r.captureUpA(temp);
		d.setBorad(r.getx(), r.gety(), temp);
		if ((temp == 6|| temp == 7)
			&& ((r.getx() == 2 && r.gety() == 1)
			|| (r.getx() == 2 && r.gety() == 2)
			|| (r.getx() == 2 && r.gety() == 4)
			|| (r.getx() == 2 && r.gety() == 5)))
			d.setBorad(r.getx() + 4, r.gety(), 0);
		else if ((temp == 1)
			&& ((r.getx() == 2 && r.gety() == 1)
			|| (r.getx() == 2 && r.gety() == 2)
			|| (r.getx() == 2 && r.gety() == 4)
			|| (r.getx() == 2 && r.gety() == 5)
			|| (r.getx() == 3 && r.gety() == 1)
			|| (r.getx() == 3 && r.gety() == 2)
			|| (r.getx() == 3 && r.gety() == 4)
			|| (r.getx() == 3 && r.gety() == 5)
			|| (r.getx() == 4 && r.gety() == 1)
			|| (r.getx() == 4 && r.gety() == 2)
			|| (r.getx() == 4 && r.gety() == 4)
			|| (r.getx() == 4 && r.gety() == 5)))
			d.setBorad(r.getx() + 1, r.gety(), 19);
		else
			d.setBorad(r.getx() + 1, r.gety(), 0);
		break;
		//-----------------
		//Down
		//-----------------
	case 2:
		r.checkposition(temp);
		r.captureDownA(temp);
		d.setBorad(r.getx(), r.gety(), temp);
		if ((temp == 6
			|| temp == 7)
			&& ((r.getx() == 6 && r.gety() == 1)
			|| (r.getx() == 6 && r.gety() == 2)
			|| (r.getx() == 6 && r.gety() == 4)
			|| (r.getx() == 6 && r.gety() == 5)))
			d.setBorad(r.getx() - 4, r.gety(), 0);
		else if ((temp == 1)
			&& ((r.getx() == 4 && r.gety() == 1)
			|| (r.getx() == 4 && r.gety() == 2)
			|| (r.getx() == 4 && r.gety() == 4)
			|| (r.getx() == 4 && r.gety() == 5)
			|| (r.getx() == 5 && r.gety() == 1)
			|| (r.getx() == 5 && r.gety() == 2)
			|| (r.getx() == 5 && r.gety() == 4)
			|| (r.getx() == 5 && r.gety() == 5)
			|| (r.getx() == 6 && r.gety() == 1)
			|| (r.getx() == 6 && r.gety() == 2)
			|| (r.getx() == 6 && r.gety() == 4)
			|| (r.getx() == 6 && r.gety() == 5)))
			d.setBorad(r.getx() - 1, r.gety(), 19);
		else
			d.setBorad(r.getx() - 1, r.gety(), 0);
		break;
		//-----------------
		//Left
		//-----------------
	case 3:
		r.checkposition(temp);
		r.captureLeftA(temp);
		d.setBorad(r.getx(), r.gety(), temp);
		if ((temp == 6
			|| temp == 7)
			&& ((r.getx() == 3 && r.gety() == 3)
			|| (r.getx() == 4 && r.gety() == 3)
			|| (r.getx() == 5 && r.gety() == 3)
			|| (r.getx() == 3 && r.gety() == 6)
			|| (r.getx() == 4 && r.gety() == 6)
			|| (r.getx() == 5 && r.gety() == 6)))
			d.setBorad(r.getx(), r.gety() + 3, 0);
		else if ((temp == 1)
			&& ((r.getx() == 3 && r.gety() == 0)
			|| (r.getx() == 3 && r.gety() == 1)
			|| (r.getx() == 3 && r.gety() == 3)
			|| (r.getx() == 3 && r.gety() == 4)
			|| (r.getx() == 4 && r.gety() == 0)
			|| (r.getx() == 4 && r.gety() == 1)
			|| (r.getx() == 4 && r.gety() == 3)
			|| (r.getx() == 4 && r.gety() == 4)
			|| (r.getx() == 5 && r.gety() == 0)
			|| (r.getx() == 5 && r.gety() == 1)
			|| (r.getx() == 5 && r.gety() == 3)
			|| (r.getx() == 5 && r.gety() == 4)))
			d.setBorad(r.getx(), r.gety() + 1, 19);
		else
			d.setBorad(r.getx(), r.gety() + 1, 0);
		break;
		//-----------------
		//Right
		//-----------------
	case 4:
		r.checkposition(temp);
		r.captureRightA(temp);
		d.setBorad(r.getx(), r.gety(), temp);
		if ((temp == 6
			|| temp == 7)
			&& ((r.getx() == 3 && r.gety() == 3)
			|| (r.getx() == 4 && r.gety() == 3)
			|| (r.getx() == 5 && r.gety() == 3)
			|| (r.getx() == 3 && r.gety() == 0)
			|| (r.getx() == 4 && r.gety() == 0)
			|| (r.getx() == 5 && r.gety() == 0)))
			d.setBorad(r.getx(), r.gety() - 3, 0);
		else if ((temp == 1)
			&& ((r.getx() == 3 && r.gety() == 2)
			|| (r.getx() == 3 && r.gety() == 3)
			|| (r.getx() == 3 && r.gety() == 5)
			|| (r.getx() == 3 && r.gety() == 6)
			|| (r.getx() == 4 && r.gety() == 2)
			|| (r.getx() == 4 && r.gety() == 3)
			|| (r.getx() == 4 && r.gety() == 5)
			|| (r.getx() == 4 && r.gety() == 6)
			|| (r.getx() == 5 && r.gety() == 2)
			|| (r.getx() == 5 && r.gety() == 3)
			|| (r.getx() == 5 && r.gety() == 5)
			|| (r.getx() == 5 && r.gety() == 6)))
			d.setBorad(r.getx(), r.gety() - 1, 19);
		else
			d.setBorad(r.getx(), r.gety() - 1, 0);
		break;
	}
}
//call movement function when Player B is selected 
void Game::MoveB()
{
	int temp = d.getChoice();
	switch (d.getMove())
	{
		//------------------
		//Up
		//-------------------
	case 1:
		r.checkposition(temp);
		r.captureUpB(temp);
		d.setBorad(r.getx(), r.gety(), temp);
		if ((temp == 14
			|| temp == 15)
			&& ((r.getx() == 2 && r.gety() == 1)
			|| (r.getx() == 2 && r.gety() == 2)
			|| (r.getx() == 2 && r.gety() == 4)
			|| (r.getx() == 2 && r.gety() == 5)))
			d.setBorad(r.getx() + 4, r.gety(), 0);
		else if ((temp == 9)
			&& ((r.getx() == 2 && r.gety() == 1)
			|| (r.getx() == 2 && r.gety() == 2)
			|| (r.getx() == 2 && r.gety() == 4)
			|| (r.getx() == 2 && r.gety() == 5)
			|| (r.getx() == 3 && r.gety() == 1)
			|| (r.getx() == 3 && r.gety() == 2)
			|| (r.getx() == 3 && r.gety() == 4)
			|| (r.getx() == 3 && r.gety() == 5)
			|| (r.getx() == 4 && r.gety() == 1)
			|| (r.getx() == 4 && r.gety() == 2)
			|| (r.getx() == 4 && r.gety() == 4)
			|| (r.getx() == 4 && r.gety() == 5)))
			d.setBorad(r.getx() + 1, r.gety(), 19);
		else
			d.setBorad(r.getx() + 1, r.gety(), 0);
		break;
		//-----------------
		//Down
		//-----------------
	case 2:
		r.checkposition(temp);
		r.captureDownB(temp);
		d.setBorad(r.getx(), r.gety(), temp);
		if ((temp == 14
			|| temp == 15)
			&& ((r.getx() == 6 && r.gety() == 1)
			|| (r.getx() == 6 && r.gety() == 2)
			|| (r.getx() == 6 && r.gety() == 4)
			|| (r.getx() == 6 && r.gety() == 5)))
			d.setBorad(r.getx() - 4, r.gety(), 0);
		else if ((temp == 9)
			&& ((r.getx() == 4 && r.gety() == 1)
			|| (r.getx() == 4 && r.gety() == 2)
			|| (r.getx() == 4 && r.gety() == 4)
			|| (r.getx() == 4 && r.gety() == 5)
			|| (r.getx() == 5 && r.gety() == 1)
			|| (r.getx() == 5 && r.gety() == 2)
			|| (r.getx() == 5 && r.gety() == 4)
			|| (r.getx() == 5 && r.gety() == 5)
			|| (r.getx() == 6 && r.gety() == 1)
			|| (r.getx() == 6 && r.gety() == 2)
			|| (r.getx() == 6 && r.gety() == 4)
			|| (r.getx() == 6 && r.gety() == 5)))
			d.setBorad(r.getx() - 1, r.gety(), 19);
		else
			d.setBorad(r.getx() - 1, r.gety(), 0);
		break;
		//-----------------
		//Left
		//-----------------
	case 3:
		r.checkposition(temp);
		r.captureLeftB(temp);
		d.setBorad(r.getx(), r.gety(), temp);
		if ((temp == 14
			|| temp == 15)
			&& ((r.getx() ==  3 && r.gety() == 3)
			|| (r.getx() == 4 && r.gety() == 3)
			|| (r.getx() == 5 && r.gety() == 3)
			|| (r.getx() == 3 && r.gety() == 6)
			|| (r.getx() == 4 && r.gety() == 6)
			|| (r.getx() == 5 && r.gety() == 6)))
			d.setBorad(r.getx(), r.gety() + 3, 0);
		else if ((temp == 9)
			&& ((r.getx() == 3 && r.gety() == 0)
			|| (r.getx() == 3 && r.gety() == 1)
			|| (r.getx() == 3 && r.gety() == 3)
			|| (r.getx() == 3 && r.gety() == 4)
			|| (r.getx() == 4 && r.gety() == 0)
			|| (r.getx() == 4 && r.gety() == 1)
			|| (r.getx() == 4 && r.gety() == 3)
			|| (r.getx() == 4 && r.gety() == 4)
			|| (r.getx() == 5 && r.gety() == 0)
			|| (r.getx() == 5 && r.gety() == 1)
			|| (r.getx() == 5 && r.gety() == 3)
			|| (r.getx() == 5 && r.gety() == 4)))
			d.setBorad(r.getx(), r.gety() + 1, 19);
		else
			d.setBorad(r.getx(), r.gety() + 1, 0);
		break;
		//-----------------
		//Right
		//-----------------
	case 4:
		r.checkposition(temp);
		r.captureRightB(temp);
		d.setBorad(r.getx(), r.gety(), temp);
		if (( temp == 14
			|| temp == 15)
			&& ((r.getx() == 3 && r.gety() == 3)
			|| (r.getx() == 4 && r.gety() == 3)
			|| (r.getx() == 5 && r.gety() == 3)
			|| (r.getx() == 3 && r.gety() == 0)
			|| (r.getx() == 4 && r.gety() == 0)
			|| (r.getx() == 5 && r.gety() == 0)))
			d.setBorad(r.getx(), r.gety() - 3, 0);
		else if ((temp == 9)
			&& ((r.getx() == 3 && r.gety() == 2)
			|| (r.getx() == 3 && r.gety() == 3)
			|| (r.getx() == 3 && r.gety() == 5)
			|| (r.getx() == 3 && r.gety() == 6)
			|| (r.getx() == 4 && r.gety() == 2)
			|| (r.getx() == 4 && r.gety() == 3)
			|| (r.getx() == 4 && r.gety() == 5)
			|| (r.getx() == 4 && r.gety() == 6)
			|| (r.getx() == 5 && r.gety() == 2)
			|| (r.getx() == 5 && r.gety() == 3)
			|| (r.getx() == 5 && r.gety() == 5)
			|| (r.getx() == 5 && r.gety() == 6)))
			d.setBorad(r.getx(), r.gety() - 1, 19);
		else
			d.setBorad(r.getx(), r.gety() - 1, 0);
		break;
	}
}
//checking for gameover
bool Game::gameover()
{
	return r.gameover();
}
//member function for display result
char* Game::result()
{
	return r.result();
}