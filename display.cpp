#include <iostream>
#include <sstream>
#include"display.h"
using namespace std;

//constructor
Display::Display()
{
	choice = 0;
}
//accessor function for chosen pieces
int Display::getChoice()
{
	return choice;
}
//mutator function for chosen pieces
void Display::setChoice(int temp)
{
	choice = temp;
}
//accessor function for chosen move
int Display::getMove()
{
	return MoveChoice;
}
//mutator function for chosen move
void Display::setMove(int temp)
{
	MoveChoice= temp;
}
//display the game board
void Display::displayboard()
{
	//frist line
	for (int i = 0; i < 79; i++)
		cout << "=";
	cout << endl;
	//second line
	for (int i = 0; i < 9; i++)
	{
		spaces();
		cout << endl;
		content(i);
		cout << endl;
		spaces();
		cout << endl;
		line();
	}
}
