#ifndef ANIMAL_H
#define ANIMAL_H
#include <iostream>
using namespace std;

class Animal
{
private:
	//array for animal name
	char* animalName[9];
public:
	//constructor
	Animal();
	//accessor function for animal name
	char* getanimalName(int x);
};
#endif