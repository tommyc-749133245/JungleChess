#include <iostream>
#include <sstream>
#include "Landscape.h"
using namespace std;

//constructor
Landscape::Landscape()
{
	LandscapeName[0] = { "  DEN   " };
	LandscapeName[1] = { "  TRAP  " };
	LandscapeName[2] = { "~River~ " };
}
//accessor function for landscape name
char* Landscape::getLandscapeName(int x)
{
	return LandscapeName[x];
}