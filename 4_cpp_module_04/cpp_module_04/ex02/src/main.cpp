#include <iostream>
#include "Cat.hpp"
#include "Dog.hpp"

// Must even !
const static int MAX_SIZE = 2;

int main()
{
	// AAnimal animal;
	AAnimal* zoo[MAX_SIZE];

	for (size_t i = 0; i < MAX_SIZE / 2; i++)
	{
		zoo[i] = new Dog;
	}
	for (size_t i = MAX_SIZE / 2; i < MAX_SIZE; i++)
	{
		zoo[i] = new Cat;
	}
	for (size_t i = 0; i < MAX_SIZE; i++)
	{
		zoo[i]->makeSound();
	}
	for (size_t i = 0; i < MAX_SIZE; i++)
	{
		delete zoo[i];
	}
	
	return 0;
}
