#include <iostream>
#include <sstream>
#include "Player.h"
using namespace std;

//constructor
Player::Player()
{
	//Life of red_pieces
	for (int i = 0; i < 8; i++)
		blue_pieces[i] = true;

	//Life of blue_pieces
	for (int i = 0; i < 8; i++)
		red_pieces[i] = true;
}
//accessor function for Red Pieces
bool Player::GetRedPieces(int x)
{
	return red_pieces[x];
}
//mutator function for Red Pieces
void Player::SetRedPieces(int x, bool temp)
{
	red_pieces[x] = temp;
}
//accessor function for Blue Pieces
bool Player::GetBluePieces(int x)
{
	return blue_pieces[x];
}
//mutator function for Blue Pieces
void Player::SetBluePieces(int x, bool temp)
{
	blue_pieces[x] = temp;
}