#include <iostream>
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* animal = new Animal();
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();
	std::cout << dog->GetType() << " " << std::endl;
	std::cout << cat->GetType() << " " << std::endl;
	dog->MakeSound();
	cat->MakeSound();
	animal->MakeSound();

	delete animal;
	delete dog;
	delete cat;

	// Wrong Class TEST
	
	const WrongAnimal* wrongAnimal = new WrongAnimal();
	const WrongAnimal* wrongCat = new WrongCat();

	std::cout << wrongCat->GetType() << " " << std::endl;
	wrongCat->MakeSound(); //will output the cat sound!
	wrongAnimal->MakeSound();

	delete wrongAnimal;
	delete wrongCat;
	return 0;
}
