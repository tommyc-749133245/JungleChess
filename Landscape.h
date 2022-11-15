#ifndef LANDSCAPE_H
#define LANDSCAPE_H
#include"Board.h"
#include <iostream>

class Landscape
{
private:
	char* LandscapeName[3];
public:
	Landscape();
	char* getLandscapeName(int x);
};
#endif