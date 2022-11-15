#include <iostream>
#include <sstream>
#include "Animal.h"
using namespace std;

//constructor
Animal::Animal()
{
	//Animal Name
	animalName[0] = { "Rat     " };
	animalName[1] = { "Cat     " };
	animalName[2] = { "Wolf    " };
	animalName[3] = { "Dog     " };
	animalName[4] = { "Leopard " };
	animalName[5] = { "Tiger   " };
	animalName[6] = { "Lion    " };
	animalName[7] = { "Elephant" };
	animalName[8] = { "        " };
}
//accessor function for animal name
char* Animal::getanimalName(int x)
{
	return animalName[x];
}
