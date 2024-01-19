#include <iostream>
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* animal = new Animal();
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();
	std::cout << dog->getType() << " " << std::endl;
	std::cout << cat->getType() << " " << std::endl;
	dog->makeSound();
	cat->makeSound();
	animal->makeSound();

	delete animal;
	delete dog;
	delete cat;

	// Wrong Class Test
	
	const WrongAnimal* wrongAnimal = new WrongAnimal();
	const WrongAnimal* wrongCat = new WrongCat();

	std::cout << wrongCat->getType() << " " << std::endl;
	wrongCat->makeSound(); //will output the cat sound!
	wrongAnimal->makeSound();

	delete wrongAnimal;
	delete wrongCat;
	return 0;
}
