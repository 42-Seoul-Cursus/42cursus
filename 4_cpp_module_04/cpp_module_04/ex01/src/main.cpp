#include <iostream>
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

// Must even !
const static int MAX_SIZE = 2;

const static std::string Ideas[10] = 
{
	"Before my nap in my favorite spot, a cute smile from you is a must.",
	"Why is my food bowl always empty? I'm hungry!",
	"A new box has arrived! Should I play with it today?",
	"Human, scratching my head always makes me feel so good.",
	"Why do humans always say 'cute' when they see me? I'm just awesome!",
	"Something is moving outside the window. It can't be something good for me, can it?",
	"My kingdom extends throughout this room. Other animals should be under my rule!",
	"I'm aware that I always look fabulous, even when I'm sleeping, eating, or playing.",
	"Why do humans tease me with those tiny fish toys? What's the point?",
	"I have my own worries. What to eat tomorrow, where to take a nap today - so many things to contemplate!"
};

void	leak(void)
{
	system("leaks --list brain");
}

int main()
{
	atexit(leak);
	Animal* zoo[MAX_SIZE];

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
		zoo[i]->MakeSound();
	}

	Cat* navi = new Cat;
	
	for (size_t i = 0; i < 11; i++)
	{
		for (size_t j = 0; j < 10; j++)
		{
			navi->AddIdea(Ideas[i]);
		}
	}

	navi->PrintAllIdeas();

	Cat* coco = new Cat;
	*coco = *navi;

	delete navi;

	coco->PrintAllIdeas();

	delete coco;
	
	for (size_t i = 0; i < MAX_SIZE; i++)
	{
		delete zoo[i];
	}

	// Wrong Class TEST

	WrongAnimal* DerivedClassNotCallOwnDestructor = new WrongCat;

	delete DerivedClassNotCallOwnDestructor;
	
	return 0;
}
